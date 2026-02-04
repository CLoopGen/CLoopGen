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
    int temp_val1, temp_val2;
    // Eliminate loop-carried dependencies by pre-loading values and reordering operations
    for (i = 0; i < border; i++) {
        for (j = 0; j < *y_size + 2 * border; j++) {
            // Pre-load source values before any stores to break potential RAW hazards
            temp_val1 = tmp_image[j * (*x_size + 2 * border) + border + i];
            temp_val2 = tmp_image[j * (*x_size + 2 * border) + *x_size + border - 1 - i];
            // Now perform all writes using local temporaries
            tmp_image[j * (*x_size + 2 * border) + border - 1 - i] = temp_val1;
            tmp_image[j * (*x_size + 2 * border) + *x_size + border + i] = temp_val2;
        }
    }
}
