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
    int64_t pkt_pts __attribute__((deprecated("")));
    int64_t pkt_dts;
    int coded_picture_number;
    int display_picture_number;
    int quality;
    void *opaque;
    uint64_t error[8] __attribute__((deprecated("")));
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
    int8_t *qscale_table __attribute__((deprecated("")));
    int qstride __attribute__((deprecated("")));
    int qscale_type __attribute__((deprecated("")));
    AVBufferRef *qp_table_buf __attribute__((deprecated("")));
    AVBufferRef *hw_frames_ctx;
    AVBufferRef *opaque_ref;
    size_t crop_top;
    size_t crop_bottom;
    size_t crop_left;
    size_t crop_right;
    AVBufferRef *private_ref;
} AVFrame;

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


union {
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
    union {
        int64_t i64;
        double dbl;
        const char *str;
        AVRational q;
    } default_val;
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

typedef struct BPNContext {
    const AVClass *class;
    int bitplane;
    int filter;
    int nb_planes;
    int planeheight[4];
    int planewidth[4];
    int depth;
} BPNContext;

extern AVFrame *in;
extern BPNContext *s;
extern  int mask;
extern  int factor;
extern float stats[4];
extern int plane;
extern int y;
extern int x;
extern int bit;
extern AVFrame *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (plane = 0; plane < s->nb_planes; plane += 2) {
    if (plane + 1 >= s->nb_planes) break;

    const int linesize0 = s->planeheight[plane] > 1 ? in->linesize[plane] / 2 : 0;
    const int linesize1 = s->planeheight[plane+1] > 1 ? in->linesize[plane+1] / 2 : 0;
    const int dlinesize0 = out->linesize[plane] / 2;
    const int dlinesize1 = out->linesize[plane+1] / 2;

    uint16_t *val0 = (uint16_t *)in->data[plane];
    uint16_t *val1 = (uint16_t *)in->data[plane+1];
    uint16_t *dst0 = s->filter ? (uint16_t *)out->data[plane] : ((void *)0);
    uint16_t *dst1 = s->filter ? (uint16_t *)out->data[plane+1] : ((void *)0);

    float acc0 = 0.0f, acc1 = 0.0f;

    for (y = 0; y < s->planeheight[plane] - 1; y += 2) {
        for (x = 1; x < s->planewidth[plane] - 1; x++) {
            bit = (((val0[x] & mask) == (val0[x-1] & mask)) +
                   ((val0[x] & mask) == (val0[x+1] & mask)) +
                   ((val0[x] & mask) == (val0[x+linesize0] & mask))) > 1;
            if (dst0) dst0[x] = factor * bit;
            acc0 += bit;

            if (y + 1 < s->planeheight[plane]) {
                bit = (((val0[x] & mask) == (val0[x-1] & mask)) +
                       ((val0[x] & mask) == (val0[x+1] & mask)) +
                       ((val0[x] & mask) == (val0[x-linesize0] & mask))) > 1;
                if (dst0) dst0[x - linesize0] = factor * bit;
                acc0 += bit;
            }
        }
    }

    for (y = 0; y < s->planeheight[plane+1]; y++) {
        for (x = 0; x < s->planewidth[plane+1]; x += 4) {
            for (int off = 0; off < 4 && (x + off) < s->planewidth[plane+1]; off++) {
                uint16_t v = val1[x + off];
                int eq_count = 0;
                if (x + off > 0) eq_count += ((v & mask) == (val1[x + off - 1] & mask));
                if (x + off < s->planewidth[plane+1] - 1) eq_count += ((v & mask) == (val1[x + off + 1] & mask));
                if (y > 0) eq_count += ((v & mask) == (val1[x + off - linesize1] & mask));
                if (y < s->planeheight[plane+1] - 1) eq_count += ((v & mask) == (val1[x + off + linesize1] & mask));
                bit = eq_count >= 2;
                if (dst1) dst1[x + off] = factor * bit;
                acc1 += bit;
            }
        }
        val1 += linesize1;
        if (dst1) dst1 += dlinesize1;
    }

    stats[plane] += acc0;
    stats[plane+1] += acc1;
}

if (s->nb_planes % 2 == 1) {
    plane = s->nb_planes - 1;
    const int linesize = s->planeheight[plane] > 1 ? in->linesize[plane] / 2 : 0;
    const int dlinesize = out->linesize[plane] / 2;
    uint16_t *val = (uint16_t *)in->data[plane];
    uint16_t *dst = s->filter ? (uint16_t *)out->data[plane] : ((void *)0);
    float acc = 0.0f;

    for (y = 0; y < s->planeheight[plane]; y++) {
        for (x = 0; x < s->planewidth[plane]; x++) {
            bit = (((val[x] & mask) == (val[(x + s->planewidth[plane] - 1) % s->planewidth[plane]] & mask)) +
                   ((val[x] & mask) == (val[(x + 1) % s->planewidth[plane]] & mask)) +
                   ((val[x] & mask) == (val[x + (y < s->planeheight[plane] - 1 ? linesize : -linesize)] & mask))) > 1;
            if (dst) dst[x] = factor * bit;
            acc += bit;
        }
        val += linesize;
        if (dst) dst += dlinesize;
    }
    stats[plane] += acc;
}
}
