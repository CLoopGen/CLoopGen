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

StorablePicture **listX[6];
int listXsize[6];
int j;
int diff;

void init_vars() {
    const int num_lists = 2;
    const int pictures_per_list = 50000;

    for (int i = 0; i < num_lists; i++) {
        listXsize[i] = pictures_per_list;
        listX[i] = (StorablePicture**)calloc(pictures_per_list, sizeof(StorablePicture*));
        for (int j = 0; j < pictures_per_list; j++) {
            listX[i][j] = (StorablePicture*)calloc(1, sizeof(StorablePicture));
            listX[i][j]->structure = FRAME;
            listX[i][j]->poc = j;
            listX[i][j]->frame_num = j % 16;
            listX[i][j]->used_for_reference = 1;
            listX[i][j]->is_output = 1;
            listX[i][j]->non_existing = 0;
            listX[i][j]->size_x = 1920;
            listX[i][j]->size_y = 1080;
            listX[i][j]->chroma_format_idc = 1;
            listX[i][j]->frame_mbs_only_flag = 1;
        }
    }

    for (int i = num_lists; i < 6; i++) {
        listXsize[i] = 0;
        listX[i] = NULL;
    }

    j = 0;
    diff = 0;
}