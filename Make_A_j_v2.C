void Make_A_j_v2(string infile = "jetsMedium0to55.root"){
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    //Load the tree into memory (TNtuple is a 1D tree)
    
    TNtuple* tree = (TNtuple*)gROOT->FindObject("ntp_truthjet");
    
// Make histograms needed
    
    
    TH1F* hAjTruth = new TH1F("hAjTruth","",70,-0.35,1);
    TH1F* hAjReco = new TH1F("hAjReco","",70,-0.35,1);
    TH2F* AjTruthvsReco = new TH2F("AjTruthvsReco", "", 35, 0, 0.8, 40, -0.5, 0.8);
   
    //number of entries in tree
    int Nentries = tree->GetEntries();
    
    //connect variables in the code to variables in the tree

    float pt,gpt,phi,gphi,event;
    tree->SetBranchAddress("event",&event);
    tree->SetBranchAddress("pt", &pt);
    tree->SetBranchAddress("gpt", &gpt);
    tree->SetBranchAddress("phi",&phi);
    tree->SetBranchAddress("gphi",&gphi);

    float curevent;
    float phi1 = 0; float phi2 = 0;
    float rphi1 = 0; float rphi2 = 0;
    float deltaphi = 0; float rdeltaphi=0;
    float leading = 0; float subleading = 0;
    float rleading = 0; float rsubleading =0;
    float Ajtruth = 0; float AJreco = 0;
    float count = 0; float negative = 0;
    
    for (int i = 0;i<Nentries;i++){
        //loop over entries
        tree->GetEntry(i);
        if (i == 0)
            curevent = event;

        if (event == curevent)//still in same event
        {
            if (pt < 1)
            continue; 

            if (gpt > leading){
                subleading = leading;
                leading = gpt;
                rsubleading = rleading;
                rleading = pt;

                phi2 = phi1;
                phi1 = gphi;

                rphi2 = rphi1;
                rphi1 = phi;
            }
            else if (gpt > subleading){
                subleading = gpt;
                rsubleading = pt;

                phi2 = gphi;
                rphi2 = phi;


            }
        }
        
        if (event != curevent){//first entry of next event
            
            deltaphi = abs(phi1 - phi2);
            rdeltaphi = abs(rphi1 - rphi2);
            Ajtruth = (leading - subleading)/(leading + subleading);
            AJreco = (rleading - rsubleading)/(rleading + rsubleading);

            /*if(leading > 15 && subleading > 5 && deltaphi > 1.57){
                 hAjTruth->Fill(Ajtruth);
            }

            if(rleading > 15 && rsubleading > 5 && rdeltaphi > 1.57){

                hAjReco->Fill(AJreco);

            }*/

            if (leading > 10 && subleading > 5 && deltaphi > 1.57 && rleading > 10 && rsubleading > 5 && rdeltaphi > 1.57){

                hAjTruth->Fill(Ajtruth);
                hAjReco->Fill(AJreco);
                AjTruthvsReco->Fill(Ajtruth,AJreco);
                count = count + 1;
                if(AJreco < 0){
                    negative = negative + 1;
                }
            }


            leading = 0; rleading = 0;
            phi1 = 0; rphi1 = 0;
            subleading = 0; rsubleading = 0;
            phi2 = 0; rphi2 = 0;
            curevent = event;
        }

        // we do not care about low momentum truth jets so continue to next entry
        
     
    } //end loop ntuple //end loop ntuple

    hAjTruth->Scale(1/count);
    hAjReco->Scale(1/count);
    cout << "Percent = " << (negative/count)*100 << "  " ;
    cout << "negative = " << negative << "  " ;
    cout << "count = "<< count << "  ";  
    //Then we would want to save these histograms to a file so that we can Draw them in a macro
    TString outfilename = infile;
    outfilename.Prepend("Aj_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    hAjTruth->Write();
    hAjReco->Write();
    AjTruthvsReco->Write();

    
}

