BITS 64

SECTION .text

	global	strcspn         ; size_t strcspn(const char *s, const char *reject)
	extern strchr

; TODO RENAME

strcspn:
	push rbp
	mov rbp, rsp

	mov r8, rdi	; s
	mov r9, rsi	; reject
	mov r14, 0
	
LOOP:
	cmp byte [r8], 0	; compare if s char is 0
	je END		; go to end

	mov rdi, r9
	mov sil, [r8]
	call strchr wrt ..plt
	cmp rax, 0
	jne END

	inc r8
	inc r14
	
	jmp LOOP		; loop
	
END:
	mov rax, r14
	mov rsp, rbp
	pop rbp
	ret
