#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_outer, i_inner;
for (i_outer = 0; i_outer < y_size; i_outer++) {
    for (i_inner = 0; i_inner < x_size; i_inner++) {
        i = i_outer * x_size + i_inner;
        if (*(mid + i) < 8)
            *(in + i) = 0;
    }
}
}
