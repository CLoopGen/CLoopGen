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

StorablePicture* listX_arr[6][256];
StorablePicture **listX[6] = { listX_arr[0], listX_arr[1], listX_arr[2],
                               listX_arr[3], listX_arr[4], listX_arr[5] };

unsigned int i;
int list0idx;

void init_vars() {
    const unsigned int num_storable_pics = 256;
    const unsigned int num_frame_stores = 32;
    const unsigned int num_long_term_refs = 16;

    StorablePicture* pics = (StorablePicture*)calloc(num_storable_pics, sizeof(StorablePicture));
    FrameStore* fs_array = (FrameStore*)calloc(num_frame_stores, sizeof(FrameStore));

    dpb.fs = (FrameStore**)calloc(num_frame_stores, sizeof(FrameStore*));
    dpb.fs_ref = (FrameStore**)calloc(num_frame_stores, sizeof(FrameStore*));
    dpb.fs_ltref = (FrameStore**)calloc(num_frame_stores, sizeof(FrameStore*));
    dpb.size = num_frame_stores;
    dpb.used_size = num_frame_stores;
    dpb.ref_frames_in_buffer = 0;
    dpb.ltref_frames_in_buffer = num_long_term_refs;
    dpb.last_output_poc = 0;
    dpb.max_long_term_pic_idx = 15;
    dpb.init_done = 1;
    dpb.last_picture = NULL;

    for (unsigned int idx = 0; idx < num_frame_stores; ++idx) {
        dpb.fs[idx] = &fs_array[idx];
        dpb.fs_ref[idx] = &fs_array[idx];
        if (idx < num_long_term_refs) {
            dpb.fs_ltref[idx] = &fs_array[idx];
            fs_array[idx].is_used = 3;
            fs_array[idx].is_long_term = 1;
            fs_array[idx].frame = &pics[idx];
            fs_array[idx].frame->is_long_term = 1;
            fs_array[idx].frame->long_term_frame_idx = idx;
            fs_array[idx].frame->order_num = 0;
            fs_array[idx].poc = idx * 2;
        } else {
            dpb.fs_ltref[idx] = NULL;
            fs_array[idx].is_used = 0;
            fs_array[idx].frame = NULL;
        }
    }

    list0idx = 0;
    i = 0;
}