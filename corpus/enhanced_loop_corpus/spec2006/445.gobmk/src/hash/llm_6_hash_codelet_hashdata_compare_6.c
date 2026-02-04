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
    Hashvalue temp = rc;
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        temp = (hd1->hashval[i] != hd2->hashval[i]) ? 2 : temp;
    }
    rc = temp;
}
