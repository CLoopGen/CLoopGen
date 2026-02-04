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

typedef struct MOVStts {
    unsigned int count;
    int duration;
} MOVStts;

typedef struct MOVStsc {
    int first;
    int count;
    int id;
} MOVStsc;

typedef struct MOVElst {
    int64_t duration;
    int64_t time;
    float rate;
} MOVElst;

typedef struct MOVIndexRange {
    int64_t start;
    int64_t end;
} MOVIndexRange;

typedef struct MOVDref {
    uint32_t type;
    char *path;
    char *dir;
    char volume[28];
    char filename[64];
    int16_t nlvl_to;
    int16_t nlvl_from;
} MOVDref;

typedef struct MOVSbgp {
    unsigned int count;
    unsigned int index;
} MOVSbgp;

enum AVStereo3DType {
    AV_STEREO3D_2D,
    AV_STEREO3D_SIDEBYSIDE,
    AV_STEREO3D_TOPBOTTOM,
    AV_STEREO3D_FRAMESEQUENCE,
    AV_STEREO3D_CHECKERBOARD,
    AV_STEREO3D_SIDEBYSIDE_QUINCUNX,
    AV_STEREO3D_LINES,
    AV_STEREO3D_COLUMNS
};


enum AVStereo3DView {
    AV_STEREO3D_VIEW_PACKED,
    AV_STEREO3D_VIEW_LEFT,
    AV_STEREO3D_VIEW_RIGHT
};


typedef struct AVStereo3D {
    enum AVStereo3DType type;
    int flags;
    enum AVStereo3DView view;
} AVStereo3D;

enum AVSphericalProjection {
    AV_SPHERICAL_EQUIRECTANGULAR,
    AV_SPHERICAL_CUBEMAP,
    AV_SPHERICAL_EQUIRECTANGULAR_TILE
};


typedef struct AVSphericalMapping {
    enum AVSphericalProjection projection;
    int32_t yaw;
    int32_t pitch;
    int32_t roll;
    uint32_t bound_left;
    uint32_t bound_top;
    uint32_t bound_right;
    uint32_t bound_bottom;
    uint32_t padding;
} AVSphericalMapping;

typedef struct AVMasteringDisplayMetadata {
    AVRational display_primaries[3][2];
    AVRational white_point[2];
    AVRational min_luminance;
    AVRational max_luminance;
    int has_primaries;
    int has_luminance;
} AVMasteringDisplayMetadata;

typedef struct AVContentLightMetadata {
    unsigned int MaxCLL;
    unsigned int MaxFALL;
} AVContentLightMetadata;

typedef struct AVSubsampleEncryptionInfo {
    unsigned int bytes_of_clear_data;
    unsigned int bytes_of_protected_data;
} AVSubsampleEncryptionInfo;

typedef struct AVEncryptionInfo {
    uint32_t scheme;
    uint32_t crypt_byte_block;
    uint32_t skip_byte_block;
    uint8_t *key_id;
    uint32_t key_id_size;
    uint8_t *iv;
    uint32_t iv_size;
    AVSubsampleEncryptionInfo *subsamples;
    uint32_t subsample_count;
} AVEncryptionInfo;

typedef struct MOVEncryptionIndex {
    unsigned int nb_encrypted_samples;
    AVEncryptionInfo **encrypted_samples;
    uint8_t *auxiliary_info_sizes;
    size_t auxiliary_info_sample_count;
    uint8_t auxiliary_info_default_size;
    uint64_t *auxiliary_offsets;
    size_t auxiliary_offsets_count;
} MOVEncryptionIndex;

struct {
    struct AVAESCTR *aes_ctr;
    unsigned int per_sample_iv_size;
    AVEncryptionInfo *default_encrypted_sample;
    MOVEncryptionIndex *encryption_index;
};


typedef struct MOVStreamContext {
    AVIOContext *pb;
    int pb_is_copied;
    int ffindex;
    int next_chunk;
    unsigned int chunk_count;
    int64_t *chunk_offsets;
    unsigned int stts_count;
    MOVStts *stts_data;
    unsigned int sdtp_count;
    uint8_t *sdtp_data;
    unsigned int ctts_count;
    unsigned int ctts_allocated_size;
    MOVStts *ctts_data;
    unsigned int stsc_count;
    MOVStsc *stsc_data;
    unsigned int stsc_index;
    int stsc_sample;
    unsigned int stps_count;
    unsigned int *stps_data;
    MOVElst *elst_data;
    unsigned int elst_count;
    int ctts_index;
    int ctts_sample;
    unsigned int sample_size;
    unsigned int stsz_sample_size;
    unsigned int sample_count;
    int *sample_sizes;
    int keyframe_absent;
    unsigned int keyframe_count;
    int *keyframes;
    int time_scale;
    int64_t time_offset;
    int64_t min_corrected_pts;
    int current_sample;
    int64_t current_index;
    MOVIndexRange *index_ranges;
    MOVIndexRange *current_index_range;
    unsigned int bytes_per_frame;
    unsigned int samples_per_frame;
    int dv_audio_container;
    int pseudo_stream_id;
    int16_t audio_cid;
    unsigned int drefs_count;
    MOVDref *drefs;
    int dref_id;
    int timecode_track;
    int width;
    int height;
    int dts_shift;
    uint32_t palette[256];
    int has_palette;
    int64_t data_size;
    uint32_t tmcd_flags;
    int64_t track_end;
    int start_pad;
    unsigned int rap_group_count;
    MOVSbgp *rap_group;
    int nb_frames_for_fps;
    int64_t duration_for_fps;
    uint8_t **extradata;
    int *extradata_size;
    int last_stsd_index;
    int stsd_count;
    int stsd_version;
    int32_t *display_matrix;
    AVStereo3D *stereo3d;
    AVSphericalMapping *spherical;
    size_t spherical_size;
    AVMasteringDisplayMetadata *mastering;
    AVContentLightMetadata *coll;
    size_t coll_size;
    uint32_t format;
    int has_sidx;
    struct {
        struct AVAESCTR *aes_ctr;
        unsigned int per_sample_iv_size;
        AVEncryptionInfo *default_encrypted_sample;
        MOVEncryptionIndex *encryption_index;
    } cenc;
} MOVStreamContext;

extern MOVStreamContext *sc;
extern int time_sample;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sc->ctts_count; i++) {
        int next = time_sample + sc->ctts_data[i].count;
        if (next > sc->current_sample) {
            sc->ctts_index = i;
            sc->ctts_sample = sc->current_sample - time_sample;
            return;
        }
        time_sample = next;
    }
}
