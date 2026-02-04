#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

typedef uint32_t CodedBitstreamUnitType;

typedef struct CodedBitstreamUnit {
    CodedBitstreamUnitType type;
    uint8_t *data;
    size_t data_size;
    size_t data_bit_padding;
    AVBufferRef *data_ref;
    void *content;
    AVBufferRef *content_ref;
} CodedBitstreamUnit;

typedef struct CodedBitstreamFragment {
    uint8_t *data;
    size_t data_size;
    size_t data_bit_padding;
    AVBufferRef *data_ref;
    int nb_units;
    int nb_units_allocated;
    CodedBitstreamUnit *units;
} CodedBitstreamFragment;

CodedBitstreamFragment *frag;
size_t max;
int i;

static AVBufferRef **data_refs = NULL;
static uint8_t **unit_data_ptrs = NULL;
static CodedBitstreamUnit *units_array = NULL;

void init_vars() {
    // Allocate several MB of data to make loop take ~0.01s
    // We'll aim for around 64MB total unit data with ~1000 units
    const int num_units = 1000;
    const size_t total_data_size = 64 * 1024 * 1024; // 64 MB
    size_t accumulated_size = 0;

    // Allocate fragment structure
    frag = (CodedBitstreamFragment*)calloc(1, sizeof(CodedBitstreamFragment));
    
    // Allocate array of units
    units_array = (CodedBitstreamUnit*)calloc(num_units, sizeof(CodedBitstreamUnit));
    frag->units = units_array;
    frag->nb_units = num_units;
    frag->nb_units_allocated = num_units;

    // Allocate storage for data pointers and buffer refs
    unit_data_ptrs = (uint8_t**)calloc(num_units, sizeof(uint8_t*));
    data_refs = (AVBufferRef**)calloc(num_units, sizeof(AVBufferRef*));

    // Initialize each unit with variable-sized data blocks
    for (int idx = 0; idx < num_units; idx++) {
        // Vary size per unit between 4KB and 128KB to simulate real variation
        size_t unit_size = 4096 + (idx * 124096) % (128 * 1024);
        unit_data_ptrs[idx] = (uint8_t*)malloc(unit_size);
        // Fill with predictable pattern to prevent compiler optimizing out
        for (size_t j = 0; j < unit_size; j += 1007) { // prime step
            unit_data_ptrs[idx][j] = (uint8_t)(j ^ idx);
        }

        data_refs[idx] = (AVBufferRef*)calloc(1, sizeof(AVBufferRef));
        data_refs[idx]->data = unit_data_ptrs[idx];
        data_refs[idx]->size = (int)unit_size;

        // Initialize the unit
        units_array[idx].data = unit_data_ptrs[idx];
        units_array[idx].data_size = unit_size;
        units_array[idx].data_ref = data_refs[idx];
        units_array[idx].type = idx % 100; // arbitrary type

        accumulated_size += unit_size;
    }

    // Set initial max to zero
    max = 0;
}