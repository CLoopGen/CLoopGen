#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct PayloadContext {
    int block_type;
    int block_size;
    int subpkts_per_block;
    uint16_t len[128];
    uint8_t buf[128][2048];
    unsigned int cache;
    unsigned int n_pkts;
    uint32_t timestamp;
};

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
    int64_t convergence_duration;
} AVPacket;

struct PayloadContext *qdm;
AVPacket *pkt;
unsigned int total;
uint8_t *q;

void init_vars() {
    qdm = (struct PayloadContext*)malloc(sizeof(struct PayloadContext));
    qdm->block_type = 0;
    qdm->subpkts_per_block = 0;
    qdm->cache = 0;
    qdm->n_pkts = 0;
    qdm->timestamp = 0;
    for (int i = 0; i < 128; ++i) {
        qdm->len[i] = 0;
        for (int j = 0; j < 2048; ++j) {
            qdm->buf[i][j] = 0;
        }
    }

    pkt = (AVPacket*)malloc(sizeof(AVPacket));
    const int data_size = 131072; // 128KB to ensure loop runs ~0.01s without being too large
    uint8_t* packet_data = (uint8_t*)malloc(data_size);
    for (int i = 0; i < data_size; ++i) {
        packet_data[i] = i & 0xFF;
    }
    qdm->block_size = data_size;

    pkt->data = packet_data;
    pkt->size = data_size;
    pkt->buf = NULL;
    pkt->pts = 0;
    pkt->dts = 0;
    pkt->stream_index = 0;
    pkt->flags = 0;
    pkt->side_data = NULL;
    pkt->side_data_elems = 0;
    pkt->duration = 0;
    pkt->pos = 0;
    pkt->convergence_duration = 0;

    total = 0;
    q = NULL;
}