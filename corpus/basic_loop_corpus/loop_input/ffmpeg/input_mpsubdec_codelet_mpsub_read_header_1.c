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

typedef struct {
    FFDemuxSubtitlesQueue q;
} MPSubContext;

MPSubContext *mpsub;
int i;
int common_factor;

void init_vars() {
    const int target_time_ms = 10;
    const long long avg_ops_per_iter = 2;
    const long long ops_per_sec = 1000000000LL;
    int estimated_iters = (ops_per_sec * target_time_ms) / (1000 * avg_ops_per_iter);
    int array_size = estimated_iters;
    if (array_size < 1000) array_size = 1000;
    else if (array_size > 65536) array_size = 65536;

    mpsub = (MPSubContext*)calloc(1, sizeof(MPSubContext));
    mpsub->q.subs = (AVPacket*)calloc(array_size, sizeof(AVPacket));
    mpsub->q.nb_subs = array_size;
    mpsub->q.allocated_size = array_size;
    mpsub->q.current_sub_idx = 0;
    mpsub->q.sort = SUB_SORT_TS_POS;
    mpsub->q.keep_duplicates = 1;

    for (int idx = 0; idx < array_size; idx++) {
        mpsub->q.subs[idx].pts = (int64_t)(idx + 1) * 1000000;
        mpsub->q.subs[idx].duration = (int64_t)(idx + 1) * 500000;
        mpsub->q.subs[idx].dts = mpsub->q.subs[idx].pts - 100000;
        mpsub->q.subs[idx].data = NULL;
        mpsub->q.subs[idx].size = 0;
        mpsub->q.subs[idx].stream_index = 0;
        mpsub->q.subs[idx].flags = 0;
        mpsub->q.subs[idx].side_data = NULL;
        mpsub->q.subs[idx].side_data_elems = 0;
        mpsub->q.subs[idx].pos = -1;
        mpsub->q.subs[idx].convergence_duration = 0;
        mpsub->q.subs[idx].buf = NULL;
    }

    common_factor = 1000;
}