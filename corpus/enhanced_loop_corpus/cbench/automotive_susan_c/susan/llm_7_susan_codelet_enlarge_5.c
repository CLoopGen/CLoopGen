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
    // Variant 2: Introduce artificial loop-carried dependency to enforce sequential update pattern
    // Simulate a cumulative effect across iterations (e.g., chained updates), increasing data dependency
    int total_width = *x_size + 2 * border;
    uchar* img = tmp_image;
    uchar prev_left = 0, prev_right = 0;

    for (i = 0; i < border; i++) {
        for (j = 0; j < *y_size + 2 * border; j++) {
            int base = j * total_width;
            int read_idx = base + border + i;
            int write_idx = base + border - 1 - i;
            int read_idx_r = base + *x_size + border - 1 - i;
            int write_idx_r = base + *x_size + border + i;

            // Introduce RAW and loop-carried dependency using previous iteration's result
            uchar current_val_l = img[read_idx];
            uchar current_val_r = img[read_idx_r];

            // Artificially depend on previous values (cumulative XOR pattern)
            img[write_idx] = current_val_l ^ prev_left;
            img[write_idx_r] = current_val_r ^ prev_right;

            // Update prev for next iteration in i (loop-carried dependency across i)
            prev_left = img[write_idx];
            prev_right = img[write_idx_r];
        }
    }
}
