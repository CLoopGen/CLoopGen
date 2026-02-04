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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Indirect memory access via index mapping array to simulate irregular access pattern
static const int index_map[5] = {0, 4, 1, 3, 2}; // Desired output order
int access_order[5];
for (ctr = 0; ctr < 10; ctr++) {
    outptr = output_buf[ctr] + output_col;
    tmp12 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    tmp12 <<= 13;
    tmp13 = (INT32)wsptr[2];
    tmp14 = (INT32)wsptr[4];
    z1 = ((tmp13 + tmp14) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp13 - tmp14) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
    z3 = tmp12 + z2;
    tmp10 = z3 + z1;
    tmp11 = z3 - z1;
    tmp12 -= z2 << 2;
    z2 = (INT32)wsptr[1];
    z3 = (INT32)wsptr[3];
    z1 = ((z2 + z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    tmp13 = z1 + ((z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    tmp14 = z1 - ((z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));

    // Precompute all values
    INT32 results[5];
    results[0] = (tmp10 + tmp13);
    results[1] = (tmp10 - tmp13);
    results[2] = (tmp11 + tmp14);
    results[3] = (tmp11 - tmp14);
    results[4] = tmp12;

    // Define indirect write order
    for (int i = 0; i < 5; i++) {
        access_order[i] = index_map[i]; // Could be dynamically modified in real use cases
    }

    // Perform indirect writes based on mapped indices
    for (int i = 0; i < 5; i++) {
        int idx = access_order[i];
        int val = (int)(results[idx] >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1);
        outptr[i] = range_limit[val];
    }
    wsptr += 5;
}
}
