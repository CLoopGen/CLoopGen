#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ADXChannelState {
    int s1;
    int s2;
} ADXChannelState;

typedef struct ADXContext {
    int channels;
    ADXChannelState prev[2];
    int header_parsed;
    int eof;
    int cutoff;
    int coeff[2];
} ADXContext;

extern ADXContext *c;
extern  int16_t *wav;
extern int channels;
extern int i;
extern int j;
extern int s0;
extern int s1;
extern int s2;
extern int d;
extern int max;
extern int min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_s1 = s1;
    int temp_s2 = s2;
    for (i = 0, j = 0; j < 32; i += channels, j++) {
        s0 = wav[i];
        d = s0 + ((-c->coeff[0] * temp_s1 - c->coeff[1] * temp_s2) >> 12);
        if (max < d)
            max = d;
        if (min > d)
            min = d;
        temp_s2 = temp_s1;
        temp_s1 = s0;
    }
    s1 = temp_s1;
    s2 = temp_s2;
}
