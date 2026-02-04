#include <stdio.h>

#include <inttypes.h>

struct asn1_object_st {
    const char *sn;
    const char *ln;
    int nid;
    int length;
    const unsigned char *data;
    int flags;
};


typedef struct asn1_object_st ASN1_OBJECT;

extern  ASN1_OBJECT *a;
extern int i;
extern unsigned long ret;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    for (i = 0; i < a->length; i++) {
        unsigned char temp = p[i];
        if ((i % 4) != 3) {
            ret ^= temp << ((i * 3) % 24);
        }
    }
}
