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
    
    // Set picture dimensions to ensure sufficient data size (~16MB for mv arrays)
    int width  = 128;  // Must be divisible by 16 -> 8 macroblocks
    int height = 128;  // Must be divisible by 8 -> 16 rows of 8-pixel blocks

    fs->frame = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    fs->top_field = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    fs->bottom_field = (StorablePicture*)calloc(1, sizeof(StorablePicture));

    fs->frame->size_x = width;
    fs->frame->size_y = height;
    fs->frame->MbaffFrameFlag = 1;
    fs->frame->frame_mbs_only_flag = 0;

    fs->top_field->size_x = width;
    fs->top_field->size_y = height / 2;
    fs->bottom_field->size_x = width;
    fs->bottom_field->size_y = height / 2;

    // Allocate mb_field: one byte per macroblock (16x16 block), so size_x/16 * size_y/16
    int num_mb_x = width / 16;
    int num_mb_y = height / 16;
    fs->frame->mb_field = (byte*)calloc(num_mb_x * num_mb_y, sizeof(byte));

    // Allocate field_frame: pointer array for each row, then data
    fs->frame->field_frame = (byte**)calloc(width, sizeof(byte*));
    for (int x = 0; x < width; x++) {
        fs->frame->field_frame[x] = (byte*)calloc(height, sizeof(byte));
    }

    fs->top_field->field_frame = (byte**)calloc(width, sizeof(byte*));
    for (int x = 0; x < width; x++) {
        fs->top_field->field_frame[x] = (byte*)calloc(height / 2, sizeof(byte));
    }

    fs->bottom_field->field_frame = (byte**)calloc(width, sizeof(byte*));
    for (int x = 0; x < width; x++) {
        fs->bottom_field->field_frame[x] = (byte*)calloc(height / 2, sizeof(byte));
    }

    // Allocate mv: [2][width][height][2]
    fs->frame->mv = (short****)calloc(2, sizeof(short***));
    for (int l = 0; l < 2; l++) {
        fs->frame->mv[l] = (short***)calloc(width, sizeof(short**));
        for (int x = 0; x < width; x++) {
            fs->frame->mv[l][x] = (short**)calloc(height, sizeof(short*));
            for (int y = 0; y < height; y++) {
                fs->frame->mv[l][x][y] = (short*)calloc(2, sizeof(short));
                fs->frame->mv[l][x][y][0] = (short)(x + y);
                fs->frame->mv[l][x][y][1] = (short)(x - y);
            }
        }
    }

    // Allocate ref_idx: [2][width][height]
    fs->frame->ref_idx = (short***)calloc(2, sizeof(short**));
    for (int l = 0; l < 2; l++) {
        fs->frame->ref_idx[l] = (short**)calloc(width, sizeof(short*));
        for (int x = 0; x < width; x++) {
            fs->frame->ref_idx[l][x] = (short*)calloc(height, sizeof(short));
            for (int y = 0; y < height; y++) {
                fs->frame->ref_idx[l][x][y] = (x + y) % 32; // valid index or -1
            }
        }
    }

    // Initialize ref_pic_num tables
    for (int l = 0; l < 2; l++) {
        for (int idx = 0; idx < 33; idx++) {
            fs->frame->top_ref_pic_num[l][idx] = idx * 2;
            fs->frame->bottom_ref_pic_num[l][idx] = idx * 2 + 1;
        }
    }

    // Allocate top_field and bottom_field mv arrays: [2][width][height/2][2]
    for (int l = 0; l < 2; l++) {
        fs->top_field->mv = (short****)calloc(2, sizeof(short***));
        fs->bottom_field->mv = (short****)calloc(2, sizeof(short***));
        for (int ll = 0; ll < 2; ll++) {
            fs->top_field->mv[ll] = (short***)calloc(width, sizeof(short**));
            fs->bottom_field->mv[ll] = (short***)calloc(width, sizeof(short**));
            for (int x = 0; x < width; x++) {
                fs->top_field->mv[ll][x] = (short**)calloc(height / 2, sizeof(short*));
                fs->bottom_field->mv[ll][x] = (short**)calloc(height / 2, sizeof(short*));
                for (int y = 0; y < height / 2; y++) {
                    fs->top_field->mv[ll][x][y] = (short*)calloc(2, sizeof(short));
                    fs->bottom_field->mv[ll][x][y] = (short*)calloc(2, sizeof(short));
                }
            }
        }
    }

    // Allocate ref_idx for top and bottom fields: [2][width][height/2]
    fs->top_field->ref_idx = (short***)calloc(2, sizeof(short**));
    fs->bottom_field->ref_idx = (short***)calloc(2, sizeof(short**));
    for (int l = 0; l < 2; l++) {
        fs->top_field->ref_idx[l] = (short**)calloc(width, sizeof(short*));
        fs->bottom_field->ref_idx[l] = (short**)calloc(width, sizeof(short*));
        for (int x = 0; x < width; x++) {
            fs->top_field->ref_idx[l][x] = (short*)calloc(height / 2, sizeof(short));
            fs->bottom_field->ref_idx[l][x] = (short*)calloc(height / 2, sizeof(short));
        }
    }

    // Allocate ref_id for top and bottom fields: [2][width][height/2]
    fs->top_field->ref_id = (int64***)calloc(2, sizeof(int64**));
    fs->bottom_field->ref_id = (int64***)calloc(2, sizeof(int64**));
    for (int l = 0; l < 2; l++) {
        fs->top_field->ref_id[l] = (int64**)calloc(width, sizeof(int64*));
        fs->bottom_field->ref_id[l] = (int64**)calloc(width, sizeof(int64*));
        for (int x = 0; x < width; x++) {
            fs->top_field->ref_id[l][x] = (int64*)calloc(height / 2, sizeof(int64));
            fs->bottom_field->ref_id[l][x] = (int64*)calloc(height / 2, sizeof(int64));
        }
    }

    // Link bidirectional
    fs->frame->top_field = fs->top_field;
    fs->frame->bottom_field = fs->bottom_field;
    fs->frame->frame = fs->frame;
    fs->top_field->frame = fs->frame;
    fs->bottom_field->frame = fs->frame;
}