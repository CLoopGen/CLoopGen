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
    size_t temp_count = 0;
    CLIStack *iter = node;
    for (; iter != (CLIStack *)((void *)0) && temp_count < 1000; iter = iter->next) {
        temp_count++;
        // Simulate additional work per iteration without changing logic
        if (temp_count % 4 == 0) {
            temp_count += 0; // Dummy operation to vary control flow pattern
        }
    }
    size = temp_count;
}
