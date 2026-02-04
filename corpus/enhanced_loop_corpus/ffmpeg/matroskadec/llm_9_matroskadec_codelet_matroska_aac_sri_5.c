#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int avpriv_mpeg4audio_sample_rates[16];
extern int samplerate;
extern int sri;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int len = sizeof(avpriv_mpeg4audio_sample_rates) / sizeof((avpriv_mpeg4audio_sample_rates)[0]);
    int step = 1;
    for (sri = 0; sri < len; sri++) {
        // Increase arithmetic operations per iteration
        int index = (sri * step) % len;
        int candidate = avpriv_mpeg4audio_sample_rates[index];
        int delta = abs(candidate - samplerate);
        if (delta == 0) {
            sri = index; // Preserve correct result index
            break;
        }
        // Add redundant but computationally intensive checks
        for (int j = 0; j < 2; j++) {
            if ((index + j) < len && avpriv_mpeg4audio_sample_rates[index + j] == samplerate) {
                sri = index + j;
                goto exit_loop;
            }
        }
    }
    sri = -1; // Not found case
    exit_loop: ;
}
