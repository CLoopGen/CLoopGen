#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _DPXFileInfo {
    unsigned int magic;
    unsigned int image_offset;
    char version[8];
    unsigned int file_size;
    unsigned int ditto_key;
    unsigned int generic_size;
    unsigned int industry_size;
    unsigned int user_size;
    char filename[100];
    char timestamp[24];
    char creator[100];
    char project[200];
    char copyright[200];
    unsigned int encrypt_key;
    char reserve[104];
} DPXFileInfo;

typedef struct _DPXImageElement {
    unsigned int data_sign;
    unsigned int low_data;
    float low_quantity;
    unsigned int high_data;
    float high_quantity;
    unsigned char descriptor;
    unsigned char transfer_characteristic;
    unsigned char colorimetric;
    unsigned char bit_size;
    unsigned short packing;
    unsigned short encoding;
    unsigned int data_offset;
    unsigned int end_of_line_padding;
    unsigned int end_of_image_padding;
    unsigned char description[32];
} DPXImageElement;

typedef struct _DPXImageInfo {
    unsigned short orientation;
    unsigned short number_elements;
    unsigned int pixels_per_line;
    unsigned int lines_per_element;
    DPXImageElement image_element[8];
    unsigned char reserve[52];
} DPXImageInfo;

typedef struct _DPXOrientationInfo {
    unsigned int x_offset;
    unsigned int y_offset;
    float x_center;
    float y_center;
    unsigned int x_size;
    unsigned int y_size;
    char filename[100];
    char timestamp[24];
    char device[32];
    char serial[32];
    unsigned short border[4];
    unsigned int aspect_ratio[2];
    unsigned char reserve[28];
} DPXOrientationInfo;

typedef struct _DPXFilmInfo {
    char id[2];
    char type[2];
    char offset[2];
    char prefix[6];
    char count[4];
    char format[32];
    unsigned int frame_position;
    unsigned int sequence_extent;
    unsigned int held_count;
    float frame_rate;
    float shutter_angle;
    char frame_id[32];
    char slate[100];
    char reserve[56];
} DPXFilmInfo;

typedef struct _DPXTelevisionInfo {
    unsigned int time_code;
    unsigned int user_bits;
    unsigned char interlace;
    unsigned char field_number;
    unsigned char video_signal;
    unsigned char padding;
    float horizontal_sample_rate;
    float vertical_sample_rate;
    float frame_rate;
    float time_offset;
    float gamma;
    float black_level;
    float black_gain;
    float break_point;
    float white_level;
    float integration_times;
    char reserve[76];
} DPXTelevisionInfo;

typedef struct _DPXUserInfo {
    char id[32];
} DPXUserInfo;

typedef struct DPXInfo {
    DPXFileInfo file;
    DPXImageInfo image;
    DPXOrientationInfo orientation;
    DPXFilmInfo film;
    DPXTelevisionInfo television;
    DPXUserInfo user;
} DPXInfo;

extern DPXInfo dpx;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        if (i % 2 == 0)
            dpx.orientation.border[i] = 0;
        else
            continue;
    }
}
