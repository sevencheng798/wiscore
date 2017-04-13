#By Seven 2017-0306
#make files.
SUBDIRS=target package

export OPWRT_WORKSPACE=$(OPENWRT_PATH)/$(OPENWRT_VERSION)-$(OPENWRT_VENDOR)-$(OPENWRT_VENDOR_VERSION)

.PHONY: compile clean install uninstall

compile:
	cp -rf opwrt-wisavs-topv001-3-20170405.config $(OPWRT_WORKSPACE)/.config
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		(echo $(PWD)); \
		(cd $$subdir && make || exit "$$?"); \
	done;
	

clean:

install:

uninstall:

