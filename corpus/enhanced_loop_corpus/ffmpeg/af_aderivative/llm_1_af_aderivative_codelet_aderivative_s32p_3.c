#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void **d;
extern void **p;
extern  void **s;
extern int nb_samples;
extern int channels;
extern int n;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32_t temp_prv[channels];
for (c = 0; c < channels; c++) {
    temp_prv[c] = ((int32_t*)p[c])[0];
}
for (n = 0; n < nb_samples; n++) {
    for (c = 0; c < channels; c++) {
        const int32_t current = ((const int32_t*)s[c])[n];
        ((int32_t*)d[c])[n] = current - temp_prv[c];
        temp_prv[c] = current;
    }
}
for (c = 0; c < channels; c++) {
    ((int32_t*)p[c])[0] = temp_prv[c];
}
}
