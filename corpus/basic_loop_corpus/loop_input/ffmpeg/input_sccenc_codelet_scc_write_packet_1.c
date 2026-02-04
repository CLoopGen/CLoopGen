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

static uint8_t packet_data[131072]; // 128KB data to target ~0.01s runtime
static AVBufferRef buffer_ref;
static AVPacket av_packet;
static int loop_index;

AVPacket *pkt = &av_packet;
int i = 0;

void init_vars() {
    int data_size = sizeof(packet_data);
    
    // Initialize data with repeating pattern: 252, 128, 128, ... to avoid early break
    for (int j = 0; j < data_size; j += 3) {
        packet_data[j] = 252;
        if (j + 1 < data_size) packet_data[j + 1] = 128;
        if (j + 2 < data_size) packet_data[j + 2] = 128;
    }
    
    // Modify a portion near the end to trigger the break condition
    int trigger_pos = data_size - 10;
    if (trigger_pos >= 0 && trigger_pos % 3 == 0 && trigger_pos + 2 < data_size) {
        packet_data[trigger_pos] = 252;
        packet_data[trigger_pos + 1] = 1;
        packet_data[trigger_pos + 2] = 1;
    }

    buffer_ref.buffer = NULL;
    buffer_ref.data = packet_data;
    buffer_ref.size = data_size;

    av_packet.buf = &buffer_ref;
    av_packet.pts = 0;
    av_packet.dts = 0;
    av_packet.data = packet_data;
    av_packet.size = data_size;
    av_packet.stream_index = 0;
    av_packet.flags = 0;
    av_packet.side_data = NULL;
    av_packet.side_data_elems = 0;
    av_packet.duration = 0;
    av_packet.pos = 0;
    av_packet.convergence_duration = 0;

    i = 0;
}