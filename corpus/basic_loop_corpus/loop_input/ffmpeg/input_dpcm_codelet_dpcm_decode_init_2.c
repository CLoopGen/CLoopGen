#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DPCMContext {
    int16_t array[256];
    int sample[2];
    const int8_t *sol_table;
} DPCMContext;

DPCMContext *s;
int i;
int delta;
int code;
int step;

static int8_t internal_sol_table[256];

void init_vars() {
    // Allocate and initialize s
    s = (DPCMContext*)calloc(1, sizeof(DPCMContext));
    if (!s) {
        fprintf(stderr, "Failed to allocate memory for DPCMContext\n");
        exit(1);
    }

    // Initialize sol_table with point to internal array
    s->sol_table = internal_sol_table;

    // Initialize other variables
    i = 0;
    delta = 0;
    code = 1;
    step = 2;

    // Ensure loop bounds: i < 127, so we write to indices i*2+1 and i*2+2
    // Max index: 126*2+2 = 254, which is within [0,255] for array[256]
}

// Explicitly prevent main from being defined here