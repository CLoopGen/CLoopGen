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
    for (j = 0; j < n; j++) {
        old = w[j];
        temp = 0;
        temp |= (old >> 24) & 255;
        temp |= (old >> 8) & 65280;
        temp |= (old << 8) & 16711680;
        temp |= (old << 24) & 4278190080U;
        newv = temp;
        w[j] = newv;
    }
}
