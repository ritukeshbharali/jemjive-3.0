
# Generated on Fri 20 Dec 14:32:24 CET 2019.
# CHANGES TO THIS FILE WILL BE LOST.


ifndef JEM_XUTIL_MAKEDEFS_MK
       JEM_XUTIL_MAKEDEFS_MK = 1

ifndef JEMPATH
  JEMPATH := $(JEMDIR)
endif
include $(JEMPATH)/makefiles/packages/util.mk

JEM_PACKAGES += xutil
JEM_LIBS     := jemxutil $(JEM_LIBS)


endif
