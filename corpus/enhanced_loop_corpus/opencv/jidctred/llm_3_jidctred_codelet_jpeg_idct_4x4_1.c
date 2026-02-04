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
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp12;
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
int access_pattern[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Strided access via indirection
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    int base_idx = 0;
    if (wsptr[access_pattern[base_idx + 1]] == 0 && wsptr[access_pattern[base_idx + 2]] == 0 &&
        wsptr[access_pattern[base_idx + 3]] == 0 && wsptr[access_pattern[base_idx + 5]] == 0 &&
        wsptr[access_pattern[base_idx + 6]] == 0 && wsptr[access_pattern[base_idx + 7]] == 0) {
        JSAMPLE dcval = range_limit[(int)((((JLONG)wsptr[access_pattern[base_idx + 0]]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        outptr[2] = dcval;
        outptr[3] = dcval;
        base_idx += 8;
        continue;
    }
    tmp0 = ((JLONG)((unsigned long)((JLONG)wsptr[access_pattern[base_idx + 0]]) << (13 + 1)));
    tmp2 = (((JLONG)wsptr[access_pattern[base_idx + 2]]) * (((JLONG)15137))) + (((JLONG)wsptr[access_pattern[base_idx + 6]]) * (-((JLONG)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (JLONG)wsptr[access_pattern[base_idx + 7]];
    z2 = (JLONG)wsptr[access_pattern[base_idx + 5]];
    z3 = (JLONG)wsptr[access_pattern[base_idx + 3]];
    z4 = (JLONG)wsptr[access_pattern[base_idx + 1]];
    tmp0 = ((z1) * (-((JLONG)1730))) + ((z2) * (((JLONG)11893))) + ((z3) * (-((JLONG)17799))) + ((z4) * (((JLONG)8697)));
    tmp2 = ((z1) * (-((JLONG)4176))) + ((z2) * (-((JLONG)4926))) + ((z3) * (((JLONG)7373))) + ((z4) * (((JLONG)20995)));
    outptr[0] = range_limit[(int)(((tmp10 + tmp2) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)(((tmp10 - tmp2) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)(((tmp12 + tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)(((tmp12 - tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];
    base_idx += 8;
}
}
