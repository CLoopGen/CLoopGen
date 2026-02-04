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
    int step = 2;
    for (i = 3; i < s->length; i += step) {
        *(p++) = s->data[i];
        *(p++) = s->data[i] ^ 0xFF; // Additional arithmetic/bitwise op to increase computational intensity
        step = 5 - step; // Alternates step between 2 and 3, changing trip count and access pattern
    }
}
