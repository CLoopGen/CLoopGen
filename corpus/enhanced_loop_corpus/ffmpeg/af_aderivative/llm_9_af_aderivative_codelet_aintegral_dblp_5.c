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
for (c = 0; c < channels; c += 2) {
    if (c + 1 >= channels) break;
    const double *src0 = s[c];
    const double *src1 = s[c+1];
    double *dst0 = d[c];
    double *dst1 = d[c+1];
    double *prv0 = p[c];
    double *prv1 = p[c+1];
    for (n = 0; n < nb_samples; n++) {
        const double current0 = src0[n];
        const double current1 = src1[n];
        dst0[n] = current0 + prv0[0];
        dst1[n] = current1 + prv1[0];
        prv0[0] = dst0[n];
        prv1[0] = dst1[n];
    }
}
}
