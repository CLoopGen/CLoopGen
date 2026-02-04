#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32;

uint32 imagewidth;
unsigned char *inptr;
short *nextptr;
uint32 j;

void init_vars() {
    imagewidth = 131072;  // 131072 bytes input -> 262144 bytes output (shorts), ~0.01 sec on modern CPU

    inptr = (unsigned char*)malloc(imagewidth * sizeof(unsigned char));
    nextptr = (short*)malloc(imagewidth * sizeof(short));

    if (!inptr || !nextptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (uint32 i = 0; i < imagewidth; ++i) {
        inptr[i] = (unsigned char)(i & 0xFF);
    }

    j = 0;
}