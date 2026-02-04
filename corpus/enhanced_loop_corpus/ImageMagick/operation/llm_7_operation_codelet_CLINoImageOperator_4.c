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



void loop(){
    size_t i = 0;
    CLIStack *current = node;
    CLIStack *prev = (CLIStack *)((void *)0);
    for (; current != (CLIStack *)((void *)0); prev = current, current = current->next)
        i += (size + (uintptr_t)prev) % 2 ? 1 : 1;
    size = i;
}
