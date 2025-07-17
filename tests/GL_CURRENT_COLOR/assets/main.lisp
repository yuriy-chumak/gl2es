#!/usr/bin/env ol

(import (lib gl))
(import (OpenGL 1.0))

(define (check name r g b a)
   (glColor4f r g b a)

   (define cf '(#i7 #i7 #i7 #i7))
   (glGetFloatv GL_CURRENT_COLOR cf)

   (if (fold (lambda (f i s)
               (and f (= i s)))
         #t cf (list r g b a))
      (print-to stdout "GL_CURRENT_COLOR: glGetFloatv - ok")
      (print-to stderr "GL_CURRENT_COLOR: glGetFloatv - failed. should be " (list r g b a) ", but got " cf)))

; draw
(gl:set-renderer (lambda ()
   ;; black / white
   (check glColor4f #i0 #i0 #i0 #i0)
   (check glColor4f #i1 #i1 #i1 #i1)
   ;; r g b a
   (check glColor4f #i1 #i0 #i0 #i0)
   (check glColor4f #i0 #i1 #i0 #i0)
   (check glColor4f #i0 #i0 #i1 #i0)
   (check glColor4f #i0 #i0 #i0 #i1)

   (exit 1)
))
