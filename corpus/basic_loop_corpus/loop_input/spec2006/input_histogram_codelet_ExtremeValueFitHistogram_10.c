#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct histogram_s {
    int *histogram;
    int min;
    int max;
    int highscore;
    int lowscore;
    int lumpsize;
    int total;
    float *expect;
    int fit_type;
    float param[3];
    float chisq;
    float chip;
};

static struct histogram_s local_h;
struct histogram_s *h = &local_h;

int sc;
int lowbound;
int max;

void init_vars() {
    const int data_size = 1 << 20; // ~4MB of histogram data (1M ints)

    h->min = 1000;
    h->lowscore = h->min + 50;
    h->highscore = h->min + data_size - 51;
    h->max = h->highscore;

    h->lumpsize = 1;
    h->total = 0;
    h->fit_type = 0;
    h->chisq = 0.0f;
    h->chip = 0.0f;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;

    h->histogram = (int*)calloc(data_size, sizeof(int));
    if (!h->histogram) exit(1);

    h->expect = (float*)calloc(data_size, sizeof(float));
    if (!h->expect) exit(1);

    for (int i = 0; i < data_size; i++) {
        h->histogram[i] = rand() % 1000;
    }

    max = -1;
    lowbound = h->lowscore;
}