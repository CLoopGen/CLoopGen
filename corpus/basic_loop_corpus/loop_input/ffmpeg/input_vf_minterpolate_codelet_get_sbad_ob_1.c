#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef struct AVMotionEstPredictor {
    int mvs[10][2];
    int nb;
} AVMotionEstPredictor;

typedef struct AVMotionEstContext {
    uint8_t *data_cur;
    uint8_t *data_ref;
    int linesize;
    int mb_size;
    int search_param;
    int width;
    int height;
    int x_min;
    int x_max;
    int y_min;
    int y_max;
    int pred_x;
    int pred_y;
    AVMotionEstPredictor preds[2];
    uint64_t (*get_cost)(struct AVMotionEstContext *, int, int, int, int);
} AVMotionEstContext;

static uint8_t *data_cur_global;
static uint8_t *data_next_global;
static AVMotionEstContext me_ctx_global;

AVMotionEstContext *me_ctx = &me_ctx_global;
int x = 16;
int y = 16;
uint8_t *data_cur;
uint8_t *data_next;
int linesize;
int mv_x = 2;
int mv_y = 2;
int i;
int j;
uint64_t sbad;

void init_vars() {
    me_ctx->mb_size = 8;
    me_ctx->linesize = 64;
    me_ctx->width = 32;
    me_ctx->height = 32;

    size_t buffer_size = me_ctx->linesize * me_ctx->height;
    data_cur_global = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    data_next_global = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));

    if (!data_cur_global || !data_next_global) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < buffer_size; idx++) {
        data_cur_global[idx] = rand() % 256;
        data_next_global[idx] = rand() % 256;
    }

    me_ctx->data_cur = data_cur_global;
    me_ctx->data_ref = data_next_global;

    data_cur = data_cur_global;
    data_next = data_next_global;
    linesize = me_ctx->linesize;

    x = me_ctx->mb_size;
    y = me_ctx->mb_size;
    mv_x = 2;
    mv_y = 2;

    me_ctx->x_min = -me_ctx->mb_size;
    me_ctx->x_max = me_ctx->width + me_ctx->mb_size;
    me_ctx->y_min = -me_ctx->mb_size;
    me_ctx->y_max = me_ctx->height + me_ctx->mb_size;
    me_ctx->pred_x = 0;
    me_ctx->pred_y = 0;
    me_ctx->search_param = 8;

    me_ctx->preds[0].nb = 0;
    me_ctx->preds[1].nb = 0;

    sbad = 0;
}