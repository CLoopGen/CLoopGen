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
for (i = 0; i < 6; i += 2) {
    int y = *(ix + 3);
    int x = *ix++;
    if (x != 0) {
        sign += 2;
        x *= 16;
        x += 5;
    }
    if (y != 0) {
        sign++;
        x -= y;
        x ^= 0xFF;
    }
    *p++ = x;
    sum += hlen[x];
    sum += hlen[x + 1];
}
}
