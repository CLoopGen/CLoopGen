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
for (i = 1; i < 13; i++) {
    if (((bitrate) > (psy_abr_map[i].quality) ? (bitrate) : (psy_abr_map[i].quality)) != bitrate) {
        upper_range = i;
        upper_range_kbps = psy_abr_map[i].quality;
        lower_range = i - 1;
        lower_range_kbps = psy_abr_map[i - 1].quality;
        break;
    }
}

}
