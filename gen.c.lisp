#!/usr/bin/env ol

(import (file json))

(define PREFIX "es")
(define GL2ES "gl2_1_")

(print (s/'/"/g "/* This file is autogenerated! Do not edit. */
#include 'es.h'

#include 'log.h'
"))

(define json (read-json stdin))
(ff-for-each (lambda (name arguments)
      (define Name (substring (symbol->string name) 2))
      (print "//")
      (define return (ref arguments 1))
      (define args (cdr (vector->list arguments)))

      ;; we have function implementation
      (define stat (syscall 4 (c-string (string-append "src/" (symbol->string name) ".c"))))

      ;; external function
      (for-each display (list return " " "(* " PREFIX Name ")"))
      (display "(")
      (unless (null? args)
         (let loop ((args args))
            (display (car args))
            (unless (null? (cdr args))
               (display ", ")
               (loop (cdr args)))))
      (print ") = 0;")

      (print "__attribute__((visibility(\"default\")))")
      (print return " " name "(")
      (unless (null? args)
         (let loop ((args args))
            (display "    ")
            (display (car args))
            (unless (null? (cdr args))
               (print ", ")
               (loop (cdr args)))))
      (if stat
         (print ");")
      else
         (print ")")
         (print "{")

         ;;(print "   ILOG(\"" name "()\");");

         (if (string-eq? return "void")
            (display "   (void) ")
            (display "   return "))
         (for-each display (list PREFIX Name "("))
         (unless (null? args)
            (let loop ((args args))
               (display (last (c/ / (car args)) #false))
               (unless (null? (cdr args))
                  (display ", ")
                  (loop (cdr args)))))
         (print ");")
         (print "}")))
   json)

(print "// ----------------------------------------------------------------- //
#ifdef __WAJIC__
#define LINK(name) " PREFIX "##name = dlsym(GLES, \"JS\" #name)
#else
#define LINK(name) " PREFIX "##name = dlsym(GLES, \"gl\" #name)
#endif

extern void Init(void); // internal, call from gl2esInit() only

#include <dlfcn.h>
void* GLES = 0;
#ifdef __WAJIC__
WA_EXPORT(gl2esInit)
#else
__attribute__((visibility(\"default\")))
#endif
void gl2esInit() {
   // if (GLES != 0) return;
   GLES = dlopen(\"libGLESv2.so\", RTLD_LAZY);
")

(ff-for-each (lambda (name arguments)
      (define Name (substring (symbol->string name) 2))
      (print "   LINK(" Name ");"))
   json)
(print )
(print "   Init();")
(print "}")
