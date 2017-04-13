#By Seven 
#make files.
SUBDIRS=alsa-lib libao
PACKAGE_LOCAL=package/libs

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


