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

extern H265RawVPS *current;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (j = 0; j <= current->vps_max_layer_id; j++) {
        i = j % 63;
        current->layer_id_included_flag[0][i] = (i == 0) ? 1 : current->layer_id_included_flag[0][i];
    }
}
