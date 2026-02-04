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

enum sub_sort {
    SUB_SORT_TS_POS = 0,
    SUB_SORT_POS_TS
};

typedef struct {
    AVPacket *subs;
    int nb_subs;
    int allocated_size;
    int current_sub_idx;
    enum sub_sort sort;
    int keep_duplicates;
} FFDemuxSubtitlesQueue;

FFDemuxSubtitlesQueue *q;
int stream_index;
int64_t min_ts;
int i;
int idx;
int64_t ts_selected;

static AVPacket *alloc_packets(size_t count) {
    AVPacket *packets = calloc(count, sizeof(AVPacket));
    if (!packets) exit(1);
    for (size_t i = 0; i < count; i++) {
        packets[i].pts = (int64_t)(i * 1000);
        packets[i].duration = 500;
        packets[i].stream_index = (i % 3);
        packets[i].size = 1024;
    }
    return packets;
}

void init_vars() {
    const size_t total_packets = 100000;

    AVPacket *packets = alloc_packets(total_packets);

    q = malloc(sizeof(FFDemuxSubtitlesQueue));
    if (!q) exit(1);

    q->subs = packets;
    q->nb_subs = total_packets;
    q->allocated_size = total_packets;
    q->current_sub_idx = 0;
    q->sort = SUB_SORT_TS_POS;
    q->keep_duplicates = 1;

    stream_index = 1;
    min_ts = 10000;
    ts_selected = 50000;
    idx = total_packets - 1;
    i = 0;
}