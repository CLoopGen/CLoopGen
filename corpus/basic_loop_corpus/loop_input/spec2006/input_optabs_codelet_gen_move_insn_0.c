#include <stdio.h>
#include <inttypes.h>

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

const unsigned char mode_size[59] = {
    0,  // VOIDmode
    1,  // BImode
    1,  // QImode
    2,  // HImode
    4,  // SImode
    8,  // DImode
    16, // TImode
    0,  // OImode
    1,  // PQImode
    2,  // PHImode
    4,  // PSImode
    8,  // PDImode
    4,  // QFmode
    2,  // HFmode
    3,  // TQFmode
    4,  // SFmode
    8,  // DFmode
    12, // XFmode
    16, // TFmode
    8,  // QCmode
    4,  // HCmode
    8,  // SCmode
    16, // DCmode
    24, // XCmode
    32, // TCmode
    2,  // CQImode
    4,  // CHImode
    8,  // CSImode
    16, // CDImode
    32, // CTImode
    0,  // COImode
    2,  // V2QImode
    4,  // V2HImode
    8,  // V2SImode
    16, // V2DImode
    4,  // V4QImode
    8,  // V4HImode
    16, // V4SImode
    32, // V4DImode
    8,  // V8QImode
    16, // V8HImode
    32, // V8SImode
    64, // V8DImode
    16, // V16QImode
    8,  // V2SFmode
    16, // V2DFmode
    16, // V4SFmode
    32, // V4DFmode
    32, // V8SFmode
    64, // V8DFmode
    64, // V16SFmode
    1,  // BLKmode
    0,  // CCmode
    0,  // CCGCmode
    0,  // CCGOCmode
    0,  // CCNOmode
    0,  // CCZmode
    0,  // CCFPmode
    0   // CCFPUmode
};

const unsigned char mode_wider_mode[59] = {
    VOIDmode,      // VOIDmode
    BImode,        // BImode
    HImode,        // QImode
    SImode,        // HImode
    DImode,        // SImode
    TImode,        // DImode
    OImode,        // TImode
    OImode,        // OImode
    PHImode,       // PQImode
    PSImode,       // PHImode
    PDImode,       // PSImode
    TImode,        // PDImode
    HFmode,        // QFmode
    TQFmode,       // HFmode
    SFmode,        // TQFmode
    DFmode,        // SFmode
    XFmode,        // DFmode
    TFmode,        // XFmode
    TFmode,        // TFmode
    HCmode,        // QCmode
    SCmode,        // HCmode
    DCmode,        // SCmode
    XCmode,        // DCmode
    TCmode,        // XCmode
    TCmode,        // TCmode
    CHImode,       // CQImode
    CSImode,       // CHImode
    CDImode,       // CSImode
    CTImode,       // CDImode
    CTImode,       // CTImode
    COImode,       // COImode
    V2HImode,      // V2QImode
    V2SImode,      // V2HImode
    V2DImode,      // V2SImode
    V2DImode,      // V2DImode
    V4HImode,      // V4QImode
    V4SImode,      // V4HImode
    V4DImode,      // V4SImode
    V4DImode,      // V4DImode
    V8HImode,      // V8QImode
    V8SImode,      // V8HImode
    V8DImode,      // V8SImode
    V8DImode,      // V8DImode
    V16QImode,     // V16QImode
    V2DFmode,      // V2SFmode
    V2DFmode,      // V2DFmode
    V4DFmode,      // V4SFmode
    V4DFmode,      // V4DFmode
    V8DFmode,      // V8SFmode
    V8DFmode,      // V8DFmode
    V16SFmode,     // V16SFmode
    BLKmode,       // BLKmode
    CCmode,        // CCmode
    CCGCmode,      // CCGCmode
    CCGOCmode,     // CCGOCmode
    CCNOmode,      // CCNOmode
    CCZmode,       // CCZmode
    CCFPmode,      // CCFPmode
    CCFPUmode      // CCFPUmode
};

enum machine_mode mode;
enum machine_mode tmode;

void init_vars() {
    mode = DImode;
    tmode = QImode;
}