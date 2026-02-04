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



void loop(){
int width = fs->top_field->size_x / 4;
int height = fs->top_field->size_y / 4;
int stride = 8;

for (i = 0; i < width; i += 2) {
    for (j = 0; j < height; j += 2) {
        int base_j1 = 8 * (j / 4) + (j % 4);
        int base_j2 = base_j1 + 4;

        if (i + 1 < width) {
            for (int jj = 0; jj < ((j + 1 < height) ? 2 : 1); jj++) {
                int curr_j = j + jj;
                int base_curr = 8 * (curr_j / 4) + (curr_j % 4);
                int base_curr2 = base_curr + 4;

                fs->frame->field_frame[i][base_curr] = fs->frame->field_frame[i][base_curr2] = 1;

                fs->frame->mv[0][i][base_curr][0] = fs->top_field->mv[0][i][curr_j][0];
                fs->frame->mv[0][i][base_curr][1] = fs->top_field->mv[0][i][curr_j][1];
                fs->frame->mv[1][i][base_curr][0] = fs->top_field->mv[1][i][curr_j][0];
                fs->frame->mv[1][i][base_curr][1] = fs->top_field->mv[1][i][curr_j][1];

                dummylist0 = fs->frame->ref_idx[0][i][base_curr] = fs->top_field->ref_idx[0][i][curr_j];
                dummylist1 = fs->frame->ref_idx[1][i][base_curr] = fs->top_field->ref_idx[1][i][curr_j];

                fs->top_field->ref_id[0][i][curr_j] = (dummylist0 >= 0) ? fs->top_field->ref_pic_num[0][dummylist0] : 0;
                fs->top_field->ref_id[1][i][curr_j] = (dummylist1 >= 0) ? fs->top_field->ref_pic_num[1][dummylist1] : 0;
                fs->frame->ref_id[0][i][base_curr] = (dummylist0 >= 0) ? fs->top_field->frm_ref_pic_num[0][dummylist0] : 0;
                fs->frame->ref_id[1][i][base_curr] = (dummylist1 >= 0) ? fs->top_field->frm_ref_pic_num[1][dummylist1] : 0;

                fs->frame->mv[0][i][base_curr2][0] = fs->bottom_field->mv[0][i][curr_j][0];
                fs->frame->mv[0][i][base_curr2][1] = fs->bottom_field->mv[0][i][curr_j][1];
                fs->frame->mv[1][i][base_curr2][0] = fs->bottom_field->mv[1][i][curr_j][0];
                fs->frame->mv[1][i][base_curr2][1] = fs->bottom_field->mv[1][i][curr_j][1];

                dummylist0 = fs->frame->ref_idx[0][i][base_curr2] = fs->bottom_field->ref_idx[0][i][curr_j];
                dummylist1 = fs->frame->ref_idx[1][i][base_curr2] = fs->bottom_field->ref_idx[1][i][curr_j];

                fs->bottom_field->ref_id[0][i][curr_j] = (dummylist0 >= 0) ? fs->bottom_field->ref_pic_num[0][dummylist0] : 0;
                fs->bottom_field->ref_id[1][i][curr_j] = (dummylist1 >= 0) ? fs->bottom_field->ref_pic_num[1][dummylist1] : 0;
                fs->frame->ref_id[0][i][base_curr2] = (dummylist0 >= 0) ? fs->bottom_field->frm_ref_pic_num[0][dummylist0] : -1;
                fs->frame->ref_id[1][i][base_curr2] = (dummylist1 >= 0) ? fs->bottom_field->frm_ref_pic_num[1][dummylist1] : -1;
            }

            if (i + 1 < width) {
                for (int jj = 0; jj < ((j + 1 < height) ? 2 : 1); jj++) {
                    int curr_j = j + jj;
                    int base_curr = 8 * (curr_j / 4) + (curr_j % 4);
                    int base_curr2 = base_curr + 4;

                    fs->frame->field_frame[i+1][base_curr] = fs->frame->field_frame[i+1][base_curr2] = 1;

                    fs->frame->mv[0][i+1][base_curr][0] = fs->top_field->mv[0][i+1][curr_j][0];
                    fs->frame->mv[0][i+1][base_curr][1] = fs->top_field->mv[0][i+1][curr_j][1];
                    fs->frame->mv[1][i+1][base_curr][0] = fs->top_field->mv[1][i+1][curr_j][0];
                    fs->frame->mv[1][i+1][base_curr][1] = fs->top_field->mv[1][i+1][curr_j][1];

                    dummylist0 = fs->frame->ref_idx[0][i+1][base_curr] = fs->top_field->ref_idx[0][i+1][curr_j];
                    dummylist1 = fs->frame->ref_idx[1][i+1][base_curr] = fs->top_field->ref_idx[1][i+1][curr_j];

                    fs->top_field->ref_id[0][i+1][curr_j] = (dummylist0 >= 0) ? fs->top_field->ref_pic_num[0][dummylist0] : 0;
                    fs->top_field->ref_id[1][i+1][curr_j] = (dummylist1 >= 0) ? fs->top_field->ref_pic_num[1][dummylist1] : 0;
                    fs->frame->ref_id[0][i+1][base_curr] = (dummylist0 >= 0) ? fs->top_field->frm_ref_pic_num[0][dummylist0] : 0;
                    fs->frame->ref_id[1][i+1][base_curr] = (dummylist1 >= 0) ? fs->top_field->frm_ref_pic_num[1][dummylist1] : 0;

                    fs->frame->mv[0][i+1][base_curr2][0] = fs->bottom_field->mv[0][i+1][curr_j][0];
                    fs->frame->mv[0][i+1][base_curr2][1] = fs->bottom_field->mv[0][i+1][curr_j][1];
                    fs->frame->mv[1][i+1][base_curr2][0] = fs->bottom_field->mv[1][i+1][curr_j][0];
                    fs->frame->mv[1][i+1][base_curr2][1] = fs->bottom_field->mv[1][i+1][curr_j][1];

                    dummylist0 = fs->frame->ref_idx[0][i+1][base_curr2] = fs->bottom_field->ref_idx[0][i+1][curr_j];
                    dummylist1 = fs->frame->ref_idx[1][i+1][base_curr2] = fs->bottom_field->ref_idx[1][i+1][curr_j];

                    fs->bottom_field->ref_id[0][i+1][curr_j] = (dummylist0 >= 0) ? fs->bottom_field->ref_pic_num[0][dummylist0] : 0;
                    fs->bottom_field->ref_id[1][i+1][curr_j] = (dummylist1 >= 0) ? fs->bottom_field->ref_pic_num[1][dummylist1] : 0;
                    fs->frame->ref_id[0][i+1][base_curr2] = (dummylist0 >= 0) ? fs->bottom_field->frm_ref_pic_num[0][dummylist0] : -1;
                    fs->frame->ref_id[1][i+1][base_curr2] = (dummylist1 >= 0) ? fs->bottom_field->frm_ref_pic_num[1][dummylist1] : -1;
                }
            }
        } else {
            int curr_j = j;
            int base_curr = base_j1;
            int base_curr2 = base_curr + 4;

            fs->frame->field_frame[i][base_curr] = fs->frame->field_frame[i][base_curr2] = 1;

            fs->frame->mv[0][i][base_curr][0] = fs->top_field->mv[0][i][curr_j][0];
            fs->frame->mv[0][i][base_curr][1] = fs->top_field->mv[0][i][curr_j][1];
            fs->frame->mv[1][i][base_curr][0] = fs->top_field->mv[1][i][curr_j][0];
            fs->frame->mv[1][i][base_curr][1] = fs->top_field->mv[1][i][curr_j][1];

            dummylist0 = fs->frame->ref_idx[0][i][base_curr] = fs->top_field->ref_idx[0][i][curr_j];
            dummylist1 = fs->frame->ref_idx[1][i][base_curr] = fs->top_field->ref_idx[1][i][curr_j];

            fs->top_field->ref_id[0][i][curr_j] = (dummylist0 >= 0) ? fs->top_field->ref_pic_num[0][dummylist0] : 0;
            fs->top_field->ref_id[1][i][curr_j] = (dummylist1 >= 0) ? fs->top_field->ref_pic_num[1][dummylist1] : 0;
            fs->frame->ref_id[0][i][base_curr] = (dummylist0 >= 0) ? fs->top_field->frm_ref_pic_num[0][dummylist0] : 0;
            fs->frame->ref_id[1][i][base_curr] = (dummylist1 >= 0) ? fs->top_field->frm_ref_pic_num[1][dummylist1] : 0;

            fs->frame->mv[0][i][base_curr2][0] = fs->bottom_field->mv[0][i][curr_j][0];
            fs->frame->mv[0][i][base_curr2][1] = fs->bottom_field->mv[0][i][curr_j][1];
            fs->frame->mv[1][i][base_curr2][0] = fs->bottom_field->mv[1][i][curr_j][0];
            fs->frame->mv[1][i][base_curr2][1] = fs->bottom_field->mv[1][i][curr_j][1];

            dummylist0 = fs->frame->ref_idx[0][i][base_curr2] = fs->bottom_field->ref_idx[0][i][curr_j];
            dummylist1 = fs->frame->ref_idx[1][i][base_curr2] = fs->bottom_field->ref_idx[1][i][curr_j];

            fs->bottom_field->ref_id[0][i][curr_j] = (dummylist0 >= 0) ? fs->bottom_field->ref_pic_num[0][dummylist0] : 0;
            fs->bottom_field->ref_id[1][i][curr_j] = (dummylist1 >= 0) ? fs->bottom_field->ref_pic_num[1][dummylist1] : 0;
            fs->frame->ref_id[0][i][base_curr2] = (dummylist0 >= 0) ? fs->bottom_field->frm_ref_pic_num[0][dummylist0] : -1;
            fs->frame->ref_id[1][i][base_curr2] = (dummylist1 >= 0) ? fs->bottom_field->frm_ref_pic_num[1][dummylist1] : -1;
        }
    }
}
}
