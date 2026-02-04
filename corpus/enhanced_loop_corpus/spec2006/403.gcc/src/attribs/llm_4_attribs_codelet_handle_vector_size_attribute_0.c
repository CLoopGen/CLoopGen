#include <stdio.h>

#include <inttypes.h>

enum mode_class {
    MODE_RANDOM,
    MODE_INT,
    MODE_FLOAT,
    MODE_PARTIAL_INT,
    MODE_CC,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_FLOAT,
    MODE_VECTOR_INT,
    MODE_VECTOR_FLOAT,
    MAX_MODE_CLASS
};


enum machine_mode {
    VOIDmode,
    BImode,
    QImode,
    HImode,
    SImode,
    DImode,
    TImode,
    OImode,
    PQImode,
    PHImode,
    PSImode,
    PDImode,
    QFmode,
    HFmode,
    TQFmode,
    SFmode,
    DFmode,
    XFmode,
    TFmode,
    QCmode,
    HCmode,
    SCmode,
    DCmode,
    XCmode,
    TCmode,
    CQImode,
    CHImode,
    CSImode,
    CDImode,
    CTImode,
    COImode,
    V2QImode,
    V2HImode,
    V2SImode,
    V2DImode,
    V4QImode,
    V4HImode,
    V4SImode,
    V4DImode,
    V8QImode,
    V8HImode,
    V8SImode,
    V8DImode,
    V16QImode,
    V2SFmode,
    V2DFmode,
    V4SFmode,
    V4DFmode,
    V8SFmode,
    V8DFmode,
    V16SFmode,
    BLKmode,
    CCmode,
    CCGCmode,
    CCGOCmode,
    CCNOmode,
    CCZmode,
    CCFPmode,
    CCFPUmode,
    MAX_MACHINE_MODE
};


extern const enum mode_class mode_class[59];
extern const unsigned char mode_size[59];
extern const unsigned char mode_unit_size[59];
extern const unsigned char mode_wider_mode[59];
extern const enum machine_mode class_narrowest_mode[9];
extern unsigned long vecsize;
extern unsigned long nunits;
extern enum machine_mode mode;
extern enum machine_mode orig_mode;
extern enum machine_mode new_mode;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (mode = class_narrowest_mode[(int)((mode_class[(int)(orig_mode)]) == MODE_INT ? MODE_VECTOR_INT : MODE_VECTOR_FLOAT)]; mode != VOIDmode; mode = ((enum machine_mode)mode_wider_mode[(int)(mode)])) {
        if (vecsize != mode_size[(int)(mode)]) {
            continue;
        }
        unsigned long computed_nunits = (mode_unit_size[(int)(mode)] == 0) ? 0 : (mode_size[(int)(mode)] / mode_unit_size[(int)(mode)]);
        if (nunits == computed_nunits) {
            new_mode = mode;
            break;
        }
    }
}
