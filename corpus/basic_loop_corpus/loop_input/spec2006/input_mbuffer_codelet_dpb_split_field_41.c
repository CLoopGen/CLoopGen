#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

int listXsize[6];

FrameStore *fs;

int i;

void init_vars() {
    for (int j = 0; j < 6; j++) {
        listXsize[j] = 0;
    }
    
    listXsize[0] = 16; 

    fs = (FrameStore *)calloc(1, sizeof(FrameStore));
    if (!fs) return;

    fs->frame = (StorablePicture *)calloc(1, sizeof(StorablePicture));
    fs->top_field = (StorablePicture *)calloc(1, sizeof(StorablePicture));
    fs->bottom_field = (StorablePicture *)calloc(1, sizeof(StorablePicture));

    if (!fs->frame || !fs->top_field || !fs->bottom_field) return;

    fs->frame->structure = FRAME;
    fs->top_field->structure = TOP_FIELD;
    fs->bottom_field->structure = BOTTOM_FIELD;

    fs->frame->top_field = fs->top_field;
    fs->frame->bottom_field = fs->bottom_field;
    fs->top_field->frame = fs->frame;
    fs->bottom_field->frame = fs->frame;

    for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 33; k++) {
            fs->frame->ref_pic_num[j][k] = (int64)(j * 1000 + k);
        }
    }

    fs->frame->top_poc = 100;
    fs->frame->bottom_poc = 101;
}