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
    for (i = 0; i < 8; i++, ptr += b_stride) {
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
        t = (((p1 - p2) >= 0 ? (p1 - p2) : (-(p1 - p2))) <= ql) + 
            (((p2 - p3) >= 0 ? (p2 - p3) : (-(p2 - p3))) <= ql) + 
            (((p3 - p4) >= 0 ? (p3 - p4) : (-(p3 - p4))) <= ql) + 
            (((p4 - p5) >= 0 ? (p4 - p5) : (-(p4 - p5))) <= ql);
        if (t > 0) {
            t += (((p5 - p6) >= 0 ? (p5 - p6) : (-(p5 - p6))) <= ql) + 
                 (((p6 - p7) >= 0 ? (p6 - p7) : (-(p6 - p7))) <= ql) + 
                 (((p7 - p8) >= 0 ? (p7 - p8) : (-(p7 - p8))) <= ql) + 
                 (((p8 - p9) >= 0 ? (p8 - p9) : (-(p8 - p9))) <= ql) + 
                 (((p0 - p1) >= 0 ? (p0 - p1) : (-(p0 - p1))) <= ql);
            if (t >= 6) {
                int min, max;
                min = max = p1;
                min = (min > p3 ? p3 : min);
                max = (max > p3 ? max : p3);
                min = (min > p5 ? p5 : min);
                max = (max > p5 ? max : p5);
                min = (min > p8 ? p8 : min);
                max = (max > p8 ? max : p8);
                if (max - min < 2 * quant) {
                    min = (min > p2 ? p2 : min);
                    max = (max > p2 ? max : p2);
                    min = (min > p4 ? p4 : min);
                    max = (max > p4 ? max : p4);
                    min = (min > p6 ? p6 : min);
                    max = (max > p6 ? max : p6);
                    min = (min > p7 ? p7 : min);
                    max = (max > p7 ? max : p7);
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
            int x, x0, x1, x2;
            int m;
            x0 = (2 * p3 - 5 * p4 + 5 * p5 - 2 * p6 + 4) >> 3;
            if ((x0 >= 0 ? x0 : -x0) < quant) {
                x1 = (2 * p1 - 5 * p2 + 5 * p3 - 2 * p4 + 4) >> 3;
                x2 = (2 * p5 - 5 * p6 + 5 * p7 - 2 * p8 + 4) >> 3;
                x = (x0 >= 0 ? x0 : -x0) - ((x1 >= 0 ? x1 : -x1) > (x2 >= 0 ? x2 : -x2) ? (x2 >= 0 ? x2 : -x2) : (x1 >= 0 ? x1 : -x1));
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
