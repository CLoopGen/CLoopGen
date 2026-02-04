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
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++) {
    for (int block = 0; block < 2; block++) {
        elemptr = sample_data[ctr * 2 + block] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[13]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[12]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[11]));
        tmp13 = ((int)(elemptr[3])) + ((int)(elemptr[10]));
        tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[9]));
        tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[8]));
        tmp6 = ((int)(elemptr[6])) + ((int)(elemptr[7]));
        tmp10 = tmp0 + tmp6;
        tmp14 = tmp0 - tmp6;
        tmp11 = tmp1 + tmp5;
        tmp15 = tmp1 - tmp5;
        tmp12 = tmp2 + tmp4;
        tmp16 = tmp2 - tmp4;
        tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[13]));
        tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[12]));
        tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[11]));
        tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[10]));
        tmp4 = ((int)(elemptr[4])) - ((int)(elemptr[9]));
        tmp5 = ((int)(elemptr[5])) - ((int)(elemptr[8]));
        tmp6 = ((int)(elemptr[6])) - ((int)(elemptr[7]));
        dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 + tmp13 - 14 * 128) << 2);
        tmp13 += tmp13;
        dataptr[4] = (DCTELEM)(((((tmp10 - tmp13) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 - tmp13) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp12 - tmp13) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        tmp10 = ((tmp14 + tmp15) * (((INT32)((1.105676686) * (((INT32)1) << 13) + 0.5))));
        dataptr[2] = (DCTELEM)(((tmp10 + ((tmp14) * (((INT32)((0.27307958999999998) * (((INT32)1) << 13) + 0.5)))) + ((tmp16) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[6] = (DCTELEM)(((tmp10 - ((tmp15) * (((INT32)((1.719280954) * (((INT32)1) << 13) + 0.5)))) - ((tmp16) * (((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        tmp10 = tmp1 + tmp2;
        tmp11 = tmp5 - tmp4;
        dataptr[7] = (DCTELEM)((tmp0 - tmp10 + tmp3 - tmp11 - tmp6) << 2);
        tmp3 <<= 13;
        tmp10 = ((tmp10) * (-((INT32)((0.15834168100000001) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((INT32)((1.405321284) * (((INT32)1) << 13) + 0.5))));
        tmp10 += tmp11 - tmp3;
        tmp11 = ((tmp0 + tmp2) * (((INT32)((1.1974488459999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp4 + tmp6) * (((INT32)((0.752406978) * (((INT32)1) << 13) + 0.5))));
        dataptr[5] = (DCTELEM)(((tmp10 + tmp11 - ((tmp2) * (((INT32)((2.3739597730000002) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((1.119999435) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        tmp12 = ((tmp0 + tmp1) * (((INT32)((1.334852607) * (((INT32)1) << 13) + 0.5)))) + ((tmp5 - tmp6) * (((INT32)((0.46708512899999999) * (((INT32)1) << 13) + 0.5))));
        dataptr[3] = (DCTELEM)(((tmp10 + tmp12 - ((tmp1) * (((INT32)((0.42410394800000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp5) * (((INT32)((3.0698552590000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[1] = (DCTELEM)(((tmp11 + tmp12 + tmp3 + tmp6 - ((tmp0 + tmp6) * (((INT32)((1.1269801690000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr += 8;
    }
}
}
