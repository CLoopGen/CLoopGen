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

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct CNGContext {
    float *refl_coef;
    float *target_refl_coef;
    float *lpc_coef;
    int order;
    int energy;
    int target_energy;
    int inited;
    float *filter_out;
    float *excitation;
    AVLFG lfg;
} CNGContext;

AVPacket *avpkt;
CNGContext *p;
int i;

void init_vars() {
    // Allocate avpkt and its buffer
    avpkt = (AVPacket*)calloc(1, sizeof(AVPacket));
    
    // Define data size to make loop run ~0.01 seconds: assume 100M iterations at ~1ns per iteration -> ~100M operations
    const int data_size = 100 * 1024 * 1024; // 100 MB
    avpkt->data = (uint8_t*)malloc(data_size * sizeof(uint8_t));
    avpkt->size = data_size;

    // Initialize data with dummy values
    for (int j = 0; j < data_size; j++) {
        avpkt->data[j] = rand() % 256;
    }

    // Allocate CNGContext
    p = (CNGContext*)calloc(1, sizeof(CNGContext));
    
    // Set order to a reasonable value within data bounds
    p->order = 10000; // Much smaller than avpkt->size to ensure safe access

    // Allocate target_refl_coef array
    p->target_refl_coef = (float*)calloc(p->order, sizeof(float));

    // Initialize other fields if needed
    p->refl_coef = (float*)calloc(p->order, sizeof(float));
    p->lpc_coef = (float*)calloc(p->order, sizeof(float));
    p->filter_out = (float*)calloc(p->order * 2, sizeof(float));
    p->excitation = (float*)calloc(p->order * 2, sizeof(float));
    p->energy = 0;
    p->target_energy = 0;
    p->inited = 1;

    // Initialize AVLFG
    for (int j = 0; j < 64; j++) {
        p->lfg.state[j] = rand();
    }
    p->lfg.index = 0;

    // Ensure avpkt->size - 1 >= p->order so the ternary condition uses p->order
    // Currently: avpkt->size = 100MB, p->order = 10000 -> condition will use p->order
}

// External symbols defined