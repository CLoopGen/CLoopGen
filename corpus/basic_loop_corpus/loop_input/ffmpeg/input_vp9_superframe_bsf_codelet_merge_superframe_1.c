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
unsigned int mag;
unsigned int n;
uint8_t *ptr;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // 128 MB of input data
    n_in = 65536; // Number of AVPacket pointers
    mag = 7; // Magnitude value used in loop

    // Allocate memory for ptr (output buffer)
    ptr = (uint8_t*)calloc(total_data_size, sizeof(uint8_t));
    if (!ptr) exit(1);

    // Allocate array of AVPacket pointers
    in = (AVPacket**)calloc(n_in, sizeof(AVPacket*));
    if (!in) exit(1);

    // Allocate shared data buffer to hold packet data fields
    uint8_t *data_pool = (uint8_t*)malloc(n_in * sizeof(int));
    if (!data_pool) exit(1);

    for (int i = 0; i < n_in; i++) {
        // Allocate AVPacket
        AVPacket *pkt = (AVPacket*)malloc(sizeof(AVPacket));
        if (!pkt) exit(1);

        // Initialize simple fields
        pkt->size = (i % 1000) + 1; // Vary size between 1 and 1000
        pkt->buf = NULL;
        pkt->pts = 0;
        pkt->dts = 0;
        pkt->data = NULL;
        pkt->stream_index = 0;
        pkt->flags = 0;
        pkt->side_data = NULL;
        pkt->side_data_elems = 0;
        pkt->duration = 0;
        pkt->pos = 0;
        pkt->convergence_duration = 0;

        // Assign deterministic data pointer content (just store size)
        pkt->data = &data_pool[i * sizeof(int)];
        *(int*)pkt->data = pkt->size;

        // Store packet in input array
        in[i] = pkt;
    }
}