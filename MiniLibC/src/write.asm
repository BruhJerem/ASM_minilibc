BITS 64

	global write
	section .text

write:
	push rbp
	mov rbp, rsp
	
	mov rax, 1   ; use the write syscall
	syscall         ; make syscall

	mov rsp, rbp
	pop rbp
	ret
