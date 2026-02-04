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
    sad = 0;
    for (j = 0; j < me_ctx->mb_size; j++) {
        for (i = 0; i < me_ctx->mb_size; i++) {
            int ref_val = data_ref[x_mv + i + j * linesize];
            int cur_val = data_cur[x_mb + i + j * linesize];
            int diff = ref_val - cur_val;
            if (diff == 0) continue;
            sad += diff > 0 ? diff : -diff;
        }
    }
}
