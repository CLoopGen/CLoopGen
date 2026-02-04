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



void loop(){
    // Eliminate loop-carried dependencies by unrolling and reordering independent computations
    for (j = -4; j < s->size_y + 4; j += 2) {  // Stride-2 outer loop to break sequential dependency
        for (i = -4; i < s->size_x + 4; i += 2) {
            int jj1, jj2, is1, is2;
            // First block: process (j, i) and (j, i+1)
            jj1 = ((0 > ((s->size_y - 1) < j ? s->size_y - 1 : j)) ? 0 : ((s->size_y - 1) < j ? s->size_y - 1 : j));
            is1 = ONE_FOURTH_TAP[0][0] * (
                imgY[jj1][((0 > ((s->size_x - 1) < i ? s->size_x - 1 : i)) ? 0 : ((s->size_x - 1) < i ? s->size_x - 1 : i))] +
                imgY[jj1][((0 > ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1))) ? 0 : ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1)))]
            ) + ONE_FOURTH_TAP[1][0] * (
                imgY[jj1][((0 > ((s->size_x - 1) < (i - 1) ? s->size_x - 1 : (i - 1))) ? 0 : ((s->size_x - 1) < (i - 1) ? s->size_x - 1 : (i - 1)))] +
                imgY[jj1][((0 > ((s->size_x - 1) < (i + 2) ? s->size_x - 1 : (i + 2))) ? 0 : ((s->size_x - 1) < (i + 2) ? s->size_x - 1 : (i + 2)))]
            ) + ONE_FOURTH_TAP[2][0] * (
                imgY[jj1][((0 > ((s->size_x - 1) < (i - 2) ? s->size_x - 1 : (i - 2))) ? 0 : ((s->size_x - 1) < (i - 2) ? s->size_x - 1 : (i - 2)))] +
                imgY[jj1][((0 > ((s->size_x - 1) < (i + 3) ? s->size_x - 1 : (i + 3))) ? 0 : ((s->size_x - 1) < (i + 3) ? s->size_x - 1 : (i + 3)))]
            );

            // Second block: (j+1, i), if within bounds
            if (j + 1 < s->size_y + 4) {
                jj2 = ((0 > ((s->size_y - 1) < (j + 1) ? s->size_y - 1 : (j + 1))) ? 0 : ((s->size_y - 1) < (j + 1) ? s->size_y - 1 : (j + 1)));
                is2 = ONE_FOURTH_TAP[0][0] * (
                    imgY[jj2][((0 > ((s->size_x - 1) < i ? s->size_x - 1 : i)) ? 0 : ((s->size_x - 1) < i ? s->size_x - 1 : i))] +
                    imgY[jj2][((0 > ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1))) ? 0 : ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1)))]
                ) + ONE_FOURTH_TAP[1][0] * (
                    imgY[jj2][((0 > ((s->size_x - 1) < (i - 1) ? s->size_x - 1 : (i - 1))) ? 0 : ((s->size_x - 1) < (i - 1) ? s->size_x - 1 : (i - 1)))] +
                    imgY[jj2][((0 > ((s->size_x - 1) < (i + 2) ? s->size_x - 1 : (i + 2))) ? 0 : ((s->size_x - 1) < (i + 2) ? s->size_x - 1 : (i + 2)))]
                ) + ONE_FOURTH_TAP[2][0] * (
                    imgY[jj2][((0 > ((s->size_x - 1) < (i - 2) ? s->size_x - 1 : (i - 2))) ? 0 : ((s->size_x - 1) < (i - 2) ? s->size_x - 1 : (i - 2)))] +
                    imgY[jj2][((0 > ((s->size_x - 1) < (i + 3) ? s->size_x - 1 : (i + 3))) ? 0 : ((s->size_x - 1) < (i + 3) ? s->size_x - 1 : (i + 3)))]
                );

                // Store both results independently — no loop-carried dependency
                img4Y_tmp[j + 1 + 4][(i + 4) * 2] = imgY[jj2][((0 > ((s->size_x - 1) < i ? s->size_x - 1 : i)) ? 0 : ((s->size_x - 1) < i ? s->size_x - 1 : i))] * 1024;
                img4Y_tmp[j + 1 + 4][(i + 4) * 2 + 1] = is2 * 32;
            }

            // Store first result
            img4Y_tmp[j + 4][(i + 4) * 2] = imgY[jj1][((0 > ((s->size_x - 1) < i ? s->size_x - 1 : i)) ? 0 : ((s->size_x - 1) < i ? s->size_x - 1 : i))] * 1024;
            img4Y_tmp[j + 4][(i + 4) * 2 + 1] = is1 * 32;

            // Duplicate for i+1 if valid
            if (i + 1 < s->size_x + 4) {
                img4Y_tmp[j + 4][(i + 1 + 4) * 2] = imgY[jj1][((0 > ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1))) ? 0 : ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1)))] * 1024;
                int is_next = ONE_FOURTH_TAP[0][0] * (
                    imgY[jj1][((0 > ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1))) ? 0 : ((s->size_x - 1) < (i + 1) ? s->size_x - 1 : (i + 1)))] +
                    imgY[jj1][((0 > ((s->size_x - 1) < (i + 2) ? s->size_x - 1 : (i + 2))) ? 0 : ((s->size_x - 1) < (i + 2) ? s->size_x - 1 : (i + 2)))]
                ) + ONE_FOURTH_TAP[1][0] * (
                    imgY[jj1][((0 > ((s->size_x - 1) < i ? s->size_x - 1 : i)) ? 0 : ((s->size_x - 1) < i ? s->size_x - 1 : i))] +
                    imgY[jj1][((0 > ((s->size_x - 1) < (i + 3) ? s->size_x - 1 : (i + 3))) ? 0 : ((s->size_x - 1) < (i + 3) ? s->size_x - 1 : (i + 3)))]
                ) + ONE_FOURTH_TAP[2][0] * (
                    imgY[jj1][((0 > ((s->size_x - 1) < (i - 1) ? s->size_x - 1 : (i - 1))) ? 0 : ((s->size_x - 1) < (i - 1) ? s->size_x - 1 : (i - 1)))] +
                    imgY[jj1][((0 > ((s->size_x - 1) < (i + 4) ? s->size_x - 1 : (i + 4))) ? 0 : ((s->size_x - 1) < (i + 4) ? s->size_x - 1 : (i + 4)))]
                );
                img4Y_tmp[j + 4][(i + 1 + 4) * 2 + 1] = is_next * 32;
            }
        }
    }
}
