#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

HOMEKIT_PATH ?= $(abspath $(shell pwd)/../..)
COMMON_COMPONENT_PATH ?= $(HOMEKIT_PATH)/examples/common/

PROJECT_NAME := lightbulb
EXTRA_COMPONENT_DIRS += $(HOMEKIT_PATH)/components/
EXTRA_COMPONENT_DIRS += $(HOMEKIT_PATH)/components/homekit
EXTRA_COMPONENT_DIRS += $(COMMON_COMPONENT_PATH)

include $(IDF_PATH)/make/project.mk

$(info    HOMEKIT_PATH is $(HOMEKIT_PATH))
$(info    COMMON_COMPONENT_PATH is $(COMMON_COMPONENT_PATH))