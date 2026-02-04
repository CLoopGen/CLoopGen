#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < n4; k += 4) {
        int idx1 = n2 - k - 1;
        int idx2 = n2 - k - 2;
        int idx3 = n2 - k - 3;
        int idx4 = n2 - k - 4;
        int idx5 = n2 + k;
        int idx6 = n2 + k + 1;
        int idx7 = n2 + k + 2;
        int idx8 = n2 + k + 3;
        int dst1 = n - k - 1;
        int dst2 = n - k - 2;
        int dst3 = n - k - 3;
        int dst4 = n - k - 4;

        output[k] = -output[idx1];
        output[k + 1] = -output[idx2];
        output[k + 2] = -output[idx3];
        output[k + 3] = -output[idx4];
        output[dst1] = output[idx5];
        output[dst2] = output[idx6];
        output[dst3] = output[idx7];
        output[dst4] = output[idx8];
    }
}
