# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/5c2acb8933c5d46a3882b8d4
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.5
Tools User: objdump and gdb

# Static Analysis
- Main fuction enter value serial in argv[1] ~ -0x8(%rbp)
- Input value give checkSerial()
- In checkSerial function, length of input value equals 0x10 ~ 16
- Value stored in -0x28(%rbp)
    11a4:       48 8b 45 d8             mov    -0x28(%rbp),%rax
    11a8:       48 89 c7                mov    %rax,%rdi
    11ab:       e8 90 fe ff ff          call   1040 <strlen@plt>
    11b0:       48 83 f8 10             cmp    $0x10,%rax

- Using value in address -0x14(%rbp) as i in while
- In loop, it has condition that s[i] - s[i+1] = 0xffffffff ~ -1

    11bd:       c7 45 ec 00 00 00 00    movl   $0x0,-0x14(%rbp)
    11c4:       eb 3d                   jmp    1203 <checkSerial+0x6c>
    11c6:       8b 45 ec                mov    -0x14(%rbp),%eax
    11c9:       48 63 d0                movslq %eax,%rdx
    11cc:       48 8b 45 d8             mov    -0x28(%rbp),%rax             ; stored value in s[i]
    11d0:       48 01 d0                add    %rdx,%rax
    11d3:       0f b6 00                movzbl (%rax),%eax
    11d6:       0f be d0                movsbl %al,%edx                     ; stored s[i] in edx
    11d9:       8b 45 ec                mov    -0x14(%rbp),%eax
    11dc:       48 98                   cltq
    11de:       48 8d 48 01             lea    0x1(%rax),%rcx               ; rcx add 1
    11e2:       48 8b 45 d8             mov    -0x28(%rbp),%rax 
    11e6:       48 01 c8                add    %rcx,%rax                    ; rax store s[i+1]
    11e9:       0f b6 00                movzbl (%rax),%eax  
    11ec:       0f be c0                movsbl %al,%eax
    11ef:       29 c2                   sub    %eax,%edx
    11f1:       89 d0                   mov    %edx,%eax
    11f3:       83 f8 ff                cmp    $0xffffffff,%eax             ; compare with -1
    11f6:       74 07                   je     11ff <checkSerial+0x68>

# Solution
- Length of argv[1] = 16
- it may be 1212121212121212
