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

static uint8_t *data_ref_global;
static uint8_t *data_cur_global;
AVMotionEstContext *me_ctx;
int x;
int y;
int x_mv;
int y_mv;
uint8_t *data_ref;
uint8_t *data_cur;
int linesize;
int i;
int j;
uint64_t sad;

void init_vars() {
    const int total_data_size = 16 * 1024 * 1024; // 16MB data for ~0.01s runtime estimate

    data_ref_global = (uint8_t*)calloc(total_data_size, sizeof(uint8_t));
    data_cur_global = (uint8_t*)calloc(total_data_size, sizeof(uint8_t));

    if (!data_ref_global || !data_cur_global) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_data_size; idx++) {
        data_ref_global[idx] = rand() % 256;
        data_cur_global[idx] = rand() % 256;
    }

    me_ctx = (AVMotionEstContext*)malloc(sizeof(AVMotionEstContext));
    if (!me_ctx) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    me_ctx->data_cur = data_cur_global;
    me_ctx->data_ref = data_ref_global;
    me_ctx->linesize = 4096; // Simulate large stride
    me_ctx->mb_size = 16;
    me_ctx->search_param = 8;
    me_ctx->width = me_ctx->linesize;
    me_ctx->height = (total_data_size / me_ctx->linesize) - 1;
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
    data_ref = me_ctx->data_ref;
    data_cur = me_ctx->data_cur;

    x = 100;
    y = 100;
    x_mv = 110;
    y_mv = 110;

    sad = 0;
}