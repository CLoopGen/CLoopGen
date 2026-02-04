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

AVFilterFormats *a;
AVFilterFormats *b;
int i;

static AVFilterFormats format_a;
static AVFilterFormats format_b;

static struct AVFilterFormats ***alloc_refs(unsigned int count) {
    struct AVFilterFormats ***refs = malloc(count * sizeof(struct AVFilterFormats **));
    for (unsigned int i = 0; i < count; i++) {
        refs[i] = malloc(sizeof(struct AVFilterFormats *));
    }
    return refs;
}

void init_vars() {
    // Allocate formats arrays
    int *formats_a = malloc(16 * sizeof(int));
    int *formats_b = malloc(16 * sizeof(int));
    for (int j = 0; j < 16; j++) {
        formats_a[j] = j;
        formats_b[j] = j + 100;
    }

    // Initialize a and b structures
    format_a.nb_formats = 16;
    format_a.formats = formats_a;
    format_a.refcount = 50000;  // Adjust to get ~0.01s runtime
    format_a.refs = alloc_refs(format_a.refcount);

    format_b.nb_formats = 16;
    format_b.formats = formats_b;
    format_b.refcount = 0;
    format_b.refs = alloc_refs(format_a.refcount); // Prevent overflow

    a = &format_a;
    b = &format_b;

    i = 0;
}