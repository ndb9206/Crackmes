# Information
Source: crackmes.one
Link: https://crackmes.one/download/crackme/655b43750f4238b24302bc42
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.8
Tools User: objdump and gdb

# Static Analysis:
- Input value checked in check_serial function.
- In serial_function:
    1191:       48 89 7d c8             mov    %rdi,-0x38(%rbp)
    1195:       c7 45 d0 58 00 00 00    movl   $0x58,-0x30(%rbp)
    119c:       c7 45 d4 6e 00 00 00    movl   $0x6e,-0x2c(%rbp)
    11a3:       c7 45 d8 60 00 00 00    movl   $0x60,-0x28(%rbp)
    11aa:       c7 45 dc 6b 00 00 00    movl   $0x6b,-0x24(%rbp)
    11b1:       c7 45 e0 7b 00 00 00    movl   $0x7b,-0x20(%rbp)
    11b8:       c7 45 e4 56 00 00 00    movl   $0x56,-0x1c(%rbp)
    11bf:       c7 45 e8 66 00 00 00    movl   $0x66,-0x18(%rbp)
    11c6:       c7 45 ec 75 00 00 00    movl   $0x75,-0x14(%rbp)
    11cd:       c7 45 f8 08 00 00 00    movl   $0x8,-0x8(%rbp)

- Input valule stored in -0x38(%rbp) ~ suppose value[]
    11d4:       48 8b 45 c8             mov    -0x38(%rbp),%rax
    11d8:       48 89 c7                mov    %rax,%rdi
    11db:       e8 60 fe ff ff          call   1040 <strlen@plt>
    11e0:       48 89 c2                mov    %rax,%rdx
    11e3:       8b 45 f8                mov    -0x8(%rbp),%eax
    11e6:       48 98                   cltq
    11e8:       48 39 c2                cmp    %rax,%rdx
    11eb:       74 07                   je     11f4 <check_serial+0x6b>

- Length of input value is 8 bytes
- Value stored in address -0x4(%rbp) is loop variable
- In loop, value[i] ~ argv[1] ~ a and i ~ argv[2] ~ b give transform function
- In transform function:
    1169:       55                      push   %rbp
    116a:       48 89 e5                mov    %rsp,%rbp
    116d:       89 f8                   mov    %edi,%eax                ; Assign by a
    116f:       89 75 f8                mov    %esi,-0x8(%rbp)          ; Assign by b
    1172:       88 45 fc                mov    %al,-0x4(%rbp)           ; Assign by a
    1175:       0f be 45 fc             movsbl -0x4(%rbp),%eax          ; Assign by a
    1179:       8b 55 f8                mov    -0x8(%rbp),%edx          ; Assign by b
    117c:       83 c2 07                add    $0x7,%edx                ; b + 7
    117f:       31 d0                   xor    %edx,%eax                ; (b + 7) ^ a
    1181:       83 c0 0d                add    $0xd,%eax                ; ((b+7) ^ a) + 13
    1184:       83 e0 7f                and    $0x7f,%eax               ; (((b+7) ^ a) + 13) & 0x7f
    1187:       5d                      pop    %rbp
    1188:       c3                      ret

- Return value compares with:
    1169:       55                      push   %rbp
    116a:       48 89 e5                mov    %rsp,%rbp
    116d:       89 f8                   mov    %edi,%eax
    116f:       89 75 f8                mov    %esi,-0x8(%rbp)
    1172:       88 45 fc                mov    %al,-0x4(%rbp)
    1175:       0f be 45 fc             movsbl -0x4(%rbp),%eax
    1179:       8b 55 f8                mov    -0x8(%rbp),%edx
    117c:       83 c2 07                add    $0x7,%edx
    117f:       31 d0                   xor    %edx,%eax
    1181:       83 c0 0d                add    $0xd,%eax
    1184:       83 e0 7f                and    $0x7f,%eax
    1187:       5d                      pop    %rbp
    1188:       c3                      ret
Code:
    1223:       8b 44 85 d0             mov    -0x30(%rbp,%rax,4),%eax
    1227:       39 c2                   cmp    %eax,%ed

# Solution
- char[i] = ((target[i] - 13) & 0x7F) ^ (i + 7)
=> Input: CiZdEtin
