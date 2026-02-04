#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _CLIStack {
    struct _CLIStack *next;
    void *data;
} CLIStack;

CLIStack *node;
size_t size;

static CLIStack *stack_array;
static size_t total_nodes = 10000000; // Adjust to target ~0.01s runtime

void init_vars() {
    stack_array = calloc(total_nodes, sizeof(CLIStack));
    if (!stack_array) {
        exit(1);
    }

    for (size_t i = 0; i < total_nodes - 1; i++) {
        stack_array[i].next = &stack_array[i + 1];
        stack_array[i].data = NULL;
    }
    stack_array[total_nodes - 1].next = NULL;
    stack_array[total_nodes - 1].data = NULL;

    node = &stack_array[0];
    size = 0;
}