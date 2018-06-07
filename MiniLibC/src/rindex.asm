BITS 64
	global rindex	; char *rindex(const char* s, int c)
	section .text

rindex:
	push rbp
	mov rbp, rsp

	mov rbx, rdi		; s
	mov rax, 0h 		; init 0

LOOP:
	cmp [rbx], sil		; check s to c
	je FOUND		; go to found
	
	cmp byte [rbx], 0h	; s == \0
	je END			; end of chain

	inc rbx			; *s++
	jmp LOOP

FOUND:
	mov rax, rbx		; found put the * to rax
	cmp byte [rbx], 0h	; compare if char \0
	je END
	inc rbx
	jmp LOOP

END:
	pop rbp
	ret
