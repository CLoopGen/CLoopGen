#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef unsigned int JDIMENSION;

JSAMPIMAGE input_buf;
JDIMENSION input_row;
JSAMPARRAY output_buf;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION count;
int num_components;
JDIMENSION num_cols;
int ci;

#define NUM_ROWS 1024
#define NUM_COLS 8192

static JSAMPLE* input_data_pool = NULL;
static JSAMPROW* input_rows = NULL;
static JSAMPARRAY* input_components = NULL;

static JSAMPLE* output_data_pool = NULL;
static JSAMPROW* output_rows = NULL;

void init_vars() {
    num_components = 3;
    num_cols = NUM_COLS;
    input_row = 0;
    ci = 0;
    count = 0;

    size_t total_input_size = (size_t)NUM_ROWS * NUM_COLS * num_components;
    input_data_pool = (JSAMPLE*)calloc(total_input_size, sizeof(JSAMPLE));
    input_rows = (JSAMPROW*)calloc(NUM_ROWS * num_components, sizeof(JSAMPROW));
    input_components = (JSAMPARRAY*)calloc(num_components, sizeof(JSAMPARRAY));

    for (int c = 0; c < num_components; c++) {
        input_components[c] = &input_rows[c * NUM_ROWS];
        for (JDIMENSION row = 0; row < NUM_ROWS; row++) {
            input_rows[c * NUM_ROWS + row] = &input_data_pool[(c * NUM_ROWS + row) * NUM_COLS];
        }
    }
    input_buf = input_components;

    size_t total_output_size = (size_t)NUM_ROWS * NUM_COLS * num_components;
    output_data_pool = (JSAMPLE*)calloc(total_output_size, sizeof(JSAMPLE));
    output_rows = (JSAMPROW*)calloc(NUM_ROWS, sizeof(JSAMPROW));
    
    for (JDIMENSION row = 0; row < NUM_ROWS; row++) {
        output_rows[row] = &output_data_pool[row * NUM_COLS * num_components];
    }
    output_buf = output_rows;
}