#!/bin/sh -ex
NAME="xenplat"

#TODO: we assume that we're building for X86_64, which we shouldn't do
UK_FAMILY=x86
ARCH=x86_64

prefix=${1:-$PREFIX}
if [ "$prefix" = "" ]; then
    prefix=`opam config var prefix`
fi
DESTINC=${prefix}/include/${NAME}
DESTLIB=${prefix}/lib/${NAME}
mkdir -p ${DESTINC} ${DESTLIB}

# `dune build` will fail for downstream packages if we don't have a META file

touch ${DESTLIB}/META

# xenplat
ar rcs libxenplat.a \
        build/libnolibc.o \
        build/libxenplat.o \
        build/libukargparse.o build/libukboot.o \
        build/libukalloc.o build/libukallocbbuddy.o \
        build/libuksched.o build/libukschedcoop.o \
        build/libukdebug.o \
        build/libuklock.o
cp libxenplat.a ${DESTLIB}/libxenplat.a

# xen headers
UNIKRAFT_MISC=unikraft-misc-includes
mkdir -p ${DESTINC}/plat/xen/include
mkdir -p ${DESTINC}/plat/common/include
mkdir -p ${DESTINC}/${UNIKRAFT_MISC}
cp -r plat/xen/include ${DESTINC}/plat/xen/
UNIKRAFT_MISC_INCLUDES="errno.h inttypes.h limits.h stdint.h"
for f in ${UNIKRAFT_MISC_INCLUDES}; do
    cp lib/nolibc/include/${f} ${DESTINC}/${UNIKRAFT_MISC}/${f}
done
# just get all of the platform headers
cp -r include/uk ${DESTINC}/uk

# get everything in plat/xen/include
cp -r plat/xen/include ${DESTINC}/plat/xen/

# also everything in plat/common/include
cp -r plat/common/include ${DESTINC}/plat/common/

# put all the arch-specific stuff into the common uk/ include directory
cp -r arch/${UK_FAMILY}/${ARCH}/include/uk ${DESTINC}/

# include the config we generated from .config
# ideally we'd check on some arch/platform stuff first and
# substitute as appropriate
cp build/include/uk/_config.h ${DESTINC}/uk/_config.h

# ukdebug headers (all code is inlined there)
cp lib/ukdebug/include/uk/assert.h ${DESTINC}/uk/assert.h
cp lib/ukdebug/include/uk/print.h ${DESTINC}/uk/print.h

# headers for all libraries go in uk/
cp -r lib/ukalloc/include/uk/*.h ${DESTINC}/uk/
cp -r lib/uksched/include/uk/*.h ${DESTINC}/uk/
cp -r lib/ukschedcoop/include/uk/*.h ${DESTINC}/uk/

# super portable, no problem (uh, TODO)
ARCH_CFLAGS="-m64 -mno-red-zone -fno-reorder-blocks -fno-asynchronous-unwind-tables"
GCC_INSTALL=$(LANG=c gcc -print-search-dirs | sed -n -e 's/install: \(.*\)/\1/p')

# get the linker script too
cp plat/xen/x86/link64.lds ${DESTLIB}/

# pkg-config
libname=lib${NAME}
sed \
  -e "s/@ARCH_LDFLAGS@/${ARCH_LDFLAGS}/g" \
  -e "s/@ARCH_CFLAGS@/${ARCH_CFLAGS}/g" \
  -e "s!@GCC_INSTALL@!${GCC_INSTALL}!g" \
  ${libname}.pc.in > ${libname}.pc
mkdir -p ${prefix}/lib/pkgconfig
cp ${libname}.pc ${prefix}/lib/pkgconfig/${libname}.pc
tail -2 ${libname}.pc|head -1|sed 's/Cflags: //;s!\${prefix\}!%{prefix}%!g' > cflags
tail -1 ${libname}.pc|sed 's/Libs: //;s!\${prefix\}!%{prefix}%!g' > libs
opam config subst xenplat cflags
cp cflags libs ${DESTLIB}/
