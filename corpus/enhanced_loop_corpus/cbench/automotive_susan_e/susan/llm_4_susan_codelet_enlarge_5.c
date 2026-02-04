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
for (i = 0; i < border; i++)
    for (j = 0; j < *y_size + 2 * border; j++) {
        if (i % 2 == 0) {
            tmp_image[j * (*x_size + 2 * border) + border - 1 - i] = tmp_image[j * (*x_size + 2 * border) + border + i];
        }
        if (i % 2 == 1) {
            tmp_image[j * (*x_size + 2 * border) + *x_size + border + i] = tmp_image[j * (*x_size + 2 * border) + *x_size + border - 1 - i];
        }
    }
}
