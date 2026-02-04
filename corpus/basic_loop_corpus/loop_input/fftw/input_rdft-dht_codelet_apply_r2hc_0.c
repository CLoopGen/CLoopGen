#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *O = NULL;
INT os = 1;
INT i = 0;
INT n = 0;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(R);
    
    O = aligned_alloc(32, total_elements * sizeof(R));
    if (!O) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        O[idx] = (R)(idx % 1000) / 100.0;
    }

    os = 1;
    n = total_elements - 1;

    while (n > 0 && n >= 2 * (1)) {
        if (n % 2 == 0) {
            n--;
        } else {
            break;
        }
    }
    if (n <= 1) {
        n = 1;
    }
}