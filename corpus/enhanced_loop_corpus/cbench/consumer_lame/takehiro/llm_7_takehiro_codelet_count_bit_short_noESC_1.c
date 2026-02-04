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
    int prev_x = 0;
    for (i = 0; i < 3; i++) {
        int y = *(ix + 3);
        int x = *ix++;

        if (prev_x > 0) {
            x += (prev_x & 0xF); 
        }

        if (x != 0) {
            sign++;
            x *= 16;
        }
        if (y != 0) {
            sign++;
            x += y;
        }
        prev_x = x; 

        *p++ = x;
        sum += hlen[x];
    }
}
