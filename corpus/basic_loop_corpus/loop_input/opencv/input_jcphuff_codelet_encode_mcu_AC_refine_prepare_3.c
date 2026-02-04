#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef short JCOEF;
typedef unsigned short UJCOEF;

JCOEF *block;
int *jpeg_natural_order_start;
int Sl;
int Al;
UJCOEF *absvalues;
int k;
int temp;
int temp2;
int EOB;
size_t zerobits;
size_t signbits;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(JCOEF))  // ~64MB of JCOEF data

static JCOEF block_data[DATA_SIZE];
static int natural_order_data[DATA_SIZE];
static UJCOEF absvalues_data[DATA_SIZE];

void init_vars() {
    // Initialize scalar variables
    Sl = DATA_SIZE > 600 ? 600 : DATA_SIZE;  // Ensure Sl is within bounds
    Al = 1;  // Arbitrary shift value, valid for testing
    EOB = 0;
    zerobits = 0;
    signbits = 0;

    // Initialize block with non-uniform signed values to trigger various conditions
    for (int i = 0; i < DATA_SIZE; i++) {
        block_data[i] = (JCOEF)((i % 251) - 125);  // Spread around zero
    }

    // Initialize jpeg_natural_order_start with valid indices
    // Ensure all indices are within [0, Sl-1] range for block access
    for (int i = 0; i < DATA_SIZE; i++) {
        natural_order_data[i] = (i * 7) % Sl;  // Pseudo-random valid index
    }

    // Zero-initialize the output array
    memset(absvalues_data, 0, sizeof(UJCOEF) * DATA_SIZE);

    // Assign pointers
    block = block_data;
    jpeg_natural_order_start = natural_order_data;
    absvalues = absvalues_data;
}