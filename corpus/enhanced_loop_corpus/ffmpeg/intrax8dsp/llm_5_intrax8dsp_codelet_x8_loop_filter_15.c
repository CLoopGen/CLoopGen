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

    // Combine all edge strength checks into one early-exit condition
    int e1 = (p1 - p2), e2 = (p2 - p3), e3 = (p3 - p4), e4 = (p4 - p5);
    int e5 = (p5 - p6), e6 = (p6 - p7), e7 = (p7 - p8), e8 = (p8 - p9), e0 = (p0 - p1);
    e1 = (e1 >= 0 ? e1 : -e1); e2 = (e2 >= 0 ? e2 : -e2);
    e3 = (e3 >= 0 ? e3 : -e3); e4 = (e4 >= 0 ? e4 : -e4);
    e5 = (e5 >= 0 ? e5 : -e5); e6 = (e6 >= 0 ? e6 : -e6);
    e7 = (e7 >= 0 ? e7 : -e7); e8 = (e8 >= 0 ? e8 : -e8);
    e0 = (e0 >= 0 ? e0 : -e0);

    t = (e1 <= ql) + (e2 <= ql) + (e3 <= ql) + (e4 <= ql) + (e5 <= ql) + (e6 <= ql) + (e7 <= ql) + (e8 <= ql) + (e0 <= ql);

    // Early exit based on combined threshold without deep nesting
    if (t < 6) {
        int x0 = (2 * p3 - 5 * p4 + 5 * p5 - 2 * p6 + 4) >> 3;
        int abs_x0 = (x0 >= 0 ? x0 : -x0);
        if (abs_x0 >= quant) {
            // Skip processing and move to next iteration
            continue;
        }

        int x1 = (2 * p1 - 5 * p2 + 5 * p3 - 2 * p4 + 4) >> 3;
        int x2 = (2 * p5 - 5 * p6 + 5 * p7 - 2 * p8 + 4) >> 3;
        int abs_x1 = (x1 >= 0 ? x1 : -x1);
        int abs_x2 = (x2 >= 0 ? x2 : -x2);
        int x = abs_x0 - (abs_x1 > abs_x2 ? abs_x2 : abs_x1);
        int m = p4 - p5;

        // Flattened logic: only apply correction if both conditions are met
        if (x > 0 && ((m ^ x0) < 0)) {
            int32_t sign = m >> 31;
            m = (m ^ sign) - sign;
            m >>= 1;
            x = (5 * x) >> 3;
            if (x > m) x = m;
            x = (x ^ sign) - sign;
            ptr[-1 * a_stride] -= x;
            ptr[0] += x;
        } else {
            // Fallback: apply minimal adjustment unconditionally
            ptr[-1 * a_stride] = (3 * p4 + 1 * p5 + 2) >> 2;
            ptr[0] = (1 * p4 + 3 * p5 + 2) >> 2;
        }
        continue;
    }

    // If t >= 6, proceed with the filtering path
    int min = p1, max = p1;
    if (p3 < min) min = p3; if (p3 > max) max = p3;
    if (p5 < min) min = p5; if (p5 > max) max = p5;
    if (p8 < min) min = p8; if (p8 > max) max = p8;

    if (max - min >= 2 * quant) continue;

    if (p2 < min) min = p2; if (p2 > max) max = p2;
    if (p4 < min) min = p4; if (p4 > max) max = p4;
    if (p6 < min) min = p6; if (p6 > max) max = p6;
    if (p7 < min) min = p7; if (p7 > max) max = p7;

    if (max - min >= 2 * quant) continue;

    // Apply filter updates directly
    ptr[-2 * a_stride] = (4 * p2 + 3 * p3 + 1 * p7 + 4) >> 3;
    ptr[-1 * a_stride] = (3 * p2 + 3 * p4 + 2 * p7 + 4) >> 3;
    ptr[0] = (2 * p2 + 3 * p5 + 3 * p7 + 4) >> 3;
    ptr[1 * a_stride] = (1 * p2 + 3 * p6 + 4 * p7 + 4) >> 3;
}
}
