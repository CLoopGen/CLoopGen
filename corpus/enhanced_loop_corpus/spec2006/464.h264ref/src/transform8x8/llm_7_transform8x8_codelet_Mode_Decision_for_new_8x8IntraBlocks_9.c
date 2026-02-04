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

extern StorablePicture *enc_picture;
extern int i;
extern int x;
extern int y;
extern int block4x4_x;
extern int block4x4_y;
extern int pic_pix_x;
extern int pic_pix_y;
extern int b4;
extern int rec8x8_c[2][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_ref_id[2][33];
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 33; c++) {
            local_ref_id[r][c] = enc_picture->ref_pic_num[r][c];
        }
    }
    for (b4 = 0; b4 < 4; b4++) {
        block4x4_x = 4 * (b4 % 2);
        block4x4_y = 4 * (b4 / 2);
        for (i = 0; i < 2; i++) {
            int offset_x = pic_pix_x + block4x4_x;
            int offset_y = pic_pix_y + block4x4_y;
            for (y = 0; y < 4; y++) {
                int idx_y = offset_y + y;
                for (x = 0; x < 4; x++) {
                    int idx_x = offset_x + x;
                    enc_picture->imgUV[i][idx_y][idx_x] = rec8x8_c[i][b4][y][x];
                }
            }
        }
        for (int c = 0; c < 33; c++) {
            enc_picture->ref_pic_num[0][c] = local_ref_id[0][c] ^ ((int64_t)b4 << 32); 
            enc_picture->ref_pic_num[1][c] = local_ref_id[1][c] ^ ((int64_t)b4 << 32);
        }
    }
}
