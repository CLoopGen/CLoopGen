#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVOptionType {
    AV_OPT_TYPE_FLAGS,
    AV_OPT_TYPE_INT,
    AV_OPT_TYPE_INT64,
    AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT,
    AV_OPT_TYPE_STRING,
    AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY,
    AV_OPT_TYPE_DICT,
    AV_OPT_TYPE_UINT64,
    AV_OPT_TYPE_CONST,
    AV_OPT_TYPE_IMAGE_SIZE,
    AV_OPT_TYPE_PIXEL_FMT,
    AV_OPT_TYPE_SAMPLE_FMT,
    AV_OPT_TYPE_VIDEO_RATE,
    AV_OPT_TYPE_DURATION,
    AV_OPT_TYPE_COLOR,
    AV_OPT_TYPE_CHANNEL_LAYOUT,
    AV_OPT_TYPE_BOOL
};

typedef struct AVRational {
    int num;
    int den;
} AVRational;

union av_default_val {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
};

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    union av_default_val default_val;
    double min;
    double max;
    int flags;
    const char *unit;
};

typedef enum {
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_INPUT,
    AV_CLASS_CATEGORY_NB
} AVClassCategory;

struct AVOptionRanges;

typedef struct AVClass {
    const char *class_name;
    const char *(*item_name)(void *);
    const struct AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *);
    int (*query_ranges)(struct AVOptionRanges **, void *, const char *, int);
} AVClass;

typedef struct AVMotionEstPredictor {
    int mvs[10][2];
    int nb;
} AVMotionEstPredictor;

typedef struct AVMotionEstContext {
    uint8_t *data_cur;
    uint8_t *data_ref;
    int linesize;
    int mb_size;
    int search_param;
    int width;
    int height;
    int x_min;
    int x_max;
    int y_min;
    int y_max;
    int pred_x;
    int pred_y;
    AVMotionEstPredictor preds[2];
    uint64_t (*get_cost)(struct AVMotionEstContext *, int, int, int, int);
} AVMotionEstContext;

enum MIMode {
    MI_MODE_DUP = 0,
    MI_MODE_BLEND = 1,
    MI_MODE_MCI = 2
};

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
    AVDictionary *metadata;
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

typedef struct Block {
    int16_t mvs[2][2];
    int cid;
    uint64_t sbad;
    int sb;
    struct Block *subs;
} Block;

typedef struct Frame {
    AVFrame *avf;
    Block *blocks;
} Frame;

typedef struct Cluster {
    int64_t sum[2];
    int nb;
} Cluster;

typedef struct PixelMVS {
    int16_t mvs[32][2];
} PixelMVS;

typedef struct PixelWeights {
    uint32_t weights[32];
} PixelWeights;

typedef struct PixelRefs {
    int8_t refs[32];
    int nb;
} PixelRefs;

typedef void (*ff_scene_sad_fn)(const uint8_t *, ptrdiff_t, const uint8_t *, ptrdiff_t, ptrdiff_t, ptrdiff_t, uint64_t *);

typedef struct MIContext {
    const struct AVClass *class;
    AVMotionEstContext me_ctx;
    AVRational frame_rate;
    enum MIMode mi_mode;
    int mc_mode;
    int me_mode;
    int me_method;
    int mb_size;
    int search_param;
    int vsbmc;
    Frame frames[4];
    Cluster clusters[128];
    Block *int_blocks;
    PixelMVS *pixel_mvs;
    PixelWeights *pixel_weights;
    PixelRefs *pixel_refs;
    int (*mv_table[3])[2][2];
    int64_t out_pts;
    int b_width;
    int b_height;
    int b_count;
    int log2_mb_size;
    int bitdepth;
    int scd_method;
    int scene_changed;
    ff_scene_sad_fn sad;
    double prev_mafd;
    double scd_threshold;
    int log2_chroma_w;
    int log2_chroma_h;
    int nb_planes;
} MIContext;

static AVClass av_class_instance = { .class_name = "test_class" };

static uint8_t *alloc_plane(int w, int h) {
    return (uint8_t *)calloc(w * h, sizeof(uint8_t));
}

static void init_avframe(AVFrame *frame, int width, int height) {
    frame->width = width;
    frame->height = height;
    frame->nb_samples = 0;
    frame->format = 0;
    frame->key_frame = 1;
    frame->pict_type = AV_PICTURE_TYPE_I;
    frame->sample_aspect_ratio.num = 1;
    frame->sample_aspect_ratio.den = 1;
    frame->pts = 0;
    frame->pkt_dts = 0;
    frame->coded_picture_number = 0;
    frame->display_picture_number = 0;
    frame->quality = 1;
    frame->repeat_pict = 0;
    frame->interlaced_frame = 0;
    frame->top_field_first = 0;
    frame->palette_has_changed = 0;
    frame->reordered_opaque = 0;
    frame->sample_rate = 0;
    frame->channel_layout = 0;
    frame->nb_extended_buf = 0;
    frame->extended_buf = NULL;
    frame->nb_side_data = 0;
    frame->side_data = NULL;
    frame->flags = 0;
    frame->color_range = AVCOL_RANGE_MPEG;
    frame->color_primaries = AVCOL_PRI_BT709;
    frame->color_trc = AVCOL_TRC_BT709;
    frame->colorspace = AVCOL_SPC_BT709;
    frame->chroma_location = AVCHROMA_LOC_CENTER;
    frame->best_effort_timestamp = 0;
    frame->pkt_pos = -1;
    frame->pkt_duration = 0;
    frame->decode_error_flags = 0;
    frame->channels = 0;
    frame->pkt_size = 0;
    frame->qscale_table = NULL;
    frame->qstride = 0;
    frame->qscale_type = 0;
    frame->qp_table_buf = NULL;
    frame->hw_frames_ctx = NULL;
    frame->opaque_ref = NULL;
    frame->crop_top = 0;
    frame->crop_bottom = 0;
    frame->crop_left = 0;
    frame->crop_right = 0;
    frame->private_ref = NULL;

    for (int i = 0; i < 8; i++) {
        frame->data[i] = NULL;
        frame->linesize[i] = 0;
        frame->buf[i] = NULL;
    }

    int w = width;
    int h = height;
    frame->data[0] = alloc_plane(w, h);
    frame->linesize[0] = w;
    if (w > 0 && h > 0) {
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                frame->data[0][y * w + x] = rand() & 0xFF;
    }

    w = (width + 1) >> 1;
    h = (height + 1) >> 1;
    frame->data[1] = alloc_plane(w, h);
    frame->data[2] = alloc_plane(w, h);
    frame->linesize[1] = w;
    frame->linesize[2] = w;
    for (int p = 1; p <= 2; p++) {
        if (frame->data[p]) {
            for (int y = 0; y < h; y++)
                for (int x = 0; x < w; x++)
                    frame->data[p][y * w + x] = rand() & 0xFF;
        }
    }
}

MIContext *mi_ctx;
int alpha;
AVFrame *avf_out;
int x;
int y;
int plane;

void init_vars(void) {
    mi_ctx = (MIContext *)calloc(1, sizeof(MIContext));
    if (!mi_ctx) exit(1);

    mi_ctx->class = &av_class_instance;
    mi_ctx->frame_rate.num = 30;
    mi_ctx->frame_rate.den = 1;
    mi_ctx->mi_mode = MI_MODE_BLEND;
    mi_ctx->mc_mode = 0;
    mi_ctx->me_mode = 1;
    mi_ctx->me_method = 7;
    mi_ctx->mb_size = 16;
    mi_ctx->search_param = 7;
    mi_ctx->vsbmc = 0;
    mi_ctx->out_pts = 0;
    mi_ctx->b_width = 128;
    mi_ctx->b_height = 128;
    mi_ctx->b_count = 16384;
    mi_ctx->log2_mb_size = 4;
    mi_ctx->bitdepth = 8;
    mi_ctx->scd_method = 1;
    mi_ctx->scene_changed = 0;
    mi_ctx->sad = NULL;
    mi_ctx->prev_mafd = 0.0;
    mi_ctx->scd_threshold = 10.0;
    mi_ctx->log2_chroma_w = 1;
    mi_ctx->log2_chroma_h = 1;
    mi_ctx->nb_planes = 3;

    int width = 128;
    int height = 128;
    int chroma_width = (width + 1) >> mi_ctx->log2_chroma_w;
    int chroma_height = (height + 1) >> mi_ctx->log2_chroma_h;
    int total_pixels = width * height;

    for (int i = 0; i < 4; i++) {
        mi_ctx->frames[i].avf = (AVFrame *)calloc(1, sizeof(AVFrame));
        if (!mi_ctx->frames[i].avf) exit(1);
        init_avframe(mi_ctx->frames[i].avf, width, height);
    }

    mi_ctx->pixel_mvs = (PixelMVS *)calloc(total_pixels, sizeof(PixelMVS));
    mi_ctx->pixel_weights = (PixelWeights *)calloc(total_pixels, sizeof(PixelWeights));
    mi_ctx->pixel_refs = (PixelRefs *)calloc(total_pixels, sizeof(PixelRefs));

    if (!mi_ctx->pixel_mvs || !mi_ctx->pixel_weights || !mi_ctx->pixel_refs)
        exit(1);

    for (int i = 0; i < total_pixels; i++) {
        PixelRefs *pr = &mi_ctx->pixel_refs[i];
        PixelWeights *pw = &mi_ctx->pixel_weights[i];
        pr->nb = 2;
        pr->refs[0] = 0;
        pr->refs[1] = 1;
        pw->weights[0] = 512;
        pw->weights[1] = 512;
        mi_ctx->pixel_mvs[i].mvs[0][0] = ((i % width) & 7) - 4;
        mi_ctx->pixel_mvs[i].mvs[0][1] = ((i / width) & 7) - 4;
        mi_ctx->pixel_mvs[i].mvs[1][0] = -((i % width) & 7) + 4;
        mi_ctx->pixel_mvs[i].mvs[1][1] = -((i / width) & 7) + 4;
    }

    avf_out = (AVFrame *)calloc(1, sizeof(AVFrame));
    if (!avf_out) exit(1);
    init_avframe(avf_out, width, height);

    alpha = 512;
    x = y = plane = 0;
}