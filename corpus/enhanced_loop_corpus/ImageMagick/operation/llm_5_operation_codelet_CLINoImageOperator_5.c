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
    size = 0;
    for (CLIStack *iter = node; iter != (CLIStack *)((void *)0) && iter->data != (void *)0; 
         iter = iter->next, size++);
}
