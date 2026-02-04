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
int list0idx;
FrameStore **fs_list0;

void init_vars() {
    const unsigned int total_fs_count = 32;
    const unsigned int ref_frames_count = 16;
    
    dpb.size = total_fs_count;
    dpb.used_size = total_fs_count;
    dpb.ref_frames_in_buffer = ref_frames_count;
    dpb.ltref_frames_in_buffer = 8;
    dpb.last_output_poc = 0;
    dpb.max_long_term_pic_idx = -1;
    dpb.init_done = 1;
    dpb.last_picture = NULL;

    dpb.fs = (FrameStore**)calloc(total_fs_count, sizeof(FrameStore*));
    dpb.fs_ref = (FrameStore**)calloc(ref_frames_count, sizeof(FrameStore*));
    dpb.fs_ltref = (FrameStore**)calloc(8, sizeof(FrameStore*));
    fs_list0 = (FrameStore**)calloc(total_fs_count, sizeof(FrameStore*));

    for (unsigned int idx = 0; idx < total_fs_count; ++idx) {
        dpb.fs[idx] = (FrameStore*)calloc(1, sizeof(FrameStore));
        dpb.fs[idx]->is_used = 1;
        dpb.fs[idx]->is_reference = (idx < ref_frames_count) ? 1 : 0;
        dpb.fs[idx]->is_long_term = (idx % 2 == 0);
        dpb.fs[idx]->is_orig_reference = dpb.fs[idx]->is_reference;
        dpb.fs[idx]->is_non_existent = 0;
        dpb.fs[idx]->frame_num = idx;
        dpb.fs[idx]->frame_num_wrap = idx;
        dpb.fs[idx]->long_term_frame_idx = (dpb.fs[idx]->is_long_term) ? (idx / 2) : -1;
        dpb.fs[idx]->is_output = 0;
        dpb.fs[idx]->poc = idx * 2;

        dpb.fs[idx]->frame = (StorablePicture*)calloc(1, sizeof(StorablePicture));
        dpb.fs[idx]->frame->structure = FRAME;
        dpb.fs[idx]->frame->poc = dpb.fs[idx]->poc;
        dpb.fs[idx]->frame->frame_num = dpb.fs[idx]->frame_num;
        dpb.fs[idx]->frame->used_for_reference = dpb.fs[idx]->is_reference;
        dpb.fs[idx]->frame->is_long_term = dpb.fs[idx]->is_long_term;
        dpb.fs[idx]->frame->is_output = dpb.fs[idx]->is_output;
        dpb.fs[idx]->frame->non_existing = 0;
        dpb.fs[idx]->frame->size_x = 1920;
        dpb.fs[idx]->frame->size_y = 1080;
        dpb.fs[idx]->frame->chroma_format_idc = 1;
        dpb.fs[idx]->frame->frame_mbs_only_flag = 1;
        dpb.fs[idx]->frame->frame_cropping_flag = 0;

        if (idx < ref_frames_count) {
            dpb.fs_ref[idx] = dpb.fs[idx];
        }
    }

    for (unsigned int idx = 0; idx < 8; ++idx) {
        dpb.fs_ltref[idx] = dpb.fs[idx * 2];
    }

    list0idx = 0;
}

void loop();