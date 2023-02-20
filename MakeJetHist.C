void MakeJetHist(string infile = "jets0000small.root"){
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    //Load the tree into memory (TNtuple is a 1D tree)
    
    TNtuple* tree = (TNtuple*)gROOT->FindObject("ntp_truthjet");
    
    //Some plots can be made directly from the Draw command
    
    TH1F* hJetTruthPt = new TH1F("hJetTruthPt","",50,0,50);
    tree->Draw("pt>>hJetTruthPt");
    
    TH1F* hJetRecoPt = new TH1F("hJetRecoPt","",50,0,50);
    tree->Draw("gpt>>hJetRecoPt");
    
    //We can even made some cuts on other values in the tree
    
    TH1F* hJetTruthPt_gpt30 = new TH1F("hJetTruthPt_gpt30","",50,0,50);
    tree->Draw("pt>>hJetTruthPt_gpt30","gpt>30");
    
    //But mostly we will want to step through the tree to do a calculation
    
    
    //number of entries in tree
    int Nentries = tree->GetEntries();
    
    //connect variables in the code to variables in the tree

    float pt,gpt;
    tree->SetBranchAddress("pt", &pt);
    tree->SetBranchAddress("gpt", &gpt);

    TH1F* hRatio = new TH1F("hRatio","",100,0,2);
    
    for (int i = 0;i<Nentries;i++){
        //loop over entries
        tree->GetEntry(i);
        
        if (pt < 1)
            continue; // we do not care about low momentum truth jets so continue to next entry
        
        float ratio = gpt/pt;
        
        hRatio->Fill(ratio);
        
    } //end loop ntuple
    
    //Then we would want to save these histograms to a file so that we can Draw them in a macro
    TString outfilename = infile;
    outfilename.Prepend("hist_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    hJetTruthPt->Write();
    hJetRecoPt->Write();
    hJetTruthPt_gpt30->Write();
    hRatio->Write();
    
    
}

