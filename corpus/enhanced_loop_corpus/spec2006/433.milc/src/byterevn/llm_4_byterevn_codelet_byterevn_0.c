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
    if (w[j] == 0) {
        continue;
    }
    old = w[j];
    newv = old >> 24 & 255;
    newv |= old >> 8 & 65280;
    newv |= old << 8 & 16711680;
    newv |= old << 24 & 4278190080U;
    w[j] = newv;
}
}
