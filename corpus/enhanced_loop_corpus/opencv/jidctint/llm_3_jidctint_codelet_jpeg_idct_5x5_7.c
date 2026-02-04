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
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect access via index mapping array to alter memory access pattern
static const int index_map[5] = {0, 4, 1, 3, 2}; // Define non-sequential write order
for (ctr = 0; ctr < 5; ctr++) {
    outptr = output_buf[ctr] + output_col;
    tmp12 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    tmp12 = ((JLONG)((unsigned long)(tmp12) << (13)));
    tmp0 = (JLONG)wsptr[2];
    tmp1 = (JLONG)wsptr[4];
    z1 = ((tmp0 + tmp1) * (((JLONG)((0.790569415) * (((JLONG)1) << 13) + 0.5))));
    z2 = ((tmp0 - tmp1) * (((JLONG)((0.35355339099999999) * (((JLONG)1) << 13) + 0.5))));
    z3 = tmp12 + z2;
    tmp10 = z3 + z1;
    tmp11 = z3 - z1;
    tmp12 -= ((JLONG)((unsigned long)(z2) << (2)));
    z2 = (JLONG)wsptr[1];
    z3 = (JLONG)wsptr[3];
    z1 = ((z2 + z3) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = z1 + ((z2) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
    tmp1 = z1 - ((z3) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));
    // Write results in a non-linear order using the index_map
    for (int i = 0; i < 5; i++) {
        int pos = index_map[i];
        JLONG val;
        if (pos == 0) val = tmp10 + tmp0;
        else if (pos == 4) val = tmp10 - tmp0;
        else if (pos == 1) val = tmp11 + tmp1;
        else if (pos == 3) val = tmp11 - tmp1;
        else if (pos == 2) val = tmp12;
        outptr[pos] = range_limit[(int)(val >> (13 + 1 + 3)) & (255 * 4 + 3)];
    }
    wsptr += 5;
}
}
