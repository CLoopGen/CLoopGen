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
// Eliminate loop-carried dependencies by reordering operations into two passes:
// Pass 1: Read all required data from top/bottom fields into local arrays
// Pass 2: Write computed results into frame structure

int max_i = fs->top_field->size_x / 4;
int max_j = fs->top_field->size_y / 4;

// Local buffers to remove inter-loop dependencies
short ref_idx0_top[64][64], ref_idx1_top[64][64];
short ref_idx0_bot[64][64], ref_idx1_bot[64][64];
short mv0_top[64][64][2], mv1_top[64][64][2];
short mv0_bot[64][64][2], mv1_bot[64][64][2];
int64 ref_pic_num0_top[64][64], ref_pic_num1_top[64][64];
int64 ref_pic_num0_bot[64][64], ref_pic_num1_bot[64][64];
int64 frm_ref_pic_num0_top[64][64], frm_ref_pic_num1_top[64][64];
int64 frm_ref_pic_num0_bot[64][64], frm_ref_pic_num1_bot[64][64];

// Clamp sizes to avoid buffer overflow (assume max 64x64)
if (max_i > 64) max_i = 64;
if (max_j > 64) max_j = 64;

// Pass 1: Load all data without any side effects
for (i = 0; i < max_i; i++) {
    for (j = 0; j < max_j; j++) {
        ref_idx0_top[i][j] = fs->top_field->ref_idx[0][i][j];
        ref_idx1_top[i][j] = fs->top_field->ref_idx[1][i][j];
        ref_idx0_bot[i][j] = fs->bottom_field->ref_idx[0][i][j];
        ref_idx1_bot[i][j] = fs->bottom_field->ref_idx[1][i][j];

        mv0_top[i][j][0] = fs->top_field->mv[0][i][j][0];
        mv0_top[i][j][1] = fs->top_field->mv[0][i][j][1];
        mv1_top[i][j][0] = fs->top_field->mv[1][i][j][0];
        mv1_top[i][j][1] = fs->top_field->mv[1][i][j][1];

        mv0_bot[i][j][0] = fs->bottom_field->mv[0][i][j][0];
        mv0_bot[i][j][1] = fs->bottom_field->mv[0][i][j][1];
        mv1_bot[i][j][0] = fs->bottom_field->mv[1][i][j][0];
        mv1_bot[i][j][1] = fs->bottom_field->mv[1][i][j][1];

        // Only load ref_pic_num if index is valid; otherwise mark as invalid
        ref_pic_num0_top[i][j] = (ref_idx0_top[i][j] >= 0) ? fs->top_field->ref_pic_num[0][ref_idx0_top[i][j]] : 0;
        ref_pic_num1_top[i][j] = (ref_idx1_top[i][j] >= 0) ? fs->top_field->ref_pic_num[1][ref_idx1_top[i][j]] : 0;
        ref_pic_num0_bot[i][j] = (ref_idx0_bot[i][j] >= 0) ? fs->bottom_field->ref_pic_num[0][ref_idx0_bot[i][j]] : 0;
        ref_pic_num1_bot[i][j] = (ref_idx1_bot[i][j] >= 0) ? fs->bottom_field->ref_pic_num[1][ref_idx1_bot[i][j]] : 0;

        frm_ref_pic_num0_top[i][j] = (ref_idx0_top[i][j] >= 0) ? fs->top_field->frm_ref_pic_num[0][ref_idx0_top[i][j]] : 0;
        frm_ref_pic_num1_top[i][j] = (ref_idx1_top[i][j] >= 0) ? fs->top_field->frm_ref_pic_num[1][ref_idx1_top[i][j]] : 0;
        frm_ref_pic_num0_bot[i][j] = (ref_idx0_bot[i][j] >= 0) ? fs->bottom_field->frm_ref_pic_num[0][ref_idx0_bot[i][j]] : -1;
        frm_ref_pic_num1_bot[i][j] = (ref_idx1_bot[i][j] >= 0) ? fs->bottom_field->frm_ref_pic_num[1][ref_idx1_bot[i][j]] : -1;
    }
}

// Pass 2: Write all data to the frame without reading from source fields
for (i = 0; i < max_i; i++) {
    for (j = 0; j < max_j; j++) {
        int idx = 8 * (j / 4) + (j % 4);

        fs->frame->field_frame[i][idx] = 1;
        fs->frame->field_frame[i][idx + 4] = 1;

        fs->frame->mv[0][i][idx][0] = mv0_top[i][j][0];
        fs->frame->mv[0][i][idx][1] = mv0_top[i][j][1];
        fs->frame->mv[1][i][idx][0] = mv1_top[i][j][0];
        fs->frame->mv[1][i][idx][1] = mv1_top[i][j][1];

        fs->frame->mv[0][i][idx + 4][0] = mv0_bot[i][j][0];
        fs->frame->mv[0][i][idx + 4][1] = mv0_bot[i][j][1];
        fs->frame->mv[1][i][idx + 4][0] = mv1_bot[i][j][0];
        fs->frame->mv[1][i][idx + 4][1] = mv1_bot[i][j][1];

        dummylist0 = fs->frame->ref_idx[0][i][idx] = ref_idx0_top[i][j];
        dummylist1 = fs->frame->ref_idx[1][i][idx] = ref_idx1_top[i][j];

        dummylist0 = fs->frame->ref_idx[0][i][idx + 4] = ref_idx0_bot[i][j];
        dummylist1 = fs->frame->ref_idx[1][i][idx + 4] = ref_idx1_bot[i][j];

        fs->top_field->ref_id[0][i][j] = ref_pic_num0_top[i][j];
        fs->top_field->ref_id[1][i][j] = ref_pic_num1_top[i][j];
        fs->bottom_field->ref_id[0][i][j] = ref_pic_num0_bot[i][j];
        fs->bottom_field->ref_id[1][i][j] = ref_pic_num1_bot[i][j];

        fs->frame->ref_id[0][i][idx] = frm_ref_pic_num0_top[i][j];
        fs->frame->ref_id[1][i][idx] = frm_ref_pic_num1_top[i][j];
        fs->frame->ref_id[0][i][idx + 4] = frm_ref_pic_num0_bot[i][j];
        fs->frame->ref_id[1][i][idx + 4] = frm_ref_pic_num1_bot[i][j];
    }
}
}
