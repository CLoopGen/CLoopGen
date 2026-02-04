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

extern InputParameters *input;
extern pic_parameter_set_rbsp_t *pps;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= pps->num_slice_groups_minus1; i++) {
        if (input->run_length_minus1[i] < 0) {
            continue;
        }
        pps->run_length_minus1[i] = input->run_length_minus1[i];
    }
}
