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
extern int maxbar;
extern int i;
extern int lowbound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_maxbar = maxbar;
    int local_lowbound = lowbound;
    int i_start = h->lowscore - h->min;
    int i_end = h->highscore - h->min;
    for (int j = i_start; j <= i_end; j++) {
        int current_count = h->histogram[j];
        int candidate_bound = j + h->min;
        local_maxbar = (current_count > local_maxbar) ? current_count : local_maxbar;
        local_lowbound = (current_count > maxbar) ? candidate_bound : local_lowbound;
    }
    maxbar = local_maxbar;
    lowbound = local_lowbound;
}
