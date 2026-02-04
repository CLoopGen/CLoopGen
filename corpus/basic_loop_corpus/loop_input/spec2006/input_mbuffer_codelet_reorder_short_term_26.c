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

StorablePicture **RefPicListX;
int num_ref_idx_lX_active_minus1;
int picNumLX;
int *refIdxLX;
int cIdx;
int nIdx;

#define NUM_REF_PICS 256

void init_vars() {
    RefPicListX = (StorablePicture**)calloc(NUM_REF_PICS, sizeof(StorablePicture*));
    
    for (int i = 0; i < NUM_REF_PICS; i++) {
        RefPicListX[i] = (StorablePicture*)calloc(1, sizeof(StorablePicture));
        RefPicListX[i]->is_long_term = (i % 7 == 0); // every 7th picture is long-term
        RefPicListX[i]->pic_num = (i % 64);         // pic_num wraps every 64
    }
    
    num_ref_idx_lX_active_minus1 = 255;
    picNumLX = 42;
    
    refIdxLX = (int*)malloc(sizeof(int));
    *refIdxLX = 0;
    
    cIdx = 0;
    nIdx = 0;
}