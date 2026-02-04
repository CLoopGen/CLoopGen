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

DecodedPictureBuffer dpb;
unsigned int i;
unsigned int j;
int re_order[32];
int list_sign[32];
int poc_diff[32];
int tmp_value;

void init_vars() {
    // Set reference frame count within bounds of re_order, list_sign, and poc_diff arrays
    dpb.ref_frames_in_buffer = 32;

    // Allocate and initialize fs_ref array to avoid null pointer dereference
    dpb.fs_ref = (FrameStore**)calloc(dpb.ref_frames_in_buffer, sizeof(FrameStore*));
    for (unsigned int idx = 0; idx < dpb.ref_frames_in_buffer; ++idx) {
        dpb.fs_ref[idx] = (FrameStore*)calloc(1, sizeof(FrameStore));
        dpb.fs_ref[idx]->is_used = 1;
        dpb.fs_ref[idx]->poc = idx * 5 - 80; // Spread POC values over a range
    }

    // Initialize poc_diff with absolute POC differences to create sorting workload
    for (int idx = 0; idx < 32; ++idx) {
        poc_diff[idx] = abs(dpb.fs_ref[idx]->poc);
        re_order[idx] = idx;
        list_sign[idx] = (dpb.fs_ref[idx]->poc >= 0) ? 1 : -1;
    }

    // Shuffle the first few elements to ensure sorting work is done
    for (int idx = 0; idx < 32; ++idx) {
        if (idx % 3 == 0 && idx + 1 < 32) {
            int temp = poc_diff[idx];
            poc_diff[idx] = poc_diff[idx+1];
            poc_diff[idx+1] = temp;

            temp = re_order[idx];
            re_order[idx] = re_order[idx+1];
            re_order[idx+1] = temp;

            temp = list_sign[idx];
            list_sign[idx] = list_sign[idx+1];
            list_sign[idx+1] = temp;
        }
    }

    // Ensure dpb fields are initialized
    dpb.size = 32;
    dpb.used_size = 32;
    dpb.ltref_frames_in_buffer = 0;
    dpb.last_output_poc = 0;
    dpb.max_long_term_pic_idx = -1;
    dpb.init_done = 1;
    dpb.last_picture = NULL;
    dpb.fs = (FrameStore**)calloc(32, sizeof(FrameStore*));
    for (unsigned int idx = 0; idx < 32; ++idx) {
        dpb.fs[idx] = dpb.fs_ref[idx];
    }
    dpb.fs_ltref = (FrameStore**)calloc(32, sizeof(FrameStore*));
}