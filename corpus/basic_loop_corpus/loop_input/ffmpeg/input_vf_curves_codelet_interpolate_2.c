#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct keypoint {
    double x;
    double y;
    struct keypoint *next;
};

int i;
struct keypoint *point;
double *h;
double *r;
int n;

void init_vars() {
    n = 10000000; // Adjust to achieve ~0.01 sec runtime

    // Allocate arrays
    h = (double*)calloc(n, sizeof(double));
    r = (double*)calloc(n, sizeof(double));

    // Initialize h values to avoid division by zero
    for (int j = 0; j < n; j++) {
        h[j] = 1.0 + (j % 997) * 0.001;
    }

    // Build linked list of keypoints
    struct keypoint *head = (struct keypoint*)malloc(n * sizeof(struct keypoint));
    for (int j = 0; j < n; j++) {
        head[j].x = j * 0.1;
        head[j].y = j * j * 0.01;
        if (j < n - 1)
            head[j].next = &head[j + 1];
        else
            head[j].next = NULL;
    }

    point = &head[0]; // Start from first keypoint
}