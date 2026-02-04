#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t **alpSrcPtr;
int i;
int end;
int16_t **tmpA;

void init_vars() {
    end = 131072; 
    i = 0;

    alpSrcPtr = (int16_t**)calloc(end, sizeof(int16_t*));
    tmpA = (int16_t**)calloc(end, sizeof(int16_t*));

    for (int idx = 0; idx < end; idx++) {
        alpSrcPtr[idx] = (int16_t*)malloc(16 * sizeof(int16_t));
        for (int j = 0; j < 16; j++) {
            alpSrcPtr[idx][j] = (int16_t)(idx + j);
        }
        tmpA[idx] = NULL;
    }
}