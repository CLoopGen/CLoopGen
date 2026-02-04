#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ElementInfo {
    void *value;
    struct _ElementInfo *next;
} ElementInfo;

extern void **array;
extern ElementInfo *next;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    for (; next != (ElementInfo *)((void *)0) && array != NULL; i++) {
        if (next->value == NULL) continue;
        array[i] = next->value;
        next = next->next;
    }
}
