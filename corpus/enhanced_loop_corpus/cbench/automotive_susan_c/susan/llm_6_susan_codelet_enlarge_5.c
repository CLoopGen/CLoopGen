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



void loop() {
    // Variant 1: Eliminate WAW and WAR dependencies by unrolling and reordering independent operations
    // This introduces more parallelism by separating reads before writes and reducing loop-carried dependencies.
    int x_plus_border = *x_size + 2 * border;
    int total_width = x_plus_border;
    uchar* img = tmp_image;

    for (i = 0; i < border; i++) {
        int forward_offset_1 = border + i;
        int backward_offset_1 = border - 1 - i;
        int forward_offset_2 = *x_size + border + i;
        int backward_offset_2 = *x_size + border - 1 - i;

        for (j = 0; j < *y_size + 2 * border; j++) {
            int base = j * total_width;
            // Read all required values first to break write-after-read (WAR) dependencies
            uchar val1 = img[base + forward_offset_1];
            uchar val2 = img[base + backward_offset_2];

            // Perform assignments after all reads (eliminates WAR/WAW hazards)
            img[base + backward_offset_1] = val1;
            img[base + forward_offset_2] = val2;
        }
    }
}
