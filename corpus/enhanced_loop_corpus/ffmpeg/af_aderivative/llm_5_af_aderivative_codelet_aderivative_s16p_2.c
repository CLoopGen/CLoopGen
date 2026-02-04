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
for (c = 0; c < channels; c++) {
    const int16_t *src = s[c];
    int16_t *dst = d[c];
    int16_t *prv = p[c];
    int limit = nb_samples;
    for (n = 0; n < limit; n++) {
        const int16_t current = src[n];
        if (current != prv[0]) {
            dst[n] = current - prv[0];
        } else {
            dst[n] = 0;
        }
        prv[0] = current;
    }
}
}
