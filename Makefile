# cleanup while insuccessfull builds
# TODO: rename to glovr ?
# ----------------------------------
$(shell [ -s src/gles-2.0.c ] || rm -rf src/gles-2.0.c)

all: src/gles-2.0.c include/gles-2.0.h \
     src/vcvs.i src/vcfs.i \


src/gles-2.0.c: spec/gles-2.0.json
	ol gen.c.lisp <$^ >$@

include/gles-2.0.h: spec/gles-2.0.json
	ol gen.h.lisp <$^ >$@

define compile
	echo "char $1[] = {" >$3
	cat $2 |xxd --include >>$3
	echo ",0};" >> $3
endef

# vertices+colors
src/vcvs.i: shaders/vc.vs
	$(call compile,vcvs,$^,$@)
src/vcfs.i: shaders/vc.fs
	$(call compile,vcfs,$^,$@)
