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

const enum mode_class mode_class[59] = {
    MODE_RANDOM,    
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_INT,      
    MODE_FLOAT,    
    MODE_FLOAT,    
    MODE_FLOAT,    
    MODE_FLOAT,    
    MODE_FLOAT,    
    MODE_FLOAT,    
    MODE_COMPLEX_FLOAT,
    MODE_COMPLEX_FLOAT,
    MODE_COMPLEX_FLOAT,
    MODE_COMPLEX_FLOAT,
    MODE_COMPLEX_FLOAT,
    MODE_COMPLEX_FLOAT,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_INT,
    MODE_VECTOR_FLOAT,
    MODE_VECTOR_FLOAT,
    MODE_VECTOR_FLOAT,
    MODE_VECTOR_FLOAT,
    MODE_VECTOR_FLOAT,
    MODE_VECTOR_FLOAT,
    MODE_VECTOR_FLOAT,
    MODE_RANDOM,
    MODE_CC,
    MODE_CC,
    MODE_CC,
    MODE_CC,
    MODE_CC,
    MODE_CC,
    MODE_CC,
    MODE_RANDOM
};

const unsigned char mode_size[59] = {
    0, // VOIDmode
    1, // BImode
    1, // QImode
    2, // HImode
    4, // SImode
    8, // DImode
    16, // TImode
    32, // OImode
    1, // PQImode
    2, // PHImode
    4, // PSImode
    8, // PDImode
    4, // QFmode
    2, // HFmode
    12, // TQFmode
    4, // SFmode
    8, // DFmode
    12, // XFmode
    16, // TFmode
    8, // QCmode
    4, // HCmode
    8, // SCmode
    16, // DCmode
    24, // XCmode
    32, // TCmode
    2, // CQImode
    4, // CHImode
    8, // CSImode
    16, // CDImode
    32, // CTImode
    64, // COImode
    2, // V2QImode
    4, // V2HImode
    8, // V2SImode
    16, // V2DImode
    4, // V4QImode
    8, // V4HImode
    16, // V4SImode
    32, // V4DImode
    8, // V8QImode
    16, // V8HImode
    32, // V8SImode
    64, // V8DImode
    16, // V16QImode
    8, // V2SFmode
    16, // V2DFmode
    16, // V4SFmode
    32, // V4DFmode
    32, // V8SFmode
    64, // V8DFmode
    64, // V16SFmode
    0, // BLKmode
    4, // CCmode
    4, // CCGCmode
    4, // CCGOCmode
    4, // CCNOmode
    4, // CCZmode
    4, // CCFPmode
    4, // CCFPUmode
};

const unsigned char mode_unit_size[59] = {
    0, // VOIDmode
    1, // BImode
    1, // QImode
    2, // HImode
    4, // SImode
    8, // DImode
    16, // TImode
    32, // OImode
    1, // PQImode
    2, // PHImode
    4, // PSImode
    8, // PDImode
    4, // QFmode
    2, // HFmode
    4, // TQFmode
    4, // SFmode
    8, // DFmode
    12, // XFmode
    16, // TFmode
    4, // QCmode
    2, // HCmode
    4, // SCmode
    8, // DCmode
    12, // XCmode
    16, // TCmode
    1, // CQImode
    2, // CHImode
    4, // CSImode
    8, // CDImode
    16, // CTImode
    32, // COImode
    1, // V2QImode
    2, // V2HImode
    4, // V2SImode
    8, // V2DImode
    1, // V4QImode
    2, // V4HImode
    4, // V4SImode
    8, // V4DImode
    1, // V8QImode
    2, // V8HImode
    4, // V8SImode
    8, // V8DImode
    1, // V16QImode
    4, // V2SFmode
    8, // V2DFmode
    4, // V4SFmode
    8, // V4DFmode
    4, // V8SFmode
    8, // V8DFmode
    4, // V16SFmode
    0, // BLKmode
    4, // CCmode
    4, // CCGCmode
    4, // CCGOCmode
    4, // CCNOmode
    4, // CCZmode
    4, // CCFPmode
    4, // CCFPUmode
};

const unsigned char mode_wider_mode[59] = {
    VOIDmode,      // VOIDmode
    QImode,        // BImode
    HImode,        // QImode
    SImode,        // HImode
    DImode,        // SImode
    TImode,        // DImode
    OImode,        // TImode
    VOIDmode,      // OImode
    PHImode,       // PQImode
    PSImode,       // PHImode
    PDImode,       // PSImode
    VOIDmode,      // PDImode
    HFmode,        // QFmode
    TQFmode,       // HFmode
    SFmode,        // TQFmode
    DFmode,        // SFmode
    XFmode,        // DFmode
    TFmode,        // XFmode
    VOIDmode,      // TFmode
    HCmode,        // QCmode
    SCmode,        // HCmode
    DCmode,        // SCmode
    XCmode,        // DCmode
    TCmode,        // XCmode
    VOIDmode,      // TCmode
    CHImode,       // CQImode
    CSImode,       // CHImode
    CDImode,       // CSImode
    CTImode,       // CDImode
    COImode,       // CTImode
    VOIDmode,      // COImode
    V2HImode,      // V2QImode
    V2SImode,      // V2HImode
    V2DImode,      // V2SImode
    VOIDmode,      // V2DImode
    V4HImode,      // V4QImode
    V4SImode,      // V4HImode
    V4DImode,      // V4SImode
    VOIDmode,      // V4DImode
    V8HImode,      // V8QImode
    V8SImode,      // V8HImode
    V8DImode,      // V8SImode
    VOIDmode,      // V8DImode
    VOIDmode,      // V16QImode
    V2DFmode,      // V2SFmode
    VOIDmode,      // V2DFmode
    V4DFmode,      // V4SFmode
    VOIDmode,      // V4DFmode
    V8DFmode,      // V8SFmode
    VOIDmode,      // V8DFmode
    VOIDmode,      // V16SFmode
    VOIDmode,      // BLKmode
    CCGCmode,      // CCmode
    CCGOCmode,     // CCGCmode
    CCNOmode,      // CCGOCmode
    CCZmode,       // CCNOmode
    CCFPmode,      // CCZmode
    CCFPUmode,     // CCFPmode
    VOIDmode       // CCFPUmode
};

const enum machine_mode class_narrowest_mode[9] = {
    VOIDmode, // placeholder for index 0
    V2QImode, // MODE_VECTOR_INT
    V2SFmode, // MODE_VECTOR_FLOAT
    VOIDmode, // unused
    VOIDmode, // unused
    VOIDmode, // unused
    VOIDmode, // unused
    VOIDmode, // unused
    VOIDmode  // unused
};

unsigned long vecsize = 16;
unsigned long nunits = 4;
enum machine_mode mode;
enum machine_mode orig_mode = V4SFmode;
enum machine_mode new_mode;

void init_vars() {
    vecsize = 16;
    nunits = 4;
    orig_mode = V4SFmode;
    new_mode = VOIDmode;
}