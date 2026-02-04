#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVRegionOfInterest {
    uint32_t self_size;
    int top;
    int bottom;
    int left;
    int right;
    AVRational qoffset;
} AVRegionOfInterest;

enum AVFrameSideDataType {
    AV_FRAME_DATA_PANSCAN,
    AV_FRAME_DATA_A53_CC,
    AV_FRAME_DATA_STEREO3D,
    AV_FRAME_DATA_MATRIXENCODING,
    AV_FRAME_DATA_DOWNMIX_INFO,
    AV_FRAME_DATA_REPLAYGAIN,
    AV_FRAME_DATA_DISPLAYMATRIX,
    AV_FRAME_DATA_AFD,
    AV_FRAME_DATA_MOTION_VECTORS,
    AV_FRAME_DATA_SKIP_SAMPLES,
    AV_FRAME_DATA_AUDIO_SERVICE_TYPE,
    AV_FRAME_DATA_MASTERING_DISPLAY_METADATA,
    AV_FRAME_DATA_GOP_TIMECODE,
    AV_FRAME_DATA_SPHERICAL,
    AV_FRAME_DATA_CONTENT_LIGHT_LEVEL,
    AV_FRAME_DATA_ICC_PROFILE,
    AV_FRAME_DATA_QP_TABLE_PROPERTIES,
    AV_FRAME_DATA_QP_TABLE_DATA,
    AV_FRAME_DATA_S12M_TIMECODE,
    AV_FRAME_DATA_DYNAMIC_HDR_PLUS,
    AV_FRAME_DATA_REGIONS_OF_INTEREST,
    AV_FRAME_DATA_VIDEO_ENC_PARAMS
};

typedef struct AVDictionary AVDictionary;

typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

typedef struct AVFrameSideData {
    enum AVFrameSideDataType type;
    uint8_t *data;
    int size;
    AVDictionary *metadata;
    AVBufferRef *buf;
} AVFrameSideData;

AVRegionOfInterest *roi;
AVFrameSideData *sd;
const AVRegionOfInterest *old_roi;
uint32_t old_roi_size;
int nb_roi;
int i;

static AVRegionOfInterest *roi_storage;
static uint8_t *sd_data;
static AVFrameSideData sd_storage;

void init_vars() {
    old_roi_size = sizeof(AVRegionOfInterest);
    nb_roi = (1024 * 1024) / old_roi_size;  // Aim for ~1MB of data
    if (nb_roi < 2) nb_roi = 2;

    roi_storage = calloc(nb_roi, sizeof(AVRegionOfInterest));
    sd_data = malloc(nb_roi * old_roi_size);
    sd = &sd_storage;
    sd->data = sd_data;
    sd->size = nb_roi * old_roi_size;
    sd->buf = NULL;
    sd->metadata = NULL;
    sd->type = AV_FRAME_DATA_REGIONS_OF_INTEREST;

    roi = roi_storage;

    for (int j = 0; j < nb_roi; j++) {
        AVRegionOfInterest *src = (AVRegionOfInterest*)&sd_data[old_roi_size * j];
        src->self_size = old_roi_size;
        src->top = j * 2;
        src->bottom = j * 2 + 10;
        src->left = j * 3;
        src->right = j * 3 + 15;
        src->qoffset.num = j + 1;
        src->qoffset.den = j + 2;
    }
}