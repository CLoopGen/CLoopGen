#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int16_t **samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index arrays to simulate irregular access pattern
    int j, i;
    // Simulate indirect access via an index mapping (e.g., reverse order access)
    int *index_map = (int*)alloca(len * sizeof(int));
    for (int temp_j = 0; temp_j < len; temp_j++) {
        index_map[temp_j] = len - 1 - temp_j; // reverse indexing
    }
    for (j = 0; j < len; j++) {
        int mapped_j = index_map[j];
        for (i = 0; i < channels; i++) {
            samples[i][mapped_j] = (int)((unsigned int)in[i][mapped_j] << shift);
        }
    }
}
