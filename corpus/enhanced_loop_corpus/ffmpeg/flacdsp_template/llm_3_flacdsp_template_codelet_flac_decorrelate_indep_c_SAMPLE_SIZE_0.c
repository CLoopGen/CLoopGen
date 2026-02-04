#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect (gather) access via pointer array to simulate irregular memory access
    // We create a local index map to access 'in' indirectly, simulating non-sequential access
    int *index_map = (int*)alloca(channels * sizeof(int));
    for (int c = 0; c < channels; c++) {
        index_map[c] = channels - 1 - c; // Reverse order access: indirect access pattern
    }
    for (j = 0; j < len; j++) {
        for (int idx = 0; idx < channels; idx++) {
            i = index_map[idx]; // Indirect channel indexing
            (*samples++) = (int)((unsigned int)in[i][j] << shift);
        }
    }
}
