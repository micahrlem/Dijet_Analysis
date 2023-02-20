void MakeJetHist_v3(string infile = "G4sPHENIX.root_g4jet_eval.root"){
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    //Load the tree into memory (TNtuple is a 1D tree)
    
    TNtuple* tree = (TNtuple*)gROOT->FindObject("ntp_truthjet");
    
    //Some plots can be made directly from the Draw command
    
    TH1F* hJetTruthPt = new TH1F("hJetTruthPt","",50,0,50);
    tree->Draw("gpt>>hJetTruthPt");
    
    TH1F* hJetRecoPt = new TH1F("hJetRecoPt","",50,0,50);
    tree->Draw("pt>>hJetRecoPt");
    
    //We can even made some cuts on other values in the tree
    
    TH1F* hJetTruthPt_gpt30 = new TH1F("hJetTruthPt_gpt30","",50,0,50);
    tree->Draw("gpt>>hJetTruthPt_gpt30","pt>30");
    
    TH1F* hRatio = new TH1F("hRatio","",100,0,2);
    TH1F* hRatioLvsSL = new TH1F("hRatioLvsSL","",100,0,2);
    TH1F* hRatioLvsSLReco = new TH1F("hRatioLvsSLReco","",100,0,2);

    TH1F* hLeadingJetPtNew = new TH1F("hLeadingJetPtNew","",50,0,50);
    TH1F* hSubLeadingJetPtNew = new TH1F("hSubLeadingJetPtNew","",50,0,50);
    TH1F* hLeadingJetPtNewReco = new TH1F("hLeadingJetPtNewReco","",50,0,50);
    TH1F* hSubLeadingJetPtNewReco = new TH1F("hSubLeadingJetPtNewReco","",50,0,50);
   
    //But mostly we will want to step through the tree to do a calculation
    
    
    //number of entries in tree
    int Nentries = tree->GetEntries();
    
    //connect variables in the code to variables in the tree

    float pt,gpt,event;
    tree->SetBranchAddress("event",&event);
    tree->SetBranchAddress("pt", &pt);
    tree->SetBranchAddress("gpt", &gpt);

    float curevent;
    float leading = 0; float subleading = 0;
    float rleading = 0; float rsubleading =0;
    
    for (int i = 0;i<Nentries;i++){
        //loop over entries
        tree->GetEntry(i);
        if (i == 0)
            curevent = event;

        if (event == curevent)//still in same event
        {
            if (gpt > leading){
                subleading = leading;
                leading = gpt;
                rsubleading = rleading;
                rleading = pt;
            }
            else if (gpt > subleading){
                subleading = gpt;
                rsubleading = pt;
            }
        }
        
        if (event != curevent){//first entry of next event
            hLeadingJetPtNew-> Fill(leading);
            hSubLeadingJetPtNew-> Fill(subleading);
            hLeadingJetPtNewReco->Fill(rleading);
            hSubLeadingJetPtNewReco->Fill(rsubleading);
            hRatioLvsSL->Fill(subleading/leading);
            hRatioLvsSLReco->Fill(rsubleading/rleading);
            leading = gpt; rleading = pt;
            subleading = 0; rsubleading = 0;
            curevent = event;
        }

        if (pt < 1)
            continue; // we do not care about low momentum truth jets so continue to next entry
        
        float ratio = pt/gpt;
        
        hRatio->Fill(ratio);
        
    } //end loop ntuple
    
    //Then we would want to save these histograms to a file so that we can Draw them in a macro
    TString outfilename = infile;
    outfilename.Prepend("newhist_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    hJetTruthPt->Write();
    hJetRecoPt->Write();
    hJetTruthPt_gpt30->Write();
    hRatio->Write();
    hLeadingJetPtNew->Write();
    hSubLeadingJetPtNew->Write();
    hLeadingJetPtNewReco->Write();
    hSubLeadingJetPtNewReco->Write();
    hRatioLvsSL->Write();
    hRatioLvsSLReco->Write();

    
}

