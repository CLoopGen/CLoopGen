#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FRAME,
    TOP_FIELD,
    BOTTOM_FIELD
} PictureStructure;

typedef int64_t int64;

typedef unsigned char byte;

typedef struct storable_picture {
    PictureStructure structure;
    int poc;
    int top_poc;
    int bottom_poc;
    int frame_poc;
    int order_num;
    int64 ref_pic_num[6][33];
    int64 frm_ref_pic_num[6][33];
    int64 top_ref_pic_num[6][33];
    int64 bottom_ref_pic_num[6][33];
    unsigned int frame_num;
    int pic_num;
    int long_term_pic_num;
    int long_term_frame_idx;
    int is_long_term;
    int used_for_reference;
    int is_output;
    int non_existing;
    int size_x;
    int size_y;
    int size_x_cr;
    int size_y_cr;
    int chroma_vector_adjustment;
    int coded_frame;
    int MbaffFrameFlag;
    unsigned short **imgY;
    unsigned short *imgY_11;
    unsigned short *imgY_11_w;
    unsigned short **imgY_ups;
    unsigned short **imgY_ups_w;
    unsigned short ***imgUV;
    byte *mb_field;
    short ***ref_idx;
    int64 ***ref_pic_id;
    int64 ***ref_id;
    short ****mv;
    byte **moving_block;
    byte **field_frame;
    struct storable_picture *top_field;
    struct storable_picture *bottom_field;
    struct storable_picture *frame;
    int chroma_format_idc;
    int frame_mbs_only_flag;
    int frame_cropping_flag;
    int frame_cropping_rect_left_offset;
    int frame_cropping_rect_right_offset;
    int frame_cropping_rect_top_offset;
    int frame_cropping_rect_bottom_offset;
} StorablePicture;

typedef struct frame_store {
    int is_used;
    int is_reference;
    int is_long_term;
    int is_orig_reference;
    int is_non_existent;
    unsigned int frame_num;
    int frame_num_wrap;
    int long_term_frame_idx;
    int is_output;
    int poc;
    StorablePicture *frame;
    StorablePicture *top_field;
    StorablePicture *bottom_field;
} FrameStore;

extern FrameStore *fs;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    // Eliminate loop-carried dependencies by reordering and unrolling assumptions
    // Use temporary local variables to break memory-based dependencies
    for (i = 0; i < fs->frame->size_x / 4; i++) {
        for (j = 0; j < fs->frame->size_y / 8; j += 2) {  // Unroll j by factor of 2 to expose parallelism
            int idiv4_1 = i / 4, jdiv4_1 = j / 2;
            int currentmb_1 = 2 * (fs->frame->size_x / 16) * (jdiv4_1 / 2) + idiv4_1 * 2 + (jdiv4_1 % 2);

            if (fs->frame->MbaffFrameFlag && fs->frame->mb_field[currentmb_1]) {
                // Break WAW and WAR dependencies with local temporaries
                byte ff_val = 1;
                short mv0_bot0, mv0_bot1, mv1_bot0, mv1_bot1;
                short mv0_top0, mv0_top1, mv1_top0, mv1_top1;
                short ref_idx0_bot, ref_idx1_bot, ref_idx0_top, ref_idx1_top;
                int64 ref_id0_bot, ref_id1_bot, ref_id0_top, ref_id1_top;

                int frame_j_b1 = (j / 4) * 8 + (j % 4) + 4;
                int frame_j_t1 = (j / 4) * 8 + (j % 4);

                // Load all data first (simulate RAW elimination via privatization)
                mv0_bot0 = fs->frame->mv[0][i][frame_j_b1][0];
                mv0_bot1 = fs->frame->mv[0][i][frame_j_b1][1];
                mv1_bot0 = fs->frame->mv[1][i][frame_j_b1][0];
                mv1_bot1 = fs->frame->mv[1][i][frame_j_b1][1];

                mv0_top0 = fs->frame->mv[0][i][frame_j_t1][0];
                mv0_top1 = fs->frame->mv[0][i][frame_j_t1][1];
                mv1_top0 = fs->frame->mv[1][i][frame_j_t1][0];
                mv1_top1 = fs->frame->mv[1][i][frame_j_t1][1];

                ref_idx0_bot = fs->frame->ref_idx[0][i][frame_j_b1];
                ref_idx1_bot = fs->frame->ref_idx[1][i][frame_j_b1];
                ref_idx0_top = fs->frame->ref_idx[0][i][frame_j_t1];
                ref_idx1_top = fs->frame->ref_idx[1][i][frame_j_t1];

                ref_id0_bot = fs->frame->ref_id[4][i][frame_j_b1];
                ref_id1_bot = fs->frame->ref_id[5][i][frame_j_b1];
                ref_id0_top = fs->frame->ref_id[2][i][frame_j_t1];
                ref_id1_top = fs->frame->ref_id[3][i][frame_j_t1];

                // Now write to output structures without interference
                fs->bottom_field->field_frame[i][j] = ff_val;
                fs->top_field->field_frame[i][j] = ff_val;
                fs->frame->field_frame[i][2*j] = ff_val;
                fs->frame->field_frame[i][2*j+1] = ff_val;

                fs->bottom_field->mv[0][i][j][0] = mv0_bot0;
                fs->bottom_field->mv[0][i][j][1] = mv0_bot1;
                fs->bottom_field->mv[1][i][j][0] = mv1_bot0;
                fs->bottom_field->mv[1][i][j][1] = mv1_bot1;

                fs->bottom_field->ref_idx[0][i][j] = ref_idx0_bot;
                fs->bottom_field->ref_idx[1][i][j] = ref_idx1_bot;
                fs->bottom_field->ref_id[0][i][j] = ref_id0_bot;
                fs->bottom_field->ref_id[1][i][j] = ref_id1_bot;

                fs->top_field->mv[0][i][j][0] = mv0_top0;
                fs->top_field->mv[0][i][j][1] = mv0_top1;
                fs->top_field->mv[1][i][j][0] = mv1_top0;
                fs->top_field->mv[1][i][j][1] = mv1_top1;

                fs->top_field->ref_idx[0][i][j] = ref_idx0_top;
                fs->top_field->ref_idx[1][i][j] = ref_idx1_top;
                fs->top_field->ref_id[0][i][j] = ref_id0_top;
                fs->top_field->ref_id[1][i][j] = ref_id1_top;
            }

            // Second iteration of unrolled j
            int j2 = j + 1;
            if (j2 >= fs->frame->size_y / 8) continue;

            int idiv4_2 = i / 4, jdiv4_2 = j2 / 2;
            int currentmb_2 = 2 * (fs->frame->size_x / 16) * (jdiv4_2 / 2) + idiv4_2 * 2 + (jdiv4_2 % 2);

            if (fs->frame->MbaffFrameFlag && fs->frame->mb_field[currentmb_2]) {
                fs->bottom_field->field_frame[i][j2] = 1;
                fs->top_field->field_frame[i][j2] = 1;
                fs->frame->field_frame[i][2*j2] = 1;
                fs->frame->field_frame[i][2*j2+1] = 1;

                int frame_j_b2 = (j2 / 4) * 8 + (j2 % 4) + 4;
                int frame_j_t2 = (j2 / 4) * 8 + (j2 % 4);

                fs->bottom_field->mv[0][i][j2][0] = fs->frame->mv[0][i][frame_j_b2][0];
                fs->bottom_field->mv[0][i][j2][1] = fs->frame->mv[0][i][frame_j_b2][1];
                fs->bottom_field->mv[1][i][j2][0] = fs->frame->mv[1][i][frame_j_b2][0];
                fs->bottom_field->mv[1][i][j2][1] = fs->frame->mv[1][i][frame_j_b2][1];

                fs->bottom_field->ref_idx[0][i][j2] = fs->frame->ref_idx[0][i][frame_j_b2];
                fs->bottom_field->ref_idx[1][i][j2] = fs->frame->ref_idx[1][i][frame_j_b2];
                fs->bottom_field->ref_id[0][i][j2] = fs->frame->ref_id[4][i][frame_j_b2];
                fs->bottom_field->ref_id[1][i][j2] = fs->frame->ref_id[5][i][frame_j_b2];

                fs->top_field->mv[0][i][j2][0] = fs->frame->mv[0][i][frame_j_t2][0];
                fs->top_field->mv[0][i][j2][1] = fs->frame->mv[0][i][frame_j_t2][1];
                fs->top_field->mv[1][i][j2][0] = fs->frame->mv[1][i][frame_j_t2][0];
                fs->top_field->mv[1][i][j2][1] = fs->frame->mv[1][i][frame_j_t2][1];

                fs->top_field->ref_idx[0][i][j2] = fs->frame->ref_idx[0][i][frame_j_t2];
                fs->top_field->ref_idx[1][i][j2] = fs->frame->ref_idx[1][i][frame_j_t2];
                fs->top_field->ref_id[0][i][j2] = fs->frame->ref_id[2][i][frame_j_t2];
                fs->top_field->ref_id[1][i][j2] = fs->frame->ref_id[3][i][frame_j_t2];
            }
        }
    }
}
