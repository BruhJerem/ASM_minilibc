	BITS 64

	global strcasecmp 	; int strcasecmp(const char *s1, const char *s2)
	section .text

strcasecmp:
        push rbp
        mov rbp, rsp

        mov r8, 0               ; init 0
        mov r9, 0               ; init 0

LOOP:
        mov r8b, [rsi]          ; moove byte s1
        cmp r8b, 65
	jl LOOP_CHECK
        cmp r8b, 90
        jg LOOP_CHECK
	add r8b, 32             ; and binaire

LOOP_CHECK:
	mov r9b, [rdi]          ; moove byte s2
        cmp r9b, 65
        jl LOOP_MAIN
        cmp r9b, 90
        jg LOOP_MAIN
        add r9b, 32             ; and binaire

LOOP_MAIN:
        cmp r8b, r9b            ; if not same
        jnz END                 ; end
        cmp r8b, 0h             ; check end
	jz END
        cmp r9b, 0h             ; check end
        jz END
        inc rsi
	inc rdi
	jmp LOOP

END:
    	sub r9, r8
	mov rax, r9
	pop rbp
	ret

