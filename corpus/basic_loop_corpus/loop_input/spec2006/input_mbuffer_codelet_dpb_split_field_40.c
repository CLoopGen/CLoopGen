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
    for (int idx = 0; idx < 6; idx++) {
        listXsize[idx] = 0;
    }
    listXsize[1] = 16; // Ensures loop runs 16 times, adjust if needed for timing

    fs = (FrameStore*)calloc(1, sizeof(FrameStore));
    fs->frame = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    fs->top_field = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    fs->bottom_field = (StorablePicture*)calloc(1, sizeof(StorablePicture));

    fs->frame->top_field = NULL;
    fs->frame->bottom_field = NULL;
    fs->frame->frame = NULL;
    fs->top_field->frame = fs->frame;
    fs->bottom_field->frame = fs->frame;

    // Initialize arrays in fs->frame to avoid undefined behavior
    for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 33; k++) {
            fs->frame->ref_pic_num[j][k] = 0;
        }
    }

    // Allocate pointer arrays to prevent crashes on access
    StorablePicture *p = fs->frame;
    p->imgY = (unsigned short**)calloc(1, sizeof(unsigned short*));
    p->imgUV = (unsigned short***)calloc(1, sizeof(unsigned short**));
    p->ref_idx = (short***)calloc(1, sizeof(short**));
    p->ref_pic_id = (int64***)calloc(1, sizeof(int64**));
    p->ref_id = (int64***)calloc(1, sizeof(int64**));
    p->mv = (short****)calloc(1, sizeof(short***));
    p->moving_block = (byte**)calloc(1, sizeof(byte*));
    p->field_frame = (byte**)calloc(1, sizeof(byte*));

    p = fs->top_field;
    p->imgY = (unsigned short**)calloc(1, sizeof(unsigned short*));
    p->imgUV = (unsigned short***)calloc(1, sizeof(unsigned short**));
    p->ref_idx = (short***)calloc(1, sizeof(short**));
    p->ref_pic_id = (int64***)calloc(1, sizeof(int64**));
    p->ref_id = (int64***)calloc(1, sizeof(int64**));
    p->mv = (short****)calloc(1, sizeof(short***));
    p->moving_block = (byte**)calloc(1, sizeof(byte*));
    p->field_frame = (byte**)calloc(1, sizeof(byte*));

    p = fs->bottom_field;
    p->imgY = (unsigned short**)calloc(1, sizeof(unsigned short*));
    p->imgUV = (unsigned short***)calloc(1, sizeof(unsigned short**));
    p->ref_idx = (short***)calloc(1, sizeof(short**));
    p->ref_pic_id = (int64***)calloc(1, sizeof(int64**));
    p->ref_id = (int64***)calloc(1, sizeof(int64**));
    p->mv = (short****)calloc(1, sizeof(short***));
    p->moving_block = (byte**)calloc(1, sizeof(byte*));
    p->field_frame = (byte**)calloc(1, sizeof(byte*));
}