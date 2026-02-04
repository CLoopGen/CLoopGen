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
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp17;
extern DCTELEM workspace[64];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        elemptr = sample_data[ctr] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[15]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[14]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[13]));
        tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[12]));
        tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[11]));
        tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[10]));
        tmp6 = ((int)(elemptr[6])) + ((int)(elemptr[9]));
        tmp7 = ((int)(elemptr[7])) + ((int)(elemptr[8]));
        tmp10 = tmp0 + tmp7;
        tmp14 = tmp0 - tmp7;
        tmp11 = tmp1 + tmp6;
        tmp15 = tmp1 - tmp6;
        tmp12 = tmp2 + tmp5;
        tmp16 = tmp2 - tmp5;
        tmp13 = tmp3 + tmp4;
        tmp17 = tmp3 - tmp4;
        tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[15]));
        tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[14]));
        tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[13]));
        tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[12]));
        tmp4 = ((int)(elemptr[4])) - ((int)(elemptr[11]));
        tmp5 = ((int)(elemptr[5])) - ((int)(elemptr[10]));
        tmp6 = ((int)(elemptr[6])) - ((int)(elemptr[9]));
        tmp7 = ((int)(elemptr[7])) - ((int)(elemptr[8]));
        dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 + tmp13 - 16 * 128) << 2);
        dataptr[4] = (DCTELEM)(((((tmp10 - tmp13) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 - tmp12) * (((INT32)4433)))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        tmp10 = ((tmp17 - tmp15) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5)))) + ((tmp14 - tmp16) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
        dataptr[2] = (DCTELEM)(((tmp10 + ((tmp15) * (((INT32)((1.4517749820000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp16) * (((INT32)((2.1727348040000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[6] = (DCTELEM)(((tmp10 - ((tmp14) * (((INT32)((0.211164243) * (((INT32)1) << 13) + 0.5)))) - ((tmp17) * (((INT32)((1.0615943379999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        tmp11 = ((tmp0 + tmp1) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp6 - tmp7) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((tmp0 + tmp2) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5)))) + ((tmp5 + tmp7) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((tmp0 + tmp3) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp4 - tmp7) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((tmp1 + tmp2) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp6 - tmp5) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
        tmp15 = ((tmp1 + tmp3) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5)))) + ((tmp4 + tmp6) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
        tmp16 = ((tmp2 + tmp3) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp5 - tmp4) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((tmp0) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp7) * (((INT32)((0.77965362500000002) * (((INT32)1) << 13) + 0.5))));
        tmp11 += tmp14 + tmp15 + ((tmp1) * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5)))) - ((tmp6) * (((INT32)((1.663905119) * (((INT32)1) << 13) + 0.5))));
        tmp12 += tmp14 + tmp16 - ((tmp2) * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5)))) + ((tmp5) * (((INT32)((1.227391138) * (((INT32)1) << 13) + 0.5))));
        tmp13 += tmp15 + tmp16 + ((tmp3) * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((2.1679856919999998) * (((INT32)1) << 13) + 0.5))));
        dataptr[1] = (DCTELEM)(((tmp10) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[3] = (DCTELEM)(((tmp11) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[5] = (DCTELEM)(((tmp12) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[7] = (DCTELEM)(((tmp13) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

        ctr++;
        if (ctr == 16) break;
        dataptr = (ctr < 8) ? dataptr + 8 : workspace;
    }
}
