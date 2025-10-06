section .data
    msg db 'Hello, World', 10   ; 10 = newline (\n)
    len equ $ - msg             ; length of the string

section .text
    global main

main:
    mov rax, 1          ; syscall number 1 = write
    mov rdi, 1          ; file descriptor 1 = stdout
    mov rsi, msg        ; address of the message
    mov rdx, len        ; length of the message
    syscall             ; perform system call (write)

    mov rax, 60         ; syscall number 60 = exit
    xor rdi, rdi        ; exit code 0
    syscall             ; perform system call (exit)
