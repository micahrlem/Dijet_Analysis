void MakeEfficiency(string infile = "G4sPHENIX_g4jet_eval.root"){

	TFile *_file0 = TFile::Open(infile.c_str());
    
    //Load the tree into memory (TNtuple is a 1D tree)
    
    TNtuple* tree = (TNtuple*)gROOT->FindObject("ntp_truthjet");

    TH1F* MatchedJets = new TH1F("MatchedJets","",70,0,70);
    TH1F* AllJets = new TH1F("AllJets","",70,0,70);
    TH1F* Efficiency = new TH1F("Efficiency","",70, 0,70);

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
    tree->SetBranchAddress("gpt",&gpt);

    float curevent;
    float eta1 = 0;
    float reta1 = 0; 
    float phi1 = 0; 
    float rphi1 = 0; 
    float diffeta = 0;
    float diffphi = 0;
    int matched = 0;
    int total = 0;
   

    for (int i = 0;i<Nentries;i++){ 
        //loop over entries
        tree->GetEntry(i);
        if (i == 0)
            curevent = event;
        
        if (event != curevent){//first entry of next event
       
         //Filling Histograms
            //std::cout << "gpt:" << gpt << "\t" << "matched:" << matched << "\t" << "total:" << total << std::endl;

              
            curevent = event;
            matched = 0;
            total = 0;
        }

        if (event == curevent)//still in same event
        { 

        	total = total + 1;
        	AllJets->Fill(gpt);

        	if (!std::isnan(eta)) {


	           	eta1 = geta; reta1 = eta;
	            phi1 = gphi; rphi1 = phi;
	            // std::cout << "geta " << geta << "\t" << "eta " << eta << std::endl;
	            diffeta = reta1 - eta1;
	            diffphi = rphi1 - phi1;
            

	            if((TMath::Sqrt(diffeta*diffeta + diffphi*diffphi)) < 0.5 && gpt > 15 && eta < 0.4 && eta > -0.4)
	            {
	            	matched = matched + 1;
	            	MatchedJets->Fill(gpt);
	            	
	            }
	        }

            
   		}
        

       


    } //end loop ntuple

    Efficiency->Divide(MatchedJets,AllJets);

    TString outfilename = infile;
    outfilename.Prepend("efficiency_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    
    MatchedJets->Write();
    AllJets->Write();
    Efficiency->Write();

}

