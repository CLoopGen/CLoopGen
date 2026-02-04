#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int Int32;

Int32 alphaSize = 512;
Int32 i;
Int32 *freq;
Int32 weight[516];

void init_vars() {
    freq = (Int32*)malloc(alphaSize * sizeof(Int32));
    if (!freq) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (Int32 idx = 0; idx < alphaSize; idx++) {
        freq[idx] = rand() & 0xFFFF; 
    }
    
    memset(weight, 0, sizeof(weight));
}