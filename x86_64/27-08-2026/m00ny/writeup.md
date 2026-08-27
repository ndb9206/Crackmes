# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/5cb7533133c5d4419da5584b
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.5
Tools User: objdump

# Static Analysis
- Program input value in argv[1] that is stored in -0x68(%rbp)
- argv[0] is stored in -0x70(%rbp)
- Next:
   123d:	c7 45 ab 00 00 00 00 	movl   $0x0,-0x55(%rbp)         ; 
    1244:	c6 45 af 00          	movb   $0x0,-0x51(%rbp)         ; assign 
    1248:	c6 45 ac 30          	movb   $0x30,-0x54(%rbp)        ; assign target[1] = 0x30
    124c:	48 8b 45 90          	mov    -0x70(%rbp),%rax         
    1250:	48 8b 00             	mov    (%rax),%rax
    1253:	0f b6 40 05          	movzbl 0x5(%rax),%eax           
    1257:	88 45 ab             	mov    %al,-0x55(%rbp)          ; assign target[0] = input[5]
    125a:	48 8b 45 90          	mov    -0x70(%rbp),%rax         
    125e:	48 8b 00             	mov    (%rax),%rax
    1261:	0f b6 40 02          	movzbl 0x2(%rax),%eax
    1265:	88 45 ad             	mov    %al,-0x53(%rbp)          ; assign target[2] = input[2]
    1268:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    126c:	48 8b 00             	mov    (%rax),%rax
    126f:	0f b6 40 06          	movzbl 0x6(%rax),%eax           ; assign target[3] = input[6]
    1273:	88 45 ae             	mov    %al,-0x52(%rbp)

- Target compares with argv[1]
    12c9:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    12cd:	48 83 c0 08          	add    $0x8,%rax
    12d1:	48 8b 00             	mov    (%rax),%rax
    12d4:	48 8d 55 ab          	lea    -0x55(%rbp),%rdx
    12d8:	48 89 d6             	mov    %rdx,%rsi
    12db:	48 89 c7             	mov    %rax,%rdi
    12de:	e8 9d fd ff ff       	call   1080 <strcmp@plt>

# Solution
- argv[0] is crackMe-by-m00ny-1 -> argv[1] is c0ck
