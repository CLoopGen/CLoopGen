#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct H265RawNALUnitHeader {
    uint8_t nal_unit_type;
    uint8_t nuh_layer_id;
    uint8_t nuh_temporal_id_plus1;
} H265RawNALUnitHeader;

typedef struct H265RawProfileTierLevel {
    uint8_t general_profile_space;
    uint8_t general_tier_flag;
    uint8_t general_profile_idc;
    uint8_t general_profile_compatibility_flag[32];
    uint8_t general_progressive_source_flag;
    uint8_t general_interlaced_source_flag;
    uint8_t general_non_packed_constraint_flag;
    uint8_t general_frame_only_constraint_flag;
    uint8_t general_max_12bit_constraint_flag;
    uint8_t general_max_10bit_constraint_flag;
    uint8_t general_max_8bit_constraint_flag;
    uint8_t general_max_422chroma_constraint_flag;
    uint8_t general_max_420chroma_constraint_flag;
    uint8_t general_max_monochrome_constraint_flag;
    uint8_t general_intra_constraint_flag;
    uint8_t general_one_picture_only_constraint_flag;
    uint8_t general_lower_bit_rate_constraint_flag;
    uint8_t general_max_14bit_constraint_flag;
    uint8_t general_inbld_flag;
    uint8_t general_level_idc;
    uint8_t sub_layer_profile_present_flag[7];
    uint8_t sub_layer_level_present_flag[7];
    uint8_t sub_layer_profile_space[7];
    uint8_t sub_layer_tier_flag[7];
    uint8_t sub_layer_profile_idc[7];
    uint8_t sub_layer_profile_compatibility_flag[7][32];
    uint8_t sub_layer_progressive_source_flag[7];
    uint8_t sub_layer_interlaced_source_flag[7];
    uint8_t sub_layer_non_packed_constraint_flag[7];
    uint8_t sub_layer_frame_only_constraint_flag[7];
    uint8_t sub_layer_max_12bit_constraint_flag[7];
    uint8_t sub_layer_max_10bit_constraint_flag[7];
    uint8_t sub_layer_max_8bit_constraint_flag[7];
    uint8_t sub_layer_max_422chroma_constraint_flag[7];
    uint8_t sub_layer_max_420chroma_constraint_flag[7];
    uint8_t sub_layer_max_monochrome_constraint_flag[7];
    uint8_t sub_layer_intra_constraint_flag[7];
    uint8_t sub_layer_one_picture_only_constraint_flag[7];
    uint8_t sub_layer_lower_bit_rate_constraint_flag[7];
    uint8_t sub_layer_max_14bit_constraint_flag[7];
    uint8_t sub_layer_inbld_flag[7];
    uint8_t sub_layer_level_idc[7];
} H265RawProfileTierLevel;

typedef struct H265RawSubLayerHRDParameters {
    uint32_t bit_rate_value_minus1[32];
    uint32_t cpb_size_value_minus1[32];
    uint32_t cpb_size_du_value_minus1[32];
    uint32_t bit_rate_du_value_minus1[32];
    uint8_t cbr_flag[32];
} H265RawSubLayerHRDParameters;

typedef struct H265RawHRDParameters {
    uint8_t nal_hrd_parameters_present_flag;
    uint8_t vcl_hrd_parameters_present_flag;
    uint8_t sub_pic_hrd_params_present_flag;
    uint8_t tick_divisor_minus2;
    uint8_t du_cpb_removal_delay_increment_length_minus1;
    uint8_t sub_pic_cpb_params_in_pic_timing_sei_flag;
    uint8_t dpb_output_delay_du_length_minus1;
    uint8_t bit_rate_scale;
    uint8_t cpb_size_scale;
    uint8_t cpb_size_du_scale;
    uint8_t initial_cpb_removal_delay_length_minus1;
    uint8_t au_cpb_removal_delay_length_minus1;
    uint8_t dpb_output_delay_length_minus1;
    uint8_t fixed_pic_rate_general_flag[7];
    uint8_t fixed_pic_rate_within_cvs_flag[7];
    uint16_t elemental_duration_in_tc_minus1[7];
    uint8_t low_delay_hrd_flag[7];
    uint8_t cpb_cnt_minus1[7];
    H265RawSubLayerHRDParameters nal_sub_layer_hrd_parameters[7];
    H265RawSubLayerHRDParameters vcl_sub_layer_hrd_parameters[7];
} H265RawHRDParameters;

typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

typedef struct H265RawExtensionData {
    uint8_t *data;
    size_t bit_length;
    AVBufferRef *data_ref;
} H265RawExtensionData;

typedef struct H265RawVPS {
    H265RawNALUnitHeader nal_unit_header;
    uint8_t vps_video_parameter_set_id;
    uint8_t vps_base_layer_internal_flag;
    uint8_t vps_base_layer_available_flag;
    uint8_t vps_max_layers_minus1;
    uint8_t vps_max_sub_layers_minus1;
    uint8_t vps_temporal_id_nesting_flag;
    H265RawProfileTierLevel profile_tier_level;
    uint8_t vps_sub_layer_ordering_info_present_flag;
    uint8_t vps_max_dec_pic_buffering_minus1[7];
    uint8_t vps_max_num_reorder_pics[7];
    uint32_t vps_max_latency_increase_plus1[7];
    uint8_t vps_max_layer_id;
    uint16_t vps_num_layer_sets_minus1;
    uint8_t layer_id_included_flag[1024][63];
    uint8_t vps_timing_info_present_flag;
    uint32_t vps_num_units_in_tick;
    uint32_t vps_time_scale;
    uint8_t vps_poc_proportional_to_timing_flag;
    uint32_t vps_num_ticks_poc_diff_one_minus1;
    uint16_t vps_num_hrd_parameters;
    uint16_t hrd_layer_set_idx[1024];
    uint8_t cprms_present_flag[1024];
    H265RawHRDParameters hrd_parameters[1024];
    uint8_t vps_extension_flag;
    H265RawExtensionData extension_data;
} H265RawVPS;

typedef struct H265RawScalingList {
    uint8_t scaling_list_pred_mode_flag[4][6];
    uint8_t scaling_list_pred_matrix_id_delta[4][6];
    int16_t scaling_list_dc_coef_minus8[4][6];
    int8_t scaling_list_delta_coeff[4][6][64];
} H265RawScalingList;

typedef struct H265RawSTRefPicSet {
    uint8_t inter_ref_pic_set_prediction_flag;
    uint8_t delta_idx_minus1;
    uint8_t delta_rps_sign;
    uint16_t abs_delta_rps_minus1;
    uint8_t used_by_curr_pic_flag[16];
    uint8_t use_delta_flag[16];
    uint8_t num_negative_pics;
    uint8_t num_positive_pics;
    uint16_t delta_poc_s0_minus1[16];
    uint8_t used_by_curr_pic_s0_flag[16];
    uint16_t delta_poc_s1_minus1[16];
    uint8_t used_by_curr_pic_s1_flag[16];
} H265RawSTRefPicSet;

typedef struct H265RawVUI {
    uint8_t aspect_ratio_info_present_flag;
    uint8_t aspect_ratio_idc;
    uint16_t sar_width;
    uint16_t sar_height;
    uint8_t overscan_info_present_flag;
    uint8_t overscan_appropriate_flag;
    uint8_t video_signal_type_present_flag;
    uint8_t video_format;
    uint8_t video_full_range_flag;
    uint8_t colour_description_present_flag;
    uint8_t colour_primaries;
    uint8_t transfer_characteristics;
    uint8_t matrix_coefficients;
    uint8_t chroma_loc_info_present_flag;
    uint8_t chroma_sample_loc_type_top_field;
    uint8_t chroma_sample_loc_type_bottom_field;
    uint8_t neutral_chroma_indication_flag;
    uint8_t field_seq_flag;
    uint8_t frame_field_info_present_flag;
    uint8_t default_display_window_flag;
    uint16_t def_disp_win_left_offset;
    uint16_t def_disp_win_right_offset;
    uint16_t def_disp_win_top_offset;
    uint16_t def_disp_win_bottom_offset;
    uint8_t vui_timing_info_present_flag;
    uint32_t vui_num_units_in_tick;
    uint32_t vui_time_scale;
    uint8_t vui_poc_proportional_to_timing_flag;
    uint32_t vui_num_ticks_poc_diff_one_minus1;
    uint8_t vui_hrd_parameters_present_flag;
    H265RawHRDParameters hrd_parameters;
    uint8_t bitstream_restriction_flag;
    uint8_t tiles_fixed_structure_flag;
    uint8_t motion_vectors_over_pic_boundaries_flag;
    uint8_t restricted_ref_pic_lists_flag;
    uint16_t min_spatial_segmentation_idc;
    uint8_t max_bytes_per_pic_denom;
    uint8_t max_bits_per_min_cu_denom;
    uint8_t log2_max_mv_length_horizontal;
    uint8_t log2_max_mv_length_vertical;
} H265RawVUI;

typedef struct H265RawSPS {
    H265RawNALUnitHeader nal_unit_header;
    uint8_t sps_video_parameter_set_id;
    uint8_t sps_max_sub_layers_minus1;
    uint8_t sps_temporal_id_nesting_flag;
    H265RawProfileTierLevel profile_tier_level;
    uint8_t sps_seq_parameter_set_id;
    uint8_t chroma_format_idc;
    uint8_t separate_colour_plane_flag;
    uint16_t pic_width_in_luma_samples;
    uint16_t pic_height_in_luma_samples;
    uint8_t conformance_window_flag;
    uint16_t conf_win_left_offset;
    uint16_t conf_win_right_offset;
    uint16_t conf_win_top_offset;
    uint16_t conf_win_bottom_offset;
    uint8_t bit_depth_luma_minus8;
    uint8_t bit_depth_chroma_minus8;
    uint8_t log2_max_pic_order_cnt_lsb_minus4;
    uint8_t sps_sub_layer_ordering_info_present_flag;
    uint8_t sps_max_dec_pic_buffering_minus1[7];
    uint8_t sps_max_num_reorder_pics[7];
    uint32_t sps_max_latency_increase_plus1[7];
    uint8_t log2_min_luma_coding_block_size_minus3;
    uint8_t log2_diff_max_min_luma_coding_block_size;
    uint8_t log2_min_luma_transform_block_size_minus2;
    uint8_t log2_diff_max_min_luma_transform_block_size;
    uint8_t max_transform_hierarchy_depth_inter;
    uint8_t max_transform_hierarchy_depth_intra;
    uint8_t scaling_list_enabled_flag;
    uint8_t sps_scaling_list_data_present_flag;
    H265RawScalingList scaling_list;
    uint8_t amp_enabled_flag;
    uint8_t sample_adaptive_offset_enabled_flag;
    uint8_t pcm_enabled_flag;
    uint8_t pcm_sample_bit_depth_luma_minus1;
    uint8_t pcm_sample_bit_depth_chroma_minus1;
    uint8_t log2_min_pcm_luma_coding_block_size_minus3;
    uint8_t log2_diff_max_min_pcm_luma_coding_block_size;
    uint8_t pcm_loop_filter_disabled_flag;
    uint8_t num_short_term_ref_pic_sets;
    H265RawSTRefPicSet st_ref_pic_set[64];
    uint8_t long_term_ref_pics_present_flag;
    uint8_t num_long_term_ref_pics_sps;
    uint16_t lt_ref_pic_poc_lsb_sps[32];
    uint8_t used_by_curr_pic_lt_sps_flag[32];
    uint8_t sps_temporal_mvp_enabled_flag;
    uint8_t strong_intra_smoothing_enabled_flag;
    uint8_t vui_parameters_present_flag;
    H265RawVUI vui;
    uint8_t sps_extension_present_flag;
    uint8_t sps_range_extension_flag;
    uint8_t sps_multilayer_extension_flag;
    uint8_t sps_3d_extension_flag;
    uint8_t sps_scc_extension_flag;
    uint8_t sps_extension_4bits;
    H265RawExtensionData extension_data;
    uint8_t transform_skip_rotation_enabled_flag;
    uint8_t transform_skip_context_enabled_flag;
    uint8_t implicit_rdpcm_enabled_flag;
    uint8_t explicit_rdpcm_enabled_flag;
    uint8_t extended_precision_processing_flag;
    uint8_t intra_smoothing_disabled_flag;
    uint8_t high_precision_offsets_enabled_flag;
    uint8_t persistent_rice_adaptation_enabled_flag;
    uint8_t cabac_bypass_alignment_enabled_flag;
    uint8_t sps_curr_pic_ref_enabled_flag;
    uint8_t palette_mode_enabled_flag;
    uint8_t palette_max_size;
    uint8_t delta_palette_max_predictor_size;
    uint8_t sps_palette_predictor_initializer_present_flag;
    uint8_t sps_num_palette_predictor_initializer_minus1;
    uint16_t sps_palette_predictor_initializers[3][128];
    uint8_t motion_vector_resolution_control_idc;
    uint8_t intra_boundary_filtering_disable_flag;
} H265RawSPS;

extern H265RawVPS *vps;
extern H265RawSPS *sps;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i <= sps->sps_max_sub_layers_minus1; i++) {
    sps->sps_max_dec_pic_buffering_minus1[i] = vps->vps_max_dec_pic_buffering_minus1[i];
    sps->sps_max_num_reorder_pics[i] = vps->vps_max_num_reorder_pics[i];
    sps->sps_max_latency_increase_plus1[i] = vps->vps_max_latency_increase_plus1[i];
}

}
