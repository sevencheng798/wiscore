#By Seven 
#make files.
SUBDIRS=alsa-utils wisapps
PACKAGE_LOCAL=package/utils

.PHONY: compile clean install uninstall

compile:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
    	(echo $(PWD)); \
		(cp -rf $$subdir $(OPWRT_WORKSPACE)/$(PACKAGE_LOCAL)); \
        (cd $(OPWRT_WORKSPACE) && make $(PACKAGE_LOCAL)/$$subdir/clean V=s); \
    done;

clean:

install:

uninstall:


