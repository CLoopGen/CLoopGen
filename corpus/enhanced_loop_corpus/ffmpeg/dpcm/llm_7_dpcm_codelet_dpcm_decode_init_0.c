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
    int16_t prev_square = 0;
    for (i = 0; i < 128; i++) {
        int16_t square = i * i + prev_square;
        s->array[i] = square;
        s->array[i + 128] = -square;
        prev_square = square;
    }
}
