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
    int new_border = border / 2;
    int y_limit = *y_size + 2 * border;
    int x_total = *x_size + 2 * border;
    for (i = 0; i < new_border; i += 2) {
        for (j = 0; j < y_limit; j += 2) {
            int idx1 = j * x_total + border - 1 - i;
            int idx2 = j * x_total + border + i;
            int idx3 = j * x_total + *x_size + border + i;
            int idx4 = j * x_total + *x_size + border - 1 - i;
            tmp_image[idx1] = tmp_image[idx2];
            tmp_image[idx3] = tmp_image[idx4];

            if (i + 1 < new_border && j + 1 < y_limit) {
                int idx1b = (j+1) * x_total + border - 1 - (i+1);
                int idx2b = (j+1) * x_total + border + (i+1);
                int idx3b = (j+1) * x_total + *x_size + border + (i+1);
                int idx4b = (j+1) * x_total + *x_size + border - 1 - (i+1);
                tmp_image[idx1b] = tmp_image[idx2b];
                tmp_image[idx3b] = tmp_image[idx4b];
            }
        }
    }
}
