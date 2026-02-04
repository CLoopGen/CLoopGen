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
    // Variant 1: Strided memory access with step of 2
    for (i = 0; i < 256; i += 2) {
        int16_t square = (i / 2) * (i / 2);
        s->array[i] = square;
        s->array[i + 1] = -square;
    }
}
