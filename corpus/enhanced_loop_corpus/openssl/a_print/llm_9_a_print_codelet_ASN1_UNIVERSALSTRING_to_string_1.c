#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_UNIVERSALSTRING;

extern ASN1_UNIVERSALSTRING *s;
extern int i;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[4] = {3, 4, 5, 6};  // Base offsets
    int base = 0;
    for (i = 3; i < s->length; i += 4) {
        int relative = (i - 3) / 4;           // Eliminate direct use of i as index
        int idx = indices[0] + 4 * relative;  // Re-compute access index (removes direct stride dependency on i)
        if (idx < s->length) {
            *(p++) = s->data[idx];
        }
    }
}
