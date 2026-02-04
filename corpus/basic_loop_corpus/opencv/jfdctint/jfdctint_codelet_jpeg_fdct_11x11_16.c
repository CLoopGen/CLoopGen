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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM workspace[24];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[10]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[9]));
    tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[8]));
    tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[7]));
    tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[6]));
    tmp5 = ((int)(elemptr[5]));
    tmp10 = ((int)(elemptr[0])) - ((int)(elemptr[10]));
    tmp11 = ((int)(elemptr[1])) - ((int)(elemptr[9]));
    tmp12 = ((int)(elemptr[2])) - ((int)(elemptr[8]));
    tmp13 = ((int)(elemptr[3])) - ((int)(elemptr[7]));
    tmp14 = ((int)(elemptr[4])) - ((int)(elemptr[6]));
    dataptr[0] = (DCTELEM)((tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 - 11 * 128) << 1);
    tmp5 += tmp5;
    tmp0 -= tmp5;
    tmp1 -= tmp5;
    tmp2 -= tmp5;
    tmp3 -= tmp5;
    tmp4 -= tmp5;
    z1 = ((tmp0 + tmp3) * (((INT32)((1.3569279759999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp2 + tmp4) * (((INT32)((0.201263574) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp1 - tmp3) * (((INT32)((0.92611293100000002) * (((INT32)1) << 13) + 0.5))));
    z3 = ((tmp0 - tmp1) * (((INT32)((1.1897121559999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[2] = (DCTELEM)(((z1 + z2 - ((tmp3) * (((INT32)((1.0183005899999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp4) * (((INT32)((1.3909757300000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 1) - 1))) >> (13 - 1));
    dataptr[4] = (DCTELEM)(((z2 + z3 + ((tmp1) * (((INT32)((0.062335649999999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp2) * (((INT32)((1.3569279759999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((0.58748554500000005) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 1) - 1))) >> (13 - 1));
    dataptr[6] = (DCTELEM)(((z1 + z3 - ((tmp0) * (((INT32)((1.6205271999999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp2) * (((INT32)((0.78874911999999997) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 1) - 1))) >> (13 - 1));
    tmp1 = ((tmp10 + tmp11) * (((INT32)((1.2864139050000001) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((tmp10 + tmp12) * (((INT32)((1.0687912980000001) * (((INT32)1) << 13) + 0.5))));
    tmp3 = ((tmp10 + tmp13) * (((INT32)((0.76458157599999998) * (((INT32)1) << 13) + 0.5))));
    tmp0 = tmp1 + tmp2 + tmp3 - ((tmp10) * (((INT32)((1.7199678709999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp14) * (((INT32)((0.39843000299999998) * (((INT32)1) << 13) + 0.5))));
    tmp4 = ((tmp11 + tmp12) * (-((INT32)((0.76458157599999998) * (((INT32)1) << 13) + 0.5))));
    tmp5 = ((tmp11 + tmp13) * (-((INT32)((1.399818907) * (((INT32)1) << 13) + 0.5))));
    tmp1 += tmp4 + tmp5 + ((tmp11) * (((INT32)((1.276416582) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((1.0687912980000001) * (((INT32)1) << 13) + 0.5))));
    tmp10 = ((tmp12 + tmp13) * (((INT32)((0.39843000299999998) * (((INT32)1) << 13) + 0.5))));
    tmp2 += tmp4 + tmp10 - ((tmp12) * (((INT32)((1.989053629) * (((INT32)1) << 13) + 0.5)))) + ((tmp14) * (((INT32)((1.399818907) * (((INT32)1) << 13) + 0.5))));
    tmp3 += tmp5 + tmp10 + ((tmp13) * (((INT32)((1.3055986260000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((1.2864139050000001) * (((INT32)1) << 13) + 0.5))));
    dataptr[1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 - 1) - 1))) >> (13 - 1));
    dataptr[3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 - 1) - 1))) >> (13 - 1));
    dataptr[5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 - 1) - 1))) >> (13 - 1));
    dataptr[7] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13 - 1) - 1))) >> (13 - 1));
    ctr++;
    if (ctr != 8) {
        if (ctr == 11)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}

}
