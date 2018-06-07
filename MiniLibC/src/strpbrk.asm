	BITS 64

	global strpbrk 	; char *strpbrk(const char *str1, const char *str2)
	extern strchr
	section .text

strpbrk:
	push rbp
	mov rbp, rsp

	mov r8, rdi 		; str1
	mov r9, rsi		; str2

	cmp r8, 0
	je END

LOOP:
	cmp byte [r8], 0
	je END
	mov rdi, r9
	mov sil, [r8]
	call strchr wrt ..plt
	cmp rax, 0
	jne RETURN

	inc r8

	jmp LOOP
	
RETURN:
	mov rax, r8
	mov rsp, rbp
	pop rbp
	ret

END:
	mov rax, 0
	mov rsp, rbp
	pop rbp
	ret
	
