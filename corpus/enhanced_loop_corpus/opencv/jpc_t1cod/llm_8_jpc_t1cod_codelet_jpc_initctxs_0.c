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
    int_fast16_t temp_ind = 3;
    int temp_mps = 0;
    for (i = 0; i < (((((0 + 1) + 9) + 3) + 5) + 1); ++i) {
        ctx->mps = temp_mps;
        switch (i) {
          case ((((0 + 1) + 9) + 3) + 5):
            temp_ind = 46;
            break;
          case (0 + 1):
            temp_ind = 4;
            break;
          case 0:
            temp_ind = 3;
            break;
          default:
            temp_ind = 0;
            break;
        }
        ctx->ind = temp_ind;
        temp_mps = (temp_ind % 7) > 3 ? 1 : 0;
        ++ctx;
    }
}
