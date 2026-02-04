#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AV1RawFrameHeader {
    uint8_t show_existing_frame;
    uint8_t frame_to_show_map_idx;
    uint32_t frame_presentation_time;
    uint32_t display_frame_id;
    uint8_t frame_type;
    uint8_t show_frame;
    uint8_t showable_frame;
    uint8_t error_resilient_mode;
    uint8_t disable_cdf_update;
    uint8_t allow_screen_content_tools;
    uint8_t force_integer_mv;
    uint32_t current_frame_id;
    uint8_t frame_size_override_flag;
    uint8_t order_hint;
    uint8_t buffer_removal_time_present_flag;
    uint32_t buffer_removal_time[32];
    uint8_t primary_ref_frame;
    uint16_t frame_width_minus_1;
    uint16_t frame_height_minus_1;
    uint8_t use_superres;
    uint8_t coded_denom;
    uint8_t render_and_frame_size_different;
    uint16_t render_width_minus_1;
    uint16_t render_height_minus_1;
    uint8_t found_ref[7];
    uint8_t refresh_frame_flags;
    uint8_t allow_intrabc;
    uint8_t ref_order_hint[8];
    uint8_t frame_refs_short_signaling;
    uint8_t last_frame_idx;
    uint8_t golden_frame_idx;
    int8_t ref_frame_idx[7];
    uint32_t delta_frame_id_minus1[7];
    uint8_t allow_high_precision_mv;
    uint8_t is_filter_switchable;
    uint8_t interpolation_filter;
    uint8_t is_motion_mode_switchable;
    uint8_t use_ref_frame_mvs;
    uint8_t disable_frame_end_update_cdf;
    uint8_t uniform_tile_spacing_flag;
    uint8_t tile_cols_log2;
    uint8_t tile_rows_log2;
    uint8_t width_in_sbs_minus_1[64];
    uint8_t height_in_sbs_minus_1[64];
    uint16_t context_update_tile_id;
    uint8_t tile_size_bytes_minus1;
    uint16_t tile_cols;
    uint16_t tile_rows;
    uint8_t base_q_idx;
    int8_t delta_q_y_dc;
    uint8_t diff_uv_delta;
    int8_t delta_q_u_dc;
    int8_t delta_q_u_ac;
    int8_t delta_q_v_dc;
    int8_t delta_q_v_ac;
    uint8_t using_qmatrix;
    uint8_t qm_y;
    uint8_t qm_u;
    uint8_t qm_v;
    uint8_t segmentation_enabled;
    uint8_t segmentation_update_map;
    uint8_t segmentation_temporal_update;
    uint8_t segmentation_update_data;
    uint8_t feature_enabled[8][8];
    int16_t feature_value[8][8];
    uint8_t delta_q_present;
    uint8_t delta_q_res;
    uint8_t delta_lf_present;
    uint8_t delta_lf_res;
    uint8_t delta_lf_multi;
    uint8_t loop_filter_level[4];
    uint8_t loop_filter_sharpness;
    uint8_t loop_filter_delta_enabled;
    uint8_t loop_filter_delta_update;
    uint8_t update_ref_delta[8];
    int8_t loop_filter_ref_deltas[8];
    uint8_t update_mode_delta[2];
    int8_t loop_filter_mode_deltas[2];
    uint8_t cdef_damping_minus_3;
    uint8_t cdef_bits;
    uint8_t cdef_y_pri_strength[8];
    uint8_t cdef_y_sec_strength[8];
    uint8_t cdef_uv_pri_strength[8];
    uint8_t cdef_uv_sec_strength[8];
    uint8_t lr_type[3];
    uint8_t lr_unit_shift;
    uint8_t lr_uv_shift;
    uint8_t tx_mode;
    uint8_t reference_select;
    uint8_t skip_mode_present;
    uint8_t allow_warped_motion;
    uint8_t reduced_tx_set;
    uint8_t is_global[8];
    uint8_t is_rot_zoom[8];
    uint8_t is_translation[8];
    uint32_t gm_params[8][6];
    uint8_t apply_grain;
    uint16_t grain_seed;
    uint8_t update_grain;
    uint8_t film_grain_params_ref_idx;
    uint8_t num_y_points;
    uint8_t point_y_value[14];
    uint8_t point_y_scaling[14];
    uint8_t chroma_scaling_from_luma;
    uint8_t num_cb_points;
    uint8_t point_cb_value[10];
    uint8_t point_cb_scaling[10];
    uint8_t num_cr_points;
    uint8_t point_cr_value[10];
    uint8_t point_cr_scaling[10];
    uint8_t grain_scaling_minus_8;
    uint8_t ar_coeff_lag;
    uint8_t ar_coeffs_y_plus_128[24];
    uint8_t ar_coeffs_cb_plus_128[25];
    uint8_t ar_coeffs_cr_plus_128[25];
    uint8_t ar_coeff_shift_minus_6;
    uint8_t grain_scale_shift;
    uint8_t cb_mult;
    uint8_t cb_luma_mult;
    uint16_t cb_offset;
    uint8_t cr_mult;
    uint8_t cr_luma_mult;
    uint16_t cr_offset;
    uint8_t overlap_flag;
    uint8_t clip_to_restricted_range;
} AV1RawFrameHeader;

extern AV1RawFrameHeader *current;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        current->loop_filter_mode_deltas[i] = 0;
    }
}
