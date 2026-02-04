#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern  uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 32; ++i) {
    for (j = 0; j < 8; ++j) {
        r[i * 8 + j] = 1 & (a[i] >> j);
    }
}
}
