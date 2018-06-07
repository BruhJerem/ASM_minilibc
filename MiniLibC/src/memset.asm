BITS 64

	global memset 		; void *memset(void *s, int c, size_t n)
	section .text

memset:
	push rbp
	mov rbp, rsp

	xor rcx, rcx		; incrementator
	mov rax, rdi		; s
LOOP:
	cmp rdx, rcx		; chck if end
	jz END
	mov [rax], sil 		; memset the rdi
	inc rcx
	inc rax
	jmp LOOP

END:
	mov rax, rdi		; put s into return value

	mov rsp, rbp
	pop rbp
	ret
