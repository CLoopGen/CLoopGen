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
extern StorablePicture **listX[6];
extern unsigned int i;
extern int list0idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Traverse the dpb.fs_ltref array with a fixed stride (e.g., stride of 2)
    // to simulate non-unit-stride access, then handle remaining elements in a second pass
    // to maintain correctness. This changes memory access pattern and may affect cache behavior.
    unsigned int size = dpb.ltref_frames_in_buffer;
    FrameStore **ltref = dpb.fs_ltref;

    // First pass: strided access (every 2nd element starting from 0)
    for (i = 0; i < size; i += 2) {
        FrameStore *fs = ltref[i];
        if (fs->is_used == 3 && fs->frame->is_long_term) {
            StorablePicture *frame = fs->frame;
            frame->long_term_pic_num = frame->long_term_frame_idx;
            frame->order_num = list0idx;
            listX[0][list0idx] = frame;
            listX[1][list0idx++] = frame;
        }
    }

    // Second pass: fill in the odd indices to ensure all elements are processed
    for (i = 1; i < size; i += 2) {
        FrameStore *fs = ltref[i];
        if (fs->is_used == 3 && fs->frame->is_long_term) {
            StorablePicture *frame = fs->frame;
            frame->long_term_pic_num = frame->long_term_frame_idx;
            frame->order_num = list0idx;
            listX[0][list0idx] = frame;
            listX[1][list0idx++] = frame;
        }
    }
}
