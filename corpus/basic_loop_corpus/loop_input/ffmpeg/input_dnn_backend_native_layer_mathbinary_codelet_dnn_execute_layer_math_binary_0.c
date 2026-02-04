#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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

DnnOperand *input;
DnnOperand *output;

void init_vars() {
    input = (DnnOperand*)malloc(sizeof(DnnOperand));
    output = (DnnOperand*)malloc(sizeof(DnnOperand));

    if (!input || !output) {
        exit(1);
    }

    input->dims[0] = 64;
    input->dims[1] = 64;
    input->dims[2] = 64;
    input->dims[3] = 4;
    input->type = DOT_INPUT;
    input->data_type = DNN_FLOAT;
    input->isNHWC = 0;
    strcpy(input->name, "input_tensor");
    input->length = 64 * 64 * 64 * 4 * sizeof(float);
    input->data = malloc(input->length);
    input->usedNumbersLeft = 0;

    output->dims[0] = 0;
    output->dims[1] = 0;
    output->dims[2] = 0;
    output->dims[3] = 0;
    output->type = DOT_OUTPUT;
    output->data_type = DNN_FLOAT;
    output->isNHWC = 0;
    strcpy(output->name, "output_tensor");
    output->length = input->length;
    output->data = malloc(output->length);
    output->usedNumbersLeft = 0;

    if (!input->data || !output->data) {
        exit(1);
    }
}