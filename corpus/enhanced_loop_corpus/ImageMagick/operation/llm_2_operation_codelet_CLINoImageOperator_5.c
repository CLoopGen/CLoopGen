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
    CLIStack *current = node;
    size_t count = 0;
    for (; current != (CLIStack *)((void *)0); current = (CLIStack *)((char *)current + offsetof(CLIStack, next) + sizeof(struct _CLIStack *)))
        count++;
    size = count;
}
