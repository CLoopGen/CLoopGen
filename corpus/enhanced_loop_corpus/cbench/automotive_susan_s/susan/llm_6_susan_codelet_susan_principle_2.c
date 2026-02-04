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
    int i, j, n;
    uchar *p, *cp;
    int temp_n[7]; // Introduce local accumulation to break loop-carried dependency on 'n'

    for (i = 3; i < y_size - 3; i++) {
        for (j = 3; j < x_size - 3; j++) {
            // Initialize temporary accumulators to eliminate WAW and WAR hazards
            for (int k = 0; k < 7; k++) temp_n[k] = 100;

            p = in + (i - 3) * x_size + j - 1;
            cp = bp + in[i * x_size + j];

            // Distribute additions across multiple accumulators to break RAW chains
            temp_n[0] += *(cp - *p++);
            temp_n[1] += *(cp - *p++);
            temp_n[2] += *(cp - *p);
            p += x_size - 3;

            temp_n[0] += *(cp - *p++);
            temp_n[1] += *(cp - *p++);
            temp_n[2] += *(cp - *p++);
            temp_n[3] += *(cp - *p++);
            temp_n[4] += *(cp - *p);
            p += x_size - 5;

            temp_n[0] += *(cp - *p++);
            temp_n[1] += *(cp - *p++);
            temp_n[2] += *(cp - *p++);
            temp_n[3] += *(cp - *p++);
            temp_n[4] += *(cp - *p++);
            temp_n[5] += *(cp - *p++);
            temp_n[6] += *(cp - *p);
            p += x_size - 6;

            temp_n[0] += *(cp - *p++);
            temp_n[1] += *(cp - *p++);
            temp_n[2] += *(cp - *p);
            p += 2;

            temp_n[3] += *(cp - *p++);
            temp_n[4] += *(cp - *p++);
            temp_n[5] += *(cp - *p);
            p += x_size - 6;

            temp_n[0] += *(cp - *p++);
            temp_n[1] += *(cp - *p++);
            temp_n[2] += *(cp - *p++);
            temp_n[3] += *(cp - *p++);
            temp_n[4] += *(cp - *p++);
            temp_n[5] += *(cp - *p++);
            temp_n[6] += *(cp - *p);
            p += x_size - 5;

            temp_n[0] += *(cp - *p++);
            temp_n[1] += *(cp - *p++);
            temp_n[2] += *(cp - *p++);
            temp_n[3] += *(cp - *p++);
            temp_n[4] += *(cp - *p);
            p += x_size - 3;

            temp_n[0] += *(cp - *p++);
            temp_n[1] += *(cp - *p++);
            temp_n[2] += *(cp - *p);

            // Final reduction of accumulators
            n = temp_n[0] + temp_n[1] + temp_n[2] + temp_n[3] +
                temp_n[4] + temp_n[5] + temp_n[6] - 600 + 100;

            if (n <= max_no)
                r[i * x_size + j] = max_no - n;
        }
    }
}
