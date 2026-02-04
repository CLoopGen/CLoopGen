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
    for (i = 0; i < 8; i++) {
        for (ssize_t j = 0; j < 8; j++) {
            ssize_t idx = i * 8 + j;
            distance += color_1->channel[idx] - (double)color_2->channel[idx];
        }
    }
}
