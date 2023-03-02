
# Generated on Mon  1 Oct 13:34:35 CEST 2018.
# CHANGES TO THIS FILE WILL BE LOST.

ifndef JIVE_FEMODEL_MAKEDEFS_MK
       JIVE_FEMODEL_MAKEDEFS_MK = 1

ifndef JIVEPATH
  JIVEPATH := $(JIVEDIR)
endif

include $(JIVEPATH)/makefiles/jive.mk

include $(JIVEPATH)/makefiles/packages/algebra.mk
include $(JIVEPATH)/makefiles/packages/fem.mk
include $(JIVEPATH)/makefiles/packages/model.mk
include $(JIVEPATH)/makefiles/packages/geom.mk
include $(JIVEPATH)/makefiles/packages/util.mk

JIVE_PACKAGES += femodel
JIVE_LIBS     := jivefemodel $(JIVE_LIBS)

endif
