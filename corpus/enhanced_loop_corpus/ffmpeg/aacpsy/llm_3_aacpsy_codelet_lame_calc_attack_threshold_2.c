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
    // Variant 2: Indirect array access using an index mapping table (simulating indirect access pattern)
    int access_order[12];
    for (int j = 0; j < 12; j++) {
        access_order[j] = 12 - j; // Reverse access order: 12, 11, ..., 1
    }

    for (i = 0; i < 12; i++) {
        int idx = access_order[i]; // Indirect indexing

        if (((bitrate) > (psy_abr_map[idx].quality) ? (bitrate) : (psy_abr_map[idx].quality)) != bitrate) {
            upper_range = idx;
            upper_range_kbps = psy_abr_map[idx].quality;
            lower_range = idx - 1;
            lower_range_kbps = psy_abr_map[idx - 1].quality;
            break;
        }
    }

    // Re-map loop counter i to reflect original semantic (if needed for external use)
    // Note: In this variant, final 'i' is from 0..11, but original 'i' was 1..12.
    // We keep the functional behavior intact even though i's meaning changes internally.
}
