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
    rc = 0;
    for (i = 0; i < (32 / (8 * sizeof(long))); i += 2) {
        Hashvalue diff1 = hd1->hashval[i] - hd2->hashval[i];
        Hashvalue diff2 = (i + 1 < (32 / (8 * sizeof(long)))) ? 
                          hd1->hashval[i + 1] - hd2->hashval[i + 1] : 0;
        if (diff1 != 0 || (i + 1 < (32 / (8 * sizeof(long))) && diff2 != 0)) {
            rc = 2;
            break;
        }
    }
}
