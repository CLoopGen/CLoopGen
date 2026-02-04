#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

extern DCTELEM *divisors;
extern DCTELEM *workspace;
extern int i;
extern DCTELEM temp;
extern JCOEFPTR output_ptr;
extern DCTELEM qval;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index remapping (bit-reversed order)
    const int indices[64] = {
        0, 32, 16, 48, 8, 40, 24, 56, 4, 36, 20, 52, 12, 44, 28, 60,
        2, 34, 18, 50, 10, 42, 26, 58, 6, 38, 22, 54, 14, 46, 30, 62,
        1, 33, 17, 49, 9, 41, 25, 57, 5, 37, 21, 53, 13, 45, 29, 61,
        3, 35, 19, 51, 11, 43, 27, 59, 7, 39, 23, 63, 15, 47, 31, 63
    };

    for (i = 0; i < 64; i++) {
        int idx = indices[i];
        qval = divisors[idx];
        temp = workspace[idx];
        if (temp < 0) {
            temp = -temp;
            temp += qval >> 1;
            if (temp >= qval)
                temp /= qval;
            else
                temp = 0;
            temp = -temp;
        } else {
            temp += qval >> 1;
            if (temp >= qval)
                temp /= qval;
            else
                temp = 0;
        }
        output_ptr[idx] = (JCOEF)temp;
    }
}
