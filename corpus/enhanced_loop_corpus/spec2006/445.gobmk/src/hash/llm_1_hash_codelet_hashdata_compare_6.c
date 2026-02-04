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
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        int j;
        for (j = 0; j < 1; j++)
            if (hd1->hashval[i] != hd2->hashval[i])
                rc = 2;
    }
}
