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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 7; ctr++) {
    elemptr = sample_data[ctr] + start_col;

    const int indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    tmp0 = ((int)(elemptr[indices[0]])) + ((int)(elemptr[indices[13]]));
    tmp1 = ((int)(elemptr[indices[1]])) + ((int)(elemptr[indices[12]]));
    tmp2 = ((int)(elemptr[indices[2]])) + ((int)(elemptr[indices[11]]));
    tmp13 = ((int)(elemptr[indices[3]])) + ((int)(elemptr[indices[10]]));
    tmp4 = ((int)(elemptr[indices[4]])) + ((int)(elemptr[indices[9]]));
    tmp5 = ((int)(elemptr[indices[5]])) + ((int)(elemptr[indices[8]]));
    tmp6 = ((int)(elemptr[indices[6]])) + ((int)(elemptr[indices[7]]));
    tmp10 = tmp0 + tmp6;
    tmp14 = tmp0 - tmp6;
    tmp11 = tmp1 + tmp5;
    tmp15 = tmp1 - tmp5;
    tmp12 = tmp2 + tmp4;
    tmp16 = tmp2 - tmp4;
    tmp0 = ((int)(elemptr[indices[0]])) - ((int)(elemptr[indices[13]]));
    tmp1 = ((int)(elemptr[indices[1]])) - ((int)(elemptr[indices[12]]));
    tmp2 = ((int)(elemptr[indices[2]])) - ((int)(elemptr[indices[11]]));
    tmp3 = ((int)(elemptr[indices[3]])) - ((int)(elemptr[indices[10]]));
    tmp4 = ((int)(elemptr[indices[4]])) - ((int)(elemptr[indices[9]]));
    tmp5 = ((int)(elemptr[indices[5]])) - ((int)(elemptr[indices[8]]));
    tmp6 = ((int)(elemptr[indices[6]])) - ((int)(elemptr[indices[7]]));

    ptrdiff_t stride = 8;
    for (int k = 0; k < 8; k++) {
        int idx = k * stride;
        switch(k) {
            case 0:
                dataptr[idx] = (DCTELEM)((tmp10 + tmp11 + tmp12 + tmp13 - 14 * 128) << 2);
                break;
            case 4:
                dataptr[idx] = (DCTELEM)(((((tmp10 - tmp13) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 - tmp13) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp12 - tmp13) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
                break;
            case 2:
                dataptr[idx] = (DCTELEM)(((tmp10 + ((tmp14) * (((INT32)((0.27307958999999998) * (((INT32)1) << 13) + 0.5)))) + ((tmp16) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
                break;
            case 6:
                dataptr[idx] = (DCTELEM)(((tmp10 - ((tmp15) * (((INT32)((1.719280954) * (((INT32)1) << 13) + 0.5)))) - ((tmp16) * (((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
                break;
            case 7:
                dataptr[idx] = (DCTELEM)((tmp0 - tmp10 + tmp3 - tmp11 - tmp6) << 2);
                break;
            case 5:
                dataptr[idx] = (DCTELEM)(((tmp10 + tmp11 - ((tmp2) * (((INT32)((2.3739597730000002) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((1.119999435) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
                break;
            case 3:
                dataptr[idx] = (DCTELEM)(((tmp10 + tmp12 - ((tmp1) * (((INT32)((0.42410394800000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp5) * (((INT32)((3.0698552590000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
                break;
            case 1:
                dataptr[idx] = (DCTELEM)(((tmp11 + tmp12 + tmp3 + tmp6 - ((tmp0 + tmp6) * (((INT32)((1.1269801690000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
                break;
        }
    }
    dataptr += 8 * 8;
}

}
