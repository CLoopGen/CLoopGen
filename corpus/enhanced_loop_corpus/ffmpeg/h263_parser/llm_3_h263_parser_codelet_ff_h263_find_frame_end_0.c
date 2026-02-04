#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int vop_found;
extern int i;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated using stride-like pattern as proxy for indirect)
    int *indices = (int*)malloc(buf_size * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < buf_size; j++) {
        indices[j] = buf_size - 1 - j; // Reverse order access pattern
    }
    for (i = 0; i < buf_size; i++) {
        int idx = indices[i]; // Indirect access through index remapping
        state = (state << 8) | buf[idx];
        if (state >> (32 - 22) == 32) {
            i++;
            vop_found = 1;
            free(indices);
            return;
        }
    }
    free(indices);
}
