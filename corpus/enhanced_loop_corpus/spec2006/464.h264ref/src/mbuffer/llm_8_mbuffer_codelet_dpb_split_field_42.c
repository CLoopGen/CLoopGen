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



void loop() {
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    for (i = 0; i < fs->frame->size_x / 4; i++) {
        int idiv4 = i / 4;
        for (j = 0; j < fs->frame->size_y / 8; j += 2) {  // Process two iterations at once
            int jdiv4_0 = j / 2;
            int currentmb_0 = 2 * (fs->frame->size_x / 16) * (jdiv4_0 / 2) + idiv4 * 2 + (jdiv4_0 % 2);

            if (fs->frame->MbaffFrameFlag && fs->frame->mb_field[currentmb_0]) {
                // First j index
                fs->bottom_field->field_frame[i][j] = fs->top_field->field_frame[i][j] = 1;
                fs->frame->field_frame[i][2 * j] = fs->frame->field_frame[i][2 * j + 1] = 1;

                int frame_j_offset_b0 = (j / 4) * 8 + (j % 4) + 4;
                int frame_j_offset_t0 = (j / 4) * 8 + (j % 4);

                // Bottom field assignments
                short**** bf_mv = fs->bottom_field->mv;
                short*** bf_ref_idx = fs->bottom_field->ref_idx;
                int64*** bf_ref_id = fs->bottom_field->ref_id;
                short**** fr_mv = fs->frame->mv;
                short*** fr_ref_idx = fs->frame->ref_idx;
                int64*** fr_ref_id = fs->frame->ref_id;

                bf_mv[0][i][j][0] = fr_mv[0][i][frame_j_offset_b0][0];
                bf_mv[0][i][j][1] = fr_mv[0][i][frame_j_offset_b0][1];
                bf_mv[1][i][j][0] = fr_mv[1][i][frame_j_offset_b0][0];
                bf_mv[1][i][j][1] = fr_mv[1][i][frame_j_offset_b0][1];
                bf_ref_idx[0][i][j] = fr_ref_idx[0][i][frame_j_offset_b0];
                bf_ref_idx[1][i][j] = fr_ref_idx[1][i][frame_j_offset_b0];
                bf_ref_id[0][i][j] = fr_ref_id[4][i][frame_j_offset_b0];
                bf_ref_id[1][i][j] = fr_ref_id[5][i][frame_j_offset_b0];

                // Top field assignments
                bf_mv = fs->top_field->mv;
                bf_ref_idx = fs->top_field->ref_idx;
                bf_ref_id = fs->top_field->ref_id;

                bf_mv[0][i][j][0] = fr_mv[0][i][frame_j_offset_t0][0];
                bf_mv[0][i][j][1] = fr_mv[0][i][frame_j_offset_t0][1];
                bf_mv[1][i][j][0] = fr_mv[1][i][frame_j_offset_t0][0];
                bf_mv[1][i][j][1] = fr_mv[1][i][frame_j_offset_t0][1];
                bf_ref_idx[0][i][j] = fr_ref_idx[0][i][frame_j_offset_t0];
                bf_ref_idx[1][i][j] = fr_ref_idx[1][i][frame_j_offset_t0];
                bf_ref_id[0][i][j] = fr_ref_id[2][i][frame_j_offset_t0];
                bf_ref_id[1][i][j] = fr_ref_id[3][i][frame_j_offset_t0];
            }

            // Second j index (j+1), if within bounds
            if (j + 1 < fs->frame->size_y / 8) {
                int jdiv4_1 = (j + 1) / 2;
                int currentmb_1 = 2 * (fs->frame->size_x / 16) * (jdiv4_1 / 2) + idiv4 * 2 + (jdiv4_1 % 2);

                if (fs->frame->MbaffFrameFlag && fs->frame->mb_field[currentmb_1]) {
                    fs->bottom_field->field_frame[i][j + 1] = fs->top_field->field_frame[i][j + 1] = 1;
                    fs->frame->field_frame[i][2 * (j + 1)] = fs->frame->field_frame[i][2 * (j + 1) + 1] = 1;

                    int frame_j_offset_b1 = ((j + 1) / 4) * 8 + ((j + 1) % 4) + 4;
                    int frame_j_offset_t1 = ((j + 1) / 4) * 8 + ((j + 1) % 4);

                    short**** bf_mv = fs->bottom_field->mv;
                    short*** bf_ref_idx = fs->bottom_field->ref_idx;
                    int64*** bf_ref_id = fs->bottom_field->ref_id;
                    short**** fr_mv = fs->frame->mv;
                    short*** fr_ref_idx = fs->frame->ref_idx;
                    int64*** fr_ref_id = fs->frame->ref_id;

                    bf_mv[0][i][j + 1][0] = fr_mv[0][i][frame_j_offset_b1][0];
                    bf_mv[0][i][j + 1][1] = fr_mv[0][i][frame_j_offset_b1][1];
                    bf_mv[1][i][j + 1][0] = fr_mv[1][i][frame_j_offset_b1][0];
                    bf_mv[1][i][j + 1][1] = fr_mv[1][i][frame_j_offset_b1][1];
                    bf_ref_idx[0][i][j + 1] = fr_ref_idx[0][i][frame_j_offset_b1];
                    bf_ref_idx[1][i][j + 1] = fr_ref_idx[1][i][frame_j_offset_b1];
                    bf_ref_id[0][i][j + 1] = fr_ref_id[4][i][frame_j_offset_b1];
                    bf_ref_id[1][i][j + 1] = fr_ref_id[5][i][frame_j_offset_b1];

                    bf_mv = fs->top_field->mv;
                    bf_ref_idx = fs->top_field->ref_idx;
                    bf_ref_id = fs->top_field->ref_id;

                    bf_mv[0][i][j + 1][0] = fr_mv[0][i][frame_j_offset_t1][0];
                    bf_mv[0][i][j + 1][1] = fr_mv[0][i][frame_j_offset_t1][1];
                    bf_mv[1][i][j + 1][0] = fr_mv[1][i][frame_j_offset_t1][0];
                    bf_mv[1][i][j + 1][1] = fr_mv[1][i][frame_j_offset_t1][1];
                    bf_ref_idx[0][i][j + 1] = fr_ref_idx[0][i][frame_j_offset_t1];
                    bf_ref_idx[1][i][j + 1] = fr_ref_idx[1][i][frame_j_offset_t1];
                    bf_ref_id[0][i][j + 1] = fr_ref_id[2][i][frame_j_offset_t1];
                    bf_ref_id[1][i][j + 1] = fr_ref_id[3][i][frame_j_offset_t1];
                }
            }
        }
    }
}
