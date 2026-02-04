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
    // Variant 2: Eliminate data dependencies by unrolling two iterations and using local temporaries
    // Removes potential WAR/WAW hazards and breaks loop-carried dependencies
    for (i = 3; i < y_size - 3; i += 2) {
        for (j = 3; j < x_size - 3; j += 2) {
            // First virtual iteration (i, j)
            if (i < y_size - 3 && j < x_size - 3) {
                int n1 = 100;
                uchar *p1 = in + (i - 3) * x_size + j - 1;
                uchar *cp1 = bp + in[i * x_size + j];
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                p1 += x_size - 3;
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                p1 += x_size - 5;
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                p1 += x_size - 6;
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                p1 += 2;
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                p1 += x_size - 6;
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                p1 += x_size - 5;
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                p1 += x_size - 3;
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1++);
                n1 += *(cp1 - *p1);
                if (n1 <= max_no)
                    r[i * x_size + j] = max_no - n1;
            }

            // Second virtual iteration (i, j+1)
            if (i < y_size - 3 && j+1 < x_size - 3) {
                int n2 = 100;
                uchar *p2 = in + (i - 3) * x_size + (j+1) - 1;
                uchar *cp2 = bp + in[i * x_size + (j+1)];
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                p2 += x_size - 3;
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                p2 += x_size - 5;
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                p2 += x_size - 6;
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                p2 += 2;
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                p2 += x_size - 6;
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                p2 += x_size - 5;
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                p2 += x_size - 3;
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2++);
                n2 += *(cp2 - *p2);
                if (n2 <= max_no)
                    r[i * x_size + (j+1)] = max_no - n2;
            }

            // Repeat for (i+1, j) and (i+1, j+1) if within bounds
            if (i+1 < y_size - 3 && j < x_size - 3) {
                int n3 = 100;
                uchar *p3 = in + ((i+1) - 3) * x_size + j - 1;
                uchar *cp3 = bp + in[(i+1) * x_size + j];
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                p3 += x_size - 3;
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                p3 += x_size - 5;
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                p3 += x_size - 6;
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                p3 += 2;
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                p3 += x_size - 6;
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                p3 += x_size - 5;
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                p3 += x_size - 3;
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3++);
                n3 += *(cp3 - *p3);
                if (n3 <= max_no)
                    r[(i+1) * x_size + j] = max_no - n3;
            }

            if (i+1 < y_size - 3 && j+1 < x_size - 3) {
                int n4 = 100;
                uchar *p4 = in + ((i+1) - 3) * x_size + (j+1) - 1;
                uchar *cp4 = bp + in[(i+1) * x_size + (j+1)];
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                p4 += x_size - 3;
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                p4 += x_size - 5;
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                p4 += x_size - 6;
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                p4 += 2;
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                p4 += x_size - 6;
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                p4 += x_size - 5;
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                p4 += x_size - 3;
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4++);
                n4 += *(cp4 - *p4);
                if (n4 <= max_no)
                    r[(i+1) * x_size + (j+1)] = max_no - n4;
            }
        }
    }
}
