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

int j;
int list0idx;
int list0idx_1;
FrameStore **fs_list0;
FrameStore **fs_list1;

void init_vars() {
    const int total_size = 256 * 1024 * 1024; // Target ~256MB of data
    const int avg_framestore_size = 1024;     // Estimate per FrameStore data size
    const int num_elements = total_size / avg_framestore_size;

    list0idx_1 = num_elements;
    list0idx = list0idx_1 + 10; // Ensure fs_list1 has enough space

    fs_list0 = (FrameStore**)calloc(list0idx_1, sizeof(FrameStore*));
    fs_list1 = (FrameStore**)calloc(list0idx, sizeof(FrameStore*));

    for (int i = 0; i < list0idx_1; i++) {
        fs_list0[i] = (FrameStore*)calloc(1, sizeof(FrameStore));
        fs_list0[i]->frame = (StorablePicture*)calloc(1, sizeof(StorablePicture));
        fs_list0[i]->frame->structure = FRAME;
        fs_list0[i]->frame->poc = i;
        fs_list0[i]->frame_num = i;
        fs_list0[i]->poc = i;
        fs_list0[i]->is_used = 1;
    }

    for (int i = 0; i < list0idx; i++) {
        fs_list1[i] = NULL;
    }
}