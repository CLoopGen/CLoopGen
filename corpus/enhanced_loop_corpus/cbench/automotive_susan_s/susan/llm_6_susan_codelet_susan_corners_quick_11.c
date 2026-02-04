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
    for (i = 7; i < y_size - 7; i++) {
        int temp_r;
        for (j = 7; j < x_size - 7; j++) {
            n = 100;
            p = in + (i - 3) * x_size + j - 1;
            cp = bp + in[i * x_size + j];
            // Introduce local accumulation to break WAW dependencies on r[]
            temp_r = 0;

            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p);
            p += x_size - 3;
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p);
            p += x_size - 5;
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p);
            p += x_size - 6;
            n += *(cp - *p++);
            n += *(cp - *p++);
            n += *(cp - *p);
            if (n >= max_no) continue;

            p += 2;
            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p);
            if (n >= max_no) continue;

            p += x_size - 6;
            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p);
            if (n >= max_no) continue;

            p += x_size - 5;
            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p);
            if (n >= max_no) continue;

            p += x_size - 3;
            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p++);
            if (n >= max_no) continue;

            n += *(cp - *p);
            if (n < max_no)
                temp_r = max_no - n;

            // Eliminate loop-carried dependency by writing only once
            r[i * x_size + j] = temp_r;
        }
    }
}
