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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 16 - 1; ctr >= 0; ctr -= 2) {
        // Unrolled version: duplicate operations for two iterations

        // First "iteration"
        tmp0 = dataptr[8 * 0] + wsptr[8 * 5];
        tmp1 = dataptr[8 * 1] + wsptr[8 * 4];
        tmp2 = dataptr[8 * 2] + wsptr[8 * 3];
        tmp13 = dataptr[8 * 3] + wsptr[8 * 2];
        tmp4 = dataptr[8 * 4] + wsptr[8 * 1];
        tmp5 = dataptr[8 * 5] + wsptr[8 * 0];
        tmp6 = dataptr[8 * 6] + dataptr[8 * 7];

        tmp10 = tmp0 + tmp6;
        tmp14 = tmp0 - tmp6;
        tmp11 = tmp1 + tmp5;
        tmp15 = tmp1 - tmp5;
        tmp12 = tmp2 + tmp4;
        tmp16 = tmp2 - tmp4;

        tmp0 = dataptr[8 * 0] - wsptr[8 * 5];
        tmp1 = dataptr[8 * 1] - wsptr[8 * 4];
        tmp2 = dataptr[8 * 2] - wsptr[8 * 3];
        tmp3 = dataptr[8 * 3] - wsptr[8 * 2];
        tmp4 = dataptr[8 * 4] - wsptr[8 * 1];
        tmp5 = dataptr[8 * 5] - wsptr[8 * 0];
        tmp6 = dataptr[8 * 6] - dataptr[8 * 7];

        dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp11 + tmp12 + tmp13) * ((INT32)(0.653061224 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));
        tmp13 += tmp13;
        dataptr[8 * 4] = (DCTELEM)((((tmp10 - tmp13) * ((INT32)(0.832106052 * (1 << 13) + 0.5)) + 
                                   (tmp11 - tmp13) * ((INT32)(0.205513223 * (1 << 13) + 0.5)) - 
                                   (tmp12 - tmp13) * ((INT32)(0.575835255 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp10 = (tmp14 + tmp15) * ((INT32)(0.72207457 * (1 << 13) + 0.5));
        dataptr[8 * 2] = (DCTELEM)(((tmp10 + tmp14 * ((INT32)(0.178337691 * (1 << 13) + 0.5)) + 
                                      tmp16 * ((INT32)(0.400721155 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));
        dataptr[8 * 6] = (DCTELEM)(((tmp10 - tmp15 * ((INT32)(1.122795725 * (1 << 13) + 0.5)) - 
                                      tmp16 * ((INT32)(0.900412262 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp10 = tmp1 + tmp2;
        tmp11 = tmp5 - tmp4;
        dataptr[8 * 7] = (DCTELEM)((((tmp0 - tmp10 + tmp3 - tmp11 - tmp6) * ((INT32)(0.653061224 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp3 = tmp3 * ((INT32)(0.653061224 * (1 << 13) + 0.5));
        tmp10 = tmp10 * (-(INT32)(0.103406812 * (1 << 13) + 0.5));
        tmp11 = tmp11 * ((INT32)(0.917760839 * (1 << 13) + 0.5));
        tmp10 += tmp11 - tmp3;

        tmp11 = (tmp0 + tmp2) * ((INT32)(0.78200741 * (1 << 13) + 0.5)) + (tmp4 + tmp6) * ((INT32)(0.491367823 * (1 << 13) + 0.5));
        dataptr[8 * 5] = (DCTELEM)(((tmp10 + tmp11 - tmp2 * ((INT32)(1.550341076 * (1 << 13) + 0.5)) + 
                                      tmp4 * ((INT32)(0.731428202 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp12 = (tmp0 + tmp1) * ((INT32)(0.871740478 * (1 << 13) + 0.5)) + (tmp5 - tmp6) * ((INT32)(0.305035186 * (1 << 13) + 0.5));
        dataptr[8 * 3] = (DCTELEM)(((tmp10 + tmp12 - tmp1 * ((INT32)(0.276965844 * (1 << 13) + 0.5)) - 
                                      tmp5 * ((INT32)(2.004803435 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));
        dataptr[8 * 1] = (DCTELEM)(((tmp11 + tmp12 + tmp3 - tmp0 * ((INT32)(0.735987049 * (1 << 13) + 0.5)) - 
                                      tmp6 * ((INT32)(0.082925825 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        DCTELEM* next_dataptr = dataptr + 1;
        DCTELEM* next_wsptr = wsptr + 1;

        // Second "iteration" (duplicate with offset)
        tmp0 = next_dataptr[8 * 0] + next_wsptr[8 * 5];
        tmp1 = next_dataptr[8 * 1] + next_wsptr[8 * 4];
        tmp2 = next_dataptr[8 * 2] + next_wsptr[8 * 3];
        tmp13 = next_dataptr[8 * 3] + next_wsptr[8 * 2];
        tmp4 = next_dataptr[8 * 4] + next_wsptr[8 * 1];
        tmp5 = next_dataptr[8 * 5] + next_wsptr[8 * 0];
        tmp6 = next_dataptr[8 * 6] + next_dataptr[8 * 7];

        tmp10 = tmp0 + tmp6;
        tmp14 = tmp0 - tmp6;
        tmp11 = tmp1 + tmp5;
        tmp15 = tmp1 - tmp5;
        tmp12 = tmp2 + tmp4;
        tmp16 = tmp2 - tmp4;

        tmp0 = next_dataptr[8 * 0] - next_wsptr[8 * 5];
        tmp1 = next_dataptr[8 * 1] - next_wsptr[8 * 4];
        tmp2 = next_dataptr[8 * 2] - next_wsptr[8 * 3];
        tmp3 = next_dataptr[8 * 3] - next_wsptr[8 * 2];
        tmp4 = next_dataptr[8 * 4] - next_wsptr[8 * 1];
        tmp5 = next_dataptr[8 * 5] - next_wsptr[8 * 0];
        tmp6 = next_dataptr[8 * 6] - next_dataptr[8 * 7];

        next_dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp11 + tmp12 + tmp13) * ((INT32)(0.653061224 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));
        tmp13 += tmp13;
        next_dataptr[8 * 4] = (DCTELEM)((((tmp10 - tmp13) * ((INT32)(0.832106052 * (1 << 13) + 0.5)) + 
                                        (tmp11 - tmp13) * ((INT32)(0.205513223 * (1 << 13) + 0.5)) - 
                                        (tmp12 - tmp13) * ((INT32)(0.575835255 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp10 = (tmp14 + tmp15) * ((INT32)(0.72207457 * (1 << 13) + 0.5));
        next_dataptr[8 * 2] = (DCTELEM)(((tmp10 + tmp14 * ((INT32)(0.178337691 * (1 << 13) + 0.5)) + 
                                      tmp16 * ((INT32)(0.400721155 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));
        next_dataptr[8 * 6] = (DCTELEM)(((tmp10 - tmp15 * ((INT32)(1.122795725 * (1 << 13) + 0.5)) - 
                                      tmp16 * ((INT32)(0.900412262 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp10 = tmp1 + tmp2;
        tmp11 = tmp5 - tmp4;
        next_dataptr[8 * 7] = (DCTELEM)((((tmp0 - tmp10 + tmp3 - tmp11 - tmp6) * ((INT32)(0.653061224 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp3 = tmp3 * ((INT32)(0.653061224 * (1 << 13) + 0.5));
        tmp10 = tmp10 * (-(INT32)(0.103406812 * (1 << 13) + 0.5));
        tmp11 = tmp11 * ((INT32)(0.917760839 * (1 << 13) + 0.5));
        tmp10 += tmp11 - tmp3;

        tmp11 = (tmp0 + tmp2) * ((INT32)(0.78200741 * (1 << 13) + 0.5)) + (tmp4 + tmp6) * ((INT32)(0.491367823 * (1 << 13) + 0.5));
        next_dataptr[8 * 5] = (DCTELEM)(((tmp10 + tmp11 - tmp2 * ((INT32)(1.550341076 * (1 << 13) + 0.5)) + 
                                      tmp4 * ((INT32)(0.731428202 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        tmp12 = (tmp0 + tmp1) * ((INT32)(0.871740478 * (1 << 13) + 0.5)) + (tmp5 - tmp6) * ((INT32)(0.305035186 * (1 << 13) + 0.5));
        next_dataptr[8 * 3] = (DCTELEM)(((tmp10 + tmp12 - tmp1 * ((INT32)(0.276965844 * (1 << 13) + 0.5)) - 
                                      tmp5 * ((INT32)(2.004803435 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));
        next_dataptr[8 * 1] = (DCTELEM)(((tmp11 + tmp12 + tmp3 - tmp0 * ((INT32)(0.735987049 * (1 << 13) + 0.5)) - 
                                      tmp6 * ((INT32)(0.082925825 * (1 << 13) + 0.5))) + (1 << (13 + 1 - 1))) >> (13 + 1));

        dataptr += 2;
        wsptr += 2;
    }
}
