#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern int i;
extern int b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 256; ++i) {
    if (r[i]) {
        for (b = 1; b <= 6 && i + b < 256; ++b) {
            if (r[i + b]) {
                if (r[i] + (r[i + b] << b) <= 15) {
                    r[i] += r[i + b] << b;
                    r[i + b] = 0;
                } else if (r[i] - (r[i + b] << b) >= -15) {
                    r[i] -= r[i + b] << b;
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
