//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************

#include "G4VtkQt.hh"
#include "G4VtkQtSceneHandler.hh"
#include "G4VtkQtViewer.hh"

#include "G4UIQt.hh"
#include "G4UImanager.hh"
#include "G4UIbatch.hh"

G4VtkQt::G4VtkQt(): G4VGraphicsSystem("VtkQt","VTKQt","VTK with Qt",
                                  G4VGraphicsSystem::noFunctionality)
{}

G4VtkQt::~G4VtkQt() {}

G4VSceneHandler* G4VtkQt::CreateSceneHandler(const G4String& name) {
  G4VSceneHandler* pScene = new G4VtkQtSceneHandler(*this, name);
  return pScene;
}

G4VViewer* G4VtkQt::CreateViewer(G4VSceneHandler& scene,
                                 const G4String& name) {
  G4VViewer* pView = new G4VtkQtViewer((G4VtkQtSceneHandler&) scene, name);
  if (pView) {
    if (pView->GetViewId() < 0) {
      G4cerr << "G4VtkQt::CreateViewer: ERROR flagged by negative"
                " view id in G4VtkViewer creation."
                "\n Destroying view and returning null pointer."
                << G4endl;
      delete pView;
      pView = nullptr;
    }
  }
  else {
    G4cerr << "G4Vtk::CreateViewer: ERROR: null pointer on new G4VtkViewer." << G4endl;
  }
  return pView;
}

G4bool G4VtkQt::IsUISessionCompatible () const
{
  G4bool isCompatible = false;
  G4UImanager* ui = G4UImanager::GetUIpointer();
  G4UIsession* session = ui->GetSession();

  // If session is a batch session, it may be:
  // a) this is a batch job (the user has not instantiated any UI session);
  // b) we are currently processing a UI command, in which case the UI
  //    manager creates a temporary batch session and to find out if there is
  //    a genuine UI session that the user has instantiated we must drill
  //    down through previous sessions to a possible non-batch session.
  while (G4UIbatch* batch = dynamic_cast<G4UIbatch*>(session)) {
    session = batch->GetPreviousSession();
  }

  // Qt windows are only appropriate in a Qt session.
  if (session) {
    // If non-zero, this is the originating non-batch session
    // The user has instantiated a UI session...
    if (dynamic_cast<G4UIQt*>(session)) {
      // ...and it's a G4UIQt session, which is OK.
      isCompatible = true;
    }
  }
  return isCompatible;
}
