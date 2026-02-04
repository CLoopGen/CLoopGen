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
    for (i = 0; i < 2; i++) {
        int index = fft_cutoff_index_table[tone->cutoff][i];
        float sign = (tone->cutoff <= i) ? -1.0f : 1.0f;
        tone->complex[index].re += c.re * f[i];
        tone->complex[index].im += c.im * sign * f[i];
    }
}
