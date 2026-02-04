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

FFTTone *tone;
float f[6];
int i;
QDM2Complex c;

void init_vars() {
    c.re = 1.0f;
    c.im = 1.0f;

    for (int j = 0; j < 6; j++) {
        f[j] = (float)(j + 1);
    }

    tone = (FFTTone *)malloc(sizeof(FFTTone));
    tone->complex = (QDM2Complex *)malloc(4 * sizeof(QDM2Complex));
    for (int k = 0; k < 4; k++) {
        tone->complex[k].re = (float)(k + 1) * 0.5f;
        tone->complex[k].im = (float)(k + 1) * 0.25f;
    }
    tone->table = NULL;
    tone->phase = 0;
    tone->phase_shift = 0;
    tone->duration = 0;
    tone->time_index = 0;
    tone->cutoff = 0;
}