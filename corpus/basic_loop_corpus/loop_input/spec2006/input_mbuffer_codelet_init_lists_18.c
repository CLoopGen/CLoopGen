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
int add_top;
int add_bottom;
unsigned int i;
int listltidx;
FrameStore **fs_listlt;

static StorablePicture **g_storable_pictures;
static FrameStore **g_frame_stores;
static FrameStore **g_fs_ltref_array;
static FrameStore **g_fs_listlt_array;

void init_vars() {
    const unsigned int buffer_size = 256 * 1024 * 1024; // ~256 MB target
    const unsigned int num_fs = 32;
    const unsigned int num_refs = 16;

    g_storable_pictures = calloc(num_fs * 3, sizeof(StorablePicture*));
    g_frame_stores = calloc(num_fs, sizeof(FrameStore*));
    g_fs_ltref_array = calloc(num_refs, sizeof(FrameStore*));
    g_fs_listlt_array = calloc(num_refs, sizeof(FrameStore*));

    for (unsigned int idx = 0; idx < num_fs * 3; idx++) {
        g_storable_pictures[idx] = calloc(1, sizeof(StorablePicture));
    }

    for (unsigned int idx = 0; idx < num_fs; idx++) {
        g_frame_stores[idx] = calloc(1, sizeof(FrameStore));
        g_frame_stores[idx]->frame = g_storable_pictures[idx * 3 + 0];
        g_frame_stores[idx]->top_field = g_storable_pictures[idx * 3 + 1];
        g_frame_stores[idx]->bottom_field = g_storable_pictures[idx * 3 + 2];

        g_frame_stores[idx]->frame->top_field = g_frame_stores[idx]->top_field;
        g_frame_stores[idx]->frame->bottom_field = g_frame_stores[idx]->bottom_field;
        g_frame_stores[idx]->frame->frame = g_frame_stores[idx]->frame;

        g_frame_stores[idx]->top_field->long_term_frame_idx = idx;
        g_frame_stores[idx]->bottom_field->long_term_frame_idx = idx;

        g_frame_stores[idx]->is_long_term = (idx % 3 == 0) ? 3 : 0;
        g_frame_stores[idx]->poc = idx * 2;
    }

    unsigned int lt_count = 0;
    for (unsigned int idx = 0; idx < num_fs && lt_count < num_refs; idx++) {
        if (g_frame_stores[idx]->is_long_term) {
            g_fs_ltref_array[lt_count] = g_frame_stores[idx];
            lt_count++;
        }
    }

    dpb.fs_ltref = g_fs_ltref_array;
    dpb.ltref_frames_in_buffer = lt_count;
    dpb.init_done = 1;
    dpb.last_picture = g_frame_stores[0];

    fs_listlt = g_fs_listlt_array;
    listltidx = 0;
    add_top = 1;
    add_bottom = 2;
}