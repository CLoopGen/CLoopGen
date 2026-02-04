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
    for (i = 1; i < 15; i++) {
        int current_quality = psy_abr_map[i].quality;
        int prev_quality = psy_abr_map[i - 1].quality;
        float avg_st_lrm = (psy_abr_map[i].st_lrm + psy_abr_map[i - 1].st_lrm) / 2.0f;
        int weighted_current = (int)(current_quality * avg_st_lrm);
        int weighted_prev = (int)(prev_quality * avg_st_lrm);
        
        if (bitrate <= weighted_current) {
            upper_range = i;
            upper_range_kbps = current_quality;
            lower_range = i - 1;
            lower_range_kbps = prev_quality;
            break;
        }
    }
}
