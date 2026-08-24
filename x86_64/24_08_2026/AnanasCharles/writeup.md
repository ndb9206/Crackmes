# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/6617d3a5cddae72ae250c556
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 2.0
Tools User: objdump and gdb

# Static Analysis
- Program input in argv[1]
    1384:	48 83 ec 40          	sub    $0x40,%rsp
    1388:	89 7d cc             	mov    %edi,-0x34(%rbp)
    138b:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
    138f:	83 7d cc 02          	cmpl   $0x2,-0x34(%rbp)

- Input value make to decode_pin function
- In decode_pin:
    + Length of pin is 4
        1287:	83 7d fc 03          	cmpl   $0x3,-0x4(%rbp)
    + Count variable strored in address -0x4(%rbp) ~ i
    + In loop, pin[i] subtract 0x35. Next, if pin[i] < 0 then pin[i] + 0xa else pin[i] + 0x30

- Return value campares with value in 0xc3d(%rip) that assign -0x10(%rbp)

# Solution
- Use gdb to see value in 0xc3d(%rip)
    + breakpoint in address 0x..415
    + use x/s $rsi that see string ~ 8446

- String is 8446 => input = 3991
