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
int newsize;
int i;

void init_vars() {
    newsize = 64 * 1024 * 1024; // ~64M integers, approx 256MB for the histogram array
    h = (struct histogram_s *)calloc(1, sizeof(struct histogram_s));
    h->histogram = (int *)calloc(newsize, sizeof(int));
    h->min = 0;
    h->max = newsize - 1;
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
}