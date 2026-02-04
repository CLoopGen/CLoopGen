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
AVFilterFormats *ret;
int i;

static AVFilterFormats format_a;
static AVFilterFormats format_ret;

static struct AVFilterFormats ***alloc_refs(unsigned int count) {
    struct AVFilterFormats ***refs = malloc(count * sizeof(struct AVFilterFormats **));
    for (unsigned int i = 0; i < count; i++) {
        refs[i] = malloc(sizeof(struct AVFilterFormats *));
    }
    return refs;
}

void init_vars() {
    // Allocate data to make loop run ~0.01 seconds: assume moderate CPU, aim for ~10M iterations
    // Each iteration does pointer assignments and dereferences — relatively cheap.
    // Let's set refcount around 50000 to stay within safe memory bounds and performance target.
    unsigned int a_refcount = 50000;
    unsigned int ret_initial_refcount = 0;
    unsigned int ret_capacity = a_refcount;

    // Initialize format_a
    format_a.nb_formats = 0;
    format_a.formats = NULL;
    format_a.refcount = a_refcount;
    format_a.refs = alloc_refs(a_refcount);

    // Initialize format_ret
    format_ret.nb_formats = 0;
    format_ret.formats = NULL;
    format_ret.refcount = ret_initial_refcount;
    format_ret.refs = alloc_refs(ret_capacity);

    // Set external pointers
    a = &format_a;
    ret = &format_ret;

    // Initialize each entry in a->refs to point to valid AVFilterFormats** that can be assigned
    for (unsigned int j = 0; j < a_refcount; j++) {
        *(a->refs[j]) = &format_a;  // Point to something valid
    }

    // Ensure ret->refs entries are initialized to avoid null dereference when assigning *ret->refs[...] = ret
    for (unsigned int j = 0; j < ret_capacity; j++) {
        ret->refs[j] = malloc(sizeof(struct AVFilterFormats *));
        // Will be overwritten in loop, but must be valid memory
    }

    i = 0;
}