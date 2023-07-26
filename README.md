# EssnusbV2
Extension to previous project Essnusb

# 1.Prerequisites
The project depends on the following subproject (for each the version used is added after the name):
  a) CERN ROOT 6.28.04 - https://root.cern/releases/release-62804/
  b) Geant4 geant4-11.1-release - https://geant4-userdoc.web.cern.ch/UsersGuides/InstallationGuide/html/installguide.html
  c) Genie  (tag repoR-3_04_00 from repo) - https://hep.ph.liv.ac.uk/~costasa/genie/get_started.html

Each of the above project has its own dependencies. The bewow list the procedure to build them on Linux Mint 21.2
## A) CERN ROOT 6.28.04 
  To install the required packages use
    ** # sudo apt-get install dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev libssl-dev **

  Pythia6 is required to have the Root lib generated, also it is used by Genie
  To build it navigate to ** ~/third_party/genie/dependencies/pythia6**
  And execute 
   ** #source build_pythia6.sh **

  
  Gsl has to be build, the sources used are located in ~third_party/root_v6.28.04/dependencies/gsl-2.7.1
  Open a terminal and type
    #./configure
    #make
    #make install

    
