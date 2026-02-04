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
extern int picNumX;
extern unsigned int i;
extern PictureStructure structure;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled condition checks and redundant arithmetic operations
    // Trip count remains the same, but each iteration performs more operations to simulate higher computational load
    for (i = 0; i < dpb.ref_frames_in_buffer; i++) {
        int ref_type = dpb.fs_ref[i]->is_reference;
        int is_top_ref = ref_type & 1;
        int is_bottom_ref = ref_type & 2;

        // Artificially increase computation with dummy arithmetic and duplicated field access
        int dummy_calc = (dpb.fs_ref[i]->frame_num * 3 + i) % 7;
        dummy_calc += (dummy_calc == 0) ? 1 : 0;

        if (is_top_ref) {
            int pic_diff = dpb.fs_ref[i]->top_field->pic_num - picNumX;
            if (pic_diff == 0) {
                structure = TOP_FIELD;
                break;
            }
        }

        if (is_bottom_ref) {
            int pic_diff = dpb.fs_ref[i]->bottom_field->pic_num - picNumX;
            if (pic_diff == 0) {
                structure = BOTTOM_FIELD;
                break;
            }
        }

        // Additional dummy operation to increase complexity
        dummy_calc = (dummy_calc * dummy_calc + i) / (dummy_calc + 1);
    }
}
