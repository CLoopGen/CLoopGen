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

extern short *extrema;
extern double value;
extern IntervalTree **list;
extern IntervalTree *node;
extern MagickBooleanType peak;
extern ssize_t i;
extern ssize_t x;
extern size_t number_crossings;
extern ssize_t _usr_index;
extern ssize_t j;
extern ssize_t k;
extern ssize_t number_nodes;
extern ZeroCrossing *zero_crossing;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (i = 0; i < number_nodes; i++) {
    k = 0;
    node = list[i];
    // Use strided access by jumping in steps of 2, then handle remainder
    for (j = 0; j <= (ssize_t)number_crossings - 1; j += 2) {
        if (zero_crossing[j].tau == node->tau) {
            k = j;
            break;
        } else if (zero_crossing[j + 1].tau == node->tau) {
            k = j + 1;
            break;
        }
    }
    // Handle possible last odd element
    if ((number_crossings % 2 == 1) && (zero_crossing[number_crossings].tau == node->tau))
        k = number_crossings;

    peak = zero_crossing[k].crossings[node->right] == -1 ? MagickTrue : MagickFalse;
    index = node->left;
    value = zero_crossing[k].histogram[index];

    // Strided forward traversal with step size 2
    ssize_t limit = node->right - (node->right - node->left + 1) % 2;
    for (x = node->left; x <= limit; x += 2) {
        double val1 = zero_crossing[k].histogram[x];
        double val2 = zero_crossing[k].histogram[x + 1];

        if (peak != MagickFalse) {
            if (val1 > value) {
                value = val1;
                index = x;
            }
            if (val2 > value) {
                value = val2;
                index = x + 1;
            }
        } else {
            if (val1 < value) {
                value = val1;
                index = x;
            }
            if (val2 < value) {
                value = val2;
                index = x + 1;
            }
        }
    }
    // Handle leftover element if range is odd
    for (x = limit + 1; x <= node->right; x++) {
        if (peak != MagickFalse) {
            if (zero_crossing[k].histogram[x] > value) {
                value = zero_crossing[k].histogram[x];
                index = x;
            }
        } else if (zero_crossing[k].histogram[x] < value) {
            value = zero_crossing[k].histogram[x];
            index = x;
        }
    }

    // Second loop: reverse memory access pattern (backward traversal)
    for (x = node->right; x >= node->left; x--) {
        if (index == 0)
            index = 256;
        if (peak != MagickFalse)
            extrema[x] = (short)index;
        else
            extrema[x] = (short)(-index);
    }
}
}
