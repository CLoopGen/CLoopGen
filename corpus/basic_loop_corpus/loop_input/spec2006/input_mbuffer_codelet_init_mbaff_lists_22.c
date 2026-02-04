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

StorablePicture* listX0[64];
StorablePicture* listX1[64];
StorablePicture* listX2[128];
StorablePicture* listX3[128];
StorablePicture* listX4[128];
StorablePicture* listX5[128];

StorablePicture** listX[6] = { listX0, listX1, listX2, listX3, listX4, listX5 };
int listXsize[6] = { 0, 64, 0, 128, 0, 128 };

StorablePicture pictures[64];
StorablePicture field_pairs[128];

int i;

void init_vars() {
    for (int j = 0; j < 64; j++) {
        pictures[j].structure = FRAME;
        pictures[j].poc = j;
        pictures[j].top_poc = j * 2;
        pictures[j].bottom_poc = j * 2 + 1;
        pictures[j].frame_poc = j;
        pictures[j].order_num = j;
        pictures[j].frame_num = j % 32;
        pictures[j].pic_num = j;
        pictures[j].long_term_pic_num = -1;
        pictures[j].long_term_frame_idx = -1;
        pictures[j].is_long_term = 0;
        pictures[j].used_for_reference = 1;
        pictures[j].is_output = 1;
        pictures[j].non_existing = 0;
        pictures[j].size_x = 1920;
        pictures[j].size_y = 1080;
        pictures[j].size_x_cr = 960;
        pictures[j].size_y_cr = 540;
        pictures[j].chroma_vector_adjustment = 0;
        pictures[j].coded_frame = 1;
        pictures[j].MbaffFrameFlag = 0;
        pictures[j].chroma_format_idc = 1;
        pictures[j].frame_mbs_only_flag = 1;
        pictures[j].frame_cropping_flag = 1;
        pictures[j].frame_cropping_rect_left_offset = 0;
        pictures[j].frame_cropping_rect_right_offset = 0;
        pictures[j].frame_cropping_rect_top_offset = 0;
        pictures[j].frame_cropping_rect_bottom_offset = 0;

        pictures[j].imgY = NULL;
        pictures[j].imgY_11 = NULL;
        pictures[j].imgY_11_w = NULL;
        pictures[j].imgY_ups = NULL;
        pictures[j].imgY_ups_w = NULL;
        pictures[j].imgUV = NULL;
        pictures[j].mb_field = NULL;
        pictures[j].ref_idx = NULL;
        pictures[j].ref_pic_id = NULL;
        pictures[j].ref_id = NULL;
        pictures[j].mv = NULL;
        pictures[j].moving_block = NULL;
        pictures[j].field_frame = NULL;
        pictures[j].frame = &pictures[j];

        field_pairs[2*j].structure = TOP_FIELD;
        field_pairs[2*j].poc = j * 2;
        field_pairs[2*j].top_poc = j * 2;
        field_pairs[2*j].bottom_poc = j * 2 + 1;
        field_pairs[2*j].frame_poc = j;
        field_pairs[2*j].order_num = j * 2;
        field_pairs[2*j].frame = &pictures[j];
        field_pairs[2*j].bottom_field = &field_pairs[2*j + 1];
        field_pairs[2*j].top_field = &field_pairs[2*j];

        field_pairs[2*j+1].structure = BOTTOM_FIELD;
        field_pairs[2*j+1].poc = j * 2 + 1;
        field_pairs[2*j+1].top_poc = j * 2;
        field_pairs[2*j+1].bottom_poc = j * 2 + 1;
        field_pairs[2*j+1].frame_poc = j;
        field_pairs[2*j+1].order_num = j * 2 + 1;
        field_pairs[2*j+1].frame = &pictures[j];
        field_pairs[2*j+1].top_field = &field_pairs[2*j];
        field_pairs[2*j+1].bottom_field = &field_pairs[2*j+1];

        pictures[j].top_field = &field_pairs[2*j];
        pictures[j].bottom_field = &field_pairs[2*j+1];

        listX1[j] = &pictures[j];
    }

    for (int j = 0; j < 128; j++) {
        listX3[j] = NULL;
        listX5[j] = NULL;
    }

    listXsize[1] = 64;
    listXsize[3] = 128;
    listXsize[5] = 128;
}