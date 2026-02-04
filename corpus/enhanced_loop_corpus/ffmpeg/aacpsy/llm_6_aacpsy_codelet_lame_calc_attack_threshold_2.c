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
    int temp_upper = -1;
    int temp_lower = -1;
    int temp_upper_kbps = 0;
    int temp_lower_kbps = 0;
    for (i = 1; i < 13; i++) {
        int current_qual = psy_abr_map[i].quality;
        int prev_qual = psy_abr_map[i - 1].quality;
        if (((bitrate) > current_qual ? (bitrate) : current_qual) != bitrate) {
            temp_upper = i;
            temp_upper_kbps = current_qual;
            temp_lower = i - 1;
            temp_lower_kbps = prev_qual;
            break;
        }
    }
    // Introduce WAW dependency: write to shared globals only after loop
    upper_range = temp_upper;
    upper_range_kbps = temp_upper_kbps;
    lower_range = temp_lower;
    lower_range_kbps = temp_lower_kbps;
}
