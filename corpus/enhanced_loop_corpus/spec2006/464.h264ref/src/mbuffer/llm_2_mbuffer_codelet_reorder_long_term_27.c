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
extern int *refIdxLX;
extern int cIdx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal using a stride of 2 (simulated by skipping elements)
    // This variant processes every other element in reverse, assuming alignment and size allow it.
    int start = num_ref_idx_lX_active_minus1 + 1;
    int end = *refIdxLX;
    for (cIdx = (start % 2 == 0) ? start : start - 1; cIdx > end; cIdx -= 2) {
        if (cIdx - 2 >= end + 1) {
            RefPicListX[cIdx] = RefPicListX[cIdx - 1];
            RefPicListX[cIdx - 2] = RefPicListX[cIdx - 3];
        } else if (cIdx - 1 > end) {
            RefPicListX[cIdx] = RefPicListX[cIdx - 1];
        }
    }
    // Final cleanup for any remaining element
    if ((start % 2 != 0) && start > *refIdxLX) {
        cIdx = start;
        RefPicListX[cIdx] = RefPicListX[cIdx - 1];
    }
}
