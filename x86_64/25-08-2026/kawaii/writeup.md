# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/5d17962b33c5d41c6d56e1f2
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 2.0
Tools User: objdump and gdb

# Static Analysis
- Program has 2 input value that is stored in address -0xb0(%rbp) and -0x60(%rbp)
- The first value is introduced into encr function.
- Return value will compare with the second input value
    12ff:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
    1306:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    130a:	48 89 d6             	mov    %rdx,%rsi
    130d:	48 89 c7             	mov    %rax,%rdi
    1310:	e8 6b fd ff ff       	call   1080 <strcmp@plt>

- Input argument of encr function is the frist input value and a array has lenth is 10 byte that stored retrun value.
    12d5:	bf 0a 00 00 00       	mov    $0xa,%edi
    12da:	e8 b1 fd ff ff       	call   1090 <malloc@plt>
    12df:	48 89 85 48 ff ff ff 	mov    %rax,-0xb8(%rbp)
    12e6:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
    12ed:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    12f4:	48 89 d6             	mov    %rdx,%rsi
    12f7:	48 89 c7             	mov    %rax,%rdi
    12fa:	e8 aa fe ff ff       	call   11a9 <encr>

In encr function:
    - the frist input value is stored in address -0x28(%rbp)
    - the array is assigned in address -0x30(%rbp)
    - count variable is stored in -0x18(%rbp)
    - -0x1c(%rbp) is allocated to caculate sum of those values of the frist input value.
        11cd:	48 63 d0             	movslq %eax,%rdx
        11d0:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
        11d4:	48 01 d0             	add    %rdx,%rax
        11d7:	0f b6 00             	movzbl (%rax),%eax
        11da:	0f be c0             	movsbl %al,%eax
        11dd:	01 45 e4             	add    %eax,-0x1c(%rbp)

    - Next, it is a loop that has 8 times
        1258:	83 7d ec 08          	cmpl   $0x8,-0x14(%rbp)
        125c:	7e aa                	jle    1208 <encr+0x5f>
    - output[i] = sum / (len(input) + i)
        1222:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
        1226:	48 89 d8             	mov    %rbx,%rax
        1229:	ba 00 00 00 00       	mov    $0x0,%edx
        122e:	48 f7 f1             	div    %rcx
        1231:	88 45 e3             	mov    %al,-0x1d(%rbp)
        1234:	0f be 75 e3          	movsbl -0x1d(%rbp),%esi
        1238:	8b 45 e4             	mov    -0x1c(%rbp),%eax

    - After loop, sum += sum / output[i]

# Solution
- Input2 = encr(input1)
- Code C:
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int len = strlen(argv[1]);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += argv[1][i];
	}

	char* num = malloc(len);
	for (int i = 0; i < 9; i++) {
		char byte = (char)((uint64_t)sum / (len + i));
		sum += sum / (int)byte;
		num[i] = byte;
	}
	
	printf("%s\n", num);
	free(num);
	return 0;
}

- Example:
    + Input1: aaaaaaaaa
    + Input2: aXQKFB>;9
