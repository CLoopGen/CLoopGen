#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int slice_type;
    int display_no;
    int reference_idc;
    int slice_qp;
    int pyramid_layer;
    int pyramidPocDelta;
} GOP_DATA;

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

GOP_DATA *gop_structure;
InputParameters *input;
int j;
int i;

void init_vars() {
    // Allocate and initialize input parameters
    input = (InputParameters*)calloc(1, sizeof(InputParameters));
    if (!input) exit(1);

    // Set data size to ensure ~0.01s runtime: moderate loop bounds
    input->successive_Bframe = 1000;

    // Allocate gop_structure with enough elements (j can go up to successive_Bframe)
    gop_structure = (GOP_DATA*)calloc(input->successive_Bframe + 1, sizeof(GOP_DATA));
    if (!gop_structure) exit(1);

    // Initialize gop_structure with descending pyramid_layer to trigger swaps
    for (int idx = 0; idx <= input->successive_Bframe; idx++) {
        gop_structure[idx].pyramid_layer = input->successive_Bframe - idx;
        gop_structure[idx].display_no = idx;
        gop_structure[idx].reference_idc = idx % 2;
        gop_structure[idx].slice_type = (idx == 0) ? 2 : 1;
        gop_structure[idx].slice_qp = 28 + (idx % 5);
        gop_structure[idx].pyramidPocDelta = idx * 2;
    }

    // Initialize other required fields in input
    input->img_width = 1920;
    input->img_height = 1080;
    input->FrameRate = 30.0;
    input->bit_rate = 5000000;
    input->qp0 = 28;
    input->intra_period = 30;
    input->PyramidCoding = 1;
    strcpy(input->infile, "input.yuv");
    strcpy(input->outfile, "output.264");

    // Initialize arrays that are accessed
    for (int k = 0; k < 8; k++) {
        input->blc_size[k][0] = 4 << (k / 2);
        input->blc_size[k][1] = 4 << (k / 2);
        input->part_size[k][0] = 4 << (k / 2);
        input->part_size[k][1] = 4 << (k / 2);
        input->ScalingListPresentFlag[k] = 0;
    }
    for (int k = 0; k < 6; k++) {
        input->LambdaWeight[k] = 1.0;
    }

    // Dummy allocation for pointer fields not used in loop but required to be non-null
    input->top_left = (int*)calloc(1, sizeof(int));
    input->bottom_right = (int*)calloc(1, sizeof(int));
    input->slice_group_id = (byte*)calloc(1, sizeof(byte));
    input->run_length_minus1 = (int*)calloc(1, sizeof(int));

    if (!input->top_left || !input->bottom_right || !input->slice_group_id || !input->run_length_minus1)
        exit(1);
}