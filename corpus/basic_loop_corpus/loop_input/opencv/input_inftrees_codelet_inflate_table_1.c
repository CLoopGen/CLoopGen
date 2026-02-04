#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int codes = 1000000;
unsigned int sym;
unsigned short *lens;
unsigned short count[16] = {0};

void init_vars() {
    lens = (unsigned short*)malloc(codes * sizeof(unsigned short));
    if (!lens) {
        exit(1);
    }
    for (unsigned int i = 0; i < codes; i++) {
        lens[i] = rand() % 16;
    }
}