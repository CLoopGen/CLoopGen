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
    for (i = 0; i < 64; i += 4) {
        distance += color_1->channel[i] - (double)color_2->channel[i];
        if (i + 1 < 64) distance += color_1->channel[i + 1] - (double)color_2->channel[i + 1];
        if (i + 2 < 64) distance += color_1->channel[i + 2] - (double)color_2->channel[i + 2];
        if (i + 3 < 64) distance += color_1->channel[i + 3] - (double)color_2->channel[i + 3];
    }
}
