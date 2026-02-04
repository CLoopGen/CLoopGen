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
for (j = 0; j < n; j++) {
    old = w[j];
    newv = 0;
    if (old >> 24 != 0) {
        newv |= old >> 24 & 255;
    }
    if (old >> 8 & 255) {
        newv |= old >> 8 & 65280;
    }
    if (old << 8 & 65535) {
        newv |= old << 8 & 16711680;
    }
    if (old << 24 != 0) {
        newv |= old << 24 & 4278190080U;
    }
    w[j] = newv;
}
}
