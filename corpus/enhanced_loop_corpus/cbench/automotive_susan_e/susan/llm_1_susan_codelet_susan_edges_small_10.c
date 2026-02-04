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
for (i = 1; i < y_size - 1; i++)
    for (int iy = i * x_size, iy1 = (i-1)*x_size, iy_1 = (i+1)*x_size; 
         iy < (i+1) * x_size && i < y_size - 1; 
         iy++, iy1++, iy_1++) {
        for (j = 1; j < x_size - 1; j++) {
            int idx = iy + j;
            n = 100;
            p = in + iy1 + j - 1;
            cp = bp + in[idx];
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p);
            p += x_size - 2;
            n += *(cp - *p);
            p += 2;
            n += *(cp - *p);
            p += x_size - 2;
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p);
            if (n <= max_no)
                r[idx] = max_no - n;
        }
    }
}
