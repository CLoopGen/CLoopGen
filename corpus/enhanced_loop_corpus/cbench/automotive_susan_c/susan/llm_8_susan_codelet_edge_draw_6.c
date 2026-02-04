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
int total = x_size * y_size;
for (i = 0; i < total; i += 2) {
    if (*(midp) < 8)
        *(in + (midp - mid)) = 0;
    midp++;
    if (i + 1 < total) {
        if (*midp < 8)
            *(in + (midp - mid)) = 0;
        midp++;
    }
}
}
