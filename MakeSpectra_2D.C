void MakeSpectra_2D(string infile = "jetsMedium0to55.root"){
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    //Load the tree into memory (TNtuple is a 1D tree)
    
    TNtuple* tree = (TNtuple*)gROOT->FindObject("ntp_truthjet");
        

    TH2F* TruthvsRecoEta = new TH2F("TruthvsRecoEta","",50,-1,1,50,-1,1);
    TH2F* TruthvsRecoPhi = new TH2F("TruthvsRecoPhi","",50,-TMath::Pi(),TMath::Pi(),50,-TMath::Pi(),TMath::Pi());
    TH2F* TruthvsRecoPt = new TH2F("TruthvsRecoPt","",70,0,70,70,0,70);
    TH1F* hTruthPhi = new TH1F("hTruthPhi","",50,-TMath::Pi(),TMath::Pi());
    TH1F* hRecoPhi = new TH1F("hRecoPhi","",50,-TMath::Pi(),TMath::Pi());
    TH1F* hTruthEta = new TH1F("hTruthEta","",25,-1,1);
    TH1F* hRecoEta = new TH1F("hRecoEta","",25,-1,1);
   
    //But mostly we will want to step through the tree to do a calculation
    
    
    //number of entries in tree
    int Nentries = tree->GetEntries();
    
    //connect variables in the code to variables in the tree

      float eta,geta,phi,gphi,event,pt,gpt;
    tree->SetBranchAddress("event",&event);
    tree->SetBranchAddress("eta",&eta);
    tree->SetBranchAddress("geta",&geta);
    tree->SetBranchAddress("phi",&phi);
    tree->SetBranchAddress("gphi",&gphi);
    tree->SetBranchAddress("pt",&pt);
    tree->SetBranchAddress("gpt",&gpt);

 float curevent;
    float eta1 = 0;
    float reta1 = 0; 
    float phi1 = 0; 
    float rphi1 = 0; 
    float pt1 = 0;
    float rpt1 = 0;

    for (int i = 0;i<Nentries;i++){ 
        //loop over entries
        tree->GetEntry(i);
        if (i == 0)
            curevent = event;

        if (event == curevent && gpt > 15)//still in same event
        { 
            eta1 = geta; reta1 = eta;
            phi1 = gphi; rphi1 = phi;
             pt1 = gpt; rpt1 = pt;
            
        }
        
        if (event != curevent){//first entry of next event
       
            {//Filling Histograms
                TruthvsRecoEta->Fill(eta1,reta1);
                TruthvsRecoPhi->Fill(phi1,rphi1);
                TruthvsRecoPt->Fill(pt1,rpt1);
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
    outfilename.Prepend("spectra2D_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    
    TruthvsRecoEta->Write();
    TruthvsRecoPhi->Write();
    TruthvsRecoPt->Write();
    hTruthPhi->Write();
    hRecoPhi->Write();
    hTruthEta->Write();
    hRecoEta->Write();

    
}
