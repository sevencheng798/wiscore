#By Seven 
#make files.
SUBDIRS=config services utils

.PHONY: compile clean install uninstall

compile:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
    	(echo $(PWD)); \
        (cd $$subdir && make || exit "$$?"); \
    done;

clean:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		(cd $subdir && make clean); \
	done;

install:

uninstall:


