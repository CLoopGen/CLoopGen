#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

typedef struct _DDSVector4 {
    float x;
    float y;
    float z;
    float w;
} DDSVector4;

typedef struct _DDSVector3 {
    float x;
    float y;
    float z;
} DDSVector3;

size_t count;
DDSVector4 *points;
float *covariance;
DDSVector3 centroid;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds runtime on modern CPU
    // Estimate: ~10-20 cycles per iteration -> target ~26 million elements for 0.01s at 3GHz
    // Use 26 million as baseline
    count = 26214400;  // ~26M

    // Allocate points array
    points = (DDSVector4*)aligned_alloc(32, count * sizeof(DDSVector4));
    if (!points) exit(1);

    // Allocate covariance matrix (6 elements, upper triangular)
    covariance = (float*)aligned_alloc(32, 6 * sizeof(float));
    if (!covariance) exit(1);

    // Initialize covariance to zero
    for (int j = 0; j < 6; j++) {
        covariance[j] = 0.0f;
    }

    // Initialize centroid
    centroid.x = 1.23f;
    centroid.y = 4.56f;
    centroid.z = 7.89f;

    // Seed random number generator and initialize points
    srand(12345);
    for (size_t idx = 0; idx < count; idx++) {
        points[idx].x = (float)((double)rand() / RAND_MAX * 10.0 - 5.0);
        points[idx].y = (float)((double)rand() / RAND_MAX * 10.0 - 5.0);
        points[idx].z = (float)((double)rand() / RAND_MAX * 10.0 - 5.0);
        points[idx].w = (float)((double)rand() / RAND_MAX * 2.0 + 0.1); // avoid zero weights
    }

    // Initialize loop index
    i = 0;
}