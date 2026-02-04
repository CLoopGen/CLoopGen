#include <stdio.h>

#include <inttypes.h>

extern  unsigned int range;
extern  double expected;
extern double sum;
extern size_t *counts;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double local_expected = expected;
    double local_sum = sum;
    for (i = 0; i < range; i += 2) {
        const double delta1 = (i + 0 < range) ? counts[i + 0] - local_expected : 0.0;
        const double delta2 = (i + 1 < range) ? counts[i + 1] - local_expected : 0.0;
        local_sum += delta1 * delta1;
        local_sum += delta2 * delta2;
    }
    sum = local_sum;
}
