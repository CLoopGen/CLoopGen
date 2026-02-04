#include <stdio.h>
#include <stdlib.h>
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

FrameStore *fs;
int i;
int j;

void init_vars() {
    fs = (FrameStore *)malloc(sizeof(FrameStore));
    if (!fs) exit(1);

    fs->frame = (StorablePicture *)malloc(sizeof(StorablePicture));
    if (!fs->frame) exit(1);

    fs->frame->size_x = 1024;
    fs->frame->size_y = 1024;
    fs->frame->MbaffFrameFlag = 1;

    int width_in_blocks = fs->frame->size_x / 4;
    int height_in_blocks = fs->frame->size_y / 4;
    int num_macroblocks = (fs->frame->size_x / 16) * (fs->frame->size_y / 16) * 2;

    fs->frame->mb_field = (byte *)calloc(num_macroblocks, sizeof(byte));
    if (!fs->frame->mb_field) exit(1);

    fs->frame->field_frame = (byte **)malloc(width_in_blocks * sizeof(byte *));
    if (!fs->frame->field_frame) exit(1);

    for (int idx = 0; idx < width_in_blocks; idx++) {
        fs->frame->field_frame[idx] = (byte *)calloc(height_in_blocks, sizeof(byte));
        if (!fs->frame->field_frame[idx]) exit(1);
    }

    for (int idx = 0; idx < num_macroblocks; idx++) {
        fs->frame->mb_field[idx] = rand() % 2;
    }
}