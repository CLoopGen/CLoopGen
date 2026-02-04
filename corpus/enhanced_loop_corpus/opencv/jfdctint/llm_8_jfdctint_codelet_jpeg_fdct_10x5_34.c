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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ctr++) {
    JSAMPROW local_elemptr = sample_data[ctr] + start_col;
    DCTELEM* local_dataptr = dataptr + 8 * ctr;

    INT32 t0, t1, t2, t3, t4;
    t0 = ((int)(local_elemptr[0])) + ((int)(local_elemptr[9]));
    t1 = ((int)(local_elemptr[1])) + ((int)(local_elemptr[8]));
    t2 = ((int)(local_elemptr[2])) + ((int)(local_elemptr[7]));
    t3 = ((int)(local_elemptr[3])) + ((int)(local_elemptr[6]));
    t4 = ((int)(local_elemptr[4])) + ((int)(local_elemptr[5]));

    INT32 sum_04 = t0 + t4;
    INT32 dif_04 = t0 - t4;
    INT32 sum_13 = t1 + t3;
    INT32 dif_13 = t1 - t3;

    INT32 u0 = ((int)(local_elemptr[0])) - ((int)(local_elemptr[9]));
    INT32 u1 = ((int)(local_elemptr[1])) - ((int)(local_elemptr[8]));
    INT32 u2 = ((int)(local_elemptr[2])) - ((int)(local_elemptr[7]));
    INT32 u3 = ((int)(local_elemptr[3])) - ((int)(local_elemptr[6]));
    INT32 u4 = ((int)(local_elemptr[4])) - ((int)(local_elemptr[5]));

    local_dataptr[0] = (DCTELEM)((sum_04 + sum_13 + t2 - 10 * 128) << 2);
    INT32 scaled_t2 = t2 << 1;
    local_dataptr[4] = (DCTELEM)(((((sum_04 - scaled_t2) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5)))) - 
                                ((sum_13 - scaled_t2) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))))) + 
                               ((INT32)1 << 10)) >> 11);

    INT32 temp_sum_dif = (dif_04 + dif_13) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5)));
    local_dataptr[2] = (DCTELEM)(((temp_sum_dif + (dif_04 * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))))) + 1024) >> 11);
    local_dataptr[6] = (DCTELEM)(((temp_sum_dif - (dif_13 * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))))) + 1024) >> 11);

    INT32 vsum = u0 + u4;
    INT32 vdif = u1 - u3;
    local_dataptr[5] = (DCTELEM)((vsum - vdif - u2) << 2);

    u2 <<= 13;
    local_dataptr[1] = (DCTELEM)((((u0 * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) +
                                  (u1 * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) +
                                  u2 +
                                  (u3 * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) +
                                 (u4 * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5))))) + 1024) >> 11);

    INT32 partA = (u0 - u4) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5)));
    INT32 partB = (u1 + u3) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5)));
    INT32 wsum = vsum + vdif;
    INT32 mixed_term = (wsum * (((INT32)((0.30901699399999999) * (((INT32)1) << 13) + 0.5)))) + (vdif << 12) - u2;

    local_dataptr[3] = (DCTELEM)(((partA - partB + mixed_term) + 1024) >> 11);
    local_dataptr[7] = (DCTELEM)(((partA - partB - mixed_term) + 1024) >> 11);
}

}
