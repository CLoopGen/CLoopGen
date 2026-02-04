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

extern AVMotionEstContext *me_ctx;
extern int x;
extern int y;
extern uint8_t *data_cur;
extern uint8_t *data_next;
extern int linesize;
extern int mv_x;
extern int mv_y;
extern int i;
extern int j;
extern uint64_t sbad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sbad = 0;
    int mb_size_half = me_ctx->mb_size / 2;
    int step = me_ctx->mb_size * 3 / 2;
    int k;
    for (k = 0; k < step * step; k++) {
        int local_j = (k / step) - mb_size_half;
        int local_i = (k % step) - mb_size_half;
        int val_cur = data_cur[(x + mv_x + local_i) + (y + mv_y + local_j) * linesize];
        int val_next = data_next[(x - mv_x + local_i) + (y - mv_y + local_j) * linesize];
        int diff = val_cur - val_next;
        if (diff >= 0)
            sbad += diff;
        else
            sbad -= diff;
    }
}
