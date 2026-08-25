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
