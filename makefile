# To see a list of available make targets from bash, type:
# make <space> <tab> <tab>


include op2ext/makefile-generic.mk


# Set compiler to mingw (can still override from command line)
config := mingw


CPPFLAGS := -Iop2ext/srcStatic/
CXXFLAGS := -std=c++17 -O2 -g -Wall -Wextra -Wpedantic -Wno-unknown-pragmas
LDFLAGS := -static-libgcc -static-libstdc++ -Lop2ext/
LDLIBS := -lop2ext


.PHONY: all garageSaveLoadBugModule op2ext clean-all op2ext-clean-all

all: garageSaveLoadBugModule
GarageSaveLoadBugModule.dll: | op2ext
op2ext:
	+make -C op2ext/

clean-all: op2ext-clean-all
op2ext-clean-all:
	make -C op2ext/ clean-all

$(eval $(call DefineCppProject,garageSaveLoadBugModule,GarageSaveLoadBugModule.dll,./*.cpp))


# Docker and CircleCI commands
$(eval $(call DefineDockerImage,.circleci/,outpostuniverse/gcc-mingw-wine-googletest-circleci,1.2))
$(eval $(call DefineCircleCi))


ifdef Outpost2Path

.PHONY: install run

ModuleFolder := $(Outpost2Path)GarageSaveLoadBugModule/
TargetName := $(ModuleFolder)op2mod.dll

install: $(TargetName)

$(TargetName): GarageSaveLoadBugModule.dll
	@mkdir -p $(ModuleFolder)
	cp GarageSaveLoadBugModule.dll "$(TargetName)"

run: install
	wine "$(Outpost2Path)Outpost2.exe" /loadmod GarageSaveLoadBugModule

endif
