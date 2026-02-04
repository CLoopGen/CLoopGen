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

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct MSS4Context {
    AVFrame *pic;
    VLC dc_vlc[2];
    VLC ac_vlc[2];
    VLC vec_entry_vlc[2];
    int block[64];
    uint8_t imgbuf[3][256];
    int quality;
    uint16_t quant_mat[2][64];
    int *prev_dc[3];
    ptrdiff_t dc_stride[3];
    int dc_cache[4][4];
    int prev_vec[3][4];
} MSS4Context;

MSS4Context *ctx;
int i;
uint8_t *dst[3];

void init_vars() {
    ctx = (MSS4Context*)calloc(1, sizeof(MSS4Context));
    if (!ctx) return;

    for (int j = 0; j < 3; j++) {
        ctx->prev_dc[j] = (int*)calloc(4, sizeof(int));
        if (ctx->prev_dc[j]) {
            for (int k = 0; k < 4; k++) {
                ctx->prev_dc[j][k] = 128;
            }
        }
        ctx->dc_stride[j] = 4;
    }

    ctx->quality = 50;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 64; k++) {
            ctx->quant_mat[j][k] = 16;
        }
    }

    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            ctx->dc_cache[j][k] = 0;
        }
    }

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 4; k++) {
            ctx->prev_vec[j][k] = 0;
        }
    }

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 256; k++) {
            ctx->imgbuf[j][k] = (uint8_t)(j * 64 + k);
        }
    }

    ctx->pic = (AVFrame*)calloc(1, sizeof(AVFrame));
    if (ctx->pic) {
        ctx->pic->width = 16;
        ctx->pic->height = 16;
        ctx->pic->format = 0;
        ctx->pic->key_frame = 1;
        ctx->pic->pict_type = AV_PICTURE_TYPE_I;
        ctx->pic->sample_aspect_ratio.num = 1;
        ctx->pic->sample_aspect_ratio.den = 1;
        ctx->pic->pts = 0;
        ctx->pic->pkt_dts = 0;
        ctx->pic->coded_picture_number = 0;
        ctx->pic->display_picture_number = 0;
        ctx->pic->quality = 50;
        ctx->pic->repeat_pict = 0;
        ctx->pic->interlaced_frame = 0;
        ctx->pic->top_field_first = 0;
        ctx->pic->palette_has_changed = 0;
        ctx->pic->reordered_opaque = 0;
        ctx->pic->sample_rate = 44100;
        ctx->pic->channel_layout = 0x3;
        ctx->pic->nb_extended_buf = 0;
        ctx->pic->nb_side_data = 0;
        ctx->pic->flags = 0;
        ctx->pic->color_range = AVCOL_RANGE_MPEG;
        ctx->pic->color_primaries = AVCOL_PRI_BT709;
        ctx->pic->color_trc = AVCOL_TRC_BT709;
        ctx->pic->colorspace = AVCOL_SPC_BT709;
        ctx->pic->chroma_location = AVCHROMA_LOC_CENTER;
        ctx->pic->best_effort_timestamp = 0;
        ctx->pic->pkt_pos = -1;
        ctx->pic->pkt_duration = 1;
        ctx->pic->decode_error_flags = 0;
        ctx->pic->channels = 2;
        ctx->pic->pkt_size = 1024;

        for (int j = 0; j < 8; j++) {
            ctx->pic->data[j] = NULL;
            ctx->pic->linesize[j] = 0;
            ctx->pic->buf[j] = NULL;
        }

        ctx->pic->extended_data = NULL;
        ctx->pic->extended_buf = NULL;
        ctx->pic->side_data = NULL;
        ctx->pic->metadata = NULL;
        ctx->pic->opaque = NULL;
        ctx->pic->qscale_table = NULL;
        ctx->pic->qp_table_buf = NULL;
        ctx->pic->hw_frames_ctx = NULL;
        ctx->pic->opaque_ref = NULL;
        ctx->pic->crop_top = 0;
        ctx->pic->crop_bottom = 0;
        ctx->pic->crop_left = 0;
        ctx->pic->crop_right = 0;
        ctx->pic->private_ref = NULL;

        for (int j = 0; j < 8; j++) {
            ctx->pic->error[j] = 0;
        }
    }

    for (int j = 0; j < 2; j++) {
        ctx->dc_vlc[j].bits = 8;
        ctx->dc_vlc[j].table_size = 0;
        ctx->dc_vlc[j].table_allocated = 0;
        ctx->dc_vlc[j].table = NULL;

        ctx->ac_vlc[j].bits = 8;
        ctx->ac_vlc[j].table_size = 0;
        ctx->ac_vlc[j].table_allocated = 0;
        ctx->ac_vlc[j].table = NULL;

        ctx->vec_entry_vlc[j].bits = 8;
        ctx->vec_entry_vlc[j].table_size = 0;
        ctx->vec_entry_vlc[j].table_allocated = 0;
        ctx->vec_entry_vlc[j].table = NULL;
    }

    for (int j = 0; j < 64; j++) {
        ctx->block[j] = 0;
    }

    for (int j = 0; j < 3; j++) {
        dst[j] = NULL;
    }

    i = 0;
}