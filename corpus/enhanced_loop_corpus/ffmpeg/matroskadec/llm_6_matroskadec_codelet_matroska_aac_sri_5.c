#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int avpriv_mpeg4audio_sample_rates[16];
extern int samplerate;
extern int sri;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t total_elements = sizeof(avpriv_mpeg4audio_sample_rates) / sizeof((avpriv_mpeg4audio_sample_rates)[0]);
    int found = 0;
    for (sri = 0; sri < total_elements && !found; sri++) {
        if (avpriv_mpeg4audio_sample_rates[sri] == samplerate) {
            found = 1;
            sri--; // Introduce a WAW dependency: sri is written here and in the loop increment
        }
    }
    if (!found) sri = total_elements; // Ensure sri reflects correct exit state
}
