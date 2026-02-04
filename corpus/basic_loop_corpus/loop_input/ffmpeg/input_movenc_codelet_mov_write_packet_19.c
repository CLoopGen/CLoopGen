#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVBuffer AVBuffer;

struct AVBuffer {
    // Minimal definition to satisfy compilation
};

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

static AVBuffer g_buffer;
static uint8_t *g_data_ptr;
static AVBufferRef g_buf_ref;
static AVPacketSideData *g_side_data;
static AVPacket g_pkt;

AVPacket *pkt = &g_pkt;
int i;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128MB for ~0.01s runtime on modern CPU

    g_data_ptr = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!g_data_ptr) exit(1);

    for (size_t j = 0; j < data_size; j++) {
        g_data_ptr[j] = (uint8_t)(j & 0xFF);
    }

    g_buf_ref.buffer = &g_buffer;
    g_buf_ref.data = g_data_ptr;
    g_buf_ref.size = (int)data_size;

    g_side_data = NULL;

    g_pkt.buf = &g_buf_ref;
    g_pkt.pts = 0;
    g_pkt.dts = 0;
    g_pkt.data = g_data_ptr;
    g_pkt.size = (int)data_size;
    g_pkt.stream_index = 0;
    g_pkt.flags = 0;
    g_pkt.side_data = g_side_data;
    g_pkt.side_data_elems = 0;
    g_pkt.duration = 0;
    g_pkt.pos = -1;
    g_pkt.convergence_duration = 0;
}