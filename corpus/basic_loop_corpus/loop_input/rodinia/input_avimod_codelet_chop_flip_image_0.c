#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *image;
int height;
int width;
int top;
int left;
int height_new;
int width_new;
int i;
int j;
float *result;
float temp;
float scale;

void init_vars() {
    width = 1024;
    height = 1024;
    top = 0;
    left = 0;
    height_new = 512;
    width_new = 512;
    scale = 1.5f;

    image = (char *)malloc(height * width * sizeof(char));
    result = (float *)malloc(height_new * width_new * sizeof(float));

    for (int idx = 0; idx < height * width; idx++) {
        image[idx] = (char)(idx % 256);
    }

    for (int idx = 0; idx < height_new * width_new; idx++) {
        result[idx] = 0.0f;
    }
}