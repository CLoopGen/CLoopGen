#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DPCMContext {
    int16_t array[256];
    int sample[2];
    const int8_t *sol_table;
} DPCMContext;

static int8_t internal_sol_table[256];
DPCMContext *s;
int i;

void init_vars() {
    s = (DPCMContext *)malloc(sizeof(DPCMContext));
    if (!s) exit(1);
    s->sol_table = internal_sol_table;
    for (int j = 0; j < 256; j++) {
        internal_sol_table[j] = (int8_t)(j - 128);
    }
    for (int j = 0; j < 2; j++) {
        s->sample[j] = j * 100;
    }
}