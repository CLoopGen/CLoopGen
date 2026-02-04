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
    temp = block[jpeg_natural_order[k]];
    r += (temp == 0) ? 1 : 0;

    if (temp != 0) {
        // Handle non-zero coefficient
        if (temp < 0) temp = -temp;
        nbits = 1;
        temp >>= 1;
        if (temp >= 1) {
            nbits++;
            temp >>= 1;
            if (temp >= 1) {
                nbits++;
                temp >>= 1;
                if (temp >= 1) {
                    nbits++;
                    temp >>= 1;
                    if (temp >= 1) {
                        nbits++;
                        temp >>= 1;
                        if (temp >= 1) {
                            nbits++;
                            temp >>= 1;
                            if (temp >= 1) {
                                nbits++;
                                temp >>= 1;
                                if (temp >= 1) {
                                    nbits++;
                                    temp >>= 1;
                                    if (temp >= 1) {
                                        nbits++;
                                        temp >>= 1;
                                        if (temp >= 1) {
                                            nbits++;
                                            temp >>= 1;
                                            if (temp >= 1) {
                                                nbits++;
                                                temp >>= 1;
                                                if (temp >= 1) {
                                                    nbits++;
                                                    temp >>= 1;
                                                    if (temp >= 1) {
                                                        nbits++;
                                                        temp >>= 1;
                                                        if (temp >= 1) {
                                                            nbits++;
                                                            temp >>= 1;
                                                            if (temp >= 1) {
                                                                nbits++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // Process accumulated runs
        for (int i = 0; i < r / 16; i++) {
            ac_counts[240]++;
        }
        r %= 16;

        ac_counts[(r << 4) + nbits]++;
        r = 0;
    }
}
}
