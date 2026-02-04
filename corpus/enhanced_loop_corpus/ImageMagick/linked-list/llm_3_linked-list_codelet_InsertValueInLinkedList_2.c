#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ElementInfo {
    void *value;
    struct _ElementInfo *next;
} ElementInfo;

extern  size_t _usr_index;
extern ElementInfo *next;
extern ssize_t i;
extern ElementInfo *element;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Indirect Access via Array-like Indexing Using an Auxiliary Pointer Array
    // Simulate indirect access by first storing pointers in an array, then traversing indirectly
    // This assumes a bounded size; use dynamic allocation to remain safe
    ElementInfo **ptr_array = (ElementInfo**)malloc(index * sizeof(ElementInfo*));
    if (!ptr_array) return;

    ElementInfo *temp = element;
    size_t count = 0;
    while (temp != NULL && count < index) {
        ptr_array[count++] = temp;
        temp = temp->next;
    }

    for (i = 1; i < (ssize_t)index; i++) {
        if (i + 1 < (ssize_t)count) {
            element = ptr_array[i];
            next->next = ptr_array[i + 1];
        }
    }

    free(ptr_array);
}
