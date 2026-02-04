#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    DOT_INPUT = 1,
    DOT_OUTPUT = 2,
    DOT_INTERMEDIATE = DOT_INPUT | DOT_OUTPUT
} DNNOperandType;

typedef enum {
    DNN_FLOAT = 1,
    DNN_UINT8 = 4
} DNNDataType;

typedef struct DnnOperand {
    int32_t dims[4];
    DNNOperandType type;
    DNNDataType data_type;
    int8_t isNHWC;
    char name[128];
    void *data;
    int32_t length;
    int32_t usedNumbersLeft;
} DnnOperand;

static DnnOperand input_impl;
static DnnOperand output_impl;

DnnOperand *input = &input_impl;
DnnOperand *output = &output_impl;

void init_vars() {
    // Set dimensions: arbitrary valid sizes, total data size aimed at ~64MB for meaningful timing (~0.01s)
    const int dim0 = 512;
    const int dim1 = 512;
    const int dim2 = 256;
    const int dim3 = 1;
    const int total_size = dim0 * dim1 * dim2 * dim3 * sizeof(float); // ~64MB

    input_impl.dims[0] = dim0;
    input_impl.dims[1] = dim1;
    input_impl.dims[2] = dim2;
    input_impl.dims[3] = dim3;

    output_impl.dims[0] = 0;
    output_impl.dims[1] = 0;
    output_impl.dims[2] = 0;
    output_impl.dims[3] = 0;

    input_impl.type = DOT_INPUT;
    output_impl.type = DOT_OUTPUT;

    input_impl.data_type = DNN_FLOAT;
    output_impl.data_type = DNN_FLOAT;

    input_impl.isNHWC = 0;
    output_impl.isNHWC = 0;

    strcpy(input_impl.name, "input_tensor");
    strcpy(output_impl.name, "output_tensor");

    input_impl.length = total_size;
    output_impl.length = total_size;

    input_impl.usedNumbersLeft = 0;
    output_impl.usedNumbersLeft = 0;

    // Allocate data buffers
    input_impl.data = aligned_alloc(32, total_size);
    output_impl.data = aligned_alloc(32, total_size);

    if (!input_impl.data || !output_impl.data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize input data with some values
    float *fptr = (float *)input_impl.data;
    for (int i = 0; i < total_size / sizeof(float); ++i) {
        fptr[i] = (float)(i % 1000) / 100.0f;
    }
}