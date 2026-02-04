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
    int *indices = (int*)malloc(buf_size * sizeof(int));
    if (!indices) return;
    
    // Precompute strided access pattern: every 2nd element forward, then fill gaps
    int j, step = 2;
    int idx = 0;
    for (j = 0; j < buf_size; j++) {
        indices[j] = (j * step) % buf_size;  // Strided access with wrap-around
    }

    for (j = 0; j < buf_size; j++) {
        int pos = indices[j];
        state = (state << 8) | buf[pos];
        if (state == 438) {
            i = pos + 1;
            vop_found = 1;
            free(indices);
            return;
        }
    }
    free(indices);
}
