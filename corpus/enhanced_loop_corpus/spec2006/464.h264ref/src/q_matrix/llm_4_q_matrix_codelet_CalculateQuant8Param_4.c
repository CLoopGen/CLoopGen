#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

typedef struct {
    unsigned int cpb_cnt;
    unsigned int bit_rate_scale;
    unsigned int cpb_size_scale;
    unsigned int bit_rate_value[32];
    unsigned int cpb_size_value[32];
    unsigned int vbr_cbr_flag[32];
    unsigned int initial_cpb_removal_delay_length_minus1;
    unsigned int cpb_removal_delay_length_minus1;
    unsigned int dpb_output_delay_length_minus1;
    unsigned int time_offset_length;
} hrd_parameters_t;

typedef struct {
    Boolean aspect_ratio_info_present_flag;
    unsigned int aspect_ratio_idc;
    unsigned int sar_width;
    unsigned int sar_height;
    Boolean overscan_info_present_flag;
    Boolean overscan_appropriate_flag;
    Boolean video_signal_type_present_flag;
    unsigned int video_format;
    Boolean video_full_range_flag;
    Boolean colour_description_present_flag;
    unsigned int colour_primaries;
    unsigned int transfer_characteristics;
    unsigned int matrix_coefficients;
    Boolean chroma_location_info_present_flag;
    unsigned int chroma_location_frame;
    unsigned int chroma_location_field;
    Boolean timing_info_present_flag;
    unsigned int num_units_in_tick;
    unsigned int time_scale;
    Boolean fixed_frame_rate_flag;
    Boolean nal_hrd_parameters_present_flag;
    hrd_parameters_t nal_hrd_parameters;
    Boolean vcl_hrd_parameters_present_flag;
    hrd_parameters_t vcl_hrd_parameters;
    Boolean low_delay_hrd_flag;
    Boolean bitstream_restriction_flag;
    Boolean motion_vectors_over_pic_boundaries_flag;
    unsigned int max_bytes_per_pic_denom;
    unsigned int max_bits_per_mb_denom;
    unsigned int log2_max_mv_length_vertical;
    unsigned int log2_max_mv_length_horizontal;
    unsigned int max_dec_frame_reordering;
    unsigned int max_dec_frame_buffering;
} vui_seq_parameters_t;

typedef struct {
    Boolean Valid;
    unsigned int profile_idc;
    Boolean constrained_set0_flag;
    Boolean constrained_set1_flag;
    Boolean constrained_set2_flag;
    Boolean constrained_set3_flag;
    unsigned int level_idc;
    unsigned int seq_parameter_set_id;
    unsigned int chroma_format_idc;
    Boolean seq_scaling_matrix_present_flag;
    int seq_scaling_list_present_flag[8];
    unsigned int bit_depth_luma_minus8;
    unsigned int bit_depth_chroma_minus8;
    unsigned int log2_max_frame_num_minus4;
    unsigned int pic_order_cnt_type;
    unsigned int log2_max_pic_order_cnt_lsb_minus4;
    Boolean delta_pic_order_always_zero_flag;
    int offset_for_non_ref_pic;
    int offset_for_top_to_bottom_field;
    unsigned int num_ref_frames_in_pic_order_cnt_cycle;
    int offset_for_ref_frame[256];
    unsigned int num_ref_frames;
    Boolean gaps_in_frame_num_value_allowed_flag;
    unsigned int pic_width_in_mbs_minus1;
    unsigned int pic_height_in_map_units_minus1;
    Boolean frame_mbs_only_flag;
    Boolean mb_adaptive_frame_field_flag;
    Boolean direct_8x8_inference_flag;
    Boolean frame_cropping_flag;
    unsigned int frame_cropping_rect_left_offset;
    unsigned int frame_cropping_rect_right_offset;
    unsigned int frame_cropping_rect_top_offset;
    unsigned int frame_cropping_rect_bottom_offset;
    Boolean vui_parameters_present_flag;
    vui_seq_parameters_t vui_seq_parameters;
} seq_parameter_set_rbsp_t;

extern seq_parameter_set_rbsp_t *active_sps;
extern int i;
extern int present[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        if (active_sps->seq_scaling_list_present_flag[i + 6] > 0) {
            present[i] = 1;
        } else {
            present[i] = 0;
        }
    }
}
