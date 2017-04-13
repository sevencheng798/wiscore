#By Seven 
#make files.
SUBDIRS=curl nghttp2
PACKAGE_LOCAL=package/network/utils

.PHONY: compile clean install uninstall

compile:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
    	(echo $(PWD)); \
		if [ -d $(OPWRT_WORKSPACE)/$(PACKAGE_LOCAL)/ ]; then \
			(cp -rf $$subdir/ $(OPWRT_WORKSPACE)/$(PACKAGE_LOCAL)); \
        	(cd $(OPWRT_WORKSPACE) && make $(PACKAGE_LOCAL)/$$subdir/clean V=s || exit "$$?"); \
		else \
			exit 1; \
		fi; \
    done;

clean:

#	@list='$(SUBDIRS)'; for subdir in $$list; do \
#		(cd $subdir && make clean); \
#	done;

install:

uninstall:


