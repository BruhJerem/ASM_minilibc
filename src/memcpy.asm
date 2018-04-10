BITS 64

	global memcpy	; void *memcpy(void *dest, const void *src, size_t n)
	section .text

memcpy:
	push rbp
	mov rbp, rsp

	xor rcx, rcx
LOOP:
	cmp rdx, rcx		; compare if end
	jz END
	mov r8b, [rsi + rcx]	; put src + inc into r8 
	mov [rdi + rcx], r8b	; put to dest
	inc rcx			; inc
	jmp LOOP

END:
	mov rax, rsi

	mov rsp, rbp
	pop rbp
	ret
