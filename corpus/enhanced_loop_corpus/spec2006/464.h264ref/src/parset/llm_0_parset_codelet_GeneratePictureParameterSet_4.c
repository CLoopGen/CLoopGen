#include <stdio.h>

#include <inttypes.h>

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

extern pic_parameter_set_rbsp_t *pps;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 2; depth1++) {
        for (int depth2 = 0; depth2 < 4; depth2++) {
            int i = depth1 * 4 + depth2;
            if (i < 8) {
                pps->pic_scaling_list_present_flag[i] = 0;
            }
        }
    }
}
