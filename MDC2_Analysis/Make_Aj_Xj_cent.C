void Make_Aj_Xj_cent(string infile = "MDC2wCentJetsUEsub.root"){
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
   
//Load the tree into memory
    TTree* tree = (TTree*)_file0->Get("tree");

        
    
// Make histograms needed
    
    
    TH1F* hAjTruth_0_20 = new TH1F("hAjTruth_0_20","",70,-0.35,1);
    TH1F* hAjTruth_20_50 = new TH1F("hAjTruth_20_50","",70,-0.35,1);
    TH1F* hAjTruth_50_100 = new TH1F("hAjTruth_50_100","",70,-0.35,1);
    TH1F* hAjReco_0_20 = new TH1F("hAjReco_0_20","",70,-0.35,1);
    TH1F* hAjReco_20_50 = new TH1F("hAjReco_20_50","",70,-0.35,1);
    TH1F* hAjReco_50_100 = new TH1F("hAjReco_50_100","",70,-0.35,1);

    TH1F* hXjTruth_0_20 = new TH1F("hXjTruth_0_20","",70,0,1.5);
    TH1F* hXjTruth_20_50 = new TH1F("hXjTruth_20_50","",70,0,1.5);
    TH1F* hXjTruth_50_100 = new TH1F("hXjTruth_50_100","",70,0,1.5);
    TH1F* hXjReco_0_20 = new TH1F("hXjReco_0_20","",70,0,1.5);
    TH1F* hXjReco_20_50 = new TH1F("hXjReco_20_50","",70,0,1.5);
    TH1F* hXjReco_50_100 = new TH1F("hXjReco_50_100","",70,0,1.5);
    
    TH1F* hAjTruth = new TH1F("hAjTruth","",70,-0.35,1);
    TH1F* hAjReco = new TH1F("hAjReco","",70,-0.35,1);
    TH1F* hXjTruth = new TH1F("hXjTruth","",70,0,1.5);
    TH1F* hXjReco = new TH1F("hXjReco","",70,0,1.5);
    
    TH2F* AjTruthvsReco = new TH2F("AjTruthvsReco", "", 35, 0, 0.8, 40, -0.5, 0.8);
    TH2F* XjTruthvsReco = new TH2F("XjTruthvsReco", "", 35, 0, 1, 40, 0, 1.5);
    
  //create vectors and load in branches
//connect variables in the code to variables in the tree

  std::vector<double> *tjet_pt ={0};
  std::vector<double> *tjet_phi ={0};
  std::vector<double> *tjet_eta ={0};
  std::vector<double> *rjet_pt ={0};
  std::vector<double> *rjet_phi ={0};
  std::vector<double> *rjet_eta ={0};
  int tjet_cent=0; 
  int rjet_cent=0;  

  tree->SetBranchAddress("tjet_pt",&tjet_pt);
  tree->SetBranchAddress("tjet_phi",&tjet_phi);
  tree->SetBranchAddress("tjet_eta",&tjet_eta);

  tree->SetBranchAddress("rjet_pt",&rjet_pt);
  tree->SetBranchAddress("rjet_phi",&rjet_phi);
  tree->SetBranchAddress("rjet_eta",&rjet_eta);

  tree->SetBranchAddress("tjet_cent",&tjet_cent);
  tree->SetBranchAddress("rjet_cent",&rjet_cent);
     

   //create other necessary variables 
    float curevent;
    float phi1 = 0; float phi2 = 0;
    float rphi1 = 0; float rphi2 = 0;
    float deltaphi = 0; float rdeltaphi=0;
    float leading  = 0; float subleading = 0;
    float rleading = 0; float rsubleading =0;
    float Ajtruth = 0; float Ajreco = 0;
    float Xjtruth = 0; float Xjreco = 0;
    float  count = 0; float negative = 0;
    int icount = 0; int jcount = 0; int lcount = 0;
    int  scount = 0; int fcount = 0;

    int  lowpt = 0;  float Percent = 0;
    float  central = 0; float  mid = 0;float  peripheral = 0;
    float  rcentral = 0; float rmid = 0; float rperipheral = 0; 
  //number of entries in tree
    int Nentries = tree->GetEntries();
    
    for (int i = 0;i<Nentries;i++){
        //loop over entries
        tree->GetEntry(i);
        icount = icount + 1;
        leading = 0; rleading = 0;
         phi1 = 0; rphi1 = 0;
         subleading = 0; rsubleading = 0;
         phi2 = 0; rphi2 = 0; 



         int ntjets = tjet_pt->size();
         for (int j = 0; j < ntjets;j++){
              jcount = jcount + 1;
	           
              float tjetpt = tjet_pt->at(j);
	      float tjetphi = tjet_phi->at(j);
	      float tjeteta = tjet_eta->at(j);
             
	      float rjetpt = rjet_pt->at(j);
	      float rjetphi = rjet_phi->at(j);
	      float rjeteta = rjet_eta->at(j);
	    
              float tjetcent = tjet_cent;
              float rjetcent = rjet_cent;
 
	      if (tjetpt < 5){
	        lowpt = lowpt + 1; 
		continue;
	      }

	      else  if (tjetpt  > leading){
                subleading = leading;
                leading = tjetpt;
                rsubleading = rleading;
                rleading = rjetpt;

                phi2 = phi1;
                phi1 = tjetphi;

                rphi2 = rphi1;
                rphi1 = rjetphi;
                
                lcount = lcount + 1;            
                
             }
            else if (tjetpt  > subleading){
                subleading = tjetpt;
                rsubleading = rjetpt;

                phi2 = tjetphi;
                rphi2 = rjetphi;
                
                scount = scount + 1;

            }
        
        
	    if (j == ntjets - 1){//last entry of current vector            
            deltaphi = abs(phi1 - phi2);
            rdeltaphi = abs(rphi1 - rphi2);
            Ajtruth = (leading - subleading)/(leading + subleading);
            Ajreco = (rleading - rsubleading)/(rleading + rsubleading);

            Xjtruth = subleading/leading;
            Xjreco = rsubleading/rleading;
             
            fcount = fcount + 1;

            if (leading > 10 && subleading > 5 && deltaphi > 1.57 && rleading > 10 && rsubleading > 5 && rdeltaphi > 1.57){ //fillhistograms

                hAjTruth->Fill(Ajtruth);
                hAjReco->Fill(Ajreco);
                AjTruthvsReco->Fill(Ajtruth,Ajreco);
               
                hXjTruth->Fill(Xjtruth);
                hXjReco->Fill(Xjreco);
                XjTruthvsReco->Fill(Xjtruth,Xjreco);
               
              
                count = count + 1;
                  
                if (tjetcent > 0 && tjetcent <= 20){
		  hAjTruth_0_20->Fill(Ajtruth);
       		  hXjTruth_0_20->Fill(Xjtruth);  
                  central = central + 1;
		}
                 if (rjetcent > 0 && rjetcent <= 20){
		  hAjReco_0_20->Fill(Ajreco);
		  hXjReco_0_20->Fill(Xjreco);  
                  rcentral = rcentral + 1;
		}
              
             

		 if (tjetcent > 20 && tjetcent <= 50){
		  hAjTruth_20_50->Fill(Ajtruth);
		  hXjTruth_20_50->Fill(Xjtruth);  
                  mid = mid + 1;
		 }
                 if (rjetcent > 20 && rjetcent <= 50){
		  hAjReco_20_50->Fill(Ajreco);
		  hXjReco_20_50->Fill(Xjreco);  
		  rmid = rmid + 1;
		 }

                if (tjetcent > 50 && tjetcent <= 100){
		  hAjTruth_50_100->Fill(Ajtruth);
		  hXjTruth_50_100->Fill(Xjtruth);  
                  peripheral = peripheral + 1;
		 }
                 if (rjetcent > 50 && rjetcent <= 100){
		  hAjReco_50_100->Fill(Ajreco);
		  hXjReco_50_100->Fill(Xjreco);  
                  rperipheral = rperipheral + 1;
		 }            
                 if(Ajreco < 0){
                  negative = negative + 1;
	         }
           
           


           }//end fillinging histograms reset values

	
	    
           
	}//resetting values for next vector loop
       
      }// end vector loop


        
    }//end loop over entries
     

    hAjTruth->Scale(1/count);
    hAjReco->Scale(1/count);
    hXjTruth->Scale(1/count);
    hXjReco->Scale(1/count);
    
    hAjTruth_0_20->Scale(1/central);
    hAjTruth_20_50->Scale(1/mid);
    hAjTruth_50_100->Scale(1/peripheral);

    hAjReco_0_20->Scale(1/rcentral);
    hAjReco_20_50->Scale(1/rmid);
    hAjReco_50_100->Scale(1/rperipheral);

    hXjTruth_0_20->Scale(1/central);
    hXjTruth_20_50->Scale(1/mid);
    hXjTruth_50_100->Scale(1/peripheral);

    hXjReco_0_20->Scale(1/rcentral);
    hXjReco_20_50->Scale(1/rmid);
    hXjReco_50_100->Scale(1/rperipheral);
    
    Percent = negative/count;
    cout << "negative = " << negative << "  " ;
    cout << "count = "<< count << "  ";  
    cout << "Percent = " << Percent*100 << "  " ;
    cout << "icount = " << icount << " ";
    cout << "jcount =" << jcount << " ";
    cout << "lcount = " << lcount << " ";
    cout << "scount = " << scount << " ";
    cout << "fcount = " << fcount << " " << endl;


    cout << "The number of jets cut below 5 pt was: " << lowpt << endl;
    cout << "The number of very central truth collisions is : " << central << endl;
    cout << "The number of very central reconstructed collisions is : " << rcentral << endl;
    cout << "The number of mid centrality truth collisions is : " << mid << endl;
    cout << "The number of mid centrality  reconstructed collisions is : " << rmid << endl;
    cout << "The number of peripheral truth collisions is : " << peripheral << endl;
    cout << "The number of peripheral reconstructed collisions is : " << rperipheral << endl;
    cout << "The total number of truth collisions recorded is: " << central + mid + peripheral << endl;
    cout << "The total number of reconstructed collisions recorded is: " << rcentral + rmid + rperipheral << endl;
       
   
 //Then we would want to save these histograms to a file so that we can Draw them in a macro
    TString outfilename = infile;
    outfilename.Prepend("Aj_Xj_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
    
    hAjTruth->Write();
    hAjReco->Write();
    AjTruthvsReco->Write();
    XjTruthvsReco->Write();
    hXjTruth->Write();
    hXjReco->Write();

      hAjTruth_0_20->Write();
      hAjTruth_20_50->Write();
      hAjTruth_50_100->Write();
      hAjReco_0_20->Write();
      hAjReco_20_50->Write();
      hAjReco_50_100->Write();

      hXjTruth_0_20->Write();
      hXjTruth_20_50->Write();
      hXjTruth_50_100->Write();
      hXjReco_0_20->Write(); 
      hXjReco_20_50->Write();  
      hXjReco_50_100->Write(); 


    
}
