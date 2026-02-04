#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

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

struct histogram_s *h;
float delta;
int sc;
int nbins;

void init_vars() {
    const int data_size = 1 << 20; // 1M elements for ~0.01 sec runtime

    h = (struct histogram_s *)calloc(1, sizeof(struct histogram_s));
    h->min = 0;
    h->lumpsize = 1;
    h->total = data_size;
    h->highscore = data_size - 1;
    h->lowscore = 0;

    h->histogram = (int *)calloc(data_size, sizeof(int));
    h->expect = (float *)calloc(data_size, sizeof(float));

    for (int i = 0; i < data_size; i++) {
        h->histogram[i] = (i % 100) + 1;
        h->expect[i] = ((i % 90) + 5) + 0.5f;
    }

    h->fit_type = 1;
    h->param[0] = 1.0f;
    h->param[1] = 2.0f;
    h->param[2] = 3.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;

    delta = 0.0f;
    sc = 0;
    nbins = 0;
}