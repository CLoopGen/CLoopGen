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
    // Variant 2: Strided memory access - write every second element first, then fill gaps
    // Simulate strided access by stepping with stride 2, then handle offset
    int base_index = 128;
    // First pass: write with stride 2 (even offsets)
    for (i = -128; i < 128; i += 2) {
        int16_t square = i * i * 2;
        s->array[base_index + i] = (i < 0) ? -square : square;
    }
    // Second pass: fill the odd indices
    for (i = -127; i < 128; i += 2) {
        int16_t square = i * i * 2;
        s->array[base_index + i] = (i < 0) ? -square : square;
    }
}
