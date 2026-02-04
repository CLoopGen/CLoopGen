#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern int i;
extern int b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Mapping Array
    int index_map[256];
    for (i = 0; i < 256; ++i) {
        index_map[i] = (i * 37) % 256; // Simple permutation using modular arithmetic
    }
    for (i = 0; i < 256; ++i) {
        int mapped_i = index_map[i];
        if (r[mapped_i]) {
            for (b = 1; b <= 6 && mapped_i + b < 256; ++b) {
                int mapped_j = mapped_i + b;
                if (r[mapped_j]) {
                    if (r[mapped_i] + (r[mapped_j] << b) <= 15) {
                        r[mapped_i] += r[mapped_j] << b;
                        r[mapped_j] = 0;
                    } else if (r[mapped_i] - (r[mapped_j] << b) >= -15) {
                        r[mapped_i] -= r[mapped_j] << b;
                        for (k = mapped_j; k < 256; ++k) {
                            if (!r[k]) {
                                r[k] = 1;
                                break;
                            }
                            r[k] = 0;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
}
