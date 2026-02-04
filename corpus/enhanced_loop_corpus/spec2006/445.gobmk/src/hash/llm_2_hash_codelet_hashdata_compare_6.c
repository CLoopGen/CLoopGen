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
    // Variant 1: Strided Memory Access Pattern
    // Access elements with a stride of 2, wrapping around if necessary
    int n = 64 / (8 * sizeof(long));
    int stride = 2;
    for (i = 0; i < n; i++) {
        int idx = (i * stride) % n;  // Strided access via index mapping
        if (hd1->hashval[idx] != hd2->hashval[idx])
            rc = 2;
    }
}
