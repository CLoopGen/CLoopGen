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
for (i = 0; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
        int y = *(ix + 3);
        int x = *ix++;
        if (x != 0) {
            sign++;
            x *= 16;
        }
        if (y != 0) {
            sign++;
            x += y;
        }
        *p++ = x;
        sum += hlen[x];
    }
}
}
