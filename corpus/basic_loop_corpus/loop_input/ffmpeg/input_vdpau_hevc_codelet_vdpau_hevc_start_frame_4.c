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

static unsigned int g_column_width[64];
static unsigned int g_row_height[64];
static unsigned int g_col_bd[65];
static unsigned int g_row_bd[65];
static int g_col_idxX[64];
static int g_ctb_addr_rs_to_ts[4096];
static int g_ctb_addr_ts_to_rs[4096];
static int g_tile_id[4096];
static int g_tile_pos_rs[4096];
static int g_min_tb_addr_zs[4096];
static int g_min_tb_addr_zs_tab[4096];

HEVCPPS *pps = NULL;

void init_vars() {
    pps = (HEVCPPS*)calloc(1, sizeof(HEVCPPS));
    if (!pps) return;

    pps->sps_id = 0;
    pps->sign_data_hiding_flag = 0;
    pps->cabac_init_present_flag = 1;
    pps->num_ref_idx_l0_default_active = 1;
    pps->num_ref_idx_l1_default_active = 1;
    pps->pic_init_qp_minus26 = 0;
    pps->constrained_intra_pred_flag = 0;
    pps->transform_skip_enabled_flag = 1;
    pps->cu_qp_delta_enabled_flag = 1;
    pps->diff_cu_qp_delta_depth = 0;
    pps->cb_qp_offset = 0;
    pps->cr_qp_offset = 0;
    pps->pic_slice_level_chroma_qp_offsets_present_flag = 1;
    pps->weighted_pred_flag = 1;
    pps->weighted_bipred_flag = 1;
    pps->output_flag_present_flag = 0;
    pps->transquant_bypass_enable_flag = 0;
    pps->dependent_slice_segments_enabled_flag = 0;
    pps->tiles_enabled_flag = 1;
    pps->entropy_coding_sync_enabled_flag = 1;
    pps->num_tile_columns = 8;
    pps->num_tile_rows = 8;
    pps->uniform_spacing_flag = 1;
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
    pps->slice_header_extension_present_flag = 1;
    pps->log2_max_transform_skip_block_size = 2;
    pps->pps_range_extensions_flag = 1;
    pps->cross_component_prediction_enabled_flag = 0;
    pps->chroma_qp_offset_list_enabled_flag = 1;
    pps->diff_cu_chroma_qp_offset_depth = 0;
    pps->chroma_qp_offset_list_len_minus1 = 5;

    for (int i = 0; i < 6; i++) {
        pps->cb_qp_offset_list[i] = (int8_t)(i - 3);
        pps->cr_qp_offset_list[i] = (int8_t)(i - 3);
    }

    pps->log2_sao_offset_scale_luma = 2;
    pps->log2_sao_offset_scale_chroma = 2;

    pps->column_width = g_column_width;
    pps->row_height = g_row_height;
    pps->col_bd = g_col_bd;
    pps->row_bd = g_row_bd;
    pps->col_idxX = g_col_idxX;
    pps->ctb_addr_rs_to_ts = g_ctb_addr_rs_to_ts;
    pps->ctb_addr_ts_to_rs = g_ctb_addr_ts_to_rs;
    pps->tile_id = g_tile_id;
    pps->tile_pos_rs = g_tile_pos_rs;
    pps->min_tb_addr_zs = g_min_tb_addr_zs;
    pps->min_tb_addr_zs_tab = g_min_tb_addr_zs_tab;

    for (int i = 0; i < 64; i++) {
        pps->column_width[i] = 8;
        pps->row_height[i] = 8;
        pps->col_idxX[i] = i;
    }

    for (int i = 0; i <= 64; i++) {
        pps->col_bd[i] = i * 8;
        pps->row_bd[i] = i * 8;
    }

    for (int i = 0; i < 4096; i++) {
        pps->ctb_addr_rs_to_ts[i] = i;
        pps->ctb_addr_ts_to_rs[i] = i;
        pps->tile_id[i] = (i % 8) + (i / 8) * 8;
        pps->tile_pos_rs[i] = i;
        pps->min_tb_addr_zs[i] = i;
        pps->min_tb_addr_zs_tab[i] = i;
    }

    for (int i = 0; i < 4096; i++) {
        pps->data[i] = (uint8_t)(i & 0xFF);
    }
    pps->data_size = 4096;
}