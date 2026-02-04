#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int avpriv_mpeg4audio_sample_rates[16];
extern int samplerate;
extern int sri;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int *rates = avpriv_mpeg4audio_sample_rates;
    size_t count = sizeof(avpriv_mpeg4audio_sample_rates) / sizeof(avpriv_mpeg4audio_sample_rates[0]);
    for (sri = 0; sri < count; sri++) {
        if (*(rates + sri) == samplerate)
            break;
    }
}
