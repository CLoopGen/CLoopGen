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
extern INT32 tmp16;
extern DCTELEM workspace[48];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        elemptr = sample_data[ctr] + start_col;

        // Combine symmetric accesses early to reduce redundant loads and introduce loop-carried reuse
        INT32 sum[7], diff[7];
        sum[0] = ((int)(elemptr[0])) + ((int)(elemptr[13]));
        sum[1] = ((int)(elemptr[1])) + ((int)(elemptr[12]));
        sum[2] = ((int)(elemptr[2])) + ((int)(elemptr[11]));
        sum[3] = ((int)(elemptr[3])) + ((int)(elemptr[10]));
        sum[4] = ((int)(elemptr[4])) + ((int)(elemptr[9]));
        sum[5] = ((int)(elemptr[5])) + ((int)(elemptr[8]));
        sum[6] = ((int)(elemptr[6])) + ((int)(elemptr[7]));

        diff[0] = ((int)(elemptr[0])) - ((int)(elemptr[13]));
        diff[1] = ((int)(elemptr[1])) - ((int)(elemptr[12]));
        diff[2] = ((int)(elemptr[2])) - ((int)(elemptr[11]));
        diff[3] = ((int)(elemptr[3])) - ((int)(elemptr[10]));
        diff[4] = ((int)(elemptr[4])) - ((int)(elemptr[9]));
        diff[5] = ((int)(elemptr[5])) - ((int)(elemptr[8]));
        diff[6] = ((int)(elemptr[6])) - ((int)(elemptr[7]));

        // Reuse sum values with explicit naming to enforce dependency chain
        INT32 s0 = sum[0], s1 = sum[1], s2 = sum[2], s3 = sum[3], s4 = sum[4], s5 = sum[5], s6 = sum[6];
        INT32 d0 = diff[0], d1 = diff[1], d2 = diff[2], d3 = diff[3], d4 = diff[4], d5 = diff[5], d6 = diff[6];

        INT32 tmp10 = s0 + s6;
        INT32 tmp14 = s0 - s6;
        INT32 tmp11 = s1 + s5;
        INT32 tmp15 = s1 - s5;
        INT32 tmp12 = s2 + s4;
        INT32 tmp16 = s2 - s4;

        dataptr[0] = (DCTELEM)(tmp10 + tmp11 + tmp12 + s3 - 14 * 128);
        INT32 scaled_s3 = s3 << 1;  // Reuse s3 after scaling

        // Fold constants and reuse intermediate expressions to create stronger data flow
        const INT32 k1 = (INT32)((1.274162392) * ((INT32)1 << 13) + 0.5);
        const INT32 k2 = (INT32)((0.31469212299999999) * ((INT32)1 << 13) + 0.5);
        const INT32 k3 = (INT32)((0.88174773399999995) * ((INT32)1 << 13) + 0.5);
        dataptr[4] = (DCTELEM)((((tmp10 - scaled_s3) * k1 + (tmp11 - scaled_s3) * k2 - (tmp12 - scaled_s3) * k3) + 
                              ((INT32)1 << 12)) >> 13);

        INT32 base_term = (tmp14 + tmp15) * (INT32)((1.105676686) * ((INT32)1 << 13) + 0.5);
        const INT32 c1 = (INT32)((0.27307958999999998) * ((INT32)1 << 13) + 0.5);
        const INT32 c2 = (INT32)((0.61360426800000001) * ((INT32)1 << 13) + 0.5);
        const INT32 c3 = (INT32)((1.719280954) * ((INT32)1 << 13) + 0.5);
        const INT32 c4 = (INT32)((1.3787562760000001) * ((INT32)1 << 13) + 0.5);

        dataptr[2] = (DCTELEM)(((base_term + tmp14 * c1 + tmp16 * c2) + (1 << 12)) >> 13);
        dataptr[6] = (DCTELEM)(((base_term - tmp15 * c3 - tmp16 * c4) + (1 << 12)) >> 13);

        INT32 comb1 = d1 + d2;
        INT32 comb2 = d5 - d4;
        dataptr[7] = (DCTELEM)(d0 - comb1 + d3 - comb2 - d6);

        d3 <<= 13;
        INT32 termA = comb1 * (-(INT32)((0.15834168100000001) * ((INT32)1 << 13) + 0.5));
        INT32 termB = comb2 * (INT32)((1.405321284) * ((INT32)1 << 13) + 0.5);
        INT32 finalA = termA + termB - d3;

        const INT32 f1 = (INT32)((1.1974488459999999) * ((INT32)1 << 13) + 0.5);
        const INT32 f2 = (INT32)((0.752406978) * ((INT32)1 << 13) + 0.5);
        INT32 val1 = (d0 + d2) * f1 + (d4 + d6) * f2;
        dataptr[5] = (DCTELEM)(((finalA + val1 - d2 * (INT32)((2.3739597730000002) * ((INT32)1 << 13) + 0.5) + 
                              d4 * (INT32)((1.119999435) * ((INT32)1 << 13) + 0.5)) + (1 << 12)) >> 13);

        const INT32 g1 = (INT32)((1.334852607) * ((INT32)1 << 13) + 0.5);
        const INT32 g2 = (INT32)((0.46708512899999999) * ((INT32)1 << 13) + 0.5);
        INT32 val2 = (d0 + d1) * g1 + (d5 - d6) * g2;
        dataptr[3] = (DCTELEM)(((finalA + val2 - d1 * (INT32)((0.42410394800000001) * ((INT32)1 << 13) + 0.5) - 
                              d5 * (INT32)((3.0698552590000001) * ((INT32)1 << 13) + 0.5)) + (1 << 12)) >> 13);

        const INT32 h1 = (INT32)((1.1269801690000001) * ((INT32)1 << 13) + 0.5);
        dataptr[1] = (DCTELEM)(((val1 + val2 + d3 + d6 - (d0 + d6) * h1) + (1 << 12)) >> 13);

        ctr++;
        if (ctr != 8) {
            if (ctr == 14)
                break;
            dataptr += 8;
        } else
            dataptr = workspace;
    }
}
