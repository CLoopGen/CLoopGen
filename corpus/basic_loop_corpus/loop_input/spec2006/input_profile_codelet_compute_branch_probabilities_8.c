#include <stdint.h>

int total_hist_br_prob[20];
int i;
int hist_br_prob[20];

void init_vars() {
    for (i = 0; i < 20; i++) {
        total_hist_br_prob[i] = 0;
        hist_br_prob[i] = i * 500000; // Large values to encourage non-trivial accumulation
    }
}