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
extern int prevsize;
extern int newsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *hist = h->histogram;
    int temp = 0;
    for (i = prevsize; i < newsize; i++) {
        temp = hist[i];       // Introduce artificial read (RAW dependency)
        hist[i] = 0;          // WAW: Write after potential prior write (loop-carried via memory)
        h->total += temp;     // Introduce loop-carried dependency through h->total
    }
}
