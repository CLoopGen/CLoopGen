#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern int k;
extern int n8;
extern  FFTSample *tcos;
extern  FFTSample *tsin;
extern FFTComplex *z;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (k = 0; k < n8; k++) {
        FFTSample temp_re_n8k1, temp_im_n8k1;
        FFTSample temp_re_n8kp, temp_im_n8kp;

        temp_re_n8k1 = z[n8 - k - 1].re;
        temp_im_n8k1 = z[n8 - k - 1].im;
        temp_re_n8kp = z[n8 + k].re;
        temp_im_n8kp = z[n8 + k].im;

        int64_t accu_r0 = (int64_t)(tsin[n8 - k - 1]) * temp_im_n8k1 - 
                          (int64_t)(tcos[n8 - k - 1]) * temp_re_n8k1;
        int64_t accu_i1 = (int64_t)(tsin[n8 - k - 1]) * temp_re_n8k1 + 
                          (int64_t)(tcos[n8 - k - 1]) * temp_im_n8k1;

        int64_t accu_r1 = (int64_t)(tsin[n8 + k]) * temp_im_n8kp - 
                          (int64_t)(tcos[n8 + k]) * temp_re_n8kp;
        int64_t accu_i0 = (int64_t)(tsin[n8 + k]) * temp_re_n8kp + 
                          (int64_t)(tcos[n8 + k]) * temp_im_n8kp;

        FFTSample r0 = (int)((accu_r0 + 1073741824) >> 31);
        FFTSample i0 = (int)((accu_i0 + 1073741824) >> 31);
        FFTSample r1 = (int)((accu_r1 + 1073741824) >> 31);
        FFTSample i1 = (int)((accu_i1 + 1073741824) >> 31);

        z[n8 - k - 1].re = r0;
        z[n8 - k - 1].im = i0;
        z[n8 + k].re = r1;
        z[n8 + k].im = i1;
    }
}
