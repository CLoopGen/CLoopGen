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

static AVBuffer* av_buffer_instance_ptr = NULL;

static uint8_t* packet_data = NULL;
static AVBufferRef buffer_ref_instance;
static AVPacket pkt_instance;

AVPacket *pkt = &pkt_instance;
int i;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB to target ~0.01 sec on modern CPU

    packet_data = (uint8_t*)malloc(data_size);
    if (!packet_data) exit(1);

    for (size_t j = 0; j < data_size; ++j) {
        packet_data[j] = j & 0xFF;
    }

    buffer_ref_instance.buffer = av_buffer_instance_ptr;
    buffer_ref_instance.data = packet_data;
    buffer_ref_instance.size = data_size;

    pkt_instance.buf = &buffer_ref_instance;
    pkt_instance.pts = 0;
    pkt_instance.dts = 0;
    pkt_instance.data = packet_data;
    pkt_instance.size = data_size - 1; // ensures i+1 <= pkt->size with i starting at 3 and stepping by 4
    pkt_instance.stream_index = 0;
    pkt_instance.flags = 0;
    pkt_instance.side_data = NULL;
    pkt_instance.side_data_elems = 0;
    pkt_instance.duration = 0;
    pkt_instance.pos = 0;
    pkt_instance.convergence_duration = 0;
}