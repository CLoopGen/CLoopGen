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
int cn;
for (cn = 0; cn < channels * nb_samples; cn++) {
    c = cn / nb_samples;
    n = cn % nb_samples;
    if (n == 0) {
        const int16_t *src = s[c];
        int16_t *dst = d[c];
        int16_t *prv = p[c];
        const int16_t current = src[0];
        dst[0] = current - prv[0];
        prv[0] = current;
    } else {
        const int16_t *src = s[c];
        int16_t *dst = d[c];
        int16_t *prv = p[c];
        const int16_t current = src[n];
        dst[n] = current - prv[0];
        prv[0] = current;
    }
}
}
