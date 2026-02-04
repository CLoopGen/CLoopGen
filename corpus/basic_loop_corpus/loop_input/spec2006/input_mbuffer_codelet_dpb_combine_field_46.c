#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    
    // Allocate top_field and initialize sizes
    StorablePicture *top_field = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    top_field->size_x = 1024;  // Must be divisible by 4
    top_field->size_y = 576;   // Must be divisible by 4
    top_field->structure = TOP_FIELD;
    
    // Allocate bottom_field
    StorablePicture *bottom_field = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    bottom_field->size_x = top_field->size_x;
    bottom_field->size_y = top_field->size_y;
    bottom_field->structure = BOTTOM_FIELD;
    
    // Allocate frame
    StorablePicture *frame = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    frame->size_x = top_field->size_x;
    frame->size_y = top_field->size_y * 2;
    frame->structure = FRAME;
    
    // Set up pointers in fs
    fs->top_field = top_field;
    fs->bottom_field = bottom_field;
    fs->frame = frame;
    
    // Allocate field_frame for frame: [size_x/4][size_y*2] -> but we access up to 8*(j/4)+(j%4)+4
    frame->field_frame = (byte**)calloc(frame->size_x / 4, sizeof(byte*));
    for (int idx = 0; idx < frame->size_x / 4; idx++) {
        frame->field_frame[idx] = (byte*)calloc(frame->size_y + 8, sizeof(byte)); // extra padding
    }
    
    // Allocate mv arrays: [2][size_x/4][size_y*2][2]
    frame->mv = (short****)calloc(2, sizeof(short***));
    for (int a = 0; a < 2; a++) {
        frame->mv[a] = (short***)calloc(frame->size_x / 4, sizeof(short**));
        for (int b = 0; b < frame->size_x / 4; b++) {
            frame->mv[a][b] = (short**)calloc(frame->size_y + 8, sizeof(short*));
            for (int c = 0; c < frame->size_y + 8; c++) {
                frame->mv[a][b][c] = (short*)calloc(2, sizeof(short));
            }
        }
    }
    
    // Allocate ref_idx: [2][size_x/4][size_y*2]
    frame->ref_idx = (short***)calloc(2, sizeof(short**));
    for (int a = 0; a < 2; a++) {
        frame->ref_idx[a] = (short**)calloc(frame->size_x / 4, sizeof(short*));
        for (int b = 0; b < frame->size_x / 4; b++) {
            frame->ref_idx[a][b] = (short*)calloc(frame->size_y + 8, sizeof(short));
        }
    }
    
    // Allocate ref_id: [2][size_x/4][size_y*2]
    frame->ref_id = (int64***)calloc(2, sizeof(int64**));
    for (int a = 0; a < 2; a++) {
        frame->ref_id[a] = (int64**)calloc(frame->size_x / 4, sizeof(int64*));
        for (int b = 0; b < frame->size_x / 4; b++) {
            frame->ref_id[a][b] = (int64*)calloc(frame->size_y + 8, sizeof(int64));
        }
    }
    
    // Setup top_field arrays: mv[2][size_x/4][size_y][2], ref_idx[2][size_x/4][size_y], ref_id[2][size_x/4][size_y]
    top_field->mv = (short****)calloc(2, sizeof(short***));
    top_field->ref_idx = (short***)calloc(2, sizeof(short**));
    top_field->ref_id = (int64***)calloc(2, sizeof(int64**));
    
    for (int a = 0; a < 2; a++) {
        top_field->mv[a] = (short***)calloc(top_field->size_x / 4, sizeof(short**));
        top_field->ref_idx[a] = (short**)calloc(top_field->size_x / 4, sizeof(short*));
        top_field->ref_id[a] = (int64**)calloc(top_field->size_x / 4, sizeof(int64*));
        
        for (int b = 0; b < top_field->size_x / 4; b++) {
            top_field->mv[a][b] = (short**)calloc(top_field->size_y, sizeof(short*));
            top_field->ref_idx[a][b] = (short*)calloc(top_field->size_y, sizeof(short));
            top_field->ref_id[a][b] = (int64*)calloc(top_field->size_y, sizeof(int64));
            
            for (int c = 0; c < top_field->size_y; c++) {
                top_field->mv[a][b][c] = (short*)calloc(2, sizeof(short));
                top_field->mv[a][b][c][0] = (short)(a * 1000 + b * 10 + c);
                top_field->mv[a][b][c][1] = (short)(a * 2000 + b * 20 + c);
            }
        }
    }
    
    // Similarly for bottom_field
    bottom_field->mv = (short****)calloc(2, sizeof(short***));
    bottom_field->ref_idx = (short***)calloc(2, sizeof(short**));
    bottom_field->ref_id = (int64***)calloc(2, sizeof(int64**));
    
    for (int a = 0; a < 2; a++) {
        bottom_field->mv[a] = (short***)calloc(bottom_field->size_x / 4, sizeof(short**));
        bottom_field->ref_idx[a] = (short**)calloc(bottom_field->size_x / 4, sizeof(short*));
        bottom_field->ref_id[a] = (int64**)calloc(bottom_field->size_x / 4, sizeof(int64*));
        
        for (int b = 0; b < bottom_field->size_x / 4; b++) {
            bottom_field->mv[a][b] = (short**)calloc(bottom_field->size_y, sizeof(short*));
            bottom_field->ref_idx[a][b] = (short*)calloc(bottom_field->size_y, sizeof(short));
            bottom_field->ref_id[a][b] = (int64*)calloc(bottom_field->size_y, sizeof(int64));
            
            for (int c = 0; c < bottom_field->size_y; c++) {
                bottom_field->mv[a][b][c] = (short*)calloc(2, sizeof(short));
                bottom_field->mv[a][b][c][0] = (short)(a * 1000 + b * 10 + c + 1);
                bottom_field->mv[a][b][c][1] = (short)(a * 2000 + b * 20 + c + 1);
            }
        }
    }
    
    // Initialize ref_pic_num and frm_ref_pic_num for both fields
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 33; b++) {
            top_field->ref_pic_num[a][b] = (int64)(a * 1000000L + b);
            top_field->frm_ref_pic_num[a][b] = (int64)(a * 2000000L + b);
            bottom_field->ref_pic_num[a][b] = (int64)(a * 1000000L + b + 1);
            bottom_field->frm_ref_pic_num[a][b] = (int64)(a * 2000000L + b + 1);
        }
    }
}