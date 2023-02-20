void Make_Aj_Truth(string infile = "jets0000small.root"){
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    //Load the tree into memory (TNtuple is a 1D tree)
    
    TNtuple* tree = (TNtuple*)gROOT->FindObject("ntp_truthjet");
    
// Make histograms needed
    
    
    TH1F* hAjTruth = new TH1F("hAjTruth","",50,0,1);
    TH1F* hAjReco = new TH1F("hAjReco","",50,0,1);
   
    //number of entries in tree
    int Nentries = tree->GetEntries();
    
    //connect variables in the code to variables in the tree

    float e,ge,phi,gphi,event;
    tree->SetBranchAddress("event",&event);
    tree->SetBranchAddress("e", &e);
    tree->SetBranchAddress("ge", &ge);
    tree->SetBranchAddress("phi",&phi);
    tree->SetBranchAddress("gphi",&gphi);

    float curevent;
    float e1 = 0; float e2 = 0;
    float re1 = 0; float re2=0;
    float phi1 = 0; float phi2 = 0;
    float rphi1 = 0; float rphi2 = 0;
    float deltaphi = 0; float rdeltaphi=0;
    
    for (int i = 0;i<Nentries;i++){ 
        //loop over entries
        tree->GetEntry(i);
        if (i == 0)
            curevent = event;

        if (event == curevent)//still in same event
        {
            if ((ge > e1) && ge > 10 && e > 0.80*ge){
                e2 = e1;
                phi2 = phi1;
                e1 = ge;
                phi1 = gphi;

                re2 = re1;
                rphi2 = rphi1;
                re1 = e;
                rphi1 = phi;

                deltaphi = phi1 - phi2;
                rdeltaphi = rphi1 - rphi2;
            }
            else if((ge > e2) && ge > 2.5 && e > 0.80*ge)
            {
                e2 = ge;
                re2 = e;

                deltaphi = abs(phi1 - phi2);
                rdeltaphi = abs(rphi1 - rphi2);
            }
        }
        
        if (event != curevent){//first entry of next event
            if(deltaphi > 1.57)
            {
                hAjTruth->Fill((e1 - e2)/(e1 + e2));

            }
            
            if(rdeltaphi > 1.57)
            {
                hAjReco->Fill((re1 - re2)/(re1 + re2));
                
            }

            e1 = ge; re1 = e;
            e2 = 0; re2 = 0;
            phi1 = gphi; rphi1 = phi;
            phi2 = 0; rphi2 = 0;
            curevent = event;
        }

        if (e1 < 10 or e2 < 2.5 ){
           continue; // we need not count
        }
        
        
    } //end loop ntuple
    
    //Then we would want to save these histograms to a file so that we can Draw them in a macro
    TString outfilename = infile;
    outfilename.Prepend("momentum_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    hAjTruth->Write();
    hAjReco->Write();
  
    
}

