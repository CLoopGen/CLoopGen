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

typedef struct NormalizeLocal {
    uint16_t in;
    float smoothed;
    float out;
} NormalizeLocal;

AVFrame *in;
NormalizeLocal min[3];
NormalizeLocal max[3];

void init_vars() {
    const int width = 1920;
    const int height = 1080;
    const int pixel_size = sizeof(uint16_t);

    in = (AVFrame*)calloc(1, sizeof(AVFrame));
    if (!in) exit(1);

    in->width = width;
    in->height = height;
    in->format = 0;
    in->pict_type = AV_PICTURE_TYPE_NONE;
    in->sample_aspect_ratio.num = 1;
    in->sample_aspect_ratio.den = 1;
    in->pts = 0;
    in->pkt_dts = 0;
    in->coded_picture_number = 0;
    in->display_picture_number = 0;
    in->quality = 0;
    in->key_frame = 1;
    in->repeat_pict = 0;
    in->interlaced_frame = 0;
    in->top_field_first = 0;
    in->palette_has_changed = 0;
    in->sample_rate = 0;
    in->channels = 0;
    in->pkt_size = 0;
    in->color_range = AVCOL_RANGE_MPEG;
    in->color_primaries = AVCOL_PRI_BT709;
    in->color_trc = AVCOL_TRC_BT709;
    in->colorspace = AVCOL_SPC_BT709;
    in->chroma_location = AVCHROMA_LOC_CENTER;
    in->best_effort_timestamp = 0;
    in->flags = 0;
    in->nb_samples = 0;
    in->channel_layout = 0;
    in->nb_extended_buf = 0;
    in->nb_side_data = 0;
    in->decode_error_flags = 0;
    in->crop_top = 0;
    in->crop_bottom = 0;
    in->crop_left = 0;
    in->crop_right = 0;

    for (int i = 0; i < 3; i++) {
        min[i].in = UINT16_MAX;
        max[i].in = 0;
        min[i].smoothed = 0.0f;
        max[i].smoothed = 0.0f;
        min[i].out = 0.0f;
        max[i].out = 0.0f;
    }

    for (int plane = 0; plane < 3; plane++) {
        int stride = width * pixel_size;
        uint8_t* data = (uint8_t*)calloc(height, stride);
        if (!data) exit(1);

        in->data[plane] = data;
        in->linesize[plane] = stride;
    }

    for (int y = 0; y < height; y++) {
        uint16_t* r_row = (uint16_t*)(in->data[2] + y * in->linesize[2]);
        uint16_t* g_row = (uint16_t*)(in->data[0] + y * in->linesize[0]);
        uint16_t* b_row = (uint16_t*)(in->data[1] + y * in->linesize[1]);

        for (int x = 0; x < width; x++) {
            r_row[x] = (uint16_t)((x * y) % 65536);
            g_row[x] = (uint16_t)(((x + y) * 3) % 65536);
            b_row[x] = (uint16_t)(((x - y + 1000) * 5) % 65536);
        }
    }
}