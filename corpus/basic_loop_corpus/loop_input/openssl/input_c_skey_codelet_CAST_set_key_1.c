#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int len;
unsigned char *data;
unsigned int x[16];
int i;

void init_vars() {
    len = 16;
    data = (unsigned char *)malloc(len * sizeof(unsigned char));
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (i = 0; i < len; i++) {
        data[i] = (unsigned char)(i & 0xFF);
        x[i] = 0; // Initialize to zero to distinguish after loop
    }
}