#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

typedef struct read_result_t {
    unsigned int data1;
    unsigned int data2;
    struct read_result_t *next;
} Read_result;

typedef struct hashnode_t {
    Hash_data key;
    Read_result *results;
    struct hashnode_t *next;
} Hashnode;

extern Hashnode *node;
extern Read_result *result;
extern unsigned int search_for1;
extern unsigned int search_for2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern by skipping every other node
    // This modifies the traversal to access result nodes in a strided manner (step size 2)
    Read_result *current = node->results;
    while (current != ((void *)0)) {
        if (current->data1 == search_for1 && ((current->data2 & 1023) == search_for2))
            break;
        // Stride over next element: jump two steps if possible
        if (current->next != ((void *)0))
            current = current->next->next;
        else
            current = ((void *)0);
    }
    result = current; // Assign final result to global 'result'
}
