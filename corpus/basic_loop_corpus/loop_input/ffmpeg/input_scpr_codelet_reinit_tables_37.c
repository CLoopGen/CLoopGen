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

static AVFrame* create_avframe() {
    AVFrame *frame = (AVFrame*)calloc(1, sizeof(AVFrame));
    if (!frame) return NULL;
    
    for (int i = 0; i < 8; i++) {
        frame->data[i] = (uint8_t*)calloc(1, 1024 * 1024);
        frame->linesize[i] = 1024;
        frame->buf[i] = (AVBufferRef*)calloc(1, sizeof(AVBufferRef));
        if (frame->buf[i]) {
            frame->buf[i]->data = frame->data[i];
            frame->buf[i]->size = 1024 * 1024;
        }
    }
    
    frame->width = 640;
    frame->height = 480;
    frame->format = 0;
    frame->key_frame = 1;
    frame->pict_type = AV_PICTURE_TYPE_I;
    frame->sample_aspect_ratio.num = 1;
    frame->sample_aspect_ratio.den = 1;
    frame->pts = 0;
    frame->pkt_dts = 0;
    frame->nb_samples = 0;
    frame->channels = 0;
    frame->channel_layout = 0;
    frame->color_range = AVCOL_RANGE_MPEG;
    frame->color_primaries = AVCOL_PRI_BT709;
    frame->color_trc = AVCOL_TRC_BT709;
    frame->colorspace = AVCOL_SPC_BT709;
    frame->chroma_location = AVCHROMA_LOC_CENTER;
    
    return frame;
}

void init_vars() {
    s = (SCPRContext*)calloc(1, sizeof(SCPRContext));
    if (!s) return;
    
    s->version = 1;
    s->last_frame = create_avframe();
    s->current_frame = create_avframe();
    
    s->gb.buffer = (const uint8_t*)calloc(1, 1024 * 1024);
    s->gb.buffer_start = s->gb.buffer;
    s->gb.buffer_end = s->gb.buffer + 1024 * 1024;
    
    s->rc.code = 0x12345678;
    s->rc.range = 0xFFFFFFFF;
    s->rc.code1 = 0x87654321;
    
    for (int c = 0; c < 3; c++) {
        for (int p = 0; p < 4096; p++) {
            s->pixel_model[c][p].total_freq = 256;
            for (int f = 0; f < 256; f++) {
                s->pixel_model[c][p].freq[f] = 1;
            }
            for (int l = 0; l < 16; l++) {
                s->pixel_model[c][p].lookup[l] = l * 16;
            }
        }
    }
    
    for (int o = 0; o < 6; o++) {
        for (int p = 0; p < 7; p++) {
            s->op_model[o][p] = 1;
        }
    }
    
    for (int r = 0; r < 6; r++) {
        for (int p = 0; p < 257; p++) {
            s->run_model[r][p] = 1;
        }
    }
    
    for (int p = 0; p < 257; p++) {
        s->range_model[p] = 1;
        s->count_model[p] = 1;
    }
    
    for (int f = 0; f < 6; f++) {
        s->fill_model[f] = 0;
    }
    
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 17; y++) {
            s->sxy_model[x][y] = 1;
        }
    }
    
    for (int m = 0; m < 2; m++) {
        for (int v = 0; v < 513; v++) {
            s->mv_model[m][v] = 1;
        }
    }
    
    s->nbx = 64;
    s->nby = 48;
    s->nbcount = 3072;
    s->blocks = (uint32_t*)calloc(s->nbcount, sizeof(uint32_t));
    s->cbits = 0;
    s->cxshift = 0;
    
    for (int c = 0; c < 3; c++) {
        for (int p = 0; p < 4096; p++) {
            s->pixel_model3[c][p].type = 0;
            s->pixel_model3[c][p].length = 8;
            s->pixel_model3[c][p].maxpos = 255;
            s->pixel_model3[c][p].fshift = 0;
            s->pixel_model3[c][p].size = 256;
            s->pixel_model3[c][p].cntsum = 256;
            for (int j = 0; j < 256; j++) {
                s->pixel_model3[c][p].symbols[j] = j;
                s->pixel_model3[c][p].freqs[j] = 1;
                s->pixel_model3[c][p].freqs1[j] = 1;
                s->pixel_model3[c][p].cnts[j] = 1;
            }
            for (int j = 0; j < 32; j++) {
                s->pixel_model3[c][p].dectab[j] = j;
            }
        }
    }
    
    for (int r = 0; r < 6; r++) {
        s->run_model3[r].cntsum = 256;
        for (int i = 0; i < 256; i++) {
            s->run_model3[r].cnts[i] = 1;
            for (int j = 0; j < 2; j++) {
                s->run_model3[r].freqs[j][i] = 1;
            }
        }
        for (int j = 0; j < 32; j++) {
            s->run_model3[r].dectab[j] = j;
        }
    }
    
    s->range_model3.cntsum = 256;
    s->count_model3.cntsum = 256;
    for (int i = 0; i < 256; i++) {
        s->range_model3.cnts[i] = 1;
        s->count_model3.cnts[i] = 1;
        for (int j = 0; j < 2; j++) {
            s->range_model3.freqs[j][i] = 1;
            s->count_model3.freqs[j][i] = 1;
        }
    }
    for (int j = 0; j < 32; j++) {
        s->range_model3.dectab[j] = j;
        s->count_model3.dectab[j] = j;
    }
    
    s->fill_model3.cntsum = 256;
    for (int i = 0; i < 5; i++) {
        s->fill_model3.cnts[i] = 1;
        for (int j = 0; j < 2; j++) {
            s->fill_model3.freqs[j][i] = 1;
        }
    }
    for (int j = 0; j < 32; j++) {
        s->fill_model3.dectab[j] = j;
    }
    
    for (int x = 0; x < 4; x++) {
        s->sxy_model3[x].cntsum = 256;
        for (int i = 0; i < 16; i++) {
            s->sxy_model3[x].cnts[i] = 1;
            for (int j = 0; j < 2; j++) {
                s->sxy_model3[x].freqs[j][i] = 1;
            }
        }
        for (int j = 0; j < 32; j++) {
            s->sxy_model3[x].dectab[j] = j;
        }
    }
    
    for (int m = 0; m < 2; m++) {
        s->mv_model3[m].cntsum = 256;
        for (int i = 0; i < 512; i++) {
            s->mv_model3[m].cnts[i] = 1;
            for (int j = 0; j < 2; j++) {
                s->mv_model3[m].freqs[j][i] = 1;
            }
        }
        for (int j = 0; j < 32; j++) {
            s->mv_model3[m].dectab[j] = j;
        }
    }
    
    for (int o = 0; o < 6; o++) {
        s->op_model3[o].cntsum = 256;
        for (int i = 0; i < 6; i++) {
            s->op_model3[o].cnts[i] = 1;
            for (int j = 0; j < 2; j++) {
                s->op_model3[o].freqs[j][i] = 1;
            }
        }
        for (int j = 0; j < 32; j++) {
            s->op_model3[o].dectab[j] = j;
        }
    }
    
    s->get_freq = NULL;
    s->decode = NULL;
}