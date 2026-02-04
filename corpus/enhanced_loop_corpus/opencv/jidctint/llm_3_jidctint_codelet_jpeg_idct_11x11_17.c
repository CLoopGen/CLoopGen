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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
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
    // Variant 2: Strided Memory Access with Indirect Indexing via Lookup Table
    const int index_map[8] = {0, 2, 4, 6, 1, 3, 5, 7};  // Reordering access pattern
    const int output_order[11] = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};  // Non-linear store order

    for (ctr = 0; ctr < 11; ctr++) {
        outptr = output_buf[ctr] + output_col;
        int stride_offset = ctr * 16;  // Increased stride in wsptr access

        tmp10 = (INT32)wsptr[stride_offset + index_map[0]] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        tmp10 <<= 13;
        z1 = (INT32)wsptr[stride_offset + index_map[1]];
        z2 = (INT32)wsptr[stride_offset + index_map[2]];
        z3 = (INT32)wsptr[stride_offset + index_map[3]];
        tmp20 = ((z2 - z3) * (((INT32)((2.5466401319999998) * (((INT32)1) << 13) + 0.5))));
        tmp23 = ((z2 - z1) * (((INT32)((0.43081504500000001) * (((INT32)1) << 13) + 0.5))));
        z4 = z1 + z3;
        tmp24 = ((z4) * (-((INT32)((1.155664402) * (((INT32)1) << 13) + 0.5))));
        z4 -= z2;
        tmp25 = tmp10 + ((z4) * (((INT32)((1.3569279759999999) * (((INT32)1) << 13) + 0.5))));
        tmp21 = tmp20 + tmp23 + tmp25 - ((z2) * (((INT32)((1.821790775) * (((INT32)1) << 13) + 0.5))));
        tmp20 += tmp25 + ((z3) * (((INT32)((2.1158250870000002) * (((INT32)1) << 13) + 0.5))));
        tmp23 += tmp25 - ((z1) * (((INT32)((1.5135984769999999) * (((INT32)1) << 13) + 0.5))));
        tmp24 += tmp25;
        tmp22 = tmp24 - ((z3) * (((INT32)((0.78874911999999997) * (((INT32)1) << 13) + 0.5))));
        tmp24 += ((z2) * (((INT32)((1.9444135220000001) * (((INT32)1) << 13) + 0.5)))) - ((z1) * (((INT32)((1.3909757300000001) * (((INT32)1) << 13) + 0.5))));
        tmp25 = tmp10 - ((z4) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));

        z1 = (INT32)wsptr[stride_offset + index_map[4]];
        z2 = (INT32)wsptr[stride_offset + index_map[5]];
        z3 = (INT32)wsptr[stride_offset + index_map[6]];
        z4 = (INT32)wsptr[stride_offset + index_map[7]];
        tmp11 = z1 + z2;
        tmp14 = ((tmp11 + z3 + z4) * (((INT32)((0.39843000299999998) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((INT32)((0.88798390199999999) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 + z3) * (((INT32)((0.67036129499999997) * (((INT32)1) << 13) + 0.5))));
        tmp13 = tmp14 + ((z1 + z4) * (((INT32)((0.36615157399999998) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((INT32)((0.92310786600000005) * (((INT32)1) << 13) + 0.5))));
        z1 = tmp14 - ((z2 + z3) * (((INT32)((1.163011579) * (((INT32)1) << 13) + 0.5))));
        tmp11 += z1 + ((z2) * (((INT32)((2.0732765880000001) * (((INT32)1) << 13) + 0.5))));
        tmp12 += z1 - ((z3) * (((INT32)((1.1921936230000001) * (((INT32)1) << 13) + 0.5))));
        z1 = ((z2 + z4) * (-((INT32)((1.7982489100000001) * (((INT32)1) << 13) + 0.5))));
        tmp11 += z1;
        tmp13 += z1 + ((z4) * (((INT32)((2.1024586319999998) * (((INT32)1) << 13) + 0.5))));
        tmp14 += ((z2) * (-((INT32)((1.4672213009999999) * (((INT32)1) << 13) + 0.5)))) + 
                  ((z3) * (((INT32)((1.001388905) * (((INT32)1) << 13) + 0.5)))) - 
                  ((z4) * (((INT32)((1.6848439070000001) * (((INT32)1) << 13) + 0.5))));

        // Write outputs in non-sequential order to increase memory access variance
        for (int i = 0; i < 11; i++) {
            int pos = output_order[i];
            int val;
            if (i == 0) val = (int)((tmp20 + tmp10) >> 18);
            else if (i == 1) val = (int)((tmp20 - tmp10) >> 18);
            else if (i == 2) val = (int)((tmp21 + tmp11) >> 18);
            else if (i == 3) val = (int)((tmp21 - tmp11) >> 18);
            else if (i == 4) val = (int)((tmp22 + tmp12) >> 18);
            else if (i == 5) val = (int)((tmp22 - tmp12) >> 18);
            else if (i == 6) val = (int)((tmp23 + tmp13) >> 18);
            else if (i == 7) val = (int)((tmp23 - tmp13) >> 18);
            else if (i == 8) val = (int)((tmp24 + tmp14) >> 18);
            else if (i == 9) val = (int)((tmp24 - tmp14) >> 18);
            else val = (int)(tmp25 >> 18);

            outptr[pos] = range_limit[val & 1023];
        }
    }
}
