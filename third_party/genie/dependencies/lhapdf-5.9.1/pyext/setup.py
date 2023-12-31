#! /usr/bin/env python

from distutils.core import setup, Extension

longdesc = """This is a simple SWIG wrapper on the main steering interface of
the LHAPDF parton density library. It is used to create, query and
use the LHAPDF data from a Python program.
"""

## Extension definition
import os
wrapsrc = './lhapdf_wrap.cc'
incdir_src = os.path.abspath('../include')
incdir_build = os.path.abspath('../include')
libdir = os.path.abspath('../lib')
cxxargs = ''.split()
ldargs = ''.split()
ext = Extension('_lhapdf',
                [wrapsrc],
                include_dirs=[incdir_src, incdir_build],
                library_dirs=[libdir, os.path.join(libdir,'.libs')],
                extra_compile_args = cxxargs,
                extra_link_args = ldargs,
                libraries=['LHAPDF'])

## Setup definition
setup(name = 'lhapdf',
      version = '5.9.1',
      #include_package_data = True,
      ext_modules=[ext],
      py_modules = ['lhapdf'],

      author = ['Andy Buckley'],
      author_email = 'andy@insectnation.org',
      url = 'http://projects.hepforge.org/lhapdf/',
      description = 'Rivet: a Python interface to the LHAPDF high-energy physics parton density library.',
      long_description = longdesc,
      keywords = 'generator montecarlo simulation data hep physics particle validation analysis tuning',
      license = 'GPL',
      )

