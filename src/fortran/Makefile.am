# Get Fortran compile rules that include preprocessing.
include $(top_srcdir)/build-aux/fortran-rules.am

# Find Fortran modules from the fmm method.
AM_FCFLAGS = $(FC_MODINC)$(top_builddir)/lib/fmm/src

# Find header files (both generated ones and distributed ones)
# from the fmm method.
#AM_FCCPPFLAGS = -I$(top_builddir)/lib/fmm/src -I$(top_srcdir)/lib/fmm/src

nodist_include_HEADERS = fcs_module.$(FC_MODEXT)

if ENABLE_SINGLE_LIB
noinst_LIBRARIES = libfcs4fortran.a
else
lib_LIBRARIES = libfcs4fortran.a
endif

libfcs4fortran_a_SOURCES = \
	fcs4fortran.f90

fcs_module.$(FC_MODEXT): fcs4fortran.$(OBJEXT)
