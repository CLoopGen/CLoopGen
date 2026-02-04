#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t bits_per_pixel;
unsigned char *pixels;
ssize_t i;

static unsigned char *internal_pixels_buffer = NULL;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    bits_per_pixel = 8;
    size_t bytes_per_pixel = bits_per_pixel >> 3;
    size_t data_size = 64 * 1024 * 1024;
    length = data_size / bytes_per_pixel;

    internal_pixels_buffer = (unsigned char *)aligned_alloc(32, data_size);
    if (!internal_pixels_buffer) {
        exit(1);
    }
    pixels = internal_pixels_buffer;

    memset(pixels, 0, data_size);

    do {
        gettimeofday(&end, NULL);
        long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        if (elapsed >= 10000) break;

        length += data_size / bytes_per_pixel;
        free(internal_pixels_buffer);
        data_size += 64 * 1024 * 1024;
        internal_pixels_buffer = (unsigned char *)aligned_alloc(32, data_size);
        if (!internal_pixels_buffer) {
            exit(1);
        }
        pixels = internal_pixels_buffer;
        memset(pixels, 0, data_size);
    } while (1);
}