#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

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
extern INT32 tmp17;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    INT32 t0 = dataptr[8 * 0] + wsptr[8 * 7];
    INT32 t1 = dataptr[8 * 1] + wsptr[8 * 6];
    INT32 t2 = dataptr[8 * 2] + wsptr[8 * 5];
    INT32 t3 = dataptr[8 * 3] + wsptr[8 * 4];
    INT32 t4 = dataptr[8 * 4] + wsptr[8 * 3];
    INT32 t5 = dataptr[8 * 5] + wsptr[8 * 2];
    INT32 t6 = dataptr[8 * 6] + wsptr[8 * 1];
    INT32 t7 = dataptr[8 * 7] + wsptr[8 * 0];

    INT32 u0 = dataptr[8 * 0] - wsptr[8 * 7];
    INT32 u1 = dataptr[8 * 1] - wsptr[8 * 6];
    INT32 u2 = dataptr[8 * 2] - wsptr[8 * 5];
    INT32 u3 = dataptr[8 * 3] - wsptr[8 * 4];
    INT32 u4 = dataptr[8 * 4] - wsptr[8 * 3];
    INT32 u5 = dataptr[8 * 5] - wsptr[8 * 2];
    INT32 u6 = dataptr[8 * 6] - wsptr[8 * 1];
    INT32 u7 = dataptr[8 * 7] - wsptr[8 * 0];

    INT32 v10 = t0 + t7;
    INT32 v14 = t0 - t7;
    INT32 v11 = t1 + t6;
    INT32 v15 = t1 - t6;
    INT32 v12 = t2 + t5;
    INT32 v16 = t2 - t5;
    INT32 v13 = t3 + t4;
    INT32 v17 = t3 - t4;

    dataptr[8 * 0] = (DCTELEM)(((v10 + v11 + v12 + v13) + ((INT32)1 << ((2 + 2) - 1))) >> (2 + 2));
    dataptr[8 * 4] = (DCTELEM)(((((v10 - v13) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5)))) + ((v11 - v12) * (((INT32)4433)))) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

    INT32 w10 = ((v17 - v15) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5)))) + ((v14 - v16) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 2] = (DCTELEM)(((w10 + ((v15) * (((INT32)((1.4517749820000001) * (((INT32)1) << 13) + 0.5)))) + ((v16) * (((INT32)((2.1727348040000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
    dataptr[8 * 6] = (DCTELEM)(((w10 - ((v14) * (((INT32)((0.211164243) * (((INT32)1) << 13) + 0.5)))) - ((v17) * (((INT32)((1.0615943379999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

    INT32 w11 = ((u0 + u1) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((u6 - u7) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
    INT32 w12 = ((u0 + u2) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5)))) + ((u5 + u7) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
    INT32 w13 = ((u0 + u3) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5)))) + ((u4 - u7) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
    INT32 w14 = ((u1 + u2) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5)))) + ((u6 - u5) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
    INT32 w15 = ((u1 + u3) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5)))) + ((u4 + u6) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
    INT32 w16 = ((u2 + u3) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((u5 - u4) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));

    INT32 x10 = w11 + w12 + w13 - ((u0) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5)))) + ((u7) * (((INT32)((0.77965362500000002) * (((INT32)1) << 13) + 0.5))));
    INT32 x11 = w11 + w14 + w15 + ((u1) * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5)))) - ((u6) * (((INT32)((1.663905119) * (((INT32)1) << 13) + 0.5))));
    INT32 x12 = w12 + w14 + w16 - ((u2) * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5)))) + ((u5) * (((INT32)((1.227391138) * (((INT32)1) << 13) + 0.5))));
    INT32 x13 = w13 + w15 + w16 + ((u3) * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5)))) + ((u4) * (((INT32)((2.1679856919999998) * (((INT32)1) << 13) + 0.5))));

    dataptr[8 * 1] = (DCTELEM)(((x10) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
    dataptr[8 * 3] = (DCTELEM)(((x11) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
    dataptr[8 * 5] = (DCTELEM)(((x12) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
    dataptr[8 * 7] = (DCTELEM)(((x13) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

    dataptr++;
    wsptr++;
}
}
