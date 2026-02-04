#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int mps;
    int_fast16_t ind;
} jpc_mqctx_t;

jpc_mqctx_t *ctx;
int i;

static jpc_mqctx_t ctx_buffer[256 * 1024]; // ~256KB of data to target ~0.01s runtime

void init_vars() {
    ctx = ctx_buffer;
}

// Initialize external variables
jpc_mqctx_t *ctx = ctx_buffer;
int i = 0;