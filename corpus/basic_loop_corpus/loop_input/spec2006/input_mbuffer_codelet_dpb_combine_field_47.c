#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef enum {
    FRAME,
    TOP_FIELD,
    BOTTOM_FIELD
} PictureStructure;

typedef unsigned char byte;

typedef struct storable_picture {
    PictureStructure structure;
    int poc;
    int top_poc;
    int bottom_poc;
    int frame_poc;
    int order_num;
    int64_t ref_pic_num[6][33];
    int64_t frm_ref_pic_num[6][33];
    int64_t top_ref_pic_num[6][33];
    int64_t bottom_ref_pic_num[6][33];
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
    int64_t ***ref_pic_id;
    int64_t ***ref_id;
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
    fs = (FrameStore *)calloc(1, sizeof(FrameStore));
    StorablePicture *top_field_pic = (StorablePicture *)calloc(1, sizeof(StorablePicture));
    StorablePicture *bottom_field_pic = (StorablePicture *)calloc(1, sizeof(StorablePicture));

    int width = 512;
    int height = 512;

    top_field_pic->size_x = width;
    top_field_pic->size_y = height;
    bottom_field_pic->size_x = width;
    bottom_field_pic->size_y = height;

    top_field_pic->field_frame = (byte **)malloc(width / 4 * sizeof(byte *));
    bottom_field_pic->field_frame = (byte **)malloc(width / 4 * sizeof(byte *));

    for (int idx = 0; idx < width / 4; idx++) {
        top_field_pic->field_frame[idx] = (byte *)calloc(height / 4, sizeof(byte));
        bottom_field_pic->field_frame[idx] = (byte *)calloc(height / 4, sizeof(byte));
    }

    fs->top_field = top_field_pic;
    fs->bottom_field = bottom_field_pic;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}