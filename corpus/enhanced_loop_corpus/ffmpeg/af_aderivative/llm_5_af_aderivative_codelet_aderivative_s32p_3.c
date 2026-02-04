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
    const int32_t *src = s[c];
    int32_t *dst = d[c];
    int32_t *prv = p[c];
    if (src == NULL || dst == NULL || prv == NULL) continue;
    for (n = 0; n < nb_samples; n++) {
        const int32_t current = src[n];
        int32_t diff = current - prv[0];
        if (diff >= 0) {
            dst[n] = diff;
        } else {
            dst[n] = -diff;
        }
        prv[0] = current;
    }
}
}
