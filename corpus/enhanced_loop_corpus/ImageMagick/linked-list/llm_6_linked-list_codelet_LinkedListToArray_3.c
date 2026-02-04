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
    ssize_t j = 0;
    ElementInfo *current = next;
    void **temp_array = array;

    for (i = 0; current != (ElementInfo *)((void *)0); i++) {
        temp_array[j] = current->value;
        current = current->next;
        j++;
    }
    i = j; // Remove WAW dependency on 'i' by updating only once at end
}
