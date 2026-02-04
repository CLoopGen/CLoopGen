#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

seq_parameter_set_rbsp_t *sps;
unsigned int i;

void init_vars() {
    sps = (seq_parameter_set_rbsp_t*)calloc(1, sizeof(seq_parameter_set_rbsp_t));
    if (!sps) exit(1);

    sps->Valid = FALSE;
    sps->profile_idc = 100;
    sps->constrained_set0_flag = FALSE;
    sps->constrained_set1_flag = FALSE;
    sps->constrained_set2_flag = FALSE;
    sps->constrained_set3_flag = FALSE;
    sps->level_idc = 40;
    sps->seq_parameter_set_id = 0;
    sps->chroma_format_idc = 1;
    sps->seq_scaling_matrix_present_flag = FALSE;
    for (int j = 0; j < 8; j++) {
        sps->seq_scaling_list_present_flag[j] = 0;
    }
    sps->bit_depth_luma_minus8 = 0;
    sps->bit_depth_chroma_minus8 = 0;
    sps->log2_max_frame_num_minus4 = 4;
    sps->pic_order_cnt_type = 0;
    sps->log2_max_pic_order_cnt_lsb_minus4 = 4;
    sps->delta_pic_order_always_zero_flag = FALSE;
    sps->offset_for_non_ref_pic = 0;
    sps->offset_for_top_to_bottom_field = 0;
    sps->num_ref_frames_in_pic_order_cnt_cycle = 0;
    for (int j = 0; j < 256; j++) {
        sps->offset_for_ref_frame[j] = 0;
    }
    sps->num_ref_frames = 1;
    sps->gaps_in_frame_num_value_allowed_flag = FALSE;
    sps->pic_width_in_mbs_minus1 = 127;
    sps->pic_height_in_map_units_minus1 = 71;
    sps->frame_mbs_only_flag = TRUE;
    sps->mb_adaptive_frame_field_flag = FALSE;
    sps->direct_8x8_inference_flag = TRUE;
    sps->frame_cropping_flag = FALSE;
    sps->frame_cropping_rect_left_offset = 0;
    sps->frame_cropping_rect_right_offset = 0;
    sps->frame_cropping_rect_top_offset = 0;
    sps->frame_cropping_rect_bottom_offset = 0;
    sps->vui_parameters_present_flag = TRUE;

    vui_seq_parameters_t* vui = &sps->vui_seq_parameters;
    vui->aspect_ratio_info_present_flag = FALSE;
    vui->aspect_ratio_idc = 0;
    vui->sar_width = 0;
    vui->sar_height = 0;
    vui->overscan_info_present_flag = FALSE;
    vui->overscan_appropriate_flag = FALSE;
    vui->video_signal_type_present_flag = FALSE;
    vui->video_format = 0;
    vui->video_full_range_flag = FALSE;
    vui->colour_description_present_flag = FALSE;
    vui->colour_primaries = 0;
    vui->transfer_characteristics = 0;
    vui->matrix_coefficients = 0;
    vui->chroma_location_info_present_flag = FALSE;
    vui->chroma_location_frame = 0;
    vui->chroma_location_field = 0;
    vui->timing_info_present_flag = FALSE;
    vui->num_units_in_tick = 1001;
    vui->time_scale = 60000;
    vui->fixed_frame_rate_flag = TRUE;
    vui->nal_hrd_parameters_present_flag = FALSE;
    vui->vcl_hrd_parameters_present_flag = FALSE;
    vui->low_delay_hrd_flag = FALSE;
    vui->bitstream_restriction_flag = FALSE;
    vui->motion_vectors_over_pic_boundaries_flag = TRUE;
    vui->max_bytes_per_pic_denom = 2;
    vui->max_bits_per_mb_denom = 1;
    vui->log2_max_mv_length_vertical = 11;
    vui->log2_max_mv_length_horizontal = 11;
    vui->max_dec_frame_reordering = 0;
    vui->max_dec_frame_buffering = 0;

    hrd_parameters_t* nal_hrd = &vui->nal_hrd_parameters;
    nal_hrd->cpb_cnt = 0;
    nal_hrd->bit_rate_scale = 0;
    nal_hrd->cpb_size_scale = 0;
    for (int j = 0; j < 32; j++) {
        nal_hrd->bit_rate_value[j] = 0;
        nal_hrd->cpb_size_value[j] = 0;
        nal_hrd->vbr_cbr_flag[j] = 0;
    }
    nal_hrd->initial_cpb_removal_delay_length_minus1 = 23;
    nal_hrd->cpb_removal_delay_length_minus1 = 23;
    nal_hrd->dpb_output_delay_length_minus1 = 23;
    nal_hrd->time_offset_length = 0;

    hrd_parameters_t* vcl_hrd = &vui->vcl_hrd_parameters;
    vcl_hrd->cpb_cnt = 0;
    vcl_hrd->bit_rate_scale = 0;
    vcl_hrd->cpb_size_scale = 0;
    for (int j = 0; j < 32; j++) {
        vcl_hrd->bit_rate_value[j] = 0;
        vcl_hrd->cpb_size_value[j] = 0;
        vcl_hrd->vbr_cbr_flag[j] = 0;
    }
    vcl_hrd->initial_cpb_removal_delay_length_minus1 = 23;
    vcl_hrd->cpb_removal_delay_length_minus1 = 23;
    vcl_hrd->dpb_output_delay_length_minus1 = 23;
    vcl_hrd->time_offset_length = 0;
}