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
extern int x_mb;
extern int x_mv;
extern  int linesize;
extern uint8_t *data_ref;
extern uint8_t *data_cur;
extern uint64_t sad;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int jj, ii;
    int block_size = me_ctx->mb_size / 2;
    for (jj = 0; jj < me_ctx->mb_size; jj += 2) {
        for (ii = 0; ii < me_ctx->mb_size; ii += 2) {
            int j_end = (jj + 1 < me_ctx->mb_size) ? jj + 2 : jj + 1;
            int i_end = (ii + 1 < me_ctx->mb_size) ? ii + 2 : ii + 1;
            for (int j = jj; j < j_end; j++) {
                for (int i = ii; i < i_end; i++) {
                    sad += ((data_ref[x_mv + i + j * linesize] - data_cur[x_mb + i + j * linesize]) >= 0 ? 
                            (data_ref[x_mv + i + j * linesize] - data_cur[x_mb + i + j * linesize]) : 
                            (-(data_ref[x_mv + i + j * linesize] - data_cur[x_mb + i + j * linesize])));
                }
            }
        }
    }
}
