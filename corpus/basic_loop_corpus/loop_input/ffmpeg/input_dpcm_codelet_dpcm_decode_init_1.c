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
    s = malloc(sizeof(DPCMContext));
    if (!s) {
        exit(1);
    }
    s->sample[0] = 0;
    s->sample[1] = 0;
    s->sol_table = internal_sol_table;
}