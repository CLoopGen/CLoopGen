#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 z1;
extern INT32 z2;
extern DCTELEM workspace[40];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;

    // Eliminate immediate reuse of elemptr by batching loads into local temporaries with reordered access
    JSAMPLE val0   = elemptr[0];
    JSAMPLE val6   = elemptr[6];
    JSAMPLE val12  = elemptr[12];
    JSAMPLE val1   = elemptr[1];
    JSAMPLE val11  = elemptr[11];
    JSAMPLE val2   = elemptr[2];
    JSAMPLE val10  = elemptr[10];
    JSAMPLE val3   = elemptr[3];
    JSAMPLE val9   = elemptr[9];
    JSAMPLE val4   = elemptr[4];
    JSAMPLE val8   = elemptr[8];
    JSAMPLE val5   = elemptr[5];
    JSAMPLE val7   = elemptr[7];

    // Break loop-carried dependency on tmp variables by using fresh locals per iteration segment
    INT32 a0 = ((int)val0) + ((int)val12);
    INT32 a1 = ((int)val1) + ((int)val11);
    INT32 a2 = ((int)val2) + ((int)val10);
    INT32 a3 = ((int)val3) + ((int)val9);
    INT32 a4 = ((int)val4) + ((int)val8);
    INT32 a5 = ((int)val5) + ((int)val7);
    INT32 a6 = ((int)val6);

    INT32 d0 = ((int)val0) - ((int)val12);
    INT32 d1 = ((int)val1) - ((int)val11);
    INT32 d2 = ((int)val2) - ((int)val10);
    INT32 d3 = ((int)val3) - ((int)val9);
    INT32 d4 = ((int)val4) - ((int)val8);
    INT32 d5 = ((int)val5) - ((int)val7);

    // Remove WAW on tmp6 by folding doubling directly into expression
    dataptr[0] = (DCTELEM)(a0 + a1 + a2 + a3 + a4 + a5 + a6 - 13 * 128);
    a6 <<= 1;  // equivalent to a6 += a6

    // Introduce non-linear update pattern to disrupt regular subtraction sequence
    INT32 b0 = a0 - a6;
    INT32 b1 = a1 - a6;
    INT32 b2 = a2 - a6;
    INT32 b3 = a3 - a6;
    INT32 b4 = a4 - a6;
    INT32 b5 = a5 - a6;

    dataptr[2] = (DCTELEM)((((b0 * (((INT32)((1.373119086) * (((INT32)1) << 13) + 0.5)))) + 
                        (b1 * (((INT32)((1.0585540520000001) * (((INT32)1) << 13) + 0.5)))) + 
                        (b2 * (((INT32)((0.50148704099999997) * (((INT32)1) << 13) + 0.5)))) - 
                        (b3 * (((INT32)((0.17046460799999999) * (((INT32)1) << 13) + 0.5)))) - 
                        (b4 * (((INT32)((0.80336486900000004) * (((INT32)1) << 13) + 0.5)))) - 
                        (b5 * (((INT32)((1.25222392) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 12)) >> 13);

    INT32 za = ((b0 - b2) * (((INT32)((1.155388986) * (((INT32)1) << 13) + 0.5)))) - 
               ((b3 - b4) * (((INT32)((0.435816023) * (((INT32)1) << 13) + 0.5)))) - 
               ((b1 - b5) * (((INT32)((0.31645013100000002) * (((INT32)1) << 13) + 0.5))));
    INT32 zb = ((b0 + b2) * (((INT32)((0.096834933999999998) * (((INT32)1) << 13) + 0.5)))) - 
               ((b3 + b4) * (((INT32)((0.93730306399999996) * (((INT32)1) << 13) + 0.5)))) + 
               ((b1 + b5) * (((INT32)((0.48691473899999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[4] = (DCTELEM)(((za + zb) + 4096) >> 13);
    dataptr[6] = (DCTELEM)(((za - zb) + 4096) >> 13);

    // Eliminate loop-carried dependency on d* by computing final values immediately
    INT32 c1 = ((d0 + d1) * (((INT32)((1.3223126510000001) * (((INT32)1) << 13) + 0.5))));
    INT32 c2 = ((d0 + d2) * (((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
    INT32 c3 = ((d0 + d3) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5)))) + 
               ((d4 + d5) * (((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
    INT32 c0 = c1 + c2 + c3 - (d0 * (((INT32)((2.0200822999999999) * (((INT32)1) << 13) + 0.5)))) + 
               (d4 * (((INT32)((0.31877435500000001) * (((INT32)1) << 13) + 0.5))));
    INT32 c4 = ((d4 - d5) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5)))) - 
               ((d1 + d2) * (((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
    INT32 c5 = ((d1 + d3) * (-((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
    c1 += c4 + c5 + (d1 * (((INT32)((0.83722356399999998) * (((INT32)1) << 13) + 0.5)))) - 
         (d4 * (((INT32)((2.3416994099999999) * (((INT32)1) << 13) + 0.5))));
    INT32 c6 = ((d2 + d3) * (-((INT32)((0.65721781300000004) * (((INT32)1) << 13) + 0.5))));
    c2 += c4 + c6 - (d2 * (((INT32)((1.5721160270000001) * (((INT32)1) << 13) + 0.5)))) + 
         (d5 * (((INT32)((2.2601097079999999) * (((INT32)1) << 13) + 0.5))));
    c3 += c5 + c6 + (d3 * (((INT32)((2.205608352) * (((INT32)1) << 13) + 0.5)))) - 
         (d5 * (((INT32)((1.7423458110000001) * (((INT32)1) << 13) + 0.5))));

    dataptr[1] = (DCTELEM)((c0 + 4096) >> 13);
    dataptr[3] = (DCTELEM)((c1 + 4096) >> 13);
    dataptr[5] = (DCTELEM)((c2 + 4096) >> 13);
    dataptr[7] = (DCTELEM)((c3 + 4096) >> 13);

    ctr++;
    if (ctr != 8) {
        if (ctr == 13)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
