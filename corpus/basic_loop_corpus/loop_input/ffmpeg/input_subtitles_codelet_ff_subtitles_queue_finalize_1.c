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
int i;

static AVPacket *create_packets(int count) {
    AVPacket *packets = calloc(count, sizeof(AVPacket));
    if (!packets) exit(1);

    for (int idx = 0; idx < count; idx++) {
        packets[idx].pts = idx * 1000;
        packets[idx].duration = -1;
        packets[idx].data = NULL;
        packets[idx].size = 0;
        packets[idx].buf = NULL;
        packets[idx].side_data = NULL;
        packets[idx].side_data_elems = 0;
        packets[idx].pos = -1;
    }

    return packets;
}

void init_vars() {
    const int target_time_ms = 10;
    const int iterations_per_packet = 2;
    const long long base_freq = 2000000000;
    const long long ops_per_sec = base_freq / 2;
    const int approx_ops_per_iter = 5;
    int nb_subs = (target_time_ms * ops_per_sec) / (1000 * approx_ops_per_iter * iterations_per_packet);
    if (nb_subs < 1000) nb_subs = 1000;
    else if (nb_subs > 1000000) nb_subs = 1000000;

    q = malloc(sizeof(FFDemuxSubtitlesQueue));
    if (!q) exit(1);

    q->subs = create_packets(nb_subs);
    q->nb_subs = nb_subs;
    q->allocated_size = nb_subs;
    q->current_sub_idx = 0;
    q->sort = SUB_SORT_TS_POS;
    q->keep_duplicates = 0;

    i = 0;
}