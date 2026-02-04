#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

uint64_t mask;
AVRational *depth;
unsigned int result;

void init_vars() {
    depth = (AVRational *)calloc(1, sizeof(AVRational));
    if (!depth) {
        exit(1);
    }
    depth->num = 0;
    depth->den = 1;

    mask = UINT64_C(0xABCDEF1234567890);
    result = 50000000;
}