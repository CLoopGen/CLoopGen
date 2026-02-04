#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

typedef enum {
    FALSE,
    TRUE
} Boolean;

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

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern pic_parameter_set_rbsp_t *pps;
extern unsigned int iGroup;
extern unsigned int j;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using indirect indexing with stride simulation
    unsigned int group, idx;
    unsigned int base = 0;
    for (group = 0; group <= pps->num_slice_groups_minus1 && base < PicSizeInMapUnits; group++) {
        unsigned int run_plus1 = pps->run_length_minus1[group] + 1;
        // Simulate strided write by accessing every 4th element cyclically within the block
        for (idx = 0; idx < run_plus1 && base + idx < PicSizeInMapUnits; idx++) {
            // Stride access: write to positions in a non-linear but deterministic order
            unsigned int stride_mask = 3; // Simulate stride of 4
            unsigned int offset = (idx & ~stride_mask) + ((idx & stride_mask) ^ 2); // Shuffle pattern
            if (base + offset < PicSizeInMapUnits) {
                MapUnitToSliceGroupMap[base + offset] = group;
            }
        }
        base += run_plus1;
    }
}
