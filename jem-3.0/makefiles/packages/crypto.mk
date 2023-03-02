
# Generated on Fri 20 Dec 14:32:23 CET 2019.
# CHANGES TO THIS FILE WILL BE LOST.


ifndef JEM_CRYPTO_MAKEDEFS_MK
       JEM_CRYPTO_MAKEDEFS_MK = 1

ifndef JEMPATH
  JEMPATH := $(JEMDIR)
endif
include $(JEMPATH)/makefiles/packages/base.mk
include $(JEMPATH)/makefiles/packages/util.mk
include $(JEMPATH)/makefiles/packages/io.mk

JEM_PACKAGES += crypto
JEM_LIBS     := jemcrypto $(JEM_LIBS)

SYS_LIBS     := crypto $(SYS_LIBS)

endif
