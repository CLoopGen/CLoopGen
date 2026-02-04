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

static struct histogram_s h_storage;
static int *histogram_data;
static float *expect_data;

struct histogram_s *h = &h_storage;
float lowbound = 10.0f;
float highbound = 100000.0f;
int sc;
int nbins;
float delta;

void init_vars() {
    const int data_size = 131072; // ~1MB of data (each int and float is 4 bytes, two arrays)
    
    histogram_data = (int*)calloc(data_size, sizeof(int));
    expect_data = (float*)calloc(data_size, sizeof(float));
    
    h->min = 0;
    h->max = data_size - 1;
    h->highscore = 100;
    h->lowscore = 0;
    h->lumpsize = 1;
    h->total = 0;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 1.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;
    
    h->histogram = histogram_data;
    h->expect = expect_data;
    
    nbins = 0;
    
    for (int i = 0; i < data_size; i++) {
        histogram_data[i] = (i % 97) + 1;  // ensures >=1, some values will be >=5
        expect_data[i] = (i % 83) + 5.0f; // ensures >=5.0 for many entries
    }
    
    lowbound = 5.0f;
    highbound = data_size - 10.0f;
}