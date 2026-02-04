#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

typedef unsigned char byte;

typedef struct {
    Boolean Valid;
    unsigned int pic_parameter_set_id;
    unsigned int seq_parameter_set_id;
    Boolean entropy_coding_mode_flag;
    Boolean transform_8x8_mode_flag;
    Boolean pic_scaling_matrix_present_flag;
    int pic_scaling_list_present_flag[8];
    Boolean pic_order_present_flag;
    unsigned int num_slice_groups_minus1;
    unsigned int slice_group_map_type;
    unsigned int run_length_minus1[8];
    unsigned int top_left[8];
    unsigned int bottom_right[8];
    Boolean slice_group_change_direction_flag;
    unsigned int slice_group_change_rate_minus1;
    unsigned int pic_size_in_map_units_minus1;
    byte *slice_group_id;
    int num_ref_idx_l0_active_minus1;
    int num_ref_idx_l1_active_minus1;
    Boolean weighted_pred_flag;
    unsigned int weighted_bipred_idc;
    int pic_init_qp_minus26;
    int pic_init_qs_minus26;
    int chroma_qp_index_offset;
    int cb_qp_index_offset;
    int cr_qp_index_offset;
    Boolean deblocking_filter_control_present_flag;
    Boolean constrained_intra_pred_flag;
    Boolean redundant_pic_cnt_present_flag;
    Boolean vui_pic_parameters_flag;
} pic_parameter_set_rbsp_t;

pic_parameter_set_rbsp_t *pps;
unsigned int i;

void init_vars() {
    pps = (pic_parameter_set_rbsp_t *)calloc(1, sizeof(pic_parameter_set_rbsp_t));
    if (!pps) exit(1);

    pps->Valid = FALSE;
    pps->pic_parameter_set_id = 0;
    pps->seq_parameter_set_id = 0;
    pps->entropy_coding_mode_flag = FALSE;
    pps->transform_8x8_mode_flag = FALSE;
    pps->pic_scaling_matrix_present_flag = FALSE;
    for (int j = 0; j < 8; j++) {
        pps->pic_scaling_list_present_flag[j] = 1;
    }
    pps->pic_order_present_flag = FALSE;
    pps->num_slice_groups_minus1 = 0;
    pps->slice_group_map_type = 0;
    for (int j = 0; j < 8; j++) {
        pps->run_length_minus1[j] = 0;
        pps->top_left[j] = 0;
        pps->bottom_right[j] = 0;
    }
    pps->slice_group_change_direction_flag = FALSE;
    pps->slice_group_change_rate_minus1 = 0;
    pps->pic_size_in_map_units_minus1 = 0;
    pps->slice_group_id = (byte *)calloc(1, 1 << 20); // ~1MB
    if (!pps->slice_group_id) exit(1);
    pps->num_ref_idx_l0_active_minus1 = 0;
    pps->num_ref_idx_l1_active_minus1 = 0;
    pps->weighted_pred_flag = FALSE;
    pps->weighted_bipred_idc = 0;
    pps->pic_init_qp_minus26 = 0;
    pps->pic_init_qs_minus26 = 0;
    pps->chroma_qp_index_offset = 0;
    pps->cb_qp_index_offset = 0;
    pps->cr_qp_index_offset = 0;
    pps->deblocking_filter_control_present_flag = FALSE;
    pps->constrained_intra_pred_flag = FALSE;
    pps->redundant_pic_cnt_present_flag = FALSE;
    pps->vui_pic_parameters_flag = FALSE;
}