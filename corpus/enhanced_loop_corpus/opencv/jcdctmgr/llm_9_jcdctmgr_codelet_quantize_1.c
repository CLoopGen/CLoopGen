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
    for (i = 0; i < 64; i += 4) {
        // Process four elements per iteration to increase computational intensity
        for (int j = 0; j < 4 && (i + j) < 64; j++) {
            int idx = i + j;
            qval = divisors[idx];
            temp = workspace[idx];
            temp += (temp < 0) ? -qval >> 1 : qval >> 1;
            if ((temp < 0 ? -temp : temp) >= qval) {
                temp = (temp < 0) ? -((-temp) / qval) : temp / qval;
            } else {
                temp = 0;
            }
            output_ptr[idx] = (JCOEF)temp;
        }
    }
}
