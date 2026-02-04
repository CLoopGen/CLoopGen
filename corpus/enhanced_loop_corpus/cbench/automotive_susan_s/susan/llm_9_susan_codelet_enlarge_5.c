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
    int step = (border > 5) ? 2 : 1;
    for (i = 0; i < border; i++) {
        for (j = 0; j < *y_size + 2 * border; j += step) {
            int base = j * (*x_size + 2 * border);
            tmp_image[base + border - 1 - i] = tmp_image[base + border + i];
            tmp_image[base + *x_size + border + i] = tmp_image[base + *x_size + border - 1 - i];
            if (j + 1 < *y_size + 2 * border) {
                int base_next = (j + 1) * (*x_size + 2 * border);
                tmp_image[base_next + border - 1 - i] = tmp_image[base_next + border + i];
                tmp_image[base_next + *x_size + border + i] = tmp_image[base_next + *x_size + border - 1 - i];
            }
        }
    }
}
