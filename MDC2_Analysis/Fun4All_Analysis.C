#ifndef MACRO_FUN4ALLANALYSIS_C
#define MACRO_FUN4ALLANALYSIS_C
#include <fun4all/Fun4AllServer.h>
#include <fun4all/Fun4AllInputManager.h>
#include <fun4all/Fun4AllDstInputManager.h>
#include <fun4all/Fun4AllDummyInputManager.h>
#include <fun4all/Fun4AllDstOutputManager.h>

#include <fun4all/Fun4AllOutputManager.h>


#include <g4jets/ClusterJetInput.h>
#include <g4jets/FastJetAlgo.h>
#include <g4jets/JetReco.h>
#include <g4jets/TowerJetInput.h>
#include <g4jets/TrackJetInput.h>
#include <g4jets/TruthJetInput.h>




#include <g4centrality/PHG4CentralityReco.h>

#include <jetbackground/CopyAndSubtractJets.h>
#include <jetbackground/DetermineTowerBackground.h>
#include <jetbackground/FastJetAlgoSub.h>
#include <jetbackground/RetowerCEMC.h>
#include <jetbackground/SubtractTowers.h>
#include <jetbackground/SubtractTowersCS.h>


#include <HIJetReco.C>





#include <analysis/analysis.h>

R__LOAD_LIBRARY(libfun4all.so)
R__LOAD_LIBRARY(libg4jets.so)
R__LOAD_LIBRARY(libjetbackground.so)
R__LOAD_LIBRARY(libanalysis.so)
R__LOAD_LIBRARY(libg4centrality.so)
R__LOAD_LIBRARY(libg4dst.so)



void Fun4All_Analysis(const char *filelistbbc = "dst_bbc_g4hit.list", const char *filelistcalo = "dst_calo_cluster.list",const char *filelisttruth = "dst_truth_jet.list" ,string outputfilename = "test.root", const int nEvents = 10000)
{
  ///////////////////////////////////////////
  // Make the Server
  //////////////////////////////////////////
  Fun4AllServer *se = Fun4AllServer::instance();
  se->Verbosity(0);

  //-----------------------------------------------------------------------
  //Read in a file containing the truth jet information
  //-----------------------------------------------------------------------
  /* Fun4AllInputManager *t_in = new Fun4AllDstInputManager("DSTin");
  t_in->fileopen(inputFile1);
  se->registerInputManager(t_in);*/

  //---------------------------------------------------------------------------
  //Read in a file containing the calorimeter information
  //---------------------------------------------------------------------------

 
  Fun4AllInputManager *intrue = new Fun4AllDstInputManager("DSTtruth");
  intrue->AddListFile(filelisttruth,1);
  se->registerInputManager(intrue);

   Fun4AllInputManager *in1 = new Fun4AllDstInputManager("DSTbbc");
  in1->AddListFile(filelistbbc,1);
  se->registerInputManager(in1);


  Fun4AllInputManager *in2 = new Fun4AllDstInputManager("DSTcalo");
  in2->AddListFile(filelistcalo,1);
  se->registerInputManager(in2); 

 

 /* Fun4AllInputManager*  in = new Fun4AllDstInputManager("DSTCALOCLUSTERS");
 in->fileopen(inputFile2);
 se->registerInputManager(in);*/
 //----------------------------------------------------------------------------------------------
 //add in centrality node

PHG4CentralityReco *cent = new PHG4CentralityReco();
  cent->Verbosity(0);
  cent->GetCalibrationParameters().ReadFromFile("centrality", "xml", 0, 0, string(getenv("CALIBRATIONROOT")) + string("/Centrality/"));
  se->registerSubsystem( cent );

 //Perform the jet reconstruction: by default producing 0.2-0.8 jets
 //----------------------------------------------------------------------------------------------

 HIJetReco();

  //-----------------------------------------------
  // register up the analysis module
  //-----------------------------------------------

  analysis *myreco = new analysis();
  myreco->SetOutputFileName(outputfilename);
  se->registerSubsystem(myreco);
  
  

  if (nEvents <= 0)
  {
    return;
  }
  cout << endl << "Running over " << nEvents << " Events" << endl;
  se->run(nEvents);
  cout << endl << "Calling End in Fun4All_Analysis.C" << endl;
  se->End();
  cout << endl << "All done, calling delete Fun4AllServer" << endl;
  delete se;
  cout << endl << "gSystem->Exit(0)" << endl;
  se->PrintTimer();
  gSystem->Exit(0);
}
#endif // MACRO_FUN4ALLANALYSIS_C

