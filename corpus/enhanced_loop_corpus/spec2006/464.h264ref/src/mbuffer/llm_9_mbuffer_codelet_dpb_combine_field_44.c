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

extern int listXsize[6];
extern FrameStore *fs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (listXsize[1] + 3) / 2; // Slightly increased trip count
    for (i = 0; i < limit; i += 2) { // Stride-2 iteration to reduce total operations but increase per-iteration work
        if (i < (listXsize[1] + 1) / 2) {
            int64 t1 = fs->top_field->ref_pic_num[1][2 * i];
            int64 b1 = fs->bottom_field->ref_pic_num[1][2 * i];
            fs->frame->ref_pic_num[1][i] = ((t1 & ~1LL) < (b1 & ~1LL)) ? (t1 & ~1LL) : (b1 & ~1LL);
        }
        if (i + 1 < (listXsize[1] + 1) / 2) {
            int64 t2 = fs->top_field->ref_pic_num[1][2 * (i + 1)];
            int64 b2 = fs->bottom_field->ref_pic_num[1][2 * (i + 1)];
            fs->frame->ref_pic_num[1][i + 1] = ((t2 & ~1LL) < (b2 & ~1LL)) ? (t2 & ~1LL) : (b2 & ~1LL);
        }
    }
}
