#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern  uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; ++i) {
        int idx = i << 2;
        r[idx]     = 1 & (a[idx >> 3] >> ((idx + 0) & 7));
        r[idx + 1] = 1 & (a[(idx + 1) >> 3] >> ((idx + 1) & 7));
        r[idx + 2] = 1 & (a[(idx + 2) >> 3] >> ((idx + 2) & 7));
        r[idx + 3] = 1 & (a[(idx + 3) >> 3] >> ((idx + 3) & 7));
    }
}
