#include <stdio.h>

#include <inttypes.h>

struct partition_elem {
    int class_element;
    struct partition_elem *next;
    unsigned int class_count;
};


extern struct partition_elem *e2;
extern struct partition_elem *p;
extern int class_element;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective nesting depth by flattening potential structure (though original is flat, we simulate reduced depth by removing any possible nesting context)
    // This version ensures minimal control flow — already at base level, so expressed directly with single loop
    for (p = e2->next; p != e2; p = p->next)
        p->class_element = class_element;
}
