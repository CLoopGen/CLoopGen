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
    int mb_size = me_ctx->mb_size;
    sad = 0;
    for (j = 0; j < mb_size; j += 2) {
        for (i = 0; i < mb_size; i += 2) {
            int dr00 = data_ref[x_mv + i     + j       * linesize] - data_cur[x_mb + i     + j       * linesize];
            int dr10 = data_ref[x_mv + i + 1 + j       * linesize] - data_cur[x_mb + i + 1 + j       * linesize];
            int dr01 = data_ref[x_mv + i     + (j + 1) * linesize] - data_cur[x_mb + i     + (j + 1) * linesize];
            int dr11 = data_ref[x_mv + i + 1 + (j + 1) * linesize] - data_cur[x_mb + i + 1 + (j + 1) * linesize];
            sad += (dr00 >= 0 ? dr00 : -dr00) +
                   (dr10 >= 0 ? dr10 : -dr10) +
                   (dr01 >= 0 ? dr01 : -dr01) +
                   (dr11 >= 0 ? dr11 : -dr11);
        }
    }
    // Handle remaining elements if mb_size is odd
    if (mb_size % 2) {
        j = mb_size - 1;
        for (i = 0; i < mb_size - 1; i++) {
            int diff = data_ref[x_mv + i + j * linesize] - data_cur[x_mb + i + j * linesize];
            sad += diff >= 0 ? diff : -diff;
        }
        for (j = 0; j < mb_size - 1; j++) {
            int diff = data_ref[x_mv + mb_size - 1 + j * linesize] - data_cur[x_mb + mb_size - 1 + j * linesize];
            sad += diff >= 0 ? diff : -diff;
        }
        sad += abs(data_ref[x_mv + mb_size - 1 + (mb_size - 1) * linesize] - 
                   data_cur[x_mb + mb_size - 1 + (mb_size - 1) * linesize]);
    }
}
