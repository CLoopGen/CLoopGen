#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct AVFilterFormats {
    unsigned int nb_formats;
    int *formats;
    unsigned int refcount;
    struct AVFilterFormats ***refs;
};


typedef struct AVFilterFormats AVFilterFormats;

extern AVFilterFormats *a;
extern AVFilterFormats *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Simulates non-sequential access pattern; here we assume indices are accessed in reverse order
    // This changes the memory access pattern from forward sequential to reverse
    unsigned int idx;
    for (i = 0; i < a->refcount; i++) {
        idx = a->refcount - 1 - i;  // Reverse access: last element first
        b->refs[b->refcount] = a->refs[idx];
        *b->refs[b->refcount++] = b;
    }
}
