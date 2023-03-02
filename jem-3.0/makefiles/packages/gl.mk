
# Generated on Fri 20 Dec 14:32:23 CET 2019.
# CHANGES TO THIS FILE WILL BE LOST.


ifndef JEM_GL_MAKEDEFS_MK
       JEM_GL_MAKEDEFS_MK = 1

ifndef JEMPATH
  JEMPATH := $(JEMDIR)
endif
include $(JEMPATH)/makefiles/packages/base.mk
include $(JEMPATH)/makefiles/packages/io.mk
include $(JEMPATH)/makefiles/packages/util.mk

JEM_PACKAGES += gl
JEM_LIBS     := jemgl $(JEM_LIBS)

SYS_LIBS     := glfw GLU GL X11 $(SYS_LIBS)

endif
