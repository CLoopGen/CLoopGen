#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

DnnOperand *oprd;
int32_t result;

void init_vars() {
    // Allocate data buffer of ~64MB to ensure loop runtime around 0.01s
    const size_t data_size = 64 * 1024 * 1024;
    int8_t *data_buffer = (int8_t *)calloc(data_size, sizeof(int8_t));
    if (!data_buffer) exit(1);

    // Initialize dims so that product over 4 iterations stays within reasonable range
    oprd = (DnnOperand *)malloc(sizeof(DnnOperand));
    if (!oprd) exit(1);

    oprd->dims[0] = 100;
    oprd->dims[1] = 100;
    oprd->dims[2] = 10;
    oprd->dims[3] = 10;

    oprd->type = DOT_INTERMEDIATE;
    oprd->data_type = DNN_UINT8;
    oprd->isNHWC = 1;
    for (int i = 0; i < 127; ++i) oprd->name[i] = 'A' + (i % 26);
    oprd->name[127] = '\0';
    oprd->data = data_buffer;
    oprd->length = data_size;
    oprd->usedNumbersLeft = 0;

    result = 1;
}