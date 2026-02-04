#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

unsigned int i;
unsigned int pic_num;
int min_poc;
DecodedPictureBuffer dpb;

static StorablePicture* create_storable_picture() {
    StorablePicture* sp = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    if (!sp) return NULL;
    sp->imgY = (unsigned short**)calloc(1, sizeof(unsigned short*));
    if (sp->imgY) {
        sp->imgY[0] = (unsigned short*)calloc(16, sizeof(unsigned short));
    }
    sp->imgY_11 = (unsigned short*)calloc(16, sizeof(unsigned short));
    sp->imgY_11_w = (unsigned short*)calloc(16, sizeof(unsigned short));
    sp->imgY_ups = (unsigned short**)calloc(1, sizeof(unsigned short*));
    if (sp->imgY_ups) {
        sp->imgY_ups[0] = (unsigned short*)calloc(16, sizeof(unsigned short));
    }
    sp->imgY_ups_w = (unsigned short**)calloc(1, sizeof(unsigned short*));
    if (sp->imgY_ups_w) {
        sp->imgY_ups_w[0] = (unsigned short*)calloc(16, sizeof(unsigned short));
    }
    sp->imgUV = (unsigned short***)calloc(1, sizeof(unsigned short**));
    if (sp->imgUV) {
        sp->imgUV[0] = (unsigned short**)calloc(1, sizeof(unsigned short*));
        if (sp->imgUV[0]) {
            sp->imgUV[0][0] = (unsigned short*)calloc(8, sizeof(unsigned short));
        }
    }
    sp->mb_field = (byte*)calloc(16, sizeof(byte));
    sp->ref_idx = (short***)calloc(1, sizeof(short**));
    if (sp->ref_idx) {
        sp->ref_idx[0] = (short**)calloc(1, sizeof(short*));
        if (sp->ref_idx[0]) {
            sp->ref_idx[0][0] = (short*)calloc(16, sizeof(short));
        }
    }
    sp->ref_pic_id = (int64***)calloc(1, sizeof(int64**));
    if (sp->ref_pic_id) {
        sp->ref_pic_id[0] = (int64**)calloc(1, sizeof(int64*));
        if (sp->ref_pic_id[0]) {
            sp->ref_pic_id[0][0] = (int64*)calloc(16, sizeof(int64));
        }
    }
    sp->ref_id = (int64***)calloc(1, sizeof(int64**));
    if (sp->ref_id) {
        sp->ref_id[0] = (int64**)calloc(1, sizeof(int64*));
        if (sp->ref_id[0]) {
            sp->ref_id[0][0] = (int64*)calloc(16, sizeof(int64));
        }
    }
    sp->mv = (short****)calloc(1, sizeof(short***));
    if (sp->mv) {
        sp->mv[0] = (short***)calloc(1, sizeof(short**));
        if (sp->mv[0]) {
            sp->mv[0][0] = (short**)calloc(1, sizeof(short*));
            if (sp->mv[0][0]) {
                sp->mv[0][0][0] = (short*)calloc(2, sizeof(short));
            }
        }
    }
    sp->moving_block = (byte**)calloc(1, sizeof(byte*));
    if (sp->moving_block) {
        sp->moving_block[0] = (byte*)calloc(16, sizeof(byte));
    }
    sp->field_frame = (byte**)calloc(1, sizeof(byte*));
    if (sp->field_frame) {
        sp->field_frame[0] = (byte*)calloc(16, sizeof(byte));
    }
    return sp;
}

static FrameStore* create_frame_store(int idx) {
    FrameStore* fs = (FrameStore*)calloc(1, sizeof(FrameStore));
    if (!fs) return NULL;
    fs->frame = create_storable_picture();
    if (fs->frame) {
        fs->frame->poc = 100 - idx;
        fs->frame->pic_num = idx;
        fs->poc = 100 - idx;
    }
    fs->is_used = 1;
    fs->is_reference = 1;
    fs->is_long_term = 0;
    fs->is_orig_reference = 1;
    fs->is_non_existent = 0;
    fs->frame_num = idx;
    fs->frame_num_wrap = idx;
    fs->long_term_frame_idx = -1;
    fs->is_output = 0;
    return fs;
}

void init_vars() {
    const unsigned int target_data_size = 64 * 1024 * 1024;
    const unsigned int base_size = sizeof(FrameStore*);
    unsigned int num_elements = target_data_size / base_size;
    if (num_elements < 16) num_elements = 16;
    if (num_elements > 1024) num_elements = 1024;

    dpb.size = num_elements;
    dpb.used_size = num_elements;
    dpb.ref_frames_in_buffer = 0;
    dpb.ltref_frames_in_buffer = 0;
    dpb.last_output_poc = 0;
    dpb.max_long_term_pic_idx = -1;
    dpb.init_done = 1;
    dpb.last_picture = NULL;

    dpb.fs = (FrameStore**)calloc(num_elements, sizeof(FrameStore*));
    dpb.fs_ref = (FrameStore**)calloc(num_elements, sizeof(FrameStore*));
    dpb.fs_ltref = (FrameStore**)calloc(num_elements, sizeof(FrameStore*));

    for (unsigned int idx = 0; idx < num_elements; idx++) {
        dpb.fs[idx] = create_frame_store(idx);
        if (dpb.fs[idx]->is_reference && !dpb.fs[idx]->is_long_term) {
            dpb.fs_ref[dpb.ref_frames_in_buffer++] = dpb.fs[idx];
        }
    }

    min_poc = 1000;
    pic_num = 0;
    i = 0;
}