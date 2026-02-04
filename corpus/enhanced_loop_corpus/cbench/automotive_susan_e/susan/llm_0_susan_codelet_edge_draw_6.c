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
    int outer, inner;
    for (outer = 0; outer < x_size; outer++) {
        for (inner = 0; inner < y_size; inner++) {
            int idx = outer * y_size + inner;
            if (*(mid + idx) < 8)
                *(in + idx) = 0;
        }
    }
}
