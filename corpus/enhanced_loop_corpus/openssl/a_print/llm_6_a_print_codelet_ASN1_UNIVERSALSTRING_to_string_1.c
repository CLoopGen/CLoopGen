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
    int j;
    for (j = 3; j < s->length; j += 4) {
        unsigned char temp = s->data[j];
        *(p++) = temp;
    }
}
