#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    DNN_FLOAT = 1,
    DNN_UINT8 = 4
} DNNDataType;

typedef struct DNNData {
    void *data;
    DNNDataType dt;
    int width;
    int height;
    int channels;
} DNNData;

typedef enum {
    DLT_INPUT = 0,
    DLT_CONV2D = 1,
    DLT_DEPTH_TO_SPACE = 2,
    DLT_MIRROR_PAD = 3,
    DLT_MAXIMUM = 4,
    DLT_MATH_BINARY = 5,
    DLT_MATH_UNARY = 6,
    DLT_COUNT
} DNNLayerType;

typedef struct Layer {
    DNNLayerType type;
    int32_t input_operand_indexes[4];
    int32_t output_operand_index;
    void *params;
} Layer;

typedef enum {
    DOT_INPUT = 1,
    DOT_OUTPUT = 2,
    DOT_INTERMEDIATE = DOT_INPUT | DOT_OUTPUT
} DNNOperandType;

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

typedef struct ConvolutionalNetwork {
    Layer *layers;
    int32_t layers_num;
    DnnOperand *operands;
    int32_t operands_num;
    int32_t *output_indexes;
    uint32_t nb_output;
} ConvolutionalNetwork;

extern DNNData *outputs;
extern ConvolutionalNetwork *network;
extern uint32_t nb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t *indices = network->output_indexes;
    DnnOperand *ops = network->operands;
    for (uint32_t i = 0; i < nb; ++i) {
        uint32_t idx = indices[i];
        DnnOperand *oprd = &ops[idx];
        outputs[i].data = oprd->data;
        outputs[i].height = oprd->dims[1];
        outputs[i].width = oprd->dims[2];
        outputs[i].channels = oprd->dims[3];
        outputs[i].dt = oprd->data_type;
    }
}
