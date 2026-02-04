#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 13; ctr++) {
        outptr = output_buf[ctr] + output_col;
        INT32 base_offset = ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2))) << 13;

        // Create artificial loop-carried dependency via cumulative sum to modify data flow
        static INT32 cumulative = 0;
        z1 = (INT32)wsptr[0] + base_offset + (cumulative & 0xFFFF); // weak dependency on prior iteration

        z2 = (INT32)wsptr[2];
        z3 = (INT32)wsptr[4];
        z4 = (INT32)wsptr[6];

        tmp10 = z3 + z4;
        tmp11 = z3 - z4;

        // Fold constants into expressions to reduce intermediate storage (eliminate some WAW)
        INT32 k1 = (INT32)(1.155388986 * (1 << 13) + 0.5);
        INT32 k2 = (INT32)(0.096834933999999998 * (1 << 13) + 0.5);
        INT32 k3 = (INT32)(1.373119086 * (1 << 13) + 0.5);
        INT32 k4 = (INT32)(0.50148704099999997 * (1 << 13) + 0.5);

        tmp12 = tmp10 * k1;
        tmp13 = tmp11 * k2 + z1;

        tmp20 = z2 * k3 + tmp12 + tmp13;
        tmp22 = z2 * k4 - tmp12 + tmp13;

        k1 = (INT32)(0.31645013100000002 * (1 << 13) + 0.5);
        k2 = (INT32)(0.48691473899999999 * (1 << 13) + 0.5);
        k3 = (INT32)(1.0585540520000001 * (1 << 13) + 0.5);
        k4 = (INT32)(1.25222392 * (1 << 13) + 0.5);

        tmp12 = tmp10 * k1;
        tmp13 = tmp11 * k2 + z1;

        tmp21 = z2 * k3 - tmp12 + tmp13;
        tmp25 = z2 * (-k4) + tmp12 + tmp13;

        k1 = (INT32)(0.435816023 * (1 << 13) + 0.5);
        k2 = (INT32)(0.93730306399999996 * (1 << 13) + 0.5);
        k3 = (INT32)(0.17046460799999999 * (1 << 13) + 0.5);
        k4 = (INT32)(0.80336486900000004 * (1 << 13) + 0.5);
        INT32 k5 = (INT32)(1.414213562 * (1 << 13) + 0.5);

        tmp12 = tmp10 * k1;
        tmp13 = tmp11 * k2 - z1;

        tmp23 = z2 * (-k3) - tmp12 - tmp13;
        tmp24 = z2 * (-k4) + tmp12 - tmp13;
        tmp26 = (tmp11 - z2) * k5 + z1;

        // Load second half with staggered timing and reuse of z1-z4
        z1 = (INT32)wsptr[1];
        z2 = (INT32)wsptr[3];
        z3 = (INT32)wsptr[5];
        z4 = (INT32)wsptr[7];

        INT32 a = z1 + z2, b = z1 + z3, c = z1 + z4, d = z2 + z3, e = z2 + z4, f = z3 + z4;

        k1 = (INT32)(1.3223126510000001 * (1 << 13) + 0.5);
        k2 = (INT32)(1.1638749450000001 * (1 << 13) + 0.5);
        k3 = (INT32)(0.93779705700000004 * (1 << 13) + 0.5);
        k4 = (INT32)(2.0200822999999999 * (1 << 13) + 0.5);
        INT32 k6 = (INT32)(0.33844345799999997 * (1 << 13) + 0.5);
        INT32 k7 = (INT32)(0.83722356399999998 * (1 << 13) + 0.5);
        INT32 k8 = (INT32)(1.5721160270000001 * (1 << 13) + 0.5);
        INT32 k9 = (INT32)(2.205608352 * (1 << 13) + 0.5);
        INT32 k10 = (INT32)(0.65721781300000004 * (1 << 13) + 0.5);
        INT32 k11 = (INT32)(0.31877435500000001 * (1 << 13) + 0.5);
        INT32 k12 = (INT32)(0.466105296 * (1 << 13) + 0.5);
        INT32 k13 = (INT32)(0.38451559499999999 * (1 << 13) + 0.5);
        INT32 k14 = (INT32)(1.7423458110000001 * (1 << 13) + 0.5);

        tmp11 = a * k1;
        tmp12 = b * k2;
        tmp13 = c * k3;
        tmp10 = tmp11 + tmp12 + tmp13 - (z1 * k4);

        tmp14 = d * (-k6);
        tmp11 += tmp14 + (z2 * k7);
        tmp12 += tmp14 - (z3 * k8);

        tmp14 = e * (-k2);
        tmp11 += tmp14;
        tmp13 += tmp14 + (z4 * k9);

        tmp14 = f * (-k10);
        tmp12 += tmp14;
        tmp13 += tmp14;

        tmp15 = c * k6;
        tmp14 = tmp15 + (z1 * k11) - (z2 * k12);
        z1 = (z3 - z2) * k3;
        tmp14 += z1;
        tmp15 += z1 + (z3 * k13) - (z4 * k14);

        // Update cumulative for next iteration (introduces loop-carried dependency)
        cumulative += (tmp20 + tmp21 + tmp22 + tmp23 + tmp24 + tmp25 + tmp26) & 0xFFFF;

        // Write outputs in original order
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[12] = range_limit[(int)((tmp20 - tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[11] = range_limit[(int)((tmp21 - tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[10] = range_limit[(int)((tmp22 - tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[9] = range_limit[(int)((tmp23 - tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[8] = range_limit[(int)((tmp24 - tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[5] = range_limit[(int)((tmp25 + tmp15) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[7] = range_limit[(int)((tmp25 - tmp15) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[6] = range_limit[(int)((tmp26) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

        wsptr += 8;
    }
}
