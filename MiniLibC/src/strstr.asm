BITS 64
	global strstr	; char *strstr(const char *meule_de_foin, const char *aiguille)
	section .text

strstr:
	push rbp
	mov rbp, rsp

	mov rbx, rdi		; meule de foin
	mov rcx, rsi		; aiguille
	;; 	cmp byte [rcx], 0	;check if aiguille is NULL
	;; 	jz END

LOOP:
	cmp byte [rcx], 0h	; check if first is empty
	jz FOUND
	cmp byte [rbx], 0h	; check end of meule
	jz ENDF			; NOT FOUND

	mov r8, [rcx]		; moove
	cmp byte [rbx], r8b	; check if found occurence with aiguille
	jz FOUND
	
	inc rbx			; *meule++
	jmp LOOP

FOUND:
	mov rax, rbx		; stock meule *
	jmp FOUNDLOOP
	
FOUNDLOOP:
	cmp byte [rcx], 0h
	jz END

	mov r9, [rcx]
	cmp byte [rbx], r9b
	jnz NOTFOUND		; NOT FOUND

	cmp byte[rbx], 0
	jz NOTFOUND
	
	inc rcx
	inc rbx
	jmp FOUNDLOOP

NOTFOUND:
	mov rcx, rsi
	mov rax, 0
	cmp byte[rbx], 0h
	jz END		; NOT FOUND
	inc rbx
	jmp LOOP

ENDF:
	mov rax, 0
	pop rbp
	ret
	
END:
	pop rbp
	ret
