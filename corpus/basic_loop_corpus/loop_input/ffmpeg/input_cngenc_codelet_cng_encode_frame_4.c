#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

enum AVPacketSideDataType {
    AV_PKT_DATA_PALETTE,
    AV_PKT_DATA_NEW_EXTRADATA,
    AV_PKT_DATA_PARAM_CHANGE,
    AV_PKT_DATA_H263_MB_INFO,
    AV_PKT_DATA_REPLAYGAIN,
    AV_PKT_DATA_DISPLAYMATRIX,
    AV_PKT_DATA_STEREO3D,
    AV_PKT_DATA_AUDIO_SERVICE_TYPE,
    AV_PKT_DATA_QUALITY_STATS,
    AV_PKT_DATA_FALLBACK_TRACK,
    AV_PKT_DATA_CPB_PROPERTIES,
    AV_PKT_DATA_SKIP_SAMPLES,
    AV_PKT_DATA_JP_DUALMONO,
    AV_PKT_DATA_STRINGS_METADATA,
    AV_PKT_DATA_SUBTITLE_POSITION,
    AV_PKT_DATA_MATROSKA_BLOCKADDITIONAL,
    AV_PKT_DATA_WEBVTT_IDENTIFIER,
    AV_PKT_DATA_WEBVTT_SETTINGS,
    AV_PKT_DATA_METADATA_UPDATE,
    AV_PKT_DATA_MPEGTS_STREAM_ID,
    AV_PKT_DATA_MASTERING_DISPLAY_METADATA,
    AV_PKT_DATA_SPHERICAL,
    AV_PKT_DATA_CONTENT_LIGHT_LEVEL,
    AV_PKT_DATA_A53_CC,
    AV_PKT_DATA_ENCRYPTION_INIT_INFO,
    AV_PKT_DATA_ENCRYPTION_INFO,
    AV_PKT_DATA_AFD,
    AV_PKT_DATA_PRFT,
    AV_PKT_DATA_ICC_PROFILE,
    AV_PKT_DATA_DOVI_CONF,
    AV_PKT_DATA_NB
};

typedef struct AVPacketSideData {
    uint8_t *data;
    int size;
    enum AVPacketSideDataType type;
} AVPacketSideData;

typedef struct AVPacket {
    AVBufferRef *buf;
    int64_t pts;
    int64_t dts;
    uint8_t *data;
    int size;
    int stream_index;
    int flags;
    AVPacketSideData *side_data;
    int side_data_elems;
    int64_t duration;
    int64_t pos;
    int64_t convergence_duration __attribute__((deprecated("")));
} AVPacket;

enum FFLPCType {
    FF_LPC_TYPE_DEFAULT = -1,
    FF_LPC_TYPE_NONE = 0,
    FF_LPC_TYPE_FIXED = 1,
    FF_LPC_TYPE_LEVINSON = 2,
    FF_LPC_TYPE_CHOLESKY = 3,
    FF_LPC_TYPE_NB
};

typedef struct LLSModel {
    double covariance[36][36] __attribute__((aligned(32)));
    double coeff[32][32] __attribute__((aligned(32)));
    double variance[32];
    int indep_count;
    void (*update_lls)(struct LLSModel *, const double *);
    double (*evaluate_lls)(struct LLSModel *, const double *, int);
} LLSModel;

typedef struct LPCContext {
    int blocksize;
    int max_order;
    enum FFLPCType lpc_type;
    double *windowed_buffer;
    double *windowed_samples;
    void (*lpc_apply_welch_window)(const int32_t *, int, double *);
    void (*lpc_compute_autocorr)(const double *, int, int, double *);
    LLSModel lls_models[2];
} LPCContext;

typedef struct CNGContext {
    LPCContext lpc;
    int order;
    int32_t *samples32;
    double *ref_coef;
} CNGContext;

AVPacket *avpkt;
CNGContext *p;
int i;

void init_vars() {
    p = (CNGContext *)calloc(1, sizeof(CNGContext));
    if (!p) exit(1);

    p->order = 1000000; // Set order to ~1M to ensure loop takes ~0.01s

    p->ref_coef = (double *)calloc(p->order, sizeof(double));
    if (!p->ref_coef) exit(1);

    for (int j = 0; j < p->order; j++) {
        p->ref_coef[j] = (double)j / p->order; // arbitrary values in [0,1)
    }

    avpkt = (AVPacket *)calloc(1, sizeof(AVPacket));
    if (!avpkt) exit(1);

    avpkt->data = (uint8_t *)calloc(1 + p->order, sizeof(uint8_t));
    if (!avpkt->data) exit(1);

    avpkt->size = 1 + p->order;
}