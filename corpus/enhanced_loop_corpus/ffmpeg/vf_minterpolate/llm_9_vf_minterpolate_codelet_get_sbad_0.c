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
    int stride = me_ctx->linesize;
    int block_size = me_ctx->mb_size / 2;  // Reduced trip count
    uint64_t sum = 0;

    // Unrolled by factor of 2 in both dimensions: process 2x2 blocks
    for (int j = 0; j < block_size; j++) {
        int j_offset = (j << 1) * stride;
        for (int i = 0; i < block_size; i++) {
            int i_offset = i << 1;
            int diff1 = data_cur[x + mv_x + i_offset + j_offset] - data_next[x - mv_x + i_offset + j_offset];
            int diff2 = data_cur[x + mv_x + i_offset + 1 + j_offset] - data_next[x - mv_x + i_offset + 1 + j_offset];
            int diff3 = data_cur[x + mv_x + i_offset + j_offset + stride] - data_next[x - mv_x + i_offset + j_offset + stride];
            int diff4 = data_cur[x + mv_x + i_offset + 1 + j_offset + stride] - data_next[x - mv_x + i_offset + 1 + j_offset + stride];

            sum += (diff1 >= 0 ? diff1 : -diff1) +
                   (diff2 >= 0 ? diff2 : -diff2) +
                   (diff3 >= 0 ? diff3 : -diff3) +
                   (diff4 >= 0 ? diff4 : -diff4);
        }
    }
    sbad += sum;
}
