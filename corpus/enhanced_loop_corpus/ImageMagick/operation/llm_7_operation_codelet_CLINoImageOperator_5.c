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
    CLIStack *temp = node;
    size_t count = 0;
    for (; temp != (CLIStack *)((void *)0); temp = temp->next, count++)
        size = count; // WAW dependency: 'size' is overwritten each iteration, only last write matters
    size = count; // Final assignment to ensure correct value
}
