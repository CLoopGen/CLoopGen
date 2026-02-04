#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
int prevsize;
int newsize;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)

    h = (struct histogram_s *)calloc(1, sizeof(struct histogram_s));
    if (!h) exit(1);

    h->histogram = (int *)calloc(data_size, sizeof(int));
    if (!h->histogram) exit(1);

    h->min = 0;
    h->max = data_size - 1;
    h->highscore = 0;
    h->lowscore = 0;
    h->lumpsize = 1;
    h->total = 0;
    h->expect = NULL;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;

    prevsize = 0;
    newsize = data_size;
    i = 0;
}