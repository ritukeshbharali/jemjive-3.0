
# Generated on Mon  1 Oct 13:34:35 CEST 2018.
# CHANGES TO THIS FILE WILL BE LOST.

ifndef JIVE_FEM_MAKEDEFS_MK
       JIVE_FEM_MAKEDEFS_MK = 1

ifndef JIVEPATH
  JIVEPATH := $(JIVEDIR)
endif

include $(JIVEPATH)/makefiles/jive.mk

include $(JIVEPATH)/makefiles/packages/algebra.mk
include $(JIVEPATH)/makefiles/packages/app.mk
include $(JIVEPATH)/makefiles/packages/model.mk
include $(JIVEPATH)/makefiles/packages/geom.mk
include $(JIVEPATH)/makefiles/packages/graph.mk
include $(JIVEPATH)/makefiles/packages/mp.mk
include $(JIVEPATH)/makefiles/packages/util.mk

JIVE_PACKAGES += fem
JIVE_LIBS     := jivefem $(JIVE_LIBS)

endif
