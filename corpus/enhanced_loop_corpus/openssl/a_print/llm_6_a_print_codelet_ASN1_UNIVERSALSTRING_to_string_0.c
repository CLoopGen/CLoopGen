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
    for (i = 0; i < s->length; i += 4) {
        j = i;
        if ((p[0] != '\x00') || (p[1] != '\x00') || (p[2] != '\x00'))
            break;
        else {
            p += 4;
            // Introduce a WAW dependency on 'j' and create loop-carried dependency via update
            j = i + 1;
        }
    }
}
