#include <stdio.h>

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


extern struct histogram_s *h;
extern float sum;
extern float sqsum;
extern float delta;
extern int sc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int stride = 2;
    int low = h->lowscore;
    int high = h->highscore;
    int base_offset = -h->min;
    for (int sc = low; sc <= high; sc += stride) {
        int offset = sc + base_offset;
        delta = (float)sc + 0.5f;
        sum += (float)h->histogram[offset] * delta;
        sqsum += (float)h->histogram[offset] * delta * delta;
        if (sc + 1 <= high) {
            int next_offset = sc + 1 + base_offset;
            float next_delta = (float)(sc + 1) + 0.5f;
            sum += (float)h->histogram[next_offset] * next_delta;
            sqsum += (float)h->histogram[next_offset] * next_delta * next_delta;
        }
    }
}
