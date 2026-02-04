#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern int i;
extern int b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; ++i) {
    if (r[i] && r[i + 1]) {
        int shift_val = r[i + 1] << 1;
        if (r[i] + shift_val <= 15) {
            r[i] += shift_val;
            r[i + 1] = 0;
        } else if (r[i] - shift_val >= -15) {
            r[i] -= shift_val;
            for (b = i + 1; b < 256; ++b) {
                if (!r[b]) {
                    r[b] = 1;
                    break;
                }
                r[b] = 0;
            }
        }
    }
}
}
