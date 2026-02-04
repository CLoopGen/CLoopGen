#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *tmp_image;
extern int *x_size;
extern int *y_size;
extern int border;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x_border = *x_size + 2 * border;
    for (i = 0; i < border; i++) {
        int offset1 = border - 1 - i;
        int offset2 = border + i;
        int offset3 = *x_size + border + i;
        int offset4 = *x_size + border - 1 - i;
        for (j = 0; j < *y_size + 2 * border; j++) {
            int base = j * x_border;
            tmp_image[base + offset1] = tmp_image[base + offset2];
            tmp_image[base + offset3] = tmp_image[base + offset4];
        }
    }
}
