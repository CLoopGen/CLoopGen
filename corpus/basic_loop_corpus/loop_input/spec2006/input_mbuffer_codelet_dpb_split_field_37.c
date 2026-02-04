#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

typedef struct frame_store {
    int is_used;
    int is_reference;
    int is_long_term;
    int is_orig_reference;
    int is_non_existent;
    unsigned int frame_num;
    int frame_num_wrap;
    int long_term_frame_idx;
    int is_output;
    int poc;
    StorablePicture *frame;
    StorablePicture *top_field;
    StorablePicture *bottom_field;
} FrameStore;

FrameStore *fs;
int i;
int j;
int dummylist0;
int dummylist1;

void init_vars() {
    fs = (FrameStore*)calloc(1, sizeof(FrameStore));
    StorablePicture *frame = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    fs->frame = frame;

    frame->size_x = 176;  
    frame->size_y = 144;
    frame->MbaffFrameFlag = 1;

    int width_in_mbs = frame->size_x / 16;
    int height_in_mbs = frame->size_y / 16;
    int num_mbs = width_in_mbs * height_in_mbs;

    frame->mb_field = (byte*)calloc(num_mbs, sizeof(byte));
    for (int mb = 0; mb < num_mbs; mb++) {
        frame->mb_field[mb] = (mb % 2);
    }

    int num_blocks_x = frame->size_x / 4;
    int num_blocks_y = frame->size_y / 4;

    frame->ref_idx = (short***)calloc(2, sizeof(short**));
    frame->ref_pic_id = (int64***)calloc(2, sizeof(int64**));
    frame->ref_id = (int64***)calloc(6, sizeof(int64**));

    for (int list = 0; list < 2; list++) {
        frame->ref_idx[list] = (short**)calloc(num_blocks_x, sizeof(short*));
        frame->ref_pic_id[list] = (int64**)calloc(num_blocks_x, sizeof(int64*));
        frame->ref_id[list] = (int64**)calloc(num_blocks_x, sizeof(int64*));
        for (int x = 0; x < num_blocks_x; x++) {
            frame->ref_idx[list][x] = (short*)calloc(num_blocks_y, sizeof(short));
            frame->ref_pic_id[list][x] = (int64*)calloc(num_blocks_y, sizeof(int64));
            frame->ref_id[list][x] = (int64*)calloc(num_blocks_y, sizeof(int64));
            for (int y = 0; y < num_blocks_y; y++) {
                frame->ref_idx[list][x][y] = (x + y) % 33;
            }
        }
    }

    for (int list = 2; list < 6; list++) {
        frame->ref_id[list] = (int64**)calloc(num_blocks_x, sizeof(int64*));
        for (int x = 0; x < num_blocks_x; x++) {
            frame->ref_id[list][x] = (int64*)calloc(num_blocks_y, sizeof(int64));
        }
    }

    for (int list = 0; list < 6; list++) {
        for (int idx = 0; idx < 33; idx++) {
            frame->ref_pic_num[list][idx] = (int64)(list * 1000 + idx);
            frame->frm_ref_pic_num[list][idx] = (int64)(list * 1000 + idx + 1);
        }
    }

    frame->top_field = NULL;
    frame->bottom_field = NULL;
    frame->frame = NULL;
}