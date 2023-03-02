
# Generated on Fri 20 Dec 14:32:22 CET 2019.
# CHANGES TO THIS FILE WILL BE LOST.


ifndef JEM_UTIL_MAKEDEFS_MK
       JEM_UTIL_MAKEDEFS_MK = 1

ifndef JEMPATH
  JEMPATH := $(JEMDIR)
endif
include $(JEMPATH)/makefiles/packages/base.mk
include $(JEMPATH)/makefiles/packages/io.mk

JEM_PACKAGES += util

DBG_TOOLS    += $(JEMPATH)/lib/util_debug$(OBJ_SUFFIX)

endif
