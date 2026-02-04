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

StorablePicture *p;
int i;
int j;
int dummylist0;
int dummylist1;

void init_vars() {
    p = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    
    // Set image dimensions to ensure loop runs with sufficient workload
    // Each iteration processes 4x4 block, so total pixels ~ (size_x * size_y)
    // We aim for ~64MB of working data: let's set size_x = 4096, size_y = 4096
    p->size_x = 4096;
    p->size_y = 4096;

    // Allocate ref_idx[2][i][j] where i = size_x/4, j = size_y/4
    int dim_i = p->size_x / 4;
    int dim_j = p->size_y / 4;
    
    p->ref_idx = (short***)calloc(2, sizeof(short**));
    for (int idx = 0; idx < 2; idx++) {
        p->ref_idx[idx] = (short**)calloc(dim_i, sizeof(short*));
        for (int i_idx = 0; i_idx < dim_i; i_idx++) {
            p->ref_idx[idx][i_idx] = (short*)calloc(dim_j, sizeof(short));
            for (int j_idx = 0; j_idx < dim_j; j_idx++) {
                // Random valid index: 0-32 or -1
                p->ref_idx[idx][i_idx][j_idx] = (rand() % 35) - 1; // -1 to 33
            }
        }
    }

    // Initialize ref_pic_num with dummy values
    for (int list = 0; list < 6; list++) {
        for (int idx = 0; idx < 33; idx++) {
            p->ref_pic_num[list][idx] = rand() % 1000;
        }
    }

    // Allocate ref_id[2][i][j]
    p->ref_id = (int64***)calloc(2, sizeof(int64**));
    for (int idx = 0; idx < 2; idx++) {
        p->ref_id[idx] = (int64**)calloc(dim_i, sizeof(int64*));
        for (int i_idx = 0; i_idx < dim_i; i_idx++) {
            p->ref_id[idx][i_idx] = (int64*)calloc(dim_j, sizeof(int64));
        }
    }

    // Allocate field_frame[i][j]
    p->field_frame = (byte**)calloc(dim_i, sizeof(byte*));
    for (int i_idx = 0; i_idx < dim_i; i_idx++) {
        p->field_frame[i_idx] = (byte*)calloc(dim_j, sizeof(byte));
    }
}