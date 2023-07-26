//____________________________________________________________________________
/*!

\class    genie::HEDISInteractionListGenerator

\brief    Concrete implementations of the InteractionListGeneratorI interface.
          Generate a list of all the Interaction (= event summary) objects that
          can be generated by the HEDIS EventGenerator.

\author   Alfonso Garcia <alfonsog \at nikhef.nl>
          NIKHEF

\created  August 28, 2019

\cpright  Copyright (c) 2003-2023, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _HEDIS_INTERACTION_LIST_GENERATOR_H_
#define _HEDIS_INTERACTION_LIST_GENERATOR_H_

#include <map>

#include "Framework/EventGen/InteractionListGeneratorI.h"
#include "Framework/Interaction/Interaction.h"

using std::multimap;

namespace genie {

class Interaction;

class HEDISInteractionListGenerator : public InteractionListGeneratorI {

public :
  HEDISInteractionListGenerator();
  HEDISInteractionListGenerator(string config);
 ~HEDISInteractionListGenerator();

  // implement the InteractionListGeneratorI interface
  InteractionList * CreateInteractionList(const InitialState & init) const;
  InteractionList * CreateHEDISlist(vector<InitialState> vinit, 
                                  vector<InteractionType_t> vinttype) const;

  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:


  multimap<int,bool> GetHitQuarks(const Interaction * interaction) const;
  vector<int> GetFinalQuarks(const Interaction * interaction) const;

  void LoadConfigData(void);
  
  bool fIsCC;
  bool fIsNC;

};

}      // genie namespace

#endif // _HEDIS_INTERACTION_LIST_GENERATOR_H_
