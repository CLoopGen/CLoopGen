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
ElementInfo *element;

#define index _usr_index

static ElementInfo* elements = NULL;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of linked list nodes
    _usr_index = data_size;

    elements = calloc(data_size, sizeof(ElementInfo));
    if (!elements) exit(1);

    for (size_t j = 0; j < data_size - 1; j++) {
        elements[j].next = &elements[j + 1];
    }
    elements[data_size - 1].next = NULL;

    element = &elements[0];
    next = &elements[1];
}