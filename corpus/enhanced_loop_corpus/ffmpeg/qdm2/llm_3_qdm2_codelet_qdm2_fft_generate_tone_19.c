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
    int base_idx = fft_cutoff_index_table[tone->cutoff][0];
    int stride = fft_cutoff_index_table[tone->cutoff][1] - base_idx;
    
    for (int j = 0; j < 2; j++) {
        int idx = base_idx + j * stride;
        tone->complex[idx].re += c.re * f[j];
        tone->complex[idx].im += c.im * ((tone->cutoff <= j) ? -f[j] : f[j]);
    }
}
