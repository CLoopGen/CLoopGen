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

extern  DnnOperand *oprd;
extern int32_t result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t local_dims[4];
    for (int i = 0; i < 4; ++i) {
        local_dims[i] = oprd->dims[i];
    }
    for (int i = 0; i < 4; ++i) {
        result *= local_dims[i];
    }
}
