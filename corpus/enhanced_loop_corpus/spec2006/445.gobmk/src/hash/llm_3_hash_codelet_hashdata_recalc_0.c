#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hash_data *target;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {0, 1, 2, 3}; // Assuming 64/(8*sizeof(long)) <= 4 for typical systems
    int n = (64 / (8 * sizeof(long)));
    for (i = 0; i < n; i++)
        target->hashval[indices[i]] = 0;
}
