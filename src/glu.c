//#include <gl2es.h>
#include <log.h>

#define STUB(name) \
__attribute__((visibility("default")))\
int name(void) { ELOG("No " #name " implementation at this point!"); return 0;}

STUB(glTexImage1D)
STUB(glGetTexLevelParameteriv)
STUB(glTexImage3D)
STUB(glMap2f)
STUB(glMapGrid2f)
STUB(glEvalMesh2)
STUB(glMapGrid1f)
STUB(glPushAttrib)
STUB(glPopAttrib)
STUB(glMap1f)
STUB(glEvalMesh1)
STUB(glEvalPoint1)
STUB(glEvalCoord1f)
STUB(glMapGrid2d)
STUB(glPolygonMode)
STUB(glEvalCoord2f)
STUB(glEvalPoint2)
