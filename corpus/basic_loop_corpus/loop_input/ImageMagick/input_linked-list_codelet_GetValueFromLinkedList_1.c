#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef struct _ElementInfo {
    void *value;
    struct _ElementInfo *next;
} ElementInfo;

size_t _usr_index;
ElementInfo *next;
ssize_t i;

#define index _usr_index

static ElementInfo* head = NULL;
static const size_t total_elements = 1000000; // ~1M elements for ~0.01s runtime

void init_vars() {
    head = malloc(total_elements * sizeof(ElementInfo));
    if (!head) exit(1);

    ElementInfo* current = head;
    for (size_t j = 0; j < total_elements; ++j) {
        current[j].value = NULL;
        current[j].next = (j == total_elements - 1) ? NULL : &current[j + 1];
    }

    next = head;
    index = total_elements - 1;
}