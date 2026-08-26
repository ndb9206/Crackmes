#include <stdio.h>

int main() {
	long long x = 0x551b3c3630112031;
	long long y = 0x5555555555555555;
	long long z = x ^ y;
	int v = 0x3017 ^ 0x5555;
	printf("%llx %x\n", z, v);
	return 0;
}
