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

extern double average_tau;
extern IntervalTree **list;
extern ssize_t i;
extern ssize_t number_nodes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (ssize_t j = 0; j < number_nodes; j++)
        temp_sum += list[j]->tau;
    average_tau += temp_sum;
}
