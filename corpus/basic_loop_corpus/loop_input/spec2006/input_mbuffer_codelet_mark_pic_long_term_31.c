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
int long_term_frame_idx;
int picNumX;
unsigned int i;

static FrameStore* g_frame_stores = NULL;
static StorablePicture* g_storable_pictures = NULL;
static FrameStore** g_fs_array = NULL;
static FrameStore** g_fs_ref_array = NULL;

void init_vars() {
    const unsigned int buffer_size = 256;
    
    g_frame_stores = calloc(buffer_size, sizeof(FrameStore));
    g_storable_pictures = calloc(buffer_size * 3, sizeof(StorablePicture));
    g_fs_array = calloc(buffer_size, sizeof(FrameStore*));
    g_fs_ref_array = calloc(buffer_size, sizeof(FrameStore*));

    if (!g_frame_stores || !g_storable_pictures || !g_fs_array || !g_fs_ref_array) {
        return;
    }

    dpb.fs = g_fs_array;
    dpb.fs_ref = g_fs_ref_array;
    dpb.fs_ltref = NULL;
    dpb.size = buffer_size;
    dpb.used_size = 0;
    dpb.ref_frames_in_buffer = buffer_size;
    dpb.ltref_frames_in_buffer = 0;
    dpb.last_output_poc = 0;
    dpb.max_long_term_pic_idx = -1;
    dpb.init_done = 1;
    dpb.last_picture = NULL;

    long_term_frame_idx = 5;
    picNumX = 100;

    for (unsigned int idx = 0; idx < buffer_size; idx++) {
        FrameStore* fs = &g_frame_stores[idx];
        StorablePicture* frame_pic = &g_storable_pictures[idx * 3];
        StorablePicture* top_pic = &g_storable_pictures[idx * 3 + 1];
        StorablePicture* bottom_pic = &g_storable_pictures[idx * 3 + 2];

        fs->is_used = 1;
        fs->is_reference = (idx == 10) ? 3 : 0;
        fs->is_long_term = 0;
        fs->is_orig_reference = 0;
        fs->is_non_existent = 0;
        fs->frame_num = idx;
        fs->frame_num_wrap = idx;
        fs->long_term_frame_idx = -1;
        fs->is_output = 0;
        fs->poc = idx * 2;

        frame_pic->structure = FRAME;
        frame_pic->poc = idx * 2;
        frame_pic->pic_num = (idx == 10) ? picNumX : picNumX + 1;
        frame_pic->long_term_frame_idx = -1;
        frame_pic->long_term_pic_num = -1;
        frame_pic->is_long_term = 0;
        frame_pic->used_for_reference = 1;
        frame_pic->is_output = 0;
        frame_pic->non_existing = 0;

        top_pic->structure = TOP_FIELD;
        top_pic->poc = idx * 2;
        top_pic->long_term_frame_idx = -1;
        top_pic->long_term_pic_num = -1;
        top_pic->is_long_term = 0;

        bottom_pic->structure = BOTTOM_FIELD;
        bottom_pic->poc = idx * 2;
        bottom_pic->long_term_frame_idx = -1;
        bottom_pic->long_term_pic_num = -1;
        bottom_pic->is_long_term = 0;

        fs->frame = frame_pic;
        fs->top_field = top_pic;
        fs->bottom_field = bottom_pic;

        dpb.fs[idx] = fs;
        dpb.fs_ref[idx] = fs;
    }
}