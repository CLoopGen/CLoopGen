#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct partition_elem {
    int class_element;
    struct partition_elem *next;
    unsigned int class_count;
};

struct partition_elem *e2;
struct partition_elem *p;
int class_element;

#define DATA_SIZE (1 << 20)  // ~1MB of data, roughly 65k elements

static struct partition_elem *elements = NULL;

void init_vars() {
    class_element = 42;

    elements = calloc(DATA_SIZE, sizeof(struct partition_elem));
    if (!elements) {
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        elements[i].class_element = 0;
        elements[i].class_count = 1;
        if (i + 1 < DATA_SIZE) {
            elements[i].next = &elements[i + 1];
        } else {
            elements[i].next = NULL;
        }
    }

    e2 = &elements[0];
    struct partition_elem *tail = &elements[DATA_SIZE - 1];

    tail->next = e2;
}