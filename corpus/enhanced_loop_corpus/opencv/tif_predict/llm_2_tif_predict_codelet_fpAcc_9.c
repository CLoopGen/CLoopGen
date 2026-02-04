#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; count > 8; count -= 8) {
        int *dummy_array = (int*)malloc(8 * sizeof(int));
        for (int i = 0; i < 8; i++) {
            dummy_array[i] = i;  // Consecutive memory access
        }
        for (int i = 0; i < 8; i++) {
            dummy_array[i] += 1;  // Another consecutive pass
        }
        free(dummy_array);
    }
}
