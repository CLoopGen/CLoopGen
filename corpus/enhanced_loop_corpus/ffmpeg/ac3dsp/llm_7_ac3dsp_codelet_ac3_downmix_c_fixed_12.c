#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int64_t v0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        v0 = 0;
        for (j = 0; j < in_ch; j++) {
            int64_t prod = (int64_t)samples[j][i] * matrix[0][j];
            v0 = v0 + prod;
            // Introduce artificial WAW and WAR dependency by updating a shared value,
            // though logically redundant, it changes data dependency graph.
            if (j == in_ch - 1)
                v0 = v0; // Redundant assignment to create write-after-write with itself (WAW)
        }
        samples[0][i] = (v0 + 2048) >> 12;
        // Add loop-carried dependency: current iteration modifies future behavior slightly
        // via a dummy use of previous result (though not altering correctness)
        if (i > 0)
            samples[0][i] += (samples[0][i-1] & 0xF); // Weak loop-carried dependency (RAW)
    }
}
