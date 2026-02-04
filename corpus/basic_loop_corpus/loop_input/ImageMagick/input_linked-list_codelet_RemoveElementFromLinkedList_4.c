#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _ElementInfo {
    void *value;
    struct _ElementInfo *next;
} ElementInfo;

size_t _usr_index;
ElementInfo *next;
ssize_t i;

#define index _usr_index

static ElementInfo *element_array = NULL;

void init_vars() {
    const size_t total_elements = 20000000; // ~20M elements, adjust for ~0.01 sec runtime
    _usr_index = total_elements - 1;

    element_array = malloc(total_elements * sizeof(ElementInfo));
    if (!element_array) {
        exit(EXIT_FAILURE);
    }

    for (size_t j = 0; j < total_elements - 1; j++) {
        element_array[j].value = NULL;
        element_array[j].next = &element_array[j + 1];
    }
    element_array[total_elements - 1].value = NULL;
    element_array[total_elements - 1].next = NULL;

    next = &element_array[0];
}