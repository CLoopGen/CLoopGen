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

HEVCPPS *pps;

void init_vars() {
    pps = (HEVCPPS *)calloc(1, sizeof(HEVCPPS));
    if (!pps) return;

    pps->sps_id = 0;
    pps->sign_data_hiding_flag = 0;
    pps->cabac_init_present_flag = 0;
    pps->num_ref_idx_l0_default_active = 1;
    pps->num_ref_idx_l1_default_active = 1;
    pps->pic_init_qp_minus26 = 0;
    pps->constrained_intra_pred_flag = 0;
    pps->transform_skip_enabled_flag = 0;
    pps->cu_qp_delta_enabled_flag = 0;
    pps->diff_cu_qp_delta_depth = 0;
    pps->cb_qp_offset = 0;
    pps->cr_qp_offset = 0;
    pps->pic_slice_level_chroma_qp_offsets_present_flag = 0;
    pps->weighted_pred_flag = 0;
    pps->weighted_bipred_flag = 0;
    pps->output_flag_present_flag = 0;
    pps->transquant_bypass_enable_flag = 0;
    pps->dependent_slice_segments_enabled_flag = 0;
    pps->tiles_enabled_flag = 1;
    pps->entropy_coding_sync_enabled_flag = 0;
    pps->num_tile_columns = 16;
    pps->num_tile_rows = 16;
    pps->uniform_spacing_flag = 0;
    pps->loop_filter_across_tiles_enabled_flag = 1;
    pps->seq_loop_filter_across_slices_enabled_flag = 1;
    pps->deblocking_filter_control_present_flag = 1;
    pps->deblocking_filter_override_enabled_flag = 0;
    pps->disable_dbf = 0;
    pps->beta_offset = 0;
    pps->tc_offset = 0;
    pps->scaling_list_data_present_flag = 0;
    pps->lists_modification_present_flag = 0;
    pps->log2_parallel_merge_level = 2;
    pps->num_extra_slice_header_bits = 0;
    pps->slice_header_extension_present_flag = 0;
    pps->log2_max_transform_skip_block_size = 2;
    pps->pps_range_extensions_flag = 0;
    pps->cross_component_prediction_enabled_flag = 0;
    pps->chroma_qp_offset_list_enabled_flag = 0;
    pps->diff_cu_chroma_qp_offset_depth = 0;
    pps->chroma_qp_offset_list_len_minus1 = 0;
    for (int i = 0; i < 6; i++) {
        pps->cb_qp_offset_list[i] = 0;
        pps->cr_qp_offset_list[i] = 0;
    }
    pps->log2_sao_offset_scale_luma = 0;
    pps->log2_sao_offset_scale_chroma = 0;

    size_t total_ctbs = pps->num_tile_columns * pps->num_tile_rows;
    size_t large_array_size = 131072; // ~1MB of integers to ensure loop overhead

    pps->column_width = (unsigned int *)calloc(large_array_size, sizeof(unsigned int));
    pps->row_height = (unsigned int *)calloc(large_array_size, sizeof(unsigned int));
    pps->col_bd = (unsigned int *)calloc(large_array_size + 1, sizeof(unsigned int));
    pps->row_bd = (unsigned int *)calloc(large_array_size + 1, sizeof(unsigned int));
    pps->col_idxX = (int *)calloc(large_array_size, sizeof(int));
    pps->ctb_addr_rs_to_ts = (int *)calloc(large_array_size, sizeof(int));
    pps->ctb_addr_ts_to_rs = (int *)calloc(large_array_size, sizeof(int));
    pps->tile_id = (int *)calloc(large_array_size, sizeof(int));
    pps->tile_pos_rs = (int *)calloc(large_array_size, sizeof(int));
    pps->min_tb_addr_zs = (int *)calloc(large_array_size, sizeof(int));
    pps->min_tb_addr_zs_tab = (int *)calloc(large_array_size, sizeof(int));

    for (size_t i = 0; i < large_array_size; i++) {
        pps->column_width[i] = 16;
        pps->row_height[i] = 16;
        pps->col_idxX[i] = i % pps->num_tile_columns;
        pps->ctb_addr_rs_to_ts[i] = i;
        pps->ctb_addr_ts_to_rs[i] = i;
        pps->tile_id[i] = i % total_ctbs;
        pps->tile_pos_rs[i] = i;
        pps->min_tb_addr_zs[i] = 0;
        pps->min_tb_addr_zs_tab[i] = 0;
    }

    for (size_t i = 0; i <= large_array_size; i++) {
        pps->col_bd[i] = i * 16;
        pps->row_bd[i] = i * 16;
    }

    pps->data_size = 4096;
    for (int i = 0; i < 4096; i++) {
        pps->data[i] = i % 256;
    }
}