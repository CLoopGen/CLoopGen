#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern char *ip1;
extern npy_intp is1;
extern char *ip2;
extern npy_intp is2;
extern npy_intp n;
extern float sumr;
extern float sumi;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_ip1r = 0.0f;
    float prev_ip1i = 0.0f;
    float running_corr_real = 0.0f;
    float running_corr_imag = 0.0f;

    for (i = 0; i < n; i++, ip1 += is1, ip2 += is2) {
        const float ip1r = ((float *)ip1)[0];
        const float ip1i = ((float *)ip1)[1];
        const float ip2r = ((float *)ip2)[0];
        const float ip2i = ((float *)ip2)[1];

        float diff_r = ip1r - prev_ip1r;
        float diff_i = ip1i - prev_ip1i;

        running_corr_real += diff_r * ip2r + diff_i * ip2i;
        running_corr_imag += diff_r * ip2i - diff_i * ip2r;

        prev_ip1r = ip1r;
        prev_ip1i = ip1i;
    }

    sumr = running_corr_real;
    sumi = running_corr_imag;
}
