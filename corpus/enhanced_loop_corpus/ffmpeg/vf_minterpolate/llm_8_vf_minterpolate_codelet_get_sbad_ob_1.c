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
    int mb_size = me_ctx->mb_size;
    int half_mb = mb_size / 2;
    int range = mb_size * 3 / 2;
    uint64_t sum = 0;
    for (j = -half_mb; j < range; j++) {
        int offset_j_cur = (y + mv_y + j) * linesize;
        int offset_j_next = (y - mv_y + j) * linesize;
        for (i = -half_mb; i < range; i++) {
            int idx_cur = x + mv_x + i + offset_j_cur;
            int idx_next = x - mv_x + i + offset_j_next;
            int diff = data_cur[idx_cur] - data_next[idx_next];
            sum += diff >= 0 ? diff : -diff;
        }
    }
    sbad = sum;
}
