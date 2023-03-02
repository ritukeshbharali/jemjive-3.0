
# Generated on Mon  1 Oct 13:34:34 CEST 2018.
# CHANGES TO THIS FILE WILL BE LOST.

ifndef JIVE_UTIL_MAKEDEFS_MK
       JIVE_UTIL_MAKEDEFS_MK = 1

ifndef JIVEPATH
  JIVEPATH := $(JIVEDIR)
endif

include $(JIVEPATH)/makefiles/jive.mk


JIVE_PACKAGES += util
JIVE_LIBS     := jiveutil $(JIVE_LIBS)

endif
