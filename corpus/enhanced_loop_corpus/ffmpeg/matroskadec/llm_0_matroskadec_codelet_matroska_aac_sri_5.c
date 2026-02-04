#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int avpriv_mpeg4audio_sample_rates[16];
extern int samplerate;
extern int sri;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (sri = 0; sri < (sizeof (avpriv_mpeg4audio_sample_rates) / sizeof ((avpriv_mpeg4audio_sample_rates)[0])); sri++) {
            if (avpriv_mpeg4audio_sample_rates[sri] == samplerate)
                break;
        }
    }
}
