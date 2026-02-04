#include <stdio.h>

#include <inttypes.h>

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

extern StorablePicture **listX[6];
extern int listXsize[6];
extern StorablePicture *enc_picture;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase computational intensity with additional arithmetic and memory accesses
    for (i = 0; i < listXsize[1]; i++) {
        StorablePicture *pic = listX[1][i];
        int base_offset = pic->poc * 2;
        int field_offset = (pic->structure == BOTTOM_FIELD) ? 1 : 0;

        // Add redundant but computationally heavier transformations
        enc_picture->ref_pic_num[1][i] = base_offset + field_offset;
        enc_picture->frm_ref_pic_num[1][i] = (pic->frame_poc << 1) ^ (pic->frame_num & 1); // Use bit shift and XOR
        enc_picture->top_ref_pic_num[1][i] = (pic->top_poc * 3) - pic->top_poc; // Equivalent to *2, more ops
        enc_picture->bottom_ref_pic_num[1][i] = (pic->bottom_poc << 1) | 1; // Use shift and bitwise OR instead of +1

        // Introduce auxiliary computation to increase intensity without changing logic
        int64 temp = enc_picture->frm_ref_pic_num[1][i];
        temp += (temp >> 31); // Dummy operation, increases ALU usage
        enc_picture->frm_ref_pic_num[1][i] = temp;
    }
}
