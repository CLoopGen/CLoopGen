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
    // Variant 2: Strided Memory Access via Pointer Arithmetic
    // Use fixed stride and indirect indexing through an index map array
    // This simulates irregular memory access useful in SIMD masking or gather patterns
    
    const int access_map[15] = {0, 14, 1, 13, 2, 12, 3, 11, 4, 10, 5, 9, 6, 8, 7};  // Original logical order
    JSAMPROW row_base;
    
    for (; ctr < 15; ) {
        row_base = sample_data[ctr] + start_col;

        // Indirect access using strided lookup via access_map
        tmp0 = ((int)(row_base[access_map[0]])) + ((int)(row_base[access_map[1]]));   // 0+14
        tmp1 = ((int)(row_base[access_map[2]])) + ((int)(row_base[access_map[3]]));   // 1+13
        tmp2 = ((int)(row_base[access_map[4]])) + ((int)(row_base[access_map[5]]));   // 2+12
        tmp3 = ((int)(row_base[access_map[6]])) + ((int)(row_base[access_map[7]]));   // 3+11
        tmp4 = ((int)(row_base[access_map[8]])) + ((int)(row_base[access_map[9]]));   // 4+10
        tmp5 = ((int)(row_base[access_map[10]])) + ((int)(row_base[access_map[11]])); // 5+9
        tmp6 = ((int)(row_base[access_map[12]])) + ((int)(row_base[access_map[13]])); // 6+8
        tmp7 = ((int)(row_base[access_map[14]]));                                     // 7

        tmp10 = ((int)(row_base[access_map[0]])) - ((int)(row_base[access_map[1]]));
        tmp11 = ((int)(row_base[access_map[2]])) - ((int)(row_base[access_map[3]]));
        tmp12 = ((int)(row_base[access_map[4]])) - ((int)(row_base[access_map[5]]));
        tmp13 = ((int)(row_base[access_map[6]])) - ((int)(row_base[access_map[7]]));
        tmp14 = ((int)(row_base[access_map[8]])) - ((int)(row_base[access_map[9]]));
        tmp15 = ((int)(row_base[access_map[10]])) - ((int)(row_base[access_map[11]]));
        tmp16 = ((int)(row_base[access_map[12]])) - ((int)(row_base[access_map[13]]));

        z1 = tmp0 + tmp4 + tmp5;
        z2 = tmp1 + tmp3 + tmp6;
        z3 = tmp2 + tmp7;
        dataptr[0] = (DCTELEM)(z1 + z2 + z3 - 15 * 128);
        z3 += z3;
        dataptr[6] = (DCTELEM)(((((z1 - z3) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5)))) - ((z2 - z3) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13) - 1))) >> (13));
        
        tmp2 += ((tmp1 + tmp4) >> 1) - tmp7 - tmp7;
        z1 = ((tmp3 - tmp2) * (((INT32)((1.531135173) * (((INT32)1) << 13) + 0.5)))) - ((tmp6 - tmp2) * (((INT32)((2.2382419549999999) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp5 - tmp2) * (((INT32)((0.79846800799999995) * (((INT32)1) << 13) + 0.5)))) - ((tmp0 - tmp2) * (((INT32)((0.091361227000000003) * (((INT32)1) << 13) + 0.5))));
        z3 = ((tmp0 - tmp3) * (((INT32)((1.3833096030000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp6 - tmp5) * (((INT32)((0.946293579) * (((INT32)1) << 13) + 0.5)))) + ((tmp1 - tmp4) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
        dataptr[2] = (DCTELEM)(((z1 + z3) + ((INT32)1 << ((13) - 1))) >> (13));
        dataptr[4] = (DCTELEM)(((z2 + z3) + ((INT32)1 << ((13) - 1))) >> (13));

        tmp2 = ((tmp10 - tmp12 - tmp13 + tmp15 + tmp16) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp1 = ((tmp10 - tmp14 - tmp15) * (((INT32)((1.344997024) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 - tmp13 - tmp16) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp4 = ((tmp10 - tmp16) * (((INT32)((1.4064663529999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 + tmp14) * (((INT32)((1.344997024) * (((INT32)1) << 13) + 0.5)))) + ((tmp13 + tmp15) * (((INT32)((0.575212477) * (((INT32)1) << 13) + 0.5))));
        tmp0 = ((tmp13) * (((INT32)((0.47575301399999997) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5)))) + ((tmp16) * (((INT32)((1.7004978850000001) * (((INT32)1) << 13) + 0.5)))) + tmp4 + tmp12;
        tmp3 = ((tmp10) * (-((INT32)((0.35550086199999997) * (((INT32)1) << 13) + 0.5)))) - ((tmp11) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5)))) - ((tmp15) * (((INT32)((0.86924400999999996) * (((INT32)1) << 13) + 0.5)))) + tmp4 - tmp12;

        dataptr[1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13) - 1))) >> (13));
        dataptr[3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13) - 1))) >> (13));
        dataptr[5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13) - 1))) >> (13));
        dataptr[7] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13) - 1))) >> (13));

        ctr++;
        if (ctr != 8) {
            if (ctr == 15)
                break;
            dataptr += 8;
        } else
            dataptr = workspace;
    }
}
