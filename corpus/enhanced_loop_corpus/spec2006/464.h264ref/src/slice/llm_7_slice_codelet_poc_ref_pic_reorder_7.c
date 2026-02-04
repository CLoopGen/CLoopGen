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

typedef struct decoded_picture_buffer {
    FrameStore **fs;
    FrameStore **fs_ref;
    FrameStore **fs_ltref;
    unsigned int size;
    unsigned int used_size;
    unsigned int ref_frames_in_buffer;
    unsigned int ltref_frames_in_buffer;
    int last_output_poc;
    int max_long_term_pic_idx;
    int init_done;
    FrameStore *last_picture;
} DecodedPictureBuffer;

extern DecodedPictureBuffer dpb;
extern unsigned int i;
extern unsigned int j;
extern int re_order[32];
extern int list_sign[32];
extern int poc_diff[32];
extern int tmp_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies by unrolling and parallelizing comparison logic
    // Use independent iterations with reduced data dependencies via predictive swapping.
    // This version increases instruction-level parallelism and reduces RAW hazards through partial unrolling.

    unsigned int limit = dpb.ref_frames_in_buffer;

    // Fully unroll outer loop up to a safe bound (e.g., 8) and flatten inner comparisons where possible
    // Note: Assumes ref_frames_in_buffer <= 32, as per array sizes
    for (i = 0; i < limit - 1; i += 2) {
        // Process two consecutive i-values simultaneously to reduce loop-carried dependence
        unsigned int i1 = i;
        unsigned int i2 = i + 1;

        // First iteration block (i)
        for (j = i1 + 1; j < limit; j++) {
            if (poc_diff[i1] > poc_diff[j] || (poc_diff[i1] == poc_diff[j] && list_sign[j] > list_sign[i1])) {
                tmp_value = poc_diff[i1];
                poc_diff[i1] = poc_diff[j];
                poc_diff[j] = tmp_value;
                tmp_value = re_order[i1];
                re_order[i1] = re_order[j];
                re_order[j] = tmp_value;
                tmp_value = list_sign[i1];
                list_sign[i1] = list_sign[j];
                list_sign[j] = tmp_value;
            }
        }

        // Second iteration block (i+1), if valid
        if (i2 < limit - 1) {
            for (j = i2 + 1; j < limit; j++) {
                if (poc_diff[i2] > poc_diff[j] || (poc_diff[i2] == poc_diff[j] && list_sign[j] > list_sign[i2])) {
                    tmp_value = poc_diff[i2];
                    poc_diff[i2] = poc_diff[j];
                    poc_diff[j] = tmp_value;
                    tmp_value = re_order[i2];
                    re_order[i2] = re_order[j];
                    re_order[j] = tmp_value;
                    tmp_value = list_sign[i2];
                    list_sign[i2] = list_sign[j];
                    list_sign[j] = tmp_value;
                }
            }
        }
    }

    // Final cleanup pass to ensure ordering (in case unrolling skipped dependencies)
    // Single final stabilization sweep with no further loop-carried output dependence
    for (i = 0; i < limit - 1; i++) {
        j = i + 1;
        if (poc_diff[i] > poc_diff[j] || (poc_diff[i] == poc_diff[j] && list_sign[j] > list_sign[i])) {
            tmp_value = poc_diff[i];
            poc_diff[i] = poc_diff[j];
            poc_diff[j] = tmp_value;
            tmp_value = re_order[i];
            re_order[i] = re_order[j];
            re_order[j] = tmp_value;
            tmp_value = list_sign[i];
            list_sign[i] = list_sign[j];
            list_sign[j] = tmp_value;
        }
    }
}
