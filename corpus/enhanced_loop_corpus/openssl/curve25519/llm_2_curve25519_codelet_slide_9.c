#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern int i;
extern int b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < 256; i += 2) {
        if (r[i]) {
            for (b = 2; b <= 12 && i + b < 256; b += 2) {
                if (r[i + b]) {
                    if (r[i] + (r[i + b] << (b / 2)) <= 15) {
                        r[i] += r[i + b] << (b / 2);
                        r[i + b] = 0;
                    } else if (r[i] - (r[i + b] << (b / 2)) >= -15) {
                        r[i] -= r[i + b] << (b / 2);
                        for (k = i + b; k < 256; ++k) {
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
