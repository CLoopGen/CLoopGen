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
    uchar *local_midp = midp;
    for (i = 0; i < x_size * y_size; i++) {
        if (*local_midp < 8)
            *(in + (local_midp - mid)) = 0;
        local_midp++;
    }
    midp = local_midp;
}
