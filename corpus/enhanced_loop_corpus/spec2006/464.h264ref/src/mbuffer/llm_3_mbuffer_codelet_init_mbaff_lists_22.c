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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Instead of sequential index progression, access with a fixed stride
    // Here we simulate a strided traversal by processing every second element in two passes.
    // This changes access pattern from sequential to strided (stride of 2).
    int size = listXsize[1];
    int double_size = 2 * size;

    // First pass: even indices (stride 2)
    for (i = 0; i < double_size; i += 2) {
        int src_idx = i / 2;
        if (src_idx >= size) break;

        listX[3][i] = listX[1][src_idx]->top_field;
        listX[5][i] = listX[1][src_idx]->bottom_field;
    }

    // Second pass: odd indices (stride 2 starting at 1)
    for (i = 1; i < double_size; i += 2) {
        int src_idx = i / 2;
        if (src_idx >= size) break;

        listX[3][i] = listX[1][src_idx]->bottom_field;
        listX[5][i] = listX[1][src_idx]->top_field;
    }
}
