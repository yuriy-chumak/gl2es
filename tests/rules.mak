# --------------------------------------
# global build setup, you can change it:

# output package file name
APK_NAME ?= debug.apk
# used build tools version
BUILD_TOOLS_VERN ?= 29.0.2
# android platform version
PLATFORM_VERN = android-29

# native architectures supported
NATIVE_PLATFORMS = armeabi-v7a arm64-v8a x86 x86_64

# default OpenGL version
GL_VERSION ?= 1.5

# :end of setup
# --------------------------------------

# extract package name from AndroidManifest.xml
PACKAGE=$(shell cat AndroidManifest.xml |sed -n 's/.*package="\([^"]*\)".*/\1/p')

# -------------------------------------------------
.PHONY: help
help:
	@echo "Usage:"
	@echo "  make build - build a regular android app"
	@echo "  make install - install built package"
	@echo "  make uninstall - uninstall built package"
	@echo ""
	@echo "  make clean - delete intermediate files"
	@echo "  make distclean - delete untracked files"

.PHONY: build install uninstall clean
# -------------------------------------------------
# setup Ol and Android folders and toolsets
OL_ROOT    ?= $(abspath ../../../../../..)
OL_ANDROID ?= $(OL_ROOT)/extensions/android

include $(OL_ANDROID)/rules.mk

# change if you want
KEYSTOREPWD = thepassword

# -------------------------------------------------
# extract all System.loadLibrary("olvm")s from the Main.java
LIBS=$(shell cat src/$(subst .,/,$(PACKAGE))/Main.java |sed -n '/loadLibrary/p' |sed 's/.*"\(.\+\)".*/\1/')

# copy prebuilt native libraries (*.so)
$(foreach so,$(LIBS:%=lib%.so),$(eval $(call SO,$(so))))

# copy java ol bridge sources (*.java)
# no files

# copy required ol libraries and includes (*.scm, *.lisp)
assets: assets/otus/case-apply.scm
assets: assets/otus/ffi.scm

assets: assets/lib/gl/config.scm
assets: assets/lib/gl/Android.lisp
assets: assets/lib/gl.scm

assets: assets/OpenGL/platform.scm
assets: assets/OpenGL/1.scm

ifeq ($(GL_VERSION),1.1)
assets: assets/OpenGL/1.1.scm
endif
ifeq ($(GL_VERSION),1.2)
assets: assets/OpenGL/1.1.scm
assets: assets/OpenGL/1.2.scm
endif
ifeq ($(GL_VERSION),1.3)
assets: assets/OpenGL/1.1.scm
assets: assets/OpenGL/1.2.scm
assets: assets/OpenGL/1.3.scm
endif
ifeq ($(GL_VERSION),1.4)
assets: assets/OpenGL/1.1.scm
assets: assets/OpenGL/1.2.scm
assets: assets/OpenGL/1.3.scm
assets: assets/OpenGL/1.4.scm
endif
ifeq ($(GL_VERSION),1.5)
assets: assets/OpenGL/1.1.scm
assets: assets/OpenGL/1.2.scm
assets: assets/OpenGL/1.3.scm
assets: assets/OpenGL/1.4.scm
assets: assets/OpenGL/1.5.scm
endif
ifeq ($(GL_VERSION),2.0)
assets: assets/OpenGL/1.1.scm
assets: assets/OpenGL/1.2.scm
assets: assets/OpenGL/1.3.scm
assets: assets/OpenGL/1.4.scm
assets: assets/OpenGL/1.5.scm
assets: assets/OpenGL/2.scm
endif
ifeq ($(GL_VERSION),2.1)
assets: assets/OpenGL/1.1.scm
assets: assets/OpenGL/1.2.scm
assets: assets/OpenGL/1.3.scm
assets: assets/OpenGL/1.4.scm
assets: assets/OpenGL/1.5.scm
assets: assets/OpenGL/2.scm
assets: assets/OpenGL/2.1.scm
endif

ifneq (,$(findstring GLU,$(LIBS)))
assets: assets/lib/GLU.scm
endif

# -------------------------------------------------
clean:
	git clean -Xdf .
distclean:
	git clean -xdf .

install:
	adb -d install -r $(APK_NAME)
uninstall:
	adb -d uninstall $(PACKAGE)
reinstall:
	$(MAKE) uninstall install

start:
	adb shell am start -n $(PACKAGE)/.Main
stop:
	adb shell am force-stop $(PACKAGE)
restart:
	$(MAKE) stop start

check:
	@$(MAKE) silentcheck --silent

silentcheck:
	adb logcat --clear; sleep 0.1
	adb shell am start -n $(PACKAGE)/.Main >/dev/null
	(adb logcat -v color ol:I *:S & echo $$! >&3) 3>/tmp/logcat.$$PPID | sed '/APP_CMD_DESTROY/q' |grep "$(notdir $(CURDIR)):"
	# cleanup
	kill `cat /tmp/logcat.$$PPID`
	rm /tmp/logcat.$$PPID
