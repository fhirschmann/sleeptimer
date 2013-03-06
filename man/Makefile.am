man_MANS = halttimer.1
EXTRA_DIST = $(man_MANS)
MAINTAINERCLEANFILES = $(man_MANS)

common_mandeps = $(top_srcdir)/configure.ac

halttimer.1: $(top_srcdir)/src/halttimer.c $(common_mandeps)
	$(HELP2MAN) \
		--name="a simple shut down timer" \
		--no-info \
		--include=help2man.include \
		$(top_srcdir)/src/halttimer -o $@
