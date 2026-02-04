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
    for (i = 3; i < s->length && s != NULL; i += 4) {
        unsigned char val = s->data[i];
        if (val != 0) {
            *(p++) = val;
        } else {
            *(p++) = 0xFF;
        }
    }
}
