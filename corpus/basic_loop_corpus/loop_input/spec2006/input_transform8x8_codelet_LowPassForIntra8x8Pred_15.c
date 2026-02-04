#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *PredPel;
int i;
int LoopArray[25];

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (adjustable)
    int *temp_array = (int *)calloc(data_size, sizeof(int));
    
    if (!temp_array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    PredPel = temp_array;

    for (int idx = 0; idx < 25; idx++) {
        LoopArray[idx] = idx * 3 + 7; // Arbitrary initialization
    }
}