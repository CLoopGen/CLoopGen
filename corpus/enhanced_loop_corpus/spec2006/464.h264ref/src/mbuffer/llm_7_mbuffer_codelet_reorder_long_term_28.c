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
extern int LongTermPicNum;
extern int *refIdxLX;
extern int cIdx;
extern int nIdx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_nIdx = nIdx;
    int i;
    for (i = *refIdxLX; i <= num_ref_idx_lX_active_minus1 + 1; i++) {
        StorablePicture* current_pic = RefPicListX[i];
        int is_not_long_term = !current_pic->is_long_term;
        int lt_num_differs = current_pic->long_term_pic_num != LongTermPicNum;
        int include = is_not_long_term || lt_num_differs;
        // Introduce artificial WAW and WAR dependency via redundant updates to same index
        if (include) {
            RefPicListX[local_nIdx] = current_pic;
            local_nIdx = local_nIdx + 1; // WAR: read-before-write on local_nIdx
        }
        // Artificially write back intermediate state (WAW on RefPicListX elements)
        if (i > *refIdxLX && include) {
            RefPicListX[local_nIdx - 2] = RefPicListX[local_nIdx - 2]; // Redundant self-assignment (WAW)
        }
    }
    nIdx = local_nIdx; // Final update to shared output variable
}
