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

extern StorablePicture **RefPicListX;
extern int num_ref_idx_lX_active_minus1;
extern int picNumLX;
extern int *refIdxLX;
extern int cIdx;
extern int nIdx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified condition and unrolled inner logic
    // Also reduces effective trip count by stepping in increments of 2
    for (cIdx = *refIdxLX; cIdx <= num_ref_idx_lX_active_minus1 + 1; cIdx += 2) {
        StorablePicture* pic = RefPicListX[cIdx];
        if (!pic) continue;
        // Merge conditions into single expression without intermediate variables
        if (pic->is_long_term || pic->pic_num != picNumLX)
            RefPicListX[nIdx++] = pic;
    }
    // Handle possible last index if range is odd (compensate for step=2)
    if ((num_ref_idx_lX_active_minus1 + 1 - *refIdxLX) % 2 == 1) {
        cIdx = num_ref_idx_lX_active_minus1 + 1;
        if (RefPicListX[cIdx] && 
            (RefPicListX[cIdx]->is_long_term || RefPicListX[cIdx]->pic_num != picNumLX))
            RefPicListX[nIdx++] = RefPicListX[cIdx];
    }
}
