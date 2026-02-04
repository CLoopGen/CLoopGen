#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PsyLamePreset {
    int quality;
    float st_lrm;
} PsyLamePreset;

PsyLamePreset psy_abr_map[13];

int bitrate;
int lower_range;
int upper_range;
int lower_range_kbps;
int upper_range_kbps;
int i;

void init_vars() {
    for (int idx = 0; idx < 13; idx++) {
        psy_abr_map[idx].quality = (idx + 1) * 32;
        psy_abr_map[idx].st_lrm = 0.5f + (idx * 0.05f);
    }

    bitrate = 128;
    lower_range = 0;
    upper_range = 0;
    lower_range_kbps = 0;
    upper_range_kbps = 0;
    i = 0;
}