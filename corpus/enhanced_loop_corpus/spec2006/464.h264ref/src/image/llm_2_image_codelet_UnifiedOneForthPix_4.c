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

extern int **img4Y_tmp;
extern  int ONE_FOURTH_TAP[3][2];
extern StorablePicture *s;
extern int is;
extern int i;
extern int j;
extern int jj;
extern unsigned short **imgY;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Precomputed Indices
    // Changed access pattern to improve spatial locality by precomputing clamped coordinates
    // and accessing imgY in a more cache-friendly manner. Also unrolled inner loop by 2x 
    // to promote consecutive writes to img4Y_tmp.

    int i_clamped, j_clamped;
    int *row_ptr;
    int offset;

    for (j = -4; j < s->size_y + 4; j++) {
        j_clamped = (j < 0) ? 0 : ((j >= s->size_y) ? s->size_y - 1 : j);
        row_ptr = img4Y_tmp[j + 4];
        for (i = -4; i < s->size_x + 4; i += 2) {  // Process two pixels at once
            // First pixel (i)
            i_clamped = (i < 0) ? 0 : ((i >= s->size_x) ? s->size_x - 1 : i);
            is = ONE_FOURTH_TAP[0][0] * (imgY[j_clamped][i_clamped] + 
                                        imgY[j_clamped][(i+1 < 0) ? 0 : ((i+1 >= s->size_x) ? s->size_x-1 : i+1)]) +
                 ONE_FOURTH_TAP[1][0] * (imgY[j_clamped][(i-1 < 0) ? 0 : ((i-1 >= s->size_x) ? s->size_x-1 : i-1)] + 
                                        imgY[j_clamped][(i+2 < 0) ? 0 : ((i+2 >= s->size_x) ? s->size_x-1 : i+2)]) +
                 ONE_FOURTH_TAP[2][0] * (imgY[j_clamped][(i-2 < 0) ? 0 : ((i-2 >= s->size_x) ? s->size_x-1 : i-2)] + 
                                        imgY[j_clamped][(i+3 < 0) ? 0 : ((i+3 >= s->size_x) ? s->size_x-1 : i+3)]);
            offset = (i + 4) * 2;
            row_ptr[offset]     = imgY[j_clamped][i_clamped] * 1024;
            row_ptr[offset + 1] = is * 32;

            // Second pixel (i+1), if within bounds
            if (i + 1 < s->size_x + 4) {
                i_clamped = (i+1 < 0) ? 0 : ((i+1 >= s->size_x) ? s->size_x - 1 : i+1);
                is = ONE_FOURTH_TAP[0][0] * (imgY[j_clamped][i_clamped] + 
                                            imgY[j_clamped][(i+2 < 0) ? 0 : ((i+2 >= s->size_x) ? s->size_x-1 : i+2)]) +
                     ONE_FOURTH_TAP[1][0] * (imgY[j_clamped][(i   < 0) ? 0 : ((i   >= s->size_x) ? s->size_x-1 : i  )] + 
                                            imgY[j_clamped][(i+3 < 0) ? 0 : ((i+3 >= s->size_x) ? s->size_x-1 : i+3)]) +
                     ONE_FOURTH_TAP[2][0] * (imgY[j_clamped][(i-1 < 0) ? 0 : ((i-1 >= s->size_x) ? s->size_x-1 : i-1)] + 
                                            imgY[j_clamped][(i+4 < 0) ? 0 : ((i+4 >= s->size_x) ? s->size_x-1 : i+4)]);
                offset = (i + 5) * 2;
                row_ptr[offset]     = imgY[j_clamped][i_clamped] * 1024;
                row_ptr[offset + 1] = is * 32;
            }
        }
    }
}
