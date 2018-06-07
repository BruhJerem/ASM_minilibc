	BITS 64

	global read
	section .text

read:
	push rbp
	mov rbp, rsp

	mov rax, 0   ; use the write syscall
	syscall         ; make syscall

	mov rsp, rbp
	pop rbp
	ret
