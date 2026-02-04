#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float UINTFLOAT;

typedef float INTFLOAT;

extern UINTFLOAT *in;
extern int i;
extern  int n;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 4 instead of 2, processing two pairs per iteration)
    for (i = 0; i < n2; i += 4) {
        INTFLOAT temp1, temp2;
        int idx1 = i;
        int idx2 = i + 1;
        int mirror1 = n - 1 - i;
        int mirror2 = n - 2 - i;

        if (idx1 < mirror1) {
            temp1 = in[idx1];
            in[idx1] = -in[mirror1];
            in[mirror1] = temp1;
        }

        if (idx2 < mirror2) {
            temp2 = in[idx2];
            in[idx2] = in[mirror2];
            in[mirror2] = -temp2;
        }

        // Second pair in the stride (i+2 and i+3), if within bounds
        if (i + 2 < n2) {
            int idx3 = i + 2;
            int idx4 = i + 3;
            int mirror3 = n - 1 - (i + 2);
            int mirror4 = n - 2 - (i + 2);

            if (idx3 < mirror3) {
                temp1 = in[idx3];
                in[idx3] = -in[mirror3];
                in[mirror3] = temp1;
            }

            if (idx4 < mirror4) {
                temp2 = in[idx4];
                in[idx4] = in[mirror4];
                in[mirror4] = -temp2;
            }
        }
    }
}
