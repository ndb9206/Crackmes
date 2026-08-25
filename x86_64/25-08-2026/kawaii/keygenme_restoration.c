#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void encr(char* input, char* output) {
	int sum = 0;
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		sum += (unsigned int)input[i];
	}

	char byte;
	for (int i = 0; i < 9; i++) {
		byte = (char)((uint64_t)sum / (len + i));
		sum += sum / (int)byte;
		output[i] = byte;
	}
}

int main() {
    char input1[100];
    char input2[100];

    printf("Enter name: ");
    fflush(stdout);
    scanf("%99s", input1); 

    printf("Enter key: ");
    fflush(stdout);
    scanf("%99s", input2);

    char* result = malloc(10);
    encr(input1, result);
    if (strcmp(result, input2) == 0) {
	    printf("Good job!\nNow write keygen)\n");
    } else {
	    printf("Wrong key! Try again)\n");
    }	    
    free(result);
    return 0;
}
