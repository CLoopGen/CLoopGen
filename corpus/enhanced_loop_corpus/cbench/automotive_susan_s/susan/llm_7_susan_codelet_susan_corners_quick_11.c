#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern int *r;
extern uchar *bp;
extern int max_no;
extern int x_size;
extern int y_size;
extern int n;
extern int i;
extern int j;
extern uchar *p;
extern uchar *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i < y_size - 7; i += 2) {
        for (j = 7; j < x_size - 7; j++) {
            n = 100;
            p = in + (i - 3) * x_size + j - 1;
            cp = bp + in[i * x_size + j];

            // Reorder memory accesses to introduce artificial RAW dependencies
            // and prevent aggressive reordering by compiler
            int val1, val2, val3;

            // First row: use temporary variables to create explicit data flow
            val1 = *(cp - *p++);
            val1 += *(cp - *p++);
            val1 += *(cp - *p); p += x_size - 2; // adjust pointer early to create WAR hazard

            // Second row
            val2 = *(cp - *(p + 1));
            val2 += *(cp - *(p + 2));
            val2 += *(cp - *(p + 3));
            val2 += *(cp - *(p + 4));
            val2 += *(cp - *(p + 5)); p += x_size - 1;

            // Third row — depends on val1 via conditional update (introduce control dependence)
            val3 = 0;
            if (val1 > 50) {
                val3 += *(cp - *p++);
                val3 += *(cp - *p++);
                val3 += *(cp - *p++);
                val3 += *(cp - *p++);
                val3 += *(cp - *p++);
                val3 += *(cp - *p++);
                val3 += *(cp - *p); p += x_size - 5;
            } else {
                p += 2 * x_size - 6; // skip ahead, simulate divergent flow
            }

            // Accumulate into n only after all partials
            n += val1 + val2 + val3;

            // Remaining checks with flattened structure but added artificial dependencies
            if (n >= max_no) goto write_default;

            p += 2;
            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p);
            if (n >= max_no) goto write_default;

            p += x_size - 6;
            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p);
            if (n >= max_no) goto write_default;

            p += x_size - 5;
            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p);
            if (n >= max_no) goto write_default;

            p += x_size - 3;
            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p++);
            if (n >= max_no) goto write_default;

            n += *(cp - *p);
            if (n < max_no) {
                r[i * x_size + j] = max_no - n;
                continue;
            }

write_default:
            r[i * x_size + j] = 0; // Introduce WAW dependency across iterations via uniform write
        }
    }
}
