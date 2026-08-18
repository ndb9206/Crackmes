# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/5c1a939633c5d41e58e005d1
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 2.0
Tools User: objdump and gdb

# Static Analysis
    120b:       48 89 c7                mov    %rax,%rdi
    120e:       e8 3d fe ff ff          call   1050 <strlen@plt>
    1213:       48 83 f8 0b             cmp    $0xb,%rax

- Input value has length equals 0xb ~ 11 
- Caculate sum that store in address -0x14(%rbp)
    11d6:       c7 45 ec 00 00 00 00    movl   $0x0,-0x14(%rbp)

- Variable count i store in -0x18(%rbp)
- It caculates sum of all value in input value
- Finally, sum compare with 0x328 ~ 1000

# Solution
- Enter character in ascii that sum equals 1000
- Example: 
    ❯ echo -n "dddddddddd" | ./rev03
    enter the magic string
    flag is flag{!#&*/5<DMW}
