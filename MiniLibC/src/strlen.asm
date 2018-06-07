BITS 64

SECTION .text                   ; Code section.

global	strlen      ; int strlen(const char *string);

; TODO RENAME
strlen:
       push rbp
        mov rbp, rsp

        mov rbx, rdi            ; first argument
        xor rax, rax            ; length

.LOOP:
        cmp byte [rbx], 0h      ; compare to 0 (null byte)
        jz  .END                 ; end of string
        inc rax                 ; length += 1
        inc rbx                 ; next byte
        jmp .LOOP

.END:    pop rbp
        ret
