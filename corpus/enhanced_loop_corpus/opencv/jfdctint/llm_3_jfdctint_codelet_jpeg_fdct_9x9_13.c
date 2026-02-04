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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    DCTELEM *data_base = dataptr;
    DCTELEM *ws_base = wsptr;

    for (ctr = 0; ctr < 8; ctr++) {
        ptrdiff_t index = (ctr & 3) * 2 + ((ctr >> 2) ^ 1) * 8;

        tmp0 = data_base[index + 0] + ws_base[index + 0];
        tmp1 = data_base[index + 8] + data_base[index + 56];
        tmp2 = data_base[index + 16] + data_base[index + 48];
        tmp3 = data_base[index + 24] + data_base[index + 40];
        tmp4 = data_base[index + 32];
        tmp10 = data_base[index + 0] - ws_base[index + 0];
        tmp11 = data_base[index + 8] - data_base[index + 56];
        tmp12 = data_base[index + 16] - data_base[index + 48];
        tmp13 = data_base[index + 24] - data_base[index + 40];

        z1 = tmp0 + tmp2 + tmp3;
        z2 = tmp1 + tmp4;
        data_base[index + 0] = (DCTELEM)((((z1 + z2) * (((INT32)((1.5802469139999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 14)) >> 15);
        data_base[index + 48] = (DCTELEM)((((z1 - z2 - z2) * (((INT32)((1.117403309) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 14)) >> 15);

        z1 = ((tmp0 - tmp2) * (((INT32)((2.1000312870000002) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp1 - tmp4 - tmp4) * (((INT32)((1.117403309) * (((INT32)1) << 13) + 0.5))));
        data_base[index + 16] = (DCTELEM)((((tmp2 - tmp3) * (((INT32)((1.71196119) * (((INT32)1) << 13) + 0.5)))) + z1 + z2 + ((INT32)1 << 14)) >> 15);
        data_base[index + 32] = (DCTELEM)((((tmp3 - tmp0) * (((INT32)((0.38807009599999998) * (((INT32)1) << 13) + 0.5)))) + z1 - z2 + ((INT32)1 << 14)) >> 15);

        data_base[index + 24] = (DCTELEM)((((tmp10 - tmp12 - tmp13) * (((INT32)((1.9353993030000001) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 14)) >> 15);

        tmp11 = (tmp11 * (((INT32)((1.9353993030000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 = ((tmp10 + tmp12) * (((INT32)((1.4365060039999999) * (((INT32)1) << 13) + 0.5))));
        tmp1 = ((tmp10 + tmp13) * (((INT32)((0.76434887900000004) * (((INT32)1) << 13) + 0.5))));

        data_base[index + 8] = (DCTELEM)(((tmp11 + tmp0 + tmp1) + ((INT32)1 << 14)) >> 15);

        tmp2 = ((tmp12 - tmp13) * (((INT32)((2.2008548829999999) * (((INT32)1) << 13) + 0.5))));
        data_base[index + 40] = (DCTELEM)(((tmp0 - tmp11 - tmp2) + ((INT32)1 << 14)) >> 15);
        data_base[index + 56] = (DCTELEM)(((tmp1 - tmp11 + tmp2) + ((INT32)1 << 14)) >> 15);
    }
}
