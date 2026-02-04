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

extern FFTTone *tone;
extern float f[6];
extern int i;
extern QDM2Complex c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float acc_re = 0.0f, acc_im = 0.0f;
    for (i = 0; i < 4; i++) {
        acc_re += c.re * f[i + 2];
        acc_im += c.im * f[i + 2];
        tone->complex[i].re = acc_re;
        tone->complex[i].im = acc_im;
    }
}
