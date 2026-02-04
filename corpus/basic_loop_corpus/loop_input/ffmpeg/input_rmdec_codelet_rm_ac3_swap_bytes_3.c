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

// External variables
AVPacket *pkt;
uint8_t *ptr;
int j;

// Global data buffers
static uint8_t *global_data_buffer;
static AVPacket global_pkt;
static AVBufferRef global_buf_ref;

void init_vars() {
    // Allocate approximately 64MB of data to target ~0.01s runtime
    const int data_size = 64 * 1024 * 1024;
    global_data_buffer = (uint8_t*)malloc(data_size);
    if (!global_data_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize buffer reference
    global_buf_ref.buffer = NULL;
    global_buf_ref.data = global_data_buffer;
    global_buf_ref.size = data_size;

    // Initialize packet
    pkt = &global_pkt;
    global_pkt.buf = &global_buf_ref;
    global_pkt.pts = 0;
    global_pkt.dts = 0;
    global_pkt.data = global_data_buffer;
    global_pkt.size = data_size;  // Ensure loop runs over full allocated size
    global_pkt.stream_index = 0;
    global_pkt.flags = 0;
    global_pkt.side_data = NULL;
    global_pkt.side_data_elems = 0;
    global_pkt.duration = 0;
    global_pkt.pos = 0;
    global_pkt.convergence_duration = 0;

    // Initialize ptr to start of data
    ptr = global_data_buffer;

    // Initialize j to 0 (loop control)
    j = 0;
}