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
static AVMotionEstContext me_ctx_storage;
AVMotionEstContext *me_ctx = &me_ctx_storage;
int x_mb;
int x_mv;
int linesize;
uint8_t *data_ref;
uint8_t *data_cur;
uint64_t sad;
int i;
int j;

void init_vars() {
    me_ctx = &me_ctx_storage;
    me_ctx->mb_size = 16;
    int block_area = me_ctx->mb_size * me_ctx->mb_size;
    size_t data_size = 16 * 1024 * 1024; // ~16MB per buffer

    data_ref_global = (uint8_t*)calloc(data_size, 1);
    data_cur_global = (uint8_t*)calloc(data_size, 1);

    if (!data_ref_global || !data_cur_global) {
        exit(1);
    }

    me_ctx->data_ref = data_ref_global;
    me_ctx->data_cur = data_cur_global;
    me_ctx->linesize = 4096;
    me_ctx->width = 1920;
    me_ctx->height = 1080;
    me_ctx->x_min = -16;
    me_ctx->x_max = 16;
    me_ctx->y_min = -16;
    me_ctx->y_max = 16;
    me_ctx->pred_x = 0;
    me_ctx->pred_y = 0;
    me_ctx->search_param = 7;
    me_ctx->preds[0].nb = 0;
    me_ctx->preds[1].nb = 0;

    data_ref = me_ctx->data_ref;
    data_cur = me_ctx->data_cur;
    linesize = me_ctx->linesize;

    x_mb = 100;
    x_mv = 200;

    sad = 0;

    for (int y = 0; y < me_ctx->mb_size; y++) {
        for (int x = 0; x < me_ctx->mb_size; x++) {
            ptrdiff_t cur_idx = (x_mb + x) + (y * linesize);
            ptrdiff_t ref_idx = (x_mv + x) + (y * linesize);
            if (cur_idx >= 0 && cur_idx < (ptrdiff_t)data_size) {
                data_cur[cur_idx] = rand() % 256;
            }
            if (ref_idx >= 0 && ref_idx < (ptrdiff_t)data_size) {
                data_ref[ref_idx] = rand() % 256;
            }
        }
    }
}