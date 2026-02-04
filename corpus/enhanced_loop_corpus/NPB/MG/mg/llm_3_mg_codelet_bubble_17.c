#include <stdio.h>

extern double ten[1037][2];
extern int j1[1037][2];
extern int j2[1037][2];
extern int j3[1037][2];
extern int m;
extern int ind;
extern double temp;
extern int i;
extern int j_temp;



void loop(){
    // Variant 2: Strided Memory Access (simulating non-unit stride via index arithmetic)
    // Access elements with a fixed stride pattern (stride of 2 in logical row access, wrapping behavior avoided by limiting loop bound)
    int stride = 2;
    int limit = (m - 1) / stride;

    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        if (ten[idx][ind] < ten[idx + stride][ind]) {
            temp = ten[idx + stride][ind];
            ten[idx + stride][ind] = ten[idx][ind];
            ten[idx][ind] = temp;

            j_temp = j1[idx + stride][ind];
            j1[idx + stride][ind] = j1[idx][ind];
            j1[idx][ind] = j_temp;

            j_temp = j2[idx + stride][ind];
            j2[idx + stride][ind] = j2[idx][ind];
            j2[idx][ind] = j_temp;

            j_temp = j3[idx + stride][ind];
            j3[idx + stride][ind] = j3[idx][ind];
            j3[idx][ind] = j_temp;
        } else {
            return;
        }
    }
}
