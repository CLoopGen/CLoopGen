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
    int64_t convergence_duration;
} AVPacket;

AVPacket **in;
int n_in;
int n;
unsigned int max;
unsigned int sum;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB of packet data
    n_in = 8192;
    
    in = (AVPacket**)calloc(n_in, sizeof(AVPacket*));
    if (!in) exit(1);

    uint8_t* shared_data_pool = (uint8_t*)malloc(total_data_size);
    if (!shared_data_pool) exit(1);

    size_t offset = 0;
    max = 0;
    sum = 0;

    for (int i = 0; i < n_in; i++) {
        AVPacket* pkt = (AVPacket*)malloc(sizeof(AVPacket));
        if (!pkt) exit(1);

        int sz = (i * 7 + 101) % (total_data_size / n_in) + 1; // vary size between 1 and ~8KB
        if (offset + sz > total_data_size) {
            sz = total_data_size - offset;
        }

        pkt->data = shared_data_pool + offset;
        pkt->size = sz;
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

        in[i] = pkt;

        if (sz > max) max = sz;
        sum += sz;

        offset += sz;
        if (offset >= total_data_size) break;
    }
}