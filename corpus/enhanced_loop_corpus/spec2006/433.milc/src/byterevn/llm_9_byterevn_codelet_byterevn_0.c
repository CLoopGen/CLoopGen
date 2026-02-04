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
int32type mask_low = 255, mask_mid1 = 65280, mask_mid2 = 16711680;
int32type mask_high = 4278190080U;
int i;
for (j = 0; j < n; j++) {
    old = w[j];
    newv = 0;
    for (i = 0; i < 4; i++) {
        if (i == 0) newv |= (old >> 24) & mask_low;
        else if (i == 1) newv |= (old >> 8) & mask_mid1;
        else if (i == 2) newv |= (old << 8) & mask_mid2;
        else if (i == 3) newv |= (old << 24) & mask_high;
    }
    w[j] = newv;
}
}
