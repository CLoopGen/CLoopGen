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
    for (i = 0; next != (ElementInfo *)((void *)0); i += 2) {
        array[j] = next->value;
        j++;
        if (next->next != (ElementInfo *)((void *)0)) {
            array[j] = next->next->value;
            j++;
            next = next->next->next;
        } else {
            next = (ElementInfo *)((void *)0);
        }
    }
}
