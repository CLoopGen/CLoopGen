#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _ElementInfo {
    void *value;
    struct _ElementInfo *next;
} ElementInfo;

void **array;
ElementInfo *next;
ssize_t i;

#define DATA_SIZE (128 << 20)  // 128 MB of data

static ElementInfo *elements = NULL;

void init_vars() {
    // Allocate array of void* with size enough to hold all values
    array = calloc(DATA_SIZE, sizeof(void*));
    if (!array) exit(1);

    // Allocate a linked list of ElementInfo nodes
    elements = malloc(DATA_SIZE * sizeof(ElementInfo));
    if (!elements) exit(1);

    // Initialize each node: assign dummy value (e.g., address of itself), link to next
    for (size_t idx = 0; idx < DATA_SIZE - 1; idx++) {
        elements[idx].value = &elements[idx];
        elements[idx].next = &elements[idx + 1];
    }
    // Last element points to NULL
    elements[DATA_SIZE - 1].value = &elements[DATA_SIZE - 1];
    elements[DATA_SIZE - 1].next = NULL;

    // Initialize global 'next' to point to the first element
    next = &elements[0];
    i = 0;
}