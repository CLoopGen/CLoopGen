#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

AVPacket *pkt;
uint32_t *flags;
uint32_t c;
int i;
int closed_gop;

static uint8_t *data_buffer;
static AVBufferRef buffer_ref;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB to target ~0.01s runtime on modern CPU

    data_buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!data_buffer) exit(1);

    pkt = (AVPacket*)calloc(1, sizeof(AVPacket));
    if (!pkt) exit(1);

    pkt->buf = &buffer_ref;
    pkt->data = data_buffer;
    pkt->size = data_size - 4; // Ensure i + 4 stays in bounds
    pkt->pts = 0;
    pkt->dts = 0;
    pkt->stream_index = 0;
    pkt->flags = 0;
    pkt->side_data = NULL;
    pkt->side_data_elems = 0;
    pkt->duration = 0;
    pkt->pos = -1;
    pkt->convergence_duration = 0;

    buffer_ref.buffer = NULL;
    buffer_ref.data = data_buffer;
    buffer_ref.size = data_size;

    flags = (uint32_t*)calloc(1, sizeof(uint32_t));
    if (!flags) exit(1);

    c = 0;
    i = 0;
    closed_gop = 0;

    // Insert pattern to trigger logic: place 0x01,0x00 at offset where c==256 (i.e., 0x0100)
    // and set temp_ref non-zero, so *flags becomes 2.
    // Also insert pattern for c==440 (0x01B8) to set closed_gop.
    for (int j = 0; j < data_size - 8; j += 100003) { // prime spacing
        if (j + 5 < data_size) {
            uint32_t val = rand() % 256;
            data_buffer[j] = (val >> 8) & 0xFF;
            data_buffer[j+1] = val & 0xFF;
            data_buffer[j+2] = rand() % 256;
            data_buffer[j+3] = rand() % 256;
            data_buffer[j+4] = rand() % 256;
        }
    }

    // Insert known pattern for c == 440 (0x01B8): bytes [0x01, 0xB8, x, x, x], then set bit 6 of next+4
    int p1 = 1000;
    data_buffer[p1] = 0x01;
    data_buffer[p1+1] = 0xB8;
    data_buffer[p1+2] = 0x12;
    data_buffer[p1+3] = 0x34;
    data_buffer[p1+4] = 0x80; // sets closed_gop = 1 when shifted and masked

    // Insert pattern for c == 256 (0x0100): [0x01, 0x00, x, x]
    int p2 = 2000;
    data_buffer[p2] = 0x01;
    data_buffer[p2+1] = 0x00;
    data_buffer[p2+2] = 0x01; // ensures temp_ref = ((0x00 << 2) | (0x01 >> 6)) = 0 -> false
    data_buffer[p2+3] = 0x00;
}