#include <inttypes.h>

int total_hist_br_prob[20];
int i;

void init_vars() {
    for (int j = 0; j < 20; j++) {
        total_hist_br_prob[j] = 0;
    }
    i = 0;
}