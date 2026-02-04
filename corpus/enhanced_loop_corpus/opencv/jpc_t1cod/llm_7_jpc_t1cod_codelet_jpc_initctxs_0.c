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
        ctx->mps = (i > 0) ? (ctx[-1].ind % 2) : 0;
        switch (i) {
          case ((((0 + 1) + 9) + 3) + 5):
            ctx->ind = 46;
            break;
          case (0 + 1):
            ctx->ind = 4;
            break;
          case 0:
            ctx->ind = 3;
            break;
          default:
            ctx->ind = (ctx[-1].mps + i) & 0xFF;
            break;
        }
        ++ctx;
    }
}
