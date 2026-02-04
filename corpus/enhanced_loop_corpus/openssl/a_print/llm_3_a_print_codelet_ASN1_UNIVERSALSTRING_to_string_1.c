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
    // Variant 2: Reverse strided access — traverse from end to beginning with step of -4
    int start = s->length - 1;
    if (start < 3) return;
    for (int j = start; j >= 3; j -= 4) {
        *(p++) = s->data[j];
    }
}
