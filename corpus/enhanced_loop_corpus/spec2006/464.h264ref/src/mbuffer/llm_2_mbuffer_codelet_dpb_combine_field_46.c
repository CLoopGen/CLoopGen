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

extern FrameStore *fs;
extern int i;
extern int j;
extern int dummylist0;
extern int dummylist1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Memory Access Pattern Modification - Use consecutive row-major traversal with precomputed indices to improve spatial locality
    int width = fs->top_field->size_x / 4;
    int height = fs->top_field->size_y / 4;

    for (int i_idx = 0; i_idx < width; i_idx++) {
        for (int j_idx = 0; j_idx < height; j_idx++) {
            int base_j_frame = 8 * (j_idx / 4) + (j_idx % 4);
            int top_mv_src_idx = j_idx;
            int bottom_mv_src_idx = j_idx;
            int frame_dst_idx_1 = base_j_frame;
            int frame_dst_idx_2 = base_j_frame + 4;

            // Assign field_frame consecutively in a cache-friendly manner
            fs->frame->field_frame[i_idx][frame_dst_idx_1] = 1;
            fs->frame->field_frame[i_idx][frame_dst_idx_2] = 1;

            // Copy motion vectors from top and bottom fields using direct index access
            for (int list = 0; list < 2; list++) {
                fs->frame->mv[list][i_idx][frame_dst_idx_1][0] = fs->top_field->mv[list][i_idx][top_mv_src_idx][0];
                fs->frame->mv[list][i_idx][frame_dst_idx_1][1] = fs->top_field->mv[list][i_idx][top_mv_src_idx][1];
                fs->frame->mv[list][i_idx][frame_dst_idx_2][0] = fs->bottom_field->mv[list][i_idx][bottom_mv_src_idx][0];
                fs->frame->mv[list][i_idx][frame_dst_idx_2][1] = fs->bottom_field->mv[list][i_idx][bottom_mv_src_idx][1];
            }

            // Handle reference indices and IDs for top field
            dummylist0 = fs->frame->ref_idx[0][i_idx][frame_dst_idx_1] = fs->top_field->ref_idx[0][i_idx][top_mv_src_idx];
            dummylist1 = fs->frame->ref_idx[1][i_idx][frame_dst_idx_1] = fs->top_field->ref_idx[1][i_idx][top_mv_src_idx];

            fs->top_field->ref_id[0][i_idx][top_mv_src_idx] = (dummylist0 >= 0) ? fs->top_field->ref_pic_num[0][dummylist0] : 0;
            fs->top_field->ref_id[1][i_idx][top_mv_src_idx] = (dummylist1 >= 0) ? fs->top_field->ref_pic_num[1][dummylist1] : 0;
            fs->frame->ref_id[0][i_idx][frame_dst_idx_1] = (dummylist0 >= 0) ? fs->top_field->frm_ref_pic_num[0][dummylist0] : 0;
            fs->frame->ref_id[1][i_idx][frame_dst_idx_1] = (dummylist1 >= 0) ? fs->top_field->frm_ref_pic_num[1][dummylist1] : 0;

            // Handle reference indices and IDs for bottom field
            dummylist0 = fs->frame->ref_idx[0][i_idx][frame_dst_idx_2] = fs->bottom_field->ref_idx[0][i_idx][bottom_mv_src_idx];
            dummylist1 = fs->frame->ref_idx[1][i_idx][frame_dst_idx_2] = fs->bottom_field->ref_idx[1][i_idx][bottom_mv_src_idx];

            fs->bottom_field->ref_id[0][i_idx][bottom_mv_src_idx] = (dummylist0 >= 0) ? fs->bottom_field->ref_pic_num[0][dummylist0] : 0;
            fs->bottom_field->ref_id[1][i_idx][bottom_mv_src_idx] = (dummylist1 >= 0) ? fs->bottom_field->ref_pic_num[1][dummylist1] : 0;
            fs->frame->ref_id[0][i_idx][frame_dst_idx_2] = (dummylist0 >= 0) ? fs->bottom_field->frm_ref_pic_num[0][dummylist0] : -1;
            fs->frame->ref_id[1][i_idx][frame_dst_idx_2] = (dummylist1 >= 0) ? fs->bottom_field->frm_ref_pic_num[1][dummylist1] : -1;
        }
    }
}
