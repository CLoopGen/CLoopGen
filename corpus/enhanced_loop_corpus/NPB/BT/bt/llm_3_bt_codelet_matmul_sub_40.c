#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    // Strided memory access pattern using pointer arithmetic with fixed offsets
    double *restrict cp = &cblock[0][0];
    const double *restrict ap = &ablock[0][0];
    const double *restrict bp = &bblock[0][0];

    for (j = 0; j < 5; j++) {
        // Access bblock values with stride of 5 (column j accessed across rows)
        const double b0j = bp[j];
        const double b1j = bp[5 + j];
        const double b2j = bp[10 + j];
        const double b3j = bp[15 + j];
        const double b4j = bp[20 + j];

        // Update each row of cblock using direct pointer indexing (row-major)
        cp[j] -= ap[0]*b0j + ap[1]*b1j + ap[2]*b2j + ap[3]*b3j + ap[4]*b4j;
        cp[5 + j] -= ap[5]*b0j + ap[6]*b1j + ap[7]*b2j + ap[8]*b3j + ap[9]*b4j;
        cp[10 + j] -= ap[10]*b0j + ap[11]*b1j + ap[12]*b2j + ap[13]*b3j + ap[14]*b4j;
        cp[15 + j] -= ap[15]*b0j + ap[16]*b1j + ap[17]*b2j + ap[18]*b3j + ap[19]*b4j;
        cp[20 + j] -= ap[20]*b0j + ap[21]*b1j + ap[22]*b2j + ap[23]*b3j + ap[24]*b4j;
    }
}
