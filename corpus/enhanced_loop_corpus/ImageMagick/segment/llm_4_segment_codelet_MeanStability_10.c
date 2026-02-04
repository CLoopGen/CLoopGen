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
    IntervalTree *temp = child;
    sum = 0.0;
    count = 0;
    for (; temp != (IntervalTree *)((void *)0); temp = temp->sibling) {
        if (temp->stability >= 0) {
            sum += temp->stability;
            count++;
        }
    }
    child = temp;
}
