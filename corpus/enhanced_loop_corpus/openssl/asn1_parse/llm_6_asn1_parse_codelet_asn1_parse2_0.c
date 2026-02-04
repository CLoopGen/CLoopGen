#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_OCTET_STRING;

extern  unsigned char *opp;
extern ASN1_OCTET_STRING *os;
extern int i;
extern int printable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_printable = 1;
    for (i = 0; i < os->length; i++) {
        unsigned char current = opp[i];
        if (((current < ' ') && (current != '\n') && (current != '\r') && (current != '\t')) || (current > '~')) {
            temp_printable = 0;
        }
    }
    printable = temp_printable;
}
