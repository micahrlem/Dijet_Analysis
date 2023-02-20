void MakeEtaPhi_2D(string infile = "jetsMedium0to55.root"){
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    //Load the tree into memory (TNtuple is a 1D tree)
    
    TNtuple* tree = (TNtuple*)gROOT->FindObject("ntp_truthjet");
        

    TH2F* EtavsPhiTruth = new TH2F("EtavsPhiTruth","",20,-TMath::Pi(),TMath::Pi(),20,-1,1);
    TH2F* EtavsPhiReco = new TH2F("EtavsPhiReco","",20,-TMath::Pi(),TMath::Pi(),20,-1,1);
    TH1F* hTruthPhi = new TH1F("hTruthPhi","",50,-TMath::Pi(),TMath::Pi());
    TH1F* hRecoPhi = new TH1F("hRecoPhi","",50,-TMath::Pi(),TMath::Pi());
    TH1F* hTruthEta = new TH1F("hTruthEta","",25,-1,1);
    TH1F* hRecoEta = new TH1F("hRecoEta","",25,-1,1);
   
    //But mostly we will want to step through the tree to do a calculation
    
    
    //number of entries in tree
    int Nentries = tree->GetEntries();
    
    //connect variables in the code to variables in the tree

    float eta,geta,phi,gphi,event;
    tree->SetBranchAddress("event",&event);
    tree->SetBranchAddress("eta",&eta);
    tree->SetBranchAddress("geta",&geta);
    tree->SetBranchAddress("phi",&phi);
    tree->SetBranchAddress("gphi",&gphi);

   float curevent;
    float eta1 = 0;
    float reta1 = 0; 
    float phi1 = 0; 
    float rphi1 = 0; 

    for (int i = 0;i<Nentries;i++){ 
        //loop over entries
        tree->GetEntry(i);
        if (i == 0)
            curevent = event;

        if (event == curevent)//still in same event
        { 
            eta1 = geta; reta1 = eta;
            phi1 = gphi; rphi1 = phi;
            
        }
        
        if (event != curevent){//first entry of next event
       
            {//Filling Histograms
                EtavsPhiTruth->Fill(phi1,eta1);
                EtavsPhiReco->Fill(rphi1,reta1);
                hTruthPhi->Fill(phi1);
                hRecoPhi->Fill(rphi1);
                hTruthEta->Fill(eta1);
                hRecoEta->Fill(reta1);
            }

           
            curevent = event;
        }
       


    } //end loop ntuple
    
    //Then we would want to save these histograms to a file so that we can Draw them in a macro
    TString outfilename = infile;
    outfilename.Prepend("etaphi2D_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    
    EtavsPhiTruth->Write();
    EtavsPhiReco->Write();
    hTruthPhi->Write();
    hRecoPhi->Write();
    hTruthEta->Write();
    hRecoEta->Write();

    
}
