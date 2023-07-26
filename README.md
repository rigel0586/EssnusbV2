# EssnusbV2
Extension to previous project Essnusb

# 1.Prerequisites
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
    create a new folder named **build** and enter it
    open the build folder and type:  <br />
    $cmake -S <extracted CLHEP folder> -B . -DCMAKE_INSTALL_PREFIX=<install path>
    #cmake --build .
    #cmake --install .

  - Expat dependency -> go to **/third_party/geant4/dependencies** and exctract in a clhep folder the expat-2.5.0.tar.gz  <br />
    create a new folder named **build** and enter it
    open the build folder and type:  <br />
    $cmake -S <extracted Expat folder> -B . -DCMAKE_INSTALL_PREFIX=<install path>
    #cmake --build .
    #cmake --install .

  - Zlib dependency -> go to **/third_party/geant4/dependencies** and exctract in a clhep folder the zlib-1.2.13.tar.gz  <br />
    create a new folder named **build** and enter it
    open the build folder and type:  <br />
    $cmake -S <extracted Zlib folder> -B . -DCMAKE_INSTALL_PREFIX=<install path>
    #cmake --build .
    #cmake --install .
  


    
