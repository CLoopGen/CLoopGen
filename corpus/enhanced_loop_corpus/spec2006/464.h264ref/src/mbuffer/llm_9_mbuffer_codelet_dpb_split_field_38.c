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
extern int dummylist0;
extern int dummylist1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < fs->frame->size_x / 2; i += 2) {
    for (j = 0; j < fs->frame->size_y / 4; j += 2) {
        int idiv4 = i / 4, jdiv4 = j / 2;
        int currentmb_base = 2 * (fs->frame->size_x / 16);
        int currentmb_step = (jdiv4 / 2);
        int currentmb = currentmb_base * currentmb_step + (idiv4) * 2 + (jdiv4 % 2);

        int cond = (!fs->frame->MbaffFrameFlag || !fs->frame->mb_field[currentmb]);
        if (cond) {
            int frame_i = i, frame_j2 = 2 * j;
            fs->frame->field_frame[frame_i][frame_j2 + 1] = 0;
            fs->frame->field_frame[frame_i][frame_j2] = 0;

            if (!fs->frame->frame_mbs_only_flag) {
                fs->top_field->field_frame[i][j] = 0;
                fs->bottom_field->field_frame[i][j] = 0;

                int idx_i = (i & 2) ? (i | 1) : (i & (~1));
                int idx_j = 2 * ((j & 2) ? (j | 1) : (j & (~1)));

                short val_mv00 = fs->frame->mv[0][idx_i][idx_j][0];
                short val_mv01 = fs->frame->mv[0][idx_i][idx_j][1];
                short val_mv10 = fs->frame->mv[1][idx_i][idx_j][0];
                short val_mv11 = fs->frame->mv[1][idx_i][idx_j][1];

                fs->top_field->mv[0][i][j][0] = val_mv00;
                fs->bottom_field->mv[0][i][j][0] = val_mv00;
                fs->top_field->mv[0][i][j][1] = val_mv01;
                fs->bottom_field->mv[0][i][j][1] = val_mv01;
                fs->top_field->mv[1][i][j][0] = val_mv10;
                fs->bottom_field->mv[1][i][j][0] = val_mv10;
                fs->top_field->mv[1][i][j][1] = val_mv11;
                fs->bottom_field->mv[1][i][j][1] = val_mv11;

                short r0 = fs->frame->ref_idx[0][idx_i][idx_j];
                fs->top_field->ref_idx[0][i][j] = r0;
                fs->bottom_field->ref_idx[0][i][j] = r0;
                fs->top_field->ref_id[0][i][j] = (r0 >= 0) ? fs->frame->top_ref_pic_num[0][r0] : 0;
                fs->bottom_field->ref_id[0][i][j] = (r0 >= 0) ? fs->frame->bottom_ref_pic_num[0][r0] : 0;

                short r1 = fs->frame->ref_idx[1][idx_i][idx_j];
                fs->top_field->ref_idx[1][i][j] = r1;
                fs->bottom_field->ref_idx[1][i][j] = r1;
                fs->top_field->ref_id[1][i][j] = (r1 >= 0) ? fs->frame->top_ref_pic_num[1][r1] : 0;
                fs->bottom_field->ref_id[1][i][j] = (r1 >= 0) ? fs->frame->bottom_ref_pic_num[1][r1] : 0;
            }
        }
    }
}
}
