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
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    int indices[4] = {3, 1, 0, 2}; // Reordered indices
    for (i = 0; i < 4; i++) {
        int idx = indices[i];
        tone->complex[idx].re += c.re * f[idx + 2];
        tone->complex[idx].im += c.im * f[idx + 2];
    }
}
