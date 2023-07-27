# EssnusbV2
Extension to previous project Essnusb

# 1.Prerequisites (The below are only if you want to build and run the application locally)
The project depends on the following subproject (for each the version used is added after the name): <br />
  a) CERN ROOT 6.28.04 - https://root.cern/releases/release-62804/ <br />
  b) Geant4 geant4-11.1-release - https://geant4-userdoc.web.cern.ch/UsersGuides/InstallationGuide/html/installguide.html <br />
  c) Genie  (tag repoR-3_04_00 from repo) - https://hep.ph.liv.ac.uk/~costasa/genie/get_started.html <br />
<br />
Each of the above project has its own dependencies. The bewow list the procedure to build them on Linux Mint 21.2 <br />

## A) CERN ROOT 6.28.04 
 - To install the required packages use <br />
      **$sudo apt-get install dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev libssl-dev cmake fastlink gfortran** <br />

- Pythia6 is required to have the Root lib generated, also it is used by Genie <br />
          To build it navigate to **~/third_party/genie/dependencies/pythia6** <br />
          Original linkg: * *https://github.com/GENIE-MC/Generator/tree/master/src/scripts/build/ext/build_pythia6.sh* *
          And execute  <br />
             **$source build_pythia6.sh** <br />

- Gsl has to be build, the sources used are located in **~third_party/root_v6.28.04/dependencies/gsl-2.7.1**<br />
          Open a terminal and type <br />
              #./configure <br />
              #make <br />
              #make install <br />

  Afthere the above have been build and installed, open the root directory **~/third_party/root_v6.28.04/source** and type
  **$cmake -S ../source -B . -DCMAKE_INSTALL_PREFIX=<install path> -Dmathmore=mathmore -Dpythia6=pythia6 -DPYTHIA6_INCLUDE_DIR=<path_pythia6_inc> -DPYTHIA6_LIBRARY= <path_Pythia6_lib>**
  **$cmake --build .**
  **$Cmake --install .**

  To have the root detected go to the installation folder and type
  **source /<install_path>/bin/thisroot.sh**
  After which root scripts can be executed.

## B) Geant4
  - CLHEP dependency -> go to **/third_party/geant4/dependencies** and exctract in a clhep folder the clhep-2.4.6.4.tgz  <br />
    create a new folder named **build** and enter it <br />
    open the build folder and type:  <br />
    $cmake -S \<extracted CLHEP folder\> -B . -DCMAKE_INSTALL_PREFIX=\<install path\> <br />
    $cmake --build . <br />
    $cmake --install . <br />

  - Expat dependency -> go to **/third_party/geant4/dependencies** and exctract in a clhep folder the expat-2.5.0.tar.gz  <br />
    create a new folder named **build** and enter it <br />
    open the build folder and type:  <br />
    $cmake -S \<extracted Expat folder\> -B . -DCMAKE_INSTALL_PREFIX=\<install path\> <br />
    $cmake --build . <br />
    $cmake --install . <br />

  - Zlib dependency -> go to **/third_party/geant4/dependencies** and exctract in a clhep folder the zlib-1.2.13.tar.gz  <br />
    create a new folder named **build** and enter it <br />
    open the build folder and type:  <br />
    $cmake -S \<extracted Zlib folder\> -B . -DCMAKE_INSTALL_PREFIX=\<install path\> <br />
    $cmake --build . <br />
    $cmake --install . <br />

  - Geant4  -> go to **~/third_party/geant4/geant4-geant4-11.1-release** which is the extracted content of **/third_party/geant4/dependencies/geant4-geant4-11.1-release.zip**   <br />
    create a new folder named **build** and enter it <br />
    open the build folder and type:  <br />
    $cmake -S \<extracted Geant folder ~/third_party/geant4/geant4-geant4-11.1-release \> -B . -DCMAKE_INSTALL_PREFIX=\<install path\> <br />
    $cmake --build . <br />
    $cmake --install . <br />

## C) Genie
 - To install the required packages use <br />
      **$sudo apt-get install libtool aclocal autoheader automake autoconf autotools-dev** <br />

 - log4cpp has to be build, the sources used are located in **~third_party/genie/dependencies/log4cpp/log4cpp-1.1.4**<br />
          Create a build folder, enter and a terminal, type <br />
              $cmake -S \<Path to ~third_party/genie/dependencies/log4cpp/log4cpp-1.1.4 \> -B . -DCMAKE_INSTALL_PREFIX=\<install path\> <br />
              $cmake --build . <br />
              $cmake --install . <br />

NOTE: If python cmd is not found for lhapdf6, navigate to /usr/bin and type
**cp python3 python** -> this will copy the python 3 as a python cmd. lhapdf requires python3.
 - lhapdf6 has to be build, the sources used are located in **~third_party/genie/dependencies/lhapdf6.5.4/LHAPDF-6.5.4**<br />
          Open a terminal, type <br />
              $./configure --prefix=\< install path is optional >\
              $gmake
              $gmake install
   
NOTE: If python cmd is not found for lhapdf5, navigate to /usr/bin and type
**cp python2 python** -> this will copy the python 2 as a python cmd.Lhapdf5 requires python 2.
 - lhapdf5 has to be build, the sources used are located in **~third_party/genie/dependencies/lhapdf-5.9.1**<br />
          Create a build folder, enter and a terminal, type <br />
              $export FCFLAGS=-std=legacy (Info: wihtout the this flag an error is shown https://sourceforge.net/p/auto-07p/bugs/9/ )
              $./configure --prefix=\< install path is optional >\
              $gmake
              $gmake install


Before following the installation instructions given above and and/or before running GENIE, make sure that:
-> You have defined $GENIE to point at your top level GENIE directory
-> You have defined $ROOTSYS to point at your ROOT installation
-> All your library paths ($ROOTSYS/lib, $GENIE/lib, /path/to/pyhia6, /path/to/libxml2/lib, /path/to/log4cpp/lib, ...) are listed in $LD_LIBRARY_PATH (of $DYLD_LIBRARY_PATH on Mac OS X)
-> All your binary paths ($ROOTSYS/bin, $GENIE/bin) are listed in $PATH

-Navigate to Genie folder, type in terminal <br />
    $export GENIE=\< path to genie source **~third_party/genie/repoR-3_04_00** \>  <br />
    $export ROOTSYS=\< path to root installation folder \>  <br />
    $export PATH=$PATH:\< path to root installation folder \>/bin  <br />
    $./configure --prefix=/some/installation/path <br />
               --disable-profiler <br />
               --disable-validation-tools <br />
               --disable-cernlib <br />
               --enable-lhapdf <br />
               --enable-flux-drivers <br />
               --enable-geom-drivers <br />
               --disable-doxygen <br />
               --enable-test <br />
               --enable-mueloss <br />
               --enable-dylibversion <br />
               --enable-t2k <br />
               --enable-fnal <br />
               --enable-atmo <br />
               --enable-nucleon-decay <br />
               --disable-masterclass <br />
               --disable-debug <br />
               --with-optimiz-level=O2 <br />
               --with-pythia6-lib=/full/path/to/my/libPythia6/ <br />
               --with-libxml2-inc=/full/path/to/my/libml2/includes/ <br />
               --with-libxml2-lib=/full/path/to/my/libxml2/library/ <br />
               --with-log4cpp-inc=/full/path/to/my/log4cpp/includes/ <br />
               --with-log4cpp-lib=/full/path/to/my/log4cpp/library/ <br />
               --lhapdf5-inc=/full/path/to/my/lhapdf5/includes/ <br />
               --lhapdf5-lib=/full/path/to/my/lhapdf5/library/ <br />

    To run genie binaries the following evironmental variables have to be set: 
    $export PATH=$PATH:$ROOTSYS/bin:$GENIE/bin -> ROOTSYS and GENIE are set above
    $export LD_LIBRARY_PATH=$LD_LIBRARY_PATH: ~/third_party/genie/dependencies/pythia6/v6_428/lib:~/third_party/genie/dependencies/lhapdf-5.9.1/lib/.libs:~/third_party/genie/dependencies/log4cpp/install/lib:/usr/local/lib:\<root install folder\>/lib:\<genie install folder\>/lib
               
  

    
