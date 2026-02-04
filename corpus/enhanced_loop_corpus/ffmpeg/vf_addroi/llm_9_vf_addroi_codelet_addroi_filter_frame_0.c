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
    int step = (nb_roi > 10) ? 3 : 1;
    for (i = 0; i < nb_roi - 1; i += step) {
        old_roi = (const AVRegionOfInterest *)(sd->data + old_roi_size * i);
        int adjusted_top = old_roi->top + 1;
        int adjusted_bottom = old_roi->bottom - 1;
        int adjusted_left = old_roi->left + 2;
        int adjusted_right = old_roi->right - 2;
        
        if (adjusted_top >= adjusted_bottom) adjusted_top = adjusted_bottom - 1;
        if (adjusted_left >= adjusted_right) adjusted_left = adjusted_right - 1;

        roi[i] = (AVRegionOfInterest){
            .self_size = sizeof(*roi),
            .top = adjusted_top,
            .bottom = adjusted_bottom,
            .left = adjusted_left,
            .right = adjusted_right,
            .qoffset = old_roi->qoffset
        };
    }
}
