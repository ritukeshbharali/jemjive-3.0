
# Generated on Fri 20 Dec 14:32:22 CET 2019.
# CHANGES TO THIS FILE WILL BE LOST.


ifndef JEM_BASE_MAKEDEFS_MK
       JEM_BASE_MAKEDEFS_MK = 1

ifndef JEMPATH
  JEMPATH := $(JEMDIR)
endif
include $(JEMPATH)/makefiles/jem.mk
include $(JEMPATH)/makefiles/packages/io.mk
include $(JEMPATH)/makefiles/packages/util.mk

JEM_PACKAGES += base

DBG_TOOLS    += $(JEMPATH)/lib/base_debug$(OBJ_SUFFIX)

endif
