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

typedef struct decoded_picture_buffer {
    FrameStore **fs;
    FrameStore **fs_ref;
    FrameStore **fs_ltref;
    unsigned int size;
    unsigned int used_size;
    unsigned int ref_frames_in_buffer;
    unsigned int ltref_frames_in_buffer;
    int last_output_poc;
    int max_long_term_pic_idx;
    int init_done;
    FrameStore *last_picture;
} DecodedPictureBuffer;

extern DecodedPictureBuffer dpb;
extern int long_term_frame_idx;
extern int picNumX;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int limit = (dpb.ref_frames_in_buffer > 8) ? 8 : dpb.ref_frames_in_buffer;
    for (i = 0; i < limit; i += 2) {
        FrameStore *fsr = dpb.fs_ref[i];
        if (fsr->is_reference == 3 && !fsr->frame->is_long_term && fsr->frame->pic_num == picNumX) {
            int idx = long_term_frame_idx;
            fsr->long_term_frame_idx = idx;
            fsr->frame->long_term_frame_idx = idx;
            fsr->top_field->long_term_frame_idx = idx;
            fsr->bottom_field->long_term_frame_idx = idx;

            fsr->frame->long_term_pic_num = idx;
            fsr->top_field->long_term_pic_num = idx;
            fsr->bottom_field->long_term_pic_num = idx;

            fsr->frame->is_long_term = 1;
            fsr->top_field->is_long_term = 1;
            fsr->bottom_field->is_long_term = 1;

            fsr->is_long_term = 3;
            return;
        }

        if (i + 1 < dpb.ref_frames_in_buffer) {
            FrameStore *fsr_next = dpb.fs_ref[i + 1];
            if (fsr_next->is_reference == 3 && !fsr_next->frame->is_long_term && fsr_next->frame->pic_num == picNumX) {
                int idx = long_term_frame_idx;
                fsr_next->long_term_frame_idx = idx;
                fsr_next->frame->long_term_frame_idx = idx;
                fsr_next->top_field->long_term_frame_idx = idx;
                fsr_next->bottom_field->long_term_frame_idx = idx;

                fsr_next->frame->long_term_pic_num = idx;
                fsr_next->top_field->long_term_pic_num = idx;
                fsr_next->bottom_field->long_term_pic_num = idx;

                fsr_next->frame->is_long_term = 1;
                fsr_next->top_field->is_long_term = 1;
                fsr_next->bottom_field->is_long_term = 1;

                fsr_next->is_long_term = 3;
                return;
            }
        }
    }
    for (; i < dpb.ref_frames_in_buffer; i++) {
        if (dpb.fs_ref[i]->is_reference == 3 && !dpb.fs_ref[i]->frame->is_long_term && dpb.fs_ref[i]->frame->pic_num == picNumX) {
            dpb.fs_ref[i]->long_term_frame_idx = 
            dpb.fs_ref[i]->frame->long_term_frame_idx = 
            dpb.fs_ref[i]->top_field->long_term_frame_idx = 
            dpb.fs_ref[i]->bottom_field->long_term_frame_idx = long_term_frame_idx;

            dpb.fs_ref[i]->frame->long_term_pic_num = 
            dpb.fs_ref[i]->top_field->long_term_pic_num = 
            dpb.fs_ref[i]->bottom_field->long_term_pic_num = long_term_frame_idx;

            dpb.fs_ref[i]->frame->is_long_term = 
            dpb.fs_ref[i]->top_field->is_long_term = 
            dpb.fs_ref[i]->bottom_field->is_long_term = 1;

            dpb.fs_ref[i]->is_long_term = 3;
            return;
        }
    }
}
