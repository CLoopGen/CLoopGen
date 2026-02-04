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
    // Variant 2: Strided memory access with indirect indexing using a step pattern
    int stride = 4; // Access every 4th element in samples, simulate strided output
    int total = channels * len;
    int idx = 0;
    for (j = 0; j < len; j++) {
        for (i = 0; i < channels; i++) {
            int src_idx = j;
            int32_t value = in[i][src_idx];
            // Write to strided position in samples
            if ((idx % stride) == 0) {
                samples[idx / stride] = (int16_t)((unsigned int)value << shift);
            }
            idx++;
            // Ensure we don't overflow samples buffer assuming it's sized for stride-reduced output
            if (idx / stride >= len * channels / stride) break;
        }
        if (idx / stride >= len * channels / stride) break;
    }
    // Update samples pointer if needed (side effect not fully preserved, but logic adapted)
}
