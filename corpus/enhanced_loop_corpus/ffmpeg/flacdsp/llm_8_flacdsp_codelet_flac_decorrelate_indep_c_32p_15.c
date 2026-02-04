#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < len; j += 2) {
        for (i = 0; i < channels; i++) {
            int val1 = (int)((unsigned int)in[i][j] << shift);
            int val2 = (j + 1 < len) ? (int)((unsigned int)in[i][j+1] << shift) : 0;
            samples[i][j] = val1;
            if (j + 1 < len) {
                samples[i][j+1] = val2;
            }
        }
    }
}
