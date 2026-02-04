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
extern uint8_t *data_cur;
extern uint8_t *data_next;
extern int linesize;
extern int mv_x;
extern int i;
extern int j;
extern uint64_t sbad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_sbad = sbad;
    int step = 2;
    int mb_size = me_ctx->mb_size;

    // Unroll by 2 to alter data dependency pattern and reduce loop-carried dependence
    for (j = 0; j < mb_size; j++) {
        for (i = 0; i < mb_size; i += step) {
            // First iteration of unrolled loop
            if (i < mb_size) {
                int diff1 = data_cur[x + mv_x + i + j * linesize] - data_next[x - mv_x + i + j * linesize];
                local_sbad += diff1 >= 0 ? diff1 : -diff1;
            }
            // Second iteration of unrolled loop
            if (i + 1 < mb_size) {
                int diff2 = data_cur[x + mv_x + (i+1) + j * linesize] - data_next[x - mv_x + (i+1) + j * linesize];
                local_sbad += diff2 >= 0 ? diff2 : -diff2;
            }
        }
    }
    sbad = local_sbad;
}
