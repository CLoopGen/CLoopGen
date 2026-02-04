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
    for (i = 0; i < 4; ++i) {
        float factor = f[i + 2];
        if (tone->duration > 0 && tone->time_index < tone->cutoff) {
            tone->complex[i].re += c.re * factor;
            tone->complex[i].im += c.im * factor;
        }
    }
}
