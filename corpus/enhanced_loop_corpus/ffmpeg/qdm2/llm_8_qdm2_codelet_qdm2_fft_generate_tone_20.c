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
    for (i = 0; i < 8; i += 2) {
        float temp_re = c.re * f[i/2 + 2];
        float temp_im = c.im * f[i/2 + 2];
        tone->complex[i % 4].re += temp_re;
        tone->complex[i % 4].im += temp_im;
        if (i < 6) {
            tone->complex[i % 4 + 1].re -= temp_re * 0.5f;
            tone->complex[i % 4 + 1].im -= temp_im * 0.5f;
        }
    }
}
