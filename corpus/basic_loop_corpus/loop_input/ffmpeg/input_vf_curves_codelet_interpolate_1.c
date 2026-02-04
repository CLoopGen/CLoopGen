#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct keypoint {
    double x;
    double y;
    struct keypoint *next;
};

struct keypoint *points = NULL;
int i = -1;
struct keypoint *point = NULL;
double xprev = 0.0;
double *h = NULL;

void init_vars() {
    const size_t num_points = 20000000; // ~160MB for keypoint list, adjust for ~0.01s runtime
    h = (double *)aligned_alloc(32, num_points * sizeof(double));
    if (!h) exit(1);

    points = (struct keypoint *)aligned_alloc(32, sizeof(struct keypoint));
    if (!points) exit(1);
    points->x = 1.0;
    points->y = 0.0;
    points->next = NULL;

    struct keypoint *current = points;
    for (size_t j = 1; j < num_points; j++) {
        struct keypoint *next_point = (struct keypoint *)aligned_alloc(32, sizeof(struct keypoint));
        if (!next_point) exit(1);
        next_point->x = (double)(j + 1);
        next_point->y = 0.0;
        next_point->next = NULL;
        current->next = next_point;
        current = next_point;
    }

    i = 0;
    xprev = 0.0;
}