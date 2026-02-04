#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; count > 8; count -= 8) {
        int *base_array = (int*)malloc(64 * sizeof(int));  // Larger array for strided access
        int stride = 8;
        for (int i = 0; i < 8; i++) {
            base_array[i * stride] = i;  // Strided memory access (every 8th element)
        }
        for (int i = 0; i < 8; i++) {
            base_array[i * stride] *= 2;  // Operate on same strided pattern
        }
        free(base_array);
    }
}
