# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/5b8a37a433c5d45fc286ad83
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.3
Tools User: objdump and gdb

# Static Analysis
    11cc:       89 7d fc                mov    %edi,-0x4(%rbp)
    11cf:       48 89 75 f0             mov    %rsi,-0x10(%rbp)
    11d3:       83 7d fc 02             cmpl   $0x2,-0x4(%rbp)

    11e4:       48 89 c7                mov    %rax,%rdi
    11e7:       e8 54 fe ff ff          call   1040 <strlen@plt>
    11ec:       48 83 f8 0a             cmp    $0xa,%rax            ; length equals 10
- Input enter in argv[1]
    11f2:       48 8b 45 f0             mov    -0x10(%rbp),%rax     ; argv[0]
    11f6:       48 83 c0 08             add    $0x8,%rax            ; argv[1]
    11fa:       48 8b 00                mov    (%rax),%rax          
    11fd:       48 83 c0 04             add    $0x4,%rax            ; argv[1][4]
    1201:       0f b6 00                movzbl (%rax),%eax  
    1204:       3c 40                   cmp    $0x40,%al            ; 0x40 ~ @
    1206:       75 2d                   jne    1235 <main+0x71>

# Solution
- Input: abcd@defgh
