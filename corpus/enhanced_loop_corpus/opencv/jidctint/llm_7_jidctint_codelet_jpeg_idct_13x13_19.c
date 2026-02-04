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
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG tmp15;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 13; ctr++) {
    outptr = output_buf[ctr] + output_col;
    // Eliminate some intermediate dependencies by precomputing constants and flattening expressions
    // Break true dependencies by reordering independent operations

    z1 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    z1 = ((JLONG)((unsigned long)(z1) << (13)));

    // Load all wsptr values upfront to reduce address dependency chains
    JLONG w0 = (JLONG)wsptr[0];
    JLONG w1 = (JLONG)wsptr[1];
    JLONG w2 = (JLONG)wsptr[2];
    JLONG w3 = (JLONG)wsptr[3];
    JLONG w4 = (JLONG)wsptr[4];
    JLONG w5 = (JLONG)wsptr[5];
    JLONG w6 = (JLONG)wsptr[6];
    JLONG w7 = (JLONG)wsptr[7];

    // Reorder computation to group similar operations and break artificial dependencies
    z2 = w2; z3 = w4; z4 = w6;
    tmp10 = z3 + z4;
    tmp11 = z3 - z4;

    // Precompute multipliers as compile-time constants to reduce runtime arithmetic
    const JLONG C1 = (JLONG)(1.155388986 * (1LL << 13) + 0.5);
    const JLONG C2 = (JLONG)(0.096834933999999998 * (1LL << 13) + 0.5);
    const JLONG C3 = (JLONG)(1.373119086 * (1LL << 13) + 0.5);
    const JLONG C4 = (JLONG)(0.50148704099999997 * (1LL << 13) + 0.5);

    tmp12 = tmp10 * C1;
    tmp13 = tmp11 * C2 + z1;
    tmp20 = w2 * C3 + tmp12 + tmp13;
    tmp22 = w2 * C4 - tmp12 + tmp13;

    // Continue with other coefficients similarly inlined
    tmp12 = tmp10 * ((JLONG)(0.31645013100000002 * (1LL << 13) + 0.5));
    tmp13 = tmp11 * ((JLONG)(0.48691473899999999 * (1LL << 13) + 0.5)) + z1;
    tmp21 = w2 * ((JLONG)(1.0585540520000001 * (1LL << 13) + 0.5)) - tmp12 + tmp13;
    tmp25 = w2 * (-((JLONG)(1.25222392 * (1LL << 13) + 0.5))) + tmp12 + tmp13;

    tmp12 = tmp10 * ((JLONG)(0.435816023 * (1LL << 13) + 0.5));
    tmp13 = tmp11 * ((JLONG)(0.93730306399999996 * (1LL << 13) + 0.5)) - z1;
    tmp23 = w2 * (-((JLONG)(0.17046460799999999 * (1LL << 13) + 0.5))) - tmp12 - tmp13;
    tmp24 = w2 * (-((JLONG)(0.80336486900000004 * (1LL << 13) + 0.5))) + tmp12 - tmp13;
    tmp26 = (tmp11 - w2) * ((JLONG)(1.414213562 * (1LL << 13) + 0.5)) + z1;

    // Second stage using odd-indexed inputs
    z1 = w1; z2 = w3; z3 = w5; z4 = w7;
    tmp11 = (z1 + z2) * ((JLONG)(1.3223126510000001 * (1LL << 13) + 0.5));
    tmp12 = (z1 + z3) * ((JLONG)(1.1638749450000001 * (1LL << 13) + 0.5));
    tmp15 = z1 + z4;
    tmp13 = tmp15 * ((JLONG)(0.93779705700000004 * (1LL << 13) + 0.5));
    tmp10 = tmp11 + tmp12 + tmp13 - z1 * ((JLONG)(2.0200822999999999 * (1LL << 13) + 0.5));

    tmp14 = (z2 + z3) * (-((JLONG)(0.33844345799999997 * (1LL << 13) + 0.5)));
    tmp11 += tmp14 + z2 * ((JLONG)(0.83722356399999998 * (1LL << 13) + 0.5));
    tmp12 += tmp14 - z3 * ((JLONG)(1.5721160270000001 * (1LL << 13) + 0.5));

    tmp14 = (z2 + z4) * (-((JLONG)(1.1638749450000001 * (1LL << 13) + 0.5)));
    tmp11 += tmp14;
    tmp13 += tmp14 + z4 * ((JLONG)(2.205608352 * (1LL << 13) + 0.5));

    tmp14 = (z3 + z4) * (-((JLONG)(0.65721781300000004 * (1LL << 13) + 0.5)));
    tmp12 += tmp14;
    tmp13 += tmp14;

    tmp15 = tmp15 * ((JLONG)(0.33844345799999997 * (1LL << 13) + 0.5));
    tmp14 = tmp15 + z1 * ((JLONG)(0.31877435500000001 * (1LL << 13) + 0.5)) - z2 * ((JLONG)(0.466105296 * (1LL << 13) + 0.5));
    z1 = (z3 - z2) * ((JLONG)(0.93779705700000004 * (1LL << 13) + 0.5));
    tmp14 += z1;
    tmp15 += z1 + z3 * ((JLONG)(0.38451559499999999 * (1LL << 13) + 0.5)) - z4 * ((JLONG)(1.7423458110000001 * (1LL << 13) + 0.5));

    // Output writes — keep same pattern but ensure no overlapping write hazards
    outptr[0]  = range_limit[(int)((tmp20 + tmp10) >> 17) & 1023];
    outptr[12] = range_limit[(int)((tmp20 - tmp10) >> 17) & 1023];
    outptr[1]  = range_limit[(int)((tmp21 + tmp11) >> 17) & 1023];
    outptr[11] = range_limit[(int)((tmp21 - tmp11) >> 17) & 1023];
    outptr[2]  = range_limit[(int)((tmp22 + tmp12) >> 17) & 1023];
    outptr[10] = range_limit[(int)((tmp22 - tmp12) >> 17) & 1023];
    outptr[3]  = range_limit[(int)((tmp23 + tmp13) >> 17) & 1023];
    outptr[9]  = range_limit[(int)((tmp23 - tmp13) >> 17) & 1023];
    outptr[4]  = range_limit[(int)((tmp24 + tmp14) >> 17) & 1023];
    outptr[8]  = range_limit[(int)((tmp24 - tmp14) >> 17) & 1023];
    outptr[5]  = range_limit[(int)((tmp25 + tmp15) >> 17) & 1023];
    outptr[7]  = range_limit[(int)((tmp25 - tmp15) >> 17) & 1023];
    outptr[6]  = range_limit[(int)(tmp26 >> 17) & 1023];

    // Remove pointer update dependency by unrolling assumption (not applied here), just advance
    wsptr += 8;
}
}
