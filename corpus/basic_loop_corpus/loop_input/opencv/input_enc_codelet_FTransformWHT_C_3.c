#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t tmp[16];
int i;

const int a0 = 5;
const int a1 = 3;
const int a2 = 2;
const int a3 = 7;

void init_vars() {
    // No dynamic initialization needed for const scalars; they are compile-time constants.
    // Ensure tmp array is accessible and i is initialized to zero before loop entry.
    // The loop uses fixed bounds (i from 0 to 3), so no large data allocation is required beyond tmp.
}