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
extern INT32 tmp15;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 6; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[11]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[10]));
    tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[9]));
    tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[8]));
    tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[7]));
    tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[6]));
    tmp10 = tmp0 + tmp5;
    tmp13 = tmp0 - tmp5;
    tmp11 = tmp1 + tmp4;
    tmp14 = tmp1 - tmp4;
    tmp12 = tmp2 + tmp3;
    tmp15 = tmp2 - tmp3;
    
    // Introduce temporary variables to break WAW and WAR dependencies
    INT32 t0, t1, t2, t3, t4, t5;
    t0 = ((int)(elemptr[0])) - ((int)(elemptr[11]));
    t1 = ((int)(elemptr[1])) - ((int)(elemptr[10]));
    t2 = ((int)(elemptr[2])) - ((int)(elemptr[9]));
    t3 = ((int)(elemptr[3])) - ((int)(elemptr[8]));
    t4 = ((int)(elemptr[4])) - ((int)(elemptr[7]));
    t5 = ((int)(elemptr[5])) - ((int)(elemptr[6]));

    dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 - 12 * 128) << 2);
    dataptr[6] = (DCTELEM)((tmp13 - tmp14 - tmp15) << 2);
    dataptr[4] = (DCTELEM)(((((tmp10 - tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[2] = (DCTELEM)(((tmp14 - tmp15 + ((tmp13 + tmp15) * (((INT32)((1.3660254039999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    // Use delayed assignment to reduce data dependency chain length
    INT32 u10 = ((t1 + t4) * (((INT32)4433)));
    INT32 u14 = u10 + (t1 * (((INT32)6270)));
    INT32 u15 = u10 - (t4 * (((INT32)15137)));
    INT32 u12 = ((t0 + t2) * (((INT32)((1.1219710540000001) * (((INT32)1) << 13) + 0.5))));
    INT32 u13 = ((t0 + t3) * (((INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5))));

    INT32 v10 = u12 + u13 + u14 - (t0 * (((INT32)((0.58077495300000004) * (((INT32)1) << 13) + 0.5)))) + (t5 * (((INT32)((0.184591911) * (((INT32)1) << 13) + 0.5))));
    INT32 v11 = ((t2 + t3) * (-((INT32)((0.184591911) * (((INT32)1) << 13) + 0.5))));
    INT32 v12 = u12 + v11 - u15 - (t2 * (((INT32)((2.339493912) * (((INT32)1) << 13) + 0.5)))) + (t5 * (((INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5))));
    INT32 v13 = u13 + v11 - u14 + (t3 * (((INT32)((0.72578801100000001) * (((INT32)1) << 13) + 0.5)))) - (t5 * (((INT32)((1.1219710540000001) * (((INT32)1) << 13) + 0.5))));
    INT32 v11_final = u15 + ((t0 - t3) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5)))) - ((t2 + t5) * (((INT32)4433)));

    dataptr[1] = (DCTELEM)(((v10) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[3] = (DCTELEM)(((v11_final) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[5] = (DCTELEM)(((v12) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[7] = (DCTELEM)(((v13) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr += 8;
}
}
