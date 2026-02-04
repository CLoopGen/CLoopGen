#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t **alpSrcPtr;
int neg;
int i;
int16_t **tmpA;

void init_vars() {
    neg = 131072; 

    alpSrcPtr = (int16_t**)calloc(neg, sizeof(int16_t*));
    tmpA = (int16_t**)calloc(neg, sizeof(int16_t*));

    int16_t *dummy_row = (int16_t*)calloc(1024, sizeof(int16_t));
    for (int j = 0; j < neg; j++) {
        alpSrcPtr[j] = dummy_row;
    }
}