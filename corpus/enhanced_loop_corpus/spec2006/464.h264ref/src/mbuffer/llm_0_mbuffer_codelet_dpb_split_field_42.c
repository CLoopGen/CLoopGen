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
    for (i = 0; i < fs->frame->size_x / 4; i++) {
        int idiv4 = i / 4;
        for (j = 0; j < fs->frame->size_y / 8; j++) {
            int jdiv4 = j / 2;
            int currentmb = 2 * (fs->frame->size_x / 16) * (jdiv4 / 2) + (idiv4) * 2 + (jdiv4 % 2);
            if (fs->frame->MbaffFrameFlag && fs->frame->mb_field[currentmb]) {
                fs->bottom_field->field_frame[i][j] = fs->top_field->field_frame[i][j] = 1;
                fs->frame->field_frame[i][2 * j] = fs->frame->field_frame[i][2 * j + 1] = 1;
                int base_j_bottom = (j / 4) * 8 + j % 4 + 4;
                int base_j_top = (j / 4) * 8 + j % 4;
                fs->bottom_field->mv[0][i][j][0] = fs->frame->mv[0][i][base_j_bottom][0];
                fs->bottom_field->mv[0][i][j][1] = fs->frame->mv[0][i][base_j_bottom][1];
                fs->bottom_field->mv[1][i][j][0] = fs->frame->mv[1][i][base_j_bottom][0];
                fs->bottom_field->mv[1][i][j][1] = fs->frame->mv[1][i][base_j_bottom][1];
                fs->bottom_field->ref_idx[0][i][j] = fs->frame->ref_idx[0][i][base_j_bottom];
                fs->bottom_field->ref_idx[1][i][j] = fs->frame->ref_idx[1][i][base_j_bottom];
                fs->bottom_field->ref_id[0][i][j] = fs->frame->ref_id[4][i][base_j_bottom];
                fs->bottom_field->ref_id[1][i][j] = fs->frame->ref_id[5][i][base_j_bottom];
                fs->top_field->mv[0][i][j][0] = fs->frame->mv[0][i][base_j_top][0];
                fs->top_field->mv[0][i][j][1] = fs->frame->mv[0][i][base_j_top][1];
                fs->top_field->mv[1][i][j][0] = fs->frame->mv[1][i][base_j_top][0];
                fs->top_field->mv[1][i][j][1] = fs->frame->mv[1][i][base_j_top][1];
                fs->top_field->ref_idx[0][i][j] = fs->frame->ref_idx[0][i][base_j_top];
                fs->top_field->ref_idx[1][i][j] = fs->frame->ref_idx[1][i][base_j_top];
                fs->top_field->ref_id[0][i][j] = fs->frame->ref_id[2][i][base_j_top];
                fs->top_field->ref_id[1][i][j] = fs->frame->ref_id[3][i][base_j_top];
            }
        }
    }
}
