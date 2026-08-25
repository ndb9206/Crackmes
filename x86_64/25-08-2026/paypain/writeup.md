# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/5c9d9eea33c5d4419da55641
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 2.0
Tools User: objdump

# Static Analysis
    107b:	83 ff 02             	cmp    $0x2,%edi
    107e:	75 50                	jne    10d0 <main+0x70>

- Input value stored in argv[1] and it stored in address 0x8(rsi) or %r8
- Code from 108b to 1093 that is similar with strlen()
    108b:	f2 ae                	repnz scas (%rdi),%al
    108d:	48 89 c8             	mov    %rcx,%rax
    1090:	48 f7 d0             	not    %rax
    1093:	48 83 e8 01          	sub    $0x1,%rax
- Length of input value is greater than 10 bytes.
    1097:	83 f8 08             	cmp    $0x8,%eax
    109a:	76 34                	jbe    10d0 <main+0x70>

- Next, it is a loop that count value 0x62
    109c:	41 0f b6 00          	movzbl (%r8),%eax           ; assign string to eax
    10a0:	84 c0                	test   %al,%al              ; check eax: NULL -> end
    10a2:	74 2c                	je     10d0 <main+0x70>     
    10a4:	49 8d 50 01          	lea    0x1(%r8),%rdx        ; assign rdx = s[1]
    10a8:	31 c9                	xor    %ecx,%ecx            ; ecx = 0
    10aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)     
    10b0:	3c 62                	cmp    $0x62,%al            ; compare s[i] with 0x62 that is 'b'
    10b2:	0f 94 c0             	sete   %al

- If in input value don't have 3 characters that is 'b', it fails
    10c6:	83 f9 03             	cmp    $0x3,%ecx
    10c9:	74 35                	je     1100 <main+0xa0>

- Next, it has a condition that compare between 0x4(%r8) and 0x40 that is '@'
- 0x4(%r8) is fifth character in input value.

# Solution
- In input value must have: 
    + length greater than 10
    + 3 characters 'b'
    + fifth character is '@'

- Example: abbb@123456
