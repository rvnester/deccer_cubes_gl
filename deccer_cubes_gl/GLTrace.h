#pragma once

#ifndef __glad_h_
#include <glad/glad.h>
#endif

#include <functional>

#define MYLOG(M, ...) std::printf(M "\n", ##__VA_ARGS__)

#define HOOK_GL_FUNC(func) tracer._##func = glad_##func;

void HookGLTrace();

using glTracer_glCullFace = std::function<void(GLenum)>;
void glCullFace_Traced(GLenum mode);
#define glCullFace glCullFace_Traced
using glTracer_glFrontFace = std::function<void(GLenum)>;
void glFrontFace_Traced(GLenum mode);
#define glFrontFace glFrontFace_Traced
using glTracer_glHint = std::function<void(GLenum, GLenum)>;
void glHint_Traced(GLenum target, GLenum mode);
#define glHint glHint_Traced
using glTracer_glLineWidth = std::function<void(GLfloat)>;
void glLineWidth_Traced(GLfloat width);
#define glLineWidth glLineWidth_Traced
using glTracer_glPointSize = std::function<void(GLfloat)>;
void glPointSize_Traced(GLfloat size);
#define glPointSize glPointSize_Traced
using glTracer_glPolygonMode = std::function<void(GLenum, GLenum)>;
void glPolygonMode_Traced(GLenum face, GLenum mode);
#define glPolygonMode glPolygonMode_Traced
using glTracer_glScissor = std::function<void(GLint, GLint, GLsizei, GLsizei)>;
void glScissor_Traced(GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissor glScissor_Traced
using glTracer_glTexParameterf = std::function<void(GLenum, GLenum, GLfloat)>;
void glTexParameterf_Traced(GLenum target, GLenum pname, GLfloat param);
#define glTexParameterf glTexParameterf_Traced
using glTracer_glTexParameterfv = std::function<void(GLenum, GLenum, const GLfloat*)>;
void glTexParameterfv_Traced(GLenum target, GLenum pname, const GLfloat* params);
#define glTexParameterfv glTexParameterfv_Traced
using glTracer_glTexParameteri = std::function<void(GLenum, GLenum, GLint)>;
void glTexParameteri_Traced(GLenum target, GLenum pname, GLint param);
#define glTexParameteri glTexParameteri_Traced
using glTracer_glTexParameteriv = std::function<void(GLenum, GLenum, const GLint*)>;
void glTexParameteriv_Traced(GLenum target, GLenum pname, const GLint* params);
#define glTexParameteriv glTexParameteriv_Traced
using glTracer_glTexImage1D = std::function<void(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void*)>;
void glTexImage1D_Traced(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
#define glTexImage1D glTexImage1D_Traced
using glTracer_glTexImage2D = std::function<void(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*)>;
void glTexImage2D_Traced(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
#define glTexImage2D glTexImage2D_Traced
using glTracer_glDrawBuffer = std::function<void(GLenum)>;
void glDrawBuffer_Traced(GLenum buf);
#define glDrawBuffer glDrawBuffer_Traced
using glTracer_glClear = std::function<void(GLbitfield)>;
void glClear_Traced(GLbitfield mask);
#define glClear glClear_Traced
using glTracer_glClearColor = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glClearColor_Traced(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearColor glClearColor_Traced
using glTracer_glClearStencil = std::function<void(GLint)>;
void glClearStencil_Traced(GLint s);
#define glClearStencil glClearStencil_Traced
using glTracer_glClearDepth = std::function<void(GLdouble)>;
void glClearDepth_Traced(GLdouble depth);
#define glClearDepth glClearDepth_Traced
using glTracer_glStencilMask = std::function<void(GLuint)>;
void glStencilMask_Traced(GLuint mask);
#define glStencilMask glStencilMask_Traced
using glTracer_glColorMask = std::function<void(GLboolean, GLboolean, GLboolean, GLboolean)>;
void glColorMask_Traced(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glColorMask glColorMask_Traced
using glTracer_glDepthMask = std::function<void(GLboolean)>;
void glDepthMask_Traced(GLboolean flag);
#define glDepthMask glDepthMask_Traced
using glTracer_glDisable = std::function<void(GLenum)>;
void glDisable_Traced(GLenum cap);
#define glDisable glDisable_Traced
using glTracer_glEnable = std::function<void(GLenum)>;
void glEnable_Traced(GLenum cap);
#define glEnable glEnable_Traced
using glTracer_glFinish = std::function<void()>;
void glFinish_Traced();
#define glFinish glFinish_Traced
using glTracer_glFlush = std::function<void()>;
void glFlush_Traced();
#define glFlush glFlush_Traced
using glTracer_glBlendFunc = std::function<void(GLenum, GLenum)>;
void glBlendFunc_Traced(GLenum sfactor, GLenum dfactor);
#define glBlendFunc glBlendFunc_Traced
using glTracer_glLogicOp = std::function<void(GLenum)>;
void glLogicOp_Traced(GLenum opcode);
#define glLogicOp glLogicOp_Traced
using glTracer_glStencilFunc = std::function<void(GLenum, GLint, GLuint)>;
void glStencilFunc_Traced(GLenum func, GLint ref, GLuint mask);
#define glStencilFunc glStencilFunc_Traced
using glTracer_glStencilOp = std::function<void(GLenum, GLenum, GLenum)>;
void glStencilOp_Traced(GLenum fail, GLenum zfail, GLenum zpass);
#define glStencilOp glStencilOp_Traced
using glTracer_glDepthFunc = std::function<void(GLenum)>;
void glDepthFunc_Traced(GLenum func);
#define glDepthFunc glDepthFunc_Traced
using glTracer_glPixelStoref = std::function<void(GLenum, GLfloat)>;
void glPixelStoref_Traced(GLenum pname, GLfloat param);
#define glPixelStoref glPixelStoref_Traced
using glTracer_glPixelStorei = std::function<void(GLenum, GLint)>;
void glPixelStorei_Traced(GLenum pname, GLint param);
#define glPixelStorei glPixelStorei_Traced
using glTracer_glReadBuffer = std::function<void(GLenum)>;
void glReadBuffer_Traced(GLenum src);
#define glReadBuffer glReadBuffer_Traced
using glTracer_glReadPixels = std::function<void(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void*)>;
void glReadPixels_Traced(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
#define glReadPixels glReadPixels_Traced
using glTracer_glGetBooleanv = std::function<void(GLenum, GLboolean*)>;
void glGetBooleanv_Traced(GLenum pname, GLboolean* data);
#define glGetBooleanv glGetBooleanv_Traced
using glTracer_glGetDoublev = std::function<void(GLenum, GLdouble*)>;
void glGetDoublev_Traced(GLenum pname, GLdouble* data);
#define glGetDoublev glGetDoublev_Traced
using glTracer_glGetError = std::function<GLenum()>;
GLenum glGetError_Traced();
#define glGetError glGetError_Traced
using glTracer_glGetFloatv = std::function<void(GLenum, GLfloat*)>;
void glGetFloatv_Traced(GLenum pname, GLfloat* data);
#define glGetFloatv glGetFloatv_Traced
using glTracer_glGetIntegerv = std::function<void(GLenum, GLint*)>;
void glGetIntegerv_Traced(GLenum pname, GLint* data);
#define glGetIntegerv glGetIntegerv_Traced
using glTracer_glGetString = std::function<const GLubyte*(GLenum)>;
const GLubyte* glGetString_Traced(GLenum name);
#define glGetString glGetString_Traced
using glTracer_glGetTexImage = std::function<void(GLenum, GLint, GLenum, GLenum, void*)>;
void glGetTexImage_Traced(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
#define glGetTexImage glGetTexImage_Traced
using glTracer_glGetTexParameterfv = std::function<void(GLenum, GLenum, GLfloat*)>;
void glGetTexParameterfv_Traced(GLenum target, GLenum pname, GLfloat* params);
#define glGetTexParameterfv glGetTexParameterfv_Traced
using glTracer_glGetTexParameteriv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetTexParameteriv_Traced(GLenum target, GLenum pname, GLint* params);
#define glGetTexParameteriv glGetTexParameteriv_Traced
using glTracer_glGetTexLevelParameterfv = std::function<void(GLenum, GLint, GLenum, GLfloat*)>;
void glGetTexLevelParameterfv_Traced(GLenum target, GLint level, GLenum pname, GLfloat* params);
#define glGetTexLevelParameterfv glGetTexLevelParameterfv_Traced
using glTracer_glGetTexLevelParameteriv = std::function<void(GLenum, GLint, GLenum, GLint*)>;
void glGetTexLevelParameteriv_Traced(GLenum target, GLint level, GLenum pname, GLint* params);
#define glGetTexLevelParameteriv glGetTexLevelParameteriv_Traced
using glTracer_glIsEnabled = std::function<GLboolean(GLenum)>;
GLboolean glIsEnabled_Traced(GLenum cap);
#define glIsEnabled glIsEnabled_Traced
using glTracer_glDepthRange = std::function<void(GLdouble, GLdouble)>;
void glDepthRange_Traced(GLdouble n, GLdouble f);
#define glDepthRange glDepthRange_Traced
using glTracer_glViewport = std::function<void(GLint, GLint, GLsizei, GLsizei)>;
void glViewport_Traced(GLint x, GLint y, GLsizei width, GLsizei height);
#define glViewport glViewport_Traced
using glTracer_glNewList = std::function<void(GLuint, GLenum)>;
void glNewList_Traced(GLuint list, GLenum mode);
#define glNewList glNewList_Traced
using glTracer_glEndList = std::function<void()>;
void glEndList_Traced();
#define glEndList glEndList_Traced
using glTracer_glCallList = std::function<void(GLuint)>;
void glCallList_Traced(GLuint list);
#define glCallList glCallList_Traced
using glTracer_glCallLists = std::function<void(GLsizei, GLenum, const void*)>;
void glCallLists_Traced(GLsizei n, GLenum type, const void* lists);
#define glCallLists glCallLists_Traced
using glTracer_glDeleteLists = std::function<void(GLuint, GLsizei)>;
void glDeleteLists_Traced(GLuint list, GLsizei range);
#define glDeleteLists glDeleteLists_Traced
using glTracer_glGenLists = std::function<GLuint(GLsizei)>;
GLuint glGenLists_Traced(GLsizei range);
#define glGenLists glGenLists_Traced
using glTracer_glListBase = std::function<void(GLuint)>;
void glListBase_Traced(GLuint base);
#define glListBase glListBase_Traced
using glTracer_glBegin = std::function<void(GLenum)>;
void glBegin_Traced(GLenum mode);
#define glBegin glBegin_Traced
using glTracer_glBitmap = std::function<void(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte*)>;
void glBitmap_Traced(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte* bitmap);
#define glBitmap glBitmap_Traced
using glTracer_glColor3b = std::function<void(GLbyte, GLbyte, GLbyte)>;
void glColor3b_Traced(GLbyte red, GLbyte green, GLbyte blue);
#define glColor3b glColor3b_Traced
using glTracer_glColor3bv = std::function<void(const GLbyte*)>;
void glColor3bv_Traced(const GLbyte* v);
#define glColor3bv glColor3bv_Traced
using glTracer_glColor3d = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glColor3d_Traced(GLdouble red, GLdouble green, GLdouble blue);
#define glColor3d glColor3d_Traced
using glTracer_glColor3dv = std::function<void(const GLdouble*)>;
void glColor3dv_Traced(const GLdouble* v);
#define glColor3dv glColor3dv_Traced
using glTracer_glColor3f = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glColor3f_Traced(GLfloat red, GLfloat green, GLfloat blue);
#define glColor3f glColor3f_Traced
using glTracer_glColor3fv = std::function<void(const GLfloat*)>;
void glColor3fv_Traced(const GLfloat* v);
#define glColor3fv glColor3fv_Traced
using glTracer_glColor3i = std::function<void(GLint, GLint, GLint)>;
void glColor3i_Traced(GLint red, GLint green, GLint blue);
#define glColor3i glColor3i_Traced
using glTracer_glColor3iv = std::function<void(const GLint*)>;
void glColor3iv_Traced(const GLint* v);
#define glColor3iv glColor3iv_Traced
using glTracer_glColor3s = std::function<void(GLshort, GLshort, GLshort)>;
void glColor3s_Traced(GLshort red, GLshort green, GLshort blue);
#define glColor3s glColor3s_Traced
using glTracer_glColor3sv = std::function<void(const GLshort*)>;
void glColor3sv_Traced(const GLshort* v);
#define glColor3sv glColor3sv_Traced
using glTracer_glColor3ub = std::function<void(GLubyte, GLubyte, GLubyte)>;
void glColor3ub_Traced(GLubyte red, GLubyte green, GLubyte blue);
#define glColor3ub glColor3ub_Traced
using glTracer_glColor3ubv = std::function<void(const GLubyte*)>;
void glColor3ubv_Traced(const GLubyte* v);
#define glColor3ubv glColor3ubv_Traced
using glTracer_glColor3ui = std::function<void(GLuint, GLuint, GLuint)>;
void glColor3ui_Traced(GLuint red, GLuint green, GLuint blue);
#define glColor3ui glColor3ui_Traced
using glTracer_glColor3uiv = std::function<void(const GLuint*)>;
void glColor3uiv_Traced(const GLuint* v);
#define glColor3uiv glColor3uiv_Traced
using glTracer_glColor3us = std::function<void(GLushort, GLushort, GLushort)>;
void glColor3us_Traced(GLushort red, GLushort green, GLushort blue);
#define glColor3us glColor3us_Traced
using glTracer_glColor3usv = std::function<void(const GLushort*)>;
void glColor3usv_Traced(const GLushort* v);
#define glColor3usv glColor3usv_Traced
using glTracer_glColor4b = std::function<void(GLbyte, GLbyte, GLbyte, GLbyte)>;
void glColor4b_Traced(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
#define glColor4b glColor4b_Traced
using glTracer_glColor4bv = std::function<void(const GLbyte*)>;
void glColor4bv_Traced(const GLbyte* v);
#define glColor4bv glColor4bv_Traced
using glTracer_glColor4d = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble)>;
void glColor4d_Traced(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
#define glColor4d glColor4d_Traced
using glTracer_glColor4dv = std::function<void(const GLdouble*)>;
void glColor4dv_Traced(const GLdouble* v);
#define glColor4dv glColor4dv_Traced
using glTracer_glColor4f = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glColor4f_Traced(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glColor4f glColor4f_Traced
using glTracer_glColor4fv = std::function<void(const GLfloat*)>;
void glColor4fv_Traced(const GLfloat* v);
#define glColor4fv glColor4fv_Traced
using glTracer_glColor4i = std::function<void(GLint, GLint, GLint, GLint)>;
void glColor4i_Traced(GLint red, GLint green, GLint blue, GLint alpha);
#define glColor4i glColor4i_Traced
using glTracer_glColor4iv = std::function<void(const GLint*)>;
void glColor4iv_Traced(const GLint* v);
#define glColor4iv glColor4iv_Traced
using glTracer_glColor4s = std::function<void(GLshort, GLshort, GLshort, GLshort)>;
void glColor4s_Traced(GLshort red, GLshort green, GLshort blue, GLshort alpha);
#define glColor4s glColor4s_Traced
using glTracer_glColor4sv = std::function<void(const GLshort*)>;
void glColor4sv_Traced(const GLshort* v);
#define glColor4sv glColor4sv_Traced
using glTracer_glColor4ub = std::function<void(GLubyte, GLubyte, GLubyte, GLubyte)>;
void glColor4ub_Traced(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
#define glColor4ub glColor4ub_Traced
using glTracer_glColor4ubv = std::function<void(const GLubyte*)>;
void glColor4ubv_Traced(const GLubyte* v);
#define glColor4ubv glColor4ubv_Traced
using glTracer_glColor4ui = std::function<void(GLuint, GLuint, GLuint, GLuint)>;
void glColor4ui_Traced(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#define glColor4ui glColor4ui_Traced
using glTracer_glColor4uiv = std::function<void(const GLuint*)>;
void glColor4uiv_Traced(const GLuint* v);
#define glColor4uiv glColor4uiv_Traced
using glTracer_glColor4us = std::function<void(GLushort, GLushort, GLushort, GLushort)>;
void glColor4us_Traced(GLushort red, GLushort green, GLushort blue, GLushort alpha);
#define glColor4us glColor4us_Traced
using glTracer_glColor4usv = std::function<void(const GLushort*)>;
void glColor4usv_Traced(const GLushort* v);
#define glColor4usv glColor4usv_Traced
using glTracer_glEdgeFlag = std::function<void(GLboolean)>;
void glEdgeFlag_Traced(GLboolean flag);
#define glEdgeFlag glEdgeFlag_Traced
using glTracer_glEdgeFlagv = std::function<void(const GLboolean*)>;
void glEdgeFlagv_Traced(const GLboolean* flag);
#define glEdgeFlagv glEdgeFlagv_Traced
using glTracer_glEnd = std::function<void()>;
void glEnd_Traced();
#define glEnd glEnd_Traced
using glTracer_glIndexd = std::function<void(GLdouble)>;
void glIndexd_Traced(GLdouble c);
#define glIndexd glIndexd_Traced
using glTracer_glIndexdv = std::function<void(const GLdouble*)>;
void glIndexdv_Traced(const GLdouble* c);
#define glIndexdv glIndexdv_Traced
using glTracer_glIndexf = std::function<void(GLfloat)>;
void glIndexf_Traced(GLfloat c);
#define glIndexf glIndexf_Traced
using glTracer_glIndexfv = std::function<void(const GLfloat*)>;
void glIndexfv_Traced(const GLfloat* c);
#define glIndexfv glIndexfv_Traced
using glTracer_glIndexi = std::function<void(GLint)>;
void glIndexi_Traced(GLint c);
#define glIndexi glIndexi_Traced
using glTracer_glIndexiv = std::function<void(const GLint*)>;
void glIndexiv_Traced(const GLint* c);
#define glIndexiv glIndexiv_Traced
using glTracer_glIndexs = std::function<void(GLshort)>;
void glIndexs_Traced(GLshort c);
#define glIndexs glIndexs_Traced
using glTracer_glIndexsv = std::function<void(const GLshort*)>;
void glIndexsv_Traced(const GLshort* c);
#define glIndexsv glIndexsv_Traced
using glTracer_glNormal3b = std::function<void(GLbyte, GLbyte, GLbyte)>;
void glNormal3b_Traced(GLbyte nx, GLbyte ny, GLbyte nz);
#define glNormal3b glNormal3b_Traced
using glTracer_glNormal3bv = std::function<void(const GLbyte*)>;
void glNormal3bv_Traced(const GLbyte* v);
#define glNormal3bv glNormal3bv_Traced
using glTracer_glNormal3d = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glNormal3d_Traced(GLdouble nx, GLdouble ny, GLdouble nz);
#define glNormal3d glNormal3d_Traced
using glTracer_glNormal3dv = std::function<void(const GLdouble*)>;
void glNormal3dv_Traced(const GLdouble* v);
#define glNormal3dv glNormal3dv_Traced
using glTracer_glNormal3f = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glNormal3f_Traced(GLfloat nx, GLfloat ny, GLfloat nz);
#define glNormal3f glNormal3f_Traced
using glTracer_glNormal3fv = std::function<void(const GLfloat*)>;
void glNormal3fv_Traced(const GLfloat* v);
#define glNormal3fv glNormal3fv_Traced
using glTracer_glNormal3i = std::function<void(GLint, GLint, GLint)>;
void glNormal3i_Traced(GLint nx, GLint ny, GLint nz);
#define glNormal3i glNormal3i_Traced
using glTracer_glNormal3iv = std::function<void(const GLint*)>;
void glNormal3iv_Traced(const GLint* v);
#define glNormal3iv glNormal3iv_Traced
using glTracer_glNormal3s = std::function<void(GLshort, GLshort, GLshort)>;
void glNormal3s_Traced(GLshort nx, GLshort ny, GLshort nz);
#define glNormal3s glNormal3s_Traced
using glTracer_glNormal3sv = std::function<void(const GLshort*)>;
void glNormal3sv_Traced(const GLshort* v);
#define glNormal3sv glNormal3sv_Traced
using glTracer_glRasterPos2d = std::function<void(GLdouble, GLdouble)>;
void glRasterPos2d_Traced(GLdouble x, GLdouble y);
#define glRasterPos2d glRasterPos2d_Traced
using glTracer_glRasterPos2dv = std::function<void(const GLdouble*)>;
void glRasterPos2dv_Traced(const GLdouble* v);
#define glRasterPos2dv glRasterPos2dv_Traced
using glTracer_glRasterPos2f = std::function<void(GLfloat, GLfloat)>;
void glRasterPos2f_Traced(GLfloat x, GLfloat y);
#define glRasterPos2f glRasterPos2f_Traced
using glTracer_glRasterPos2fv = std::function<void(const GLfloat*)>;
void glRasterPos2fv_Traced(const GLfloat* v);
#define glRasterPos2fv glRasterPos2fv_Traced
using glTracer_glRasterPos2i = std::function<void(GLint, GLint)>;
void glRasterPos2i_Traced(GLint x, GLint y);
#define glRasterPos2i glRasterPos2i_Traced
using glTracer_glRasterPos2iv = std::function<void(const GLint*)>;
void glRasterPos2iv_Traced(const GLint* v);
#define glRasterPos2iv glRasterPos2iv_Traced
using glTracer_glRasterPos2s = std::function<void(GLshort, GLshort)>;
void glRasterPos2s_Traced(GLshort x, GLshort y);
#define glRasterPos2s glRasterPos2s_Traced
using glTracer_glRasterPos2sv = std::function<void(const GLshort*)>;
void glRasterPos2sv_Traced(const GLshort* v);
#define glRasterPos2sv glRasterPos2sv_Traced
using glTracer_glRasterPos3d = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glRasterPos3d_Traced(GLdouble x, GLdouble y, GLdouble z);
#define glRasterPos3d glRasterPos3d_Traced
using glTracer_glRasterPos3dv = std::function<void(const GLdouble*)>;
void glRasterPos3dv_Traced(const GLdouble* v);
#define glRasterPos3dv glRasterPos3dv_Traced
using glTracer_glRasterPos3f = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glRasterPos3f_Traced(GLfloat x, GLfloat y, GLfloat z);
#define glRasterPos3f glRasterPos3f_Traced
using glTracer_glRasterPos3fv = std::function<void(const GLfloat*)>;
void glRasterPos3fv_Traced(const GLfloat* v);
#define glRasterPos3fv glRasterPos3fv_Traced
using glTracer_glRasterPos3i = std::function<void(GLint, GLint, GLint)>;
void glRasterPos3i_Traced(GLint x, GLint y, GLint z);
#define glRasterPos3i glRasterPos3i_Traced
using glTracer_glRasterPos3iv = std::function<void(const GLint*)>;
void glRasterPos3iv_Traced(const GLint* v);
#define glRasterPos3iv glRasterPos3iv_Traced
using glTracer_glRasterPos3s = std::function<void(GLshort, GLshort, GLshort)>;
void glRasterPos3s_Traced(GLshort x, GLshort y, GLshort z);
#define glRasterPos3s glRasterPos3s_Traced
using glTracer_glRasterPos3sv = std::function<void(const GLshort*)>;
void glRasterPos3sv_Traced(const GLshort* v);
#define glRasterPos3sv glRasterPos3sv_Traced
using glTracer_glRasterPos4d = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble)>;
void glRasterPos4d_Traced(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glRasterPos4d glRasterPos4d_Traced
using glTracer_glRasterPos4dv = std::function<void(const GLdouble*)>;
void glRasterPos4dv_Traced(const GLdouble* v);
#define glRasterPos4dv glRasterPos4dv_Traced
using glTracer_glRasterPos4f = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glRasterPos4f_Traced(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glRasterPos4f glRasterPos4f_Traced
using glTracer_glRasterPos4fv = std::function<void(const GLfloat*)>;
void glRasterPos4fv_Traced(const GLfloat* v);
#define glRasterPos4fv glRasterPos4fv_Traced
using glTracer_glRasterPos4i = std::function<void(GLint, GLint, GLint, GLint)>;
void glRasterPos4i_Traced(GLint x, GLint y, GLint z, GLint w);
#define glRasterPos4i glRasterPos4i_Traced
using glTracer_glRasterPos4iv = std::function<void(const GLint*)>;
void glRasterPos4iv_Traced(const GLint* v);
#define glRasterPos4iv glRasterPos4iv_Traced
using glTracer_glRasterPos4s = std::function<void(GLshort, GLshort, GLshort, GLshort)>;
void glRasterPos4s_Traced(GLshort x, GLshort y, GLshort z, GLshort w);
#define glRasterPos4s glRasterPos4s_Traced
using glTracer_glRasterPos4sv = std::function<void(const GLshort*)>;
void glRasterPos4sv_Traced(const GLshort* v);
#define glRasterPos4sv glRasterPos4sv_Traced
using glTracer_glRectd = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble)>;
void glRectd_Traced(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
#define glRectd glRectd_Traced
using glTracer_glRectdv = std::function<void(const GLdouble*, const GLdouble*)>;
void glRectdv_Traced(const GLdouble* v1, const GLdouble* v2);
#define glRectdv glRectdv_Traced
using glTracer_glRectf = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glRectf_Traced(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
#define glRectf glRectf_Traced
using glTracer_glRectfv = std::function<void(const GLfloat*, const GLfloat*)>;
void glRectfv_Traced(const GLfloat* v1, const GLfloat* v2);
#define glRectfv glRectfv_Traced
using glTracer_glRecti = std::function<void(GLint, GLint, GLint, GLint)>;
void glRecti_Traced(GLint x1, GLint y1, GLint x2, GLint y2);
#define glRecti glRecti_Traced
using glTracer_glRectiv = std::function<void(const GLint*, const GLint*)>;
void glRectiv_Traced(const GLint* v1, const GLint* v2);
#define glRectiv glRectiv_Traced
using glTracer_glRects = std::function<void(GLshort, GLshort, GLshort, GLshort)>;
void glRects_Traced(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
#define glRects glRects_Traced
using glTracer_glRectsv = std::function<void(const GLshort*, const GLshort*)>;
void glRectsv_Traced(const GLshort* v1, const GLshort* v2);
#define glRectsv glRectsv_Traced
using glTracer_glTexCoord1d = std::function<void(GLdouble)>;
void glTexCoord1d_Traced(GLdouble s);
#define glTexCoord1d glTexCoord1d_Traced
using glTracer_glTexCoord1dv = std::function<void(const GLdouble*)>;
void glTexCoord1dv_Traced(const GLdouble* v);
#define glTexCoord1dv glTexCoord1dv_Traced
using glTracer_glTexCoord1f = std::function<void(GLfloat)>;
void glTexCoord1f_Traced(GLfloat s);
#define glTexCoord1f glTexCoord1f_Traced
using glTracer_glTexCoord1fv = std::function<void(const GLfloat*)>;
void glTexCoord1fv_Traced(const GLfloat* v);
#define glTexCoord1fv glTexCoord1fv_Traced
using glTracer_glTexCoord1i = std::function<void(GLint)>;
void glTexCoord1i_Traced(GLint s);
#define glTexCoord1i glTexCoord1i_Traced
using glTracer_glTexCoord1iv = std::function<void(const GLint*)>;
void glTexCoord1iv_Traced(const GLint* v);
#define glTexCoord1iv glTexCoord1iv_Traced
using glTracer_glTexCoord1s = std::function<void(GLshort)>;
void glTexCoord1s_Traced(GLshort s);
#define glTexCoord1s glTexCoord1s_Traced
using glTracer_glTexCoord1sv = std::function<void(const GLshort*)>;
void glTexCoord1sv_Traced(const GLshort* v);
#define glTexCoord1sv glTexCoord1sv_Traced
using glTracer_glTexCoord2d = std::function<void(GLdouble, GLdouble)>;
void glTexCoord2d_Traced(GLdouble s, GLdouble t);
#define glTexCoord2d glTexCoord2d_Traced
using glTracer_glTexCoord2dv = std::function<void(const GLdouble*)>;
void glTexCoord2dv_Traced(const GLdouble* v);
#define glTexCoord2dv glTexCoord2dv_Traced
using glTracer_glTexCoord2f = std::function<void(GLfloat, GLfloat)>;
void glTexCoord2f_Traced(GLfloat s, GLfloat t);
#define glTexCoord2f glTexCoord2f_Traced
using glTracer_glTexCoord2fv = std::function<void(const GLfloat*)>;
void glTexCoord2fv_Traced(const GLfloat* v);
#define glTexCoord2fv glTexCoord2fv_Traced
using glTracer_glTexCoord2i = std::function<void(GLint, GLint)>;
void glTexCoord2i_Traced(GLint s, GLint t);
#define glTexCoord2i glTexCoord2i_Traced
using glTracer_glTexCoord2iv = std::function<void(const GLint*)>;
void glTexCoord2iv_Traced(const GLint* v);
#define glTexCoord2iv glTexCoord2iv_Traced
using glTracer_glTexCoord2s = std::function<void(GLshort, GLshort)>;
void glTexCoord2s_Traced(GLshort s, GLshort t);
#define glTexCoord2s glTexCoord2s_Traced
using glTracer_glTexCoord2sv = std::function<void(const GLshort*)>;
void glTexCoord2sv_Traced(const GLshort* v);
#define glTexCoord2sv glTexCoord2sv_Traced
using glTracer_glTexCoord3d = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glTexCoord3d_Traced(GLdouble s, GLdouble t, GLdouble r);
#define glTexCoord3d glTexCoord3d_Traced
using glTracer_glTexCoord3dv = std::function<void(const GLdouble*)>;
void glTexCoord3dv_Traced(const GLdouble* v);
#define glTexCoord3dv glTexCoord3dv_Traced
using glTracer_glTexCoord3f = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glTexCoord3f_Traced(GLfloat s, GLfloat t, GLfloat r);
#define glTexCoord3f glTexCoord3f_Traced
using glTracer_glTexCoord3fv = std::function<void(const GLfloat*)>;
void glTexCoord3fv_Traced(const GLfloat* v);
#define glTexCoord3fv glTexCoord3fv_Traced
using glTracer_glTexCoord3i = std::function<void(GLint, GLint, GLint)>;
void glTexCoord3i_Traced(GLint s, GLint t, GLint r);
#define glTexCoord3i glTexCoord3i_Traced
using glTracer_glTexCoord3iv = std::function<void(const GLint*)>;
void glTexCoord3iv_Traced(const GLint* v);
#define glTexCoord3iv glTexCoord3iv_Traced
using glTracer_glTexCoord3s = std::function<void(GLshort, GLshort, GLshort)>;
void glTexCoord3s_Traced(GLshort s, GLshort t, GLshort r);
#define glTexCoord3s glTexCoord3s_Traced
using glTracer_glTexCoord3sv = std::function<void(const GLshort*)>;
void glTexCoord3sv_Traced(const GLshort* v);
#define glTexCoord3sv glTexCoord3sv_Traced
using glTracer_glTexCoord4d = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble)>;
void glTexCoord4d_Traced(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glTexCoord4d glTexCoord4d_Traced
using glTracer_glTexCoord4dv = std::function<void(const GLdouble*)>;
void glTexCoord4dv_Traced(const GLdouble* v);
#define glTexCoord4dv glTexCoord4dv_Traced
using glTracer_glTexCoord4f = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glTexCoord4f_Traced(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glTexCoord4f glTexCoord4f_Traced
using glTracer_glTexCoord4fv = std::function<void(const GLfloat*)>;
void glTexCoord4fv_Traced(const GLfloat* v);
#define glTexCoord4fv glTexCoord4fv_Traced
using glTracer_glTexCoord4i = std::function<void(GLint, GLint, GLint, GLint)>;
void glTexCoord4i_Traced(GLint s, GLint t, GLint r, GLint q);
#define glTexCoord4i glTexCoord4i_Traced
using glTracer_glTexCoord4iv = std::function<void(const GLint*)>;
void glTexCoord4iv_Traced(const GLint* v);
#define glTexCoord4iv glTexCoord4iv_Traced
using glTracer_glTexCoord4s = std::function<void(GLshort, GLshort, GLshort, GLshort)>;
void glTexCoord4s_Traced(GLshort s, GLshort t, GLshort r, GLshort q);
#define glTexCoord4s glTexCoord4s_Traced
using glTracer_glTexCoord4sv = std::function<void(const GLshort*)>;
void glTexCoord4sv_Traced(const GLshort* v);
#define glTexCoord4sv glTexCoord4sv_Traced
using glTracer_glVertex2d = std::function<void(GLdouble, GLdouble)>;
void glVertex2d_Traced(GLdouble x, GLdouble y);
#define glVertex2d glVertex2d_Traced
using glTracer_glVertex2dv = std::function<void(const GLdouble*)>;
void glVertex2dv_Traced(const GLdouble* v);
#define glVertex2dv glVertex2dv_Traced
using glTracer_glVertex2f = std::function<void(GLfloat, GLfloat)>;
void glVertex2f_Traced(GLfloat x, GLfloat y);
#define glVertex2f glVertex2f_Traced
using glTracer_glVertex2fv = std::function<void(const GLfloat*)>;
void glVertex2fv_Traced(const GLfloat* v);
#define glVertex2fv glVertex2fv_Traced
using glTracer_glVertex2i = std::function<void(GLint, GLint)>;
void glVertex2i_Traced(GLint x, GLint y);
#define glVertex2i glVertex2i_Traced
using glTracer_glVertex2iv = std::function<void(const GLint*)>;
void glVertex2iv_Traced(const GLint* v);
#define glVertex2iv glVertex2iv_Traced
using glTracer_glVertex2s = std::function<void(GLshort, GLshort)>;
void glVertex2s_Traced(GLshort x, GLshort y);
#define glVertex2s glVertex2s_Traced
using glTracer_glVertex2sv = std::function<void(const GLshort*)>;
void glVertex2sv_Traced(const GLshort* v);
#define glVertex2sv glVertex2sv_Traced
using glTracer_glVertex3d = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glVertex3d_Traced(GLdouble x, GLdouble y, GLdouble z);
#define glVertex3d glVertex3d_Traced
using glTracer_glVertex3dv = std::function<void(const GLdouble*)>;
void glVertex3dv_Traced(const GLdouble* v);
#define glVertex3dv glVertex3dv_Traced
using glTracer_glVertex3f = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glVertex3f_Traced(GLfloat x, GLfloat y, GLfloat z);
#define glVertex3f glVertex3f_Traced
using glTracer_glVertex3fv = std::function<void(const GLfloat*)>;
void glVertex3fv_Traced(const GLfloat* v);
#define glVertex3fv glVertex3fv_Traced
using glTracer_glVertex3i = std::function<void(GLint, GLint, GLint)>;
void glVertex3i_Traced(GLint x, GLint y, GLint z);
#define glVertex3i glVertex3i_Traced
using glTracer_glVertex3iv = std::function<void(const GLint*)>;
void glVertex3iv_Traced(const GLint* v);
#define glVertex3iv glVertex3iv_Traced
using glTracer_glVertex3s = std::function<void(GLshort, GLshort, GLshort)>;
void glVertex3s_Traced(GLshort x, GLshort y, GLshort z);
#define glVertex3s glVertex3s_Traced
using glTracer_glVertex3sv = std::function<void(const GLshort*)>;
void glVertex3sv_Traced(const GLshort* v);
#define glVertex3sv glVertex3sv_Traced
using glTracer_glVertex4d = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble)>;
void glVertex4d_Traced(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertex4d glVertex4d_Traced
using glTracer_glVertex4dv = std::function<void(const GLdouble*)>;
void glVertex4dv_Traced(const GLdouble* v);
#define glVertex4dv glVertex4dv_Traced
using glTracer_glVertex4f = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glVertex4f_Traced(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertex4f glVertex4f_Traced
using glTracer_glVertex4fv = std::function<void(const GLfloat*)>;
void glVertex4fv_Traced(const GLfloat* v);
#define glVertex4fv glVertex4fv_Traced
using glTracer_glVertex4i = std::function<void(GLint, GLint, GLint, GLint)>;
void glVertex4i_Traced(GLint x, GLint y, GLint z, GLint w);
#define glVertex4i glVertex4i_Traced
using glTracer_glVertex4iv = std::function<void(const GLint*)>;
void glVertex4iv_Traced(const GLint* v);
#define glVertex4iv glVertex4iv_Traced
using glTracer_glVertex4s = std::function<void(GLshort, GLshort, GLshort, GLshort)>;
void glVertex4s_Traced(GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertex4s glVertex4s_Traced
using glTracer_glVertex4sv = std::function<void(const GLshort*)>;
void glVertex4sv_Traced(const GLshort* v);
#define glVertex4sv glVertex4sv_Traced
using glTracer_glClipPlane = std::function<void(GLenum, const GLdouble*)>;
void glClipPlane_Traced(GLenum plane, const GLdouble* equation);
#define glClipPlane glClipPlane_Traced
using glTracer_glColorMaterial = std::function<void(GLenum, GLenum)>;
void glColorMaterial_Traced(GLenum face, GLenum mode);
#define glColorMaterial glColorMaterial_Traced
using glTracer_glFogf = std::function<void(GLenum, GLfloat)>;
void glFogf_Traced(GLenum pname, GLfloat param);
#define glFogf glFogf_Traced
using glTracer_glFogfv = std::function<void(GLenum, const GLfloat*)>;
void glFogfv_Traced(GLenum pname, const GLfloat* params);
#define glFogfv glFogfv_Traced
using glTracer_glFogi = std::function<void(GLenum, GLint)>;
void glFogi_Traced(GLenum pname, GLint param);
#define glFogi glFogi_Traced
using glTracer_glFogiv = std::function<void(GLenum, const GLint*)>;
void glFogiv_Traced(GLenum pname, const GLint* params);
#define glFogiv glFogiv_Traced
using glTracer_glLightf = std::function<void(GLenum, GLenum, GLfloat)>;
void glLightf_Traced(GLenum light, GLenum pname, GLfloat param);
#define glLightf glLightf_Traced
using glTracer_glLightfv = std::function<void(GLenum, GLenum, const GLfloat*)>;
void glLightfv_Traced(GLenum light, GLenum pname, const GLfloat* params);
#define glLightfv glLightfv_Traced
using glTracer_glLighti = std::function<void(GLenum, GLenum, GLint)>;
void glLighti_Traced(GLenum light, GLenum pname, GLint param);
#define glLighti glLighti_Traced
using glTracer_glLightiv = std::function<void(GLenum, GLenum, const GLint*)>;
void glLightiv_Traced(GLenum light, GLenum pname, const GLint* params);
#define glLightiv glLightiv_Traced
using glTracer_glLightModelf = std::function<void(GLenum, GLfloat)>;
void glLightModelf_Traced(GLenum pname, GLfloat param);
#define glLightModelf glLightModelf_Traced
using glTracer_glLightModelfv = std::function<void(GLenum, const GLfloat*)>;
void glLightModelfv_Traced(GLenum pname, const GLfloat* params);
#define glLightModelfv glLightModelfv_Traced
using glTracer_glLightModeli = std::function<void(GLenum, GLint)>;
void glLightModeli_Traced(GLenum pname, GLint param);
#define glLightModeli glLightModeli_Traced
using glTracer_glLightModeliv = std::function<void(GLenum, const GLint*)>;
void glLightModeliv_Traced(GLenum pname, const GLint* params);
#define glLightModeliv glLightModeliv_Traced
using glTracer_glLineStipple = std::function<void(GLint, GLushort)>;
void glLineStipple_Traced(GLint factor, GLushort pattern);
#define glLineStipple glLineStipple_Traced
using glTracer_glMaterialf = std::function<void(GLenum, GLenum, GLfloat)>;
void glMaterialf_Traced(GLenum face, GLenum pname, GLfloat param);
#define glMaterialf glMaterialf_Traced
using glTracer_glMaterialfv = std::function<void(GLenum, GLenum, const GLfloat*)>;
void glMaterialfv_Traced(GLenum face, GLenum pname, const GLfloat* params);
#define glMaterialfv glMaterialfv_Traced
using glTracer_glMateriali = std::function<void(GLenum, GLenum, GLint)>;
void glMateriali_Traced(GLenum face, GLenum pname, GLint param);
#define glMateriali glMateriali_Traced
using glTracer_glMaterialiv = std::function<void(GLenum, GLenum, const GLint*)>;
void glMaterialiv_Traced(GLenum face, GLenum pname, const GLint* params);
#define glMaterialiv glMaterialiv_Traced
using glTracer_glPolygonStipple = std::function<void(const GLubyte*)>;
void glPolygonStipple_Traced(const GLubyte* mask);
#define glPolygonStipple glPolygonStipple_Traced
using glTracer_glShadeModel = std::function<void(GLenum)>;
void glShadeModel_Traced(GLenum mode);
#define glShadeModel glShadeModel_Traced
using glTracer_glTexEnvf = std::function<void(GLenum, GLenum, GLfloat)>;
void glTexEnvf_Traced(GLenum target, GLenum pname, GLfloat param);
#define glTexEnvf glTexEnvf_Traced
using glTracer_glTexEnvfv = std::function<void(GLenum, GLenum, const GLfloat*)>;
void glTexEnvfv_Traced(GLenum target, GLenum pname, const GLfloat* params);
#define glTexEnvfv glTexEnvfv_Traced
using glTracer_glTexEnvi = std::function<void(GLenum, GLenum, GLint)>;
void glTexEnvi_Traced(GLenum target, GLenum pname, GLint param);
#define glTexEnvi glTexEnvi_Traced
using glTracer_glTexEnviv = std::function<void(GLenum, GLenum, const GLint*)>;
void glTexEnviv_Traced(GLenum target, GLenum pname, const GLint* params);
#define glTexEnviv glTexEnviv_Traced
using glTracer_glTexGend = std::function<void(GLenum, GLenum, GLdouble)>;
void glTexGend_Traced(GLenum coord, GLenum pname, GLdouble param);
#define glTexGend glTexGend_Traced
using glTracer_glTexGendv = std::function<void(GLenum, GLenum, const GLdouble*)>;
void glTexGendv_Traced(GLenum coord, GLenum pname, const GLdouble* params);
#define glTexGendv glTexGendv_Traced
using glTracer_glTexGenf = std::function<void(GLenum, GLenum, GLfloat)>;
void glTexGenf_Traced(GLenum coord, GLenum pname, GLfloat param);
#define glTexGenf glTexGenf_Traced
using glTracer_glTexGenfv = std::function<void(GLenum, GLenum, const GLfloat*)>;
void glTexGenfv_Traced(GLenum coord, GLenum pname, const GLfloat* params);
#define glTexGenfv glTexGenfv_Traced
using glTracer_glTexGeni = std::function<void(GLenum, GLenum, GLint)>;
void glTexGeni_Traced(GLenum coord, GLenum pname, GLint param);
#define glTexGeni glTexGeni_Traced
using glTracer_glTexGeniv = std::function<void(GLenum, GLenum, const GLint*)>;
void glTexGeniv_Traced(GLenum coord, GLenum pname, const GLint* params);
#define glTexGeniv glTexGeniv_Traced
using glTracer_glFeedbackBuffer = std::function<void(GLsizei, GLenum, GLfloat*)>;
void glFeedbackBuffer_Traced(GLsizei size, GLenum type, GLfloat* buffer);
#define glFeedbackBuffer glFeedbackBuffer_Traced
using glTracer_glSelectBuffer = std::function<void(GLsizei, GLuint*)>;
void glSelectBuffer_Traced(GLsizei size, GLuint* buffer);
#define glSelectBuffer glSelectBuffer_Traced
using glTracer_glRenderMode = std::function<GLint(GLenum)>;
GLint glRenderMode_Traced(GLenum mode);
#define glRenderMode glRenderMode_Traced
using glTracer_glInitNames = std::function<void()>;
void glInitNames_Traced();
#define glInitNames glInitNames_Traced
using glTracer_glLoadName = std::function<void(GLuint)>;
void glLoadName_Traced(GLuint name);
#define glLoadName glLoadName_Traced
using glTracer_glPassThrough = std::function<void(GLfloat)>;
void glPassThrough_Traced(GLfloat token);
#define glPassThrough glPassThrough_Traced
using glTracer_glPopName = std::function<void()>;
void glPopName_Traced();
#define glPopName glPopName_Traced
using glTracer_glPushName = std::function<void(GLuint)>;
void glPushName_Traced(GLuint name);
#define glPushName glPushName_Traced
using glTracer_glClearAccum = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glClearAccum_Traced(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearAccum glClearAccum_Traced
using glTracer_glClearIndex = std::function<void(GLfloat)>;
void glClearIndex_Traced(GLfloat c);
#define glClearIndex glClearIndex_Traced
using glTracer_glIndexMask = std::function<void(GLuint)>;
void glIndexMask_Traced(GLuint mask);
#define glIndexMask glIndexMask_Traced
using glTracer_glAccum = std::function<void(GLenum, GLfloat)>;
void glAccum_Traced(GLenum op, GLfloat value);
#define glAccum glAccum_Traced
using glTracer_glPopAttrib = std::function<void()>;
void glPopAttrib_Traced();
#define glPopAttrib glPopAttrib_Traced
using glTracer_glPushAttrib = std::function<void(GLbitfield)>;
void glPushAttrib_Traced(GLbitfield mask);
#define glPushAttrib glPushAttrib_Traced
using glTracer_glMap1d = std::function<void(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble*)>;
void glMap1d_Traced(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points);
#define glMap1d glMap1d_Traced
using glTracer_glMap1f = std::function<void(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat*)>;
void glMap1f_Traced(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points);
#define glMap1f glMap1f_Traced
using glTracer_glMap2d = std::function<void(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble*)>;
void glMap2d_Traced(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points);
#define glMap2d glMap2d_Traced
using glTracer_glMap2f = std::function<void(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat*)>;
void glMap2f_Traced(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points);
#define glMap2f glMap2f_Traced
using glTracer_glMapGrid1d = std::function<void(GLint, GLdouble, GLdouble)>;
void glMapGrid1d_Traced(GLint un, GLdouble u1, GLdouble u2);
#define glMapGrid1d glMapGrid1d_Traced
using glTracer_glMapGrid1f = std::function<void(GLint, GLfloat, GLfloat)>;
void glMapGrid1f_Traced(GLint un, GLfloat u1, GLfloat u2);
#define glMapGrid1f glMapGrid1f_Traced
using glTracer_glMapGrid2d = std::function<void(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble)>;
void glMapGrid2d_Traced(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
#define glMapGrid2d glMapGrid2d_Traced
using glTracer_glMapGrid2f = std::function<void(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat)>;
void glMapGrid2f_Traced(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
#define glMapGrid2f glMapGrid2f_Traced
using glTracer_glEvalCoord1d = std::function<void(GLdouble)>;
void glEvalCoord1d_Traced(GLdouble u);
#define glEvalCoord1d glEvalCoord1d_Traced
using glTracer_glEvalCoord1dv = std::function<void(const GLdouble*)>;
void glEvalCoord1dv_Traced(const GLdouble* u);
#define glEvalCoord1dv glEvalCoord1dv_Traced
using glTracer_glEvalCoord1f = std::function<void(GLfloat)>;
void glEvalCoord1f_Traced(GLfloat u);
#define glEvalCoord1f glEvalCoord1f_Traced
using glTracer_glEvalCoord1fv = std::function<void(const GLfloat*)>;
void glEvalCoord1fv_Traced(const GLfloat* u);
#define glEvalCoord1fv glEvalCoord1fv_Traced
using glTracer_glEvalCoord2d = std::function<void(GLdouble, GLdouble)>;
void glEvalCoord2d_Traced(GLdouble u, GLdouble v);
#define glEvalCoord2d glEvalCoord2d_Traced
using glTracer_glEvalCoord2dv = std::function<void(const GLdouble*)>;
void glEvalCoord2dv_Traced(const GLdouble* u);
#define glEvalCoord2dv glEvalCoord2dv_Traced
using glTracer_glEvalCoord2f = std::function<void(GLfloat, GLfloat)>;
void glEvalCoord2f_Traced(GLfloat u, GLfloat v);
#define glEvalCoord2f glEvalCoord2f_Traced
using glTracer_glEvalCoord2fv = std::function<void(const GLfloat*)>;
void glEvalCoord2fv_Traced(const GLfloat* u);
#define glEvalCoord2fv glEvalCoord2fv_Traced
using glTracer_glEvalMesh1 = std::function<void(GLenum, GLint, GLint)>;
void glEvalMesh1_Traced(GLenum mode, GLint i1, GLint i2);
#define glEvalMesh1 glEvalMesh1_Traced
using glTracer_glEvalPoint1 = std::function<void(GLint)>;
void glEvalPoint1_Traced(GLint i);
#define glEvalPoint1 glEvalPoint1_Traced
using glTracer_glEvalMesh2 = std::function<void(GLenum, GLint, GLint, GLint, GLint)>;
void glEvalMesh2_Traced(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
#define glEvalMesh2 glEvalMesh2_Traced
using glTracer_glEvalPoint2 = std::function<void(GLint, GLint)>;
void glEvalPoint2_Traced(GLint i, GLint j);
#define glEvalPoint2 glEvalPoint2_Traced
using glTracer_glAlphaFunc = std::function<void(GLenum, GLfloat)>;
void glAlphaFunc_Traced(GLenum func, GLfloat ref);
#define glAlphaFunc glAlphaFunc_Traced
using glTracer_glPixelZoom = std::function<void(GLfloat, GLfloat)>;
void glPixelZoom_Traced(GLfloat xfactor, GLfloat yfactor);
#define glPixelZoom glPixelZoom_Traced
using glTracer_glPixelTransferf = std::function<void(GLenum, GLfloat)>;
void glPixelTransferf_Traced(GLenum pname, GLfloat param);
#define glPixelTransferf glPixelTransferf_Traced
using glTracer_glPixelTransferi = std::function<void(GLenum, GLint)>;
void glPixelTransferi_Traced(GLenum pname, GLint param);
#define glPixelTransferi glPixelTransferi_Traced
using glTracer_glPixelMapfv = std::function<void(GLenum, GLsizei, const GLfloat*)>;
void glPixelMapfv_Traced(GLenum map, GLsizei mapsize, const GLfloat* values);
#define glPixelMapfv glPixelMapfv_Traced
using glTracer_glPixelMapuiv = std::function<void(GLenum, GLsizei, const GLuint*)>;
void glPixelMapuiv_Traced(GLenum map, GLsizei mapsize, const GLuint* values);
#define glPixelMapuiv glPixelMapuiv_Traced
using glTracer_glPixelMapusv = std::function<void(GLenum, GLsizei, const GLushort*)>;
void glPixelMapusv_Traced(GLenum map, GLsizei mapsize, const GLushort* values);
#define glPixelMapusv glPixelMapusv_Traced
using glTracer_glCopyPixels = std::function<void(GLint, GLint, GLsizei, GLsizei, GLenum)>;
void glCopyPixels_Traced(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
#define glCopyPixels glCopyPixels_Traced
using glTracer_glDrawPixels = std::function<void(GLsizei, GLsizei, GLenum, GLenum, const void*)>;
void glDrawPixels_Traced(GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
#define glDrawPixels glDrawPixels_Traced
using glTracer_glGetClipPlane = std::function<void(GLenum, GLdouble*)>;
void glGetClipPlane_Traced(GLenum plane, GLdouble* equation);
#define glGetClipPlane glGetClipPlane_Traced
using glTracer_glGetLightfv = std::function<void(GLenum, GLenum, GLfloat*)>;
void glGetLightfv_Traced(GLenum light, GLenum pname, GLfloat* params);
#define glGetLightfv glGetLightfv_Traced
using glTracer_glGetLightiv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetLightiv_Traced(GLenum light, GLenum pname, GLint* params);
#define glGetLightiv glGetLightiv_Traced
using glTracer_glGetMapdv = std::function<void(GLenum, GLenum, GLdouble*)>;
void glGetMapdv_Traced(GLenum target, GLenum query, GLdouble* v);
#define glGetMapdv glGetMapdv_Traced
using glTracer_glGetMapfv = std::function<void(GLenum, GLenum, GLfloat*)>;
void glGetMapfv_Traced(GLenum target, GLenum query, GLfloat* v);
#define glGetMapfv glGetMapfv_Traced
using glTracer_glGetMapiv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetMapiv_Traced(GLenum target, GLenum query, GLint* v);
#define glGetMapiv glGetMapiv_Traced
using glTracer_glGetMaterialfv = std::function<void(GLenum, GLenum, GLfloat*)>;
void glGetMaterialfv_Traced(GLenum face, GLenum pname, GLfloat* params);
#define glGetMaterialfv glGetMaterialfv_Traced
using glTracer_glGetMaterialiv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetMaterialiv_Traced(GLenum face, GLenum pname, GLint* params);
#define glGetMaterialiv glGetMaterialiv_Traced
using glTracer_glGetPixelMapfv = std::function<void(GLenum, GLfloat*)>;
void glGetPixelMapfv_Traced(GLenum map, GLfloat* values);
#define glGetPixelMapfv glGetPixelMapfv_Traced
using glTracer_glGetPixelMapuiv = std::function<void(GLenum, GLuint*)>;
void glGetPixelMapuiv_Traced(GLenum map, GLuint* values);
#define glGetPixelMapuiv glGetPixelMapuiv_Traced
using glTracer_glGetPixelMapusv = std::function<void(GLenum, GLushort*)>;
void glGetPixelMapusv_Traced(GLenum map, GLushort* values);
#define glGetPixelMapusv glGetPixelMapusv_Traced
using glTracer_glGetPolygonStipple = std::function<void(GLubyte*)>;
void glGetPolygonStipple_Traced(GLubyte* mask);
#define glGetPolygonStipple glGetPolygonStipple_Traced
using glTracer_glGetTexEnvfv = std::function<void(GLenum, GLenum, GLfloat*)>;
void glGetTexEnvfv_Traced(GLenum target, GLenum pname, GLfloat* params);
#define glGetTexEnvfv glGetTexEnvfv_Traced
using glTracer_glGetTexEnviv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetTexEnviv_Traced(GLenum target, GLenum pname, GLint* params);
#define glGetTexEnviv glGetTexEnviv_Traced
using glTracer_glGetTexGendv = std::function<void(GLenum, GLenum, GLdouble*)>;
void glGetTexGendv_Traced(GLenum coord, GLenum pname, GLdouble* params);
#define glGetTexGendv glGetTexGendv_Traced
using glTracer_glGetTexGenfv = std::function<void(GLenum, GLenum, GLfloat*)>;
void glGetTexGenfv_Traced(GLenum coord, GLenum pname, GLfloat* params);
#define glGetTexGenfv glGetTexGenfv_Traced
using glTracer_glGetTexGeniv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetTexGeniv_Traced(GLenum coord, GLenum pname, GLint* params);
#define glGetTexGeniv glGetTexGeniv_Traced
using glTracer_glIsList = std::function<GLboolean(GLuint)>;
GLboolean glIsList_Traced(GLuint list);
#define glIsList glIsList_Traced
using glTracer_glFrustum = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)>;
void glFrustum_Traced(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glFrustum glFrustum_Traced
using glTracer_glLoadIdentity = std::function<void()>;
void glLoadIdentity_Traced();
#define glLoadIdentity glLoadIdentity_Traced
using glTracer_glLoadMatrixf = std::function<void(const GLfloat*)>;
void glLoadMatrixf_Traced(const GLfloat* m);
#define glLoadMatrixf glLoadMatrixf_Traced
using glTracer_glLoadMatrixd = std::function<void(const GLdouble*)>;
void glLoadMatrixd_Traced(const GLdouble* m);
#define glLoadMatrixd glLoadMatrixd_Traced
using glTracer_glMatrixMode = std::function<void(GLenum)>;
void glMatrixMode_Traced(GLenum mode);
#define glMatrixMode glMatrixMode_Traced
using glTracer_glMultMatrixf = std::function<void(const GLfloat*)>;
void glMultMatrixf_Traced(const GLfloat* m);
#define glMultMatrixf glMultMatrixf_Traced
using glTracer_glMultMatrixd = std::function<void(const GLdouble*)>;
void glMultMatrixd_Traced(const GLdouble* m);
#define glMultMatrixd glMultMatrixd_Traced
using glTracer_glOrtho = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)>;
void glOrtho_Traced(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glOrtho glOrtho_Traced
using glTracer_glPopMatrix = std::function<void()>;
void glPopMatrix_Traced();
#define glPopMatrix glPopMatrix_Traced
using glTracer_glPushMatrix = std::function<void()>;
void glPushMatrix_Traced();
#define glPushMatrix glPushMatrix_Traced
using glTracer_glRotated = std::function<void(GLdouble, GLdouble, GLdouble, GLdouble)>;
void glRotated_Traced(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glRotated glRotated_Traced
using glTracer_glRotatef = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glRotatef_Traced(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glRotatef glRotatef_Traced
using glTracer_glScaled = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glScaled_Traced(GLdouble x, GLdouble y, GLdouble z);
#define glScaled glScaled_Traced
using glTracer_glScalef = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glScalef_Traced(GLfloat x, GLfloat y, GLfloat z);
#define glScalef glScalef_Traced
using glTracer_glTranslated = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glTranslated_Traced(GLdouble x, GLdouble y, GLdouble z);
#define glTranslated glTranslated_Traced
using glTracer_glTranslatef = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glTranslatef_Traced(GLfloat x, GLfloat y, GLfloat z);
#define glTranslatef glTranslatef_Traced
using glTracer_glDrawArrays = std::function<void(GLenum, GLint, GLsizei)>;
void glDrawArrays_Traced(GLenum mode, GLint first, GLsizei count);
#define glDrawArrays glDrawArrays_Traced
using glTracer_glDrawElements = std::function<void(GLenum, GLsizei, GLenum, const void*)>;
void glDrawElements_Traced(GLenum mode, GLsizei count, GLenum type, const void* indices);
#define glDrawElements glDrawElements_Traced
using glTracer_glGetPointerv = std::function<void(GLenum, void**)>;
void glGetPointerv_Traced(GLenum pname, void** params);
#define glGetPointerv glGetPointerv_Traced
using glTracer_glPolygonOffset = std::function<void(GLfloat, GLfloat)>;
void glPolygonOffset_Traced(GLfloat factor, GLfloat units);
#define glPolygonOffset glPolygonOffset_Traced
using glTracer_glCopyTexImage1D = std::function<void(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)>;
void glCopyTexImage1D_Traced(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1D glCopyTexImage1D_Traced
using glTracer_glCopyTexImage2D = std::function<void(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)>;
void glCopyTexImage2D_Traced(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2D glCopyTexImage2D_Traced
using glTracer_glCopyTexSubImage1D = std::function<void(GLenum, GLint, GLint, GLint, GLint, GLsizei)>;
void glCopyTexSubImage1D_Traced(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1D glCopyTexSubImage1D_Traced
using glTracer_glCopyTexSubImage2D = std::function<void(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>;
void glCopyTexSubImage2D_Traced(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2D glCopyTexSubImage2D_Traced
using glTracer_glTexSubImage1D = std::function<void(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void*)>;
void glTexSubImage1D_Traced(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
#define glTexSubImage1D glTexSubImage1D_Traced
using glTracer_glTexSubImage2D = std::function<void(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void*)>;
void glTexSubImage2D_Traced(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
#define glTexSubImage2D glTexSubImage2D_Traced
using glTracer_glBindTexture = std::function<void(GLenum, GLuint)>;
void glBindTexture_Traced(GLenum target, GLuint texture);
#define glBindTexture glBindTexture_Traced
using glTracer_glDeleteTextures = std::function<void(GLsizei, const GLuint*)>;
void glDeleteTextures_Traced(GLsizei n, const GLuint* textures);
#define glDeleteTextures glDeleteTextures_Traced
using glTracer_glGenTextures = std::function<void(GLsizei, GLuint*)>;
void glGenTextures_Traced(GLsizei n, GLuint* textures);
#define glGenTextures glGenTextures_Traced
using glTracer_glIsTexture = std::function<GLboolean(GLuint)>;
GLboolean glIsTexture_Traced(GLuint texture);
#define glIsTexture glIsTexture_Traced
using glTracer_glArrayElement = std::function<void(GLint)>;
void glArrayElement_Traced(GLint i);
#define glArrayElement glArrayElement_Traced
using glTracer_glColorPointer = std::function<void(GLint, GLenum, GLsizei, const void*)>;
void glColorPointer_Traced(GLint size, GLenum type, GLsizei stride, const void* pointer);
#define glColorPointer glColorPointer_Traced
using glTracer_glDisableClientState = std::function<void(GLenum)>;
void glDisableClientState_Traced(GLenum array);
#define glDisableClientState glDisableClientState_Traced
using glTracer_glEdgeFlagPointer = std::function<void(GLsizei, const void*)>;
void glEdgeFlagPointer_Traced(GLsizei stride, const void* pointer);
#define glEdgeFlagPointer glEdgeFlagPointer_Traced
using glTracer_glEnableClientState = std::function<void(GLenum)>;
void glEnableClientState_Traced(GLenum array);
#define glEnableClientState glEnableClientState_Traced
using glTracer_glIndexPointer = std::function<void(GLenum, GLsizei, const void*)>;
void glIndexPointer_Traced(GLenum type, GLsizei stride, const void* pointer);
#define glIndexPointer glIndexPointer_Traced
using glTracer_glInterleavedArrays = std::function<void(GLenum, GLsizei, const void*)>;
void glInterleavedArrays_Traced(GLenum format, GLsizei stride, const void* pointer);
#define glInterleavedArrays glInterleavedArrays_Traced
using glTracer_glNormalPointer = std::function<void(GLenum, GLsizei, const void*)>;
void glNormalPointer_Traced(GLenum type, GLsizei stride, const void* pointer);
#define glNormalPointer glNormalPointer_Traced
using glTracer_glTexCoordPointer = std::function<void(GLint, GLenum, GLsizei, const void*)>;
void glTexCoordPointer_Traced(GLint size, GLenum type, GLsizei stride, const void* pointer);
#define glTexCoordPointer glTexCoordPointer_Traced
using glTracer_glVertexPointer = std::function<void(GLint, GLenum, GLsizei, const void*)>;
void glVertexPointer_Traced(GLint size, GLenum type, GLsizei stride, const void* pointer);
#define glVertexPointer glVertexPointer_Traced
using glTracer_glAreTexturesResident = std::function<GLboolean(GLsizei, const GLuint*, GLboolean*)>;
GLboolean glAreTexturesResident_Traced(GLsizei n, const GLuint* textures, GLboolean* residences);
#define glAreTexturesResident glAreTexturesResident_Traced
using glTracer_glPrioritizeTextures = std::function<void(GLsizei, const GLuint*, const GLfloat*)>;
void glPrioritizeTextures_Traced(GLsizei n, const GLuint* textures, const GLfloat* priorities);
#define glPrioritizeTextures glPrioritizeTextures_Traced
using glTracer_glIndexub = std::function<void(GLubyte)>;
void glIndexub_Traced(GLubyte c);
#define glIndexub glIndexub_Traced
using glTracer_glIndexubv = std::function<void(const GLubyte*)>;
void glIndexubv_Traced(const GLubyte* c);
#define glIndexubv glIndexubv_Traced
using glTracer_glPopClientAttrib = std::function<void()>;
void glPopClientAttrib_Traced();
#define glPopClientAttrib glPopClientAttrib_Traced
using glTracer_glPushClientAttrib = std::function<void(GLbitfield)>;
void glPushClientAttrib_Traced(GLbitfield mask);
#define glPushClientAttrib glPushClientAttrib_Traced
using glTracer_glDrawRangeElements = std::function<void(GLenum, GLuint, GLuint, GLsizei, GLenum, const void*)>;
void glDrawRangeElements_Traced(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
#define glDrawRangeElements glDrawRangeElements_Traced
using glTracer_glTexImage3D = std::function<void(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*)>;
void glTexImage3D_Traced(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
#define glTexImage3D glTexImage3D_Traced
using glTracer_glTexSubImage3D = std::function<void(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void*)>;
void glTexSubImage3D_Traced(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
#define glTexSubImage3D glTexSubImage3D_Traced
using glTracer_glCopyTexSubImage3D = std::function<void(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>;
void glCopyTexSubImage3D_Traced(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage3D glCopyTexSubImage3D_Traced
using glTracer_glActiveTexture = std::function<void(GLenum)>;
void glActiveTexture_Traced(GLenum texture);
#define glActiveTexture glActiveTexture_Traced
using glTracer_glSampleCoverage = std::function<void(GLfloat, GLboolean)>;
void glSampleCoverage_Traced(GLfloat value, GLboolean invert);
#define glSampleCoverage glSampleCoverage_Traced
using glTracer_glCompressedTexImage3D = std::function<void(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void*)>;
void glCompressedTexImage3D_Traced(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
#define glCompressedTexImage3D glCompressedTexImage3D_Traced
using glTracer_glCompressedTexImage2D = std::function<void(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void*)>;
void glCompressedTexImage2D_Traced(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
#define glCompressedTexImage2D glCompressedTexImage2D_Traced
using glTracer_glCompressedTexImage1D = std::function<void(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void*)>;
void glCompressedTexImage1D_Traced(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
#define glCompressedTexImage1D glCompressedTexImage1D_Traced
using glTracer_glCompressedTexSubImage3D = std::function<void(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void*)>;
void glCompressedTexSubImage3D_Traced(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
#define glCompressedTexSubImage3D glCompressedTexSubImage3D_Traced
using glTracer_glCompressedTexSubImage2D = std::function<void(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void*)>;
void glCompressedTexSubImage2D_Traced(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
#define glCompressedTexSubImage2D glCompressedTexSubImage2D_Traced
using glTracer_glCompressedTexSubImage1D = std::function<void(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void*)>;
void glCompressedTexSubImage1D_Traced(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
#define glCompressedTexSubImage1D glCompressedTexSubImage1D_Traced
using glTracer_glGetCompressedTexImage = std::function<void(GLenum, GLint, void*)>;
void glGetCompressedTexImage_Traced(GLenum target, GLint level, void* img);
#define glGetCompressedTexImage glGetCompressedTexImage_Traced
using glTracer_glClientActiveTexture = std::function<void(GLenum)>;
void glClientActiveTexture_Traced(GLenum texture);
#define glClientActiveTexture glClientActiveTexture_Traced
using glTracer_glMultiTexCoord1d = std::function<void(GLenum, GLdouble)>;
void glMultiTexCoord1d_Traced(GLenum target, GLdouble s);
#define glMultiTexCoord1d glMultiTexCoord1d_Traced
using glTracer_glMultiTexCoord1dv = std::function<void(GLenum, const GLdouble*)>;
void glMultiTexCoord1dv_Traced(GLenum target, const GLdouble* v);
#define glMultiTexCoord1dv glMultiTexCoord1dv_Traced
using glTracer_glMultiTexCoord1f = std::function<void(GLenum, GLfloat)>;
void glMultiTexCoord1f_Traced(GLenum target, GLfloat s);
#define glMultiTexCoord1f glMultiTexCoord1f_Traced
using glTracer_glMultiTexCoord1fv = std::function<void(GLenum, const GLfloat*)>;
void glMultiTexCoord1fv_Traced(GLenum target, const GLfloat* v);
#define glMultiTexCoord1fv glMultiTexCoord1fv_Traced
using glTracer_glMultiTexCoord1i = std::function<void(GLenum, GLint)>;
void glMultiTexCoord1i_Traced(GLenum target, GLint s);
#define glMultiTexCoord1i glMultiTexCoord1i_Traced
using glTracer_glMultiTexCoord1iv = std::function<void(GLenum, const GLint*)>;
void glMultiTexCoord1iv_Traced(GLenum target, const GLint* v);
#define glMultiTexCoord1iv glMultiTexCoord1iv_Traced
using glTracer_glMultiTexCoord1s = std::function<void(GLenum, GLshort)>;
void glMultiTexCoord1s_Traced(GLenum target, GLshort s);
#define glMultiTexCoord1s glMultiTexCoord1s_Traced
using glTracer_glMultiTexCoord1sv = std::function<void(GLenum, const GLshort*)>;
void glMultiTexCoord1sv_Traced(GLenum target, const GLshort* v);
#define glMultiTexCoord1sv glMultiTexCoord1sv_Traced
using glTracer_glMultiTexCoord2d = std::function<void(GLenum, GLdouble, GLdouble)>;
void glMultiTexCoord2d_Traced(GLenum target, GLdouble s, GLdouble t);
#define glMultiTexCoord2d glMultiTexCoord2d_Traced
using glTracer_glMultiTexCoord2dv = std::function<void(GLenum, const GLdouble*)>;
void glMultiTexCoord2dv_Traced(GLenum target, const GLdouble* v);
#define glMultiTexCoord2dv glMultiTexCoord2dv_Traced
using glTracer_glMultiTexCoord2f = std::function<void(GLenum, GLfloat, GLfloat)>;
void glMultiTexCoord2f_Traced(GLenum target, GLfloat s, GLfloat t);
#define glMultiTexCoord2f glMultiTexCoord2f_Traced
using glTracer_glMultiTexCoord2fv = std::function<void(GLenum, const GLfloat*)>;
void glMultiTexCoord2fv_Traced(GLenum target, const GLfloat* v);
#define glMultiTexCoord2fv glMultiTexCoord2fv_Traced
using glTracer_glMultiTexCoord2i = std::function<void(GLenum, GLint, GLint)>;
void glMultiTexCoord2i_Traced(GLenum target, GLint s, GLint t);
#define glMultiTexCoord2i glMultiTexCoord2i_Traced
using glTracer_glMultiTexCoord2iv = std::function<void(GLenum, const GLint*)>;
void glMultiTexCoord2iv_Traced(GLenum target, const GLint* v);
#define glMultiTexCoord2iv glMultiTexCoord2iv_Traced
using glTracer_glMultiTexCoord2s = std::function<void(GLenum, GLshort, GLshort)>;
void glMultiTexCoord2s_Traced(GLenum target, GLshort s, GLshort t);
#define glMultiTexCoord2s glMultiTexCoord2s_Traced
using glTracer_glMultiTexCoord2sv = std::function<void(GLenum, const GLshort*)>;
void glMultiTexCoord2sv_Traced(GLenum target, const GLshort* v);
#define glMultiTexCoord2sv glMultiTexCoord2sv_Traced
using glTracer_glMultiTexCoord3d = std::function<void(GLenum, GLdouble, GLdouble, GLdouble)>;
void glMultiTexCoord3d_Traced(GLenum target, GLdouble s, GLdouble t, GLdouble r);
#define glMultiTexCoord3d glMultiTexCoord3d_Traced
using glTracer_glMultiTexCoord3dv = std::function<void(GLenum, const GLdouble*)>;
void glMultiTexCoord3dv_Traced(GLenum target, const GLdouble* v);
#define glMultiTexCoord3dv glMultiTexCoord3dv_Traced
using glTracer_glMultiTexCoord3f = std::function<void(GLenum, GLfloat, GLfloat, GLfloat)>;
void glMultiTexCoord3f_Traced(GLenum target, GLfloat s, GLfloat t, GLfloat r);
#define glMultiTexCoord3f glMultiTexCoord3f_Traced
using glTracer_glMultiTexCoord3fv = std::function<void(GLenum, const GLfloat*)>;
void glMultiTexCoord3fv_Traced(GLenum target, const GLfloat* v);
#define glMultiTexCoord3fv glMultiTexCoord3fv_Traced
using glTracer_glMultiTexCoord3i = std::function<void(GLenum, GLint, GLint, GLint)>;
void glMultiTexCoord3i_Traced(GLenum target, GLint s, GLint t, GLint r);
#define glMultiTexCoord3i glMultiTexCoord3i_Traced
using glTracer_glMultiTexCoord3iv = std::function<void(GLenum, const GLint*)>;
void glMultiTexCoord3iv_Traced(GLenum target, const GLint* v);
#define glMultiTexCoord3iv glMultiTexCoord3iv_Traced
using glTracer_glMultiTexCoord3s = std::function<void(GLenum, GLshort, GLshort, GLshort)>;
void glMultiTexCoord3s_Traced(GLenum target, GLshort s, GLshort t, GLshort r);
#define glMultiTexCoord3s glMultiTexCoord3s_Traced
using glTracer_glMultiTexCoord3sv = std::function<void(GLenum, const GLshort*)>;
void glMultiTexCoord3sv_Traced(GLenum target, const GLshort* v);
#define glMultiTexCoord3sv glMultiTexCoord3sv_Traced
using glTracer_glMultiTexCoord4d = std::function<void(GLenum, GLdouble, GLdouble, GLdouble, GLdouble)>;
void glMultiTexCoord4d_Traced(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glMultiTexCoord4d glMultiTexCoord4d_Traced
using glTracer_glMultiTexCoord4dv = std::function<void(GLenum, const GLdouble*)>;
void glMultiTexCoord4dv_Traced(GLenum target, const GLdouble* v);
#define glMultiTexCoord4dv glMultiTexCoord4dv_Traced
using glTracer_glMultiTexCoord4f = std::function<void(GLenum, GLfloat, GLfloat, GLfloat, GLfloat)>;
void glMultiTexCoord4f_Traced(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glMultiTexCoord4f glMultiTexCoord4f_Traced
using glTracer_glMultiTexCoord4fv = std::function<void(GLenum, const GLfloat*)>;
void glMultiTexCoord4fv_Traced(GLenum target, const GLfloat* v);
#define glMultiTexCoord4fv glMultiTexCoord4fv_Traced
using glTracer_glMultiTexCoord4i = std::function<void(GLenum, GLint, GLint, GLint, GLint)>;
void glMultiTexCoord4i_Traced(GLenum target, GLint s, GLint t, GLint r, GLint q);
#define glMultiTexCoord4i glMultiTexCoord4i_Traced
using glTracer_glMultiTexCoord4iv = std::function<void(GLenum, const GLint*)>;
void glMultiTexCoord4iv_Traced(GLenum target, const GLint* v);
#define glMultiTexCoord4iv glMultiTexCoord4iv_Traced
using glTracer_glMultiTexCoord4s = std::function<void(GLenum, GLshort, GLshort, GLshort, GLshort)>;
void glMultiTexCoord4s_Traced(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
#define glMultiTexCoord4s glMultiTexCoord4s_Traced
using glTracer_glMultiTexCoord4sv = std::function<void(GLenum, const GLshort*)>;
void glMultiTexCoord4sv_Traced(GLenum target, const GLshort* v);
#define glMultiTexCoord4sv glMultiTexCoord4sv_Traced
using glTracer_glLoadTransposeMatrixf = std::function<void(const GLfloat*)>;
void glLoadTransposeMatrixf_Traced(const GLfloat* m);
#define glLoadTransposeMatrixf glLoadTransposeMatrixf_Traced
using glTracer_glLoadTransposeMatrixd = std::function<void(const GLdouble*)>;
void glLoadTransposeMatrixd_Traced(const GLdouble* m);
#define glLoadTransposeMatrixd glLoadTransposeMatrixd_Traced
using glTracer_glMultTransposeMatrixf = std::function<void(const GLfloat*)>;
void glMultTransposeMatrixf_Traced(const GLfloat* m);
#define glMultTransposeMatrixf glMultTransposeMatrixf_Traced
using glTracer_glMultTransposeMatrixd = std::function<void(const GLdouble*)>;
void glMultTransposeMatrixd_Traced(const GLdouble* m);
#define glMultTransposeMatrixd glMultTransposeMatrixd_Traced
using glTracer_glBlendFuncSeparate = std::function<void(GLenum, GLenum, GLenum, GLenum)>;
void glBlendFuncSeparate_Traced(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#define glBlendFuncSeparate glBlendFuncSeparate_Traced
using glTracer_glMultiDrawArrays = std::function<void(GLenum, const GLint*, const GLsizei*, GLsizei)>;
void glMultiDrawArrays_Traced(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
#define glMultiDrawArrays glMultiDrawArrays_Traced
using glTracer_glMultiDrawElements = std::function<void(GLenum, const GLsizei*, GLenum, const void* const*, GLsizei)>;
void glMultiDrawElements_Traced(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
#define glMultiDrawElements glMultiDrawElements_Traced
using glTracer_glPointParameterf = std::function<void(GLenum, GLfloat)>;
void glPointParameterf_Traced(GLenum pname, GLfloat param);
#define glPointParameterf glPointParameterf_Traced
using glTracer_glPointParameterfv = std::function<void(GLenum, const GLfloat*)>;
void glPointParameterfv_Traced(GLenum pname, const GLfloat* params);
#define glPointParameterfv glPointParameterfv_Traced
using glTracer_glPointParameteri = std::function<void(GLenum, GLint)>;
void glPointParameteri_Traced(GLenum pname, GLint param);
#define glPointParameteri glPointParameteri_Traced
using glTracer_glPointParameteriv = std::function<void(GLenum, const GLint*)>;
void glPointParameteriv_Traced(GLenum pname, const GLint* params);
#define glPointParameteriv glPointParameteriv_Traced
using glTracer_glFogCoordf = std::function<void(GLfloat)>;
void glFogCoordf_Traced(GLfloat coord);
#define glFogCoordf glFogCoordf_Traced
using glTracer_glFogCoordfv = std::function<void(const GLfloat*)>;
void glFogCoordfv_Traced(const GLfloat* coord);
#define glFogCoordfv glFogCoordfv_Traced
using glTracer_glFogCoordd = std::function<void(GLdouble)>;
void glFogCoordd_Traced(GLdouble coord);
#define glFogCoordd glFogCoordd_Traced
using glTracer_glFogCoorddv = std::function<void(const GLdouble*)>;
void glFogCoorddv_Traced(const GLdouble* coord);
#define glFogCoorddv glFogCoorddv_Traced
using glTracer_glFogCoordPointer = std::function<void(GLenum, GLsizei, const void*)>;
void glFogCoordPointer_Traced(GLenum type, GLsizei stride, const void* pointer);
#define glFogCoordPointer glFogCoordPointer_Traced
using glTracer_glSecondaryColor3b = std::function<void(GLbyte, GLbyte, GLbyte)>;
void glSecondaryColor3b_Traced(GLbyte red, GLbyte green, GLbyte blue);
#define glSecondaryColor3b glSecondaryColor3b_Traced
using glTracer_glSecondaryColor3bv = std::function<void(const GLbyte*)>;
void glSecondaryColor3bv_Traced(const GLbyte* v);
#define glSecondaryColor3bv glSecondaryColor3bv_Traced
using glTracer_glSecondaryColor3d = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glSecondaryColor3d_Traced(GLdouble red, GLdouble green, GLdouble blue);
#define glSecondaryColor3d glSecondaryColor3d_Traced
using glTracer_glSecondaryColor3dv = std::function<void(const GLdouble*)>;
void glSecondaryColor3dv_Traced(const GLdouble* v);
#define glSecondaryColor3dv glSecondaryColor3dv_Traced
using glTracer_glSecondaryColor3f = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glSecondaryColor3f_Traced(GLfloat red, GLfloat green, GLfloat blue);
#define glSecondaryColor3f glSecondaryColor3f_Traced
using glTracer_glSecondaryColor3fv = std::function<void(const GLfloat*)>;
void glSecondaryColor3fv_Traced(const GLfloat* v);
#define glSecondaryColor3fv glSecondaryColor3fv_Traced
using glTracer_glSecondaryColor3i = std::function<void(GLint, GLint, GLint)>;
void glSecondaryColor3i_Traced(GLint red, GLint green, GLint blue);
#define glSecondaryColor3i glSecondaryColor3i_Traced
using glTracer_glSecondaryColor3iv = std::function<void(const GLint*)>;
void glSecondaryColor3iv_Traced(const GLint* v);
#define glSecondaryColor3iv glSecondaryColor3iv_Traced
using glTracer_glSecondaryColor3s = std::function<void(GLshort, GLshort, GLshort)>;
void glSecondaryColor3s_Traced(GLshort red, GLshort green, GLshort blue);
#define glSecondaryColor3s glSecondaryColor3s_Traced
using glTracer_glSecondaryColor3sv = std::function<void(const GLshort*)>;
void glSecondaryColor3sv_Traced(const GLshort* v);
#define glSecondaryColor3sv glSecondaryColor3sv_Traced
using glTracer_glSecondaryColor3ub = std::function<void(GLubyte, GLubyte, GLubyte)>;
void glSecondaryColor3ub_Traced(GLubyte red, GLubyte green, GLubyte blue);
#define glSecondaryColor3ub glSecondaryColor3ub_Traced
using glTracer_glSecondaryColor3ubv = std::function<void(const GLubyte*)>;
void glSecondaryColor3ubv_Traced(const GLubyte* v);
#define glSecondaryColor3ubv glSecondaryColor3ubv_Traced
using glTracer_glSecondaryColor3ui = std::function<void(GLuint, GLuint, GLuint)>;
void glSecondaryColor3ui_Traced(GLuint red, GLuint green, GLuint blue);
#define glSecondaryColor3ui glSecondaryColor3ui_Traced
using glTracer_glSecondaryColor3uiv = std::function<void(const GLuint*)>;
void glSecondaryColor3uiv_Traced(const GLuint* v);
#define glSecondaryColor3uiv glSecondaryColor3uiv_Traced
using glTracer_glSecondaryColor3us = std::function<void(GLushort, GLushort, GLushort)>;
void glSecondaryColor3us_Traced(GLushort red, GLushort green, GLushort blue);
#define glSecondaryColor3us glSecondaryColor3us_Traced
using glTracer_glSecondaryColor3usv = std::function<void(const GLushort*)>;
void glSecondaryColor3usv_Traced(const GLushort* v);
#define glSecondaryColor3usv glSecondaryColor3usv_Traced
using glTracer_glSecondaryColorPointer = std::function<void(GLint, GLenum, GLsizei, const void*)>;
void glSecondaryColorPointer_Traced(GLint size, GLenum type, GLsizei stride, const void* pointer);
#define glSecondaryColorPointer glSecondaryColorPointer_Traced
using glTracer_glWindowPos2d = std::function<void(GLdouble, GLdouble)>;
void glWindowPos2d_Traced(GLdouble x, GLdouble y);
#define glWindowPos2d glWindowPos2d_Traced
using glTracer_glWindowPos2dv = std::function<void(const GLdouble*)>;
void glWindowPos2dv_Traced(const GLdouble* v);
#define glWindowPos2dv glWindowPos2dv_Traced
using glTracer_glWindowPos2f = std::function<void(GLfloat, GLfloat)>;
void glWindowPos2f_Traced(GLfloat x, GLfloat y);
#define glWindowPos2f glWindowPos2f_Traced
using glTracer_glWindowPos2fv = std::function<void(const GLfloat*)>;
void glWindowPos2fv_Traced(const GLfloat* v);
#define glWindowPos2fv glWindowPos2fv_Traced
using glTracer_glWindowPos2i = std::function<void(GLint, GLint)>;
void glWindowPos2i_Traced(GLint x, GLint y);
#define glWindowPos2i glWindowPos2i_Traced
using glTracer_glWindowPos2iv = std::function<void(const GLint*)>;
void glWindowPos2iv_Traced(const GLint* v);
#define glWindowPos2iv glWindowPos2iv_Traced
using glTracer_glWindowPos2s = std::function<void(GLshort, GLshort)>;
void glWindowPos2s_Traced(GLshort x, GLshort y);
#define glWindowPos2s glWindowPos2s_Traced
using glTracer_glWindowPos2sv = std::function<void(const GLshort*)>;
void glWindowPos2sv_Traced(const GLshort* v);
#define glWindowPos2sv glWindowPos2sv_Traced
using glTracer_glWindowPos3d = std::function<void(GLdouble, GLdouble, GLdouble)>;
void glWindowPos3d_Traced(GLdouble x, GLdouble y, GLdouble z);
#define glWindowPos3d glWindowPos3d_Traced
using glTracer_glWindowPos3dv = std::function<void(const GLdouble*)>;
void glWindowPos3dv_Traced(const GLdouble* v);
#define glWindowPos3dv glWindowPos3dv_Traced
using glTracer_glWindowPos3f = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glWindowPos3f_Traced(GLfloat x, GLfloat y, GLfloat z);
#define glWindowPos3f glWindowPos3f_Traced
using glTracer_glWindowPos3fv = std::function<void(const GLfloat*)>;
void glWindowPos3fv_Traced(const GLfloat* v);
#define glWindowPos3fv glWindowPos3fv_Traced
using glTracer_glWindowPos3i = std::function<void(GLint, GLint, GLint)>;
void glWindowPos3i_Traced(GLint x, GLint y, GLint z);
#define glWindowPos3i glWindowPos3i_Traced
using glTracer_glWindowPos3iv = std::function<void(const GLint*)>;
void glWindowPos3iv_Traced(const GLint* v);
#define glWindowPos3iv glWindowPos3iv_Traced
using glTracer_glWindowPos3s = std::function<void(GLshort, GLshort, GLshort)>;
void glWindowPos3s_Traced(GLshort x, GLshort y, GLshort z);
#define glWindowPos3s glWindowPos3s_Traced
using glTracer_glWindowPos3sv = std::function<void(const GLshort*)>;
void glWindowPos3sv_Traced(const GLshort* v);
#define glWindowPos3sv glWindowPos3sv_Traced
using glTracer_glBlendColor = std::function<void(GLfloat, GLfloat, GLfloat, GLfloat)>;
void glBlendColor_Traced(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColor glBlendColor_Traced
using glTracer_glBlendEquation = std::function<void(GLenum)>;
void glBlendEquation_Traced(GLenum mode);
#define glBlendEquation glBlendEquation_Traced
using glTracer_glGenQueries = std::function<void(GLsizei, GLuint*)>;
void glGenQueries_Traced(GLsizei n, GLuint* ids);
#define glGenQueries glGenQueries_Traced
using glTracer_glDeleteQueries = std::function<void(GLsizei, const GLuint*)>;
void glDeleteQueries_Traced(GLsizei n, const GLuint* ids);
#define glDeleteQueries glDeleteQueries_Traced
using glTracer_glIsQuery = std::function<GLboolean(GLuint)>;
GLboolean glIsQuery_Traced(GLuint id);
#define glIsQuery glIsQuery_Traced
using glTracer_glBeginQuery = std::function<void(GLenum, GLuint)>;
void glBeginQuery_Traced(GLenum target, GLuint id);
#define glBeginQuery glBeginQuery_Traced
using glTracer_glEndQuery = std::function<void(GLenum)>;
void glEndQuery_Traced(GLenum target);
#define glEndQuery glEndQuery_Traced
using glTracer_glGetQueryiv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetQueryiv_Traced(GLenum target, GLenum pname, GLint* params);
#define glGetQueryiv glGetQueryiv_Traced
using glTracer_glGetQueryObjectiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetQueryObjectiv_Traced(GLuint id, GLenum pname, GLint* params);
#define glGetQueryObjectiv glGetQueryObjectiv_Traced
using glTracer_glGetQueryObjectuiv = std::function<void(GLuint, GLenum, GLuint*)>;
void glGetQueryObjectuiv_Traced(GLuint id, GLenum pname, GLuint* params);
#define glGetQueryObjectuiv glGetQueryObjectuiv_Traced
using glTracer_glBindBuffer = std::function<void(GLenum, GLuint)>;
void glBindBuffer_Traced(GLenum target, GLuint buffer);
#define glBindBuffer glBindBuffer_Traced
using glTracer_glDeleteBuffers = std::function<void(GLsizei, const GLuint*)>;
void glDeleteBuffers_Traced(GLsizei n, const GLuint* buffers);
#define glDeleteBuffers glDeleteBuffers_Traced
using glTracer_glGenBuffers = std::function<void(GLsizei, GLuint*)>;
void glGenBuffers_Traced(GLsizei n, GLuint* buffers);
#define glGenBuffers glGenBuffers_Traced
using glTracer_glIsBuffer = std::function<GLboolean(GLuint)>;
GLboolean glIsBuffer_Traced(GLuint buffer);
#define glIsBuffer glIsBuffer_Traced
using glTracer_glBufferData = std::function<void(GLenum, GLsizeiptr, const void*, GLenum)>;
void glBufferData_Traced(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
#define glBufferData glBufferData_Traced
using glTracer_glBufferSubData = std::function<void(GLenum, GLintptr, GLsizeiptr, const void*)>;
void glBufferSubData_Traced(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
#define glBufferSubData glBufferSubData_Traced
using glTracer_glGetBufferSubData = std::function<void(GLenum, GLintptr, GLsizeiptr, void*)>;
void glGetBufferSubData_Traced(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
#define glGetBufferSubData glGetBufferSubData_Traced
using glTracer_glMapBuffer = std::function<void* (GLenum, GLenum)>;
void* glMapBuffer_Traced(GLenum target, GLenum access);
#define glMapBuffer glMapBuffer_Traced
using glTracer_glUnmapBuffer = std::function<GLboolean(GLenum)>;
GLboolean glUnmapBuffer_Traced(GLenum target);
#define glUnmapBuffer glUnmapBuffer_Traced
using glTracer_glGetBufferParameteriv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetBufferParameteriv_Traced(GLenum target, GLenum pname, GLint* params);
#define glGetBufferParameteriv glGetBufferParameteriv_Traced
using glTracer_glGetBufferPointerv = std::function<void(GLenum, GLenum, void**)>;
void glGetBufferPointerv_Traced(GLenum target, GLenum pname, void** params);
#define glGetBufferPointerv glGetBufferPointerv_Traced
using glTracer_glBlendEquationSeparate = std::function<void(GLenum, GLenum)>;
void glBlendEquationSeparate_Traced(GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparate glBlendEquationSeparate_Traced
using glTracer_glDrawBuffers = std::function<void(GLsizei, const GLenum*)>;
void glDrawBuffers_Traced(GLsizei n, const GLenum* bufs);
#define glDrawBuffers glDrawBuffers_Traced
using glTracer_glStencilOpSeparate = std::function<void(GLenum, GLenum, GLenum, GLenum)>;
void glStencilOpSeparate_Traced(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
#define glStencilOpSeparate glStencilOpSeparate_Traced
using glTracer_glStencilFuncSeparate = std::function<void(GLenum, GLenum, GLint, GLuint)>;
void glStencilFuncSeparate_Traced(GLenum face, GLenum func, GLint ref, GLuint mask);
#define glStencilFuncSeparate glStencilFuncSeparate_Traced
using glTracer_glStencilMaskSeparate = std::function<void(GLenum, GLuint)>;
void glStencilMaskSeparate_Traced(GLenum face, GLuint mask);
#define glStencilMaskSeparate glStencilMaskSeparate_Traced
using glTracer_glAttachShader = std::function<void(GLuint, GLuint)>;
void glAttachShader_Traced(GLuint program, GLuint shader);
#define glAttachShader glAttachShader_Traced
using glTracer_glBindAttribLocation = std::function<void(GLuint, GLuint, const GLchar*)>;
void glBindAttribLocation_Traced(GLuint program, GLuint index, const GLchar* name);
#define glBindAttribLocation glBindAttribLocation_Traced
using glTracer_glCompileShader = std::function<void(GLuint)>;
void glCompileShader_Traced(GLuint shader);
#define glCompileShader glCompileShader_Traced
using glTracer_glCreateProgram = std::function<GLuint()>;
GLuint glCreateProgram_Traced();
#define glCreateProgram glCreateProgram_Traced
using glTracer_glCreateShader = std::function<GLuint(GLenum)>;
GLuint glCreateShader_Traced(GLenum type);
#define glCreateShader glCreateShader_Traced
using glTracer_glDeleteProgram = std::function<void(GLuint)>;
void glDeleteProgram_Traced(GLuint program);
#define glDeleteProgram glDeleteProgram_Traced
using glTracer_glDeleteShader = std::function<void(GLuint)>;
void glDeleteShader_Traced(GLuint shader);
#define glDeleteShader glDeleteShader_Traced
using glTracer_glDetachShader = std::function<void(GLuint, GLuint)>;
void glDetachShader_Traced(GLuint program, GLuint shader);
#define glDetachShader glDetachShader_Traced
using glTracer_glDisableVertexAttribArray = std::function<void(GLuint)>;
void glDisableVertexAttribArray_Traced(GLuint index);
#define glDisableVertexAttribArray glDisableVertexAttribArray_Traced
using glTracer_glEnableVertexAttribArray = std::function<void(GLuint)>;
void glEnableVertexAttribArray_Traced(GLuint index);
#define glEnableVertexAttribArray glEnableVertexAttribArray_Traced
using glTracer_glGetActiveAttrib = std::function<void(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*)>;
void glGetActiveAttrib_Traced(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
#define glGetActiveAttrib glGetActiveAttrib_Traced
using glTracer_glGetActiveUniform = std::function<void(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*)>;
void glGetActiveUniform_Traced(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
#define glGetActiveUniform glGetActiveUniform_Traced
using glTracer_glGetAttachedShaders = std::function<void(GLuint, GLsizei, GLsizei*, GLuint*)>;
void glGetAttachedShaders_Traced(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
#define glGetAttachedShaders glGetAttachedShaders_Traced
using glTracer_glGetAttribLocation = std::function<GLint(GLuint, const GLchar*)>;
GLint glGetAttribLocation_Traced(GLuint program, const GLchar* name);
#define glGetAttribLocation glGetAttribLocation_Traced
using glTracer_glGetProgramiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetProgramiv_Traced(GLuint program, GLenum pname, GLint* params);
#define glGetProgramiv glGetProgramiv_Traced
using glTracer_glGetProgramInfoLog = std::function<void(GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetProgramInfoLog_Traced(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
#define glGetProgramInfoLog glGetProgramInfoLog_Traced
using glTracer_glGetShaderiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetShaderiv_Traced(GLuint shader, GLenum pname, GLint* params);
#define glGetShaderiv glGetShaderiv_Traced
using glTracer_glGetShaderInfoLog = std::function<void(GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetShaderInfoLog_Traced(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
#define glGetShaderInfoLog glGetShaderInfoLog_Traced
using glTracer_glGetShaderSource = std::function<void(GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetShaderSource_Traced(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
#define glGetShaderSource glGetShaderSource_Traced
using glTracer_glGetUniformLocation = std::function<GLint(GLuint, const GLchar*)>;
GLint glGetUniformLocation_Traced(GLuint program, const GLchar* name);
#define glGetUniformLocation glGetUniformLocation_Traced
using glTracer_glGetUniformfv = std::function<void(GLuint, GLint, GLfloat*)>;
void glGetUniformfv_Traced(GLuint program, GLint location, GLfloat* params);
#define glGetUniformfv glGetUniformfv_Traced
using glTracer_glGetUniformiv = std::function<void(GLuint, GLint, GLint*)>;
void glGetUniformiv_Traced(GLuint program, GLint location, GLint* params);
#define glGetUniformiv glGetUniformiv_Traced
using glTracer_glGetVertexAttribdv = std::function<void(GLuint, GLenum, GLdouble*)>;
void glGetVertexAttribdv_Traced(GLuint index, GLenum pname, GLdouble* params);
#define glGetVertexAttribdv glGetVertexAttribdv_Traced
using glTracer_glGetVertexAttribfv = std::function<void(GLuint, GLenum, GLfloat*)>;
void glGetVertexAttribfv_Traced(GLuint index, GLenum pname, GLfloat* params);
#define glGetVertexAttribfv glGetVertexAttribfv_Traced
using glTracer_glGetVertexAttribiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetVertexAttribiv_Traced(GLuint index, GLenum pname, GLint* params);
#define glGetVertexAttribiv glGetVertexAttribiv_Traced
using glTracer_glGetVertexAttribPointerv = std::function<void(GLuint, GLenum, void**)>;
void glGetVertexAttribPointerv_Traced(GLuint index, GLenum pname, void** pointer);
#define glGetVertexAttribPointerv glGetVertexAttribPointerv_Traced
using glTracer_glIsProgram = std::function<GLboolean(GLuint)>;
GLboolean glIsProgram_Traced(GLuint program);
#define glIsProgram glIsProgram_Traced
using glTracer_glIsShader = std::function<GLboolean(GLuint)>;
GLboolean glIsShader_Traced(GLuint shader);
#define glIsShader glIsShader_Traced
using glTracer_glLinkProgram = std::function<void(GLuint)>;
void glLinkProgram_Traced(GLuint program);
#define glLinkProgram glLinkProgram_Traced
using glTracer_glShaderSource = std::function<void(GLuint, GLsizei, const GLchar* const*, const GLint*)>;
void glShaderSource_Traced(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
#define glShaderSource glShaderSource_Traced
using glTracer_glUseProgram = std::function<void(GLuint)>;
void glUseProgram_Traced(GLuint program);
#define glUseProgram glUseProgram_Traced
using glTracer_glUniform1f = std::function<void(GLint, GLfloat)>;
void glUniform1f_Traced(GLint location, GLfloat v0);
#define glUniform1f glUniform1f_Traced
using glTracer_glUniform2f = std::function<void(GLint, GLfloat, GLfloat)>;
void glUniform2f_Traced(GLint location, GLfloat v0, GLfloat v1);
#define glUniform2f glUniform2f_Traced
using glTracer_glUniform3f = std::function<void(GLint, GLfloat, GLfloat, GLfloat)>;
void glUniform3f_Traced(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glUniform3f glUniform3f_Traced
using glTracer_glUniform4f = std::function<void(GLint, GLfloat, GLfloat, GLfloat, GLfloat)>;
void glUniform4f_Traced(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glUniform4f glUniform4f_Traced
using glTracer_glUniform1i = std::function<void(GLint, GLint)>;
void glUniform1i_Traced(GLint location, GLint v0);
#define glUniform1i glUniform1i_Traced
using glTracer_glUniform2i = std::function<void(GLint, GLint, GLint)>;
void glUniform2i_Traced(GLint location, GLint v0, GLint v1);
#define glUniform2i glUniform2i_Traced
using glTracer_glUniform3i = std::function<void(GLint, GLint, GLint, GLint)>;
void glUniform3i_Traced(GLint location, GLint v0, GLint v1, GLint v2);
#define glUniform3i glUniform3i_Traced
using glTracer_glUniform4i = std::function<void(GLint, GLint, GLint, GLint, GLint)>;
void glUniform4i_Traced(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glUniform4i glUniform4i_Traced
using glTracer_glUniform1fv = std::function<void(GLint, GLsizei, const GLfloat*)>;
void glUniform1fv_Traced(GLint location, GLsizei count, const GLfloat* value);
#define glUniform1fv glUniform1fv_Traced
using glTracer_glUniform2fv = std::function<void(GLint, GLsizei, const GLfloat*)>;
void glUniform2fv_Traced(GLint location, GLsizei count, const GLfloat* value);
#define glUniform2fv glUniform2fv_Traced
using glTracer_glUniform3fv = std::function<void(GLint, GLsizei, const GLfloat*)>;
void glUniform3fv_Traced(GLint location, GLsizei count, const GLfloat* value);
#define glUniform3fv glUniform3fv_Traced
using glTracer_glUniform4fv = std::function<void(GLint, GLsizei, const GLfloat*)>;
void glUniform4fv_Traced(GLint location, GLsizei count, const GLfloat* value);
#define glUniform4fv glUniform4fv_Traced
using glTracer_glUniform1iv = std::function<void(GLint, GLsizei, const GLint*)>;
void glUniform1iv_Traced(GLint location, GLsizei count, const GLint* value);
#define glUniform1iv glUniform1iv_Traced
using glTracer_glUniform2iv = std::function<void(GLint, GLsizei, const GLint*)>;
void glUniform2iv_Traced(GLint location, GLsizei count, const GLint* value);
#define glUniform2iv glUniform2iv_Traced
using glTracer_glUniform3iv = std::function<void(GLint, GLsizei, const GLint*)>;
void glUniform3iv_Traced(GLint location, GLsizei count, const GLint* value);
#define glUniform3iv glUniform3iv_Traced
using glTracer_glUniform4iv = std::function<void(GLint, GLsizei, const GLint*)>;
void glUniform4iv_Traced(GLint location, GLsizei count, const GLint* value);
#define glUniform4iv glUniform4iv_Traced
using glTracer_glUniformMatrix2fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix2fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix2fv glUniformMatrix2fv_Traced
using glTracer_glUniformMatrix3fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix3fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix3fv glUniformMatrix3fv_Traced
using glTracer_glUniformMatrix4fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix4fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix4fv glUniformMatrix4fv_Traced
using glTracer_glValidateProgram = std::function<void(GLuint)>;
void glValidateProgram_Traced(GLuint program);
#define glValidateProgram glValidateProgram_Traced
using glTracer_glVertexAttrib1d = std::function<void(GLuint, GLdouble)>;
void glVertexAttrib1d_Traced(GLuint index, GLdouble x);
#define glVertexAttrib1d glVertexAttrib1d_Traced
using glTracer_glVertexAttrib1dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttrib1dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttrib1dv glVertexAttrib1dv_Traced
using glTracer_glVertexAttrib1f = std::function<void(GLuint, GLfloat)>;
void glVertexAttrib1f_Traced(GLuint index, GLfloat x);
#define glVertexAttrib1f glVertexAttrib1f_Traced
using glTracer_glVertexAttrib1fv = std::function<void(GLuint, const GLfloat*)>;
void glVertexAttrib1fv_Traced(GLuint index, const GLfloat* v);
#define glVertexAttrib1fv glVertexAttrib1fv_Traced
using glTracer_glVertexAttrib1s = std::function<void(GLuint, GLshort)>;
void glVertexAttrib1s_Traced(GLuint index, GLshort x);
#define glVertexAttrib1s glVertexAttrib1s_Traced
using glTracer_glVertexAttrib1sv = std::function<void(GLuint, const GLshort*)>;
void glVertexAttrib1sv_Traced(GLuint index, const GLshort* v);
#define glVertexAttrib1sv glVertexAttrib1sv_Traced
using glTracer_glVertexAttrib2d = std::function<void(GLuint, GLdouble, GLdouble)>;
void glVertexAttrib2d_Traced(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2d glVertexAttrib2d_Traced
using glTracer_glVertexAttrib2dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttrib2dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttrib2dv glVertexAttrib2dv_Traced
using glTracer_glVertexAttrib2f = std::function<void(GLuint, GLfloat, GLfloat)>;
void glVertexAttrib2f_Traced(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2f glVertexAttrib2f_Traced
using glTracer_glVertexAttrib2fv = std::function<void(GLuint, const GLfloat*)>;
void glVertexAttrib2fv_Traced(GLuint index, const GLfloat* v);
#define glVertexAttrib2fv glVertexAttrib2fv_Traced
using glTracer_glVertexAttrib2s = std::function<void(GLuint, GLshort, GLshort)>;
void glVertexAttrib2s_Traced(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2s glVertexAttrib2s_Traced
using glTracer_glVertexAttrib2sv = std::function<void(GLuint, const GLshort*)>;
void glVertexAttrib2sv_Traced(GLuint index, const GLshort* v);
#define glVertexAttrib2sv glVertexAttrib2sv_Traced
using glTracer_glVertexAttrib3d = std::function<void(GLuint, GLdouble, GLdouble, GLdouble)>;
void glVertexAttrib3d_Traced(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3d glVertexAttrib3d_Traced
using glTracer_glVertexAttrib3dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttrib3dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttrib3dv glVertexAttrib3dv_Traced
using glTracer_glVertexAttrib3f = std::function<void(GLuint, GLfloat, GLfloat, GLfloat)>;
void glVertexAttrib3f_Traced(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3f glVertexAttrib3f_Traced
using glTracer_glVertexAttrib3fv = std::function<void(GLuint, const GLfloat*)>;
void glVertexAttrib3fv_Traced(GLuint index, const GLfloat* v);
#define glVertexAttrib3fv glVertexAttrib3fv_Traced
using glTracer_glVertexAttrib3s = std::function<void(GLuint, GLshort, GLshort, GLshort)>;
void glVertexAttrib3s_Traced(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3s glVertexAttrib3s_Traced
using glTracer_glVertexAttrib3sv = std::function<void(GLuint, const GLshort*)>;
void glVertexAttrib3sv_Traced(GLuint index, const GLshort* v);
#define glVertexAttrib3sv glVertexAttrib3sv_Traced
using glTracer_glVertexAttrib4Nbv = std::function<void(GLuint, const GLbyte*)>;
void glVertexAttrib4Nbv_Traced(GLuint index, const GLbyte* v);
#define glVertexAttrib4Nbv glVertexAttrib4Nbv_Traced
using glTracer_glVertexAttrib4Niv = std::function<void(GLuint, const GLint*)>;
void glVertexAttrib4Niv_Traced(GLuint index, const GLint* v);
#define glVertexAttrib4Niv glVertexAttrib4Niv_Traced
using glTracer_glVertexAttrib4Nsv = std::function<void(GLuint, const GLshort*)>;
void glVertexAttrib4Nsv_Traced(GLuint index, const GLshort* v);
#define glVertexAttrib4Nsv glVertexAttrib4Nsv_Traced
using glTracer_glVertexAttrib4Nub = std::function<void(GLuint, GLubyte, GLubyte, GLubyte, GLubyte)>;
void glVertexAttrib4Nub_Traced(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4Nub glVertexAttrib4Nub_Traced
using glTracer_glVertexAttrib4Nubv = std::function<void(GLuint, const GLubyte*)>;
void glVertexAttrib4Nubv_Traced(GLuint index, const GLubyte* v);
#define glVertexAttrib4Nubv glVertexAttrib4Nubv_Traced
using glTracer_glVertexAttrib4Nuiv = std::function<void(GLuint, const GLuint*)>;
void glVertexAttrib4Nuiv_Traced(GLuint index, const GLuint* v);
#define glVertexAttrib4Nuiv glVertexAttrib4Nuiv_Traced
using glTracer_glVertexAttrib4Nusv = std::function<void(GLuint, const GLushort*)>;
void glVertexAttrib4Nusv_Traced(GLuint index, const GLushort* v);
#define glVertexAttrib4Nusv glVertexAttrib4Nusv_Traced
using glTracer_glVertexAttrib4bv = std::function<void(GLuint, const GLbyte*)>;
void glVertexAttrib4bv_Traced(GLuint index, const GLbyte* v);
#define glVertexAttrib4bv glVertexAttrib4bv_Traced
using glTracer_glVertexAttrib4d = std::function<void(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>;
void glVertexAttrib4d_Traced(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4d glVertexAttrib4d_Traced
using glTracer_glVertexAttrib4dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttrib4dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttrib4dv glVertexAttrib4dv_Traced
using glTracer_glVertexAttrib4f = std::function<void(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>;
void glVertexAttrib4f_Traced(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4f glVertexAttrib4f_Traced
using glTracer_glVertexAttrib4fv = std::function<void(GLuint, const GLfloat*)>;
void glVertexAttrib4fv_Traced(GLuint index, const GLfloat* v);
#define glVertexAttrib4fv glVertexAttrib4fv_Traced
using glTracer_glVertexAttrib4iv = std::function<void(GLuint, const GLint*)>;
void glVertexAttrib4iv_Traced(GLuint index, const GLint* v);
#define glVertexAttrib4iv glVertexAttrib4iv_Traced
using glTracer_glVertexAttrib4s = std::function<void(GLuint, GLshort, GLshort, GLshort, GLshort)>;
void glVertexAttrib4s_Traced(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4s glVertexAttrib4s_Traced
using glTracer_glVertexAttrib4sv = std::function<void(GLuint, const GLshort*)>;
void glVertexAttrib4sv_Traced(GLuint index, const GLshort* v);
#define glVertexAttrib4sv glVertexAttrib4sv_Traced
using glTracer_glVertexAttrib4ubv = std::function<void(GLuint, const GLubyte*)>;
void glVertexAttrib4ubv_Traced(GLuint index, const GLubyte* v);
#define glVertexAttrib4ubv glVertexAttrib4ubv_Traced
using glTracer_glVertexAttrib4uiv = std::function<void(GLuint, const GLuint*)>;
void glVertexAttrib4uiv_Traced(GLuint index, const GLuint* v);
#define glVertexAttrib4uiv glVertexAttrib4uiv_Traced
using glTracer_glVertexAttrib4usv = std::function<void(GLuint, const GLushort*)>;
void glVertexAttrib4usv_Traced(GLuint index, const GLushort* v);
#define glVertexAttrib4usv glVertexAttrib4usv_Traced
using glTracer_glVertexAttribPointer = std::function<void(GLuint, GLint, GLenum, GLboolean, GLsizei, const void*)>;
void glVertexAttribPointer_Traced(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
#define glVertexAttribPointer glVertexAttribPointer_Traced
using glTracer_glUniformMatrix2x3fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix2x3fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix2x3fv glUniformMatrix2x3fv_Traced
using glTracer_glUniformMatrix3x2fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix3x2fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix3x2fv glUniformMatrix3x2fv_Traced
using glTracer_glUniformMatrix2x4fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix2x4fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix2x4fv glUniformMatrix2x4fv_Traced
using glTracer_glUniformMatrix4x2fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix4x2fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix4x2fv glUniformMatrix4x2fv_Traced
using glTracer_glUniformMatrix3x4fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix3x4fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix3x4fv glUniformMatrix3x4fv_Traced
using glTracer_glUniformMatrix4x3fv = std::function<void(GLint, GLsizei, GLboolean, const GLfloat*)>;
void glUniformMatrix4x3fv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glUniformMatrix4x3fv glUniformMatrix4x3fv_Traced
using glTracer_glColorMaski = std::function<void(GLuint, GLboolean, GLboolean, GLboolean, GLboolean)>;
void glColorMaski_Traced(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
#define glColorMaski glColorMaski_Traced
using glTracer_glGetBooleani_v = std::function<void(GLenum, GLuint, GLboolean*)>;
void glGetBooleani_v_Traced(GLenum target, GLuint index, GLboolean* data);
#define glGetBooleani_v glGetBooleani_v_Traced
using glTracer_glGetIntegeri_v = std::function<void(GLenum, GLuint, GLint*)>;
void glGetIntegeri_v_Traced(GLenum target, GLuint index, GLint* data);
#define glGetIntegeri_v glGetIntegeri_v_Traced
using glTracer_glEnablei = std::function<void(GLenum, GLuint)>;
void glEnablei_Traced(GLenum target, GLuint index);
#define glEnablei glEnablei_Traced
using glTracer_glDisablei = std::function<void(GLenum, GLuint)>;
void glDisablei_Traced(GLenum target, GLuint index);
#define glDisablei glDisablei_Traced
using glTracer_glIsEnabledi = std::function<GLboolean(GLenum, GLuint)>;
GLboolean glIsEnabledi_Traced(GLenum target, GLuint index);
#define glIsEnabledi glIsEnabledi_Traced
using glTracer_glBeginTransformFeedback = std::function<void(GLenum)>;
void glBeginTransformFeedback_Traced(GLenum primitiveMode);
#define glBeginTransformFeedback glBeginTransformFeedback_Traced
using glTracer_glEndTransformFeedback = std::function<void()>;
void glEndTransformFeedback_Traced();
#define glEndTransformFeedback glEndTransformFeedback_Traced
using glTracer_glBindBufferRange = std::function<void(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr)>;
void glBindBufferRange_Traced(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRange glBindBufferRange_Traced
using glTracer_glBindBufferBase = std::function<void(GLenum, GLuint, GLuint)>;
void glBindBufferBase_Traced(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBase glBindBufferBase_Traced
using glTracer_glTransformFeedbackVaryings = std::function<void(GLuint, GLsizei, const GLchar* const*, GLenum)>;
void glTransformFeedbackVaryings_Traced(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
#define glTransformFeedbackVaryings glTransformFeedbackVaryings_Traced
using glTracer_glGetTransformFeedbackVarying = std::function<void(GLuint, GLuint, GLsizei, GLsizei*, GLsizei*, GLenum*, GLchar*)>;
void glGetTransformFeedbackVarying_Traced(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
#define glGetTransformFeedbackVarying glGetTransformFeedbackVarying_Traced
using glTracer_glClampColor = std::function<void(GLenum, GLenum)>;
void glClampColor_Traced(GLenum target, GLenum clamp);
#define glClampColor glClampColor_Traced
using glTracer_glBeginConditionalRender = std::function<void(GLuint, GLenum)>;
void glBeginConditionalRender_Traced(GLuint id, GLenum mode);
#define glBeginConditionalRender glBeginConditionalRender_Traced
using glTracer_glEndConditionalRender = std::function<void()>;
void glEndConditionalRender_Traced();
#define glEndConditionalRender glEndConditionalRender_Traced
using glTracer_glVertexAttribIPointer = std::function<void(GLuint, GLint, GLenum, GLsizei, const void*)>;
void glVertexAttribIPointer_Traced(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
#define glVertexAttribIPointer glVertexAttribIPointer_Traced
using glTracer_glGetVertexAttribIiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetVertexAttribIiv_Traced(GLuint index, GLenum pname, GLint* params);
#define glGetVertexAttribIiv glGetVertexAttribIiv_Traced
using glTracer_glGetVertexAttribIuiv = std::function<void(GLuint, GLenum, GLuint*)>;
void glGetVertexAttribIuiv_Traced(GLuint index, GLenum pname, GLuint* params);
#define glGetVertexAttribIuiv glGetVertexAttribIuiv_Traced
using glTracer_glVertexAttribI1i = std::function<void(GLuint, GLint)>;
void glVertexAttribI1i_Traced(GLuint index, GLint x);
#define glVertexAttribI1i glVertexAttribI1i_Traced
using glTracer_glVertexAttribI2i = std::function<void(GLuint, GLint, GLint)>;
void glVertexAttribI2i_Traced(GLuint index, GLint x, GLint y);
#define glVertexAttribI2i glVertexAttribI2i_Traced
using glTracer_glVertexAttribI3i = std::function<void(GLuint, GLint, GLint, GLint)>;
void glVertexAttribI3i_Traced(GLuint index, GLint x, GLint y, GLint z);
#define glVertexAttribI3i glVertexAttribI3i_Traced
using glTracer_glVertexAttribI4i = std::function<void(GLuint, GLint, GLint, GLint, GLint)>;
void glVertexAttribI4i_Traced(GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glVertexAttribI4i glVertexAttribI4i_Traced
using glTracer_glVertexAttribI1ui = std::function<void(GLuint, GLuint)>;
void glVertexAttribI1ui_Traced(GLuint index, GLuint x);
#define glVertexAttribI1ui glVertexAttribI1ui_Traced
using glTracer_glVertexAttribI2ui = std::function<void(GLuint, GLuint, GLuint)>;
void glVertexAttribI2ui_Traced(GLuint index, GLuint x, GLuint y);
#define glVertexAttribI2ui glVertexAttribI2ui_Traced
using glTracer_glVertexAttribI3ui = std::function<void(GLuint, GLuint, GLuint, GLuint)>;
void glVertexAttribI3ui_Traced(GLuint index, GLuint x, GLuint y, GLuint z);
#define glVertexAttribI3ui glVertexAttribI3ui_Traced
using glTracer_glVertexAttribI4ui = std::function<void(GLuint, GLuint, GLuint, GLuint, GLuint)>;
void glVertexAttribI4ui_Traced(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glVertexAttribI4ui glVertexAttribI4ui_Traced
using glTracer_glVertexAttribI1iv = std::function<void(GLuint, const GLint*)>;
void glVertexAttribI1iv_Traced(GLuint index, const GLint* v);
#define glVertexAttribI1iv glVertexAttribI1iv_Traced
using glTracer_glVertexAttribI2iv = std::function<void(GLuint, const GLint*)>;
void glVertexAttribI2iv_Traced(GLuint index, const GLint* v);
#define glVertexAttribI2iv glVertexAttribI2iv_Traced
using glTracer_glVertexAttribI3iv = std::function<void(GLuint, const GLint*)>;
void glVertexAttribI3iv_Traced(GLuint index, const GLint* v);
#define glVertexAttribI3iv glVertexAttribI3iv_Traced
using glTracer_glVertexAttribI4iv = std::function<void(GLuint, const GLint*)>;
void glVertexAttribI4iv_Traced(GLuint index, const GLint* v);
#define glVertexAttribI4iv glVertexAttribI4iv_Traced
using glTracer_glVertexAttribI1uiv = std::function<void(GLuint, const GLuint*)>;
void glVertexAttribI1uiv_Traced(GLuint index, const GLuint* v);
#define glVertexAttribI1uiv glVertexAttribI1uiv_Traced
using glTracer_glVertexAttribI2uiv = std::function<void(GLuint, const GLuint*)>;
void glVertexAttribI2uiv_Traced(GLuint index, const GLuint* v);
#define glVertexAttribI2uiv glVertexAttribI2uiv_Traced
using glTracer_glVertexAttribI3uiv = std::function<void(GLuint, const GLuint*)>;
void glVertexAttribI3uiv_Traced(GLuint index, const GLuint* v);
#define glVertexAttribI3uiv glVertexAttribI3uiv_Traced
using glTracer_glVertexAttribI4uiv = std::function<void(GLuint, const GLuint*)>;
void glVertexAttribI4uiv_Traced(GLuint index, const GLuint* v);
#define glVertexAttribI4uiv glVertexAttribI4uiv_Traced
using glTracer_glVertexAttribI4bv = std::function<void(GLuint, const GLbyte*)>;
void glVertexAttribI4bv_Traced(GLuint index, const GLbyte* v);
#define glVertexAttribI4bv glVertexAttribI4bv_Traced
using glTracer_glVertexAttribI4sv = std::function<void(GLuint, const GLshort*)>;
void glVertexAttribI4sv_Traced(GLuint index, const GLshort* v);
#define glVertexAttribI4sv glVertexAttribI4sv_Traced
using glTracer_glVertexAttribI4ubv = std::function<void(GLuint, const GLubyte*)>;
void glVertexAttribI4ubv_Traced(GLuint index, const GLubyte* v);
#define glVertexAttribI4ubv glVertexAttribI4ubv_Traced
using glTracer_glVertexAttribI4usv = std::function<void(GLuint, const GLushort*)>;
void glVertexAttribI4usv_Traced(GLuint index, const GLushort* v);
#define glVertexAttribI4usv glVertexAttribI4usv_Traced
using glTracer_glGetUniformuiv = std::function<void(GLuint, GLint, GLuint*)>;
void glGetUniformuiv_Traced(GLuint program, GLint location, GLuint* params);
#define glGetUniformuiv glGetUniformuiv_Traced
using glTracer_glBindFragDataLocation = std::function<void(GLuint, GLuint, const GLchar*)>;
void glBindFragDataLocation_Traced(GLuint program, GLuint color, const GLchar* name);
#define glBindFragDataLocation glBindFragDataLocation_Traced
using glTracer_glGetFragDataLocation = std::function<GLint(GLuint, const GLchar*)>;
GLint glGetFragDataLocation_Traced(GLuint program, const GLchar* name);
#define glGetFragDataLocation glGetFragDataLocation_Traced
using glTracer_glUniform1ui = std::function<void(GLint, GLuint)>;
void glUniform1ui_Traced(GLint location, GLuint v0);
#define glUniform1ui glUniform1ui_Traced
using glTracer_glUniform2ui = std::function<void(GLint, GLuint, GLuint)>;
void glUniform2ui_Traced(GLint location, GLuint v0, GLuint v1);
#define glUniform2ui glUniform2ui_Traced
using glTracer_glUniform3ui = std::function<void(GLint, GLuint, GLuint, GLuint)>;
void glUniform3ui_Traced(GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glUniform3ui glUniform3ui_Traced
using glTracer_glUniform4ui = std::function<void(GLint, GLuint, GLuint, GLuint, GLuint)>;
void glUniform4ui_Traced(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glUniform4ui glUniform4ui_Traced
using glTracer_glUniform1uiv = std::function<void(GLint, GLsizei, const GLuint*)>;
void glUniform1uiv_Traced(GLint location, GLsizei count, const GLuint* value);
#define glUniform1uiv glUniform1uiv_Traced
using glTracer_glUniform2uiv = std::function<void(GLint, GLsizei, const GLuint*)>;
void glUniform2uiv_Traced(GLint location, GLsizei count, const GLuint* value);
#define glUniform2uiv glUniform2uiv_Traced
using glTracer_glUniform3uiv = std::function<void(GLint, GLsizei, const GLuint*)>;
void glUniform3uiv_Traced(GLint location, GLsizei count, const GLuint* value);
#define glUniform3uiv glUniform3uiv_Traced
using glTracer_glUniform4uiv = std::function<void(GLint, GLsizei, const GLuint*)>;
void glUniform4uiv_Traced(GLint location, GLsizei count, const GLuint* value);
#define glUniform4uiv glUniform4uiv_Traced
using glTracer_glTexParameterIiv = std::function<void(GLenum, GLenum, const GLint*)>;
void glTexParameterIiv_Traced(GLenum target, GLenum pname, const GLint* params);
#define glTexParameterIiv glTexParameterIiv_Traced
using glTracer_glTexParameterIuiv = std::function<void(GLenum, GLenum, const GLuint*)>;
void glTexParameterIuiv_Traced(GLenum target, GLenum pname, const GLuint* params);
#define glTexParameterIuiv glTexParameterIuiv_Traced
using glTracer_glGetTexParameterIiv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetTexParameterIiv_Traced(GLenum target, GLenum pname, GLint* params);
#define glGetTexParameterIiv glGetTexParameterIiv_Traced
using glTracer_glGetTexParameterIuiv = std::function<void(GLenum, GLenum, GLuint*)>;
void glGetTexParameterIuiv_Traced(GLenum target, GLenum pname, GLuint* params);
#define glGetTexParameterIuiv glGetTexParameterIuiv_Traced
using glTracer_glClearBufferiv = std::function<void(GLenum, GLint, const GLint*)>;
void glClearBufferiv_Traced(GLenum buffer, GLint drawbuffer, const GLint* value);
#define glClearBufferiv glClearBufferiv_Traced
using glTracer_glClearBufferuiv = std::function<void(GLenum, GLint, const GLuint*)>;
void glClearBufferuiv_Traced(GLenum buffer, GLint drawbuffer, const GLuint* value);
#define glClearBufferuiv glClearBufferuiv_Traced
using glTracer_glClearBufferfv = std::function<void(GLenum, GLint, const GLfloat*)>;
void glClearBufferfv_Traced(GLenum buffer, GLint drawbuffer, const GLfloat* value);
#define glClearBufferfv glClearBufferfv_Traced
using glTracer_glClearBufferfi = std::function<void(GLenum, GLint, GLfloat, GLint)>;
void glClearBufferfi_Traced(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearBufferfi glClearBufferfi_Traced
using glTracer_glGetStringi = std::function<const GLubyte*(GLenum, GLuint)>;
const GLubyte* glGetStringi_Traced(GLenum name, GLuint index);
#define glGetStringi glGetStringi_Traced
using glTracer_glIsRenderbuffer = std::function<GLboolean(GLuint)>;
GLboolean glIsRenderbuffer_Traced(GLuint renderbuffer);
#define glIsRenderbuffer glIsRenderbuffer_Traced
using glTracer_glBindRenderbuffer = std::function<void(GLenum, GLuint)>;
void glBindRenderbuffer_Traced(GLenum target, GLuint renderbuffer);
#define glBindRenderbuffer glBindRenderbuffer_Traced
using glTracer_glDeleteRenderbuffers = std::function<void(GLsizei, const GLuint*)>;
void glDeleteRenderbuffers_Traced(GLsizei n, const GLuint* renderbuffers);
#define glDeleteRenderbuffers glDeleteRenderbuffers_Traced
using glTracer_glGenRenderbuffers = std::function<void(GLsizei, GLuint*)>;
void glGenRenderbuffers_Traced(GLsizei n, GLuint* renderbuffers);
#define glGenRenderbuffers glGenRenderbuffers_Traced
using glTracer_glRenderbufferStorage = std::function<void(GLenum, GLenum, GLsizei, GLsizei)>;
void glRenderbufferStorage_Traced(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorage glRenderbufferStorage_Traced
using glTracer_glGetRenderbufferParameteriv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetRenderbufferParameteriv_Traced(GLenum target, GLenum pname, GLint* params);
#define glGetRenderbufferParameteriv glGetRenderbufferParameteriv_Traced
using glTracer_glIsFramebuffer = std::function<GLboolean(GLuint)>;
GLboolean glIsFramebuffer_Traced(GLuint framebuffer);
#define glIsFramebuffer glIsFramebuffer_Traced
using glTracer_glBindFramebuffer = std::function<void(GLenum, GLuint)>;
void glBindFramebuffer_Traced(GLenum target, GLuint framebuffer);
#define glBindFramebuffer glBindFramebuffer_Traced
using glTracer_glDeleteFramebuffers = std::function<void(GLsizei, const GLuint*)>;
void glDeleteFramebuffers_Traced(GLsizei n, const GLuint* framebuffers);
#define glDeleteFramebuffers glDeleteFramebuffers_Traced
using glTracer_glGenFramebuffers = std::function<void(GLsizei, GLuint*)>;
void glGenFramebuffers_Traced(GLsizei n, GLuint* framebuffers);
#define glGenFramebuffers glGenFramebuffers_Traced
using glTracer_glCheckFramebufferStatus = std::function<GLenum(GLenum)>;
GLenum glCheckFramebufferStatus_Traced(GLenum target);
#define glCheckFramebufferStatus glCheckFramebufferStatus_Traced
using glTracer_glFramebufferTexture1D = std::function<void(GLenum, GLenum, GLenum, GLuint, GLint)>;
void glFramebufferTexture1D_Traced(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1D glFramebufferTexture1D_Traced
using glTracer_glFramebufferTexture2D = std::function<void(GLenum, GLenum, GLenum, GLuint, GLint)>;
void glFramebufferTexture2D_Traced(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2D glFramebufferTexture2D_Traced
using glTracer_glFramebufferTexture3D = std::function<void(GLenum, GLenum, GLenum, GLuint, GLint, GLint)>;
void glFramebufferTexture3D_Traced(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3D glFramebufferTexture3D_Traced
using glTracer_glFramebufferRenderbuffer = std::function<void(GLenum, GLenum, GLenum, GLuint)>;
void glFramebufferRenderbuffer_Traced(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbuffer glFramebufferRenderbuffer_Traced
using glTracer_glGetFramebufferAttachmentParameteriv = std::function<void(GLenum, GLenum, GLenum, GLint*)>;
void glGetFramebufferAttachmentParameteriv_Traced(GLenum target, GLenum attachment, GLenum pname, GLint* params);
#define glGetFramebufferAttachmentParameteriv glGetFramebufferAttachmentParameteriv_Traced
using glTracer_glGenerateMipmap = std::function<void(GLenum)>;
void glGenerateMipmap_Traced(GLenum target);
#define glGenerateMipmap glGenerateMipmap_Traced
using glTracer_glBlitFramebuffer = std::function<void(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum)>;
void glBlitFramebuffer_Traced(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebuffer glBlitFramebuffer_Traced
using glTracer_glRenderbufferStorageMultisample = std::function<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>;
void glRenderbufferStorageMultisample_Traced(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisample glRenderbufferStorageMultisample_Traced
using glTracer_glFramebufferTextureLayer = std::function<void(GLenum, GLenum, GLuint, GLint, GLint)>;
void glFramebufferTextureLayer_Traced(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayer glFramebufferTextureLayer_Traced
using glTracer_glMapBufferRange = std::function<void* (GLenum, GLintptr, GLsizeiptr, GLbitfield)>;
void* glMapBufferRange_Traced(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapBufferRange glMapBufferRange_Traced
using glTracer_glFlushMappedBufferRange = std::function<void(GLenum, GLintptr, GLsizeiptr)>;
void glFlushMappedBufferRange_Traced(GLenum target, GLintptr offset, GLsizeiptr length);
#define glFlushMappedBufferRange glFlushMappedBufferRange_Traced
using glTracer_glBindVertexArray = std::function<void(GLuint)>;
void glBindVertexArray_Traced(GLuint array);
#define glBindVertexArray glBindVertexArray_Traced
using glTracer_glDeleteVertexArrays = std::function<void(GLsizei, const GLuint*)>;
void glDeleteVertexArrays_Traced(GLsizei n, const GLuint* arrays);
#define glDeleteVertexArrays glDeleteVertexArrays_Traced
using glTracer_glGenVertexArrays = std::function<void(GLsizei, GLuint*)>;
void glGenVertexArrays_Traced(GLsizei n, GLuint* arrays);
#define glGenVertexArrays glGenVertexArrays_Traced
using glTracer_glIsVertexArray = std::function<GLboolean(GLuint)>;
GLboolean glIsVertexArray_Traced(GLuint array);
#define glIsVertexArray glIsVertexArray_Traced
using glTracer_glDrawArraysInstanced = std::function<void(GLenum, GLint, GLsizei, GLsizei)>;
void glDrawArraysInstanced_Traced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
#define glDrawArraysInstanced glDrawArraysInstanced_Traced
using glTracer_glDrawElementsInstanced = std::function<void(GLenum, GLsizei, GLenum, const void*, GLsizei)>;
void glDrawElementsInstanced_Traced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
#define glDrawElementsInstanced glDrawElementsInstanced_Traced
using glTracer_glTexBuffer = std::function<void(GLenum, GLenum, GLuint)>;
void glTexBuffer_Traced(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBuffer glTexBuffer_Traced
using glTracer_glPrimitiveRestartIndex = std::function<void(GLuint)>;
void glPrimitiveRestartIndex_Traced(GLuint index);
#define glPrimitiveRestartIndex glPrimitiveRestartIndex_Traced
using glTracer_glCopyBufferSubData = std::function<void(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr)>;
void glCopyBufferSubData_Traced(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyBufferSubData glCopyBufferSubData_Traced
using glTracer_glGetUniformIndices = std::function<void(GLuint, GLsizei, const GLchar* const*, GLuint*)>;
void glGetUniformIndices_Traced(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
#define glGetUniformIndices glGetUniformIndices_Traced
using glTracer_glGetActiveUniformsiv = std::function<void(GLuint, GLsizei, const GLuint*, GLenum, GLint*)>;
void glGetActiveUniformsiv_Traced(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
#define glGetActiveUniformsiv glGetActiveUniformsiv_Traced
using glTracer_glGetActiveUniformName = std::function<void(GLuint, GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetActiveUniformName_Traced(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
#define glGetActiveUniformName glGetActiveUniformName_Traced
using glTracer_glGetUniformBlockIndex = std::function<GLuint(GLuint, const GLchar*)>;
GLuint glGetUniformBlockIndex_Traced(GLuint program, const GLchar* uniformBlockName);
#define glGetUniformBlockIndex glGetUniformBlockIndex_Traced
using glTracer_glGetActiveUniformBlockiv = std::function<void(GLuint, GLuint, GLenum, GLint*)>;
void glGetActiveUniformBlockiv_Traced(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
#define glGetActiveUniformBlockiv glGetActiveUniformBlockiv_Traced
using glTracer_glGetActiveUniformBlockName = std::function<void(GLuint, GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetActiveUniformBlockName_Traced(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
#define glGetActiveUniformBlockName glGetActiveUniformBlockName_Traced
using glTracer_glUniformBlockBinding = std::function<void(GLuint, GLuint, GLuint)>;
void glUniformBlockBinding_Traced(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#define glUniformBlockBinding glUniformBlockBinding_Traced
using glTracer_glDrawElementsBaseVertex = std::function<void(GLenum, GLsizei, GLenum, const void*, GLint)>;
void glDrawElementsBaseVertex_Traced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
#define glDrawElementsBaseVertex glDrawElementsBaseVertex_Traced
using glTracer_glDrawRangeElementsBaseVertex = std::function<void(GLenum, GLuint, GLuint, GLsizei, GLenum, const void*, GLint)>;
void glDrawRangeElementsBaseVertex_Traced(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
#define glDrawRangeElementsBaseVertex glDrawRangeElementsBaseVertex_Traced
using glTracer_glDrawElementsInstancedBaseVertex = std::function<void(GLenum, GLsizei, GLenum, const void*, GLsizei, GLint)>;
void glDrawElementsInstancedBaseVertex_Traced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
#define glDrawElementsInstancedBaseVertex glDrawElementsInstancedBaseVertex_Traced
using glTracer_glMultiDrawElementsBaseVertex = std::function<void(GLenum, const GLsizei*, GLenum, const void* const*, GLsizei, const GLint*)>;
void glMultiDrawElementsBaseVertex_Traced(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
#define glMultiDrawElementsBaseVertex glMultiDrawElementsBaseVertex_Traced
using glTracer_glProvokingVertex = std::function<void(GLenum)>;
void glProvokingVertex_Traced(GLenum mode);
#define glProvokingVertex glProvokingVertex_Traced
using glTracer_glFenceSync = std::function<GLsync(GLenum, GLbitfield)>;
GLsync glFenceSync_Traced(GLenum condition, GLbitfield flags);
#define glFenceSync glFenceSync_Traced
using glTracer_glIsSync = std::function<GLboolean(GLsync)>;
GLboolean glIsSync_Traced(GLsync sync);
#define glIsSync glIsSync_Traced
using glTracer_glDeleteSync = std::function<void(GLsync)>;
void glDeleteSync_Traced(GLsync sync);
#define glDeleteSync glDeleteSync_Traced
using glTracer_glClientWaitSync = std::function<GLenum(GLsync, GLbitfield, GLuint64)>;
GLenum glClientWaitSync_Traced(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glClientWaitSync glClientWaitSync_Traced
using glTracer_glWaitSync = std::function<void(GLsync, GLbitfield, GLuint64)>;
void glWaitSync_Traced(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glWaitSync glWaitSync_Traced
using glTracer_glGetInteger64v = std::function<void(GLenum, GLint64*)>;
void glGetInteger64v_Traced(GLenum pname, GLint64* data);
#define glGetInteger64v glGetInteger64v_Traced
using glTracer_glGetSynciv = std::function<void(GLsync, GLenum, GLsizei, GLsizei*, GLint*)>;
void glGetSynciv_Traced(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
#define glGetSynciv glGetSynciv_Traced
using glTracer_glGetInteger64i_v = std::function<void(GLenum, GLuint, GLint64*)>;
void glGetInteger64i_v_Traced(GLenum target, GLuint index, GLint64* data);
#define glGetInteger64i_v glGetInteger64i_v_Traced
using glTracer_glGetBufferParameteri64v = std::function<void(GLenum, GLenum, GLint64*)>;
void glGetBufferParameteri64v_Traced(GLenum target, GLenum pname, GLint64* params);
#define glGetBufferParameteri64v glGetBufferParameteri64v_Traced
using glTracer_glFramebufferTexture = std::function<void(GLenum, GLenum, GLuint, GLint)>;
void glFramebufferTexture_Traced(GLenum target, GLenum attachment, GLuint texture, GLint level);
#define glFramebufferTexture glFramebufferTexture_Traced
using glTracer_glTexImage2DMultisample = std::function<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)>;
void glTexImage2DMultisample_Traced(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexImage2DMultisample glTexImage2DMultisample_Traced
using glTracer_glTexImage3DMultisample = std::function<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>;
void glTexImage3DMultisample_Traced(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexImage3DMultisample glTexImage3DMultisample_Traced
using glTracer_glGetMultisamplefv = std::function<void(GLenum, GLuint, GLfloat*)>;
void glGetMultisamplefv_Traced(GLenum pname, GLuint index, GLfloat* val);
#define glGetMultisamplefv glGetMultisamplefv_Traced
using glTracer_glSampleMaski = std::function<void(GLuint, GLbitfield)>;
void glSampleMaski_Traced(GLuint maskNumber, GLbitfield mask);
#define glSampleMaski glSampleMaski_Traced
using glTracer_glBindFragDataLocationIndexed = std::function<void(GLuint, GLuint, GLuint, const GLchar*)>;
void glBindFragDataLocationIndexed_Traced(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
#define glBindFragDataLocationIndexed glBindFragDataLocationIndexed_Traced
using glTracer_glGetFragDataIndex = std::function<GLint(GLuint, const GLchar*)>;
GLint glGetFragDataIndex_Traced(GLuint program, const GLchar* name);
#define glGetFragDataIndex glGetFragDataIndex_Traced
using glTracer_glGenSamplers = std::function<void(GLsizei, GLuint*)>;
void glGenSamplers_Traced(GLsizei count, GLuint* samplers);
#define glGenSamplers glGenSamplers_Traced
using glTracer_glDeleteSamplers = std::function<void(GLsizei, const GLuint*)>;
void glDeleteSamplers_Traced(GLsizei count, const GLuint* samplers);
#define glDeleteSamplers glDeleteSamplers_Traced
using glTracer_glIsSampler = std::function<GLboolean(GLuint)>;
GLboolean glIsSampler_Traced(GLuint sampler);
#define glIsSampler glIsSampler_Traced
using glTracer_glBindSampler = std::function<void(GLuint, GLuint)>;
void glBindSampler_Traced(GLuint unit, GLuint sampler);
#define glBindSampler glBindSampler_Traced
using glTracer_glSamplerParameteri = std::function<void(GLuint, GLenum, GLint)>;
void glSamplerParameteri_Traced(GLuint sampler, GLenum pname, GLint param);
#define glSamplerParameteri glSamplerParameteri_Traced
using glTracer_glSamplerParameteriv = std::function<void(GLuint, GLenum, const GLint*)>;
void glSamplerParameteriv_Traced(GLuint sampler, GLenum pname, const GLint* param);
#define glSamplerParameteriv glSamplerParameteriv_Traced
using glTracer_glSamplerParameterf = std::function<void(GLuint, GLenum, GLfloat)>;
void glSamplerParameterf_Traced(GLuint sampler, GLenum pname, GLfloat param);
#define glSamplerParameterf glSamplerParameterf_Traced
using glTracer_glSamplerParameterfv = std::function<void(GLuint, GLenum, const GLfloat*)>;
void glSamplerParameterfv_Traced(GLuint sampler, GLenum pname, const GLfloat* param);
#define glSamplerParameterfv glSamplerParameterfv_Traced
using glTracer_glSamplerParameterIiv = std::function<void(GLuint, GLenum, const GLint*)>;
void glSamplerParameterIiv_Traced(GLuint sampler, GLenum pname, const GLint* param);
#define glSamplerParameterIiv glSamplerParameterIiv_Traced
using glTracer_glSamplerParameterIuiv = std::function<void(GLuint, GLenum, const GLuint*)>;
void glSamplerParameterIuiv_Traced(GLuint sampler, GLenum pname, const GLuint* param);
#define glSamplerParameterIuiv glSamplerParameterIuiv_Traced
using glTracer_glGetSamplerParameteriv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetSamplerParameteriv_Traced(GLuint sampler, GLenum pname, GLint* params);
#define glGetSamplerParameteriv glGetSamplerParameteriv_Traced
using glTracer_glGetSamplerParameterIiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetSamplerParameterIiv_Traced(GLuint sampler, GLenum pname, GLint* params);
#define glGetSamplerParameterIiv glGetSamplerParameterIiv_Traced
using glTracer_glGetSamplerParameterfv = std::function<void(GLuint, GLenum, GLfloat*)>;
void glGetSamplerParameterfv_Traced(GLuint sampler, GLenum pname, GLfloat* params);
#define glGetSamplerParameterfv glGetSamplerParameterfv_Traced
using glTracer_glGetSamplerParameterIuiv = std::function<void(GLuint, GLenum, GLuint*)>;
void glGetSamplerParameterIuiv_Traced(GLuint sampler, GLenum pname, GLuint* params);
#define glGetSamplerParameterIuiv glGetSamplerParameterIuiv_Traced
using glTracer_glQueryCounter = std::function<void(GLuint, GLenum)>;
void glQueryCounter_Traced(GLuint id, GLenum target);
#define glQueryCounter glQueryCounter_Traced
using glTracer_glGetQueryObjecti64v = std::function<void(GLuint, GLenum, GLint64*)>;
void glGetQueryObjecti64v_Traced(GLuint id, GLenum pname, GLint64* params);
#define glGetQueryObjecti64v glGetQueryObjecti64v_Traced
using glTracer_glGetQueryObjectui64v = std::function<void(GLuint, GLenum, GLuint64*)>;
void glGetQueryObjectui64v_Traced(GLuint id, GLenum pname, GLuint64* params);
#define glGetQueryObjectui64v glGetQueryObjectui64v_Traced
using glTracer_glVertexAttribDivisor = std::function<void(GLuint, GLuint)>;
void glVertexAttribDivisor_Traced(GLuint index, GLuint divisor);
#define glVertexAttribDivisor glVertexAttribDivisor_Traced
using glTracer_glVertexAttribP1ui = std::function<void(GLuint, GLenum, GLboolean, GLuint)>;
void glVertexAttribP1ui_Traced(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP1ui glVertexAttribP1ui_Traced
using glTracer_glVertexAttribP1uiv = std::function<void(GLuint, GLenum, GLboolean, const GLuint*)>;
void glVertexAttribP1uiv_Traced(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#define glVertexAttribP1uiv glVertexAttribP1uiv_Traced
using glTracer_glVertexAttribP2ui = std::function<void(GLuint, GLenum, GLboolean, GLuint)>;
void glVertexAttribP2ui_Traced(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP2ui glVertexAttribP2ui_Traced
using glTracer_glVertexAttribP2uiv = std::function<void(GLuint, GLenum, GLboolean, const GLuint*)>;
void glVertexAttribP2uiv_Traced(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#define glVertexAttribP2uiv glVertexAttribP2uiv_Traced
using glTracer_glVertexAttribP3ui = std::function<void(GLuint, GLenum, GLboolean, GLuint)>;
void glVertexAttribP3ui_Traced(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP3ui glVertexAttribP3ui_Traced
using glTracer_glVertexAttribP3uiv = std::function<void(GLuint, GLenum, GLboolean, const GLuint*)>;
void glVertexAttribP3uiv_Traced(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#define glVertexAttribP3uiv glVertexAttribP3uiv_Traced
using glTracer_glVertexAttribP4ui = std::function<void(GLuint, GLenum, GLboolean, GLuint)>;
void glVertexAttribP4ui_Traced(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP4ui glVertexAttribP4ui_Traced
using glTracer_glVertexAttribP4uiv = std::function<void(GLuint, GLenum, GLboolean, const GLuint*)>;
void glVertexAttribP4uiv_Traced(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#define glVertexAttribP4uiv glVertexAttribP4uiv_Traced
using glTracer_glVertexP2ui = std::function<void(GLenum, GLuint)>;
void glVertexP2ui_Traced(GLenum type, GLuint value);
#define glVertexP2ui glVertexP2ui_Traced
using glTracer_glVertexP2uiv = std::function<void(GLenum, const GLuint*)>;
void glVertexP2uiv_Traced(GLenum type, const GLuint* value);
#define glVertexP2uiv glVertexP2uiv_Traced
using glTracer_glVertexP3ui = std::function<void(GLenum, GLuint)>;
void glVertexP3ui_Traced(GLenum type, GLuint value);
#define glVertexP3ui glVertexP3ui_Traced
using glTracer_glVertexP3uiv = std::function<void(GLenum, const GLuint*)>;
void glVertexP3uiv_Traced(GLenum type, const GLuint* value);
#define glVertexP3uiv glVertexP3uiv_Traced
using glTracer_glVertexP4ui = std::function<void(GLenum, GLuint)>;
void glVertexP4ui_Traced(GLenum type, GLuint value);
#define glVertexP4ui glVertexP4ui_Traced
using glTracer_glVertexP4uiv = std::function<void(GLenum, const GLuint*)>;
void glVertexP4uiv_Traced(GLenum type, const GLuint* value);
#define glVertexP4uiv glVertexP4uiv_Traced
using glTracer_glTexCoordP1ui = std::function<void(GLenum, GLuint)>;
void glTexCoordP1ui_Traced(GLenum type, GLuint coords);
#define glTexCoordP1ui glTexCoordP1ui_Traced
using glTracer_glTexCoordP1uiv = std::function<void(GLenum, const GLuint*)>;
void glTexCoordP1uiv_Traced(GLenum type, const GLuint* coords);
#define glTexCoordP1uiv glTexCoordP1uiv_Traced
using glTracer_glTexCoordP2ui = std::function<void(GLenum, GLuint)>;
void glTexCoordP2ui_Traced(GLenum type, GLuint coords);
#define glTexCoordP2ui glTexCoordP2ui_Traced
using glTracer_glTexCoordP2uiv = std::function<void(GLenum, const GLuint*)>;
void glTexCoordP2uiv_Traced(GLenum type, const GLuint* coords);
#define glTexCoordP2uiv glTexCoordP2uiv_Traced
using glTracer_glTexCoordP3ui = std::function<void(GLenum, GLuint)>;
void glTexCoordP3ui_Traced(GLenum type, GLuint coords);
#define glTexCoordP3ui glTexCoordP3ui_Traced
using glTracer_glTexCoordP3uiv = std::function<void(GLenum, const GLuint*)>;
void glTexCoordP3uiv_Traced(GLenum type, const GLuint* coords);
#define glTexCoordP3uiv glTexCoordP3uiv_Traced
using glTracer_glTexCoordP4ui = std::function<void(GLenum, GLuint)>;
void glTexCoordP4ui_Traced(GLenum type, GLuint coords);
#define glTexCoordP4ui glTexCoordP4ui_Traced
using glTracer_glTexCoordP4uiv = std::function<void(GLenum, const GLuint*)>;
void glTexCoordP4uiv_Traced(GLenum type, const GLuint* coords);
#define glTexCoordP4uiv glTexCoordP4uiv_Traced
using glTracer_glMultiTexCoordP1ui = std::function<void(GLenum, GLenum, GLuint)>;
void glMultiTexCoordP1ui_Traced(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP1ui glMultiTexCoordP1ui_Traced
using glTracer_glMultiTexCoordP1uiv = std::function<void(GLenum, GLenum, const GLuint*)>;
void glMultiTexCoordP1uiv_Traced(GLenum texture, GLenum type, const GLuint* coords);
#define glMultiTexCoordP1uiv glMultiTexCoordP1uiv_Traced
using glTracer_glMultiTexCoordP2ui = std::function<void(GLenum, GLenum, GLuint)>;
void glMultiTexCoordP2ui_Traced(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP2ui glMultiTexCoordP2ui_Traced
using glTracer_glMultiTexCoordP2uiv = std::function<void(GLenum, GLenum, const GLuint*)>;
void glMultiTexCoordP2uiv_Traced(GLenum texture, GLenum type, const GLuint* coords);
#define glMultiTexCoordP2uiv glMultiTexCoordP2uiv_Traced
using glTracer_glMultiTexCoordP3ui = std::function<void(GLenum, GLenum, GLuint)>;
void glMultiTexCoordP3ui_Traced(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP3ui glMultiTexCoordP3ui_Traced
using glTracer_glMultiTexCoordP3uiv = std::function<void(GLenum, GLenum, const GLuint*)>;
void glMultiTexCoordP3uiv_Traced(GLenum texture, GLenum type, const GLuint* coords);
#define glMultiTexCoordP3uiv glMultiTexCoordP3uiv_Traced
using glTracer_glMultiTexCoordP4ui = std::function<void(GLenum, GLenum, GLuint)>;
void glMultiTexCoordP4ui_Traced(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP4ui glMultiTexCoordP4ui_Traced
using glTracer_glMultiTexCoordP4uiv = std::function<void(GLenum, GLenum, const GLuint*)>;
void glMultiTexCoordP4uiv_Traced(GLenum texture, GLenum type, const GLuint* coords);
#define glMultiTexCoordP4uiv glMultiTexCoordP4uiv_Traced
using glTracer_glNormalP3ui = std::function<void(GLenum, GLuint)>;
void glNormalP3ui_Traced(GLenum type, GLuint coords);
#define glNormalP3ui glNormalP3ui_Traced
using glTracer_glNormalP3uiv = std::function<void(GLenum, const GLuint*)>;
void glNormalP3uiv_Traced(GLenum type, const GLuint* coords);
#define glNormalP3uiv glNormalP3uiv_Traced
using glTracer_glColorP3ui = std::function<void(GLenum, GLuint)>;
void glColorP3ui_Traced(GLenum type, GLuint color);
#define glColorP3ui glColorP3ui_Traced
using glTracer_glColorP3uiv = std::function<void(GLenum, const GLuint*)>;
void glColorP3uiv_Traced(GLenum type, const GLuint* color);
#define glColorP3uiv glColorP3uiv_Traced
using glTracer_glColorP4ui = std::function<void(GLenum, GLuint)>;
void glColorP4ui_Traced(GLenum type, GLuint color);
#define glColorP4ui glColorP4ui_Traced
using glTracer_glColorP4uiv = std::function<void(GLenum, const GLuint*)>;
void glColorP4uiv_Traced(GLenum type, const GLuint* color);
#define glColorP4uiv glColorP4uiv_Traced
using glTracer_glSecondaryColorP3ui = std::function<void(GLenum, GLuint)>;
void glSecondaryColorP3ui_Traced(GLenum type, GLuint color);
#define glSecondaryColorP3ui glSecondaryColorP3ui_Traced
using glTracer_glSecondaryColorP3uiv = std::function<void(GLenum, const GLuint*)>;
void glSecondaryColorP3uiv_Traced(GLenum type, const GLuint* color);
#define glSecondaryColorP3uiv glSecondaryColorP3uiv_Traced
using glTracer_glMinSampleShading = std::function<void(GLfloat)>;
void glMinSampleShading_Traced(GLfloat value);
#define glMinSampleShading glMinSampleShading_Traced
using glTracer_glBlendEquationi = std::function<void(GLuint, GLenum)>;
void glBlendEquationi_Traced(GLuint buf, GLenum mode);
#define glBlendEquationi glBlendEquationi_Traced
using glTracer_glBlendEquationSeparatei = std::function<void(GLuint, GLenum, GLenum)>;
void glBlendEquationSeparatei_Traced(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparatei glBlendEquationSeparatei_Traced
using glTracer_glBlendFunci = std::function<void(GLuint, GLenum, GLenum)>;
void glBlendFunci_Traced(GLuint buf, GLenum src, GLenum dst);
#define glBlendFunci glBlendFunci_Traced
using glTracer_glBlendFuncSeparatei = std::function<void(GLuint, GLenum, GLenum, GLenum, GLenum)>;
void glBlendFuncSeparatei_Traced(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#define glBlendFuncSeparatei glBlendFuncSeparatei_Traced
using glTracer_glDrawArraysIndirect = std::function<void(GLenum, const void*)>;
void glDrawArraysIndirect_Traced(GLenum mode, const void* indirect);
#define glDrawArraysIndirect glDrawArraysIndirect_Traced
using glTracer_glDrawElementsIndirect = std::function<void(GLenum, GLenum, const void*)>;
void glDrawElementsIndirect_Traced(GLenum mode, GLenum type, const void* indirect);
#define glDrawElementsIndirect glDrawElementsIndirect_Traced
using glTracer_glUniform1d = std::function<void(GLint, GLdouble)>;
void glUniform1d_Traced(GLint location, GLdouble x);
#define glUniform1d glUniform1d_Traced
using glTracer_glUniform2d = std::function<void(GLint, GLdouble, GLdouble)>;
void glUniform2d_Traced(GLint location, GLdouble x, GLdouble y);
#define glUniform2d glUniform2d_Traced
using glTracer_glUniform3d = std::function<void(GLint, GLdouble, GLdouble, GLdouble)>;
void glUniform3d_Traced(GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glUniform3d glUniform3d_Traced
using glTracer_glUniform4d = std::function<void(GLint, GLdouble, GLdouble, GLdouble, GLdouble)>;
void glUniform4d_Traced(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glUniform4d glUniform4d_Traced
using glTracer_glUniform1dv = std::function<void(GLint, GLsizei, const GLdouble*)>;
void glUniform1dv_Traced(GLint location, GLsizei count, const GLdouble* value);
#define glUniform1dv glUniform1dv_Traced
using glTracer_glUniform2dv = std::function<void(GLint, GLsizei, const GLdouble*)>;
void glUniform2dv_Traced(GLint location, GLsizei count, const GLdouble* value);
#define glUniform2dv glUniform2dv_Traced
using glTracer_glUniform3dv = std::function<void(GLint, GLsizei, const GLdouble*)>;
void glUniform3dv_Traced(GLint location, GLsizei count, const GLdouble* value);
#define glUniform3dv glUniform3dv_Traced
using glTracer_glUniform4dv = std::function<void(GLint, GLsizei, const GLdouble*)>;
void glUniform4dv_Traced(GLint location, GLsizei count, const GLdouble* value);
#define glUniform4dv glUniform4dv_Traced
using glTracer_glUniformMatrix2dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix2dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix2dv glUniformMatrix2dv_Traced
using glTracer_glUniformMatrix3dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix3dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix3dv glUniformMatrix3dv_Traced
using glTracer_glUniformMatrix4dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix4dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix4dv glUniformMatrix4dv_Traced
using glTracer_glUniformMatrix2x3dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix2x3dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix2x3dv glUniformMatrix2x3dv_Traced
using glTracer_glUniformMatrix2x4dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix2x4dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix2x4dv glUniformMatrix2x4dv_Traced
using glTracer_glUniformMatrix3x2dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix3x2dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix3x2dv glUniformMatrix3x2dv_Traced
using glTracer_glUniformMatrix3x4dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix3x4dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix3x4dv glUniformMatrix3x4dv_Traced
using glTracer_glUniformMatrix4x2dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix4x2dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix4x2dv glUniformMatrix4x2dv_Traced
using glTracer_glUniformMatrix4x3dv = std::function<void(GLint, GLsizei, GLboolean, const GLdouble*)>;
void glUniformMatrix4x3dv_Traced(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glUniformMatrix4x3dv glUniformMatrix4x3dv_Traced
using glTracer_glGetUniformdv = std::function<void(GLuint, GLint, GLdouble*)>;
void glGetUniformdv_Traced(GLuint program, GLint location, GLdouble* params);
#define glGetUniformdv glGetUniformdv_Traced
using glTracer_glGetSubroutineUniformLocation = std::function<GLint(GLuint, GLenum, const GLchar*)>;
GLint glGetSubroutineUniformLocation_Traced(GLuint program, GLenum shadertype, const GLchar* name);
#define glGetSubroutineUniformLocation glGetSubroutineUniformLocation_Traced
using glTracer_glGetSubroutineIndex = std::function<GLuint(GLuint, GLenum, const GLchar*)>;
GLuint glGetSubroutineIndex_Traced(GLuint program, GLenum shadertype, const GLchar* name);
#define glGetSubroutineIndex glGetSubroutineIndex_Traced
using glTracer_glGetActiveSubroutineUniformiv = std::function<void(GLuint, GLenum, GLuint, GLenum, GLint*)>;
void glGetActiveSubroutineUniformiv_Traced(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
#define glGetActiveSubroutineUniformiv glGetActiveSubroutineUniformiv_Traced
using glTracer_glGetActiveSubroutineUniformName = std::function<void(GLuint, GLenum, GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetActiveSubroutineUniformName_Traced(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
#define glGetActiveSubroutineUniformName glGetActiveSubroutineUniformName_Traced
using glTracer_glGetActiveSubroutineName = std::function<void(GLuint, GLenum, GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetActiveSubroutineName_Traced(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
#define glGetActiveSubroutineName glGetActiveSubroutineName_Traced
using glTracer_glUniformSubroutinesuiv = std::function<void(GLenum, GLsizei, const GLuint*)>;
void glUniformSubroutinesuiv_Traced(GLenum shadertype, GLsizei count, const GLuint* indices);
#define glUniformSubroutinesuiv glUniformSubroutinesuiv_Traced
using glTracer_glGetUniformSubroutineuiv = std::function<void(GLenum, GLint, GLuint*)>;
void glGetUniformSubroutineuiv_Traced(GLenum shadertype, GLint location, GLuint* params);
#define glGetUniformSubroutineuiv glGetUniformSubroutineuiv_Traced
using glTracer_glGetProgramStageiv = std::function<void(GLuint, GLenum, GLenum, GLint*)>;
void glGetProgramStageiv_Traced(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
#define glGetProgramStageiv glGetProgramStageiv_Traced
using glTracer_glPatchParameteri = std::function<void(GLenum, GLint)>;
void glPatchParameteri_Traced(GLenum pname, GLint value);
#define glPatchParameteri glPatchParameteri_Traced
using glTracer_glPatchParameterfv = std::function<void(GLenum, const GLfloat*)>;
void glPatchParameterfv_Traced(GLenum pname, const GLfloat* values);
#define glPatchParameterfv glPatchParameterfv_Traced
using glTracer_glBindTransformFeedback = std::function<void(GLenum, GLuint)>;
void glBindTransformFeedback_Traced(GLenum target, GLuint id);
#define glBindTransformFeedback glBindTransformFeedback_Traced
using glTracer_glDeleteTransformFeedbacks = std::function<void(GLsizei, const GLuint*)>;
void glDeleteTransformFeedbacks_Traced(GLsizei n, const GLuint* ids);
#define glDeleteTransformFeedbacks glDeleteTransformFeedbacks_Traced
using glTracer_glGenTransformFeedbacks = std::function<void(GLsizei, GLuint*)>;
void glGenTransformFeedbacks_Traced(GLsizei n, GLuint* ids);
#define glGenTransformFeedbacks glGenTransformFeedbacks_Traced
using glTracer_glIsTransformFeedback = std::function<GLboolean(GLuint)>;
GLboolean glIsTransformFeedback_Traced(GLuint id);
#define glIsTransformFeedback glIsTransformFeedback_Traced
using glTracer_glPauseTransformFeedback = std::function<void()>;
void glPauseTransformFeedback_Traced();
#define glPauseTransformFeedback glPauseTransformFeedback_Traced
using glTracer_glResumeTransformFeedback = std::function<void()>;
void glResumeTransformFeedback_Traced();
#define glResumeTransformFeedback glResumeTransformFeedback_Traced
using glTracer_glDrawTransformFeedback = std::function<void(GLenum, GLuint)>;
void glDrawTransformFeedback_Traced(GLenum mode, GLuint id);
#define glDrawTransformFeedback glDrawTransformFeedback_Traced
using glTracer_glDrawTransformFeedbackStream = std::function<void(GLenum, GLuint, GLuint)>;
void glDrawTransformFeedbackStream_Traced(GLenum mode, GLuint id, GLuint stream);
#define glDrawTransformFeedbackStream glDrawTransformFeedbackStream_Traced
using glTracer_glBeginQueryIndexed = std::function<void(GLenum, GLuint, GLuint)>;
void glBeginQueryIndexed_Traced(GLenum target, GLuint index, GLuint id);
#define glBeginQueryIndexed glBeginQueryIndexed_Traced
using glTracer_glEndQueryIndexed = std::function<void(GLenum, GLuint)>;
void glEndQueryIndexed_Traced(GLenum target, GLuint index);
#define glEndQueryIndexed glEndQueryIndexed_Traced
using glTracer_glGetQueryIndexediv = std::function<void(GLenum, GLuint, GLenum, GLint*)>;
void glGetQueryIndexediv_Traced(GLenum target, GLuint index, GLenum pname, GLint* params);
#define glGetQueryIndexediv glGetQueryIndexediv_Traced
using glTracer_glReleaseShaderCompiler = std::function<void()>;
void glReleaseShaderCompiler_Traced();
#define glReleaseShaderCompiler glReleaseShaderCompiler_Traced
using glTracer_glShaderBinary = std::function<void(GLsizei, const GLuint*, GLenum, const void*, GLsizei)>;
void glShaderBinary_Traced(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length);
#define glShaderBinary glShaderBinary_Traced
using glTracer_glGetShaderPrecisionFormat = std::function<void(GLenum, GLenum, GLint*, GLint*)>;
void glGetShaderPrecisionFormat_Traced(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
#define glGetShaderPrecisionFormat glGetShaderPrecisionFormat_Traced
using glTracer_glDepthRangef = std::function<void(GLfloat, GLfloat)>;
void glDepthRangef_Traced(GLfloat n, GLfloat f);
#define glDepthRangef glDepthRangef_Traced
using glTracer_glClearDepthf = std::function<void(GLfloat)>;
void glClearDepthf_Traced(GLfloat d);
#define glClearDepthf glClearDepthf_Traced
using glTracer_glGetProgramBinary = std::function<void(GLuint, GLsizei, GLsizei*, GLenum*, void*)>;
void glGetProgramBinary_Traced(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary);
#define glGetProgramBinary glGetProgramBinary_Traced
using glTracer_glProgramBinary = std::function<void(GLuint, GLenum, const void*, GLsizei)>;
void glProgramBinary_Traced(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length);
#define glProgramBinary glProgramBinary_Traced
using glTracer_glProgramParameteri = std::function<void(GLuint, GLenum, GLint)>;
void glProgramParameteri_Traced(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri glProgramParameteri_Traced
using glTracer_glUseProgramStages = std::function<void(GLuint, GLbitfield, GLuint)>;
void glUseProgramStages_Traced(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStages glUseProgramStages_Traced
using glTracer_glActiveShaderProgram = std::function<void(GLuint, GLuint)>;
void glActiveShaderProgram_Traced(GLuint pipeline, GLuint program);
#define glActiveShaderProgram glActiveShaderProgram_Traced
using glTracer_glCreateShaderProgramv = std::function<GLuint(GLenum, GLsizei, const GLchar* const*)>;
GLuint glCreateShaderProgramv_Traced(GLenum type, GLsizei count, const GLchar* const* strings);
#define glCreateShaderProgramv glCreateShaderProgramv_Traced
using glTracer_glBindProgramPipeline = std::function<void(GLuint)>;
void glBindProgramPipeline_Traced(GLuint pipeline);
#define glBindProgramPipeline glBindProgramPipeline_Traced
using glTracer_glDeleteProgramPipelines = std::function<void(GLsizei, const GLuint*)>;
void glDeleteProgramPipelines_Traced(GLsizei n, const GLuint* pipelines);
#define glDeleteProgramPipelines glDeleteProgramPipelines_Traced
using glTracer_glGenProgramPipelines = std::function<void(GLsizei, GLuint*)>;
void glGenProgramPipelines_Traced(GLsizei n, GLuint* pipelines);
#define glGenProgramPipelines glGenProgramPipelines_Traced
using glTracer_glIsProgramPipeline = std::function<GLboolean(GLuint)>;
GLboolean glIsProgramPipeline_Traced(GLuint pipeline);
#define glIsProgramPipeline glIsProgramPipeline_Traced
using glTracer_glGetProgramPipelineiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetProgramPipelineiv_Traced(GLuint pipeline, GLenum pname, GLint* params);
#define glGetProgramPipelineiv glGetProgramPipelineiv_Traced
using glTracer_glProgramUniform1i = std::function<void(GLuint, GLint, GLint)>;
void glProgramUniform1i_Traced(GLuint program, GLint location, GLint v0);
#define glProgramUniform1i glProgramUniform1i_Traced
using glTracer_glProgramUniform1iv = std::function<void(GLuint, GLint, GLsizei, const GLint*)>;
void glProgramUniform1iv_Traced(GLuint program, GLint location, GLsizei count, const GLint* value);
#define glProgramUniform1iv glProgramUniform1iv_Traced
using glTracer_glProgramUniform1f = std::function<void(GLuint, GLint, GLfloat)>;
void glProgramUniform1f_Traced(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1f glProgramUniform1f_Traced
using glTracer_glProgramUniform1fv = std::function<void(GLuint, GLint, GLsizei, const GLfloat*)>;
void glProgramUniform1fv_Traced(GLuint program, GLint location, GLsizei count, const GLfloat* value);
#define glProgramUniform1fv glProgramUniform1fv_Traced
using glTracer_glProgramUniform1d = std::function<void(GLuint, GLint, GLdouble)>;
void glProgramUniform1d_Traced(GLuint program, GLint location, GLdouble v0);
#define glProgramUniform1d glProgramUniform1d_Traced
using glTracer_glProgramUniform1dv = std::function<void(GLuint, GLint, GLsizei, const GLdouble*)>;
void glProgramUniform1dv_Traced(GLuint program, GLint location, GLsizei count, const GLdouble* value);
#define glProgramUniform1dv glProgramUniform1dv_Traced
using glTracer_glProgramUniform1ui = std::function<void(GLuint, GLint, GLuint)>;
void glProgramUniform1ui_Traced(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1ui glProgramUniform1ui_Traced
using glTracer_glProgramUniform1uiv = std::function<void(GLuint, GLint, GLsizei, const GLuint*)>;
void glProgramUniform1uiv_Traced(GLuint program, GLint location, GLsizei count, const GLuint* value);
#define glProgramUniform1uiv glProgramUniform1uiv_Traced
using glTracer_glProgramUniform2i = std::function<void(GLuint, GLint, GLint, GLint)>;
void glProgramUniform2i_Traced(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2i glProgramUniform2i_Traced
using glTracer_glProgramUniform2iv = std::function<void(GLuint, GLint, GLsizei, const GLint*)>;
void glProgramUniform2iv_Traced(GLuint program, GLint location, GLsizei count, const GLint* value);
#define glProgramUniform2iv glProgramUniform2iv_Traced
using glTracer_glProgramUniform2f = std::function<void(GLuint, GLint, GLfloat, GLfloat)>;
void glProgramUniform2f_Traced(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2f glProgramUniform2f_Traced
using glTracer_glProgramUniform2fv = std::function<void(GLuint, GLint, GLsizei, const GLfloat*)>;
void glProgramUniform2fv_Traced(GLuint program, GLint location, GLsizei count, const GLfloat* value);
#define glProgramUniform2fv glProgramUniform2fv_Traced
using glTracer_glProgramUniform2d = std::function<void(GLuint, GLint, GLdouble, GLdouble)>;
void glProgramUniform2d_Traced(GLuint program, GLint location, GLdouble v0, GLdouble v1);
#define glProgramUniform2d glProgramUniform2d_Traced
using glTracer_glProgramUniform2dv = std::function<void(GLuint, GLint, GLsizei, const GLdouble*)>;
void glProgramUniform2dv_Traced(GLuint program, GLint location, GLsizei count, const GLdouble* value);
#define glProgramUniform2dv glProgramUniform2dv_Traced
using glTracer_glProgramUniform2ui = std::function<void(GLuint, GLint, GLuint, GLuint)>;
void glProgramUniform2ui_Traced(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2ui glProgramUniform2ui_Traced
using glTracer_glProgramUniform2uiv = std::function<void(GLuint, GLint, GLsizei, const GLuint*)>;
void glProgramUniform2uiv_Traced(GLuint program, GLint location, GLsizei count, const GLuint* value);
#define glProgramUniform2uiv glProgramUniform2uiv_Traced
using glTracer_glProgramUniform3i = std::function<void(GLuint, GLint, GLint, GLint, GLint)>;
void glProgramUniform3i_Traced(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3i glProgramUniform3i_Traced
using glTracer_glProgramUniform3iv = std::function<void(GLuint, GLint, GLsizei, const GLint*)>;
void glProgramUniform3iv_Traced(GLuint program, GLint location, GLsizei count, const GLint* value);
#define glProgramUniform3iv glProgramUniform3iv_Traced
using glTracer_glProgramUniform3f = std::function<void(GLuint, GLint, GLfloat, GLfloat, GLfloat)>;
void glProgramUniform3f_Traced(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3f glProgramUniform3f_Traced
using glTracer_glProgramUniform3fv = std::function<void(GLuint, GLint, GLsizei, const GLfloat*)>;
void glProgramUniform3fv_Traced(GLuint program, GLint location, GLsizei count, const GLfloat* value);
#define glProgramUniform3fv glProgramUniform3fv_Traced
using glTracer_glProgramUniform3d = std::function<void(GLuint, GLint, GLdouble, GLdouble, GLdouble)>;
void glProgramUniform3d_Traced(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
#define glProgramUniform3d glProgramUniform3d_Traced
using glTracer_glProgramUniform3dv = std::function<void(GLuint, GLint, GLsizei, const GLdouble*)>;
void glProgramUniform3dv_Traced(GLuint program, GLint location, GLsizei count, const GLdouble* value);
#define glProgramUniform3dv glProgramUniform3dv_Traced
using glTracer_glProgramUniform3ui = std::function<void(GLuint, GLint, GLuint, GLuint, GLuint)>;
void glProgramUniform3ui_Traced(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3ui glProgramUniform3ui_Traced
using glTracer_glProgramUniform3uiv = std::function<void(GLuint, GLint, GLsizei, const GLuint*)>;
void glProgramUniform3uiv_Traced(GLuint program, GLint location, GLsizei count, const GLuint* value);
#define glProgramUniform3uiv glProgramUniform3uiv_Traced
using glTracer_glProgramUniform4i = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLint)>;
void glProgramUniform4i_Traced(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4i glProgramUniform4i_Traced
using glTracer_glProgramUniform4iv = std::function<void(GLuint, GLint, GLsizei, const GLint*)>;
void glProgramUniform4iv_Traced(GLuint program, GLint location, GLsizei count, const GLint* value);
#define glProgramUniform4iv glProgramUniform4iv_Traced
using glTracer_glProgramUniform4f = std::function<void(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat)>;
void glProgramUniform4f_Traced(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4f glProgramUniform4f_Traced
using glTracer_glProgramUniform4fv = std::function<void(GLuint, GLint, GLsizei, const GLfloat*)>;
void glProgramUniform4fv_Traced(GLuint program, GLint location, GLsizei count, const GLfloat* value);
#define glProgramUniform4fv glProgramUniform4fv_Traced
using glTracer_glProgramUniform4d = std::function<void(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble)>;
void glProgramUniform4d_Traced(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
#define glProgramUniform4d glProgramUniform4d_Traced
using glTracer_glProgramUniform4dv = std::function<void(GLuint, GLint, GLsizei, const GLdouble*)>;
void glProgramUniform4dv_Traced(GLuint program, GLint location, GLsizei count, const GLdouble* value);
#define glProgramUniform4dv glProgramUniform4dv_Traced
using glTracer_glProgramUniform4ui = std::function<void(GLuint, GLint, GLuint, GLuint, GLuint, GLuint)>;
void glProgramUniform4ui_Traced(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4ui glProgramUniform4ui_Traced
using glTracer_glProgramUniform4uiv = std::function<void(GLuint, GLint, GLsizei, const GLuint*)>;
void glProgramUniform4uiv_Traced(GLuint program, GLint location, GLsizei count, const GLuint* value);
#define glProgramUniform4uiv glProgramUniform4uiv_Traced
using glTracer_glProgramUniformMatrix2fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix2fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix2fv glProgramUniformMatrix2fv_Traced
using glTracer_glProgramUniformMatrix3fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix3fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix3fv glProgramUniformMatrix3fv_Traced
using glTracer_glProgramUniformMatrix4fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix4fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix4fv glProgramUniformMatrix4fv_Traced
using glTracer_glProgramUniformMatrix2dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix2dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix2dv glProgramUniformMatrix2dv_Traced
using glTracer_glProgramUniformMatrix3dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix3dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix3dv glProgramUniformMatrix3dv_Traced
using glTracer_glProgramUniformMatrix4dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix4dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix4dv glProgramUniformMatrix4dv_Traced
using glTracer_glProgramUniformMatrix2x3fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix2x3fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix2x3fv glProgramUniformMatrix2x3fv_Traced
using glTracer_glProgramUniformMatrix3x2fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix3x2fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix3x2fv glProgramUniformMatrix3x2fv_Traced
using glTracer_glProgramUniformMatrix2x4fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix2x4fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix2x4fv glProgramUniformMatrix2x4fv_Traced
using glTracer_glProgramUniformMatrix4x2fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix4x2fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix4x2fv glProgramUniformMatrix4x2fv_Traced
using glTracer_glProgramUniformMatrix3x4fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix3x4fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix3x4fv glProgramUniformMatrix3x4fv_Traced
using glTracer_glProgramUniformMatrix4x3fv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat*)>;
void glProgramUniformMatrix4x3fv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#define glProgramUniformMatrix4x3fv glProgramUniformMatrix4x3fv_Traced
using glTracer_glProgramUniformMatrix2x3dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix2x3dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix2x3dv glProgramUniformMatrix2x3dv_Traced
using glTracer_glProgramUniformMatrix3x2dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix3x2dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix3x2dv glProgramUniformMatrix3x2dv_Traced
using glTracer_glProgramUniformMatrix2x4dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix2x4dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix2x4dv glProgramUniformMatrix2x4dv_Traced
using glTracer_glProgramUniformMatrix4x2dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix4x2dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix4x2dv glProgramUniformMatrix4x2dv_Traced
using glTracer_glProgramUniformMatrix3x4dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix3x4dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix3x4dv glProgramUniformMatrix3x4dv_Traced
using glTracer_glProgramUniformMatrix4x3dv = std::function<void(GLuint, GLint, GLsizei, GLboolean, const GLdouble*)>;
void glProgramUniformMatrix4x3dv_Traced(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
#define glProgramUniformMatrix4x3dv glProgramUniformMatrix4x3dv_Traced
using glTracer_glValidateProgramPipeline = std::function<void(GLuint)>;
void glValidateProgramPipeline_Traced(GLuint pipeline);
#define glValidateProgramPipeline glValidateProgramPipeline_Traced
using glTracer_glGetProgramPipelineInfoLog = std::function<void(GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetProgramPipelineInfoLog_Traced(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
#define glGetProgramPipelineInfoLog glGetProgramPipelineInfoLog_Traced
using glTracer_glVertexAttribL1d = std::function<void(GLuint, GLdouble)>;
void glVertexAttribL1d_Traced(GLuint index, GLdouble x);
#define glVertexAttribL1d glVertexAttribL1d_Traced
using glTracer_glVertexAttribL2d = std::function<void(GLuint, GLdouble, GLdouble)>;
void glVertexAttribL2d_Traced(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2d glVertexAttribL2d_Traced
using glTracer_glVertexAttribL3d = std::function<void(GLuint, GLdouble, GLdouble, GLdouble)>;
void glVertexAttribL3d_Traced(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3d glVertexAttribL3d_Traced
using glTracer_glVertexAttribL4d = std::function<void(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>;
void glVertexAttribL4d_Traced(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4d glVertexAttribL4d_Traced
using glTracer_glVertexAttribL1dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttribL1dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttribL1dv glVertexAttribL1dv_Traced
using glTracer_glVertexAttribL2dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttribL2dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttribL2dv glVertexAttribL2dv_Traced
using glTracer_glVertexAttribL3dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttribL3dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttribL3dv glVertexAttribL3dv_Traced
using glTracer_glVertexAttribL4dv = std::function<void(GLuint, const GLdouble*)>;
void glVertexAttribL4dv_Traced(GLuint index, const GLdouble* v);
#define glVertexAttribL4dv glVertexAttribL4dv_Traced
using glTracer_glVertexAttribLPointer = std::function<void(GLuint, GLint, GLenum, GLsizei, const void*)>;
void glVertexAttribLPointer_Traced(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
#define glVertexAttribLPointer glVertexAttribLPointer_Traced
using glTracer_glGetVertexAttribLdv = std::function<void(GLuint, GLenum, GLdouble*)>;
void glGetVertexAttribLdv_Traced(GLuint index, GLenum pname, GLdouble* params);
#define glGetVertexAttribLdv glGetVertexAttribLdv_Traced
using glTracer_glViewportArrayv = std::function<void(GLuint, GLsizei, const GLfloat*)>;
void glViewportArrayv_Traced(GLuint first, GLsizei count, const GLfloat* v);
#define glViewportArrayv glViewportArrayv_Traced
using glTracer_glViewportIndexedf = std::function<void(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>;
void glViewportIndexedf_Traced(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
#define glViewportIndexedf glViewportIndexedf_Traced
using glTracer_glViewportIndexedfv = std::function<void(GLuint, const GLfloat*)>;
void glViewportIndexedfv_Traced(GLuint index, const GLfloat* v);
#define glViewportIndexedfv glViewportIndexedfv_Traced
using glTracer_glScissorArrayv = std::function<void(GLuint, GLsizei, const GLint*)>;
void glScissorArrayv_Traced(GLuint first, GLsizei count, const GLint* v);
#define glScissorArrayv glScissorArrayv_Traced
using glTracer_glScissorIndexed = std::function<void(GLuint, GLint, GLint, GLsizei, GLsizei)>;
void glScissorIndexed_Traced(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
#define glScissorIndexed glScissorIndexed_Traced
using glTracer_glScissorIndexedv = std::function<void(GLuint, const GLint*)>;
void glScissorIndexedv_Traced(GLuint index, const GLint* v);
#define glScissorIndexedv glScissorIndexedv_Traced
using glTracer_glDepthRangeArrayv = std::function<void(GLuint, GLsizei, const GLdouble*)>;
void glDepthRangeArrayv_Traced(GLuint first, GLsizei count, const GLdouble* v);
#define glDepthRangeArrayv glDepthRangeArrayv_Traced
using glTracer_glDepthRangeIndexed = std::function<void(GLuint, GLdouble, GLdouble)>;
void glDepthRangeIndexed_Traced(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexed glDepthRangeIndexed_Traced
using glTracer_glGetFloati_v = std::function<void(GLenum, GLuint, GLfloat*)>;
void glGetFloati_v_Traced(GLenum target, GLuint index, GLfloat* data);
#define glGetFloati_v glGetFloati_v_Traced
using glTracer_glGetDoublei_v = std::function<void(GLenum, GLuint, GLdouble*)>;
void glGetDoublei_v_Traced(GLenum target, GLuint index, GLdouble* data);
#define glGetDoublei_v glGetDoublei_v_Traced
using glTracer_glDrawArraysInstancedBaseInstance = std::function<void(GLenum, GLint, GLsizei, GLsizei, GLuint)>;
void glDrawArraysInstancedBaseInstance_Traced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
#define glDrawArraysInstancedBaseInstance glDrawArraysInstancedBaseInstance_Traced
using glTracer_glDrawElementsInstancedBaseInstance = std::function<void(GLenum, GLsizei, GLenum, const void*, GLsizei, GLuint)>;
void glDrawElementsInstancedBaseInstance_Traced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
#define glDrawElementsInstancedBaseInstance glDrawElementsInstancedBaseInstance_Traced
using glTracer_glDrawElementsInstancedBaseVertexBaseInstance = std::function<void(GLenum, GLsizei, GLenum, const void*, GLsizei, GLint, GLuint)>;
void glDrawElementsInstancedBaseVertexBaseInstance_Traced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#define glDrawElementsInstancedBaseVertexBaseInstance glDrawElementsInstancedBaseVertexBaseInstance_Traced
using glTracer_glGetInternalformativ = std::function<void(GLenum, GLenum, GLenum, GLsizei, GLint*)>;
void glGetInternalformativ_Traced(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params);
#define glGetInternalformativ glGetInternalformativ_Traced
using glTracer_glGetActiveAtomicCounterBufferiv = std::function<void(GLuint, GLuint, GLenum, GLint*)>;
void glGetActiveAtomicCounterBufferiv_Traced(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
#define glGetActiveAtomicCounterBufferiv glGetActiveAtomicCounterBufferiv_Traced
using glTracer_glBindImageTexture = std::function<void(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum)>;
void glBindImageTexture_Traced(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
#define glBindImageTexture glBindImageTexture_Traced
using glTracer_glMemoryBarrier = std::function<void(GLbitfield)>;
void glMemoryBarrier_Traced(GLbitfield barriers);
#define glMemoryBarrier glMemoryBarrier_Traced
using glTracer_glTexStorage1D = std::function<void(GLenum, GLsizei, GLenum, GLsizei)>;
void glTexStorage1D_Traced(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1D glTexStorage1D_Traced
using glTracer_glTexStorage2D = std::function<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>;
void glTexStorage2D_Traced(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2D glTexStorage2D_Traced
using glTracer_glTexStorage3D = std::function<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)>;
void glTexStorage3D_Traced(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3D glTexStorage3D_Traced
using glTracer_glDrawTransformFeedbackInstanced = std::function<void(GLenum, GLuint, GLsizei)>;
void glDrawTransformFeedbackInstanced_Traced(GLenum mode, GLuint id, GLsizei instancecount);
#define glDrawTransformFeedbackInstanced glDrawTransformFeedbackInstanced_Traced
using glTracer_glDrawTransformFeedbackStreamInstanced = std::function<void(GLenum, GLuint, GLuint, GLsizei)>;
void glDrawTransformFeedbackStreamInstanced_Traced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#define glDrawTransformFeedbackStreamInstanced glDrawTransformFeedbackStreamInstanced_Traced
using glTracer_glClearBufferData = std::function<void(GLenum, GLenum, GLenum, GLenum, const void*)>;
void glClearBufferData_Traced(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
#define glClearBufferData glClearBufferData_Traced
using glTracer_glClearBufferSubData = std::function<void(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void*)>;
void glClearBufferSubData_Traced(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
#define glClearBufferSubData glClearBufferSubData_Traced
using glTracer_glDispatchCompute = std::function<void(GLuint, GLuint, GLuint)>;
void glDispatchCompute_Traced(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
#define glDispatchCompute glDispatchCompute_Traced
using glTracer_glDispatchComputeIndirect = std::function<void(GLintptr)>;
void glDispatchComputeIndirect_Traced(GLintptr indirect);
#define glDispatchComputeIndirect glDispatchComputeIndirect_Traced
using glTracer_glCopyImageSubData = std::function<void(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)>;
void glCopyImageSubData_Traced(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#define glCopyImageSubData glCopyImageSubData_Traced
using glTracer_glFramebufferParameteri = std::function<void(GLenum, GLenum, GLint)>;
void glFramebufferParameteri_Traced(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteri glFramebufferParameteri_Traced
using glTracer_glGetFramebufferParameteriv = std::function<void(GLenum, GLenum, GLint*)>;
void glGetFramebufferParameteriv_Traced(GLenum target, GLenum pname, GLint* params);
#define glGetFramebufferParameteriv glGetFramebufferParameteriv_Traced
using glTracer_glGetInternalformati64v = std::function<void(GLenum, GLenum, GLenum, GLsizei, GLint64*)>;
void glGetInternalformati64v_Traced(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params);
#define glGetInternalformati64v glGetInternalformati64v_Traced
using glTracer_glInvalidateTexSubImage = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)>;
void glInvalidateTexSubImage_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#define glInvalidateTexSubImage glInvalidateTexSubImage_Traced
using glTracer_glInvalidateTexImage = std::function<void(GLuint, GLint)>;
void glInvalidateTexImage_Traced(GLuint texture, GLint level);
#define glInvalidateTexImage glInvalidateTexImage_Traced
using glTracer_glInvalidateBufferSubData = std::function<void(GLuint, GLintptr, GLsizeiptr)>;
void glInvalidateBufferSubData_Traced(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glInvalidateBufferSubData glInvalidateBufferSubData_Traced
using glTracer_glInvalidateBufferData = std::function<void(GLuint)>;
void glInvalidateBufferData_Traced(GLuint buffer);
#define glInvalidateBufferData glInvalidateBufferData_Traced
using glTracer_glInvalidateFramebuffer = std::function<void(GLenum, GLsizei, const GLenum*)>;
void glInvalidateFramebuffer_Traced(GLenum target, GLsizei numAttachments, const GLenum* attachments);
#define glInvalidateFramebuffer glInvalidateFramebuffer_Traced
using glTracer_glInvalidateSubFramebuffer = std::function<void(GLenum, GLsizei, const GLenum*, GLint, GLint, GLsizei, GLsizei)>;
void glInvalidateSubFramebuffer_Traced(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateSubFramebuffer glInvalidateSubFramebuffer_Traced
using glTracer_glMultiDrawArraysIndirect = std::function<void(GLenum, const void*, GLsizei, GLsizei)>;
void glMultiDrawArraysIndirect_Traced(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawArraysIndirect glMultiDrawArraysIndirect_Traced
using glTracer_glMultiDrawElementsIndirect = std::function<void(GLenum, GLenum, const void*, GLsizei, GLsizei)>;
void glMultiDrawElementsIndirect_Traced(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawElementsIndirect glMultiDrawElementsIndirect_Traced
using glTracer_glGetProgramInterfaceiv = std::function<void(GLuint, GLenum, GLenum, GLint*)>;
void glGetProgramInterfaceiv_Traced(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
#define glGetProgramInterfaceiv glGetProgramInterfaceiv_Traced
using glTracer_glGetProgramResourceIndex = std::function<GLuint(GLuint, GLenum, const GLchar*)>;
GLuint glGetProgramResourceIndex_Traced(GLuint program, GLenum programInterface, const GLchar* name);
#define glGetProgramResourceIndex glGetProgramResourceIndex_Traced
using glTracer_glGetProgramResourceName = std::function<void(GLuint, GLenum, GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetProgramResourceName_Traced(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
#define glGetProgramResourceName glGetProgramResourceName_Traced
using glTracer_glGetProgramResourceiv = std::function<void(GLuint, GLenum, GLuint, GLsizei, const GLenum*, GLsizei, GLsizei*, GLint*)>;
void glGetProgramResourceiv_Traced(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params);
#define glGetProgramResourceiv glGetProgramResourceiv_Traced
using glTracer_glGetProgramResourceLocation = std::function<GLint(GLuint, GLenum, const GLchar*)>;
GLint glGetProgramResourceLocation_Traced(GLuint program, GLenum programInterface, const GLchar* name);
#define glGetProgramResourceLocation glGetProgramResourceLocation_Traced
using glTracer_glGetProgramResourceLocationIndex = std::function<GLint(GLuint, GLenum, const GLchar*)>;
GLint glGetProgramResourceLocationIndex_Traced(GLuint program, GLenum programInterface, const GLchar* name);
#define glGetProgramResourceLocationIndex glGetProgramResourceLocationIndex_Traced
using glTracer_glShaderStorageBlockBinding = std::function<void(GLuint, GLuint, GLuint)>;
void glShaderStorageBlockBinding_Traced(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#define glShaderStorageBlockBinding glShaderStorageBlockBinding_Traced
using glTracer_glTexBufferRange = std::function<void(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr)>;
void glTexBufferRange_Traced(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTexBufferRange glTexBufferRange_Traced
using glTracer_glTexStorage2DMultisample = std::function<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)>;
void glTexStorage2DMultisample_Traced(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexStorage2DMultisample glTexStorage2DMultisample_Traced
using glTracer_glTexStorage3DMultisample = std::function<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>;
void glTexStorage3DMultisample_Traced(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexStorage3DMultisample glTexStorage3DMultisample_Traced
using glTracer_glTextureView = std::function<void(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint)>;
void glTextureView_Traced(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#define glTextureView glTextureView_Traced
using glTracer_glBindVertexBuffer = std::function<void(GLuint, GLuint, GLintptr, GLsizei)>;
void glBindVertexBuffer_Traced(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glBindVertexBuffer glBindVertexBuffer_Traced
using glTracer_glVertexAttribFormat = std::function<void(GLuint, GLint, GLenum, GLboolean, GLuint)>;
void glVertexAttribFormat_Traced(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexAttribFormat glVertexAttribFormat_Traced
using glTracer_glVertexAttribIFormat = std::function<void(GLuint, GLint, GLenum, GLuint)>;
void glVertexAttribIFormat_Traced(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribIFormat glVertexAttribIFormat_Traced
using glTracer_glVertexAttribLFormat = std::function<void(GLuint, GLint, GLenum, GLuint)>;
void glVertexAttribLFormat_Traced(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribLFormat glVertexAttribLFormat_Traced
using glTracer_glVertexAttribBinding = std::function<void(GLuint, GLuint)>;
void glVertexAttribBinding_Traced(GLuint attribindex, GLuint bindingindex);
#define glVertexAttribBinding glVertexAttribBinding_Traced
using glTracer_glVertexBindingDivisor = std::function<void(GLuint, GLuint)>;
void glVertexBindingDivisor_Traced(GLuint bindingindex, GLuint divisor);
#define glVertexBindingDivisor glVertexBindingDivisor_Traced
using glTracer_glDebugMessageControl = std::function<void(GLenum, GLenum, GLenum, GLsizei, const GLuint*, GLboolean)>;
void glDebugMessageControl_Traced(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
#define glDebugMessageControl glDebugMessageControl_Traced
using glTracer_glDebugMessageInsert = std::function<void(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar*)>;
void glDebugMessageInsert_Traced(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
#define glDebugMessageInsert glDebugMessageInsert_Traced
using glTracer_glDebugMessageCallback = std::function<void(GLDEBUGPROC, const void*)>;
void glDebugMessageCallback_Traced(GLDEBUGPROC callback, const void* userParam);
#define glDebugMessageCallback glDebugMessageCallback_Traced
using glTracer_glGetDebugMessageLog = std::function<GLuint(GLuint, GLsizei, GLenum*, GLenum*, GLuint*, GLenum*, GLsizei*, GLchar*)>;
GLuint glGetDebugMessageLog_Traced(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
#define glGetDebugMessageLog glGetDebugMessageLog_Traced
using glTracer_glPushDebugGroup = std::function<void(GLenum, GLuint, GLsizei, const GLchar*)>;
void glPushDebugGroup_Traced(GLenum source, GLuint id, GLsizei length, const GLchar* message);
#define glPushDebugGroup glPushDebugGroup_Traced
using glTracer_glPopDebugGroup = std::function<void()>;
void glPopDebugGroup_Traced();
#define glPopDebugGroup glPopDebugGroup_Traced
using glTracer_glObjectLabel = std::function<void(GLenum, GLuint, GLsizei, const GLchar*)>;
void glObjectLabel_Traced(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
#define glObjectLabel glObjectLabel_Traced
using glTracer_glGetObjectLabel = std::function<void(GLenum, GLuint, GLsizei, GLsizei*, GLchar*)>;
void glGetObjectLabel_Traced(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
#define glGetObjectLabel glGetObjectLabel_Traced
using glTracer_glObjectPtrLabel = std::function<void(const void*, GLsizei, const GLchar*)>;
void glObjectPtrLabel_Traced(const void* ptr, GLsizei length, const GLchar* label);
#define glObjectPtrLabel glObjectPtrLabel_Traced
using glTracer_glGetObjectPtrLabel = std::function<void(const void*, GLsizei, GLsizei*, GLchar*)>;
void glGetObjectPtrLabel_Traced(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
#define glGetObjectPtrLabel glGetObjectPtrLabel_Traced
using glTracer_glBufferStorage = std::function<void(GLenum, GLsizeiptr, const void*, GLbitfield)>;
void glBufferStorage_Traced(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
#define glBufferStorage glBufferStorage_Traced
using glTracer_glClearTexImage = std::function<void(GLuint, GLint, GLenum, GLenum, const void*)>;
void glClearTexImage_Traced(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
#define glClearTexImage glClearTexImage_Traced
using glTracer_glClearTexSubImage = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void*)>;
void glClearTexSubImage_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
#define glClearTexSubImage glClearTexSubImage_Traced
using glTracer_glBindBuffersBase = std::function<void(GLenum, GLuint, GLsizei, const GLuint*)>;
void glBindBuffersBase_Traced(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
#define glBindBuffersBase glBindBuffersBase_Traced
using glTracer_glBindBuffersRange = std::function<void(GLenum, GLuint, GLsizei, const GLuint*, const GLintptr*, const GLsizeiptr*)>;
void glBindBuffersRange_Traced(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
#define glBindBuffersRange glBindBuffersRange_Traced
using glTracer_glBindTextures = std::function<void(GLuint, GLsizei, const GLuint*)>;
void glBindTextures_Traced(GLuint first, GLsizei count, const GLuint* textures);
#define glBindTextures glBindTextures_Traced
using glTracer_glBindSamplers = std::function<void(GLuint, GLsizei, const GLuint*)>;
void glBindSamplers_Traced(GLuint first, GLsizei count, const GLuint* samplers);
#define glBindSamplers glBindSamplers_Traced
using glTracer_glBindImageTextures = std::function<void(GLuint, GLsizei, const GLuint*)>;
void glBindImageTextures_Traced(GLuint first, GLsizei count, const GLuint* textures);
#define glBindImageTextures glBindImageTextures_Traced
using glTracer_glBindVertexBuffers = std::function<void(GLuint, GLsizei, const GLuint*, const GLintptr*, const GLsizei*)>;
void glBindVertexBuffers_Traced(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
#define glBindVertexBuffers glBindVertexBuffers_Traced
using glTracer_glClipControl = std::function<void(GLenum, GLenum)>;
void glClipControl_Traced(GLenum origin, GLenum depth);
#define glClipControl glClipControl_Traced
using glTracer_glCreateTransformFeedbacks = std::function<void(GLsizei, GLuint*)>;
void glCreateTransformFeedbacks_Traced(GLsizei n, GLuint* ids);
#define glCreateTransformFeedbacks glCreateTransformFeedbacks_Traced
using glTracer_glTransformFeedbackBufferBase = std::function<void(GLuint, GLuint, GLuint)>;
void glTransformFeedbackBufferBase_Traced(GLuint xfb, GLuint index, GLuint buffer);
#define glTransformFeedbackBufferBase glTransformFeedbackBufferBase_Traced
using glTracer_glTransformFeedbackBufferRange = std::function<void(GLuint, GLuint, GLuint, GLintptr, GLsizeiptr)>;
void glTransformFeedbackBufferRange_Traced(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTransformFeedbackBufferRange glTransformFeedbackBufferRange_Traced
using glTracer_glGetTransformFeedbackiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetTransformFeedbackiv_Traced(GLuint xfb, GLenum pname, GLint* param);
#define glGetTransformFeedbackiv glGetTransformFeedbackiv_Traced
using glTracer_glGetTransformFeedbacki_v = std::function<void(GLuint, GLenum, GLuint, GLint*)>;
void glGetTransformFeedbacki_v_Traced(GLuint xfb, GLenum pname, GLuint index, GLint* param);
#define glGetTransformFeedbacki_v glGetTransformFeedbacki_v_Traced
using glTracer_glGetTransformFeedbacki64_v = std::function<void(GLuint, GLenum, GLuint, GLint64*)>;
void glGetTransformFeedbacki64_v_Traced(GLuint xfb, GLenum pname, GLuint index, GLint64* param);
#define glGetTransformFeedbacki64_v glGetTransformFeedbacki64_v_Traced
using glTracer_glCreateBuffers = std::function<void(GLsizei, GLuint*)>;
void glCreateBuffers_Traced(GLsizei n, GLuint* buffers);
#define glCreateBuffers glCreateBuffers_Traced
using glTracer_glNamedBufferStorage = std::function<void(GLuint, GLsizeiptr, const void*, GLbitfield)>;
void glNamedBufferStorage_Traced(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
#define glNamedBufferStorage glNamedBufferStorage_Traced
using glTracer_glNamedBufferData = std::function<void(GLuint, GLsizeiptr, const void*, GLenum)>;
void glNamedBufferData_Traced(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
#define glNamedBufferData glNamedBufferData_Traced
using glTracer_glNamedBufferSubData = std::function<void(GLuint, GLintptr, GLsizeiptr, const void*)>;
void glNamedBufferSubData_Traced(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
#define glNamedBufferSubData glNamedBufferSubData_Traced
using glTracer_glCopyNamedBufferSubData = std::function<void(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr)>;
void glCopyNamedBufferSubData_Traced(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyNamedBufferSubData glCopyNamedBufferSubData_Traced
using glTracer_glClearNamedBufferData = std::function<void(GLuint, GLenum, GLenum, GLenum, const void*)>;
void glClearNamedBufferData_Traced(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
#define glClearNamedBufferData glClearNamedBufferData_Traced
using glTracer_glClearNamedBufferSubData = std::function<void(GLuint, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void*)>;
void glClearNamedBufferSubData_Traced(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
#define glClearNamedBufferSubData glClearNamedBufferSubData_Traced
using glTracer_glMapNamedBuffer = std::function<void* (GLuint, GLenum)>;
void* glMapNamedBuffer_Traced(GLuint buffer, GLenum access);
#define glMapNamedBuffer glMapNamedBuffer_Traced
using glTracer_glMapNamedBufferRange = std::function<void* (GLuint, GLintptr, GLsizeiptr, GLbitfield)>;
void* glMapNamedBufferRange_Traced(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRange glMapNamedBufferRange_Traced
using glTracer_glUnmapNamedBuffer = std::function<GLboolean(GLuint)>;
GLboolean glUnmapNamedBuffer_Traced(GLuint buffer);
#define glUnmapNamedBuffer glUnmapNamedBuffer_Traced
using glTracer_glFlushMappedNamedBufferRange = std::function<void(GLuint, GLintptr, GLsizeiptr)>;
void glFlushMappedNamedBufferRange_Traced(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRange glFlushMappedNamedBufferRange_Traced
using glTracer_glGetNamedBufferParameteriv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetNamedBufferParameteriv_Traced(GLuint buffer, GLenum pname, GLint* params);
#define glGetNamedBufferParameteriv glGetNamedBufferParameteriv_Traced
using glTracer_glGetNamedBufferParameteri64v = std::function<void(GLuint, GLenum, GLint64*)>;
void glGetNamedBufferParameteri64v_Traced(GLuint buffer, GLenum pname, GLint64* params);
#define glGetNamedBufferParameteri64v glGetNamedBufferParameteri64v_Traced
using glTracer_glGetNamedBufferPointerv = std::function<void(GLuint, GLenum, void**)>;
void glGetNamedBufferPointerv_Traced(GLuint buffer, GLenum pname, void** params);
#define glGetNamedBufferPointerv glGetNamedBufferPointerv_Traced
using glTracer_glGetNamedBufferSubData = std::function<void(GLuint, GLintptr, GLsizeiptr, void*)>;
void glGetNamedBufferSubData_Traced(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
#define glGetNamedBufferSubData glGetNamedBufferSubData_Traced
using glTracer_glCreateFramebuffers = std::function<void(GLsizei, GLuint*)>;
void glCreateFramebuffers_Traced(GLsizei n, GLuint* framebuffers);
#define glCreateFramebuffers glCreateFramebuffers_Traced
using glTracer_glNamedFramebufferRenderbuffer = std::function<void(GLuint, GLenum, GLenum, GLuint)>;
void glNamedFramebufferRenderbuffer_Traced(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbuffer glNamedFramebufferRenderbuffer_Traced
using glTracer_glNamedFramebufferParameteri = std::function<void(GLuint, GLenum, GLint)>;
void glNamedFramebufferParameteri_Traced(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteri glNamedFramebufferParameteri_Traced
using glTracer_glNamedFramebufferTexture = std::function<void(GLuint, GLenum, GLuint, GLint)>;
void glNamedFramebufferTexture_Traced(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTexture glNamedFramebufferTexture_Traced
using glTracer_glNamedFramebufferTextureLayer = std::function<void(GLuint, GLenum, GLuint, GLint, GLint)>;
void glNamedFramebufferTextureLayer_Traced(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayer glNamedFramebufferTextureLayer_Traced
using glTracer_glNamedFramebufferDrawBuffer = std::function<void(GLuint, GLenum)>;
void glNamedFramebufferDrawBuffer_Traced(GLuint framebuffer, GLenum buf);
#define glNamedFramebufferDrawBuffer glNamedFramebufferDrawBuffer_Traced
using glTracer_glNamedFramebufferDrawBuffers = std::function<void(GLuint, GLsizei, const GLenum*)>;
void glNamedFramebufferDrawBuffers_Traced(GLuint framebuffer, GLsizei n, const GLenum* bufs);
#define glNamedFramebufferDrawBuffers glNamedFramebufferDrawBuffers_Traced
using glTracer_glNamedFramebufferReadBuffer = std::function<void(GLuint, GLenum)>;
void glNamedFramebufferReadBuffer_Traced(GLuint framebuffer, GLenum src);
#define glNamedFramebufferReadBuffer glNamedFramebufferReadBuffer_Traced
using glTracer_glInvalidateNamedFramebufferData = std::function<void(GLuint, GLsizei, const GLenum*)>;
void glInvalidateNamedFramebufferData_Traced(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments);
#define glInvalidateNamedFramebufferData glInvalidateNamedFramebufferData_Traced
using glTracer_glInvalidateNamedFramebufferSubData = std::function<void(GLuint, GLsizei, const GLenum*, GLint, GLint, GLsizei, GLsizei)>;
void glInvalidateNamedFramebufferSubData_Traced(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateNamedFramebufferSubData glInvalidateNamedFramebufferSubData_Traced
using glTracer_glClearNamedFramebufferiv = std::function<void(GLuint, GLenum, GLint, const GLint*)>;
void glClearNamedFramebufferiv_Traced(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value);
#define glClearNamedFramebufferiv glClearNamedFramebufferiv_Traced
using glTracer_glClearNamedFramebufferuiv = std::function<void(GLuint, GLenum, GLint, const GLuint*)>;
void glClearNamedFramebufferuiv_Traced(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value);
#define glClearNamedFramebufferuiv glClearNamedFramebufferuiv_Traced
using glTracer_glClearNamedFramebufferfv = std::function<void(GLuint, GLenum, GLint, const GLfloat*)>;
void glClearNamedFramebufferfv_Traced(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value);
#define glClearNamedFramebufferfv glClearNamedFramebufferfv_Traced
using glTracer_glClearNamedFramebufferfi = std::function<void(GLuint, GLenum, GLint, GLfloat, GLint)>;
void glClearNamedFramebufferfi_Traced(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearNamedFramebufferfi glClearNamedFramebufferfi_Traced
using glTracer_glBlitNamedFramebuffer = std::function<void(GLuint, GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum)>;
void glBlitNamedFramebuffer_Traced(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitNamedFramebuffer glBlitNamedFramebuffer_Traced
using glTracer_glCheckNamedFramebufferStatus = std::function<GLenum(GLuint, GLenum)>;
GLenum glCheckNamedFramebufferStatus_Traced(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatus glCheckNamedFramebufferStatus_Traced
using glTracer_glGetNamedFramebufferParameteriv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetNamedFramebufferParameteriv_Traced(GLuint framebuffer, GLenum pname, GLint* param);
#define glGetNamedFramebufferParameteriv glGetNamedFramebufferParameteriv_Traced
using glTracer_glGetNamedFramebufferAttachmentParameteriv = std::function<void(GLuint, GLenum, GLenum, GLint*)>;
void glGetNamedFramebufferAttachmentParameteriv_Traced(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
#define glGetNamedFramebufferAttachmentParameteriv glGetNamedFramebufferAttachmentParameteriv_Traced
using glTracer_glCreateRenderbuffers = std::function<void(GLsizei, GLuint*)>;
void glCreateRenderbuffers_Traced(GLsizei n, GLuint* renderbuffers);
#define glCreateRenderbuffers glCreateRenderbuffers_Traced
using glTracer_glNamedRenderbufferStorage = std::function<void(GLuint, GLenum, GLsizei, GLsizei)>;
void glNamedRenderbufferStorage_Traced(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorage glNamedRenderbufferStorage_Traced
using glTracer_glNamedRenderbufferStorageMultisample = std::function<void(GLuint, GLsizei, GLenum, GLsizei, GLsizei)>;
void glNamedRenderbufferStorageMultisample_Traced(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisample glNamedRenderbufferStorageMultisample_Traced
using glTracer_glGetNamedRenderbufferParameteriv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetNamedRenderbufferParameteriv_Traced(GLuint renderbuffer, GLenum pname, GLint* params);
#define glGetNamedRenderbufferParameteriv glGetNamedRenderbufferParameteriv_Traced
using glTracer_glCreateTextures = std::function<void(GLenum, GLsizei, GLuint*)>;
void glCreateTextures_Traced(GLenum target, GLsizei n, GLuint* textures);
#define glCreateTextures glCreateTextures_Traced
using glTracer_glTextureBuffer = std::function<void(GLuint, GLenum, GLuint)>;
void glTextureBuffer_Traced(GLuint texture, GLenum internalformat, GLuint buffer);
#define glTextureBuffer glTextureBuffer_Traced
using glTracer_glTextureBufferRange = std::function<void(GLuint, GLenum, GLuint, GLintptr, GLsizeiptr)>;
void glTextureBufferRange_Traced(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRange glTextureBufferRange_Traced
using glTracer_glTextureStorage1D = std::function<void(GLuint, GLsizei, GLenum, GLsizei)>;
void glTextureStorage1D_Traced(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1D glTextureStorage1D_Traced
using glTracer_glTextureStorage2D = std::function<void(GLuint, GLsizei, GLenum, GLsizei, GLsizei)>;
void glTextureStorage2D_Traced(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2D glTextureStorage2D_Traced
using glTracer_glTextureStorage3D = std::function<void(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)>;
void glTextureStorage3D_Traced(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3D glTextureStorage3D_Traced
using glTracer_glTextureStorage2DMultisample = std::function<void(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)>;
void glTextureStorage2DMultisample_Traced(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisample glTextureStorage2DMultisample_Traced
using glTracer_glTextureStorage3DMultisample = std::function<void(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>;
void glTextureStorage3DMultisample_Traced(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisample glTextureStorage3DMultisample_Traced
using glTracer_glTextureSubImage1D = std::function<void(GLuint, GLint, GLint, GLsizei, GLenum, GLenum, const void*)>;
void glTextureSubImage1D_Traced(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
#define glTextureSubImage1D glTextureSubImage1D_Traced
using glTracer_glTextureSubImage2D = std::function<void(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void*)>;
void glTextureSubImage2D_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
#define glTextureSubImage2D glTextureSubImage2D_Traced
using glTracer_glTextureSubImage3D = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void*)>;
void glTextureSubImage3D_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
#define glTextureSubImage3D glTextureSubImage3D_Traced
using glTracer_glCompressedTextureSubImage1D = std::function<void(GLuint, GLint, GLint, GLsizei, GLenum, GLsizei, const void*)>;
void glCompressedTextureSubImage1D_Traced(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
#define glCompressedTextureSubImage1D glCompressedTextureSubImage1D_Traced
using glTracer_glCompressedTextureSubImage2D = std::function<void(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void*)>;
void glCompressedTextureSubImage2D_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
#define glCompressedTextureSubImage2D glCompressedTextureSubImage2D_Traced
using glTracer_glCompressedTextureSubImage3D = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void*)>;
void glCompressedTextureSubImage3D_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
#define glCompressedTextureSubImage3D glCompressedTextureSubImage3D_Traced
using glTracer_glCopyTextureSubImage1D = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLsizei)>;
void glCopyTextureSubImage1D_Traced(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1D glCopyTextureSubImage1D_Traced
using glTracer_glCopyTextureSubImage2D = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>;
void glCopyTextureSubImage2D_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2D glCopyTextureSubImage2D_Traced
using glTracer_glCopyTextureSubImage3D = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>;
void glCopyTextureSubImage3D_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3D glCopyTextureSubImage3D_Traced
using glTracer_glTextureParameterf = std::function<void(GLuint, GLenum, GLfloat)>;
void glTextureParameterf_Traced(GLuint texture, GLenum pname, GLfloat param);
#define glTextureParameterf glTextureParameterf_Traced
using glTracer_glTextureParameterfv = std::function<void(GLuint, GLenum, const GLfloat*)>;
void glTextureParameterfv_Traced(GLuint texture, GLenum pname, const GLfloat* param);
#define glTextureParameterfv glTextureParameterfv_Traced
using glTracer_glTextureParameteri = std::function<void(GLuint, GLenum, GLint)>;
void glTextureParameteri_Traced(GLuint texture, GLenum pname, GLint param);
#define glTextureParameteri glTextureParameteri_Traced
using glTracer_glTextureParameterIiv = std::function<void(GLuint, GLenum, const GLint*)>;
void glTextureParameterIiv_Traced(GLuint texture, GLenum pname, const GLint* params);
#define glTextureParameterIiv glTextureParameterIiv_Traced
using glTracer_glTextureParameterIuiv = std::function<void(GLuint, GLenum, const GLuint*)>;
void glTextureParameterIuiv_Traced(GLuint texture, GLenum pname, const GLuint* params);
#define glTextureParameterIuiv glTextureParameterIuiv_Traced
using glTracer_glTextureParameteriv = std::function<void(GLuint, GLenum, const GLint*)>;
void glTextureParameteriv_Traced(GLuint texture, GLenum pname, const GLint* param);
#define glTextureParameteriv glTextureParameteriv_Traced
using glTracer_glGenerateTextureMipmap = std::function<void(GLuint)>;
void glGenerateTextureMipmap_Traced(GLuint texture);
#define glGenerateTextureMipmap glGenerateTextureMipmap_Traced
using glTracer_glBindTextureUnit = std::function<void(GLuint, GLuint)>;
void glBindTextureUnit_Traced(GLuint unit, GLuint texture);
#define glBindTextureUnit glBindTextureUnit_Traced
using glTracer_glGetTextureImage = std::function<void(GLuint, GLint, GLenum, GLenum, GLsizei, void*)>;
void glGetTextureImage_Traced(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
#define glGetTextureImage glGetTextureImage_Traced
using glTracer_glGetCompressedTextureImage = std::function<void(GLuint, GLint, GLsizei, void*)>;
void glGetCompressedTextureImage_Traced(GLuint texture, GLint level, GLsizei bufSize, void* pixels);
#define glGetCompressedTextureImage glGetCompressedTextureImage_Traced
using glTracer_glGetTextureLevelParameterfv = std::function<void(GLuint, GLint, GLenum, GLfloat*)>;
void glGetTextureLevelParameterfv_Traced(GLuint texture, GLint level, GLenum pname, GLfloat* params);
#define glGetTextureLevelParameterfv glGetTextureLevelParameterfv_Traced
using glTracer_glGetTextureLevelParameteriv = std::function<void(GLuint, GLint, GLenum, GLint*)>;
void glGetTextureLevelParameteriv_Traced(GLuint texture, GLint level, GLenum pname, GLint* params);
#define glGetTextureLevelParameteriv glGetTextureLevelParameteriv_Traced
using glTracer_glGetTextureParameterfv = std::function<void(GLuint, GLenum, GLfloat*)>;
void glGetTextureParameterfv_Traced(GLuint texture, GLenum pname, GLfloat* params);
#define glGetTextureParameterfv glGetTextureParameterfv_Traced
using glTracer_glGetTextureParameterIiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetTextureParameterIiv_Traced(GLuint texture, GLenum pname, GLint* params);
#define glGetTextureParameterIiv glGetTextureParameterIiv_Traced
using glTracer_glGetTextureParameterIuiv = std::function<void(GLuint, GLenum, GLuint*)>;
void glGetTextureParameterIuiv_Traced(GLuint texture, GLenum pname, GLuint* params);
#define glGetTextureParameterIuiv glGetTextureParameterIuiv_Traced
using glTracer_glGetTextureParameteriv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetTextureParameteriv_Traced(GLuint texture, GLenum pname, GLint* params);
#define glGetTextureParameteriv glGetTextureParameteriv_Traced
using glTracer_glCreateVertexArrays = std::function<void(GLsizei, GLuint*)>;
void glCreateVertexArrays_Traced(GLsizei n, GLuint* arrays);
#define glCreateVertexArrays glCreateVertexArrays_Traced
using glTracer_glDisableVertexArrayAttrib = std::function<void(GLuint, GLuint)>;
void glDisableVertexArrayAttrib_Traced(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttrib glDisableVertexArrayAttrib_Traced
using glTracer_glEnableVertexArrayAttrib = std::function<void(GLuint, GLuint)>;
void glEnableVertexArrayAttrib_Traced(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttrib glEnableVertexArrayAttrib_Traced
using glTracer_glVertexArrayElementBuffer = std::function<void(GLuint, GLuint)>;
void glVertexArrayElementBuffer_Traced(GLuint vaobj, GLuint buffer);
#define glVertexArrayElementBuffer glVertexArrayElementBuffer_Traced
using glTracer_glVertexArrayVertexBuffer = std::function<void(GLuint, GLuint, GLuint, GLintptr, GLsizei)>;
void glVertexArrayVertexBuffer_Traced(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayVertexBuffer glVertexArrayVertexBuffer_Traced
using glTracer_glVertexArrayVertexBuffers = std::function<void(GLuint, GLuint, GLsizei, const GLuint*, const GLintptr*, const GLsizei*)>;
void glVertexArrayVertexBuffers_Traced(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
#define glVertexArrayVertexBuffers glVertexArrayVertexBuffers_Traced
using glTracer_glVertexArrayAttribBinding = std::function<void(GLuint, GLuint, GLuint)>;
void glVertexArrayAttribBinding_Traced(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayAttribBinding glVertexArrayAttribBinding_Traced
using glTracer_glVertexArrayAttribFormat = std::function<void(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint)>;
void glVertexArrayAttribFormat_Traced(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayAttribFormat glVertexArrayAttribFormat_Traced
using glTracer_glVertexArrayAttribIFormat = std::function<void(GLuint, GLuint, GLint, GLenum, GLuint)>;
void glVertexArrayAttribIFormat_Traced(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribIFormat glVertexArrayAttribIFormat_Traced
using glTracer_glVertexArrayAttribLFormat = std::function<void(GLuint, GLuint, GLint, GLenum, GLuint)>;
void glVertexArrayAttribLFormat_Traced(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribLFormat glVertexArrayAttribLFormat_Traced
using glTracer_glVertexArrayBindingDivisor = std::function<void(GLuint, GLuint, GLuint)>;
void glVertexArrayBindingDivisor_Traced(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayBindingDivisor glVertexArrayBindingDivisor_Traced
using glTracer_glGetVertexArrayiv = std::function<void(GLuint, GLenum, GLint*)>;
void glGetVertexArrayiv_Traced(GLuint vaobj, GLenum pname, GLint* param);
#define glGetVertexArrayiv glGetVertexArrayiv_Traced
using glTracer_glGetVertexArrayIndexediv = std::function<void(GLuint, GLuint, GLenum, GLint*)>;
void glGetVertexArrayIndexediv_Traced(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
#define glGetVertexArrayIndexediv glGetVertexArrayIndexediv_Traced
using glTracer_glGetVertexArrayIndexed64iv = std::function<void(GLuint, GLuint, GLenum, GLint64*)>;
void glGetVertexArrayIndexed64iv_Traced(GLuint vaobj, GLuint index, GLenum pname, GLint64* param);
#define glGetVertexArrayIndexed64iv glGetVertexArrayIndexed64iv_Traced
using glTracer_glCreateSamplers = std::function<void(GLsizei, GLuint*)>;
void glCreateSamplers_Traced(GLsizei n, GLuint* samplers);
#define glCreateSamplers glCreateSamplers_Traced
using glTracer_glCreateProgramPipelines = std::function<void(GLsizei, GLuint*)>;
void glCreateProgramPipelines_Traced(GLsizei n, GLuint* pipelines);
#define glCreateProgramPipelines glCreateProgramPipelines_Traced
using glTracer_glCreateQueries = std::function<void(GLenum, GLsizei, GLuint*)>;
void glCreateQueries_Traced(GLenum target, GLsizei n, GLuint* ids);
#define glCreateQueries glCreateQueries_Traced
using glTracer_glGetQueryBufferObjecti64v = std::function<void(GLuint, GLuint, GLenum, GLintptr)>;
void glGetQueryBufferObjecti64v_Traced(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjecti64v glGetQueryBufferObjecti64v_Traced
using glTracer_glGetQueryBufferObjectiv = std::function<void(GLuint, GLuint, GLenum, GLintptr)>;
void glGetQueryBufferObjectiv_Traced(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectiv glGetQueryBufferObjectiv_Traced
using glTracer_glGetQueryBufferObjectui64v = std::function<void(GLuint, GLuint, GLenum, GLintptr)>;
void glGetQueryBufferObjectui64v_Traced(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectui64v glGetQueryBufferObjectui64v_Traced
using glTracer_glGetQueryBufferObjectuiv = std::function<void(GLuint, GLuint, GLenum, GLintptr)>;
void glGetQueryBufferObjectuiv_Traced(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectuiv glGetQueryBufferObjectuiv_Traced
using glTracer_glMemoryBarrierByRegion = std::function<void(GLbitfield)>;
void glMemoryBarrierByRegion_Traced(GLbitfield barriers);
#define glMemoryBarrierByRegion glMemoryBarrierByRegion_Traced
using glTracer_glGetTextureSubImage = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void*)>;
void glGetTextureSubImage_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
#define glGetTextureSubImage glGetTextureSubImage_Traced
using glTracer_glGetCompressedTextureSubImage = std::function<void(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, void*)>;
void glGetCompressedTextureSubImage_Traced(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels);
#define glGetCompressedTextureSubImage glGetCompressedTextureSubImage_Traced
using glTracer_glGetGraphicsResetStatus = std::function<GLenum()>;
GLenum glGetGraphicsResetStatus_Traced();
#define glGetGraphicsResetStatus glGetGraphicsResetStatus_Traced
using glTracer_glGetnCompressedTexImage = std::function<void(GLenum, GLint, GLsizei, void*)>;
void glGetnCompressedTexImage_Traced(GLenum target, GLint lod, GLsizei bufSize, void* pixels);
#define glGetnCompressedTexImage glGetnCompressedTexImage_Traced
using glTracer_glGetnTexImage = std::function<void(GLenum, GLint, GLenum, GLenum, GLsizei, void*)>;
void glGetnTexImage_Traced(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
#define glGetnTexImage glGetnTexImage_Traced
using glTracer_glGetnUniformdv = std::function<void(GLuint, GLint, GLsizei, GLdouble*)>;
void glGetnUniformdv_Traced(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#define glGetnUniformdv glGetnUniformdv_Traced
using glTracer_glGetnUniformfv = std::function<void(GLuint, GLint, GLsizei, GLfloat*)>;
void glGetnUniformfv_Traced(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
#define glGetnUniformfv glGetnUniformfv_Traced
using glTracer_glGetnUniformiv = std::function<void(GLuint, GLint, GLsizei, GLint*)>;
void glGetnUniformiv_Traced(GLuint program, GLint location, GLsizei bufSize, GLint* params);
#define glGetnUniformiv glGetnUniformiv_Traced
using glTracer_glGetnUniformuiv = std::function<void(GLuint, GLint, GLsizei, GLuint*)>;
void glGetnUniformuiv_Traced(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
#define glGetnUniformuiv glGetnUniformuiv_Traced
using glTracer_glReadnPixels = std::function<void(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void*)>;
void glReadnPixels_Traced(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data);
#define glReadnPixels glReadnPixels_Traced
using glTracer_glGetnMapdv = std::function<void(GLenum, GLenum, GLsizei, GLdouble*)>;
void glGetnMapdv_Traced(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
#define glGetnMapdv glGetnMapdv_Traced
using glTracer_glGetnMapfv = std::function<void(GLenum, GLenum, GLsizei, GLfloat*)>;
void glGetnMapfv_Traced(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
#define glGetnMapfv glGetnMapfv_Traced
using glTracer_glGetnMapiv = std::function<void(GLenum, GLenum, GLsizei, GLint*)>;
void glGetnMapiv_Traced(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
#define glGetnMapiv glGetnMapiv_Traced
using glTracer_glGetnPixelMapfv = std::function<void(GLenum, GLsizei, GLfloat*)>;
void glGetnPixelMapfv_Traced(GLenum map, GLsizei bufSize, GLfloat* values);
#define glGetnPixelMapfv glGetnPixelMapfv_Traced
using glTracer_glGetnPixelMapuiv = std::function<void(GLenum, GLsizei, GLuint*)>;
void glGetnPixelMapuiv_Traced(GLenum map, GLsizei bufSize, GLuint* values);
#define glGetnPixelMapuiv glGetnPixelMapuiv_Traced
using glTracer_glGetnPixelMapusv = std::function<void(GLenum, GLsizei, GLushort*)>;
void glGetnPixelMapusv_Traced(GLenum map, GLsizei bufSize, GLushort* values);
#define glGetnPixelMapusv glGetnPixelMapusv_Traced
using glTracer_glGetnPolygonStipple = std::function<void(GLsizei, GLubyte*)>;
void glGetnPolygonStipple_Traced(GLsizei bufSize, GLubyte* pattern);
#define glGetnPolygonStipple glGetnPolygonStipple_Traced
using glTracer_glGetnColorTable = std::function<void(GLenum, GLenum, GLenum, GLsizei, void*)>;
void glGetnColorTable_Traced(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table);
#define glGetnColorTable glGetnColorTable_Traced
using glTracer_glGetnConvolutionFilter = std::function<void(GLenum, GLenum, GLenum, GLsizei, void*)>;
void glGetnConvolutionFilter_Traced(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image);
#define glGetnConvolutionFilter glGetnConvolutionFilter_Traced
using glTracer_glGetnSeparableFilter = std::function<void(GLenum, GLenum, GLenum, GLsizei, void*, GLsizei, void*, void*)>;
void glGetnSeparableFilter_Traced(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, void* column, void* span);
#define glGetnSeparableFilter glGetnSeparableFilter_Traced
using glTracer_glGetnHistogram = std::function<void(GLenum, GLboolean, GLenum, GLenum, GLsizei, void*)>;
void glGetnHistogram_Traced(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
#define glGetnHistogram glGetnHistogram_Traced
using glTracer_glGetnMinmax = std::function<void(GLenum, GLboolean, GLenum, GLenum, GLsizei, void*)>;
void glGetnMinmax_Traced(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
#define glGetnMinmax glGetnMinmax_Traced
using glTracer_glTextureBarrier = std::function<void()>;
void glTextureBarrier_Traced();
#define glTextureBarrier glTextureBarrier_Traced
using glTracer_glSpecializeShader = std::function<void(GLuint, const GLchar*, GLuint, const GLuint*, const GLuint*)>;
void glSpecializeShader_Traced(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
#define glSpecializeShader glSpecializeShader_Traced
using glTracer_glMultiDrawArraysIndirectCount = std::function<void(GLenum, const void*, GLintptr, GLsizei, GLsizei)>;
void glMultiDrawArraysIndirectCount_Traced(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawArraysIndirectCount glMultiDrawArraysIndirectCount_Traced
using glTracer_glMultiDrawElementsIndirectCount = std::function<void(GLenum, GLenum, const void*, GLintptr, GLsizei, GLsizei)>;
void glMultiDrawElementsIndirectCount_Traced(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawElementsIndirectCount glMultiDrawElementsIndirectCount_Traced
using glTracer_glPolygonOffsetClamp = std::function<void(GLfloat, GLfloat, GLfloat)>;
void glPolygonOffsetClamp_Traced(GLfloat factor, GLfloat units, GLfloat clamp);
#define glPolygonOffsetClamp glPolygonOffsetClamp_Traced
