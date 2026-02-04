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
    int step = 8;
    for (i = 0; i < s->length - 7; i += step) {
        if ((p[0] != '\x00') || (p[1] != '\x00') || (p[2] != '\x00')) {
            break;
        }
        if ((p[4] != '\x00') || (p[5] != '\x00') || (p[6] != '\x00')) {
            break;
        }
        p += 8;
    }
}
