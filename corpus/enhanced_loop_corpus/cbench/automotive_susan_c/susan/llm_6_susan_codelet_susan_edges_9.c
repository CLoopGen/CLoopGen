#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern int *r;
extern uchar *bp;
extern int max_no;
extern int x_size;
extern int y_size;
extern int i;
extern int j;
extern int n;
extern uchar *p;
extern uchar *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i < y_size - 3; i++) {
        int local_sum[y_size * x_size]; // Introduce private storage to break WAW/RAW across iterations
        for (j = 3; j < x_size - 3; j++) {
            n = 100;
            p = in + (i - 3) * x_size + j - 1;
            cp = bp + in[i * x_size + j];
            uchar val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            p += x_size - 3;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            p += x_size - 5;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            p += x_size - 6;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            p += 2;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            p += x_size - 6;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            p += x_size - 5;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            p += x_size - 3;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            n += *(cp - *p);
            local_sum[j] = (n <= max_no) ? (max_no - n) : 0;
        }
        // Resolve data dependency by writing only after full row computation
        for (j = 3; j < x_size - 3; j++) {
            if (local_sum[j] != 0 || (100 < max_no && local_sum[j] == max_no - 100)) {
                r[i * x_size + j] = local_sum[j];
            }
        }
    }
}
