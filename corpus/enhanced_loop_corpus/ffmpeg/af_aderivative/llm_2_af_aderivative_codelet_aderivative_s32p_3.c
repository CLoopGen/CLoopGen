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
    const int32_t *src0 = s[c];
    int32_t *dst0 = d[c];
    int32_t *prv0 = p[c];
    const int32_t *src1 = (c + 1 < channels) ? s[c + 1] : NULL;
    int32_t *dst1 = (c + 1 < channels) ? d[c + 1] : NULL;
    int32_t *prv1 = (c + 1 < channels) ? p[c + 1] : NULL;
    for (n = 0; n < nb_samples; n++) {
        const int32_t current0 = src0[n];
        dst0[n] = current0 - prv0[0];
        prv0[0] = current0;
        if (src1 != NULL) {
            const int32_t current1 = src1[n];
            dst1[n] = current1 - prv1[0];
            prv1[0] = current1;
        }
    }
}
}
