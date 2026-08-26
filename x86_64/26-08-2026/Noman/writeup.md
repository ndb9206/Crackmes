# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/62072dd633c5d46c8bcbfd9b
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.8
Tools User: objdump

# Static Analysis
- Program stores input value in argv[1] and in -0x28(%rbp)
    117d:	48 83 ec 30          	sub    $0x30,%rsp
    1181:	89 7d dc             	mov    %edi,-0x24(%rbp)
    1184:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    1188:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    118f:	00 00 
    1191:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1195:	31 c0                	xor    %eax,%eax
    1197:	83 7d dc 02          	cmpl   $0x2,-0x24(%rbp)

- Next, input value is separated other string and other string is convert to integer value that use atoi function.
    11eb:	88 45 ef             	mov    %al,-0x11(%rbp)
    11ee:	48 8d 45 ef          	lea    -0x11(%rbp),%rax
    11f2:	48 89 c7             	mov    %rax,%rdi
    11f5:	e8 66 fe ff ff       	call   1060 <atoi@plt>

- Finally, result copares with 0x32 ~ 50

# Solution
- Input value follows:
    + Other characters is integer.
    + Sum of all value equals 50.

- Example: 1234567895

# Bug in the program with atoi
- Result string is stored in address -0x11(%rbp)
- sum is stored in address -0x10(%rbp)
- In atoi function, pointer is stop while character is 0x00. So while a char in string put in atoi function, the pointer of function read value sum and check condition if is integer 0-9 -> convert to interge
- Because sum compare with 50, bug will occur with final character is 0,1,2 that follow:
    + privious sum = 50 if final = 0, value 50 ~ 0x32 ~ '2', -> in stack is '0' in -0x10(%rbp) and '0x32' ~ '2' in -0x11(%rbp) so atoi will read 0x32 in sum -> return value equals 2 -> Final sum equals 2 + 50 = 52.
    + Similar, final = 1 -> sum = 49 + 11 = 60
    + Similar, final = 2 -> sum = 48 + 20 = 68
