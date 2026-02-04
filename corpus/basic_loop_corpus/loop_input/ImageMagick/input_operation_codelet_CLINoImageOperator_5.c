#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _CLIStack {
    struct _CLIStack *next;
    void *data;
} CLIStack;

CLIStack *node = NULL;
size_t size = 0;

void init_vars() {
    const size_t num_nodes = 10000000; // Adjust to achieve ~0.01s runtime

    if (num_nodes == 0) return;

    CLIStack *head = NULL;
    CLIStack *current = NULL;

    for (size_t i = 0; i < num_nodes; i++) {
        CLIStack *new_node = (CLIStack *)malloc(sizeof(CLIStack));
        new_node->data = NULL;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    node = head;
    size = 0;
}