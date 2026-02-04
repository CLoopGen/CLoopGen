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
// Eliminate loop-carried dependencies entirely by unrolling the logical behavior
// and using local temporaries to break aliasing and storage dependencies.
for (ctr = 0; ctr < 10; ctr++) {
    JSAMPROW local_outptr = output_buf[ctr] + output_col;
    int offset = ctr * 5; // Flatten wsptr indexing to remove cumulative pointer updates

    // Remove WAW on tmp12, tmp13, etc., by using local copies per iteration
    INT32 l_tmp12 = (INT32)wsptr[offset + 0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    l_tmp12 <<= 13;
    INT32 l_tmp13 = (INT32)wsptr[offset + 2];
    INT32 l_tmp14 = (INT32)wsptr[offset + 4];
    INT32 l_z1 = ((l_tmp13 + l_tmp14) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
    INT32 l_z2 = ((l_tmp13 - l_tmp14) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
    INT32 l_z3 = l_tmp12 + l_z2;
    INT32 l_tmp10 = l_z3 + l_z1;
    INT32 l_tmp11 = l_z3 - l_z1;
    INT32 l_tmp12_next = l_tmp12 - (l_z2 << 2);

    INT32 l_z2a = (INT32)wsptr[offset + 1];
    INT32 l_z3a = (INT32)wsptr[offset + 3];
    l_z1 = ((l_z2a + l_z3a) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    INT32 l_tmp13_final = l_z1 + (l_z2a * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    INT32 l_tmp14_final = l_z1 - (l_z3a * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));

    // Break address/data dependency on global outptr by delaying assignment
    int shift = (13 + 2 + 3);
    int mask = ((128 << 2) * 2 - 1);
    local_outptr[0] = range_limit[(int)((l_tmp10 + l_tmp13_final) >> shift) & mask];
    local_outptr[4] = range_limit[(int)((l_tmp10 - l_tmp13_final) >> shift) & mask];
    local_outptr[1] = range_limit[(int)((l_tmp11 + l_tmp14_final) >> shift) & mask];
    local_outptr[3] = range_limit[(int)((l_tmp11 - l_tmp14_final) >> shift) & mask];
    local_outptr[2] = range_limit[(int)(l_tmp12_next >> shift) & mask];

    // Remove WAR hazard on wsptr by eliminating increment inside iteration
    // Instead, rely on flat indexing; comment out wsptr update since offset is now direct
    // wsptr += 5; // Removed: use base + offset instead of side effect
}
}
