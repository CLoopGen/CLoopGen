#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double count[100];
unsigned int i;

void init_vars() {
    // No additional initialization required beyond zero-initialization of count
    // The array size is fixed at 100, so no dynamic sizing needed
    // Loop bounds are already safe: i from 0 to 99
}