#include <stdio.h>

#include <inttypes.h>

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

extern const int jpeg_natural_order[];
extern JCOEFPTR block;
extern long ac_counts[];
extern int temp;
extern int nbits;
extern int k;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k < 64; k++) {
    int inner_flag = 1;
    if ((temp = block[jpeg_natural_order[k]]) == 0) {
        r++;
    } else {
        for (; inner_flag; ) {
            if (r <= 15) {
                if (temp < 0)
                    temp = -temp;
                nbits = 1;
                for (int t = temp; t > 1; t >>= 1) {
                    nbits++;
                }
                ac_counts[(r << 4) + nbits]++;
                r = 0;
                inner_flag = 0;
            } else {
                ac_counts[240]++;
                r -= 16;
            }
        }
    }
}
}
