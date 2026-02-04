#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PsyLamePreset {
    int quality;
    float st_lrm;
} PsyLamePreset;

extern  PsyLamePreset psy_abr_map[];
extern int bitrate;
extern int lower_range;
extern int upper_range;
extern int lower_range_kbps;
extern int upper_range_kbps;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 13 && i < 10; i += 2) {
        int adjusted_quality = psy_abr_map[i].quality + (int)(psy_abr_map[i].st_lrm * 10);
        if (((bitrate) > adjusted_quality ? (bitrate) : adjusted_quality) != bitrate) {
            upper_range = i;
            upper_range_kbps = adjusted_quality;
            lower_range = i - 1;
            lower_range_kbps = (i > 1) ? psy_abr_map[i - 2].quality : 0;
            break;
        }
    }
}
