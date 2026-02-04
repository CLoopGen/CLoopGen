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
    int idx1, idx2;
    for (i = 0; i < border; i++) {
        for (j = 0; j < *y_size + 2 * border; j++) {
            idx1 = j * (*x_size + 2 * border) + border - 1 - i;
            idx2 = j * (*x_size + 2 * border) + border + i;
            // Introduce WAW dependency by writing to same location in different iterations
            tmp_image[idx1] = tmp_image[idx2];
            tmp_image[idx1] = tmp_image[idx2] ^ 0xFF; // Additional write creates WAW
            idx1 = j * (*x_size + 2 * border) + *x_size + border + i;
            idx2 = j * (*x_size + 2 * border) + *x_size + border - 1 - i;
            tmp_image[idx1] = tmp_image[idx2];
            tmp_image[idx1] = tmp_image[idx2] ^ 0xFF; // WAW dependency introduced
        }
    }
}
