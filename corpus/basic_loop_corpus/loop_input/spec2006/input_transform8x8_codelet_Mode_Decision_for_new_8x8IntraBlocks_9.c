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

StorablePicture *enc_picture;
int i;
int x;
int y;
int block4x4_x;
int block4x4_y;
int pic_pix_x = 0;
int pic_pix_y = 0;
int b4;
int rec8x8_c[2][4][4][4];

void init_vars() {
    enc_picture = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    if (!enc_picture) exit(1);

    enc_picture->chroma_format_idc = 1;
    enc_picture->size_x = 1920;
    enc_picture->size_y = 1080;
    enc_picture->size_x_cr = enc_picture->size_x >> (enc_picture->chroma_format_idc == 1);
    enc_picture->size_y_cr = enc_picture->size_y >> (enc_picture->chroma_format_idc == 1);
    enc_picture->imgUV = (unsigned short***)calloc(2, sizeof(unsigned short**));
    if (!enc_picture->imgUV) exit(1);

    for (int c = 0; c < 2; c++) {
        enc_picture->imgUV[c] = (unsigned short**)calloc(enc_picture->size_y_cr, sizeof(unsigned short*));
        if (!enc_picture->imgUV[c]) exit(1);
        for (int row = 0; row < enc_picture->size_y_cr; row++) {
            enc_picture->imgUV[c][row] = (unsigned short*)calloc(enc_picture->size_x_cr, sizeof(unsigned short));
            if (!enc_picture->imgUV[c][row]) exit(1);
        }
    }

    pic_pix_x = 0;
    pic_pix_y = 0;

    for (int c = 0; c < 2; c++)
        for (int b = 0; b < 4; b++)
            for (int yy = 0; yy < 4; yy++)
                for (int xx = 0; xx < 4; xx++)
                    rec8x8_c[c][b][yy][xx] = (c + b + yy + xx) % 256;
}