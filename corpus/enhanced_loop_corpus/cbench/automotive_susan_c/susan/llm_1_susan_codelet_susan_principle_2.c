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
    n = 100;
    p = in + (i - 3) * x_size + 3 - 1;
    cp = bp + in[i * x_size + 3];
    for (j = 3; j < x_size - 3; j++) {
        int local_n = 100;
        uchar* local_p = p + (j - 3);
        uchar* local_cp = bp + in[i * x_size + j];
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        local_p += x_size - 3;
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        local_p += x_size - 5;
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        local_p += x_size - 6;
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        local_p += 2;
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        local_p += x_size - 6;
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        local_p += x_size - 5;
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        local_p += x_size - 3;
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p++);
        local_n += *(local_cp - *local_p);
        if (local_n <= max_no)
            r[i * x_size + j] = max_no - local_n;
    }
}
}
