# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/5dfd77a833c5d419aa013406
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 2.0
Tools User: objdump and gdb

# Static Analysis
- Program accepts input value in argv[1]
 82d:   89 7d ec                mov    %edi,-0x14(%rbp)
 830:   48 89 75 e0             mov    %rsi,-0x20(%rbp)
 834:   83 7d ec 02             cmpl   $0x2,-0x14(%rbp)
 838:   74 13                   je     84d <main+0x28>

- Input string give checkPassword function()
- Input string stored in address -0x48(%rbp)
 73f:   48 83 ec 48             sub    $0x48,%rsp
 743:   48 89 7d b8             mov    %rdi,-0x48(%rbp)

- in address -0x36(%rbp), it stored vaulue 0x0x3166656562646162 ~ 8 bytes ~ badbeef1 ~ little-endian
- in address -0x2e(rbp), it stored value 0x3200 (movw) that -0x36 + 0x8 = -0x2e. So, value in this is badbeef12\0

 756:   48 b8 62 61 64 62 65    movabs $0x3166656562646162,%rax
 75d:   65 66 31
 760:   48 89 45 ca             mov    %rax,-0x36(%rbp)
 764:   66 c7 45 d2 32 00       movw   $0x32,-0x2e(%rbp)

- in address -0x2c(%rbp) stored 0x20a170c050a1410 and end character stored in -0x24(%rbp) = 0x6

- Next, it is loop that xor input value and value in -0x36(%rbp)
 787:   8b 45 c4                mov    -0x3c(%rbp),%eax
 78a:   48 98                   cltq
 78c:   0f b6 4c 05 ca          movzbl -0x36(%rbp,%rax,1),%ecx
 791:   8b 45 c4                mov    -0x3c(%rbp),%eax
 794:   48 63 d0                movslq %eax,%rdx
 797:   48 8b 45 b8             mov    -0x48(%rbp),%rax
 79b:   48 01 d0                add    %rdx,%rax
 79e:   0f b6 00                movzbl (%rax),%eax
 7a1:   31 c1                   xor    %eax,%ecx
- Result compare with value in address -0x2c(%rbp)
- Return 1 if true and 0 if false.
 7d8:   48 8d 4d d4             lea    -0x2c(%rbp),%rcx
 7dc:   48 8d 45 de             lea    -0x22(%rbp),%rax
 7e0:   48 89 ce                mov    %rcx,%rsi
 7e3:   48 89 c7                mov    %rax,%rdi
 7e6:   e8 f5 fd ff ff          call   5e0 <strncmp@plt>
# Solution
        String[2] = String[1] xor input
=> Input: rungirl32\0
