#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef struct opj_mqc_state {
    OPJ_UINT32 qeval;
    OPJ_UINT32 mps;
    const struct opj_mqc_state *nmps;
    const struct opj_mqc_state *nlps;
} opj_mqc_state_t;

typedef unsigned char OPJ_BYTE;

typedef struct opj_mqc {
    OPJ_UINT32 c;
    OPJ_UINT32 a;
    OPJ_UINT32 ct;
    OPJ_UINT32 end_of_byte_stream_counter;
    OPJ_BYTE *bp;
    OPJ_BYTE *start;
    OPJ_BYTE *end;
    const opj_mqc_state_t *ctxs[19];
    const opj_mqc_state_t **curctx;
    const OPJ_BYTE *lut_ctxno_zc_orient;
    OPJ_BYTE backup[2];
} opj_mqc_t;

extern  opj_mqc_state_t mqc_states[94];
extern opj_mqc_t *mqc;
extern OPJ_UINT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal
    for (i = 18; i < 19 && i >= 0; i -= 2) {
        mqc->ctxs[i] = mqc_states;
        if (i == 0) break; // Prevent underflow on unsigned decrement
    }
    // Fill remaining indices in a forward pass with stride 2
    for (OPJ_UINT32 j = 0; j < 19; j += 2) {
        if (j <= 18) mqc->ctxs[j] = mqc_states;
    }
}
