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
int i, j;
int total_size = x_size * y_size;
for (i = 0; i < x_size; i++) {
    for (j = 0; j < y_size; j++) {
        int idx = i * y_size + j;
        if (*(mid + idx) < 8)
            *(in + idx) = 0;
    }
}
}
