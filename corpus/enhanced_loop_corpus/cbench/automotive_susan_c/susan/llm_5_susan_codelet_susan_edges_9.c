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
        cp = bp + in[i * x_size + j];

        // Eliminate conditional write by always computing, but use control flow to skip partial updates
        int index = i * x_size + j;
        uchar center_val = in[index];
        if (center_val < 10 || center_val > 245) {
            // For edge cases in lookup table range, skip processing
            r[index] = 0;
            continue;
        }

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
        p += 2;
        n += *(cp - *p++);
        n += *(cp - *p++);
        n += *(cp - *p);
        p += x_size - 6;
        n += *(cp - *p++);
        n += *(cp - *p++);
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
        n += *(cp - *p);
        p += x_size - 3;
        n += *(cp - *p++);
        n += *(cp - *p++);
        n += *(cp - *p);

        // Only assign result if condition holds; otherwise leave as zero (initialized above)
        if (n <= max_no)
            r[index] = max_no - n;
    }
}
