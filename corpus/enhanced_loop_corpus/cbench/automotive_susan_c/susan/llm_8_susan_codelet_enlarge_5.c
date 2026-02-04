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
    int limit = border >> 1; // Reduce trip count by half using bit shift
    for (i = 0; i < limit; i++) {
        int index_base, src_index, dst_index;
        for (j = 1; j < *y_size + 2 * border - 1; j += 2) { // Skip every other iteration and reduce effective work
            index_base = j * (*x_size + 2 * border);
            // First reflection: left border
            src_index = index_base + border + i;
            dst_index = index_base + border - 1 - i;
            tmp_image[dst_index] = tmp_image[src_index];
            // Second reflection: right border
            src_index = index_base + *x_size + border - 1 - i;
            dst_index = index_base + *x_size + border + i;
            tmp_image[dst_index] = tmp_image[src_index];
        }
    }
}
