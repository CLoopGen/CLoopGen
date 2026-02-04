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
int i;
int total_size = x_size * y_size;
for (i = 0; i < total_size; i += 2) {
    // Process two elements per iteration
    if (*(midp) < 8)
        *(in + (midp - mid)) = 0;
    midp++;
    if (i + 1 < total_size) {
        if (*midp < 8)
            *(in + (midp - mid)) = 0;
        midp++;
    }
}
}
