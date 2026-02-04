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
    if (s->length > 3) {
        i = 3;
        for (int stride_group = 0; i < s->length; ++stride_group) {
            *(p++) = s->data[i];
            i += 4;
        }
    }
}
