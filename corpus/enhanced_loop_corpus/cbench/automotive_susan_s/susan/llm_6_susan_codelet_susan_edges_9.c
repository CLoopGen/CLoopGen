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
            int temp_n = 0;

            // Introduce temporary accumulation to break direct RAW dependencies on 'n'
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);
            p += x_size - 3;
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);
            p += x_size - 5;
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);
            p += x_size - 6;
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);
            p += 2;
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);
            p += x_size - 6;
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);
            p += x_size - 5;
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);
            p += x_size - 3;
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p++);
            temp_n += *(cp - *p);

            n += temp_n; // Single update to 'n' after all reads
            if (n <= max_no)
                r[i * x_size + j] = max_no - n;
        }
}
