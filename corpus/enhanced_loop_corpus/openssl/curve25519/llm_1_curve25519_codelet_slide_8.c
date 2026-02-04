#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern  uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; ++i) {
    int outer = i >> 3;
    int inner = i & 7;
    for (int temp = 0; temp < 1; ++temp) {
        r[i] = 1 & (a[outer] >> inner);
    }
}
}
