#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern uint16_t ff_fft_offsets_lut[];
extern FFTComplex *z;
extern int n;
extern int num_transforms;
extern int offset;
extern unsigned int tmp1;
extern unsigned int tmp2;
extern unsigned int tmp3;
extern unsigned int tmp4;
extern unsigned int tmp5;
extern unsigned int tmp6;
extern unsigned int tmp7;
extern unsigned int tmp8;
extern FFTComplex *tmpz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < num_transforms; n++) {
    offset = ff_fft_offsets_lut[n] << 2;
    tmpz = z + offset;

    if (tmpz[0].re < tmpz[1].re) continue;

    tmp1 = tmpz[0].re + (unsigned int)tmpz[1].re;
    tmp5 = tmpz[2].re + (unsigned int)tmpz[3].re;
    tmp2 = tmpz[0].im + (unsigned int)tmpz[1].im;
    tmp6 = tmpz[2].im + (unsigned int)tmpz[3].im;
    tmp3 = tmpz[0].re - (unsigned int)tmpz[1].re;
    tmp8 = tmpz[2].im - (unsigned int)tmpz[3].im;
    tmp4 = tmpz[0].im - (unsigned int)tmpz[1].im;
    tmp7 = tmpz[2].re - (unsigned int)tmpz[3].re;

    tmpz[0].re = tmp1 + tmp5;
    tmpz[2].re = tmp1 - tmp5;
    tmpz[0].im = tmp2 + tmp6;
    tmpz[2].im = tmp2 - tmp6;

    if (tmpz[2].im > tmpz[3].im) {
        tmpz[1].re = tmp3;
        tmpz[3].re = tmp3;
        tmpz[1].im = tmp4;
        tmpz[3].im = tmp4;
    } else {
        tmpz[1].re = tmp3 + tmp8;
        tmpz[3].re = tmp3 - tmp8;
        tmpz[1].im = tmp4 - tmp7;
        tmpz[3].im = tmp4 + tmp7;
    }
}
}
