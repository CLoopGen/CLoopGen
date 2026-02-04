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
    // Variant 2: Strided memory access (stride of 2) with bounds check
    for (i = 0; i < a->length; i += 2)
        ret ^= p[i] << ((i * 3) % 24);
}
