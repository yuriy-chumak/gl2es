
#include <GLES3/gl3.h>
#include <log.h>

#include <gles-2.0.h>

//
void (* gles_glGetIntegerv)(GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetIntegerv(
    GLenum pname, 
    GLint * params);
//
void (* gles_glDeleteRenderbuffers)(GLsizei n, const GLuint * renderbuffers) = 0;
__attribute__((visibility("default")))
void glDeleteRenderbuffers(
    GLsizei n, 
    const GLuint * renderbuffers)
{
   (void) gles_glDeleteRenderbuffers(n, renderbuffers);
}
//
void (* gles_glClear)(GLbitfield mask) = 0;
__attribute__((visibility("default")))
void glClear(
    GLbitfield mask)
{
   (void) gles_glClear(mask);
}
//
void (* gles_glBlendColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) = 0;
__attribute__((visibility("default")))
void glBlendColor(
    GLclampf red, 
    GLclampf green, 
    GLclampf blue, 
    GLclampf alpha)
{
   (void) gles_glBlendColor(red, green, blue, alpha);
}
//
void (* gles_glBindBuffer)(GLenum target, GLuint buffer) = 0;
__attribute__((visibility("default")))
void glBindBuffer(
    GLenum target, 
    GLuint buffer)
{
   (void) gles_glBindBuffer(target, buffer);
}
//
void (* gles_glAttachShader)(GLuint program, GLuint shader) = 0;
__attribute__((visibility("default")))
void glAttachShader(
    GLuint program, 
    GLuint shader)
{
   (void) gles_glAttachShader(program, shader);
}
//
void (* gles_glActiveTexture)(GLenum texture) = 0;
__attribute__((visibility("default")))
void glActiveTexture(
    GLenum texture);
//
void (* gles_glBindAttribLocation)(GLuint program, GLuint index, const GLchar * name) = 0;
__attribute__((visibility("default")))
void glBindAttribLocation(
    GLuint program, 
    GLuint index, 
    const GLchar * name)
{
   (void) gles_glBindAttribLocation(program, index, name);
}
//
void (* gles_glBindRenderbuffer)(GLenum target, GLuint renderbuffer) = 0;
__attribute__((visibility("default")))
void glBindRenderbuffer(
    GLenum target, 
    GLuint renderbuffer)
{
   (void) gles_glBindRenderbuffer(target, renderbuffer);
}
//
void (* gles_glBindFramebuffer)(GLenum target, GLuint framebuffer) = 0;
__attribute__((visibility("default")))
void glBindFramebuffer(
    GLenum target, 
    GLuint framebuffer)
{
   (void) gles_glBindFramebuffer(target, framebuffer);
}
//
void (* gles_glBindTexture)(GLenum target, GLuint texture) = 0;
__attribute__((visibility("default")))
void glBindTexture(
    GLenum target, 
    GLuint texture)
{
   (void) gles_glBindTexture(target, texture);
}
//
void (* gles_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = 0;
__attribute__((visibility("default")))
void glBlendFuncSeparate(
    GLenum sfactorRGB, 
    GLenum dfactorRGB, 
    GLenum sfactorAlpha, 
    GLenum dfactorAlpha)
{
   (void) gles_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
//
void (* gles_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeA) = 0;
__attribute__((visibility("default")))
void glBlendEquationSeparate(
    GLenum modeRGB, 
    GLenum modeA)
{
   (void) gles_glBlendEquationSeparate(modeRGB, modeA);
}
//
void (* gles_glBlendEquation)(GLenum mode) = 0;
__attribute__((visibility("default")))
void glBlendEquation(
    GLenum mode)
{
   (void) gles_glBlendEquation(mode);
}
//
void (* gles_glBlendFunc)(GLenum sfactor, GLenum dfactor) = 0;
__attribute__((visibility("default")))
void glBlendFunc(
    GLenum sfactor, 
    GLenum dfactor)
{
   (void) gles_glBlendFunc(sfactor, dfactor);
}
//
void (* gles_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) = 0;
__attribute__((visibility("default")))
void glBufferSubData(
    GLenum target, 
    GLintptr offset, 
    GLsizeiptr size, 
    const GLvoid * data)
{
   (void) gles_glBufferSubData(target, offset, size, data);
}
//
void (* gles_glBufferData)(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) = 0;
__attribute__((visibility("default")))
void glBufferData(
    GLenum target, 
    GLsizeiptr size, 
    const GLvoid * data, 
    GLenum usage)
{
   (void) gles_glBufferData(target, size, data, usage);
}
//
GLenum (* gles_glCheckFramebufferStatus)(GLenum target) = 0;
__attribute__((visibility("default")))
GLenum glCheckFramebufferStatus(
    GLenum target)
{
   return gles_glCheckFramebufferStatus(target);
}
//
void (* gles_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = 0;
__attribute__((visibility("default")))
void glCopyTexImage2D(
    GLenum target, 
    GLint level, 
    GLenum internalformat, 
    GLint x, 
    GLint y, 
    GLsizei width, 
    GLsizei height, 
    GLint border)
{
   (void) gles_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
//
void (* gles_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = 0;
__attribute__((visibility("default")))
void glColorMask(
    GLboolean red, 
    GLboolean green, 
    GLboolean blue, 
    GLboolean alpha)
{
   (void) gles_glColorMask(red, green, blue, alpha);
}
//
void (* gles_glClearDepthf)(GLclampf depth) = 0;
__attribute__((visibility("default")))
void glClearDepthf(
    GLclampf depth)
{
   (void) gles_glClearDepthf(depth);
}
//
void (* gles_glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) = 0;
__attribute__((visibility("default")))
void glClearColor(
    GLclampf red, 
    GLclampf green, 
    GLclampf blue, 
    GLclampf alpha)
{
   (void) gles_glClearColor(red, green, blue, alpha);
}
//
void (* gles_glClearStencil)(GLint s) = 0;
__attribute__((visibility("default")))
void glClearStencil(
    GLint s)
{
   (void) gles_glClearStencil(s);
}
//
void (* gles_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) = 0;
__attribute__((visibility("default")))
void glCompressedTexImage2D(
    GLenum target, 
    GLint level, 
    GLenum internalformat, 
    GLsizei width, 
    GLsizei height, 
    GLint border, 
    GLsizei imageSize, 
    const GLvoid * data)
{
   (void) gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
//
void (* gles_glCompileShader)(GLuint shader) = 0;
__attribute__((visibility("default")))
void glCompileShader(
    GLuint shader)
{
   (void) gles_glCompileShader(shader);
}
//
void (* gles_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) = 0;
__attribute__((visibility("default")))
void glCompressedTexSubImage2D(
    GLenum target, 
    GLint level, 
    GLint xoffset, 
    GLint yoffset, 
    GLsizei width, 
    GLsizei height, 
    GLenum format, 
    GLsizei imageSize, 
    const GLvoid * data)
{
   (void) gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
//
void (* gles_glCullFace)(GLenum mode) = 0;
__attribute__((visibility("default")))
void glCullFace(
    GLenum mode)
{
   (void) gles_glCullFace(mode);
}
//
GLuint (* gles_glCreateProgram)() = 0;
__attribute__((visibility("default")))
GLuint glCreateProgram(
)
{
   return gles_glCreateProgram();
}
//
void (* gles_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = 0;
__attribute__((visibility("default")))
void glCopyTexSubImage2D(
    GLenum target, 
    GLint level, 
    GLint xoffset, 
    GLint yoffset, 
    GLint x, 
    GLint y, 
    GLsizei width, 
    GLsizei height)
{
   (void) gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
//
GLuint (* gles_glCreateShader)(GLenum type) = 0;
__attribute__((visibility("default")))
GLuint glCreateShader(
    GLenum type)
{
   return gles_glCreateShader(type);
}
//
void (* gles_glDeleteFramebuffers)(GLsizei n, const GLuint * framebuffers) = 0;
__attribute__((visibility("default")))
void glDeleteFramebuffers(
    GLsizei n, 
    const GLuint * framebuffers)
{
   (void) gles_glDeleteFramebuffers(n, framebuffers);
}
//
void (* gles_glDeleteBuffers)(GLsizei n, const GLuint * buffer) = 0;
__attribute__((visibility("default")))
void glDeleteBuffers(
    GLsizei n, 
    const GLuint * buffer)
{
   (void) gles_glDeleteBuffers(n, buffer);
}
//
void (* gles_glDeleteProgram)(GLuint program) = 0;
__attribute__((visibility("default")))
void glDeleteProgram(
    GLuint program)
{
   (void) gles_glDeleteProgram(program);
}
//
void (* gles_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = 0;
__attribute__((visibility("default")))
void glFramebufferTexture2D(
    GLenum target, 
    GLenum attachment, 
    GLenum textarget, 
    GLuint texture, 
    GLint level)
{
   (void) gles_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
//
void (* gles_glDisableVertexAttribArray)(GLuint index) = 0;
__attribute__((visibility("default")))
void glDisableVertexAttribArray(
    GLuint index)
{
   (void) gles_glDisableVertexAttribArray(index);
}
//
void (* gles_glDepthMask)(GLboolean flag) = 0;
__attribute__((visibility("default")))
void glDepthMask(
    GLboolean flag)
{
   (void) gles_glDepthMask(flag);
}
//
void (* gles_glDeleteTextures)(GLsizei n, const GLuint * textures) = 0;
__attribute__((visibility("default")))
void glDeleteTextures(
    GLsizei n, 
    const GLuint * textures)
{
   (void) gles_glDeleteTextures(n, textures);
}
//
void (* gles_glDeleteShader)(GLuint program) = 0;
__attribute__((visibility("default")))
void glDeleteShader(
    GLuint program)
{
   (void) gles_glDeleteShader(program);
}
//
void (* gles_glDepthFunc)(GLenum func) = 0;
__attribute__((visibility("default")))
void glDepthFunc(
    GLenum func)
{
   (void) gles_glDepthFunc(func);
}
//
void (* gles_glDetachShader)(GLuint program, GLuint shader) = 0;
__attribute__((visibility("default")))
void glDetachShader(
    GLuint program, 
    GLuint shader)
{
   (void) gles_glDetachShader(program, shader);
}
//
void (* gles_glDepthRangef)(GLclampf zNear, GLclampf zFar) = 0;
__attribute__((visibility("default")))
void glDepthRangef(
    GLclampf zNear, 
    GLclampf zFar)
{
   (void) gles_glDepthRangef(zNear, zFar);
}
//
void (* gles_glDisable)(GLenum cap) = 0;
__attribute__((visibility("default")))
void glDisable(
    GLenum cap)
{
   (void) gles_glDisable(cap);
}
//
void (* gles_glEnableVertexAttribArray)(GLuint index) = 0;
__attribute__((visibility("default")))
void glEnableVertexAttribArray(
    GLuint index)
{
   (void) gles_glEnableVertexAttribArray(index);
}
//
void (* gles_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) = 0;
__attribute__((visibility("default")))
void glDrawElements(
    GLenum mode, 
    GLsizei count, 
    GLenum type, 
    const GLvoid * indices)
{
   (void) gles_glDrawElements(mode, count, type, indices);
}
//
void (* gles_glDrawArrays)(GLenum mode, GLint first, GLsizei count) = 0;
__attribute__((visibility("default")))
void glDrawArrays(
    GLenum mode, 
    GLint first, 
    GLsizei count)
{
   (void) gles_glDrawArrays(mode, first, count);
}
//
void (* gles_glEnable)(GLenum cap) = 0;
__attribute__((visibility("default")))
void glEnable(
    GLenum cap)
{
   (void) gles_glEnable(cap);
}
//
void (* gles_glFlush)() = 0;
__attribute__((visibility("default")))
void glFlush(
)
{
   (void) gles_glFlush();
}
//
void (* gles_glFinish)() = 0;
__attribute__((visibility("default")))
void glFinish(
)
{
   (void) gles_glFinish();
}
//
void (* gles_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = 0;
__attribute__((visibility("default")))
void glFramebufferRenderbuffer(
    GLenum target, 
    GLenum attachment, 
    GLenum renderbuffertarget, 
    GLuint renderbuffer)
{
   (void) gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
//
void (* gles_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) = 0;
__attribute__((visibility("default")))
void glGetActiveUniform(
    GLuint program, 
    GLuint index, 
    GLsizei bufSize, 
    GLsizei * length, 
    GLint * size, 
    GLenum * type, 
    GLchar * name)
{
   (void) gles_glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
//
void (* gles_glGenRenderbuffers)(GLsizei n, GLuint * renderbuffers) = 0;
__attribute__((visibility("default")))
void glGenRenderbuffers(
    GLsizei n, 
    GLuint * renderbuffers)
{
   (void) gles_glGenRenderbuffers(n, renderbuffers);
}
//
void (* gles_glGenBuffers)(GLsizei n, GLuint * buffer) = 0;
__attribute__((visibility("default")))
void glGenBuffers(
    GLsizei n, 
    GLuint * buffer)
{
   (void) gles_glGenBuffers(n, buffer);
}
//
void (* gles_glFrontFace)(GLenum mode) = 0;
__attribute__((visibility("default")))
void glFrontFace(
    GLenum mode)
{
   (void) gles_glFrontFace(mode);
}
//
void (* gles_glGenFramebuffers)(GLsizei n, GLuint * framebuffers) = 0;
__attribute__((visibility("default")))
void glGenFramebuffers(
    GLsizei n, 
    GLuint * framebuffers)
{
   (void) gles_glGenFramebuffers(n, framebuffers);
}
//
void (* gles_glGenerateMipmap)(GLenum target) = 0;
__attribute__((visibility("default")))
void glGenerateMipmap(
    GLenum target)
{
   (void) gles_glGenerateMipmap(target);
}
//
void (* gles_glGenTextures)(GLsizei n, GLuint * textures) = 0;
__attribute__((visibility("default")))
void glGenTextures(
    GLsizei n, 
    GLuint * textures)
{
   (void) gles_glGenTextures(n, textures);
}
//
void (* gles_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) = 0;
__attribute__((visibility("default")))
void glGetActiveAttrib(
    GLuint program, 
    GLuint index, 
    GLsizei bufSize, 
    GLsizei * length, 
    GLint * size, 
    GLenum * type, 
    GLchar * name)
{
   (void) gles_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
//
void (* gles_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetBufferParameteriv(
    GLenum target, 
    GLenum pname, 
    GLint * params)
{
   (void) gles_glGetBufferParameteriv(target, pname, params);
}
//
GLint (* gles_glGetAttribLocation)(GLuint program, const GLchar * name) = 0;
__attribute__((visibility("default")))
GLint glGetAttribLocation(
    GLuint program, 
    const GLchar * name)
{
   return gles_glGetAttribLocation(program, name);
}
//
void (* gles_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) = 0;
__attribute__((visibility("default")))
void glGetAttachedShaders(
    GLuint program, 
    GLsizei maxCount, 
    GLsizei * count, 
    GLuint * obj)
{
   (void) gles_glGetAttachedShaders(program, maxCount, count, obj);
}
//
void (* gles_glGetBooleanv)(GLenum pname, GLboolean * params) = 0;
__attribute__((visibility("default")))
void glGetBooleanv(
    GLenum pname, 
    GLboolean * params)
{
   (void) gles_glGetBooleanv(pname, params);
}
//
void (* gles_glGetFloatv)(GLenum pname, GLfloat * params) = 0;
__attribute__((visibility("default")))
void glGetFloatv(
    GLenum pname, 
    GLfloat * params)
{
   (void) gles_glGetFloatv(pname, params);
}
//
GLenum (* gles_glGetError)() = 0;
__attribute__((visibility("default")))
GLenum glGetError(
)
{
   return gles_glGetError();
}
//
void (* gles_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetFramebufferAttachmentParameteriv(
    GLenum target, 
    GLenum attachment, 
    GLenum pname, 
    GLint * params)
{
   (void) gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
//
void (* gles_glSampleCoverage)(GLclampf value, GLboolean invert) = 0;
__attribute__((visibility("default")))
void glSampleCoverage(
    GLclampf value, 
    GLboolean invert)
{
   (void) gles_glSampleCoverage(value, invert);
}
//
void (* gles_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetVertexAttribiv(
    GLuint index, 
    GLenum pname, 
    GLint * params)
{
   (void) gles_glGetVertexAttribiv(index, pname, params);
}
//
const GLubyte * (* gles_glGetString)(GLenum name) = 0;
__attribute__((visibility("default")))
const GLubyte * glGetString(
    GLenum name)
{
   return gles_glGetString(name);
}
//
void (* gles_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) = 0;
__attribute__((visibility("default")))
void glGetShaderInfoLog(
    GLuint shader, 
    GLsizei bufSize, 
    GLsizei * length, 
    GLchar * infoLog)
{
   (void) gles_glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
//
void (* gles_glGetProgramiv)(GLuint program, GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetProgramiv(
    GLuint program, 
    GLenum pname, 
    GLint * params)
{
   (void) gles_glGetProgramiv(program, pname, params);
}
//
void (* gles_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) = 0;
__attribute__((visibility("default")))
void glGetProgramInfoLog(
    GLuint program, 
    GLsizei bufSize, 
    GLsizei * length, 
    GLchar * infoLog)
{
   (void) gles_glGetProgramInfoLog(program, bufSize, length, infoLog);
}
//
void (* gles_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetRenderbufferParameteriv(
    GLenum target, 
    GLenum pname, 
    GLint * params)
{
   (void) gles_glGetRenderbufferParameteriv(target, pname, params);
}
//
void (* gles_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) = 0;
__attribute__((visibility("default")))
void glGetShaderSource(
    GLuint shader, 
    GLsizei bufSize, 
    GLsizei * length, 
    GLchar * source)
{
   (void) gles_glGetShaderSource(shader, bufSize, length, source);
}
//
void (* gles_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) = 0;
__attribute__((visibility("default")))
void glGetShaderPrecisionFormat(
    GLenum shadertype, 
    GLenum precisiontype, 
    GLint * range, 
    GLint * precision)
{
   (void) gles_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
//
void (* gles_glGetShaderiv)(GLuint shader, GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetShaderiv(
    GLuint shader, 
    GLenum pname, 
    GLint * params)
{
   (void) gles_glGetShaderiv(shader, pname, params);
}
//
void (* gles_glGetUniformfv)(GLuint program, GLint location, GLfloat * params) = 0;
__attribute__((visibility("default")))
void glGetUniformfv(
    GLuint program, 
    GLint location, 
    GLfloat * params)
{
   (void) gles_glGetUniformfv(program, location, params);
}
//
void (* gles_glGetTexParameteriv)(GLenum target, GLenum pname, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetTexParameteriv(
    GLenum target, 
    GLenum pname, 
    GLint * params)
{
   (void) gles_glGetTexParameteriv(target, pname, params);
}
//
void (* gles_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat * params) = 0;
__attribute__((visibility("default")))
void glGetTexParameterfv(
    GLenum target, 
    GLenum pname, 
    GLfloat * params)
{
   (void) gles_glGetTexParameterfv(target, pname, params);
}
//
GLint (* gles_glGetUniformLocation)(GLuint program, const GLchar * name) = 0;
__attribute__((visibility("default")))
GLint glGetUniformLocation(
    GLuint program, 
    const GLchar * name)
{
   return gles_glGetUniformLocation(program, name);
}
//
void (* gles_glGetVertexAttribPointerv)(GLuint index, GLenum pname, GLvoid ** pointer) = 0;
__attribute__((visibility("default")))
void glGetVertexAttribPointerv(
    GLuint index, 
    GLenum pname, 
    GLvoid ** pointer)
{
   (void) gles_glGetVertexAttribPointerv(index, pname, pointer);
}
//
void (* gles_glGetUniformiv)(GLuint program, GLint location, GLint * params) = 0;
__attribute__((visibility("default")))
void glGetUniformiv(
    GLuint program, 
    GLint location, 
    GLint * params)
{
   (void) gles_glGetUniformiv(program, location, params);
}
//
void (* gles_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat * params) = 0;
__attribute__((visibility("default")))
void glGetVertexAttribfv(
    GLuint index, 
    GLenum pname, 
    GLfloat * params)
{
   (void) gles_glGetVertexAttribfv(index, pname, params);
}
//
GLboolean (* gles_glIsTexture)(GLuint texture) = 0;
__attribute__((visibility("default")))
GLboolean glIsTexture(
    GLuint texture)
{
   return gles_glIsTexture(texture);
}
//
GLboolean (* gles_glIsFramebuffer)(GLuint framebuffer) = 0;
__attribute__((visibility("default")))
GLboolean glIsFramebuffer(
    GLuint framebuffer)
{
   return gles_glIsFramebuffer(framebuffer);
}
//
GLboolean (* gles_glIsBuffer)(GLuint buffer) = 0;
__attribute__((visibility("default")))
GLboolean glIsBuffer(
    GLuint buffer)
{
   return gles_glIsBuffer(buffer);
}
//
void (* gles_glHint)(GLenum target, GLenum mode) = 0;
__attribute__((visibility("default")))
void glHint(
    GLenum target, 
    GLenum mode);
//
GLboolean (* gles_glIsEnabled)(GLenum cap) = 0;
__attribute__((visibility("default")))
GLboolean glIsEnabled(
    GLenum cap)
{
   return gles_glIsEnabled(cap);
}
//
GLboolean (* gles_glIsRenderbuffer)(GLuint renderbuffer) = 0;
__attribute__((visibility("default")))
GLboolean glIsRenderbuffer(
    GLuint renderbuffer)
{
   return gles_glIsRenderbuffer(renderbuffer);
}
//
GLboolean (* gles_glIsProgram)(GLuint program) = 0;
__attribute__((visibility("default")))
GLboolean glIsProgram(
    GLuint program)
{
   return gles_glIsProgram(program);
}
//
GLboolean (* gles_glIsShader)(GLuint shader) = 0;
__attribute__((visibility("default")))
GLboolean glIsShader(
    GLuint shader)
{
   return gles_glIsShader(shader);
}
//
void (* gles_glPolygonOffset)(GLfloat factor, GLfloat units) = 0;
__attribute__((visibility("default")))
void glPolygonOffset(
    GLfloat factor, 
    GLfloat units)
{
   (void) gles_glPolygonOffset(factor, units);
}
//
void (* gles_glLinkProgram)(GLuint program) = 0;
__attribute__((visibility("default")))
void glLinkProgram(
    GLuint program)
{
   (void) gles_glLinkProgram(program);
}
//
void (* gles_glLineWidth)(GLfloat width) = 0;
__attribute__((visibility("default")))
void glLineWidth(
    GLfloat width)
{
   (void) gles_glLineWidth(width);
}
//
void (* gles_glPixelStorei)(GLenum pname, GLint param) = 0;
__attribute__((visibility("default")))
void glPixelStorei(
    GLenum pname, 
    GLint param)
{
   (void) gles_glPixelStorei(pname, param);
}
//
void (* gles_glReleaseShaderCompiler)() = 0;
__attribute__((visibility("default")))
void glReleaseShaderCompiler(
)
{
   (void) gles_glReleaseShaderCompiler();
}
//
void (* gles_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) = 0;
__attribute__((visibility("default")))
void glReadPixels(
    GLint x, 
    GLint y, 
    GLsizei width, 
    GLsizei height, 
    GLenum format, 
    GLenum type, 
    GLvoid * pixels)
{
   (void) gles_glReadPixels(x, y, width, height, format, type, pixels);
}
//
void (* gles_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = 0;
__attribute__((visibility("default")))
void glRenderbufferStorage(
    GLenum target, 
    GLenum internalformat, 
    GLsizei width, 
    GLsizei height)
{
   (void) gles_glRenderbufferStorage(target, internalformat, width, height);
}
//
void (* gles_glUniform1f)(GLint location, GLfloat v0) = 0;
__attribute__((visibility("default")))
void glUniform1f(
    GLint location, 
    GLfloat v0)
{
   (void) gles_glUniform1f(location, v0);
}
//
void (* gles_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = 0;
__attribute__((visibility("default")))
void glStencilOp(
    GLenum fail, 
    GLenum zfail, 
    GLenum zpass)
{
   (void) gles_glStencilOp(fail, zfail, zpass);
}
//
void (* gles_glStencilFunc)(GLenum func, GLint ref, GLuint mask) = 0;
__attribute__((visibility("default")))
void glStencilFunc(
    GLenum func, 
    GLint ref, 
    GLuint mask)
{
   (void) gles_glStencilFunc(func, ref, mask);
}
//
void (* gles_glShaderBinary)(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) = 0;
__attribute__((visibility("default")))
void glShaderBinary(
    GLsizei n, 
    const GLuint * shaders, 
    GLenum binaryformat, 
    const GLvoid * binary, 
    GLsizei length)
{
   (void) gles_glShaderBinary(n, shaders, binaryformat, binary, length);
}
//
void (* gles_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) = 0;
__attribute__((visibility("default")))
void glScissor(
    GLint x, 
    GLint y, 
    GLsizei width, 
    GLsizei height)
{
   (void) gles_glScissor(x, y, width, height);
}
//
void (* gles_glShaderSource)(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) = 0;
__attribute__((visibility("default")))
void glShaderSource(
    GLuint shader, 
    GLsizei count, 
    const GLchar * const * string, 
    const GLint * length);
//
void (* gles_glStencilMask)(GLuint mask) = 0;
__attribute__((visibility("default")))
void glStencilMask(
    GLuint mask)
{
   (void) gles_glStencilMask(mask);
}
//
void (* gles_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) = 0;
__attribute__((visibility("default")))
void glStencilFuncSeparate(
    GLenum face, 
    GLenum func, 
    GLint ref, 
    GLuint mask)
{
   (void) gles_glStencilFuncSeparate(face, func, ref, mask);
}
//
void (* gles_glStencilMaskSeparate)(GLenum face, GLuint mask) = 0;
__attribute__((visibility("default")))
void glStencilMaskSeparate(
    GLenum face, 
    GLuint mask)
{
   (void) gles_glStencilMaskSeparate(face, mask);
}
//
void (* gles_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat * params) = 0;
__attribute__((visibility("default")))
void glTexParameterfv(
    GLenum target, 
    GLenum pname, 
    const GLfloat * params)
{
   (void) gles_glTexParameterfv(target, pname, params);
}
//
void (* gles_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) = 0;
__attribute__((visibility("default")))
void glTexImage2D(
    GLenum target, 
    GLint level, 
    GLint internalformat, 
    GLsizei width, 
    GLsizei height, 
    GLint border, 
    GLenum format, 
    GLenum type, 
    const GLvoid * pixels)
{
   (void) gles_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
//
void (* gles_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) = 0;
__attribute__((visibility("default")))
void glStencilOpSeparate(
    GLenum face, 
    GLenum sfail, 
    GLenum zfail, 
    GLenum zpass)
{
   (void) gles_glStencilOpSeparate(face, sfail, zfail, zpass);
}
//
void (* gles_glTexParameterf)(GLenum target, GLenum pname, GLfloat param) = 0;
__attribute__((visibility("default")))
void glTexParameterf(
    GLenum target, 
    GLenum pname, 
    GLfloat param)
{
   (void) gles_glTexParameterf(target, pname, param);
}
//
void (* gles_glTexParameteriv)(GLenum target, GLenum pname, const GLint * params) = 0;
__attribute__((visibility("default")))
void glTexParameteriv(
    GLenum target, 
    GLenum pname, 
    const GLint * params)
{
   (void) gles_glTexParameteriv(target, pname, params);
}
//
void (* gles_glTexParameteri)(GLenum target, GLenum pname, GLint param) = 0;
__attribute__((visibility("default")))
void glTexParameteri(
    GLenum target, 
    GLenum pname, 
    GLint param)
{
   (void) gles_glTexParameteri(target, pname, param);
}
//
void (* gles_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) = 0;
__attribute__((visibility("default")))
void glTexSubImage2D(
    GLenum target, 
    GLint level, 
    GLint xoffset, 
    GLint yoffset, 
    GLsizei width, 
    GLsizei height, 
    GLenum format, 
    GLenum type, 
    const GLvoid * pixels)
{
   (void) gles_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
//
void (* gles_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = 0;
__attribute__((visibility("default")))
void glUniform3f(
    GLint location, 
    GLfloat v0, 
    GLfloat v1, 
    GLfloat v2)
{
   (void) gles_glUniform3f(location, v0, v1, v2);
}
//
void (* gles_glUniform2f)(GLint location, GLfloat v0, GLfloat v1) = 0;
__attribute__((visibility("default")))
void glUniform2f(
    GLint location, 
    GLfloat v0, 
    GLfloat v1)
{
   (void) gles_glUniform2f(location, v0, v1);
}
//
void (* gles_glUniform1i)(GLint location, GLint v0) = 0;
__attribute__((visibility("default")))
void glUniform1i(
    GLint location, 
    GLint v0)
{
   (void) gles_glUniform1i(location, v0);
}
//
void (* gles_glUniform1fv)(GLint location, GLsizei count, const GLfloat * value) = 0;
__attribute__((visibility("default")))
void glUniform1fv(
    GLint location, 
    GLsizei count, 
    const GLfloat * value)
{
   (void) gles_glUniform1fv(location, count, value);
}
//
void (* gles_glUniform1iv)(GLint location, GLsizei count, const GLint * value) = 0;
__attribute__((visibility("default")))
void glUniform1iv(
    GLint location, 
    GLsizei count, 
    const GLint * value)
{
   (void) gles_glUniform1iv(location, count, value);
}
//
void (* gles_glUniform2i)(GLint location, GLint v0, GLint v1) = 0;
__attribute__((visibility("default")))
void glUniform2i(
    GLint location, 
    GLint v0, 
    GLint v1)
{
   (void) gles_glUniform2i(location, v0, v1);
}
//
void (* gles_glUniform2fv)(GLint location, GLsizei count, const GLfloat * value) = 0;
__attribute__((visibility("default")))
void glUniform2fv(
    GLint location, 
    GLsizei count, 
    const GLfloat * value)
{
   (void) gles_glUniform2fv(location, count, value);
}
//
void (* gles_glUniform2iv)(GLint location, GLsizei count, const GLint * value) = 0;
__attribute__((visibility("default")))
void glUniform2iv(
    GLint location, 
    GLsizei count, 
    const GLint * value)
{
   (void) gles_glUniform2iv(location, count, value);
}
//
void (* gles_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = 0;
__attribute__((visibility("default")))
void glUniformMatrix2fv(
    GLint location, 
    GLsizei count, 
    GLboolean transpose, 
    const GLfloat * value)
{
   (void) gles_glUniformMatrix2fv(location, count, transpose, value);
}
//
void (* gles_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = 0;
__attribute__((visibility("default")))
void glUniform4f(
    GLint location, 
    GLfloat v0, 
    GLfloat v1, 
    GLfloat v2, 
    GLfloat v3)
{
   (void) gles_glUniform4f(location, v0, v1, v2, v3);
}
//
void (* gles_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2) = 0;
__attribute__((visibility("default")))
void glUniform3i(
    GLint location, 
    GLint v0, 
    GLint v1, 
    GLint v2)
{
   (void) gles_glUniform3i(location, v0, v1, v2);
}
//
void (* gles_glUniform3fv)(GLint location, GLsizei count, const GLfloat * value) = 0;
__attribute__((visibility("default")))
void glUniform3fv(
    GLint location, 
    GLsizei count, 
    const GLfloat * value)
{
   (void) gles_glUniform3fv(location, count, value);
}
//
void (* gles_glUniform3iv)(GLint location, GLsizei count, const GLint * value) = 0;
__attribute__((visibility("default")))
void glUniform3iv(
    GLint location, 
    GLsizei count, 
    const GLint * value)
{
   (void) gles_glUniform3iv(location, count, value);
}
//
void (* gles_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = 0;
__attribute__((visibility("default")))
void glUniform4i(
    GLint location, 
    GLint v0, 
    GLint v1, 
    GLint v2, 
    GLint v3)
{
   (void) gles_glUniform4i(location, v0, v1, v2, v3);
}
//
void (* gles_glUniform4fv)(GLint location, GLsizei count, const GLfloat * value) = 0;
__attribute__((visibility("default")))
void glUniform4fv(
    GLint location, 
    GLsizei count, 
    const GLfloat * value)
{
   (void) gles_glUniform4fv(location, count, value);
}
//
void (* gles_glUniform4iv)(GLint location, GLsizei count, const GLint * value) = 0;
__attribute__((visibility("default")))
void glUniform4iv(
    GLint location, 
    GLsizei count, 
    const GLint * value)
{
   (void) gles_glUniform4iv(location, count, value);
}
//
void (* gles_glValidateProgram)(GLuint program) = 0;
__attribute__((visibility("default")))
void glValidateProgram(
    GLuint program)
{
   (void) gles_glValidateProgram(program);
}
//
void (* gles_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = 0;
__attribute__((visibility("default")))
void glUniformMatrix4fv(
    GLint location, 
    GLsizei count, 
    GLboolean transpose, 
    const GLfloat * value)
{
   (void) gles_glUniformMatrix4fv(location, count, transpose, value);
}
//
void (* gles_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = 0;
__attribute__((visibility("default")))
void glUniformMatrix3fv(
    GLint location, 
    GLsizei count, 
    GLboolean transpose, 
    const GLfloat * value)
{
   (void) gles_glUniformMatrix3fv(location, count, transpose, value);
}
//
void (* gles_glUseProgram)(GLuint program) = 0;
__attribute__((visibility("default")))
void glUseProgram(
    GLuint program)
{
   (void) gles_glUseProgram(program);
}
//
void (* gles_glVertexAttrib2fv)(GLuint index, const GLfloat * v) = 0;
__attribute__((visibility("default")))
void glVertexAttrib2fv(
    GLuint index, 
    const GLfloat * v)
{
   (void) gles_glVertexAttrib2fv(index, v);
}
//
void (* gles_glVertexAttrib1fv)(GLuint index, const GLfloat * v) = 0;
__attribute__((visibility("default")))
void glVertexAttrib1fv(
    GLuint index, 
    const GLfloat * v)
{
   (void) gles_glVertexAttrib1fv(index, v);
}
//
void (* gles_glVertexAttrib1f)(GLuint index, GLfloat x) = 0;
__attribute__((visibility("default")))
void glVertexAttrib1f(
    GLuint index, 
    GLfloat x)
{
   (void) gles_glVertexAttrib1f(index, x);
}
//
void (* gles_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y) = 0;
__attribute__((visibility("default")))
void glVertexAttrib2f(
    GLuint index, 
    GLfloat x, 
    GLfloat y)
{
   (void) gles_glVertexAttrib2f(index, x, y);
}
//
void (* gles_glVertexAttrib3fv)(GLuint index, const GLfloat * v) = 0;
__attribute__((visibility("default")))
void glVertexAttrib3fv(
    GLuint index, 
    const GLfloat * v)
{
   (void) gles_glVertexAttrib3fv(index, v);
}
//
void (* gles_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = 0;
__attribute__((visibility("default")))
void glVertexAttrib3f(
    GLuint index, 
    GLfloat x, 
    GLfloat y, 
    GLfloat z)
{
   (void) gles_glVertexAttrib3f(index, x, y, z);
}
//
void (* gles_glVertexAttrib4fv)(GLuint index, const GLfloat * v) = 0;
__attribute__((visibility("default")))
void glVertexAttrib4fv(
    GLuint index, 
    const GLfloat * v)
{
   (void) gles_glVertexAttrib4fv(index, v);
}
//
void (* gles_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = 0;
__attribute__((visibility("default")))
void glVertexAttrib4f(
    GLuint index, 
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLfloat w)
{
   (void) gles_glVertexAttrib4f(index, x, y, z, w);
}
//
void (* gles_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) = 0;
__attribute__((visibility("default")))
void glVertexAttribPointer(
    GLuint index, 
    GLint size, 
    GLenum type, 
    GLboolean normalized, 
    GLsizei stride, 
    const GLvoid * pointer)
{
   (void) gles_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
//
void (* gles_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) = 0;
__attribute__((visibility("default")))
void glViewport(
    GLint x, 
    GLint y, 
    GLsizei width, 
    GLsizei height)
{
   (void) gles_glViewport(x, y, width, height);
}
// ----------------------------------------------------------------- //
#define LINK(name) gles_##name = dlsym(GLES, #name)
extern void Init(void);

#include <dlfcn.h>
void* GLES = 0;
__attribute__((visibility("default")))
void initialize_gl2es() {
   GLES = dlopen("libGLESv2.so", RTLD_LAZY);

   LINK(glGetIntegerv);
   LINK(glDeleteRenderbuffers);
   LINK(glClear);
   LINK(glBlendColor);
   LINK(glBindBuffer);
   LINK(glAttachShader);
   LINK(glActiveTexture);
   LINK(glBindAttribLocation);
   LINK(glBindRenderbuffer);
   LINK(glBindFramebuffer);
   LINK(glBindTexture);
   LINK(glBlendFuncSeparate);
   LINK(glBlendEquationSeparate);
   LINK(glBlendEquation);
   LINK(glBlendFunc);
   LINK(glBufferSubData);
   LINK(glBufferData);
   LINK(glCheckFramebufferStatus);
   LINK(glCopyTexImage2D);
   LINK(glColorMask);
   LINK(glClearDepthf);
   LINK(glClearColor);
   LINK(glClearStencil);
   LINK(glCompressedTexImage2D);
   LINK(glCompileShader);
   LINK(glCompressedTexSubImage2D);
   LINK(glCullFace);
   LINK(glCreateProgram);
   LINK(glCopyTexSubImage2D);
   LINK(glCreateShader);
   LINK(glDeleteFramebuffers);
   LINK(glDeleteBuffers);
   LINK(glDeleteProgram);
   LINK(glFramebufferTexture2D);
   LINK(glDisableVertexAttribArray);
   LINK(glDepthMask);
   LINK(glDeleteTextures);
   LINK(glDeleteShader);
   LINK(glDepthFunc);
   LINK(glDetachShader);
   LINK(glDepthRangef);
   LINK(glDisable);
   LINK(glEnableVertexAttribArray);
   LINK(glDrawElements);
   LINK(glDrawArrays);
   LINK(glEnable);
   LINK(glFlush);
   LINK(glFinish);
   LINK(glFramebufferRenderbuffer);
   LINK(glGetActiveUniform);
   LINK(glGenRenderbuffers);
   LINK(glGenBuffers);
   LINK(glFrontFace);
   LINK(glGenFramebuffers);
   LINK(glGenerateMipmap);
   LINK(glGenTextures);
   LINK(glGetActiveAttrib);
   LINK(glGetBufferParameteriv);
   LINK(glGetAttribLocation);
   LINK(glGetAttachedShaders);
   LINK(glGetBooleanv);
   LINK(glGetFloatv);
   LINK(glGetError);
   LINK(glGetFramebufferAttachmentParameteriv);
   LINK(glSampleCoverage);
   LINK(glGetVertexAttribiv);
   LINK(glGetString);
   LINK(glGetShaderInfoLog);
   LINK(glGetProgramiv);
   LINK(glGetProgramInfoLog);
   LINK(glGetRenderbufferParameteriv);
   LINK(glGetShaderSource);
   LINK(glGetShaderPrecisionFormat);
   LINK(glGetShaderiv);
   LINK(glGetUniformfv);
   LINK(glGetTexParameteriv);
   LINK(glGetTexParameterfv);
   LINK(glGetUniformLocation);
   LINK(glGetVertexAttribPointerv);
   LINK(glGetUniformiv);
   LINK(glGetVertexAttribfv);
   LINK(glIsTexture);
   LINK(glIsFramebuffer);
   LINK(glIsBuffer);
   LINK(glHint);
   LINK(glIsEnabled);
   LINK(glIsRenderbuffer);
   LINK(glIsProgram);
   LINK(glIsShader);
   LINK(glPolygonOffset);
   LINK(glLinkProgram);
   LINK(glLineWidth);
   LINK(glPixelStorei);
   LINK(glReleaseShaderCompiler);
   LINK(glReadPixels);
   LINK(glRenderbufferStorage);
   LINK(glUniform1f);
   LINK(glStencilOp);
   LINK(glStencilFunc);
   LINK(glShaderBinary);
   LINK(glScissor);
   LINK(glShaderSource);
   LINK(glStencilMask);
   LINK(glStencilFuncSeparate);
   LINK(glStencilMaskSeparate);
   LINK(glTexParameterfv);
   LINK(glTexImage2D);
   LINK(glStencilOpSeparate);
   LINK(glTexParameterf);
   LINK(glTexParameteriv);
   LINK(glTexParameteri);
   LINK(glTexSubImage2D);
   LINK(glUniform3f);
   LINK(glUniform2f);
   LINK(glUniform1i);
   LINK(glUniform1fv);
   LINK(glUniform1iv);
   LINK(glUniform2i);
   LINK(glUniform2fv);
   LINK(glUniform2iv);
   LINK(glUniformMatrix2fv);
   LINK(glUniform4f);
   LINK(glUniform3i);
   LINK(glUniform3fv);
   LINK(glUniform3iv);
   LINK(glUniform4i);
   LINK(glUniform4fv);
   LINK(glUniform4iv);
   LINK(glValidateProgram);
   LINK(glUniformMatrix4fv);
   LINK(glUniformMatrix3fv);
   LINK(glUseProgram);
   LINK(glVertexAttrib2fv);
   LINK(glVertexAttrib1fv);
   LINK(glVertexAttrib1f);
   LINK(glVertexAttrib2f);
   LINK(glVertexAttrib3fv);
   LINK(glVertexAttrib3f);
   LINK(glVertexAttrib4fv);
   LINK(glVertexAttrib4f);
   LINK(glVertexAttribPointer);
   LINK(glViewport);
   Init();
}
