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
for (i = 3; i < y_size - 3; i++)
    for (j = 3; j < x_size - 3; j++) {
        n = 100;
        p = in + (i - 3) * x_size + j - 1;
        int center_val = in[i * x_size + j];
        cp = bp + center_val;

        // Eliminate all conditionals that affect data flow except the final one
        // Flatten logic with direct arithmetic and remove potential branches

        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);
        p += x_size - 3;
        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);
        p += x_size - 5;
        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);
        p += x_size - 6;
        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);
        p += 2;
        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);
        p += x_size - 6;
        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);
        p += x_size - 5;
        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);
        p += x_size - 3;
        n += *(cp - *p++); n += *(cp - *p++); n += *(cp - *p);

        // Only conditional remains as it determines write to output
        if (n <= max_no)
            r[i * x_size + j] = max_no - n;
    }
}
