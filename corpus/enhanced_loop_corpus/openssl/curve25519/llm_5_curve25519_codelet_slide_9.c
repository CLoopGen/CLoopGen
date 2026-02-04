#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern int i;
extern int b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; ++i) {
    if (!r[i]) continue;
    for (b = 1; b <= 6 && i + b < 256; ++b) {
        if (r[i + b]) {
            int shift_val = r[i + b] << b;
            int sum = r[i] + shift_val;
            int diff = r[i] - shift_val;

            if (sum <= 15) {
                r[i] = sum;
                r[i + b] = 0;
            } else if (diff >= -15) {
                r[i] = diff;
                for (k = i + b; k < 256; ++k) {
                    if (r[k] == 0) {
                        r[k] = 1;
                        break;
                    }
                    r[k] = 0;
                }
            } else {
                // Skip further b increments once condition fails
                goto next_i;
            }
        }
    }
    next_i: ;
}
}
