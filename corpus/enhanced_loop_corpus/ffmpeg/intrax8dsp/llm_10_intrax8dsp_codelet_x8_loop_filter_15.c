#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern  ptrdiff_t a_stride;
extern  ptrdiff_t b_stride;
extern int quant;
extern int i;
extern int t;
extern int p0;
extern int p1;
extern int p2;
extern int p3;
extern int p4;
extern int p5;
extern int p6;
extern int p7;
extern int p8;
extern int p9;
extern int ql;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 4; i++, ptr += b_stride) {
        p0 = ptr[-5 * a_stride];
        p1 = ptr[-4 * a_stride];
        p2 = ptr[-3 * a_stride];
        p3 = ptr[-2 * a_stride];
        p4 = ptr[-1 * a_stride];
        p5 = ptr[0];
        p6 = ptr[1 * a_stride];
        p7 = ptr[2 * a_stride];
        p8 = ptr[3 * a_stride];
        p9 = ptr[4 * a_stride];

        t = 0;
        int diff;

        #define CHECK_DIFF(a, b) \
            diff = (a) - (b); \
            t += (diff >= 0 ? diff : -diff) <= ql;

        CHECK_DIFF(p1, p2);
        CHECK_DIFF(p2, p3);
        CHECK_DIFF(p3, p4);
        CHECK_DIFF(p4, p5);

        if (t > 0) {
            CHECK_DIFF(p5, p6);
            CHECK_DIFF(p6, p7);
            CHECK_DIFF(p7, p8);
            CHECK_DIFF(p8, p9);
            CHECK_DIFF(p0, p1);

            if (t >= 6) {
                int values[] = {p1, p2, p3, p4, p5, p7, p8};
                int min = p1, max = p1;
                for (int j = 1; j < 7; j++) {
                    min = (min > values[j]) ? values[j] : min;
                    max = (max > values[j]) ? max : values[j];
                }

                if (max - min < 2 * quant) {
                    int values2[] = {p2, p4, p6, p7};
                    for (int j = 0; j < 4; j++) {
                        min = (min > values2[j]) ? values2[j] : min;
                        max = (max > values2[j]) ? max : values2[j];
                    }

                    if (max - min < 2 * quant) {
                        ptr[-2 * a_stride] = (4 * p2 + 3 * p3 + 1 * p7 + 4) >> 3;
                        ptr[-1 * a_stride] = (3 * p2 + 3 * p4 + 2 * p7 + 4) >> 3;
                        ptr[0] = (2 * p2 + 3 * p5 + 3 * p7 + 4) >> 3;
                        ptr[1 * a_stride] = (1 * p2 + 3 * p6 + 4 * p7 + 4) >> 3;
                        continue;
                    }
                }
            }
        }

        {
            int x0 = (2 * p3 - 5 * p4 + 5 * p5 - 2 * p6 + 4) >> 3;
            if ((x0 >= 0 ? x0 : -x0) < quant) {
                int x1 = (2 * p1 - 5 * p2 + 5 * p3 - 2 * p4 + 4) >> 3;
                int x2 = (2 * p5 - 5 * p6 + 5 * p7 - 2 * p8 + 4) >> 3;
                int abs_x0 = x0 >= 0 ? x0 : -x0;
                int abs_x1 = x1 >= 0 ? x1 : -x1;
                int abs_x2 = x2 >= 0 ? x2 : -x2;
                int x = abs_x0 - (abs_x1 > abs_x2 ? abs_x2 : abs_x1);
                int m = p4 - p5;

                if (x > 0 && (m ^ x0) < 0) {
                    int32_t sign = m >> 31;
                    m = (m ^ sign) - sign;
                    m >>= 1;
                    x = (5 * x) >> 3;
                    if (x > m) x = m;
                    x = (x ^ sign) - sign;
                    ptr[-1 * a_stride] -= x;
                    ptr[0] += x;
                }
            }
        }
    }
}
