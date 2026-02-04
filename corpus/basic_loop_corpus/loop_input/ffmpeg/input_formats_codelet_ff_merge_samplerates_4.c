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

static AVFilterFormats fmt_a;
static AVFilterFormats fmt_b;
static AVFilterFormats **refs_a_storage;
static AVFilterFormats **refs_b_storage;
static AVFilterFormats ***ptr_refs_a_storage;
static AVFilterFormats ***ptr_refs_b_storage;

void init_vars() {
    // Allocate storage arrays
    size_t num_refs = 10000; // Adjust to control runtime (~0.01 sec)

    refs_a_storage = calloc(num_refs, sizeof(AVFilterFormats*));
    refs_b_storage = calloc(num_refs, sizeof(AVFilterFormats*));
    ptr_refs_a_storage = malloc(num_refs * sizeof(AVFilterFormats**));
    ptr_refs_b_storage = malloc(num_refs * sizeof(AVFilterFormats**));

    // Initialize fmt_a
    fmt_a.nb_formats = 0;
    fmt_a.formats = NULL;
    fmt_a.refcount = 0;
    fmt_a.refs = ptr_refs_a_storage;

    // Initialize fmt_b
    fmt_b.nb_formats = 0;
    fmt_b.formats = NULL;
    fmt_b.refcount = num_refs;
    fmt_b.refs = ptr_refs_b_storage;

    // Initialize b's refs and a's refs pointers
    for (size_t j = 0; j < num_refs; j++) {
        ptr_refs_b_storage[j] = &refs_b_storage[j];
        refs_b_storage[j] = &fmt_b; // arbitrary valid pointer
        ptr_refs_a_storage[j] = &refs_a_storage[j];
    }

    // Set global pointers
    a = &fmt_a;
    b = &fmt_b;

    // Pre-initialize one element in a->refs to avoid null pointer dereference when incrementing
    a->refs[0] = &refs_a_storage[0];
}