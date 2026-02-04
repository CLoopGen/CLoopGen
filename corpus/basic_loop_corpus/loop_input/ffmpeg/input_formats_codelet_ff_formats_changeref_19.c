#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct AVFilterFormats {
    unsigned int nb_formats;
    int *formats;
    unsigned int refcount;
    struct AVFilterFormats ***refs;
};

typedef struct AVFilterFormats AVFilterFormats;

AVFilterFormats **oldref;
int idx;
int i;

void init_vars() {
    const unsigned int data_size = 1 << 20; // ~1MB of input indirectly

    // Allocate an array of AVFilterFormats pointers
    AVFilterFormats **formats_array = calloc(data_size, sizeof(AVFilterFormats*));
    if (!formats_array) exit(1);

    // Allocate one AVFilterFormats instance
    AVFilterFormats *format = calloc(1, sizeof(AVFilterFormats));
    if (!format) exit(1);

    // Set refcount to a value so loop runs long enough (~1M iterations)
    format->refcount = data_size;

    // Allocate refs: array of pointers to arrays of AVFilterFormats**
    struct AVFilterFormats ***refs = calloc(data_size, sizeof(struct AVFilterFormats**));
    if (!refs) exit(1);

    for (unsigned int j = 0; j < data_size; j++) {
        refs[j] = calloc(1, sizeof(struct AVFilterFormats*));
        if (!refs[j]) exit(1);
    }

    format->refs = refs;

    formats_array[0] = format;
    oldref = formats_array;

    // Choose a valid index within bounds where the condition (*oldref)->refs[i] == oldref becomes true
    unsigned int target_index = data_size / 2;
    if (target_index >= (*oldref)->refcount) {
        target_index = (*oldref)->refcount - 1;
    }

    // Make sure that at target_index, the condition triggers: (*oldref)->refs[target_index] == oldref
    // So assign &((*oldref)->refs[target_index][0]) such that it points back to oldref
    (*oldref)->refs[target_index][0] = *oldref; // This ensures (*oldref)->refs[target_index] == oldref when compared as pointers
}