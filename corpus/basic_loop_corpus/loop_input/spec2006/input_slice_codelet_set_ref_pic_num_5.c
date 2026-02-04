#include <stdio.h>
#include <stdlib.h>
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

StorablePicture *enc_picture;

int listXsize[6];
StorablePicture **listX[6];

int i;
int j;

void init_vars() {
    enc_picture = (StorablePicture *)calloc(1, sizeof(StorablePicture));
    if (!enc_picture) exit(1);

    const int total_size = 1024 * 1024 * 8; // ~8MB of data
    const int avg_pic_size = 128;
    const int num_pics_per_list = total_size / (6 * avg_pic_size);
    
    for (int idx = 0; idx < 6; idx++) {
        if (idx < 2) {
            listXsize[idx] = 0;
            listX[idx] = NULL;
        } else {
            listXsize[idx] = (num_pics_per_list / 4) + 1;
            listX[idx] = (StorablePicture **)calloc(listXsize[idx], sizeof(StorablePicture *));
            if (!listX[idx]) exit(1);
            
            for (int k = 0; k < listXsize[idx]; k++) {
                listX[idx][k] = (StorablePicture *)calloc(1, sizeof(StorablePicture));
                if (!listX[idx][k]) exit(1);
                
                listX[idx][k]->poc = k + 1;
                listX[idx][k]->frame_poc = k * 2;
                listX[idx][k]->top_poc = k * 2;
                listX[idx][k]->bottom_poc = k * 2 + 1;
                listX[idx][k]->structure = (k % 3 == 0) ? BOTTOM_FIELD : FRAME;
            }
        }
    }

    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 33; b++) {
            enc_picture->ref_pic_num[a][b] = 0;
            enc_picture->frm_ref_pic_num[a][b] = 0;
            enc_picture->top_ref_pic_num[a][b] = 0;
            enc_picture->bottom_ref_pic_num[a][b] = 0;
        }
    }
}