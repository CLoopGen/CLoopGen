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

extern IntervalTree *child;
extern ssize_t count;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IntervalTree *curr = child;
    sum = 0.0;
    count = 0;
    for (; curr != (IntervalTree *)((void *)0) && curr->sibling != (IntervalTree *)((void *)0); 
         curr = (curr->sibling != (IntervalTree *)((void *)0)) ? curr->sibling->sibling : (IntervalTree *)((void *)0)) {
        sum += curr->stability;
        count++;
        if (curr->mean_stability < curr->tau) {
            continue;
        }
        if (curr->child != (IntervalTree *)((void *)0)) {
            sum += curr->child->stability;
            count++;
        }
    }
    if (curr != (IntervalTree *)((void *)0)) {
        sum += curr->stability;
        count++;
    }
}
