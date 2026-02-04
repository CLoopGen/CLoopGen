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
extern int sc;
extern int lowbound;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int *hist = h->histogram;
    int min_val = h->min;
    int high = h->highscore;
    int low = h->lowscore;
    int current_max = max;
    int current_lowbound = lowbound;

    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access by precomputing valid indices into a buffer
    // Since we don't know exact size at compile time, we use stack allocation (VLA) for clarity

    int range = high - low + 1;
    int indices[range];

    // Precompute the actual histogram indices: sc - min_val for each sc in [low, high]
    for (int i = 0; i < range; i++) {
        indices[i] = (low + i) - min_val;
    }

    // Now traverse indirectly via the indices array
    for (int i = 0; i < range; i++) {
        int sc_temp = low + i;
        int idx = indices[i]; // Indirect access mapping
        if (hist[idx] > current_max) {
            current_max = hist[idx];
            current_lowbound = sc_temp;
        }
    }

    max = current_max;
    lowbound = current_lowbound;
}
