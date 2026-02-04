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
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (n = 0; n < num_transforms; n++) {
        offset = ff_fft_offsets_lut[n] << 3;
        tmpz = z + offset;

        // Indirect memory access via index array to simulate irregular access pattern
        const int idx[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        const FFTComplex *base = tmpz;

        tmp1 = base[idx[4]].re + (unsigned int)base[idx[5]].re;
        tmp3 = base[idx[6]].re + (unsigned int)base[idx[7]].re;
        tmp2 = base[idx[4]].im + (unsigned int)base[idx[5]].im;
        tmp4 = base[idx[6]].im + (unsigned int)base[idx[7]].im;

        tmp5 = tmp1 + tmp3;
        tmp7 = tmp1 - tmp3;
        tmp6 = tmp2 + tmp4;
        tmp8 = tmp2 - tmp4;

        tmp1 = base[idx[4]].re - (unsigned int)base[idx[5]].re;
        tmp2 = base[idx[4]].im - (unsigned int)base[idx[5]].im;
        tmp3 = base[idx[6]].re - (unsigned int)base[idx[7]].re;
        tmp4 = base[idx[6]].im - (unsigned int)base[idx[7]].im;

        tmpz[idx[4]].re = tmpz[idx[0]].re - tmp5;
        tmpz[idx[0]].re = tmpz[idx[0]].re + tmp5;
        tmpz[idx[4]].im = tmpz[idx[0]].im - tmp6;
        tmpz[idx[0]].im = tmpz[idx[0]].im + tmp6;

        tmpz[idx[6]].re = tmpz[idx[2]].re - tmp8;
        tmpz[idx[2]].re = tmpz[idx[2]].re + tmp8;
        tmpz[idx[6]].im = tmpz[idx[2]].im + tmp7;
        tmpz[idx[2]].im = tmpz[idx[2]].im - tmp7;

        accu = (int64_t)(int)((0.70710678118654757) * 2147483648. + 0.5) * (int)(tmp1 + tmp2);
        tmp5 = (int32_t)((accu + 1073741824) >> 31);
        accu = (int64_t)(int)((0.70710678118654757) * 2147483648. + 0.5) * (int)(tmp3 - tmp4);
        tmp7 = (int32_t)((accu + 1073741824) >> 31);
        accu = (int64_t)(int)((0.70710678118654757) * 2147483648. + 0.5) * (int)(tmp2 - tmp1);
        tmp6 = (int32_t)((accu + 1073741824) >> 31);
        accu = (int64_t)(int)((0.70710678118654757) * 2147483648. + 0.5) * (int)(tmp3 + tmp4);
        tmp8 = (int32_t)((accu + 1073741824) >> 31);

        tmp1 = tmp5 + tmp7;
        tmp3 = tmp5 - tmp7;
        tmp2 = tmp6 + tmp8;
        tmp4 = tmp6 - tmp8;

        tmpz[idx[5]].re = tmpz[idx[1]].re - tmp1;
        tmpz[idx[1]].re = tmpz[idx[1]].re + tmp1;
        tmpz[idx[5]].im = tmpz[idx[1]].im - tmp2;
        tmpz[idx[1]].im = tmpz[idx[1]].im + tmp2;

        tmpz[idx[7]].re = tmpz[idx[3]].re - tmp4;
        tmpz[idx[3]].re = tmpz[idx[3]].re + tmp4;
        tmpz[idx[7]].im = tmpz[idx[3]].im + tmp3;
        tmpz[idx[3]].im = tmpz[idx[3]].im - tmp3;
    }
}
