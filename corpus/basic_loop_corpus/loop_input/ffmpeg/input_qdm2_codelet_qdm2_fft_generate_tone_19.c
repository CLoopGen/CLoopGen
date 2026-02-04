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

int fft_cutoff_index_table[4][2] = {
    {0, 1},
    {2, 3},
    {4, 5},
    {6, 7}
};

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
    tone->cutoff = 0;
    tone->level = 0.0f;
    tone->phase = 0;
    tone->phase_shift = 0;
    tone->duration = 0;
    tone->time_index = 0;

    tone->complex = (QDM2Complex *)calloc(8, sizeof(QDM2Complex));
    float *table_data = (float *)malloc(10 * sizeof(float));
    for (int j = 0; j < 10; j++) {
        table_data[j] = (float)j * 0.5f;
    }
    tone->table = table_data;
}