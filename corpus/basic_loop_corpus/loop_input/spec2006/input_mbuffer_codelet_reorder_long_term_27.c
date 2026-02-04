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

StorablePicture **RefPicListX;
int num_ref_idx_lX_active_minus1;
int *refIdxLX;
int cIdx;

void init_vars() {
    const int list_size = 32;
    num_ref_idx_lX_active_minus1 = list_size - 1;
    refIdxLX = (int*)malloc(sizeof(int));
    *refIdxLX = 0;

    RefPicListX = (StorablePicture**)calloc(list_size + 1, sizeof(StorablePicture*));
    for (int i = 0; i <= list_size; i++) {
        RefPicListX[i] = (StorablePicture*)malloc(sizeof(StorablePicture));
        RefPicListX[i]->structure = FRAME;
        RefPicListX[i]->poc = i * 10;
        RefPicListX[i]->frame_num = i;
        RefPicListX[i]->used_for_reference = 1;
        RefPicListX[i]->is_output = 1;
        RefPicListX[i]->non_existing = 0;
        RefPicListX[i]->size_x = 1920;
        RefPicListX[i]->size_y = 1080;
        RefPicListX[i]->chroma_format_idc = 1;
        RefPicListX[i]->frame_mbs_only_flag = 1;
        RefPicListX[i]->frame_cropping_flag = 0;
    }
}