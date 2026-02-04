#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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

static DnnOperand input_local;
static DnnOperand output_local;

DnnOperand *input = &input_local;
DnnOperand *output = &output_local;

void init_vars() {
    // Set dimensions: use a large enough size to make loop measurable (~0.01s)
    // We'll set the tensor size to about 64MB of float data to ensure sufficient workload
    const int dim0 = 1024;
    const int dim1 = 1024;
    const int dim2 = 1024;
    const int dim3 = 16;  // total ~64M floats = 256MB

    input->dims[0] = dim0;
    input->dims[1] = dim1;
    input->dims[2] = dim2;
    input->dims[3] = dim3;

    input->type = DOT_INPUT;
    input->data_type = DNN_FLOAT;
    input->isNHWC = 0;
    strcpy(input->name, "input_tensor");
    input->length = dim0 * dim1 * dim2 * dim3;
    input->usedNumbersLeft = input->length;
    input->data = aligned_alloc(32, input->length * sizeof(float));
    
    if (!input->data) {
        fprintf(stderr, "Failed to allocate input data\n");
        exit(1);
    }

    // Initialize output operand
    output->dims[0] = 0;
    output->dims[1] = 0;
    output->dims[2] = 0;
    output->dims[3] = 0;

    output->type = DOT_OUTPUT;
    output->data_type = DNN_FLOAT;
    output->isNHWC = 0;
    strcpy(output->name, "output_tensor");
    output->length = input->length;
    output->usedNumbersLeft = output->length;
    output->data = aligned_alloc(32, output->length * sizeof(float));
    
    if (!output->data) {
        fprintf(stderr, "Failed to allocate output data\n");
        exit(1);
    }

    // Pre-initialize input data with some values to avoid undefined behavior
    float *fdata = (float *)input->data;
    for (int i = 0; i < input->length; ++i) {
        fdata[i] = (float)(i % 1000) / 100.0f;
    }

    // Zero output data
    memset(output->data, 0, output->length * sizeof(float));
}