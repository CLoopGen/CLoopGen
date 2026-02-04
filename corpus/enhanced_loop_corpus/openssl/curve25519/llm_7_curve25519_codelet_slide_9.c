#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern int i;
extern int b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 256; ++i) {
        signed char current = r[i];
        if (current) {
            for (b = 1; b <= 6 && i + b < 256; ++b) {
                if (r[i + b]) {
                    int shifted = r[i + b] << b;
                    if (current + shifted <= 15) {
                        current += shifted;
                        r[i + b] = 0;
                    } else if (current - shifted >= -15) {
                        current -= shifted;
                        r[i + b] = 0;
                        for (k = i + b; k < 256; ++k) {
                            if (r[k] == 0) {
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
            r[i] = current;
        }
    }
}
