# cleanup while insuccessfull builds
# ----------------------------------
$(shell [ -s src/gles-2.0.c ] || rm -rf src/gles-2.0.c)

all: src/es.c src/re.c include/es.h \
     $(addprefix src/, $(notdir $(patsubst %.glsl,%.b,$(wildcard shaders/*.glsl))))

shaders: src/vc.b src/vct0.b

src/es.c: spec/gles-2.0.json $(wildcard src/*.c)
	ol gen.c.lisp <$< >$@
src/re.c: include/re.h
	curl -o $@ https://raw.githubusercontent.com/kokke/tiny-regex-c/98d0bf28278b2230f95b7ba39744cb29b806f03a/re.c

include/es.h: spec/gles-2.0.json $(wildcard src/*.c)
	ol gen.h.lisp <$< >$@
include/re.h:
	curl -o $@ https://raw.githubusercontent.com/kokke/tiny-regex-c/98d0bf28278b2230f95b7ba39744cb29b806f03a/re.h

define compile
	echo "char $1[] = {" >$3
	cat $2 |xxd --include >>$3
	echo ",0};" >> $3
endef

# convert shader code to binary representation
src/%.b: shaders/%.glsl
	$(call compile,$(notdir $(patsubst %.glsl,%,$^)),$^,$@)
