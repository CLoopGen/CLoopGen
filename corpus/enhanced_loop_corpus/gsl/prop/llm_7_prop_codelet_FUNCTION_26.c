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
    int64_t *data = (int64_t*)calloc(size1, sizeof(int64_t));
    if (!data) return;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            data[i] = i + j; // Write after write (WAW) across inner loop; no loop-carried dep in j-loop
        }
        // Each i-th element written repeatedly, last value is i + (size2 - 1)
    }

    free(data);
}
