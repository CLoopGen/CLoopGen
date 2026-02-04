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
    int offset = (i * 2); // Strided access with step 2
    int y = *(ix + offset + 3);
    int x = *(ix + offset);
    if (x != 0) {
        sign++;
        x *= 16;
    }
    if (y != 0) {
        sign++;
        x += y;
    }
    *(p + offset) = x;
    sum += hlen[x];
}
}
