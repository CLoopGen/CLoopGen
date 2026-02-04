#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PixelChannels {
    double channel[64];
} PixelChannels;

extern  PixelChannels *color_1;
extern  PixelChannels *color_2;
extern double distance;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_distance = 0.0;
    for (i = 0; i < 64; i++) {
        temp_distance += color_1->channel[i] - color_2->channel[i];
    }
    distance += temp_distance;
}
