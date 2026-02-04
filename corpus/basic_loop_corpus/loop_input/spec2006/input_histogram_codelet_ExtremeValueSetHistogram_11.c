#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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
int hsize;
int idx;

void init_vars() {
    hsize = 67108864;  // ~256MB of float data (67M elements * 4 bytes)

    h = (struct histogram_s *)calloc(1, sizeof(struct histogram_s));
    if (!h) exit(1);

    h->expect = (float *)calloc(hsize, sizeof(float));
    if (!h->expect) exit(1);

    h->min = 0;
    h->max = hsize - 1;
    h->highscore = 0;
    h->lowscore = 0;
    h->lumpsize = 1;
    h->total = 0;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;

    idx = 0;
}