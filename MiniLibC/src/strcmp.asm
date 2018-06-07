BITS 64

	global strcmp	;int strcmp (const char* s1, const char* s2)
	section .text

strcmp:
	push rbp
	mov rbp, rsp

	mov r8, 0		; init 0
	mov r9, 0		; init 0
LOOP:
	mov r8b, [rsi]		; moove byte s1
	mov r9b, [rdi]		; moove byte s2

	cmp r8b, 0		; check end s1
	jz END			; moove to end
	cmp r9b, 0		; check end s2
	jz END			; moove to end
	cmp r8b, r9b		; if not same
	jnz END			; go to end

	inc rsi			; inc s1
	inc rdi			; inc s2
	jmp LOOP		; loop

END:
	sub r9, r8		; *s1 - *s2
	mov rax, r9		; moove to return
	pop rbp
	ret
