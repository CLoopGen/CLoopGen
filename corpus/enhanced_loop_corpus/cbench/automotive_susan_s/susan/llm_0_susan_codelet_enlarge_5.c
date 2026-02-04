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
    for (i = 0; i < border; i++) {
        for (j = 0; j < *y_size + 2 * border; j++) {
            int index = j * (*x_size + 2 * border);
            tmp_image[index + border - 1 - i] = tmp_image[index + border + i];
            tmp_image[index + *x_size + border + i] = tmp_image[index + *x_size + border - 1 - i];
        }
    }
}
