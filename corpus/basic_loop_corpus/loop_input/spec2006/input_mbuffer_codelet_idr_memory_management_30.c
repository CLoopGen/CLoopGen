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

void init_vars() {
    const unsigned int buffer_size = 256 * 1024 * 1024; // ~256MB target data
    const unsigned int num_fs_entries = buffer_size / (sizeof(FrameStore*) * 3);
    
    dpb.size = num_fs_entries;
    dpb.used_size = 0;
    dpb.ref_frames_in_buffer = 0;
    dpb.ltref_frames_in_buffer = num_fs_entries > 1000 ? 1000 : num_fs_entries;

    dpb.fs = (FrameStore**)calloc(num_fs_entries, sizeof(FrameStore*));
    dpb.fs_ref = (FrameStore**)calloc(num_fs_entries, sizeof(FrameStore*));
    dpb.fs_ltref = (FrameStore**)calloc(num_fs_entries, sizeof(FrameStore*));

    for (unsigned int idx = 0; idx < num_fs_entries; idx++) {
        dpb.fs[idx] = (FrameStore*)calloc(1, sizeof(FrameStore));
        dpb.fs_ref[idx] = (FrameStore*)calloc(1, sizeof(FrameStore));
        dpb.fs_ltref[idx] = (FrameStore*)calloc(1, sizeof(FrameStore));
        
        dpb.fs[idx]->frame = NULL;
        dpb.fs[idx]->top_field = NULL;
        dpb.fs[idx]->bottom_field = NULL;
        dpb.fs_ref[idx]->frame = NULL;
        dpb.fs_ref[idx]->top_field = NULL;
        dpb.fs_ref[idx]->bottom_field = NULL;
        dpb.fs_ltref[idx]->frame = NULL;
        dpb.fs_ltref[idx]->top_field = NULL;
        dpb.fs_ltref[idx]->bottom_field = NULL;
    }

    dpb.last_output_poc = 0;
    dpb.max_long_term_pic_idx = -1;
    dpb.init_done = 1;
    dpb.last_picture = NULL;

    i = 0;
}