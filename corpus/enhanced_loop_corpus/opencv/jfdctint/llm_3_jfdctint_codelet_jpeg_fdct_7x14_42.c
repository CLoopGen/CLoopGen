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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM workspace[48];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Indirect memory access using an index map to simulate reordered processing
    static const int access_order[] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reorder even-odd pattern
    int idx;

    for (;;) {
        elemptr = sample_data[ctr] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[6]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[5]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[4]));
        tmp3 = ((int)(elemptr[3]));
        tmp10 = ((int)(elemptr[0])) - ((int)(elemptr[6]));
        tmp11 = ((int)(elemptr[1])) - ((int)(elemptr[5]));
        tmp12 = ((int)(elemptr[2])) - ((int)(elemptr[4]));
        z1 = tmp0 + tmp2;
        
        // Use indirect indexing for output storage
        idx = access_order[0];
        dataptr[idx] = (DCTELEM)((z1 + tmp1 + tmp3 - 7 * 128) << 2);
        
        tmp3 += tmp3;
        z1 -= tmp3;
        z1 -= tmp3;
        z1 = ((z1) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp0 - tmp2) * (((INT32)((0.92060900199999995) * (((INT32)1) << 13) + 0.5))));
        z3 = ((tmp1 - tmp2) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
        
        idx = access_order[1];
        dataptr[idx] = (DCTELEM)(((z1 + z2 + z3) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        z1 -= z2;
        z2 = ((tmp0 - tmp1) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
        
        idx = access_order[2];
        dataptr[idx] = (DCTELEM)(((z2 + z3 - ((tmp1 - tmp3) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        idx = access_order[3];
        dataptr[idx] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        tmp1 = ((tmp10 + tmp11) * (((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp10 - tmp11) * (((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp1 - tmp2;
        tmp1 += tmp2;
        tmp2 = ((tmp11 + tmp12) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
        tmp1 += tmp2;
        tmp3 = ((tmp10 + tmp12) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 += tmp3;
        tmp2 += tmp3 + ((tmp12) * (((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5))));
        
        idx = access_order[4];
        dataptr[idx] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        idx = access_order[5];
        dataptr[idx] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        idx = access_order[6];
        dataptr[idx] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        ctr++;
        if (ctr != 8) {
            if (ctr == 14)
                break;
            dataptr += 8;
        } else
            dataptr = workspace;
    }
}
