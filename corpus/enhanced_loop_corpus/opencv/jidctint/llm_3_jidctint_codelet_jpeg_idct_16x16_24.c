#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
extern JLONG tmp27;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index array to perform indirect access into inptr, quantptr, and wsptr
    // Simulates non-unit stride or gather/scatter patterns common in optimized codecs

    static const int idx[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reordered access pattern
    int i;

    for (ctr = 0; ctr < 8; ctr++) {
        i = idx[ctr]; // Indirect indexing

        tmp0 = (((ISLOW_MULT_TYPE)(inptr[i * 8])) * (quantptr[i * 8]));
        tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
        tmp0 += ((JLONG)1) << (13 - 1 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[(i ^ 4) * 8])) * (quantptr[(i ^ 4) * 8])); // Bit manipulation for variation
        tmp1 = ((z1) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((JLONG)4433)));
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;
        z1 = (((ISLOW_MULT_TYPE)(inptr[((i + 2) & 7) * 8])) * (quantptr[((i + 2) & 7) * 8]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[((i + 6) & 7) * 8])) * (quantptr[((i + 6) & 7) * 8]));
        z3 = z1 - z2;
        z4 = ((z3) * (((JLONG)((0.275899379) * (((JLONG)1) << 13) + 0.5))));
        z3 = ((z3) * (((JLONG)((1.3870398450000001) * (((JLONG)1) << 13) + 0.5))));
        tmp0 = z3 + ((z2) * (((JLONG)20995)));
        tmp1 = z4 + ((z1) * (((JLONG)7373)));
        tmp2 = z3 - ((z1) * (((JLONG)((0.60134488699999999) * (((JLONG)1) << 13) + 0.5))));
        tmp3 = z4 - ((z2) * (((JLONG)((0.50979557900000005) * (((JLONG)1) << 13) + 0.5))));
        tmp20 = tmp10 + tmp0;
        tmp27 = tmp10 - tmp0;
        tmp21 = tmp12 + tmp1;
        tmp26 = tmp12 - tmp1;
        tmp22 = tmp13 + tmp2;
        tmp25 = tmp13 - tmp2;
        tmp23 = tmp11 + tmp3;
        tmp24 = tmp11 - tmp3;
        z1 = (((ISLOW_MULT_TYPE)(inptr[((i + 1) & 7) * 8])) * (quantptr[((i + 1) & 7) * 8]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[((i + 3) & 7) * 8])) * (quantptr[((i + 3) & 7) * 8]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[((i + 5) & 7) * 8])) * (quantptr[((i + 5) & 7) * 8]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[((i + 7) & 7) * 8])) * (quantptr[((i + 7) & 7) * 8]));
        tmp11 = z1 + z3;
        tmp1 = ((z1 + z2) * (((JLONG)((1.3533180010000001) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((tmp11) * (((JLONG)((1.247225013) * (((JLONG)1) << 13) + 0.5))));
        tmp3 = ((z1 + z4) * (((JLONG)((1.0932018670000001) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = ((z1 - z4) * (((JLONG)((0.89716758600000002) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((JLONG)((0.66665565800000004) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((JLONG)((0.410524528) * (((JLONG)1) << 13) + 0.5))));
        tmp0 = tmp1 + tmp2 + tmp3 - ((z1) * (((JLONG)((2.2863411440000001) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = tmp10 + tmp11 + tmp12 - ((z1) * (((JLONG)((1.835730603) * (((JLONG)1) << 13) + 0.5))));
        z1 = ((z2 + z3) * (((JLONG)((0.13861716900000001) * (((JLONG)1) << 13) + 0.5))));
        tmp1 += z1 + ((z2) * (((JLONG)((0.071888073999999996) * (((JLONG)1) << 13) + 0.5))));
        tmp2 += z1 - ((z3) * (((JLONG)((1.125726048) * (((JLONG)1) << 13) + 0.5))));
        z1 = ((z3 - z2) * (((JLONG)((1.407403738) * (((JLONG)1) << 13) + 0.5))));
        tmp11 += z1 - ((z3) * (((JLONG)((0.76636728200000004) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += z1 + ((z2) * (((JLONG)((1.971951411) * (((JLONG)1) << 13) + 0.5))));
        z2 += z4;
        z1 = ((z2) * (-((JLONG)((0.66665565800000004) * (((JLONG)1) << 13) + 0.5))));
        tmp1 += z1;
        tmp3 += z1 + ((z4) * (((JLONG)((1.0653889620000001) * (((JLONG)1) << 13) + 0.5))));
        z2 = ((z2) * (-((JLONG)((1.247225013) * (((JLONG)1) << 13) + 0.5))));
        tmp10 += z2 + ((z4) * (((JLONG)((3.141271809) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += z2;
        z2 = ((z3 + z4) * (-((JLONG)((1.3533180010000001) * (((JLONG)1) << 13) + 0.5))));
        tmp2 += z2;
        tmp3 += z2;
        z2 = ((z4 - z3) * (((JLONG)((0.410524528) * (((JLONG)1) << 13) + 0.5))));
        tmp10 += z2;
        tmp11 += z2;

        // Output uses indirect write via fixed permutation
        static const int out_idx[16] = {0,15,1,14,2,13,3,12,4,11,5,10,6,9,7,8};
        wsptr[out_idx[0]]  = (int)((tmp20 + tmp0) >> (13 - 1));
        wsptr[out_idx[1]]  = (int)((tmp20 - tmp0) >> (13 - 1));
        wsptr[out_idx[2]]  = (int)((tmp21 + tmp1) >> (13 - 1));
        wsptr[out_idx[3]]  = (int)((tmp21 - tmp1) >> (13 - 1));
        wsptr[out_idx[4]]  = (int)((tmp22 + tmp2) >> (13 - 1));
        wsptr[out_idx[5]]  = (int)((tmp22 - tmp2) >> (13 - 1));
        wsptr[out_idx[6]]  = (int)((tmp23 + tmp3) >> (13 - 1));
        wsptr[out_idx[7]]  = (int)((tmp23 - tmp3) >> (13 - 1));
        wsptr[out_idx[8]]  = (int)((tmp24 + tmp10) >> (13 - 1));
        wsptr[out_idx[9]]  = (int)((tmp24 - tmp10) >> (13 - 1));
        wsptr[out_idx[10]] = (int)((tmp25 + tmp11) >> (13 - 1));
        wsptr[out_idx[11]] = (int)((tmp25 - tmp11) >> (13 - 1));
        wsptr[out_idx[12]] = (int)((tmp26 + tmp12) >> (13 - 1));
        wsptr[out_idx[13]] = (int)((tmp26 - tmp12) >> (13 - 1));
        wsptr[out_idx[14]] = (int)((tmp27 + tmp13) >> (13 - 1));
        wsptr[out_idx[15]] = (int)((tmp27 - tmp13) >> (13 - 1));

        // Manual pointer advancement (maintain original interface)
        inptr++;
        quantptr++;
        wsptr++;
    }
}
