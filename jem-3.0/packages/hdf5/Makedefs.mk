
# Generated on Fri 20 Dec 14:32:24 CET 2019.
# CHANGES TO THIS FILE WILL BE LOST.


ifndef JEM_HDF5_MAKEDEFS_MK
       JEM_HDF5_MAKEDEFS_MK = 1

ifndef JEMPATH
  JEMPATH := $(JEMDIR)
endif
include $(JEMPATH)/makefiles/packages/base.mk
include $(JEMPATH)/makefiles/packages/util.mk
include $(JEMPATH)/makefiles/packages/io.mk

JEM_PACKAGES += hdf5
JEM_LIBS     := jemhdf5 $(JEM_LIBS)

SYS_LIBS     := hdf5_serial $(SYS_LIBS)
SYS_INCDIRS  := /usr/include/hdf5/serial $(SYS_INCDIRS)

endif
