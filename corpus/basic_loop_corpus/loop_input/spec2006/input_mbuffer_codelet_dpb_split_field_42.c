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
int i, j;

static void init_array_2d_byte(byte ***arr, int dim1, int dim2) {
    *arr = (byte**)calloc(dim1, sizeof(byte*));
    for (int i = 0; i < dim1; i++) {
        (*arr)[i] = (byte*)calloc(dim2, sizeof(byte));
    }
}

static void init_array_2d_short(short ***arr, int dim1, int dim2) {
    *arr = (short**)calloc(dim1, sizeof(short*));
    for (int i = 0; i < dim1; i++) {
        (*arr)[i] = (short*)calloc(dim2, sizeof(short));
    }
}

static void init_array_3d_short(short ****arr, int dim1, int dim2, int dim3) {
    *arr = (short***)calloc(dim1, sizeof(short**));
    for (int i = 0; i < dim1; i++) {
        (*arr)[i] = (short**)calloc(dim2, sizeof(short*));
        for (int j = 0; j < dim2; j++) {
            (*arr)[i][j] = (short*)calloc(dim3, sizeof(short));
        }
    }
}

static void init_array_4d_short(short *****arr, int dim1, int dim2, int dim3, int dim4) {
    *arr = (short****)calloc(dim1, sizeof(short***));
    for (int i = 0; i < dim1; i++) {
        (*arr)[i] = (short***)calloc(dim2, sizeof(short**));
        for (int j = 0; j < dim2; j++) {
            (*arr)[i][j] = (short**)calloc(dim3, sizeof(short*));
            for (int k = 0; k < dim3; k++) {
                (*arr)[i][j][k] = (short*)calloc(dim4, sizeof(short));
            }
        }
    }
}

static void init_array_3d_int64(int64 ****arr, int dim1, int dim2, int dim3) {
    *arr = (int64***)calloc(dim1, sizeof(int64**));
    for (int i = 0; i < dim1; i++) {
        (*arr)[i] = (int64**)calloc(dim2, sizeof(int64*));
        for (int j = 0; j < dim2; j++) {
            (*arr)[i][j] = (int64*)calloc(dim3, sizeof(int64));
        }
    }
}

void init_vars() {
    fs = (FrameStore*)calloc(1, sizeof(FrameStore));
    
    // Allocate frame picture
    StorablePicture *frame_pic = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    StorablePicture *top_field_pic = (StorablePicture*)calloc(1, sizeof(StorablePicture));
    StorablePicture *bottom_field_pic = (StorablePicture*)calloc(1, sizeof(StorablePicture));

    // Set sizes to achieve ~10ms runtime: aim for moderate loop iterations (~100K)
    // i < size_x / 4, j < size_y / 8 => total iterations ~ (size_x/4) * (size_y/8)
    // Set size_x = 512, size_y = 512 -> iterations = 128 * 64 = 8192, which is safe and fast
    frame_pic->size_x = 512;
    frame_pic->size_y = 512;
    frame_pic->MbaffFrameFlag = 1;

    // Allocate field_frame arrays: [size_x/4][size_y/8]
    int field_width = frame_pic->size_x / 4;
    int field_height = frame_pic->size_y / 8;

    init_array_2d_byte(&frame_pic->field_frame, field_width, 2 * field_height);
    init_array_2d_byte(&top_field_pic->field_frame, field_width, field_height);
    init_array_2d_byte(&bottom_field_pic->field_frame, field_width, field_height);

    // Allocate mb_field: one entry per macroblock in frame
    int mb_width = frame_pic->size_x / 16;
    int mb_height = frame_pic->size_y / 16;
    frame_pic->mb_field = (byte*)calloc(mb_width * mb_height, sizeof(byte));
    // Set some blocks as field-coded
    for (int idx = 0; idx < mb_width * mb_height; idx += 2) {
        frame_pic->mb_field[idx] = 1;
    }

    // Allocate mv arrays: [2][field_width][field_height][2]
    init_array_4d_short(&frame_pic->mv, 2, field_width, 2 * field_height, 2);
    init_array_4d_short(&top_field_pic->mv, 2, field_width, field_height, 2);
    init_array_4d_short(&bottom_field_pic->mv, 2, field_width, field_height, 2);

    // Allocate ref_idx: [2][field_width][field_height]
    init_array_3d_short(&frame_pic->ref_idx, 2, field_width, 2 * field_height);
    init_array_3d_short(&top_field_pic->ref_idx, 2, field_width, field_height);
    init_array_3d_short(&bottom_field_pic->ref_idx, 2, field_width, field_height);

    // Allocate ref_id: [6][field_width][field_height] - we only access up to index 5
    init_array_3d_int64(&frame_pic->ref_id, 6, field_width, 2 * field_height);
    init_array_3d_int64(&top_field_pic->ref_id, 2, field_width, field_height);
    init_array_3d_int64(&bottom_field_pic->ref_id, 2, field_width, field_height);

    // Link structures
    fs->frame = frame_pic;
    fs->top_field = top_field_pic;
    fs->bottom_field = bottom_field_pic;

    frame_pic->top_field = top_field_pic;
    frame_pic->bottom_field = bottom_field_pic;
    frame_pic->frame = frame_pic;

    top_field_pic->frame = frame_pic;
    bottom_field_pic->frame = frame_pic;
}