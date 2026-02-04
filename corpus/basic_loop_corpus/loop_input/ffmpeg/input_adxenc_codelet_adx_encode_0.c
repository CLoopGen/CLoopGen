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

ADXContext *c;
int16_t *wav;
int channels;
int i;
int j;
int s0;
int s1;
int s2;
int d;
int max;
int min;

void init_vars() {
    channels = 2;
    c = (ADXContext*)calloc(1, sizeof(ADXContext));
    c->channels = channels;
    c->coeff[0] = 3800;
    c->coeff[1] = -1600;
    c->prev[0].s1 = 0;
    c->prev[0].s2 = 0;
    c->prev[1].s1 = 0;
    c->prev[1].s2 = 0;
    c->header_parsed = 1;
    c->eof = 0;
    c->cutoff = 500;

    const int data_size = 1 << 20;
    wav = (int16_t*)calloc(data_size, sizeof(int16_t));
    for (int idx = 0; idx < data_size; idx++) {
        wav[idx] = (rand() % 65536) - 32768;
    }

    s1 = 0;
    s2 = 0;
    d = 0;
    max = -2147483648;
    min = 2147483647;
}