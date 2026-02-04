#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DPCMContext {
    int16_t array[256];
    int sample[2];
    const int8_t *sol_table;
} DPCMContext;

extern DPCMContext *s;
extern int i;
extern int delta;
extern int code;
extern int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of writing to strided indices (i*2+1, i*2+2), accumulate results in local array and copy consecutively
    int16_t temp[256];
    int delta_local = delta;
    int code_local = code;
    int step_local = step;

    for (i = 0; i < 127; i++) {
        delta_local += (code_local >> 5);
        code_local += step_local;
        step_local += 2;
        temp[i * 2 + 0] = delta_local;   // Store delta at even index
        temp[i * 2 + 1] = -delta_local;  // Store -delta at odd index
    }

    // Copy transformed data into s->array with consecutive write pattern
    for (i = 0; i < 254; i++) {
        s->array[i] = temp[i];
    }
}
