# Information
Source: crackmes.one
Link:
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.5
Tools User: objdump

# Static Analysis
- Input value is stored in agev[1]
- In address -0x12(%rbp), it stores value 0x31201130363c1b55 ~ 8 bytes
- In address -0xa(%rbp), it stores value 0x1730
- Because the program use little endian, string is stored in thist is 0x551b3c36301120313017

- Next, string xor 0x55555555555555555555 (0x55 ever a byte)
    1219:	0f b6 44 05 ee       	movzbl -0x12(%rbp,%rax,1),%eax
    121e:	83 f0 55             	xor    $0x55,%eax

- Result string compares with input value

# Solution
Code C that caculate result string:
#include <stdio.h>

int main() {
	long long x = 0x551b3c3630112031;
	long long y = 0x5555555555555555;
	long long z = x ^ y;
	int v = 0x3017 ^ 0x5555;
	printf("%llx %x\n", z, v);
	return 0;
}

- Result: 4e6963654475646542 ~ NiceDudeB
