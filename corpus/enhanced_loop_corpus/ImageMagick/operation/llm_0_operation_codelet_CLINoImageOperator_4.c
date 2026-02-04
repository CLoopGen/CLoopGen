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
for (; node != (CLIStack *)((void *)0); node = node->next)
    for (size_t i = 0; i < 1; i++)
        size++;
}
