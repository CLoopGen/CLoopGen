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



void loop() {
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        // Variant 1: Consecutive Memory Access with Local Array Buffering
        // Instead of strided access (8 * i), use local arrays to store consecutive inputs
        DCTELEM data_cache[8];
        DCTELEM ws_cache[8];
        
        // Pre-load data using base pointer arithmetic with stride 8 -> now accessed consecutively
        for (int i = 0; i < 8; i++) {
            data_cache[i] = dataptr[i * 8];  // Original: dataptr[8*i]
            ws_cache[i]    = wsptr[i * 8];   // Original: wsptr[8*i]
        }

        tmp0 = data_cache[0] + ws_cache[7];
        tmp1 = data_cache[1] + ws_cache[6];
        tmp2 = data_cache[2] + ws_cache[5];
        tmp3 = data_cache[3] + ws_cache[4];
        tmp4 = data_cache[4] + ws_cache[3];
        tmp5 = data_cache[5] + ws_cache[2];
        tmp6 = data_cache[6] + ws_cache[1];
        tmp7 = data_cache[7] + ws_cache[0];
        tmp10 = tmp0 + tmp7;
        tmp14 = tmp0 - tmp7;
        tmp11 = tmp1 + tmp6;
        tmp15 = tmp1 - tmp6;
        tmp12 = tmp2 + tmp5;
        tmp16 = tmp2 - tmp5;
        tmp13 = tmp3 + tmp4;
        tmp17 = tmp3 - tmp4;
        tmp0 = data_cache[0] - ws_cache[7];
        tmp1 = data_cache[1] - ws_cache[6];
        tmp2 = data_cache[2] - ws_cache[5];
        tmp3 = data_cache[3] - ws_cache[4];
        tmp4 = data_cache[4] - ws_cache[3];
        tmp5 = data_cache[5] - ws_cache[2];
        tmp6 = data_cache[6] - ws_cache[1];
        tmp7 = data_cache[7] - ws_cache[0];

        dataptr[8 * 0] = (DCTELEM)(((tmp10 + tmp11 + tmp12 + tmp13) + ((INT32)1 << ((2 + 2) - 1))) >> (2 + 2));
        dataptr[8 * 4] = (DCTELEM)(((((tmp10 - tmp13) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 - tmp12) * (((INT32)4433)))) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
        tmp10 = ((tmp17 - tmp15) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5)))) + ((tmp14 - tmp16) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
        dataptr[8 * 2] = (DCTELEM)(((tmp10 + ((tmp15) * (((INT32)((1.4517749820000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp16) * (((INT32)((2.1727348040000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
        dataptr[8 * 6] = (DCTELEM)(((tmp10 - ((tmp14) * (((INT32)((0.211164243) * (((INT32)1) << 13) + 0.5)))) - ((tmp17) * (((INT32)((1.0615943379999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
        tmp11 = ((tmp0 + tmp1) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp6 - tmp7) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((tmp0 + tmp2) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5)))) + ((tmp5 + tmp7) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((tmp0 + tmp3) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp4 - tmp7) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((tmp1 + tmp2) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp6 - tmp5) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
        tmp15 = ((tmp1 + tmp3) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5)))) + ((tmp4 + tmp6) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
        tmp16 = ((tmp2 + tmp3) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp5 - tmp4) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((tmp0) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp7) * (((INT32)((0.77965362500000002) * (((INT32)1) << 13) + 0.5))));
        tmp11 += tmp14 + tmp15 + ((tmp1) * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5)))) - ((tmp6) * (((INT32)((1.663905119) * (((INT32)1) << 13) + 0.5))));
        tmp12 += tmp14 + tmp16 - ((tmp2) * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5)))) + ((tmp5) * (((INT32)((1.227391138) * (((INT32)1) << 13) + 0.5))));
        tmp13 += tmp15 + tmp16 + ((tmp3) * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((2.1679856919999998) * (((INT32)1) << 13) + 0.5))));
        dataptr[8 * 1] = (DCTELEM)(((tmp10) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
        dataptr[8 * 3] = (DCTELEM)(((tmp11) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
        dataptr[8 * 5] = (DCTELEM)(((tmp12) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
        dataptr[8 * 7] = (DCTELEM)(((tmp13) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

        dataptr++;
        wsptr++;
    }
}
