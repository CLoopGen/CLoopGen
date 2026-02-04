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
    int total = x_size * y_size;
    for (i = 0; i < total; i += 2) {
        for (j = 0; j < (total - i > 1 ? 2 : 1); j++) {
            if (*(midp + j) < 8)
                *(in + (midp + j - mid)) = 0;
        }
        midp += 2;
    }
}
