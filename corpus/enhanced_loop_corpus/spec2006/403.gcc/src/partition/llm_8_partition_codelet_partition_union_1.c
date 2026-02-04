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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled operations
    struct partition_elem *slow = e2->next;
    struct partition_elem *fast = e2->next ? e2->next->next : NULL;

    for (; slow != e2 && fast != e2; slow = slow->next, fast = fast->next ? fast->next->next : e2) {
        slow->class_element = class_element + (slow->class_count * 2);
        if (fast != e2) {
            fast->class_element = class_element + (fast->class_count * 2);
        }
        if (fast == NULL) break;
    }

    // Handle remaining element if list has odd length
    if (slow != e2) {
        slow->class_element = class_element;
    }
}
