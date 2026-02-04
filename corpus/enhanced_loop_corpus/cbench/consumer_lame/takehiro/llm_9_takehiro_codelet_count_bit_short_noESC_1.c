#include <stdio.h>

#include <inttypes.h>

extern int *ix;
extern int sum;
extern int sign;
extern unsigned char *hlen;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int y1 = *(ix + 3);
    int y2 = *(ix + 4);
    int x1 = *ix++;
    int x2 = *ix++;
    if (x1 != 0) {
        sign++;
        x1 <<= 4;
    }
    if (x2 != 0) {
        sign++;
        x2 <<= 4;
    }
    if (y1 != 0) {
        sign++;
        x1 += y1;
    }
    if (y2 != 0) {
        sign++;
        x2 += y2;
    }
    *p++ = x1;
    *p++ = x2;
    sum += hlen[x1];
    sum += hlen[x2];
}
}
