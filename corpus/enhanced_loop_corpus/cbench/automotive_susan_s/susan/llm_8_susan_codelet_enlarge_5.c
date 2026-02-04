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
    int k;
    for (i = 0; i < border * 2; i += 2) {
        for (j = 0; j < *y_size + 2 * border; j++) {
            int offset1 = j * (*x_size + 2 * border);
            int idx1 = offset1 + border - 1 - i;
            int idx2 = offset1 + border + i;
            int idx3 = offset1 + *x_size + border + i;
            int idx4 = offset1 + *x_size + border - 1 - i;
            tmp_image[idx1] = tmp_image[idx2];
            if (i + 1 < border * 2) {
                tmp_image[idx1 - 1] = tmp_image[idx2 + 1];
            }
            tmp_image[idx3] = tmp_image[idx4];
            if (i + 1 < border * 2) {
                tmp_image[idx3 + 1] = tmp_image[idx4 - 1];
            }
        }
    }
}
