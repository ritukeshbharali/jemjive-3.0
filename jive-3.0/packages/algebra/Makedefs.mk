
# Generated on Mon  1 Oct 13:34:34 CEST 2018.
# CHANGES TO THIS FILE WILL BE LOST.

ifndef JIVE_ALGEBRA_MAKEDEFS_MK
       JIVE_ALGEBRA_MAKEDEFS_MK = 1

ifndef JIVEPATH
  JIVEPATH := $(JIVEDIR)
endif

include $(JIVEPATH)/makefiles/jive.mk

include $(JIVEPATH)/makefiles/packages/mp.mk
include $(JIVEPATH)/makefiles/packages/util.mk

JIVE_PACKAGES += algebra
JIVE_LIBS     := jivealgebra $(JIVE_LIBS)

endif
