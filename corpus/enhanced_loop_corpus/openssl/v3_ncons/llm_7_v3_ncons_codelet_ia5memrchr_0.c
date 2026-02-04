#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_IA5STRING;

extern ASN1_IA5STRING *str;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long flags_cache = str->flags;
    int len = str->length;
    for (i = len; i > 0 && (str->data[i - 1] ^ c) & (~((flags_cache >> 8) & 0x1)); i--)
        ;
}
