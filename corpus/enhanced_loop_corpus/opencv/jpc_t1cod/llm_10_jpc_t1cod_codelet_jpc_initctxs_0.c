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
    // Variant 2: Reduced complexity with simplified control flow and lower trip count
    for (i = 0; i < 4; ++i) {
        ctx->mps = 0;
        switch (i) {
            case 3:
                ctx->ind = 46;
                break;
            case 1:
                ctx->ind = 4;
                break;
            case 0:
                ctx->ind = 3;
                break;
            default:
                ctx->ind = 0;
                break;
        }
        ++ctx;
    }
}
