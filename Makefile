# cleanup while insuccessfull builds
# ----------------------------------
$(shell [ -s src/gles-2.0.c ] || rm -rf src/gles-2.0.c)

all: src/es.c include/es.h \
     $(addprefix src/, $(notdir $(patsubst %.glsl,%.b,$(wildcard shaders/*.glsl))))

shaders: src/vc.b src/vct0.b

src/es.c: spec/gles-2.0.json $(wildcard src/*.c)
	ol gen.c.lisp <$< >$@

include/es.h: spec/gles-2.0.json $(wildcard src/*.c)
	ol gen.h.lisp <$< >$@

define compile
	echo "char $1[] = {" >$3
	cat $2 |xxd --include >>$3
	echo ",0};" >> $3
endef

# convert shader code to binary representation
src/%.b: shaders/%.glsl
	$(call compile,$(notdir $(patsubst %.glsl,%,$^)),$^,$@)
