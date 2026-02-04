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
for (j = 0; j < fs->frame->size_y / 4; j++) {
    for (i = 0; i < fs->frame->size_x / 4; i++) {
        int idiv4 = i >> 2, jdiv4 = j >> 2;
        int currentmb = (fs->frame->size_x / 16) * (jdiv4 & ~1) + (idiv4 << 1) + (jdiv4 & 1);
        int list_offset = 0;
        dummylist0 = fs->frame->ref_idx[0][i][j];
        dummylist1 = fs->frame->ref_idx[1][i][j];
        
        if (fs->frame->MbaffFrameFlag && fs->frame->mb_field[currentmb]) {
            list_offset = (currentmb & 1) ? 4 : 2;
            int64_t temp0 = (dummylist0 >= 0) ? fs->frame->ref_pic_num[0 + list_offset][dummylist0] : 0;
            int64_t temp1 = (dummylist1 >= 0) ? fs->frame->ref_pic_num[1 + list_offset][dummylist1] : 0;
            int64_t temp2 = (dummylist0 >= 0) ? fs->frame->frm_ref_pic_num[0 + list_offset][dummylist0] : 0;
            int64_t temp3 = (dummylist1 >= 0) ? fs->frame->frm_ref_pic_num[1 + list_offset][dummylist1] : 0;
            
            fs->frame->ref_id[0 + list_offset][i][j] = temp0;
            fs->frame->ref_id[1 + list_offset][i][j] = temp1;
            fs->frame->ref_id[0][i][j] = temp2;
            fs->frame->ref_id[1][i][j] = temp3;
        } else {
            fs->frame->ref_id[0][i][j] = (dummylist0 >= 0) ? fs->frame->ref_pic_num[0][dummylist0] : -1;
            fs->frame->ref_id[1][i][j] = (dummylist1 >= 0) ? fs->frame->ref_pic_num[1][dummylist1] : -1;
        }
    }
}
}
