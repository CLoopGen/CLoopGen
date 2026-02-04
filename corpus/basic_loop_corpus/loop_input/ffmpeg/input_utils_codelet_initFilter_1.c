#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **filterPos;
int dstW = 1000;
int i;
int filter2Size = 64;
int minFilterSize = 8;
int64_t *filter2;
int64_t fone = (1LL << 30);

void init_vars() {
    // Allocate filter2 as a 2D array of size [dstW][filter2Size]
    filter2 = (int64_t *)calloc(dstW * filter2Size, sizeof(int64_t));
    
    // Initialize filter2 with small alternating positive/negative values to allow cutoff condition triggering
    for (int i = 0; i < dstW; i++) {
        for (int j = 0; j < filter2Size; j++) {
            int64_t val = (j % 2 == 0) ? (fone * 0.0005) : -(fone * 0.0004);
            filter2[i * filter2Size + j] = val;
        }
    }

    // Allocate filterPos array of dstW int32_t pointers
    filterPos = (int32_t **)malloc(dstW * sizeof(int32_t*));
    for (int i = 0; i < dstW; i++) {
        filterPos[i] = (int32_t *)malloc(sizeof(int32_t));
        *filterPos[i] = 0;
    }
}