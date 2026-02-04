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

static AVFilterFormats static_a_storage;
static AVFilterFormats static_ret_storage;

static struct AVFilterFormats ***create_refs_array(unsigned int size) {
    struct AVFilterFormats ***arr = malloc(size * sizeof(struct AVFilterFormats **));
    for (unsigned int i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(struct AVFilterFormats *));
        *arr[i] = NULL;
    }
    return arr;
}

void init_vars() {
    a = &static_a_storage;
    ret = &static_ret_storage;

    a->nb_formats = 0;
    a->formats = NULL;
    a->refcount = 50000;

    ret->nb_formats = 0;
    ret->formats = NULL;
    ret->refcount = 0;

    a->refs = create_refs_array(a->refcount);
    ret->refs = create_refs_array(a->refcount);

    for (unsigned int j = 0; j < a->refcount; j++) {
        a->refs[j] = malloc(sizeof(struct AVFilterFormats *));
        *a->refs[j] = a;
    }

    ret->refcount = 0;
}