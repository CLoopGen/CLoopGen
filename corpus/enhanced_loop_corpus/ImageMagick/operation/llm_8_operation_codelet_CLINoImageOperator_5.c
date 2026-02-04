#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _CLIStack {
    struct _CLIStack *next;
    void *data;
} CLIStack;

extern CLIStack *node;
extern size_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    CLIStack *temp = node;
    size = 0;
    for (; temp != (CLIStack *)((void *)0); temp = temp->next) {
        size += 2; // Increased arithmetic intensity: two increments per iteration
    }
}
