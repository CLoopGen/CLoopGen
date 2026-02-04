#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

Hash_data *hd1;
Hash_data *hd2;
int rc;
int i;

void init_vars() {
    const int num_elements = 64 / (8 * sizeof(long));
    size_t data_size = sizeof(Hashvalue) * num_elements;
    
    // Allocate memory for hd1 and hd2
    Hash_data *ptr1 = (Hash_data*)malloc(sizeof(Hash_data) + sizeof(Hashvalue) * (num_elements - 1));
    Hash_data *ptr2 = (Hash_data*)malloc(sizeof(Hash_data) + sizeof(Hashvalue) * (num_elements - 1));
    
    // Initialize both arrays with identical values to avoid early exit, but make one element differ
    for (int j = 0; j < num_elements; j++) {
        ptr1->hashval[j] = 0xABCDEF00 + j;
        ptr2->hashval[j] = 0xABCDEF00 + j;
    }
    
    // Make sure they differ so rc gets set (as per loop logic)
    if (num_elements > 0) {
        ptr2->hashval[num_elements - 1] ^= 1;  // Ensure inequality in last element
    }
    
    hd1 = ptr1;
    hd2 = ptr2;
    rc = 0;  // Initial value before loop
    i = 0;   // Will be used in loop
}