#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ElsDecCtx {
    const uint8_t *in_buf;
    unsigned int x;
    size_t data_size;
    int j;
    int t;
    int diff;
    int err;
} ElsDecCtx;

typedef struct ElsRungNode {
    uint8_t rung;
    uint16_t next_index;
} ElsRungNode;

typedef struct ElsUnsignedRung {
    uint8_t prefix_rung[11];
    ElsRungNode *rem_rung_list;
    size_t rung_list_size;
    uint16_t avail_index;
} ElsUnsignedRung;

struct ePICPixListElem {
    struct ePICPixListElem *next;
    uint32_t pixel;
    uint8_t rung;
};

typedef struct ePICPixHashElem {
    uint32_t pix_id;
    struct ePICPixListElem *list;
} ePICPixHashElem;

typedef struct ePICPixHash {
    ePICPixHashElem *bucket[256];
    int bucket_size[256];
    int bucket_fill[256];
} ePICPixHash;

typedef struct ePICContext {
    ElsDecCtx els_ctx;
    int next_run_pos;
    ElsUnsignedRung unsigned_rung;
    uint8_t W_flag_rung;
    uint8_t N_flag_rung;
    uint8_t W_ctx_rung[256];
    uint8_t N_ctx_rung[512];
    uint8_t nw_pred_rung[256];
    uint8_t ne_pred_rung[256];
    uint8_t prev_row_rung[14];
    uint8_t runlen_zeroes[14];
    uint8_t runlen_one;
    int stack_pos;
    uint32_t stack[1024];
    ePICPixHash hash;
} ePICContext;

ePICContext *dc;
uint32_t pix;
int i;

void init_vars() {
    dc = (ePICContext*)calloc(1, sizeof(ePICContext));
    if (!dc) exit(1);

    dc->els_ctx.in_buf = (const uint8_t *)calloc(1, 1024 * 1024 * 64);
    if (!dc->els_ctx.in_buf) exit(1);
    dc->els_ctx.data_size = 1024 * 1024 * 64;
    dc->els_ctx.x = 0;
    dc->els_ctx.j = 0;
    dc->els_ctx.t = 0;
    dc->els_ctx.diff = 0;
    dc->els_ctx.err = 0;

    dc->next_run_pos = 0;

    dc->unsigned_rung.rem_rung_list = (ElsRungNode *)calloc(1024, sizeof(ElsRungNode));
    if (!dc->unsigned_rung.rem_rung_list) exit(1);
    dc->unsigned_rung.rung_list_size = 1024;
    dc->unsigned_rung.avail_index = 0;

    dc->W_flag_rung = 0;
    dc->N_flag_rung = 0;

    for (int idx = 0; idx < 256; idx++) {
        dc->W_ctx_rung[idx] = 0;
        dc->nw_pred_rung[idx] = 0;
        dc->ne_pred_rung[idx] = 0;
    }

    for (int idx = 0; idx < 512; idx++) {
        dc->N_ctx_rung[idx] = 0;
    }

    for (int idx = 0; idx < 14; idx++) {
        dc->prev_row_rung[idx] = 0;
        dc->runlen_zeroes[idx] = 0;
    }

    dc->runlen_one = 0;

    dc->stack_pos = 512;
    for (int idx = 0; idx < dc->stack_pos; idx++) {
        dc->stack[idx] = (uint32_t)(idx * 2); 
    }
    pix = 1022;

    for (int idx = 0; idx < 256; idx++) {
        dc->hash.bucket[idx] = NULL;
        dc->hash.bucket_size[idx] = 0;
        dc->hash.bucket_fill[idx] = 0;
    }
}