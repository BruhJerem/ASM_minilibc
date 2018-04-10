BITS 64

SECTION .text

global	strchr          ; char *strchr(const char *s, int c);
extern	strlen          ; Call function from lib

strchr:
	pushfq
	push rcx
	push rdi

	call strlen wrt ..plt    ; get lenth -> procedure table entry sympbol
	lea rcx, [rax + 1]      ; moove return of strlen adress of rax + 1 into rcx

	mov rax, rsi            ; first param into rax
	cld

	repne scasb
	je .FOUND               ; boucle

	xor rax, rax            ; address
	jmp .END

.FOUND:
	lea rax, [rdi - 1]      ; moove adress into rax

.END:
	pop	rdi
	pop	rcx
	popfq
	ret
