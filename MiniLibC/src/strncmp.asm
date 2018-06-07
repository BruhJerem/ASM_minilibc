	BITS 64

	global strncmp	; int strncmp(const char* s1, const char* s2, size_t n)
	section .text

strncmp:
        push rbp
        mov rbp, rsp

        mov r10b, 0             ; init i = 0
        ;edx = n
LOOP:
        mov r8b, [rsi]          ; moove byte s1
        mov r9b, [rdi]          ; moove byte s2

        cmp r10d, edx           ; if n == i
        jz END
        cmp r8b, 0              ; check end s1
        jz END                  ; moove to end
        cmp r9b, 0              ; check end s2
        jz END                  ; moove to end
        cmp r8b, r9b            ; if not the same
        jnz END                 ; moove to end but ret diff

        inc rsi
        inc rdi
        inc r10                 ; i++
        jmp LOOP

END:
        sub r9b, r8b            ; *s2 - *s1
	movsx rax, r9b
	pop rbp
	ret

