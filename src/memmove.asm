BITS 64
	global memmove	; void *memmove(void *dest, void *src, int n)
	section .text

memmove:
	push rbp
	mov rbp, rsp

	cmp rsi, 0
	jz END
	
	cmp rdx, 0
	jz END

	mov r8, rdi
	mov r9b, [rsi]
	
	cmp rdi, rsi
	jl LEFT_LOOP
	
	dec rdx
	add rsi, rdx
	add rdi, rdx

RIGHT_LOOP:
	cmp rdx, -1
	jz END

	dec rdx
	
	mov r9b, byte [rsi]
	dec rsi
	
	mov [rdi], r9b
	dec rdi
	
	jmp RIGHT_LOOP

LEFT_LOOP:
	cmp rdx, 0
	jz END

	dec rdx
	
	mov r9b, [rsi]
	inc rsi
	
	mov [rdi], r9b
	inc rdi
	
	jmp LEFT_LOOP
	
END:
	mov rax, r8
	
	mov rsp, rbp
	pop rbp
	ret
