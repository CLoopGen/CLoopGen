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
    int mb_size = me_ctx->mb_size;
    int center = mb_size / 2;
    // Increase computational intensity by unrolling inner loop 4 times
    for (j = -center; j < mb_size * 3 / 2; j++) {
        for (i = -center; i < mb_size * 3 / 2; i += 4) {
            // Unroll 4 iterations
            if (i + 0 < mb_size * 3 / 2) {
                int diff0 = data_ref[x_mv + i + 0 + (y_mv + j) * linesize] - data_cur[x + i + 0 + (y + j) * linesize];
                sad += diff0 >= 0 ? diff0 : -diff0;
            }
            if (i + 1 < mb_size * 3 / 2) {
                int diff1 = data_ref[x_mv + i + 1 + (y_mv + j) * linesize] - data_cur[x + i + 1 + (y + j) * linesize];
                sad += diff1 >= 0 ? diff1 : -diff1;
            }
            if (i + 2 < mb_size * 3 / 2) {
                int diff2 = data_ref[x_mv + i + 2 + (y_mv + j) * linesize] - data_cur[x + i + 2 + (y + j) * linesize];
                sad += diff2 >= 0 ? diff2 : -diff2;
            }
            if (i + 3 < mb_size * 3 / 2) {
                int diff3 = data_ref[x_mv + i + 3 + (y_mv + j) * linesize] - data_cur[x + i + 3 + (y + j) * linesize];
                sad += diff3 >= 0 ? diff3 : -diff3;
            }
        }
    }
}
