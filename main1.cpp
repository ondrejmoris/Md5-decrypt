
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <sstream>

uint8_t* hex_str_to_uint8(const char* string) {

    if (string == NULL)
        return NULL;

    size_t slength = strlen(string);
    if ((slength % 2) != 0) // must be even
        return NULL;

    size_t dlength = slength / 2;

    uint8_t* data = (uint8_t*)malloc(dlength);

    memset(data, 0, dlength);

    size_t index = 0;
    while (index < slength) {
        char c = string[index];
        int value = 0;
        if (c >= '0' && c <= '9')
            value = (c - '0');
        else if (c >= 'A' && c <= 'F')
            value = (10 + (c - 'A'));
        else if (c >= 'a' && c <= 'f')
            value = (10 + (c - 'a'));
        else
            return NULL;

        data[(index / 2)] += value << (((index + 1) % 2) * 4);

        index++;
    }

    return data;
}

// Prototype of function from .cu file
void run_cuda(uint8_t* hash, int len, unsigned int p);

int main(int argc, char** argv)
{
	int len = atoi(argv[1]);

    char hash[32];
    strcpy(hash, argv[2]);

    unsigned int p = pow(26,len);

    uint8_t *result = (uint8_t*)malloc(sizeof(uint8_t)*16);

    result = hex_str_to_uint8(hash);
   
    printf("Number of combination is %d\n",p);
	// Function calling
	run_cuda(result, len, p);
	return 0;
}

