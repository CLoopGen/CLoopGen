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

DNNData *outputs;
ConvolutionalNetwork *network;
uint32_t nb;

void init_vars() {
    nb = 10000; // Adjust to control loop iterations for ~0.01 sec runtime

    outputs = (DNNData*)calloc(nb, sizeof(DNNData));
    if (!outputs) exit(1);

    network = (ConvolutionalNetwork*)malloc(sizeof(ConvolutionalNetwork));
    if (!network) exit(1);

    network->nb_output = nb;
    network->output_indexes = (int32_t*)malloc(nb * sizeof(int32_t));
    if (!network->output_indexes) exit(1);

    int total_operands = nb + 10; // Ensure output indexes are within bounds
    network->operands = (DnnOperand*)calloc(total_operands, sizeof(DnnOperand));
    if (!network->operands) exit(1);
    network->operands_num = total_operands;

    // Initialize operands and output indexes
    for (uint32_t i = 0; i < nb; ++i) {
        network->output_indexes[i] = i; // Map each output to operand[i]

        DnnOperand *oprd = &network->operands[i];
        oprd->dims[0] = 1;
        oprd->dims[1] = 64;   // height
        oprd->dims[2] = 64;   // width
        oprd->dims[3] = 32;   // channels
        oprd->type = DOT_OUTPUT;
        oprd->data_type = DNN_FLOAT;
        oprd->isNHWC = 1;

        size_t data_size = (size_t)oprd->dims[1] * oprd->dims[2] * oprd->dims[3] * sizeof(float);
        oprd->data = malloc(data_size);
        if (!oprd->data) exit(1);
        oprd->length = data_size;
        oprd->usedNumbersLeft = 1;
    }

    // Initialize remaining operands if any
    for (int i = nb; i < total_operands; ++i) {
        DnnOperand *oprd = &network->operands[i];
        oprd->dims[0] = 1;
        oprd->dims[1] = 32;
        oprd->dims[2] = 32;
        oprd->dims[3] = 16;
        oprd->type = DOT_INTERMEDIATE;
        oprd->data_type = DNN_UINT8;
        oprd->isNHWC = 0;

        size_t data_size = (size_t)oprd->dims[1] * oprd->dims[2] * oprd->dims[3] * sizeof(uint8_t);
        oprd->data = malloc(data_size);
        if (!oprd->data) exit(1);
        oprd->length = data_size;
        oprd->usedNumbersLeft = 1;
    }

    // Allocate dummy layers
    network->layers_num = 5;
    network->layers = (Layer*)calloc(network->layers_num, sizeof(Layer));
    if (!network->layers) exit(1);

    for (int i = 0; i < network->layers_num; ++i) {
        network->layers[i].type = DLT_CONV2D;
        network->layers[i].input_operand_indexes[0] = i;
        network->layers[i].output_operand_index = i + 1;
        network->layers[i].params = NULL;
    }
}