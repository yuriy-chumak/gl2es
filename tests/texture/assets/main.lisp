#!/usr/bin/env ol

(import (lib gl))
(import (OpenGL 1.1))

(define-values (a b c d e f g h i j k)
   (values 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0)
)

; generate texture
(define tex (let ((t '(0))) (glGenTextures 1 t) (car t)))
(glBindTexture GL_TEXTURE_2D tex)
(glTexParameteri GL_TEXTURE_2D GL_TEXTURE_MAG_FILTER GL_NEAREST)
(glTexParameteri GL_TEXTURE_2D GL_TEXTURE_MIN_FILTER GL_NEAREST)
(glTexImage2D GL_TEXTURE_2D 0 GL_RGB
   5 5
   0 GL_RGB GL_FLOAT (cons (fft* fft-float) [
                        1 0 0  a a a  0 1 0  b b b  0 0 1
                        c c c  1 1 0  d d d  0 1 1  e e e
                        0 0 1  f f f  1 0 0  g g g  0 1 0
                        h h h  0 1 1  i i i  1 1 0  j j j
                        0 1 0  k k k  0 0 1  a a a  1 0 0
   ]))

; init
(glEnable GL_TEXTURE_2D)

; draw
(gl:set-renderer (lambda ()
   (glClearColor 0.1 0.1 0.1 1)
   (glClear (vm:ior GL_COLOR_BUFFER_BIT GL_DEPTH_BUFFER_BIT))

   (glColor3f 1 1 1)
   (glBegin GL_QUADS)
      (glTexCoord2f 0 0)
      (glVertex2f -0.9 -0.9)
      (glTexCoord2f 0 1)
      (glVertex2f -0.9 +0.9)
      (glTexCoord2f 1 1)
      (glVertex2f +0.9 +0.9)
      (glTexCoord2f 1 0)
      (glVertex2f +0.9 -0.9)
   (glEnd)
))
