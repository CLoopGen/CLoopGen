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

AVFilterFormats **ref;
int idx;
int i;

static AVFilterFormats filter_formats_instance;
static AVFilterFormats ***refs_array;
static AVFilterFormats **outer_ref_pointers;
static const unsigned int array_size = 20000;

void init_vars() {
    refs_array = malloc(array_size * sizeof(AVFilterFormats***));
    outer_ref_pointers = malloc(array_size * sizeof(AVFilterFormats**));

    for (unsigned int j = 0; j < array_size; j++) {
        outer_ref_pointers[j] = &filter_formats_instance;
        refs_array[j] = &(outer_ref_pointers[j]);
    }

    filter_formats_instance.nb_formats = 0;
    filter_formats_instance.formats = NULL;
    filter_formats_instance.refcount = array_size;
    filter_formats_instance.refs = refs_array;

    ref = &(outer_ref_pointers[0]);

    idx = -1;
    i = 0;
}