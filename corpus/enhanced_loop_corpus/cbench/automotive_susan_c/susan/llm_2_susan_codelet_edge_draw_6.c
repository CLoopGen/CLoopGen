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
    int idx;
    for (i = 0; i < x_size * y_size; i += 4) {
        idx = midp - mid;
        if (*(midp) < 8)
            *(in + idx) = 0;
        if (*(midp + 1) < 8 && i + 1 < x_size * y_size)
            *(in + idx + 1) = 0;
        if (*(midp + 2) < 8 && i + 2 < x_size * y_size)
            *(in + idx + 2) = 0;
        if (*(midp + 3) < 8 && i + 3 < x_size * y_size)
            *(in + idx + 3) = 0;
        midp += 4;
    }
}
