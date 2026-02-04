#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HEVCWindow {
    unsigned int left_offset;
    unsigned int right_offset;
    unsigned int top_offset;
    unsigned int bottom_offset;
} HEVCWindow;

enum AVPixelFormat {
    AV_PIX_FMT_NONE = -1,
    AV_PIX_FMT_YUV420P,
    AV_PIX_FMT_YUYV422,
    AV_PIX_FMT_RGB24,
    AV_PIX_FMT_BGR24,
    AV_PIX_FMT_YUV422P,
    AV_PIX_FMT_YUV444P,
    AV_PIX_FMT_YUV410P,
    AV_PIX_FMT_YUV411P,
    AV_PIX_FMT_GRAY8,
    AV_PIX_FMT_MONOWHITE,
    AV_PIX_FMT_MONOBLACK,
    AV_PIX_FMT_PAL8,
    AV_PIX_FMT_YUVJ420P,
    AV_PIX_FMT_YUVJ422P,
    AV_PIX_FMT_YUVJ444P,
    AV_PIX_FMT_UYVY422,
    AV_PIX_FMT_UYYVYY411,
    AV_PIX_FMT_BGR8,
    AV_PIX_FMT_BGR4,
    AV_PIX_FMT_BGR4_BYTE,
    AV_PIX_FMT_RGB8,
    AV_PIX_FMT_RGB4,
    AV_PIX_FMT_RGB4_BYTE,
    AV_PIX_FMT_NV12,
    AV_PIX_FMT_NV21,
    AV_PIX_FMT_ARGB,
    AV_PIX_FMT_RGBA,
    AV_PIX_FMT_ABGR,
    AV_PIX_FMT_BGRA,
    AV_PIX_FMT_GRAY16BE,
    AV_PIX_FMT_GRAY16LE,
    AV_PIX_FMT_YUV440P,
    AV_PIX_FMT_YUVJ440P,
    AV_PIX_FMT_YUVA420P,
    AV_PIX_FMT_RGB48BE,
    AV_PIX_FMT_RGB48LE,
    AV_PIX_FMT_RGB565BE,
    AV_PIX_FMT_RGB565LE,
    AV_PIX_FMT_RGB555BE,
    AV_PIX_FMT_RGB555LE,
    AV_PIX_FMT_BGR565BE,
    AV_PIX_FMT_BGR565LE,
    AV_PIX_FMT_BGR555BE,
    AV_PIX_FMT_BGR555LE,
    AV_PIX_FMT_VAAPI_MOCO,
    AV_PIX_FMT_VAAPI_IDCT,
    AV_PIX_FMT_VAAPI_VLD,
    AV_PIX_FMT_VAAPI = AV_PIX_FMT_VAAPI_VLD,
    AV_PIX_FMT_YUV420P16LE,
    AV_PIX_FMT_YUV420P16BE,
    AV_PIX_FMT_YUV422P16LE,
    AV_PIX_FMT_YUV422P16BE,
    AV_PIX_FMT_YUV444P16LE,
    AV_PIX_FMT_YUV444P16BE,
    AV_PIX_FMT_DXVA2_VLD,
    AV_PIX_FMT_RGB444LE,
    AV_PIX_FMT_RGB444BE,
    AV_PIX_FMT_BGR444LE,
    AV_PIX_FMT_BGR444BE,
    AV_PIX_FMT_YA8,
    AV_PIX_FMT_Y400A = AV_PIX_FMT_YA8,
    AV_PIX_FMT_GRAY8A = AV_PIX_FMT_YA8,
    AV_PIX_FMT_BGR48BE,
    AV_PIX_FMT_BGR48LE,
    AV_PIX_FMT_YUV420P9BE,
    AV_PIX_FMT_YUV420P9LE,
    AV_PIX_FMT_YUV420P10BE,
    AV_PIX_FMT_YUV420P10LE,
    AV_PIX_FMT_YUV422P10BE,
    AV_PIX_FMT_YUV422P10LE,
    AV_PIX_FMT_YUV444P9BE,
    AV_PIX_FMT_YUV444P9LE,
    AV_PIX_FMT_YUV444P10BE,
    AV_PIX_FMT_YUV444P10LE,
    AV_PIX_FMT_YUV422P9BE,
    AV_PIX_FMT_YUV422P9LE,
    AV_PIX_FMT_GBRP,
    AV_PIX_FMT_GBR24P = AV_PIX_FMT_GBRP,
    AV_PIX_FMT_GBRP9BE,
    AV_PIX_FMT_GBRP9LE,
    AV_PIX_FMT_GBRP10BE,
    AV_PIX_FMT_GBRP10LE,
    AV_PIX_FMT_GBRP16BE,
    AV_PIX_FMT_GBRP16LE,
    AV_PIX_FMT_YUVA422P,
    AV_PIX_FMT_YUVA444P,
    AV_PIX_FMT_YUVA420P9BE,
    AV_PIX_FMT_YUVA420P9LE,
    AV_PIX_FMT_YUVA422P9BE,
    AV_PIX_FMT_YUVA422P9LE,
    AV_PIX_FMT_YUVA444P9BE,
    AV_PIX_FMT_YUVA444P9LE,
    AV_PIX_FMT_YUVA420P10BE,
    AV_PIX_FMT_YUVA420P10LE,
    AV_PIX_FMT_YUVA422P10BE,
    AV_PIX_FMT_YUVA422P10LE,
    AV_PIX_FMT_YUVA444P10BE,
    AV_PIX_FMT_YUVA444P10LE,
    AV_PIX_FMT_YUVA420P16BE,
    AV_PIX_FMT_YUVA420P16LE,
    AV_PIX_FMT_YUVA422P16BE,
    AV_PIX_FMT_YUVA422P16LE,
    AV_PIX_FMT_YUVA444P16BE,
    AV_PIX_FMT_YUVA444P16LE,
    AV_PIX_FMT_VDPAU,
    AV_PIX_FMT_XYZ12LE,
    AV_PIX_FMT_XYZ12BE,
    AV_PIX_FMT_NV16,
    AV_PIX_FMT_NV20LE,
    AV_PIX_FMT_NV20BE,
    AV_PIX_FMT_RGBA64BE,
    AV_PIX_FMT_RGBA64LE,
    AV_PIX_FMT_BGRA64BE,
    AV_PIX_FMT_BGRA64LE,
    AV_PIX_FMT_YVYU422,
    AV_PIX_FMT_YA16BE,
    AV_PIX_FMT_YA16LE,
    AV_PIX_FMT_GBRAP,
    AV_PIX_FMT_GBRAP16BE,
    AV_PIX_FMT_GBRAP16LE,
    AV_PIX_FMT_QSV,
    AV_PIX_FMT_MMAL,
    AV_PIX_FMT_D3D11VA_VLD,
    AV_PIX_FMT_CUDA,
    AV_PIX_FMT_0RGB,
    AV_PIX_FMT_RGB0,
    AV_PIX_FMT_0BGR,
    AV_PIX_FMT_BGR0,
    AV_PIX_FMT_YUV420P12BE,
    AV_PIX_FMT_YUV420P12LE,
    AV_PIX_FMT_YUV420P14BE,
    AV_PIX_FMT_YUV420P14LE,
    AV_PIX_FMT_YUV422P12BE,
    AV_PIX_FMT_YUV422P12LE,
    AV_PIX_FMT_YUV422P14BE,
    AV_PIX_FMT_YUV422P14LE,
    AV_PIX_FMT_YUV444P12BE,
    AV_PIX_FMT_YUV444P12LE,
    AV_PIX_FMT_YUV444P14BE,
    AV_PIX_FMT_YUV444P14LE,
    AV_PIX_FMT_GBRP12BE,
    AV_PIX_FMT_GBRP12LE,
    AV_PIX_FMT_GBRP14BE,
    AV_PIX_FMT_GBRP14LE,
    AV_PIX_FMT_YUVJ411P,
    AV_PIX_FMT_BAYER_BGGR8,
    AV_PIX_FMT_BAYER_RGGB8,
    AV_PIX_FMT_BAYER_GBRG8,
    AV_PIX_FMT_BAYER_GRBG8,
    AV_PIX_FMT_BAYER_BGGR16LE,
    AV_PIX_FMT_BAYER_BGGR16BE,
    AV_PIX_FMT_BAYER_RGGB16LE,
    AV_PIX_FMT_BAYER_RGGB16BE,
    AV_PIX_FMT_BAYER_GBRG16LE,
    AV_PIX_FMT_BAYER_GBRG16BE,
    AV_PIX_FMT_BAYER_GRBG16LE,
    AV_PIX_FMT_BAYER_GRBG16BE,
    AV_PIX_FMT_XVMC,
    AV_PIX_FMT_YUV440P10LE,
    AV_PIX_FMT_YUV440P10BE,
    AV_PIX_FMT_YUV440P12LE,
    AV_PIX_FMT_YUV440P12BE,
    AV_PIX_FMT_AYUV64LE,
    AV_PIX_FMT_AYUV64BE,
    AV_PIX_FMT_VIDEOTOOLBOX,
    AV_PIX_FMT_P010LE,
    AV_PIX_FMT_P010BE,
    AV_PIX_FMT_GBRAP12BE,
    AV_PIX_FMT_GBRAP12LE,
    AV_PIX_FMT_GBRAP10BE,
    AV_PIX_FMT_GBRAP10LE,
    AV_PIX_FMT_MEDIACODEC,
    AV_PIX_FMT_GRAY12BE,
    AV_PIX_FMT_GRAY12LE,
    AV_PIX_FMT_GRAY10BE,
    AV_PIX_FMT_GRAY10LE,
    AV_PIX_FMT_P016LE,
    AV_PIX_FMT_P016BE,
    AV_PIX_FMT_D3D11,
    AV_PIX_FMT_GRAY9BE,
    AV_PIX_FMT_GRAY9LE,
    AV_PIX_FMT_GBRPF32BE,
    AV_PIX_FMT_GBRPF32LE,
    AV_PIX_FMT_GBRAPF32BE,
    AV_PIX_FMT_GBRAPF32LE,
    AV_PIX_FMT_DRM_PRIME,
    AV_PIX_FMT_OPENCL,
    AV_PIX_FMT_GRAY14BE,
    AV_PIX_FMT_GRAY14LE,
    AV_PIX_FMT_GRAYF32BE,
    AV_PIX_FMT_GRAYF32LE,
    AV_PIX_FMT_YUVA422P12BE,
    AV_PIX_FMT_YUVA422P12LE,
    AV_PIX_FMT_YUVA444P12BE,
    AV_PIX_FMT_YUVA444P12LE,
    AV_PIX_FMT_NV24,
    AV_PIX_FMT_NV42,
    AV_PIX_FMT_VULKAN,
    AV_PIX_FMT_Y210BE,
    AV_PIX_FMT_Y210LE,
    AV_PIX_FMT_NB
};

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct VUI {
    AVRational sar;
    int overscan_info_present_flag;
    int overscan_appropriate_flag;
    int video_signal_type_present_flag;
    int video_format;
    int video_full_range_flag;
    int colour_description_present_flag;
    uint8_t colour_primaries;
    uint8_t transfer_characteristic;
    uint8_t matrix_coeffs;
    int chroma_loc_info_present_flag;
    int chroma_sample_loc_type_top_field;
    int chroma_sample_loc_type_bottom_field;
    int neutra_chroma_indication_flag;
    int field_seq_flag;
    int frame_field_info_present_flag;
    int default_display_window_flag;
    HEVCWindow def_disp_win;
    int vui_timing_info_present_flag;
    uint32_t vui_num_units_in_tick;
    uint32_t vui_time_scale;
    int vui_poc_proportional_to_timing_flag;
    int vui_num_ticks_poc_diff_one_minus1;
    int vui_hrd_parameters_present_flag;
    int bitstream_restriction_flag;
    int tiles_fixed_structure_flag;
    int motion_vectors_over_pic_boundaries_flag;
    int restricted_ref_pic_lists_flag;
    int min_spatial_segmentation_idc;
    int max_bytes_per_pic_denom;
    int max_bits_per_min_cu_denom;
    int log2_max_mv_length_horizontal;
    int log2_max_mv_length_vertical;
} VUI;

typedef struct PTLCommon {
    uint8_t profile_space;
    uint8_t tier_flag;
    uint8_t profile_idc;
    uint8_t profile_compatibility_flag[32];
    uint8_t progressive_source_flag;
    uint8_t interlaced_source_flag;
    uint8_t non_packed_constraint_flag;
    uint8_t frame_only_constraint_flag;
    uint8_t max_12bit_constraint_flag;
    uint8_t max_10bit_constraint_flag;
    uint8_t max_8bit_constraint_flag;
    uint8_t max_422chroma_constraint_flag;
    uint8_t max_420chroma_constraint_flag;
    uint8_t max_monochrome_constraint_flag;
    uint8_t intra_constraint_flag;
    uint8_t one_picture_only_constraint_flag;
    uint8_t lower_bit_rate_constraint_flag;
    uint8_t max_14bit_constraint_flag;
    uint8_t inbld_flag;
    uint8_t level_idc;
} PTLCommon;

typedef struct PTL {
    PTLCommon general_ptl;
    PTLCommon sub_layer_ptl[7];
    uint8_t sub_layer_profile_present_flag[7];
    uint8_t sub_layer_level_present_flag[7];
} PTL;

typedef struct ScalingList {
    uint8_t sl[4][6][64];
    uint8_t sl_dc[2][6];
} ScalingList;

typedef struct ShortTermRPS {
    unsigned int num_negative_pics;
    int num_delta_pocs;
    int rps_idx_num_delta_pocs;
    int32_t delta_poc[32];
    uint8_t used[32];
} ShortTermRPS;

enum HEVCSliceType {
    HEVC_SLICE_B = 0,
    HEVC_SLICE_P = 1,
    HEVC_SLICE_I = 2
};

typedef struct LongTermRPS {
    int poc[32];
    uint8_t poc_msb_present[32];
    uint8_t used[32];
    uint8_t nb_refs;
} LongTermRPS;

typedef struct SliceHeader {
    unsigned int pps_id;
    unsigned int slice_segment_addr;
    unsigned int slice_addr;
    enum HEVCSliceType slice_type;
    int pic_order_cnt_lsb;
    uint8_t first_slice_in_pic_flag;
    uint8_t dependent_slice_segment_flag;
    uint8_t pic_output_flag;
    uint8_t colour_plane_id;
    int short_term_ref_pic_set_sps_flag;
    int short_term_ref_pic_set_size;
    ShortTermRPS slice_rps;
    const ShortTermRPS *short_term_rps;
    int long_term_ref_pic_set_size;
    LongTermRPS long_term_rps;
    unsigned int list_entry_lx[2][32];
    uint8_t rpl_modification_flag[2];
    uint8_t no_output_of_prior_pics_flag;
    uint8_t slice_temporal_mvp_enabled_flag;
    unsigned int nb_refs[2];
    uint8_t slice_sample_adaptive_offset_flag[3];
    uint8_t mvd_l1_zero_flag;
    uint8_t cabac_init_flag;
    uint8_t disable_deblocking_filter_flag;
    uint8_t slice_loop_filter_across_slices_enabled_flag;
    uint8_t collocated_list;
    unsigned int collocated_ref_idx;
    int slice_qp_delta;
    int slice_cb_qp_offset;
    int slice_cr_qp_offset;
    uint8_t cu_chroma_qp_offset_enabled_flag;
    int beta_offset;
    int tc_offset;
    unsigned int max_num_merge_cand;
    unsigned int *entry_point_offset;
    int *offset;
    int *size;
    int num_entry_point_offsets;
    int8_t slice_qp;
    uint8_t luma_log2_weight_denom;
    int16_t chroma_log2_weight_denom;
    int16_t luma_weight_l0[16];
    int16_t chroma_weight_l0[16][2];
    int16_t chroma_weight_l1[16][2];
    int16_t luma_weight_l1[16];
    int16_t luma_offset_l0[16];
    int16_t chroma_offset_l0[16][2];
    int16_t luma_offset_l1[16];
    int16_t chroma_offset_l1[16][2];
    int slice_ctb_addr_rs;
} SliceHeader;

typedef struct HEVCSPS {
    unsigned int vps_id;
    int chroma_format_idc;
    uint8_t separate_colour_plane_flag;
    HEVCWindow output_window;
    HEVCWindow pic_conf_win;
    int bit_depth;
    int bit_depth_chroma;
    int pixel_shift;
    enum AVPixelFormat pix_fmt;
    unsigned int log2_max_poc_lsb;
    int pcm_enabled_flag;
    int max_sub_layers;
    struct {
        int max_dec_pic_buffering;
        int num_reorder_pics;
        int max_latency_increase;
    } temporal_layer[7];
    uint8_t temporal_id_nesting_flag;
    VUI vui;
    PTL ptl;
    uint8_t scaling_list_enable_flag;
    ScalingList scaling_list;
    unsigned int nb_st_rps;
    ShortTermRPS st_rps[64];
    uint8_t amp_enabled_flag;
    uint8_t sao_enabled;
    uint8_t long_term_ref_pics_present_flag;
    uint16_t lt_ref_pic_poc_lsb_sps[32];
    uint8_t used_by_curr_pic_lt_sps_flag[32];
    uint8_t num_long_term_ref_pics_sps;
    struct {
        uint8_t bit_depth;
        uint8_t bit_depth_chroma;
        unsigned int log2_min_pcm_cb_size;
        unsigned int log2_max_pcm_cb_size;
        uint8_t loop_filter_disable_flag;
    } pcm;
    uint8_t sps_temporal_mvp_enabled_flag;
    uint8_t sps_strong_intra_smoothing_enable_flag;
    unsigned int log2_min_cb_size;
    unsigned int log2_diff_max_min_coding_block_size;
    unsigned int log2_min_tb_size;
    unsigned int log2_max_trafo_size;
    unsigned int log2_ctb_size;
    unsigned int log2_min_pu_size;
    int max_transform_hierarchy_depth_inter;
    int max_transform_hierarchy_depth_intra;
    int sps_range_extension_flag;
    int transform_skip_rotation_enabled_flag;
    int transform_skip_context_enabled_flag;
    int implicit_rdpcm_enabled_flag;
    int explicit_rdpcm_enabled_flag;
    int extended_precision_processing_flag;
    int intra_smoothing_disabled_flag;
    int high_precision_offsets_enabled_flag;
    int persistent_rice_adaptation_enabled_flag;
    int cabac_bypass_alignment_enabled_flag;
    int width;
    int height;
    int ctb_width;
    int ctb_height;
    int ctb_size;
    int min_cb_width;
    int min_cb_height;
    int min_tb_width;
    int min_tb_height;
    int min_pu_width;
    int min_pu_height;
    int tb_mask;
    int hshift[3];
    int vshift[3];
    int qp_bd_offset;
    uint8_t data[4096];
    int data_size;
} HEVCSPS;

HEVCSPS *sps;
SliceHeader *sh;

void init_vars() {
    sps = (HEVCSPS*)calloc(1, sizeof(HEVCSPS));
    sh = (SliceHeader*)calloc(1, sizeof(SliceHeader));

    sps->nb_st_rps = 64;
    for (int i = 0; i < 64; i++) {
        sps->st_rps[i].num_delta_pocs = i + 1;
    }

    sh->short_term_rps = &sps->st_rps[32];

    sps->pix_fmt = AV_PIX_FMT_YUV420P;
    sps->bit_depth = 8;
    sps->bit_depth_chroma = 8;
    sps->pixel_shift = 0;
    sps->log2_max_poc_lsb = 16;
    sps->pcm_enabled_flag = 0;
    sps->max_sub_layers = 7;
    sps->temporal_id_nesting_flag = 1;
    sps->scaling_list_enable_flag = 1;
    sps->amp_enabled_flag = 1;
    sps->sao_enabled = 1;
    sps->long_term_ref_pics_present_flag = 0;
    sps->num_long_term_ref_pics_sps = 0;
    sps->sps_temporal_mvp_enabled_flag = 1;
    sps->sps_strong_intra_smoothing_enable_flag = 1;
    sps->log2_min_cb_size = 4;
    sps->log2_diff_max_min_coding_block_size = 4;
    sps->log2_min_tb_size = 2;
    sps->log2_max_trafo_size = 5;
    sps->log2_ctb_size = 6;
    sps->log2_min_pu_size = 2;
    sps->max_transform_hierarchy_depth_inter = 3;
    sps->max_transform_hierarchy_depth_intra = 3;
    sps->width = 1920;
    sps->height = 1080;
    sps->ctb_width = sps->width >> sps->log2_ctb_size;
    sps->ctb_height = sps->height >> sps->log2_ctb_size;
    sps->ctb_size = 1 << sps->log2_ctb_size;
    sps->min_cb_width = sps->width >> sps->log2_diff_max_min_coding_block_size;
    sps->min_cb_height = sps->height >> sps->log2_diff_max_min_coding_block_size;
    sps->min_tb_width = 1 << sps->log2_min_tb_size;
    sps->min_tb_height = 1 << sps->log2_min_tb_size;
    sps->min_pu_width = 1 << sps->log2_min_pu_size;
    sps->min_pu_height = 1 << sps->log2_min_pu_size;
    sps->tb_mask = (1 << (sps->log2_max_trafo_size - sps->log2_min_tb_size)) - 1;
    sps->hshift[0] = 0; sps->hshift[1] = 1; sps->hshift[2] = 1;
    sps->vshift[0] = 0; sps->vshift[1] = 1; sps->vshift[2] = 1;
    sps->qp_bd_offset = 6 * (sps->bit_depth - 8);

    sps->data_size = 4096;

    sh->slice_type = HEVC_SLICE_P;
    sh->pic_order_cnt_lsb = 12345;
    sh->first_slice_in_pic_flag = 1;
    sh->dependent_slice_segment_flag = 0;
    sh->pic_output_flag = 1;
    sh->colour_plane_id = 0;
    sh->short_term_ref_pic_set_sps_flag = 1;
    sh->short_term_ref_pic_set_size = 10;
    sh->long_term_ref_pic_set_size = 0;
    sh->rpl_modification_flag[0] = 0;
    sh->rpl_modification_flag[1] = 0;
    sh->no_output_of_prior_pics_flag = 0;
    sh->slice_temporal_mvp_enabled_flag = 1;
    sh->nb_refs[0] = 3;
    sh->nb_refs[1] = 2;
    sh->slice_sample_adaptive_offset_flag[0] = 1;
    sh->slice_sample_adaptive_offset_flag[1] = 1;
    sh->slice_sample_adaptive_offset_flag[2] = 0;
    sh->mvd_l1_zero_flag = 1;
    sh->cabac_init_flag = 0;
    sh->disable_deblocking_filter_flag = 0;
    sh->slice_loop_filter_across_slices_enabled_flag = 1;
    sh->collocated_list = 0;
    sh->collocated_ref_idx = 1;
    sh->slice_qp_delta = 2;
    sh->slice_cb_qp_offset = 1;
    sh->slice_cr_qp_offset = -1;
    sh->cu_chroma_qp_offset_enabled_flag = 1;
    sh->beta_offset = 0;
    sh->tc_offset = 0;
    sh->max_num_merge_cand = 5;
    sh->num_entry_point_offsets = 0;
    sh->slice_qp = 28;
    sh->luma_log2_weight_denom = 5;
    sh->chroma_log2_weight_denom = 4;
    for (int i = 0; i < 16; i++) {
        sh->luma_weight_l0[i] = 32;
        sh->luma_weight_l1[i] = 32;
        sh->luma_offset_l0[i] = 0;
        sh->luma_offset_l1[i] = 0;
        for (int j = 0; j < 2; j++) {
            sh->chroma_weight_l0[i][j] = 32;
            sh->chroma_weight_l1[i][j] = 32;
            sh->chroma_offset_l0[i][j] = 0;
            sh->chroma_offset_l1[i][j] = 0;
        }
    }
    sh->slice_ctb_addr_rs = 100;

    sps->vui.sar.num = 1;
    sps->vui.sar.den = 1;
    sps->vui.overscan_info_present_flag = 0;
    sps->vui.video_signal_type_present_flag = 1;
    sps->vui.video_format = 5;
    sps->vui.colour_description_present_flag = 1;
    sps->vui.colour_primaries = 1;
    sps->vui.transfer_characteristic = 1;
    sps->vui.matrix_coeffs = 1;
    sps->vui.chroma_loc_info_present_flag = 1;
    sps->vui.chroma_sample_loc_type_top_field = 0;
    sps->vui.chroma_sample_loc_type_bottom_field = 0;
    sps->vui.neutra_chroma_indication_flag = 1;
    sps->vui.field_seq_flag = 0;
    sps->vui.frame_field_info_present_flag = 1;
    sps->vui.default_display_window_flag = 1;
    sps->vui.def_disp_win.left_offset = 0;
    sps->vui.def_disp_win.right_offset = 0;
    sps->vui.def_disp_win.top_offset = 0;
    sps->vui.def_disp_win.bottom_offset = 0;
    sps->vui.vui_timing_info_present_flag = 1;
    sps->vui.vui_num_units_in_tick = 1000;
    sps->vui.vui_time_scale = 60000;
    sps->vui.vui_poc_proportional_to_timing_flag = 0;
    sps->vui.vui_num_ticks_poc_diff_one_minus1 = 0;
    sps->vui.bitstream_restriction_flag = 1;
    sps->vui.tiles_fixed_structure_flag = 0;
    sps->vui.motion_vectors_over_pic_boundaries_flag = 1;
    sps->vui.restricted_ref_pic_lists_flag = 0;
    sps->vui.min_spatial_segmentation_idc = 0;
    sps->vui.max_bytes_per_pic_denom = 2;
    sps->vui.max_bits_per_min_cu_denom = 1;
    sps->vui.log2_max_mv_length_horizontal = 15;
    sps->vui.log2_max_mv_length_vertical = 15;

    sps->ptl.general_ptl.profile_idc = 1;
    sps->ptl.general_ptl.tier_flag = 0;
    sps->ptl.general_ptl.level_idc = 120;
    for (int i = 0; i < 32; i++) {
        sps->ptl.general_ptl.profile_compatibility_flag[i] = (i == 1) ? 1 : 0;
    }

    for (int i = 0; i < 7; i++) {
        sps->temporal_layer[i].max_dec_pic_buffering = 4 + i;
        sps->temporal_layer[i].num_reorder_pics = 2 + i;
        sps->temporal_layer[i].max_latency_increase = 1000;
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 64; k++)
                sps->scaling_list.sl[i][j][k] = 16;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 6; j++)
            sps->scaling_list.sl_dc[i][j] = 16;

    sps->pcm.bit_depth = 8;
    sps->pcm.bit_depth_chroma = 8;
    sps->pcm.log2_min_pcm_cb_size = 3;
    sps->pcm.log2_max_pcm_cb_size = 4;
    sps->pcm.loop_filter_disable_flag = 0;

    sps->output_window.left_offset = 0;
    sps->output_window.right_offset = 0;
    sps->output_window.top_offset = 0;
    sps->output_window.bottom_offset = 0;
    sps->pic_conf_win = sps->output_window;
}