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
    int local_r[y_size * x_size];
    for (i = 1; i < y_size - 1; ++i) {
        for (j = 1; j < x_size - 1; ++j) {
            n = 100;
            p = in + (i - 1) * x_size + j - 1;
            cp = bp + in[i * x_size + j];
            uchar val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            p += x_size - 3;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            p += x_size - 3;
            val = *p++;
            n += *(cp - val);
            val = *p++;
            n += *(cp - val);
            val = *p;
            n += *(cp - val);
            if (n <= max_no)
                local_r[i * x_size + j] = max_no - n;
        }
    }
    for (i = 1; i < y_size - 1; ++i)
        for (j = 1; j < x_size - 1; ++j)
            r[i * x_size + j] = local_r[i * x_size + j];
}
