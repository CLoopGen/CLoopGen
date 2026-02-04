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



void loop(){
for (i = 0; i < 8; i++ , ptr += b_stride) {
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

    int diff_p1_p2 = p1 - p2;
    int abs_diff_p1_p2 = (diff_p1_p2 >= 0) ? diff_p1_p2 : -diff_p1_p2;
    int diff_p2_p3 = p2 - p3;
    int abs_diff_p2_p3 = (diff_p2_p3 >= 0) ? diff_p2_p3 : -diff_p2_p3;
    int diff_p3_p4 = p3 - p4;
    int abs_diff_p3_p4 = (diff_p3_p4 >= 0) ? diff_p3_p4 : -diff_p3_p4;
    int diff_p4_p5 = p4 - p5;
    int abs_diff_p4_p5 = (diff_p4_p5 >= 0) ? diff_p4_p5 : -diff_p4_p5;

    t = (abs_diff_p1_p2 <= ql) + (abs_diff_p2_p3 <= ql) + (abs_diff_p3_p4 <= ql) + (abs_diff_p4_p5 <= ql);

    if (t > 0) {
        int diff_p5_p6 = p5 - p6;
        int abs_diff_p5_p6 = (diff_p5_p6 >= 0) ? diff_p5_p6 : -diff_p5_p6;
        int diff_p6_p7 = p6 - p7;
        int abs_diff_p6_p7 = (diff_p6_p7 >= 0) ? diff_p6_p7 : -diff_p6_p7;
        int diff_p7_p8 = p7 - p8;
        int abs_diff_p7_p8 = (diff_p7_p8 >= 0) ? diff_p7_p8 : -diff_p7_p8;
        int diff_p8_p9 = p8 - p9;
        int abs_diff_p8_p9 = (diff_p8_p9 >= 0) ? diff_p8_p9 : -diff_p8_p9;
        int diff_p0_p1 = p0 - p1;
        int abs_diff_p0_p1 = (diff_p0_p1 >= 0) ? diff_p0_p1 : -diff_p0_p1;

        t += (abs_diff_p5_p6 <= ql) + (abs_diff_p6_p7 <= ql) + (abs_diff_p7_p8 <= ql) + (abs_diff_p8_p9 <= ql) + (abs_diff_p0_p1 <= ql);

        if (t >= 6) {
            int values[] = {p1, p2, p3, p4, p5, p6, p7, p8};
            int min = values[0], max = values[0];
            for (int j = 1; j < 8; j++) {
                if (values[j] < min) min = values[j];
                if (values[j] > max) max = values[j];
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

    {
        int x, x0, x1, x2;
        int m;
        x0 = (2 * p3 - 5 * p4 + 5 * p5 - 2 * p6 + 4) >> 3;
        if (((x0) >= 0 ? (x0) : (-(x0))) < quant) {
            x1 = (2 * p1 - 5 * p2 + 5 * p3 - 2 * p4 + 4) >> 3;
            x2 = (2 * p5 - 5 * p6 + 5 * p7 - 2 * p8 + 4) >> 3;
            x = ((x0) >= 0 ? (x0) : (-(x0))) - ((((x1) >= 0 ? (x1) : (-(x1)))) > (((x2) >= 0 ? (x2) : (-(x2)))) ? (((x2) >= 0 ? (x2) : (-(x2)))) : (((x1) >= 0 ? (x1) : (-(x1)))));
            m = p4 - p5;
            if (x > 0 && (m ^ x0) < 0) {
                int32_t sign = m >> 31;
                m = (m ^ sign) - sign;
                m >>= 1;
                x = 5 * x >> 3;
                if (x > m) x = m;
                x = (x ^ sign) - sign;
                ptr[-1 * a_stride] -= x;
                ptr[0] += x;
            }
        }
    }
}
}
