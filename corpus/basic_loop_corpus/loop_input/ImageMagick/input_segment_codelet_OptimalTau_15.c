#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _IntervalTree {
    double tau;
    ssize_t left;
    ssize_t right;
    double mean_stability;
    double stability;
    struct _IntervalTree *sibling;
    struct _IntervalTree *child;
} IntervalTree;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

short *extrema;
double value;
IntervalTree **list;
IntervalTree *node;
MagickBooleanType peak;
ssize_t i;
ssize_t x;
size_t number_crossings;
ssize_t _usr_index;
ssize_t j;
ssize_t k;
ssize_t number_nodes;
ZeroCrossing *zero_crossing;

#define index _usr_index

void init_vars() {
    number_nodes = 4000;
    number_crossings = 255;

    extrema = (short*)calloc(256, sizeof(short));
    zero_crossing = (ZeroCrossing*)calloc(number_crossings + 1, sizeof(ZeroCrossing));
    list = (IntervalTree**)malloc(number_nodes * sizeof(IntervalTree*));

    for (j = 0; j <= (ssize_t)number_crossings; j++) {
        zero_crossing[j].tau = (double)(j + 1) * 0.5;
        for (int h = 0; h < 256; h++) {
            zero_crossing[j].histogram[h] = (h % 2 == 0) ? (100.0 + h) : (100.0 - h);
            zero_crossing[j].crossings[h] = (h % 3 == 0) ? -1 : 1;
        }
    }

    for (i = 0; i < number_nodes; i++) {
        node = (IntervalTree*)malloc(sizeof(IntervalTree));
        node->tau = zero_crossing[i % (number_crossings + 1)].tau;
        node->left = rand() % 128;
        node->right = node->left + (rand() % (256 - node->left));
        node->sibling = NULL;
        node->child = NULL;
        list[i] = node;
    }

    value = 0.0;
    peak = MagickFalse;
    _usr_index = 0;
}