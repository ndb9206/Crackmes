# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/612e85d833c5d41acedffa4f
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.5
Tools User: objdump

# Static Analysis
- Program input value 3 times
- Frist, input value stored in address -0x70(%rbp) that is a string 
- Second, input value stored in address -0x78(%rbp) that is a number between 1 and 9
- Next, the program have loop that add the frist input value  and the second input value with count variable stored in -0x74(%rbp)
    1292:	c7 45 8c 00 00 00 00 	movl   $0x0,-0x74(%rbp)                 ; suppose count variable is i
    1299:	eb 20                	jmp    12bb <main+0xd2>                 
    129b:	8b 45 8c             	mov    -0x74(%rbp),%eax                 
    129e:	48 98                	cltq
    12a0:	0f b6 44 05 90       	movzbl -0x70(%rbp,%rax,1),%eax          ; make value s[i]
    12a5:	89 c2                	mov    %eax,%edx                        
    12a7:	8b 45 88             	mov    -0x78(%rbp),%eax                 ; value 2 is x
    12aa:	01 d0                	add    %edx,%eax                        ; s[i] + x
    12ac:	89 c2                	mov    %eax,%edx
    12ae:	8b 45 8c             	mov    -0x74(%rbp),%eax
    12b1:	48 98                	cltq
    12b3:	88 54 05 b0          	mov    %dl,-0x50(%rbp,%rax,1)           ; a[i] = s[i] + x
    12b7:	83 45 8c 01          	addl   $0x1,-0x74(%rbp)                 ; i++
    12bb:	8b 45 8c             	mov    -0x74(%rbp),%eax                 
    12be:	48 63 d8             	movslq %eax,%rbx
    12c1:	48 8d 45 90          	lea    -0x70(%rbp),%rax
    12c5:	48 89 c7             	mov    %rax,%rdi
    12c8:	e8 e3 fd ff ff       	call   10b0 <strlen@plt>
    12cd:	48 39 c3             	cmp    %rax,%rbx                        ; comapre with length of input value 1
    12d0:	72 c9                	jb     129b <main+0xb2>

- Result stored in address -0x50(%rbp)

# Solution
- input3[i] = input[i] + input2
- Pass: 
    input1 = aaa
    input2 = 1
    input3 = bbb
