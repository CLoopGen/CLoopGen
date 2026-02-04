#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ctr = 0; ctr < 4; ctr++) {
        for (int sub = 0; sub < 2; sub++) {
            int idx = ctr * 2 + sub;
            outptr = output_buf[idx] + output_col;
            int *local_wsptr = wsptr + idx * 8;
            if (local_wsptr[1] == 0 && local_wsptr[2] == 0 && local_wsptr[3] == 0 && local_wsptr[4] == 0 && local_wsptr[5] == 0 && local_wsptr[6] == 0 && local_wsptr[7] == 0) {
                JSAMPLE dcval = range_limit[(int)((((JLONG)local_wsptr[0]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
                for (int i = 0; i < 8; i++) {
                    outptr[i] = dcval;
                }
                continue;
            }
            z2 = (JLONG)local_wsptr[2];
            z3 = (JLONG)local_wsptr[6];
            z1 = ((z2 + z3) * (((JLONG)4433)));
            tmp2 = z1 + ((z3) * (-((JLONG)15137)));
            tmp3 = z1 + ((z2) * (((JLONG)6270)));
            tmp0 = ((JLONG)((unsigned long)((JLONG)local_wsptr[0] + (JLONG)local_wsptr[4]) << (13)));
            tmp1 = ((JLONG)((unsigned long)((JLONG)local_wsptr[0] - (JLONG)local_wsptr[4]) << (13)));
            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;
            tmp0 = (JLONG)local_wsptr[7];
            tmp1 = (JLONG)local_wsptr[5];
            tmp2 = (JLONG)local_wsptr[3];
            tmp3 = (JLONG)local_wsptr[1];
            z1 = tmp0 + tmp3;
            z2 = tmp1 + tmp2;
            z3 = tmp0 + tmp2;
            z4 = tmp1 + tmp3;
            z5 = ((z3 + z4) * (((JLONG)9633)));
            tmp0 = ((tmp0) * (((JLONG)2446)));
            tmp1 = ((tmp1) * (((JLONG)16819)));
            tmp2 = ((tmp2) * (((JLONG)25172)));
            tmp3 = ((tmp3) * (((JLONG)12299)));
            z1 = ((z1) * (-((JLONG)7373)));
            z2 = ((z2) * (-((JLONG)20995)));
            z3 = ((z3) * (-((JLONG)16069)));
            z4 = ((z4) * (-((JLONG)3196)));
            z3 += z5;
            z4 += z5;
            tmp0 += z1 + z3;
            tmp1 += z2 + z4;
            tmp2 += z2 + z3;
            tmp3 += z1 + z4;
            outptr[0] = range_limit[(int)(((tmp10 + tmp3) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[7] = range_limit[(int)(((tmp10 - tmp3) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[1] = range_limit[(int)(((tmp11 + tmp2) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[6] = range_limit[(int)(((tmp11 - tmp2) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[2] = range_limit[(int)(((tmp12 + tmp1) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[5] = range_limit[(int)(((tmp12 - tmp1) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[3] = range_limit[(int)(((tmp13 + tmp0) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[4] = range_limit[(int)(((tmp13 - tmp0) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        }
    }
    wsptr += 64;
}
