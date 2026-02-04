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
int depth = 2;
int block_size = (x_size * y_size + depth - 1) / depth;
for (int d = 0; d < depth; d++) {
    int start = d * block_size;
    int end = start + block_size;
    if (start >= x_size * y_size) break;
    if (end > x_size * y_size) end = x_size * y_size;
    for (i = start; i < end; i++) {
        if (*midp < 8)
            *(in + (midp - mid)) = 0;
        midp++;
    }
}
}
