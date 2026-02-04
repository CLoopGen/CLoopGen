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
    const size_t total_data_size = 128 * 1024 * 1024; // 128 MB of total packet data
    n_in = 32768; // Number of AVPacket pointers
    mag = 3; // Ensures ptr advances by mag+1 = 4 bytes per iteration

    // Allocate array of AVPacket pointers
    in = (AVPacket**)calloc(n_in, sizeof(AVPacket*));
    if (!in) exit(1);

    // Allocate shared buffer for simulating data
    uint8_t *shared_data_pool = (uint8_t*)malloc(total_data_size);
    if (!shared_data_pool) exit(1);

    size_t current_offset = 0;

    for (int i = 0; i < n_in; i++) {
        AVPacket *pkt = (AVPacket*)malloc(sizeof(AVPacket));
        if (!pkt) exit(1);

        AVBufferRef *buf = (AVBufferRef*)malloc(sizeof(AVBufferRef));
        if (!buf) exit(1);

        int packet_size = (total_data_size / n_in); // Uniform size for simplicity
        if (current_offset + packet_size > total_data_size) {
            packet_size = total_data_size - current_offset;
        }

        pkt->size = packet_size;
        pkt->buf = buf;
        pkt->data = shared_data_pool + current_offset;

        buf->data = pkt->data;
        buf->size = packet_size;

        in[i] = pkt;
        current_offset += packet_size;
    }

    // Allocate ptr with sufficient space: each iteration writes 3 bytes and advances by mag+1=4
    size_t ptr_size = (size_t)n_in * (mag + 1);
    ptr = (uint8_t*)malloc(ptr_size);
    if (!ptr) exit(1);

    // Initialize ptr memory to zero
    for (size_t i = 0; i < ptr_size; i++) {
        ptr[i] = 0;
    }
}