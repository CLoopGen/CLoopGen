#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int avpriv_mpeg4audio_sample_rates[16];
extern int samplerate;
extern int sri;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    size_t count = sizeof(indices) / sizeof(indices[0]);
    for (sri = 0; sri < count; sri++) {
        if (avpriv_mpeg4audio_sample_rates[indices[sri]] == samplerate)
            break;
    }
}
