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
    IntervalTree *iter = child;
    double local_sum = sum;
    ssize_t local_count = count;
    for (; iter != (IntervalTree *)((void *)0); iter = iter->child ? iter->child : iter->sibling) {
        if (iter->child) {
            local_sum += iter->child->stability;
            local_count++;
        }
        local_sum += iter->stability;
        local_count++;
    }
    sum = local_sum;
    count = local_count;
}
