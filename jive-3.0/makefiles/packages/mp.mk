
# Generated on Mon  1 Oct 13:34:34 CEST 2018.
# CHANGES TO THIS FILE WILL BE LOST.

ifndef JIVE_MP_MAKEDEFS_MK
       JIVE_MP_MAKEDEFS_MK = 1

ifndef JIVEPATH
  JIVEPATH := $(JIVEDIR)
endif

include $(JIVEPATH)/makefiles/jive.mk

include $(JIVEPATH)/makefiles/packages/util.mk

JIVE_PACKAGES += mp
JIVE_LIBS     := jivemp $(JIVE_LIBS)

endif
