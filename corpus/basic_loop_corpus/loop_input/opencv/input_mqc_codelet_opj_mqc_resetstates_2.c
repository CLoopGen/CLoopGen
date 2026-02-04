#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef unsigned char OPJ_BYTE;

typedef struct opj_mqc_state {
    OPJ_UINT32 qeval;
    OPJ_UINT32 mps;
    const struct opj_mqc_state *nmps;
    const struct opj_mqc_state *nlps;
} opj_mqc_state_t;

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

opj_mqc_state_t mqc_states[94];

opj_mqc_t *mqc;
OPJ_UINT32 i;

void init_vars() {
    mqc = (opj_mqc_t*)calloc(1, sizeof(opj_mqc_t));
    if (!mqc) return;

    size_t data_size = 16 * 1024 * 1024;
    OPJ_BYTE* buffer = (OPJ_BYTE*)calloc(data_size + 8, sizeof(OPJ_BYTE));
    if (!buffer) {
        free(mqc);
        mqc = NULL;
        return;
    }

    mqc->bp = buffer;
    mqc->start = buffer;
    mqc->end = buffer + data_size;
    mqc->c = 0;
    mqc->a = 0x8000;
    mqc->ct = 12;
    mqc->end_of_byte_stream_counter = 0;
    mqc->curctx = (const opj_mqc_state_t**)&(mqc->ctxs[0]);
    mqc->lut_ctxno_zc_orient = (const OPJ_BYTE*)calloc(256, sizeof(OPJ_BYTE));

    mqc->backup[0] = 0;
    mqc->backup[1] = 0;

    for (int j = 0; j < 94; ++j) {
        mqc_states[j].qeval = (j + 1) * 17;
        mqc_states[j].mps = j % 2;
        mqc_states[j].nmps = &mqc_states[(j + 1) % 94];
        mqc_states[j].nlps = &mqc_states[(j + 2) % 94];
    }
}