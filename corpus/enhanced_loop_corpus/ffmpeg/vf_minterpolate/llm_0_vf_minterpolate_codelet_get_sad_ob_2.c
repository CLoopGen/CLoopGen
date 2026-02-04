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
extern int x_mv;
extern int y_mv;
extern uint8_t *data_ref;
extern uint8_t *data_cur;
extern int linesize;
extern int i;
extern int j;
extern uint64_t sad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j_start = -me_ctx->mb_size / 2;
    int j_end = me_ctx->mb_size * 3 / 2;
    int i_start = -me_ctx->mb_size / 2;
    int i_end = me_ctx->mb_size * 3 / 2;
    for (j = j_start; j < j_end; j++) {
        for (i = i_start; i < i_end; i++) {
            int diff = data_ref[x_mv + i + (y_mv + j) * linesize] - data_cur[x + i + (y + j) * linesize];
            sad += diff >= 0 ? diff : -diff;
        }
    }
}
