#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct colorbox {
    struct colorbox *next;
    struct colorbox *prev;
    int rmin;
    int rmax;
    int gmin;
    int gmax;
    int bmin;
    int bmax;
    int total;
} Colorbox;

int histogram[32][32][32];
Colorbox *ptr;
int *iptr;
int *histp;

int ir;
int ig;
int ib;

void init_vars() {
    ptr = (Colorbox*)malloc(sizeof(Colorbox));
    ptr->rmin = 0;
    ptr->rmax = 31;
    ptr->gmin = 0;
    ptr->gmax = 31;
    ptr->bmin = 0;
    ptr->bmax = 31;
    ptr->total = 0;
    ptr->next = NULL;
    ptr->prev = NULL;

    memset(histogram, 0, sizeof(histogram));

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 32; k++) {
                histogram[i][j][k] = rand() % 256;
            }
        }
    }

    histp = (int*)malloc(32 * 32 * sizeof(int));
    if (!histp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    iptr = NULL;
}