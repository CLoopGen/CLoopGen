#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct AVBuffer {
    int dummy;
};

struct AVBufferRef {
    struct AVBuffer *buffer;
    uint8_t *data;
    int size;
};

typedef uint32_t CodedBitstreamUnitType;

struct CodedBitstreamUnit {
    CodedBitstreamUnitType type;
    uint8_t *data;
    size_t data_size;
    size_t data_bit_padding;
    struct AVBufferRef *data_ref;
    void *content;
    struct AVBufferRef *content_ref;
};

struct CodedBitstreamFragment {
    uint8_t *data;
    size_t data_size;
    size_t data_bit_padding;
    struct AVBufferRef *data_ref;
    int nb_units;
    int nb_units_allocated;
    struct CodedBitstreamUnit *units;
};

struct CodedBitstreamFragment *au;
struct CodedBitstreamUnit *nal;
int i;

static struct CodedBitstreamUnit *g_units = NULL;
static struct CodedBitstreamFragment g_fragment;
static struct AVBufferRef g_buffer_ref;
static uint8_t *g_data = NULL;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // 128 MB
    const int unit_count = 30000;

    g_data = (uint8_t*)calloc(total_data_size, 1);
    if (!g_data) exit(1);

    g_units = (struct CodedBitstreamUnit*)calloc(unit_count, sizeof(struct CodedBitstreamUnit));
    if (!g_units) exit(1);

    for (int j = 0; j < unit_count; j++) {
        g_units[j].data = g_data + (j * (total_data_size / unit_count));
        g_units[j].data_size = total_data_size / unit_count;
        g_units[j].type = (CodedBitstreamUnitType)(j + 1);
        g_units[j].data_ref = &g_buffer_ref;
    }

    g_buffer_ref.buffer = NULL;
    g_buffer_ref.data = g_data;
    g_buffer_ref.size = total_data_size;

    g_fragment.data = g_data;
    g_fragment.data_size = total_data_size;
    g_fragment.data_bit_padding = 0;
    g_fragment.data_ref = &g_buffer_ref;
    g_fragment.nb_units = unit_count;
    g_fragment.nb_units_allocated = unit_count;
    g_fragment.units = g_units;

    au = &g_fragment;
    nal = &g_units[unit_count - 1]; // Point to last unit to ensure loop runs through most units
    i = 0;
}