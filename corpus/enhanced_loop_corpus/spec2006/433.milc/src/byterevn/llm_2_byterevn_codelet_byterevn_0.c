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
    for (j = 0; j < n; j += 2) {
        if (j + 1 < n) {
            int32type temp1 = w[j];
            int32type temp2 = w[j + 1];

            int32type newv1 = (temp1 >> 24 & 255) | (temp1 >> 8 & 65280) |
                              (temp1 << 8 & 16711680) | (temp1 << 24 & 4278190080U);
            int32type newv2 = (temp2 >> 24 & 255) | (temp2 >> 8 & 65280) |
                              (temp2 << 8 & 16711680) | (temp2 << 24 & 4278190080U);

            w[j] = newv1;
            w[j + 1] = newv2;
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
