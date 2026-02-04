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
    for (i = 0; i < fs->frame->size_x / 4; i++) {
        for (j = 0; j < fs->frame->size_y / 8; j++) {
            int idiv4 = i >> 2, jdiv4 = j >> 1;
            int currentmb = 2 * ((fs->frame->size_x / 16) * (jdiv4 >> 1)) + (idiv4 << 1) + (jdiv4 & 1);
            if (!fs->frame->MbaffFrameFlag || !fs->frame->mb_field[currentmb]) {
                // Introduce WAW dependency: split field_frame assignment into two sequential steps
                fs->frame->field_frame[i][2 * j] = 0;
                fs->frame->field_frame[i][2 * j + 1] = fs->frame->field_frame[i][2 * j]; // WAW: depends on prior write

                if (!fs->frame->frame_mbs_only_flag) {
                    fs->top_field->field_frame[i][j] = 0;
                    fs->bottom_field->field_frame[i][j] = fs->top_field->field_frame[i][j]; // WAR: read after write

                    // Introduce loop-carried dependence via dummylist accumulation across iterations
                    static int prev_dummy0 = -1, prev_dummy1 = -1;
                    if (prev_dummy0 != -1) {
                        fs->top_field->ref_idx[0][i][j] = prev_dummy0;
                        fs->bottom_field->ref_idx[0][i][j] = prev_dummy0;
                    }
                    if (prev_dummy1 != -1) {
                        fs->top_field->ref_idx[1][i][j] = prev_dummy1;
                        fs->bottom_field->ref_idx[1][i][j] = prev_dummy1;
                    }

                    int idx0 = ((i & 2) ? (i | 1) : (i & (~1)));
                    int idx1 = 2 * ((j & 2) ? (j | 1) : (j & (~1)));

                    if (fs->frame->ref_idx[0][idx0][idx1] == -1) {
                        fs->top_field->ref_idx[0][i][j] = fs->bottom_field->ref_idx[0][i][j] = -1;
                        prev_dummy0 = -1;
                    } else {
                        dummylist0 = fs->frame->ref_idx[0][idx0][idx1];
                        fs->top_field->ref_idx[0][i][j] = dummylist0;
                        fs->bottom_field->ref_idx[0][i][j] = dummylist0;
                        prev_dummy0 = dummylist0;
                    }

                    if (fs->frame->ref_idx[1][idx0][idx1] == -1) {
                        fs->top_field->ref_idx[1][i][j] = fs->bottom_field->ref_idx[1][i][j] = -1;
                        prev_dummy1 = -1;
                    } else {
                        dummylist1 = fs->frame->ref_idx[1][idx0][idx1];
                        fs->top_field->ref_idx[1][i][j] = dummylist1;
                        fs->bottom_field->ref_idx[1][i][j] = dummylist1;
                        prev_dummy1 = dummylist1;
                    }

                    // Maintain other assignments with modified indexing to preserve functionality
                    fs->top_field->mv[0][i][j][0] = fs->frame->mv[0][idx0][idx1][0];
                    fs->bottom_field->mv[0][i][j][0] = fs->frame->mv[0][idx0][idx1][0];
                    fs->top_field->mv[0][i][j][1] = fs->frame->mv[0][idx0][idx1][1];
                    fs->bottom_field->mv[0][i][j][1] = fs->frame->mv[0][idx0][idx1][1];

                    fs->top_field->mv[1][i][j][0] = fs->frame->mv[1][idx0][idx1][0];
                    fs->bottom_field->mv[1][i][j][0] = fs->frame->mv[1][idx0][idx1][0];
                    fs->top_field->mv[1][i][j][1] = fs->frame->mv[1][idx0][idx1][1];
                    fs->bottom_field->mv[1][i][j][1] = fs->frame->mv[1][idx0][idx1][1];

                    fs->top_field->ref_id[0][i][j] = (dummylist0 >= 0) ? fs->frame->top_ref_pic_num[0][dummylist0] : 0;
                    fs->bottom_field->ref_id[0][i][j] = (dummylist0 >= 0) ? fs->frame->bottom_ref_pic_num[0][dummylist0] : 0;

                    fs->top_field->ref_id[1][i][j] = (dummylist1 >= 0) ? fs->frame->top_ref_pic_num[1][dummylist1] : 0;
                    fs->bottom_field->ref_id[1][i][j] = (dummylist1 >= 0) ? fs->frame->bottom_ref_pic_num[1][dummylist1] : 0;
                }
            }
        }
    }
}
