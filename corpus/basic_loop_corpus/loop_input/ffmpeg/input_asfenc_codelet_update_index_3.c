#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVOptionType {
    AV_OPT_TYPE_FLAGS,
    AV_OPT_TYPE_INT,
    AV_OPT_TYPE_INT64,
    AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT,
    AV_OPT_TYPE_STRING,
    AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY,
    AV_OPT_TYPE_DICT,
    AV_OPT_TYPE_UINT64,
    AV_OPT_TYPE_CONST,
    AV_OPT_TYPE_IMAGE_SIZE,
    AV_OPT_TYPE_PIXEL_FMT,
    AV_OPT_TYPE_SAMPLE_FMT,
    AV_OPT_TYPE_VIDEO_RATE,
    AV_OPT_TYPE_DURATION,
    AV_OPT_TYPE_COLOR,
    AV_OPT_TYPE_CHANNEL_LAYOUT,
    AV_OPT_TYPE_BOOL
};

typedef struct AVRational {
    int num;
    int den;
} AVRational;

union {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
};

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    union {
        int64_t i64;
        double dbl;
        const char *str;
        AVRational q;
    } default_val;
    double min;
    double max;
    int flags;
    const char *unit;
};

typedef enum {
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_INPUT,
    AV_CLASS_CATEGORY_NB
} AVClassCategory;

typedef struct AVClass {
    const char *class_name;
    const char *(*item_name)(void *);
    const struct AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *);
    int (*query_ranges)(struct AVOptionRanges **, void *, const char *, int);
} AVClass;

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

typedef struct ASFPayload {
    uint8_t type;
    uint16_t size;
} ASFPayload;

typedef struct ASFStream {
    int num;
    unsigned char seq;
    AVPacket pkt;
    int frag_offset;
    int packet_obj_size;
    int timestamp;
    int64_t duration;
    int skip_to_key;
    int pkt_clean;
    int ds_span;
    int ds_packet_size;
    int ds_chunk_size;
    int64_t packet_pos;
    uint16_t stream_language_index;
    int palette_changed;
    uint32_t palette[256];
    int payload_ext_ct;
    ASFPayload payload[8];
} ASFStream;

enum AVIODataMarkerType {
    AVIO_DATA_MARKER_HEADER,
    AVIO_DATA_MARKER_SYNC_POINT,
    AVIO_DATA_MARKER_BOUNDARY_POINT,
    AVIO_DATA_MARKER_UNKNOWN,
    AVIO_DATA_MARKER_TRAILER,
    AVIO_DATA_MARKER_FLUSH_POINT
};

typedef struct AVIOContext {
    const AVClass *av_class;
    unsigned char *buffer;
    int buffer_size;
    unsigned char *buf_ptr;
    unsigned char *buf_end;
    void *opaque;
    int (*read_packet)(void *, uint8_t *, int);
    int (*write_packet)(void *, uint8_t *, int);
    int64_t (*seek)(void *, int64_t, int);
    int64_t pos;
    int eof_reached;
    int write_flag;
    int max_packet_size;
    unsigned long checksum;
    unsigned char *checksum_ptr;
    unsigned long (*update_checksum)(unsigned long, const uint8_t *, unsigned int);
    int error;
    int (*read_pause)(void *, int);
    int64_t (*read_seek)(void *, int, int64_t, int);
    int seekable;
    int64_t maxsize;
    int direct;
    int64_t bytes_read;
    int seek_count;
    int writeout_count;
    int orig_buffer_size;
    int short_seek_threshold;
    const char *protocol_whitelist;
    const char *protocol_blacklist;
    int (*write_data_type)(void *, uint8_t *, int, enum AVIODataMarkerType, int64_t);
    int ignore_boundary_point;
    enum AVIODataMarkerType current_type;
    int64_t last_time;
    int (*short_seek_get)(void *);
    int64_t written;
    unsigned char *buf_ptr_max;
    int min_packet_size;
} AVIOContext;

typedef struct ASFIndex {
    uint32_t packet_number;
    uint16_t packet_count;
    uint64_t send_time;
    uint64_t offset;
} ASFIndex;

typedef struct ASFContext {
    AVClass *av_class;
    uint32_t seqno;
    int is_streamed;
    ASFStream streams[128];
    const char *languages[128];
    int nb_languages;
    int64_t creation_time;
    uint64_t nb_packets;
    int64_t duration;
    unsigned char multi_payloads_present;
    int packet_size_left;
    int64_t packet_timestamp_start;
    int64_t packet_timestamp_end;
    unsigned int packet_nb_payloads;
    uint8_t packet_buf[65536];
    AVIOContext pb;
    uint64_t data_offset;
    ASFIndex *index_ptr;
    uint32_t nb_index_memory_alloc;
    uint16_t maximum_packet;
    uint32_t next_packet_number;
    uint16_t next_packet_count;
    uint64_t next_packet_offset;
    int next_start_sec;
    int end_sec;
    int packet_size;
} ASFContext;

int start_sec;
ASFContext *asf;
int i;

static ASFIndex index_data[100000];

void init_vars() {
    start_sec = 100000;
    
    asf = (ASFContext*)malloc(sizeof(ASFContext));
    if (!asf) return;
    
    asf->av_class = NULL;
    asf->seqno = 0;
    asf->is_streamed = 0;
    asf->nb_languages = 0;
    asf->creation_time = 0;
    asf->nb_packets = 0;
    asf->duration = 0;
    asf->multi_payloads_present = 0;
    asf->packet_size_left = 0;
    asf->packet_timestamp_start = 0;
    asf->packet_timestamp_end = 0;
    asf->packet_nb_payloads = 0;
    asf->data_offset = 0;
    asf->nb_index_memory_alloc = 100000;
    asf->maximum_packet = 0;
    asf->next_packet_number = 12345;
    asf->next_packet_count = 6789;
    asf->next_packet_offset = 987654321;
    asf->next_start_sec = 0;
    asf->end_sec = 200000;
    asf->packet_size = 0;
    
    for (int j = 0; j < 128; j++) {
        asf->streams[j].num = j;
        asf->streams[j].seq = j % 256;
        asf->streams[j].frag_offset = 0;
        asf->streams[j].packet_obj_size = 0;
        asf->streams[j].timestamp = 0;
        asf->streams[j].duration = 0;
        asf->streams[j].skip_to_key = 0;
        asf->streams[j].pkt_clean = 0;
        asf->streams[j].ds_span = 0;
        asf->streams[j].ds_packet_size = 0;
        asf->streams[j].ds_chunk_size = 0;
        asf->streams[j].packet_pos = 0;
        asf->streams[j].stream_language_index = 0;
        asf->streams[j].palette_changed = 0;
        asf->streams[j].payload_ext_ct = 0;
        for (int k = 0; k < 8; k++) {
            asf->streams[j].payload[k].type = 0;
            asf->streams[j].payload[k].size = 0;
        }
        for (int k = 0; k < 256; k++) {
            asf->streams[j].palette[k] = 0;
        }
    }
    
    asf->pb.av_class = NULL;
    asf->pb.buffer = NULL;
    asf->pb.buffer_size = 0;
    asf->pb.buf_ptr = NULL;
    asf->pb.buf_end = NULL;
    asf->pb.opaque = NULL;
    asf->pb.read_packet = NULL;
    asf->pb.write_packet = NULL;
    asf->pb.seek = NULL;
    asf->pb.pos = 0;
    asf->pb.eof_reached = 0;
    asf->pb.write_flag = 0;
    asf->pb.max_packet_size = 0;
    asf->pb.checksum = 0;
    asf->pb.checksum_ptr = NULL;
    asf->pb.update_checksum = NULL;
    asf->pb.error = 0;
    asf->pb.read_pause = NULL;
    asf->pb.read_seek = NULL;
    asf->pb.seekable = 0;
    asf->pb.maxsize = 0;
    asf->pb.direct = 0;
    asf->pb.bytes_read = 0;
    asf->pb.seek_count = 0;
    asf->pb.writeout_count = 0;
    asf->pb.orig_buffer_size = 0;
    asf->pb.short_seek_threshold = 0;
    asf->pb.protocol_whitelist = NULL;
    asf->pb.protocol_blacklist = NULL;
    asf->pb.write_data_type = NULL;
    asf->pb.ignore_boundary_point = 0;
    asf->pb.current_type = AVIO_DATA_MARKER_UNKNOWN;
    asf->pb.last_time = 0;
    asf->pb.short_seek_get = NULL;
    asf->pb.written = 0;
    asf->pb.buf_ptr_max = NULL;
    asf->pb.min_packet_size = 0;
    
    for (int j = 0; j < 65536; j++) {
        asf->packet_buf[j] = 0;
    }
    
    asf->index_ptr = index_data;
}