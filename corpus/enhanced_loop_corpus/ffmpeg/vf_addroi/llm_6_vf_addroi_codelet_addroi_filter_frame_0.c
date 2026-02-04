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

extern AVRegionOfInterest *roi;
extern AVFrameSideData *sd;
extern  AVRegionOfInterest *old_roi;
extern uint32_t old_roi_size;
extern int nb_roi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried dependency (WAW) by making each iteration depend on the previous write
    if (nb_roi > 1) {
        roi[0] = (AVRegionOfInterest){.self_size = sizeof(*roi), .top = 0, .bottom = 0, .left = 0, .right = 0, .qoffset = (AVRational){0,1}};
        for (i = 1; i < nb_roi; i++) {
            const AVRegionOfInterest *prev_old_roi = (const AVRegionOfInterest *)(sd->data + old_roi_size * (i - 1));
            const AVRegionOfInterest *curr_old_roi = (const AVRegionOfInterest *)(sd->data + old_roi_size * i);
            // Current iteration depends on prior written value via WAW-like chain
            roi[i] = (AVRegionOfInterest){
                .self_size = sizeof(*roi),
                .top = curr_old_roi->top + roi[i-1].top,
                .bottom = curr_old_roi->bottom,
                .left = curr_old_roi->left,
                .right = curr_old_roi->right,
                .qoffset = curr_old_roi->qoffset
            };
        }
    }
}
