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
    for (k = 1; k < 64; k += 2) {
        temp = block[jpeg_natural_order[k]];
        if (temp == 0) {
            r++;
        } else {
            nbits = (temp < 0) ? -temp : temp;
            nbits = (nbits > 32767) ? 16 : (nbits > 16383) ? 15 : (nbits > 8191) ? 14 :
                   (nbits > 4095) ? 13 : (nbits > 2047) ? 12 : (nbits > 1023) ? 11 :
                   (nbits > 511) ? 10 : (nbits > 255) ? 9 : (nbits > 127) ? 8 :
                   (nbits > 63) ? 7 : (nbits > 31) ? 6 : (nbits > 15) ? 5 :
                   (nbits > 7) ? 4 : (nbits > 3) ? 3 : (nbits > 1) ? 2 : 1;
            while (r > 15) {
                ac_counts[240]++;
                r -= 16;
            }
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        }
        if (k + 1 < 64) {
            temp = block[jpeg_natural_order[k + 1]];
            if (temp == 0) {
                r++;
            } else {
                nbits = (temp < 0) ? -temp : temp;
                nbits = (nbits > 32767) ? 16 : (nbits > 16383) ? 15 : (nbits > 8191) ? 14 :
                       (nbits > 4095) ? 13 : (nbits > 2047) ? 12 : (nbits > 1023) ? 11 :
                       (nbits > 511) ? 10 : (nbits > 255) ? 9 : (nbits > 127) ? 8 :
                       (nbits > 63) ? 7 : (nbits > 31) ? 6 : (nbits > 15) ? 5 :
                       (nbits > 7) ? 4 : (nbits > 3) ? 3 : (nbits > 1) ? 2 : 1;
                while (r > 15) {
                    ac_counts[240]++;
                    r -= 16;
                }
                ac_counts[(r << 4) + nbits]++;
                r = 0;
            }
        }
    }
}
