#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int mps;
    int_fast16_t ind;
} jpc_mqctx_t;

extern jpc_mqctx_t *ctx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (((((0 + 1) + 9) + 3) + 5) + 1); ++i) {
        ctx->mps = 0;
        ctx->ind = 0;
        if (i == 0)
            ctx->ind = 3;
        else if (i == 1)
            ctx->ind = 4;
        else if (i == 18)
            ctx->ind = 46;
        ++ctx;
    }
}
