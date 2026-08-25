#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("[!] WRONG Password");
		exit(-1);
	}

	if (strlen(argv[1]) <= 10) {
		printf("[!] WRONG Password");
		exit(-1);
	}
	
	int count = 0;
	for (int i = 0; i < strlen(argv[1]); i++) {
		if (argv[1][i] == 'b') {
			count++;
		}
	}

	if (count != 3) {
		printf("[!] WRONG Password");
		exit(-1);
	}

	if (argv[1][4] != '@') {
		printf("[!] WRONG Password");
		exit(-1);
	}

	printf("[+]Login Complete\n");
	printf("[+] License->FL4GiNyOUrMinDabbb@123456WiNAll\n");
	return 0;
}
