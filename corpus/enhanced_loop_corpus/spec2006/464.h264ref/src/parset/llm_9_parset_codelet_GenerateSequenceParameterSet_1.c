#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

typedef struct {
    int ProfileIDC;
    int LevelIDC;
    int no_frames;
    int qp0;
    int qpN;
    int jumpd;
    int hadamard;
    int hadamardqpel;
    int search_range;
    int num_ref_frames;
    int P_List0_refs;
    int B_List0_refs;
    int B_List1_refs;
    int Log2MaxFrameNum;
    int ResendPPS;
    int GenerateMultiplePPS;
    int img_width;
    int img_height;
    int yuv_format;
    int intra_upd;
    int blc_size[8][2];
    int part_size[8][2];
    int slice_mode;
    int slice_argument;
    int UseConstrainedIntraPred;
    int infile_header;
    char infile[200];
    char outfile[200];
    char ReconFile[200];
    char TraceFile[200];
    char QmatrixFile[200];
    int intra_period;
    int idr_enable;
    int start_frame;
    int successive_Bframe;
    int qpB;
    int qpBRSOffset;
    int direct_spatial_mv_pred_flag;
    int directInferenceFlag;
    int BiPredMotionEstimation;
    int BiPredMERefinements;
    int BiPredMESearchRange;
    int BiPredMESubPel;
    int sp_periodicity;
    int qpsp;
    int qpsp_pred;
    int WeightedPrediction;
    int WeightedBiprediction;
    int UseWeightedReferenceME;
    int RDPictureDecision;
    int RDPictureIntra;
    int RDPSliceWeightOnly;
    int RDBSliceWeightOnly;
    int SkipIntraInInterSlices;
    int BRefPictures;
    int PyramidCoding;
    char ExplicitPyramidFormat[1024];
    int PyramidRefReorder;
    int PocMemoryManagement;
    int symbol_mode;
    int of_mode;
    int partition_mode;
    int InterSearch16x16;
    int InterSearch16x8;
    int InterSearch8x16;
    int InterSearch8x8;
    int InterSearch8x4;
    int InterSearch4x8;
    int InterSearch4x4;
    int IntraDisableInterOnly;
    int Intra4x4ParDisable;
    int Intra4x4DiagDisable;
    int Intra4x4DirDisable;
    int Intra16x16ParDisable;
    int Intra16x16PlaneDisable;
    int ChromaIntraDisable;
    double FrameRate;
    int chroma_qp_index_offset;
    int full_search;
    int last_frame;
    int qpN2;
    int qpB2;
    int qp2start;
    int qp02;
    int qpBRS2Offset;
    int rdopt;
    int disthres;
    int nobskip;
    int NumberLeakyBuckets;
    char LeakyBucketRateFile[200];
    char LeakyBucketParamFile[200];
    int PicInterlace;
    int MbInterlace;
    int IntraBottom;
    int LossRateA;
    int LossRateB;
    int LossRateC;
    int NoOfDecoders;
    int RestrictRef;
    int NumFramesInELSubSeq;
    int NumFrameIn2ndIGOP;
    int RandomIntraMBRefresh;
    int LFSendParameters;
    int LFDisableIdc;
    int LFAlphaC0Offset;
    int LFBetaOffset;
    int SparePictureOption;
    int SPDetectionThreshold;
    int SPPercentageThreshold;
    char SliceGroupConfigFileName[200];
    int num_slice_groups_minus1;
    int slice_group_map_type;
    int *top_left;
    int *bottom_right;
    byte *slice_group_id;
    int *run_length_minus1;
    int slice_group_change_direction_flag;
    int slice_group_change_rate_minus1;
    int slice_group_change_cycle;
    int redundant_slice_flag;
    int pic_order_cnt_type;
    int context_init_method;
    int model_number;
    int AllowTransform8x8;
    int LowPassForIntra8x8;
    int ReportFrameStats;
    int DisplayEncParams;
    int RCEnable;
    int bit_rate;
    int SeinitialQP;
    int basicunit;
    int channel_type;
    int ScalingMatrixPresentFlag;
    int ScalingListPresentFlag[8];
    int FMEnable;
    int BitDepthLuma;
    int BitDepthChroma;
    int img_height_cr;
    int img_width_cr;
    int rgb_input_flag;
    int cb_qp_index_offset;
    int cr_qp_index_offset;
    int lossless_qpprime_y_zero_flag;
    int residue_transform_flag;
    int UseExplicitLambdaParams;
    double LambdaWeight[6];
    char QOffsetMatrixFile[200];
    int OffsetMatrixPresentFlag;
} InputParameters;

typedef enum {
    FALSE,
    TRUE
} Boolean;

typedef struct {
    unsigned int cpb_cnt;
    unsigned int bit_rate_scale;
    unsigned int cpb_size_scale;
    unsigned int bit_rate_value[32];
    unsigned int cpb_size_value[32];
    unsigned int vbr_cbr_flag[32];
    unsigned int initial_cpb_removal_delay_length_minus1;
    unsigned int cpb_removal_delay_length_minus1;
    unsigned int dpb_output_delay_length_minus1;
    unsigned int time_offset_length;
} hrd_parameters_t;

typedef struct {
    Boolean aspect_ratio_info_present_flag;
    unsigned int aspect_ratio_idc;
    unsigned int sar_width;
    unsigned int sar_height;
    Boolean overscan_info_present_flag;
    Boolean overscan_appropriate_flag;
    Boolean video_signal_type_present_flag;
    unsigned int video_format;
    Boolean video_full_range_flag;
    Boolean colour_description_present_flag;
    unsigned int colour_primaries;
    unsigned int transfer_characteristics;
    unsigned int matrix_coefficients;
    Boolean chroma_location_info_present_flag;
    unsigned int chroma_location_frame;
    unsigned int chroma_location_field;
    Boolean timing_info_present_flag;
    unsigned int num_units_in_tick;
    unsigned int time_scale;
    Boolean fixed_frame_rate_flag;
    Boolean nal_hrd_parameters_present_flag;
    hrd_parameters_t nal_hrd_parameters;
    Boolean vcl_hrd_parameters_present_flag;
    hrd_parameters_t vcl_hrd_parameters;
    Boolean low_delay_hrd_flag;
    Boolean bitstream_restriction_flag;
    Boolean motion_vectors_over_pic_boundaries_flag;
    unsigned int max_bytes_per_pic_denom;
    unsigned int max_bits_per_mb_denom;
    unsigned int log2_max_mv_length_vertical;
    unsigned int log2_max_mv_length_horizontal;
    unsigned int max_dec_frame_reordering;
    unsigned int max_dec_frame_buffering;
} vui_seq_parameters_t;

typedef struct {
    Boolean Valid;
    unsigned int profile_idc;
    Boolean constrained_set0_flag;
    Boolean constrained_set1_flag;
    Boolean constrained_set2_flag;
    Boolean constrained_set3_flag;
    unsigned int level_idc;
    unsigned int seq_parameter_set_id;
    unsigned int chroma_format_idc;
    Boolean seq_scaling_matrix_present_flag;
    int seq_scaling_list_present_flag[8];
    unsigned int bit_depth_luma_minus8;
    unsigned int bit_depth_chroma_minus8;
    unsigned int log2_max_frame_num_minus4;
    unsigned int pic_order_cnt_type;
    unsigned int log2_max_pic_order_cnt_lsb_minus4;
    Boolean delta_pic_order_always_zero_flag;
    int offset_for_non_ref_pic;
    int offset_for_top_to_bottom_field;
    unsigned int num_ref_frames_in_pic_order_cnt_cycle;
    int offset_for_ref_frame[256];
    unsigned int num_ref_frames;
    Boolean gaps_in_frame_num_value_allowed_flag;
    unsigned int pic_width_in_mbs_minus1;
    unsigned int pic_height_in_map_units_minus1;
    Boolean frame_mbs_only_flag;
    Boolean mb_adaptive_frame_field_flag;
    Boolean direct_8x8_inference_flag;
    Boolean frame_cropping_flag;
    unsigned int frame_cropping_rect_left_offset;
    unsigned int frame_cropping_rect_right_offset;
    unsigned int frame_cropping_rect_top_offset;
    unsigned int frame_cropping_rect_bottom_offset;
    Boolean vui_parameters_present_flag;
    vui_seq_parameters_t vui_seq_parameters;
} seq_parameter_set_rbsp_t;

extern InputParameters *input;
extern seq_parameter_set_rbsp_t *sps;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with conditional early termination and simplified control flow
    // Focus on minimizing operations when AllowTransform8x8 is disabled

    // Early exit optimization
    if (!input->AllowTransform8x8) {
        for (i = 0; i < 6; i++) {
            sps->seq_scaling_list_present_flag[i] = input->ScalingListPresentFlag[i] & 1;
        }
        // Remaining indices are implicitly 0, but we explicitly set them once
        sps->seq_scaling_list_present_flag[6] = 0;
        sps->seq_scaling_list_present_flag[7] = 0;
        return;
    }

    // Full logic only when necessary
    for (i = 0; i < 8; i++) {
        sps->seq_scaling_list_present_flag[i] = input->ScalingListPresentFlag[i] & 1;
    }
}
