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

typedef struct FFFrameBucket {
    AVFrame *frame;
} FFFrameBucket;

FFFrameBucket *b;
size_t bytes;
int planes;
int i;

void init_vars() {
    b = malloc(sizeof(FFFrameBucket));
    b->frame = malloc(sizeof(AVFrame));

    // Set up a data size to make loop take ~0.01 seconds
    // Assume modern CPU can do pointer arithmetic quickly, so we need enough iterations
    // Let's aim for about 16 million iterations (which is fast but measurable)
    planes = 8;  // Max number of planes based on AVFrame layout
    bytes = 1 << 21; // 2MB offset per plane

    // Allocate extended_data array
    b->frame->extended_data = malloc(planes * sizeof(uint8_t*));

    // Allocate each data pointer with sufficient size to handle the byte offset
    size_t total_data_size = bytes + 256; // Add padding beyond the offset
    for (int j = 0; j < planes; j++) {
        b->frame->extended_data[j] = malloc(total_data_size);
        // Initialize to avoid uninitialized value issues
        for (size_t k = 0; k < total_data_size; k++) {
            b->frame->extended_data[j][k] = (uint8_t)(j + k);
        }
    }

    // Zero out other fields to avoid undefined behavior if accessed
    for (int j = 0; j < 8; j++) {
        b->frame->data[j] = NULL;
        b->frame->linesize[j] = 0;
        b->frame->buf[j] = NULL;
        b->frame->error[j] = 0;
    }

    b->frame->width = 0;
    b->frame->height = 0;
    b->frame->nb_samples = 0;
    b->frame->format = 0;
    b->frame->key_frame = 0;
    b->frame->pict_type = AV_PICTURE_TYPE_NONE;
    b->frame->sample_aspect_ratio.num = 0;
    b->frame->sample_aspect_ratio.den = 1;
    b->frame->pts = 0;
    b->frame->pkt_pts = 0;
    b->frame->pkt_dts = 0;
    b->frame->coded_picture_number = 0;
    b->frame->display_picture_number = 0;
    b->frame->quality = 0;
    b->frame->opaque = NULL;
    b->frame->repeat_pict = 0;
    b->frame->interlaced_frame = 0;
    b->frame->top_field_first = 0;
    b->frame->palette_has_changed = 0;
    b->frame->reordered_opaque = 0;
    b->frame->sample_rate = 0;
    b->frame->channel_layout = 0;
    b->frame->extended_buf = NULL;
    b->frame->nb_extended_buf = 0;
    b->frame->side_data = NULL;
    b->frame->nb_side_data = 0;
    b->frame->flags = 0;
    b->frame->color_range = AVCOL_RANGE_UNSPECIFIED;
    b->frame->color_primaries = AVCOL_PRI_UNSPECIFIED;
    b->frame->color_trc = AVCOL_TRC_UNSPECIFIED;
    b->frame->colorspace = AVCOL_SPC_UNSPECIFIED;
    b->frame->chroma_location = AVCHROMA_LOC_UNSPECIFIED;
    b->frame->best_effort_timestamp = 0;
    b->frame->pkt_pos = 0;
    b->frame->pkt_duration = 0;
    b->frame->metadata = NULL;
    b->frame->decode_error_flags = 0;
    b->frame->channels = 0;
    b->frame->pkt_size = 0;
    b->frame->qscale_table = NULL;
    b->frame->qstride = 0;
    b->frame->qscale_type = 0;
    b->frame->qp_table_buf = NULL;
    b->frame->hw_frames_ctx = NULL;
    b->frame->opaque_ref = NULL;
    b->frame->crop_top = 0;
    b->frame->crop_bottom = 0;
    b->frame->crop_left = 0;
    b->frame->crop_right = 0;
    b->frame->private_ref = NULL;
}