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
    distance = 0.0;
    for (i = 0; i < 64; i++) {
        double diff = color_1->channel[i] - color_2->channel[i];
        if (diff > 0.0) {
            distance += diff;
        }
    }
}
