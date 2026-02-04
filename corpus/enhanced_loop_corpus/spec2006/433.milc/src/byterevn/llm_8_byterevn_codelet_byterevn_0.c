#include <stdio.h>

#include <inttypes.h>

typedef int int32type;

extern int32type w[];
extern int n;
extern int32type old;
extern int32type newv;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32type temp;
for (j = 0; j < n; j += 2) {
    if (j + 1 < n) {
        old = w[j];
        temp = w[j + 1];
        newv = (old >> 24 & 255) | (old >> 8 & 65280) | (old << 8 & 16711680) | (old << 24 & 4278190080U);
        w[j] = newv;
        newv = (temp >> 24 & 255) | (temp >> 8 & 65280) | (temp << 8 & 16711680) | (temp << 24 & 4278190080U);
        w[j + 1] = newv;
    } else {
        old = w[j];
        newv = old >> 24 & 255;
        newv |= old >> 8 & 65280;
        newv |= old << 8 & 16711680;
        newv |= old << 24 & 4278190080U;
        w[j] = newv;
    }
}
}
