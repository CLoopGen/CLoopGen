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

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct RangeCoder {
    uint32_t code;
    uint32_t range;
    uint32_t code1;
} RangeCoder;

typedef struct PixelModel {
    uint32_t freq[256];
    uint32_t lookup[16];
    uint32_t total_freq;
} PixelModel;

typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[256];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

typedef struct RunModel3 {
    uint32_t cntsum;
    uint16_t freqs[2][256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} RunModel3;

typedef struct FillModel3 {
    uint32_t cntsum;
    uint16_t freqs[2][5];
    uint16_t cnts[5];
    uint8_t dectab[32];
} FillModel3;

typedef struct SxyModel3 {
    uint32_t cntsum;
    uint16_t freqs[2][16];
    uint16_t cnts[16];
    uint8_t dectab[32];
} SxyModel3;

typedef struct MVModel3 {
    uint32_t cntsum;
    uint16_t freqs[2][512];
    uint16_t cnts[512];
    uint8_t dectab[32];
} MVModel3;

typedef struct OpModel3 {
    uint32_t cntsum;
    uint16_t freqs[2][6];
    uint16_t cnts[6];
    uint8_t dectab[32];
} OpModel3;

typedef struct SCPRContext {
    int version;
    AVFrame *last_frame;
    AVFrame *current_frame;
    GetByteContext gb;
    RangeCoder rc;
    PixelModel pixel_model[3][4096];
    uint32_t op_model[6][7];
    uint32_t run_model[6][257];
    uint32_t range_model[257];
    uint32_t count_model[257];
    uint32_t fill_model[6];
    uint32_t sxy_model[4][17];
    uint32_t mv_model[2][513];
    uint32_t nbx;
    uint32_t nby;
    uint32_t nbcount;
    uint32_t *blocks;
    uint32_t cbits;
    int cxshift;
    PixelModel3 pixel_model3[3][4096];
    RunModel3 run_model3[6];
    RunModel3 range_model3;
    RunModel3 count_model3;
    FillModel3 fill_model3;
    SxyModel3 sxy_model3[4];
    MVModel3 mv_model3[2];
    OpModel3 op_model3[6];
    int (*get_freq)(RangeCoder *, uint32_t, uint32_t *);
    int (*decode)(GetByteContext *, RangeCoder *, uint32_t, uint32_t, uint32_t);
} SCPRContext;

SCPRContext *s;
int i;
int j;

void init_vars() {
    s = (SCPRContext *)calloc(1, sizeof(SCPRContext));
    if (!s) return;

    s->version = 1;
    s->last_frame = (AVFrame *)calloc(1, sizeof(AVFrame));
    s->current_frame = (AVFrame *)calloc(1, sizeof(AVFrame));

    s->gb.buffer = (const uint8_t *)calloc(1, 1024 * 1024);
    s->gb.buffer_start = s->gb.buffer;
    s->gb.buffer_end = s->gb.buffer + 1024 * 1024;

    s->rc.code = 0x12345678;
    s->rc.range = 0xFFFFFFFF;
    s->rc.code1 = 0x87654321;

    for (int c = 0; c < 3; c++) {
        for (int idx = 0; idx < 4096; idx++) {
            s->pixel_model[c][idx].total_freq = 256;
            for (int k = 0; k < 256; k++) {
                s->pixel_model[c][idx].freq[k] = 1;
            }
            for (int k = 0; k < 16; k++) {
                s->pixel_model[c][idx].lookup[k] = 16;
            }
        }
    }

    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 7; b++) {
            s->op_model[a][b] = 1;
        }
    }

    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 257; b++) {
            s->run_model[a][b] = 1;
        }
    }

    for (int a = 0; a < 257; a++) {
        s->range_model[a] = 1;
        s->count_model[a] = 1;
    }

    for (int a = 0; a < 6; a++) {
        s->fill_model[a] = 1;
    }

    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 17; b++) {
            s->sxy_model[a][b] = 1;
        }
    }

    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 513; b++) {
            s->mv_model[a][b] = 1;
        }
    }

    s->nbx = 64;
    s->nby = 64;
    s->nbcount = 4096;
    s->blocks = (uint32_t *)calloc(s->nbcount, sizeof(uint32_t));
    s->cbits = 8;
    s->cxshift = 2;

    for (int c = 0; c < 3; c++) {
        for (int idx = 0; idx < 4096; idx++) {
            s->pixel_model3[c][idx].cntsum = 256;
            s->pixel_model3[c][idx].size = 256;
            for (int k = 0; k < 256; k++) {
                s->pixel_model3[c][idx].symbols[k] = k;
                s->pixel_model3[c][idx].freqs[k] = 1;
                s->pixel_model3[c][idx].freqs1[k] = 1;
                s->pixel_model3[c][idx].cnts[k] = 1;
            }
            for (int k = 0; k < 32; k++) {
                s->pixel_model3[c][idx].dectab[k] = k;
            }
        }
    }

    for (int a = 0; a < 6; a++) {
        s->run_model3[a].cntsum = 256;
        for (int k = 0; k < 256; k++) {
            s->run_model3[a].cnts[k] = 1;
            for (int l = 0; l < 2; l++) {
                s->run_model3[a].freqs[l][k] = 1;
            }
        }
        for (int k = 0; k < 32; k++) {
            s->run_model3[a].dectab[k] = k;
        }
    }

    s->range_model3.cntsum = 256;
    for (int k = 0; k < 256; k++) {
        s->range_model3.cnts[k] = 1;
        for (int l = 0; l < 2; l++) {
            s->range_model3.freqs[l][k] = 1;
        }
    }
    for (int k = 0; k < 32; k++) {
        s->range_model3.dectab[k] = k;
    }

    s->count_model3.cntsum = 256;
    for (int k = 0; k < 256; k++) {
        s->count_model3.cnts[k] = 1;
        for (int l = 0; l < 2; l++) {
            s->count_model3.freqs[l][k] = 1;
        }
    }
    for (int k = 0; k < 32; k++) {
        s->count_model3.dectab[k] = k;
    }

    s->fill_model3.cntsum = 5;
    for (int k = 0; k < 5; k++) {
        s->fill_model3.cnts[k] = 1;
        for (int l = 0; l < 2; l++) {
            s->fill_model3.freqs[l][k] = 1;
        }
    }
    for (int k = 0; k < 32; k++) {
        s->fill_model3.dectab[k] = k;
    }

    for (int a = 0; a < 4; a++) {
        s->sxy_model3[a].cntsum = 16;
        for (int k = 0; k < 16; k++) {
            s->sxy_model3[a].cnts[k] = 1;
            for (int l = 0; l < 2; l++) {
                s->sxy_model3[a].freqs[l][k] = 1;
            }
        }
        for (int k = 0; k < 32; k++) {
            s->sxy_model3[a].dectab[k] = k;
        }
    }

    for (int a = 0; a < 2; a++) {
        s->mv_model3[a].cntsum = 512;
        for (int k = 0; k < 512; k++) {
            s->mv_model3[a].cnts[k] = 1;
            for (int l = 0; l < 2; l++) {
                s->mv_model3[a].freqs[l][k] = 1;
            }
        }
        for (int k = 0; k < 32; k++) {
            s->mv_model3[a].dectab[k] = k;
        }
    }

    for (int a = 0; a < 6; a++) {
        s->op_model3[a].cntsum = 6;
        for (int k = 0; k < 6; k++) {
            s->op_model3[a].cnts[k] = 1;
            for (int l = 0; l < 2; l++) {
                s->op_model3[a].freqs[l][k] = 1;
            }
        }
        for (int k = 0; k < 32; k++) {
            s->op_model3[a].dectab[k] = k;
        }
    }

    s->get_freq = NULL;
    s->decode = NULL;
}