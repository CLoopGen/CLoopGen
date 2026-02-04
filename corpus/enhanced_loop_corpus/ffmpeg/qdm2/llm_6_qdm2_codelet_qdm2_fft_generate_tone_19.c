#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct QDM2Complex {
    float re;
    float im;
} QDM2Complex;

typedef struct FFTTone {
    float level;
    QDM2Complex *complex;
    const float *table;
    int phase;
    int phase_shift;
    int duration;
    short time_index;
    short cutoff;
} FFTTone;

extern  int fft_cutoff_index_table[4][2];
extern FFTTone *tone;
extern float f[6];
extern int i;
extern QDM2Complex c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_re[2], temp_im[2];
    for (i = 0; i < 2; i++) {
        int idx = fft_cutoff_index_table[tone->cutoff][i];
        temp_re[i] = c.re * f[i];
        temp_im[i] = c.im * ((tone->cutoff <= i) ? -f[i] : f[i]);
    }
    for (i = 0; i < 2; i++) {
        int idx = fft_cutoff_index_table[tone->cutoff][i];
        tone->complex[idx].re += temp_re[i];
        tone->complex[idx].im += temp_im[i];
    }
}
