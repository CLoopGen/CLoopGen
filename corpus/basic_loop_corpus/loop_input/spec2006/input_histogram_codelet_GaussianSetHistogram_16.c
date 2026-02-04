#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

static struct histogram_s h_instance;
struct histogram_s *h = &h_instance;

int hsize;
int idx;

void init_vars() {
    hsize = 67108864; // ~256MB / sizeof(float) ≈ 67M elements for 0.01 sec estimate

    h->expect = (float *)calloc(hsize, sizeof(float));
    if (!h->expect) {
        exit(1);
    }

    h->histogram = NULL;
    h->min = 0;
    h->max = 0;
    h->highscore = 0;
    h->lowscore = 0;
    h->lumpsize = 0;
    h->total = 0;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;
}