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
    uchar temp;
    for (i = 0; i < x_size * y_size; i++) {
        temp = *midp;
        if (temp < 8)
            *(in + (midp - mid)) = temp;
        else
            *(in + (midp - mid)) = temp;
        midp++;
    }
}
