#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *data = (uint64_t*)malloc(size1 * sizeof(uint64_t));
    if (!data) return;
    for (i = 0; i < size1; i++) {
        data[i] = i;
        for (j = 0; j < size2; j++) {
            data[i] += (i + j) % 7;
        }
        // WAW: Only one write per i, no conflict
        // RAW: data[i] read after write in accumulation
        // Loop-carried dependence removed: each i is independent due to array partitioning
    }
    free(data);
}
