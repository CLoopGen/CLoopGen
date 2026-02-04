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
    int local_r, local_in_val, offset;
    for (i = 1; i < y_size - 1; i++) {
        for (j = 1; j < x_size - 1; j++) {
            offset = i * x_size + j;
            local_in_val = in[offset];
            n = 100;
            p = in + (i - 1) * x_size + j - 1;
            cp = bp + local_in_val;
            n += *(cp - *(p++));
            n += *(cp - *(p++));
            n += *(cp - *p);
            p += x_size - 2;
            n += *(cp - *p);
            p += 2;
            n += *(cp - *p);
            p += x_size - 2;
            n += *(cp - *(p++));
            n += *(cp - *(p++));
            n += *(cp - *p);
            if (n <= max_no)
                local_r = max_no - n;
            r[offset] = local_r;
        }
    }
}
