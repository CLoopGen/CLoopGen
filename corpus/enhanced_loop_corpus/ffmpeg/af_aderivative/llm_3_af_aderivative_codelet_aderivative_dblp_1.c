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
    const double *src = s[c];
    double *dst = d[c];
    double *prv = p[c];
    int *indices = (int*)malloc(nb_samples * sizeof(int));
    for (n = 0; n < nb_samples; n++) {
        indices[n] = n;
    }
    for (n = 0; n < nb_samples; n++) {
        const int idx = indices[n];
        const double current = src[idx];
        dst[idx] = current - prv[0];
        prv[0] = current;
    }
    free(indices);
}
}
