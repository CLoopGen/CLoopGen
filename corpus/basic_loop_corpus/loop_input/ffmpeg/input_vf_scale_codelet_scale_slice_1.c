#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVPictureType {
    AV_PICTURE_TYPE_NONE = 0,
    AV_PICTURE_TYPE_I,
    AV_PICTURE_TYPE_P,
    AV_PICTURE_TYPE_B,
    AV_PICTURE_TYPE_S,
    AV_PICTURE_TYPE_SI,
    AV_PICTURE_TYPE_SP,
    AV_PICTURE_TYPE_BI
};

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

enum AVFrameSideDataType {
    AV_FRAME_DATA_PANSCAN,
    AV_FRAME_DATA_A53_CC,
    AV_FRAME_DATA_STEREO3D,
    AV_FRAME_DATA_MATRIXENCODING,
    AV_FRAME_DATA_DOWNMIX_INFO,
    AV_FRAME_DATA_REPLAYGAIN,
    AV_FRAME_DATA_DISPLAYMATRIX,
    AV_FRAME_DATA_AFD,
    AV_FRAME_DATA_MOTION_VECTORS,
    AV_FRAME_DATA_SKIP_SAMPLES,
    AV_FRAME_DATA_AUDIO_SERVICE_TYPE,
    AV_FRAME_DATA_MASTERING_DISPLAY_METADATA,
    AV_FRAME_DATA_GOP_TIMECODE,
    AV_FRAME_DATA_SPHERICAL,
    AV_FRAME_DATA_CONTENT_LIGHT_LEVEL,
    AV_FRAME_DATA_ICC_PROFILE,
    AV_FRAME_DATA_QP_TABLE_PROPERTIES,
    AV_FRAME_DATA_QP_TABLE_DATA,
    AV_FRAME_DATA_S12M_TIMECODE,
    AV_FRAME_DATA_DYNAMIC_HDR_PLUS,
    AV_FRAME_DATA_REGIONS_OF_INTEREST,
    AV_FRAME_DATA_VIDEO_ENC_PARAMS
};

typedef struct AVDictionary AVDictionary;

typedef struct AVFrameSideData {
    enum AVFrameSideDataType type;
    uint8_t *data;
    int size;
    AVDictionary *metadata;
    AVBufferRef *buf;
} AVFrameSideData;

enum AVColorRange {
    AVCOL_RANGE_UNSPECIFIED = 0,
    AVCOL_RANGE_MPEG = 1,
    AVCOL_RANGE_JPEG = 2,
    AVCOL_RANGE_NB
};

enum AVColorPrimaries {
    AVCOL_PRI_RESERVED0 = 0,
    AVCOL_PRI_BT709 = 1,
    AVCOL_PRI_UNSPECIFIED = 2,
    AVCOL_PRI_RESERVED = 3,
    AVCOL_PRI_BT470M = 4,
    AVCOL_PRI_BT470BG = 5,
    AVCOL_PRI_SMPTE170M = 6,
    AVCOL_PRI_SMPTE240M = 7,
    AVCOL_PRI_FILM = 8,
    AVCOL_PRI_BT2020 = 9,
    AVCOL_PRI_SMPTE428 = 10,
    AVCOL_PRI_SMPTEST428_1 = AVCOL_PRI_SMPTE428,
    AVCOL_PRI_SMPTE431 = 11,
    AVCOL_PRI_SMPTE432 = 12,
    AVCOL_PRI_EBU3213 = 22,
    AVCOL_PRI_JEDEC_P22 = AVCOL_PRI_EBU3213,
    AVCOL_PRI_NB
};

enum AVColorTransferCharacteristic {
    AVCOL_TRC_RESERVED0 = 0,
    AVCOL_TRC_BT709 = 1,
    AVCOL_TRC_UNSPECIFIED = 2,
    AVCOL_TRC_RESERVED = 3,
    AVCOL_TRC_GAMMA22 = 4,
    AVCOL_TRC_GAMMA28 = 5,
    AVCOL_TRC_SMPTE170M = 6,
    AVCOL_TRC_SMPTE240M = 7,
    AVCOL_TRC_LINEAR = 8,
    AVCOL_TRC_LOG = 9,
    AVCOL_TRC_LOG_SQRT = 10,
    AVCOL_TRC_IEC61966_2_4 = 11,
    AVCOL_TRC_BT1361_ECG = 12,
    AVCOL_TRC_IEC61966_2_1 = 13,
    AVCOL_TRC_BT2020_10 = 14,
    AVCOL_TRC_BT2020_12 = 15,
    AVCOL_TRC_SMPTE2084 = 16,
    AVCOL_TRC_SMPTEST2084 = AVCOL_TRC_SMPTE2084,
    AVCOL_TRC_SMPTE428 = 17,
    AVCOL_TRC_SMPTEST428_1 = AVCOL_TRC_SMPTE428,
    AVCOL_TRC_ARIB_STD_B67 = 18,
    AVCOL_TRC_NB
};

enum AVColorSpace {
    AVCOL_SPC_RGB = 0,
    AVCOL_SPC_BT709 = 1,
    AVCOL_SPC_UNSPECIFIED = 2,
    AVCOL_SPC_RESERVED = 3,
    AVCOL_SPC_FCC = 4,
    AVCOL_SPC_BT470BG = 5,
    AVCOL_SPC_SMPTE170M = 6,
    AVCOL_SPC_SMPTE240M = 7,
    AVCOL_SPC_YCGCO = 8,
    AVCOL_SPC_YCOCG = AVCOL_SPC_YCGCO,
    AVCOL_SPC_BT2020_NCL = 9,
    AVCOL_SPC_BT2020_CL = 10,
    AVCOL_SPC_SMPTE2085 = 11,
    AVCOL_SPC_CHROMA_DERIVED_NCL = 12,
    AVCOL_SPC_CHROMA_DERIVED_CL = 13,
    AVCOL_SPC_ICTCP = 14,
    AVCOL_SPC_NB
};

enum AVChromaLocation {
    AVCHROMA_LOC_UNSPECIFIED = 0,
    AVCHROMA_LOC_LEFT = 1,
    AVCHROMA_LOC_CENTER = 2,
    AVCHROMA_LOC_TOPLEFT = 3,
    AVCHROMA_LOC_TOP = 4,
    AVCHROMA_LOC_BOTTOMLEFT = 5,
    AVCHROMA_LOC_BOTTOM = 6,
    AVCHROMA_LOC_NB
};

typedef struct SwsContext SwsContext;

typedef struct AVClass {
    const char *class_name;
    const char *(*item_name)(void *);
    const struct AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    enum { AV_CLASS_CATEGORY_NA = 0, AV_CLASS_CATEGORY_INPUT, AV_CLASS_CATEGORY_OUTPUT, AV_CLASS_CATEGORY_MUXER, AV_CLASS_CATEGORY_DEMUXER, AV_CLASS_CATEGORY_ENCODER, AV_CLASS_CATEGORY_DECODER, AV_CLASS_CATEGORY_FILTER, AV_CLASS_CATEGORY_BITSTREAM_FILTER, AV_CLASS_CATEGORY_SWSCALER, AV_CLASS_CATEGORY_SWRESAMPLER, AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40, AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT, AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT, AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT, AV_CLASS_CATEGORY_DEVICE_OUTPUT, AV_CLASS_CATEGORY_DEVICE_INPUT, AV_CLASS_CATEGORY_NB } category;
    enum AVClassCategory (*get_category)(void *);
    int (*query_ranges)(struct AVOptionRanges **, void *, const char *, int);
} AVClass;

typedef struct ScaleContext {
    const AVClass *class;
    struct SwsContext *sws;
    struct SwsContext *isws[2];
    struct AVDictionary *opts;
    int w;
    int h;
    char *size_str;
    unsigned int flags;
    double param[2];
    int hsub;
    int vsub;
    int slice_y;
    int input_is_pal;
    int output_is_pal;
    int interlaced;
    char *w_expr;
    char *h_expr;
    struct AVExpr *w_pexpr;
    struct AVExpr *h_pexpr;
    double var_values[29];
    char *flags_str;
    char *in_color_matrix;
    char *out_color_matrix;
    int in_range;
    int out_range;
    int out_h_chr_pos;
    int out_v_chr_pos;
    int in_h_chr_pos;
    int in_v_chr_pos;
    int force_original_aspect_ratio;
    int force_divisible_by;
    int nb_slices;
    int eval_mode;
} ScaleContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    uint8_t **extended_data;
    int width;
    int height;
    int nb_samples;
    int format;
    int key_frame;
    enum AVPictureType pict_type;
    AVRational sample_aspect_ratio;
    int64_t pts;
    int64_t pkt_pts;
    int64_t pkt_dts;
    int coded_picture_number;
    int display_picture_number;
    int quality;
    void *opaque;
    uint64_t error[8];
    int repeat_pict;
    int interlaced_frame;
    int top_field_first;
    int palette_has_changed;
    int64_t reordered_opaque;
    int sample_rate;
    uint64_t channel_layout;
    AVBufferRef *buf[8];
    AVBufferRef **extended_buf;
    int nb_extended_buf;
    AVFrameSideData **side_data;
    int nb_side_data;
    int flags;
    enum AVColorRange color_range;
    enum AVColorPrimaries color_primaries;
    enum AVColorTransferCharacteristic color_trc;
    enum AVColorSpace colorspace;
    enum AVChromaLocation chroma_location;
    int64_t best_effort_timestamp;
    int64_t pkt_pos;
    int64_t pkt_duration;
    struct AVDictionary *metadata;
    int decode_error_flags;
    int channels;
    int pkt_size;
    int8_t *qscale_table;
    int qstride;
    int qscale_type;
    AVBufferRef *qp_table_buf;
    AVBufferRef *hw_frames_ctx;
    AVBufferRef *opaque_ref;
    size_t crop_top;
    size_t crop_bottom;
    size_t crop_left;
    size_t crop_right;
    AVBufferRef *private_ref;
} AVFrame;

AVFrame *out_buf;
AVFrame *cur_pic;
int y;
int mul;
int field;
ScaleContext *scale;
uint8_t *in[4];
uint8_t *out[4];
int in_stride[4];
int out_stride[4];
int i;

static AVClass av_class = { .class_name = "scale" };
static uint8_t *input_data[8];
static uint8_t *output_data[8];
static int data_size = 64 * 1024 * 1024 / 8; // ~64MB total across planes

void init_vars() {
    scale = (ScaleContext *)calloc(1, sizeof(ScaleContext));
    if (!scale) return;
    
    scale->class = &av_class;
    scale->vsub = 1;
    scale->hsub = 1;
    scale->w = 1920;
    scale->h = 1080;

    cur_pic = (AVFrame *)calloc(1, sizeof(AVFrame));
    out_buf = (AVFrame *)calloc(1, sizeof(AVFrame));
    if (!cur_pic || !out_buf) return;

    for (int p = 0; p < 4; p++) {
        int h_factor = (p == 1 || p == 2) ? (1 << scale->vsub) : 1;
        int w_factor = (p == 1 || p == 2) ? (1 << scale->hsub) : 1;
        int plane_width = (scale->w + w_factor - 1) / w_factor;
        int plane_height = (scale->h + h_factor - 1) / h_factor;
        int bytes_per_pixel = 1;
        int stride = plane_width * bytes_per_pixel;
        int size = stride * plane_height;

        if (size > data_size) size = data_size;

        input_data[p] = (uint8_t *)calloc(size, 1);
        output_data[p] = (uint8_t *)calloc(size, 1);

        cur_pic->data[p] = input_data[p];
        cur_pic->linesize[p] = stride;
        out_buf->data[p] = output_data[p];
        out_buf->linesize[p] = stride;
    }

    cur_pic->width = scale->w;
    cur_pic->height = scale->h;
    out_buf->width = scale->w;
    out_buf->height = scale->h;

    y = 10;
    mul = 1;
    field = 1;

    in[0] = NULL;
    in[1] = NULL;
    in[2] = NULL;
    in[3] = NULL;
    out[0] = NULL;
    out[1] = NULL;
    out[2] = NULL;
    out[3] = NULL;
    in_stride[0] = 0;
    in_stride[1] = 0;
    in_stride[2] = 0;
    in_stride[3] = 0;
    out_stride[0] = 0;
    out_stride[1] = 0;
    out_stride[2] = 0;
    out_stride[3] = 0;
}