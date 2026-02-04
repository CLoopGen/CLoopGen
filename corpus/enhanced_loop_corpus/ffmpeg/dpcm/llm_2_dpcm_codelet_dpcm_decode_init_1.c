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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing (unrolled-like pattern)
    int base_index = 128;
    for (i = -128; i < 128; i++) {
        int16_t square = i * i * 2;
        // Access array in strictly increasing, consecutive order
        s->array[base_index + i] = (i < 0) ? -square : square;
    }
}
