#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef int DCTELEM;

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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int indices[] = {0, 7, 1, 6, 2, 5, 3, 4}; // Indirect access pattern using index mapping

    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        DCTELEM *row = dataptr; // Fixed row, varying column via indirect indexing

        tmp0 = row[8 * indices[0]] + row[8 * indices[1]];
        tmp7 = row[8 * indices[0]] - row[8 * indices[1]];
        tmp1 = row[8 * indices[2]] + row[8 * indices[3]];
        tmp6 = row[8 * indices[2]] - row[8 * indices[3]];
        tmp2 = row[8 * indices[4]] + row[8 * indices[5]];
        tmp5 = row[8 * indices[4]] - row[8 * indices[5]];
        tmp3 = row[8 * indices[6]] + row[8 * indices[7]];
        tmp4 = row[8 * indices[6]] - row[8 * indices[7]];

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        row[8 * 0] = (DCTELEM)(((tmp10 + tmp11) + (((INT32)1) << ((2) - 1))) >> (2));
        row[8 * 4] = (DCTELEM)(((tmp10 - tmp11) + (((INT32)1) << ((2) - 1))) >> (2));

        z1 = ((tmp12 + tmp13) * (((INT32)4433)));
        row[8 * 2] = (DCTELEM)(((z1 + ((tmp13) * (((INT32)6270)))) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
        row[8 * 6] = (DCTELEM)(((z1 + ((tmp12) * (-((INT32)15137)))) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = ((z3 + z4) * (((INT32)9633)));

        tmp4 = ((tmp4) * (((INT32)2446)));
        tmp5 = ((tmp5) * (((INT32)16819)));
        tmp6 = ((tmp6) * (((INT32)25172)));
        tmp7 = ((tmp7) * (((INT32)12299)));

        z1 = ((z1) * (-((INT32)7373)));
        z2 = ((z2) * (-((INT32)20995)));
        z3 = ((z3) * (-((INT32)16069)));
        z4 = ((z4) * (-((INT32)3196)));

        z3 += z5;
        z4 += z5;

        row[8 * 7] = (DCTELEM)(((tmp4 + z1 + z3) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
        row[8 * 5] = (DCTELEM)(((tmp5 + z2 + z4) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
        row[8 * 3] = (DCTELEM)(((tmp6 + z2 + z3) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
        row[8 * 1] = (DCTELEM)(((tmp7 + z1 + z4) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));

        dataptr++; // Move to next column set
    }
}
