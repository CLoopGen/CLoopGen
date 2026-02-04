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

pic_parameter_set_rbsp_t *active_pps;
int i;
int present[6];

void init_vars() {
    active_pps = (pic_parameter_set_rbsp_t*)malloc(sizeof(pic_parameter_set_rbsp_t));
    if (!active_pps) return;

    active_pps->Valid = TRUE;
    active_pps->pic_parameter_set_id = 1;
    active_pps->seq_parameter_set_id = 0;
    active_pps->entropy_coding_mode_flag = FALSE;
    active_pps->transform_8x8_mode_flag = TRUE;
    active_pps->pic_scaling_matrix_present_flag = TRUE;
    for (int j = 0; j < 8; j++) {
        active_pps->pic_scaling_list_present_flag[j] = (j < 6) ? (j % 2) : 0;
    }
    active_pps->pic_order_present_flag = FALSE;
    active_pps->num_slice_groups_minus1 = 0;
    active_pps->slice_group_map_type = 0;
    for (int j = 0; j < 8; j++) {
        active_pps->run_length_minus1[j] = 0;
        active_pps->top_left[j] = j;
        active_pps->bottom_right[j] = j + 1;
    }
    active_pps->slice_group_change_direction_flag = FALSE;
    active_pps->slice_group_change_rate_minus1 = 0;
    active_pps->pic_size_in_map_units_minus1 = 0;
    size_t slice_group_id_size = 256 * 1024 * 1024; // ~256 MB
    active_pps->slice_group_id = (byte*)malloc(slice_group_id_size);
    if (active_pps->slice_group_id) {
        for (size_t k = 0; k < slice_group_id_size; k++) {
            active_pps->slice_group_id[k] = (byte)(k % 256);
        }
    }
    active_pps->num_ref_idx_l0_active_minus1 = 0;
    active_pps->num_ref_idx_l1_active_minus1 = 0;
    active_pps->weighted_pred_flag = FALSE;
    active_pps->weighted_bipred_idc = 0;
    active_pps->pic_init_qp_minus26 = -10;
    active_pps->pic_init_qs_minus26 = 0;
    active_pps->chroma_qp_index_offset = 2;
    active_pps->cb_qp_index_offset = 2;
    active_pps->cr_qp_index_offset = 2;
    active_pps->deblocking_filter_control_present_flag = TRUE;
    active_pps->constrained_intra_pred_flag = TRUE;
    active_pps->redundant_pic_cnt_present_flag = FALSE;
    active_pps->vui_pic_parameters_flag = FALSE;

    for (int j = 0; j < 6; j++) {
        present[j] = 0;
    }

    i = 0;
}