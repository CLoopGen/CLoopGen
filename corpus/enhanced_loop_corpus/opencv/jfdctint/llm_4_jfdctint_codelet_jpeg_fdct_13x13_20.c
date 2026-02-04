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
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[12]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[11]));
    tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[10]));
    tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[9]));
    tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[8]));
    tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[7]));
    tmp6 = ((int)(elemptr[6]));
    tmp10 = ((int)(elemptr[0])) - ((int)(elemptr[12]));
    tmp11 = ((int)(elemptr[1])) - ((int)(elemptr[11]));
    tmp12 = ((int)(elemptr[2])) - ((int)(elemptr[10]));
    tmp13 = ((int)(elemptr[3])) - ((int)(elemptr[9]));
    tmp14 = ((int)(elemptr[4])) - ((int)(elemptr[8]));
    tmp15 = ((int)(elemptr[5])) - ((int)(elemptr[7]));
    dataptr[0] = (DCTELEM)(tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp6 - 13 * 128);
    tmp6 += tmp6;
    tmp0 -= tmp6;
    tmp1 -= tmp6;
    tmp2 -= tmp6;
    tmp3 -= tmp6;
    tmp4 -= tmp6;
    tmp5 -= tmp6;
    dataptr[2] = (DCTELEM)(((((tmp0) * (((INT32)((1.373119086) * (((INT32)1) << 13) + 0.5)))) + ((tmp1) * (((INT32)((1.0585540520000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp2) * (((INT32)((0.50148704099999997) * (((INT32)1) << 13) + 0.5)))) - ((tmp3) * (((INT32)((0.17046460799999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp4) * (((INT32)((0.80336486900000004) * (((INT32)1) << 13) + 0.5)))) - ((tmp5) * (((INT32)((1.25222392) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13) - 1))) >> (13));
    z1 = ((tmp0 - tmp2) * (((INT32)((1.155388986) * (((INT32)1) << 13) + 0.5)))) - ((tmp3 - tmp4) * (((INT32)((0.435816023) * (((INT32)1) << 13) + 0.5)))) - ((tmp1 - tmp5) * (((INT32)((0.31645013100000002) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp0 + tmp2) * (((INT32)((0.096834933999999998) * (((INT32)1) << 13) + 0.5)))) - ((tmp3 + tmp4) * (((INT32)((0.93730306399999996) * (((INT32)1) << 13) + 0.5)))) + ((tmp1 + tmp5) * (((INT32)((0.48691473899999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[4] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13) - 1))) >> (13));
    dataptr[6] = (DCTELEM)(((z1 - z2) + ((INT32)1 << ((13) - 1))) >> (13));
    tmp1 = ((tmp10 + tmp11) * (((INT32)((1.3223126510000001) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((tmp10 + tmp12) * (((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
    tmp3 = ((tmp10 + tmp13) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5)))) + ((tmp14 + tmp15) * (((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
    tmp0 = tmp1 + tmp2 + tmp3 - ((tmp10) * (((INT32)((2.0200822999999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp14) * (((INT32)((0.31877435500000001) * (((INT32)1) << 13) + 0.5))));
    tmp4 = ((tmp14 - tmp15) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5)))) - ((tmp11 + tmp12) * (((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
    tmp5 = ((tmp11 + tmp13) * (-((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
    tmp1 += tmp4 + tmp5 + ((tmp11) * (((INT32)((0.83722356399999998) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((2.3416994099999999) * (((INT32)1) << 13) + 0.5))));
    tmp6 = ((tmp12 + tmp13) * (-((INT32)((0.65721781300000004) * (((INT32)1) << 13) + 0.5))));
    tmp2 += tmp4 + tmp6 - ((tmp12) * (((INT32)((1.5721160270000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp15) * (((INT32)((2.2601097079999999) * (((INT32)1) << 13) + 0.5))));
    tmp3 += tmp5 + tmp6 + ((tmp13) * (((INT32)((2.205608352) * (((INT32)1) << 13) + 0.5)))) - ((tmp15) * (((INT32)((1.7423458110000001) * (((INT32)1) << 13) + 0.5))));
    dataptr[1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13) - 1))) >> (13));
    dataptr[3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13) - 1))) >> (13));
    dataptr[5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13) - 1))) >> (13));
    dataptr[7] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13) - 1))) >> (13));
    ctr++;
    if (ctr == 8) {
        dataptr = workspace;
    } else if (ctr < 13) {
        dataptr += 8;
    } else {
        return;
    }
    goto loop;  
loop:;
}
