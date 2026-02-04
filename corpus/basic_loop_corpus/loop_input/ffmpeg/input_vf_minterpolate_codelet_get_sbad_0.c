#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

AVMotionEstContext *me_ctx;
uint8_t *data_cur;
uint8_t *data_next;
int linesize;
int mv_x;
int x;
int i;
int j;
uint64_t sbad;

static uint8_t *buffer_cur;
static uint8_t *buffer_next;

void init_vars() {
    const int data_size = 16 * 1024 * 1024; // 16 MB per buffer

    buffer_cur = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    buffer_next = (uint8_t *)calloc(data_size, sizeof(uint8_t));

    if (!buffer_cur || !buffer_next) {
        exit(1);
    }

    data_cur = buffer_cur;
    data_next = buffer_next;

    me_ctx = (AVMotionEstContext *)malloc(sizeof(AVMotionEstContext));
    if (!me_ctx) {
        exit(1);
    }

    me_ctx->data_cur = buffer_cur;
    me_ctx->data_ref = buffer_next;
    me_ctx->linesize = 4096;
    me_ctx->mb_size = 16;
    me_ctx->search_param = 7;
    me_ctx->width = 1920;
    me_ctx->height = 1080;
    me_ctx->x_min = -16;
    me_ctx->x_max = 16;
    me_ctx->y_min = -16;
    me_ctx->y_max = 16;
    me_ctx->pred_x = 0;
    me_ctx->pred_y = 0;
    me_ctx->preds[0].nb = 0;
    me_ctx->preds[1].nb = 0;
    me_ctx->get_cost = NULL;

    linesize = me_ctx->linesize;
    x = 1000;
    mv_x = 5;
    i = 0;
    j = 0;
    sbad = 0;
}