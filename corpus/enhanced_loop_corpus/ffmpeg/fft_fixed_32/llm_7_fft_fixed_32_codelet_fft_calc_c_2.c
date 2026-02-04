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
for (n = 0; n < num_transforms; n += 2) {
    if (n + 1 >= num_transforms) break;
    offset = ff_fft_offsets_lut[n] << 2;
    int offset2 = ff_fft_offsets_lut[n + 1] << 2;
    FFTComplex *tmpz1 = z + offset;
    FFTComplex *tmpz2 = z + offset2;
    unsigned int t1, t5, t2, t6, t3, t8, t4, t7;
    t1 = tmpz1[0].re + (unsigned int)tmpz1[1].re;
    t5 = tmpz1[2].re + (unsigned int)tmpz1[3].re;
    t2 = tmpz1[0].im + (unsigned int)tmpz1[1].im;
    t6 = tmpz1[2].im + (unsigned int)tmpz1[3].im;
    t3 = tmpz1[0].re - (unsigned int)tmpz1[1].re;
    t8 = tmpz1[2].im - (unsigned int)tmpz1[3].im;
    t4 = tmpz1[0].im - (unsigned int)tmpz1[1].im;
    t7 = tmpz1[2].re - (unsigned int)tmpz1[3].re;
    tmpz1[0].re = t1 + t5;
    tmpz1[2].re = t1 - t5;
    tmpz1[0].im = t2 + t6;
    tmpz1[2].im = t2 - t6;
    tmpz1[1].re = t3 + t8;
    tmpz1[3].re = t3 - t8;
    tmpz1[1].im = t4 - t7;
    tmpz1[3].im = t4 + t7;

    t1 = tmpz2[0].re + (unsigned int)tmpz2[1].re;
    t5 = tmpz2[2].re + (unsigned int)tmpz2[3].re;
    t2 = tmpz2[0].im + (unsigned int)tmpz2[1].im;
    t6 = tmpz2[2].im + (unsigned int)tmpz2[3].im;
    t3 = tmpz2[0].re - (unsigned int)tmpz2[1].re;
    t8 = tmpz2[2].im - (unsigned int)tmpz2[3].im;
    t4 = tmpz2[0].im - (unsigned int)tmpz2[1].im;
    t7 = tmpz2[2].re - (unsigned int)tmpz2[3].re;
    tmpz2[0].re = t1 + t5;
    tmpz2[2].re = t1 - t5;
    tmpz2[0].im = t2 + t6;
    tmpz2[2].im = t2 - t6;
    tmpz2[1].re = t3 + t8;
    tmpz2[3].re = t3 - t8;
    tmpz2[1].im = t4 - t7;
    tmpz2[3].im = t4 + t7;
}
}
