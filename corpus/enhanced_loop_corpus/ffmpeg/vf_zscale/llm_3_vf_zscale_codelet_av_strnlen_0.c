#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Simulate an indirect access pattern using a stride-like alternating pattern
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    
    for (i = 0; i < len; i++) {
        indices[i] = i; // Identity mapping for indirect access
    }

    size_t j;
    for (j = 0; j < len; j++) {
        i = indices[j];
        if (!s[i]) {
            break;
        }
    }
    if (j == len) {
        i = len;
    }

    free(indices);
}
