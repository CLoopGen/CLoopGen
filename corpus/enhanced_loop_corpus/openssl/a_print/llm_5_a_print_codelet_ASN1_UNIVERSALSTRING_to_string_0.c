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
for (i = 0; i < s->length && (p[0] == '\x00' && p[1] == '\x00' && p[2] == '\x00'); i += 4, p += 4) {
    continue;
}
}
