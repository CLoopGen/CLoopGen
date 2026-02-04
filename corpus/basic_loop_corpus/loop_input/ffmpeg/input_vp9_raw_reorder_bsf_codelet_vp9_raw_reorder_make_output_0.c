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

typedef struct VP9RawReorderFrame {
    AVPacket *packet;
    int needs_output;
    int needs_display;
    int64_t pts;
    int64_t sequence;
    unsigned int slots;
    unsigned int profile;
    unsigned int show_existing_frame;
    unsigned int frame_to_show;
    unsigned int frame_type;
    unsigned int show_frame;
    unsigned int refresh_frame_flags;
} VP9RawReorderFrame;

typedef struct VP9RawReorderContext {
    int64_t sequence;
    VP9RawReorderFrame *slot[8];
    VP9RawReorderFrame *next_frame;
} VP9RawReorderContext;

VP9RawReorderContext *ctx;
VP9RawReorderFrame *next_output;
VP9RawReorderFrame *next_display;
VP9RawReorderFrame *frame;
int s;

static AVPacket **packets;
static AVBufferRef **buffer_refs;
static uint8_t **raw_data_buffers;
static int num_frames = 8;

void init_vars() {
    packets = calloc(num_frames, sizeof(AVPacket*));
    buffer_refs = calloc(num_frames, sizeof(AVBufferRef*));
    raw_data_buffers = calloc(num_frames, sizeof(uint8_t*));

    for (int i = 0; i < num_frames; i++) {
        raw_data_buffers[i] = malloc(1024);
        buffer_refs[i] = malloc(sizeof(AVBufferRef));
        buffer_refs[i]->data = raw_data_buffers[i];
        buffer_refs[i]->size = 1024;
        buffer_refs[i]->buffer = NULL;

        packets[i] = malloc(sizeof(AVPacket));
        packets[i]->buf = buffer_refs[i];
        packets[i]->pts = i * 1000;
        packets[i]->dts = i * 1000;
        packets[i]->data = raw_data_buffers[i];
        packets[i]->size = 1024;
        packets[i]->stream_index = 0;
        packets[i]->flags = 0;
        packets[i]->side_data = NULL;
        packets[i]->side_data_elems = 0;
        packets[i]->duration = 1000;
        packets[i]->pos = -1;
        packets[i]->convergence_duration = 0;
    }

    ctx = malloc(sizeof(VP9RawReorderContext));
    ctx->sequence = 0;
    ctx->next_frame = NULL;

    for (int i = 0; i < 8; i++) {
        ctx->slot[i] = NULL;
    }

    for (int i = 0; i < 8; i++) {
        VP9RawReorderFrame *f = malloc(sizeof(VP9RawReorderFrame));
        f->packet = packets[i];
        f->needs_output = 1;
        f->needs_display = 1;
        f->pts = packets[i]->pts;
        f->sequence = i;
        f->slots = 0;
        f->profile = 0;
        f->show_existing_frame = 0;
        f->frame_to_show = 0;
        f->frame_type = 0;
        f->show_frame = 1;
        f->refresh_frame_flags = 0;

        ctx->slot[i] = f;
    }

    next_output = NULL;
    next_display = NULL;
    frame = NULL;
    s = 0;
}