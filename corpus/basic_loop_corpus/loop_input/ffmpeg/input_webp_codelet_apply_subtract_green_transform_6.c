#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

enum ImageRole {
    IMAGE_ROLE_ARGB,
    IMAGE_ROLE_ENTROPY,
    IMAGE_ROLE_PREDICTOR,
    IMAGE_ROLE_COLOR_TRANSFORM,
    IMAGE_ROLE_COLOR_INDEXING,
    IMAGE_ROLE_NB
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

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct HuffReader {
    VLC vlc;
    int simple;
    int nb_symbols;
    uint16_t simple_symbols[2];
} HuffReader;

typedef struct ImageContext {
    enum ImageRole role;
    AVFrame *frame;
    int color_cache_bits;
    uint32_t *color_cache;
    int nb_huffman_groups;
    HuffReader *huffman_groups;
    int size_reduction;
    int is_alpha_primary;
} ImageContext;

int x;
int y;
ImageContext *img;

void init_vars() {
    const size_t target_data_size = 64 * 1024 * 1024;
    const int bytes_per_pixel = 4;
    const int total_pixels = target_data_size / bytes_per_pixel;
    int width = (int)sqrt(total_pixels);
    int height = total_pixels / width;

    img = (ImageContext *)calloc(1, sizeof(ImageContext));
    img->frame = (AVFrame *)calloc(1, sizeof(AVFrame));
    img->role = IMAGE_ROLE_ARGB;
    img->color_cache_bits = 8;
    img->color_cache = (uint32_t *)calloc(1 << img->color_cache_bits, sizeof(uint32_t));
    img->nb_huffman_groups = 1;
    img->huffman_groups = (HuffReader *)calloc(1, sizeof(HuffReader));
    img->size_reduction = 0;
    img->is_alpha_primary = 0;

    img->frame->width = width;
    img->frame->height = height;
    img->frame->format = 0;
    img->frame->pict_type = AV_PICTURE_TYPE_I;
    img->frame->color_range = AVCOL_RANGE_MPEG;
    img->frame->color_primaries = AVCOL_PRI_BT709;
    img->frame->color_trc = AVCOL_TRC_BT709;
    img->frame->colorspace = AVCOL_SPC_BT709;
    img->frame->chroma_location = AVCHROMA_LOC_CENTER;

    int linesize = width * bytes_per_pixel;
    img->frame->linesize[0] = linesize;
    img->frame->data[0] = (uint8_t *)calloc(height, linesize);

    for (int i = 0; i < height; i++) {
        uint8_t *row = img->frame->data[0] + i * linesize;
        for (int j = 0; j < width; j++) {
            int idx = j * bytes_per_pixel;
            row[idx + 0] = rand() & 0xFF;
            row[idx + 1] = rand() & 0xFF;
            row[idx + 2] = rand() & 0xFF;
            row[idx + 3] = rand() & 0xFF;
        }
    }

    img->frame->extended_data = (uint8_t **)calloc(1, sizeof(uint8_t *));
    img->frame->extended_data[0] = img->frame->data[0];

    img->frame->nb_extended_buf = 0;
    img->frame->extended_buf = NULL;
    img->frame->nb_side_data = 0;
    img->frame->side_data = NULL;

    img->frame->sample_aspect_ratio.num = 1;
    img->frame->sample_aspect_ratio.den = 1;
    img->frame->pts = 0;
    img->frame->pkt_dts = 0;
    img->frame->best_effort_timestamp = 0;
    img->frame->pkt_pos = -1;
    img->frame->pkt_duration = 0;
    img->frame->key_frame = 1;
    img->frame->pict_type = AV_PICTURE_TYPE_I;
    img->frame->quality = 1;
    img->frame->interlaced_frame = 0;
    img->frame->top_field_first = 0;
    img->frame->reordered_opaque = 0;
    img->frame->sample_rate = 0;
    img->frame->channel_layout = 0;
    img->frame->channels = 0;
    img->frame->pkt_size = 0;
    img->frame->flags = 0;
    img->frame->decode_error_flags = 0;
    img->frame->crop_top = 0;
    img->frame->crop_bottom = 0;
    img->frame->crop_left = 0;
    img->frame->crop_right = 0;

    for (int i = 1; i < 8; i++) {
        img->frame->data[i] = NULL;
        img->frame->linesize[i] = 0;
        img->frame->buf[i] = NULL;
    }
    img->frame->buf[0] = NULL;
}