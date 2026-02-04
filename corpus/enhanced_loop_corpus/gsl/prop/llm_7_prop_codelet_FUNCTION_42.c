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
    int64_t *data = (int64_t*)malloc(size1 * sizeof(int64_t));
    if (!data) return;

    for (i = 0; i < size1; i++) {
        data[i] = i + 1; // Write to data[i]
        for (j = 0; j < size2; j++) {
            if (j < i && i > 0) {
                data[i] += data[i-1]; // RAW dependency: read data[i-1] written in previous outer iteration
                                     // Loop-carried dependency across outer loop iterations (i)
            }
        }
    }

    free(data);
}
