#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ScalingList {
    uint8_t sl[4][6][64];
    uint8_t sl_dc[2][6];
} ScalingList;

typedef struct HEVCPPS {
    unsigned int sps_id;
    uint8_t sign_data_hiding_flag;
    uint8_t cabac_init_present_flag;
    int num_ref_idx_l0_default_active;
    int num_ref_idx_l1_default_active;
    int pic_init_qp_minus26;
    uint8_t constrained_intra_pred_flag;
    uint8_t transform_skip_enabled_flag;
    uint8_t cu_qp_delta_enabled_flag;
    int diff_cu_qp_delta_depth;
    int cb_qp_offset;
    int cr_qp_offset;
    uint8_t pic_slice_level_chroma_qp_offsets_present_flag;
    uint8_t weighted_pred_flag;
    uint8_t weighted_bipred_flag;
    uint8_t output_flag_present_flag;
    uint8_t transquant_bypass_enable_flag;
    uint8_t dependent_slice_segments_enabled_flag;
    uint8_t tiles_enabled_flag;
    uint8_t entropy_coding_sync_enabled_flag;
    uint16_t num_tile_columns;
    uint16_t num_tile_rows;
    uint8_t uniform_spacing_flag;
    uint8_t loop_filter_across_tiles_enabled_flag;
    uint8_t seq_loop_filter_across_slices_enabled_flag;
    uint8_t deblocking_filter_control_present_flag;
    uint8_t deblocking_filter_override_enabled_flag;
    uint8_t disable_dbf;
    int beta_offset;
    int tc_offset;
    uint8_t scaling_list_data_present_flag;
    ScalingList scaling_list;
    uint8_t lists_modification_present_flag;
    int log2_parallel_merge_level;
    int num_extra_slice_header_bits;
    uint8_t slice_header_extension_present_flag;
    uint8_t log2_max_transform_skip_block_size;
    uint8_t pps_range_extensions_flag;
    uint8_t cross_component_prediction_enabled_flag;
    uint8_t chroma_qp_offset_list_enabled_flag;
    uint8_t diff_cu_chroma_qp_offset_depth;
    uint8_t chroma_qp_offset_list_len_minus1;
    int8_t cb_qp_offset_list[6];
    int8_t cr_qp_offset_list[6];
    uint8_t log2_sao_offset_scale_luma;
    uint8_t log2_sao_offset_scale_chroma;
    unsigned int *column_width;
    unsigned int *row_height;
    unsigned int *col_bd;
    unsigned int *row_bd;
    int *col_idxX;
    int *ctb_addr_rs_to_ts;
    int *ctb_addr_ts_to_rs;
    int *tile_id;
    int *tile_pos_rs;
    int *min_tb_addr_zs;
    int *min_tb_addr_zs_tab;
    uint8_t data[4096];
    int data_size;
} HEVCPPS;

extern  HEVCPPS *pps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t i = 0; i < pps->num_tile_columns; i++) {
    // Variant 1: Consecutive memory access - unroll and access multiple elements in row-major order
    ssize_t idx = i * 4;
    if (idx < pps->data_size) {
        uint8_t temp1 = pps->data[idx];
        uint8_t temp2 = pps->data[idx + 1];
        uint8_t temp3 = pps->data[idx + 2];
        uint8_t temp4 = pps->data[idx + 3];
        pps->data[idx] = temp1 ^ temp2;
        pps->data[idx + 1] = temp3 ^ temp4;
    }
}
}
