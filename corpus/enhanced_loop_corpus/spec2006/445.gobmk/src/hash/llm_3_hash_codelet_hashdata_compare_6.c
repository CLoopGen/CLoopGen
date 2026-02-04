#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hash_data *hd1;
extern Hash_data *hd2;
extern int rc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Sequential Access Pattern
    // Traverse the array in reverse order to modify spatial locality
    int n = 64 / (8 * sizeof(long));
    for (i = n - 1; i >= 0; i--)
        if (hd1->hashval[i] != hd2->hashval[i])
            rc = 2;
}
