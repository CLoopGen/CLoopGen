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
for (i = 0; i < 8; ++i) {
    uint8_t *base_ptr = ptr + i * b_stride;

    p0 = base_ptr[-5 * a_stride];
    p1 = base_ptr[-4 * a_stride];
    p2 = base_ptr[-3 * a_stride];
    p3 = base_ptr[-2 * a_stride];
    p4 = base_ptr[-1 * a_stride];
    p5 = base_ptr[0];
    p6 = base_ptr[1 * a_stride];
    p7 = base_ptr[2 * a_stride];
    p8 = base_ptr[3 * a_stride];
    p9 = base_ptr[4 * a_stride];

    int cond1 = (p1 - p2);
    int cond2 = (p2 - p3);
    int cond3 = (p3 - p4);
    int cond4 = (p4 - p5);
    t = ((cond1 >= 0 ? cond1 : -cond1) <= ql) +
        ((cond2 >= 0 ? cond2 : -cond2) <= ql) +
        ((cond3 >= 0 ? cond3 : -cond3) <= ql) +
        ((cond4 >= 0 ? cond4 : -cond4) <= ql);

    if (t > 0) {
        int cond5 = (p5 - p6);
        int cond6 = (p6 - p7);
        int cond7 = (p7 - p8);
        int cond8 = (p8 - p9);
        int cond0 = (p0 - p1);
        t += ((cond5 >= 0 ? cond5 : -cond5) <= ql) +
             ((cond6 >= 0 ? cond6 : -cond6) <= ql) +
             ((cond7 >= 0 ? cond7 : -cond7) <= ql) +
             ((cond8 >= 0 ? cond8 : -cond8) <= ql) +
             ((cond0 >= 0 ? cond0 : -cond0) <= ql);

        if (t >= 6) {
            int candidates[] = {p1, p3, p5, p8};
            int min = p1, max = p1;
            for (int k = 0; k < 4; ++k) {
                min = (candidates[k] < min) ? candidates[k] : min;
                max = (candidates[k] > max) ? candidates[k] : max;
            }
            if (max - min < 2 * quant) {
                int inner_candidates[] = {p2, p4, p6, p7};
                for (int k = 0; k < 4; ++k) {
                    min = (inner_candidates[k] < min) ? inner_candidates[k] : min;
                    max = (inner_candidates[k] > max) ? inner_candidates[k] : max;
                }
                if (max - min < 2 * quant) {
                    ptr[-2 * a_stride] = (4 * p2 + 3 * p3 + p7 + 4) >> 3;
                    ptr[-1 * a_stride] = (3 * p2 + 3 * p4 + 2 * p7 + 4) >> 3;
                    ptr[0] = (2 * p2 + 3 * p5 + 3 * p7 + 4) >> 3;
                    ptr[1 * a_stride] = (p2 + 3 * p6 + 4 * p7 + 4) >> 3;
                    i--; 
                    ptr += b_stride;
                    continue;
                }
            }
        }
    }

    int x0 = (2 * p3 - 5 * p4 + 5 * p5 - 2 * p6 + 4) >> 3;
    if ((x0 >= 0 ? x0 : -x0) < quant) {
        int x1 = (2 * p1 - 5 * p2 + 5 * p3 - 2 * p4 + 4) >> 3;
        int x2 = (2 * p5 - 5 * p6 + 5 * p7 - 2 * p8 + 4) >> 3;
        int abs_x0 = (x0 >= 0 ? x0 : -x0);
        int abs_x1 = (x1 >= 0 ? x1 : -x1);
        int abs_x2 = (x2 >= 0 ? x2 : -x2);
        int x = abs_x0 - (abs_x1 > abs_x2 ? abs_x2 : abs_x1);
        int m = p4 - p5;
        if (x > 0 && (m ^ x0) < 0) {
            int32_t sign = (m >> 31);
            m = (m ^ sign) - sign;
            m >>= 1;
            x = (5 * x) >> 3;
            if (x > m) x = m;
            x = (x ^ sign) - sign;
            ptr[-1 * a_stride] -= x;
            ptr[0] += x;
        }
    }
    ptr += b_stride;
}
}
