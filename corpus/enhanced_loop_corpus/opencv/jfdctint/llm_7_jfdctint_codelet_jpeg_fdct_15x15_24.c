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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM workspace[56];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_row[8];
    DCTELEM *local_dataptr = workspace;
    INT32 temp_results[8][8];

    for (ctr = 0; ctr < 8; ctr++) {
        local_row[ctr] = sample_data[ctr] + start_col;

        tmp0 = ((int)(local_row[ctr][0])) + ((int)(local_row[ctr][14]));
        tmp1 = ((int)(local_row[ctr][1])) + ((int)(local_row[ctr][13]));
        tmp2 = ((int)(local_row[ctr][2])) + ((int)(local_row[ctr][12]));
        tmp3 = ((int)(local_row[ctr][3])) + ((int)(local_row[ctr][11]));
        tmp4 = ((int)(local_row[ctr][4])) + ((int)(local_row[ctr][10]));
        tmp5 = ((int)(local_row[ctr][5])) + ((int)(local_row[ctr][9]));
        tmp6 = ((int)(local_row[ctr][6])) + ((int)(local_row[ctr][8]));
        tmp7 = ((int)(local_row[ctr][7]));

        tmp10 = ((int)(local_row[ctr][0])) - ((int)(local_row[ctr][14]));
        tmp11 = ((int)(local_row[ctr][1])) - ((int)(local_row[ctr][13]));
        tmp12 = ((int)(local_row[ctr][2])) - ((int)(local_row[ctr][12]));
        tmp13 = ((int)(local_row[ctr][3])) - ((int)(local_row[ctr][11]));
        tmp14 = ((int)(local_row[ctr][4])) - ((int)(local_row[ctr][10]));
        tmp15 = ((int)(local_row[ctr][5])) - ((int)(local_row[ctr][9]));
        tmp16 = ((int)(local_row[ctr][6])) - ((int)(local_row[ctr][8]));

        z1 = tmp0 + tmp4 + tmp5;
        z2 = tmp1 + tmp3 + tmp6;
        z3 = tmp2 + tmp7;

        temp_results[ctr][0] = (DCTELEM)(z1 + z2 + z3 - 15 * 128);
        z3 += z3;
        temp_results[ctr][6] = (DCTELEM)(((((z1 - z3) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5)))) - ((z2 - z3) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13) - 1))) >> (13));

        tmp2 += ((tmp1 + tmp4) >> 1) - tmp7 - tmp7;
        z1 = ((tmp3 - tmp2) * (((INT32)((1.531135173) * (((INT32)1) << 13) + 0.5)))) - ((tmp6 - tmp2) * (((INT32)((2.2382419549999999) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp5 - tmp2) * (((INT32)((0.79846800799999995) * (((INT32)1) << 13) + 0.5)))) - ((tmp0 - tmp2) * (((INT32)((0.091361227000000003) * (((INT32)1) << 13) + 0.5))));
        z3 = ((tmp0 - tmp3) * (((INT32)((1.3833096030000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp6 - tmp5) * (((INT32)((0.946293579) * (((INT32)1) << 13) + 0.5)))) + ((tmp1 - tmp4) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));

        temp_results[ctr][2] = (DCTELEM)(((z1 + z3) + ((INT32)1 << ((13) - 1))) >> (13));
        temp_results[ctr][4] = (DCTELEM)(((z2 + z3) + ((INT32)1 << ((13) - 1))) >> (13));

        tmp2 = ((tmp10 - tmp12 - tmp13 + tmp15 + tmp16) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp1 = ((tmp10 - tmp14 - tmp15) * (((INT32)((1.344997024) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 - tmp13 - tmp16) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp4 = ((tmp10 - tmp16) * (((INT32)((1.4064663529999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 + tmp14) * (((INT32)((1.344997024) * (((INT32)1) << 13) + 0.5)))) + ((tmp13 + tmp15) * (((INT32)((0.575212477) * (((INT32)1) << 13) + 0.5))));
        tmp0 = ((tmp13) * (((INT32)((0.47575301399999997) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5)))) + ((tmp16) * (((INT32)((1.7004978850000001) * (((INT32)1) << 13) + 0.5)))) + tmp4 + tmp12;
        tmp3 = ((tmp10) * (-((INT32)((0.35550086199999997) * (((INT32)1) << 13) + 0.5)))) - ((tmp11) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5)))) - ((tmp15) * (((INT32)((0.86924400999999996) * (((INT32)1) << 13) + 0.5)))) + tmp4 - tmp12;

        temp_results[ctr][1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13) - 1))) >> (13));
        temp_results[ctr][3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13) - 1))) >> (13));
        temp_results[ctr][5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13) - 1))) >> (13));
        temp_results[ctr][7] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13) - 1))) >> (13));
    }

    for (ctr = 0; ctr < 8; ctr++) {
        for (int i = 0; i < 8; i++) {
            local_dataptr[i] = temp_results[ctr][i];
        }
        local_dataptr += 8;
    }

    dataptr = workspace;
}
