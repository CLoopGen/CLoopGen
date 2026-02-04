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
    // Variant 1: Consecutive memory access with reversed traversal
    for (i = a->length - 1; i >= 0; i--)
        ret ^= p[i] << ((i * 3) % 24);
}
