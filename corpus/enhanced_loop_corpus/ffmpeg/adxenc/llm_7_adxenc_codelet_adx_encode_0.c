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
    int local_max = max;
    int local_min = min;
    int prev1 = s1;
    int prev2 = s2;
    for (i = 0, j = 0; j < 32; i += channels, j++) {
        s0 = wav[i];
        d = s0 + ((-c->coeff[0] * prev1 - c->coeff[1] * prev2) >> 12);
        local_max = (local_max > d) ? local_max : d;
        local_min = (local_min < d) ? local_min : d;
        prev2 = prev1;
        prev1 = s0;
    }
    max = local_max;
    min = local_min;
    s1 = prev1;
    s2 = prev2;
}
