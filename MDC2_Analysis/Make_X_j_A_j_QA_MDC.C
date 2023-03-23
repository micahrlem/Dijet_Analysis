void Make_X_j_A_j_QA_MDC(string infile = "MDC2wCentJets.root"){

#define _USE_MATH_DEFINES

#include <math.h> 
#include <cmath>
#include <iostream>

#include<vector>
#include<array>
    
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
TFile* _file0 = TFile::Open(infile.c_str());
TTree* tree = (TTree*)gROOT->FindObject("tree");
    
// Make histograms needed
    //Jet Spectra Histograms
    TH1F* hJetTruthPt = new TH1F("hJetTruthPt","",20,0,80);
    TH1F* hJetRecoPt = new TH1F("hJetRecoPt","",20,0,80);

   // Aj and Xj Histograms 
    TH1F* hAjTruth = new TH1F("hAjTruth","",25,-0.35,1);
    TH1F* hAjReco = new TH1F("hAjReco","",25,-0.35,1);
    TH1F* hAjTruthLow = new TH1F("hAjTruthLow","",25,-0.35,0.8);
    TH1F* hAjRecoLow = new TH1F("hAjRecoLow","",25,-0.35,0.8);
    TH1F* hAjTruthMid = new TH1F("hAjTruthMid","",25,-0.35,0.8);
    TH1F* hAjRecoMid = new TH1F("hAjRecoMid","",25,-0.35,0.8);
    TH1F* hAjTruthHigh = new TH1F("hAjTruthHigh","",25,-0.35,0.8);
    TH1F* hAjRecoHigh = new TH1F("hAjRecoHigh","",25,-0.35,0.8);
    TH1F* hXjTruth = new TH1F("hXjTruth","",25,0,1.5);
    TH1F* hXjReco = new TH1F("hXjReco","",25,0,1.5);
    TH1F* hXjTruthLow = new TH1F("hXjTruthLow","",25,0,1.5);
    TH1F* hXjRecoLow = new TH1F("hXjRecoLow","",25,0,1.5);
    TH1F* hXjTruthMid = new TH1F("hXjTruthMid","",25,0,1.5);
    TH1F* hXjRecoMid = new TH1F("hXjRecoMid","",25,0,1.5);
    TH1F* hXjTruthHigh = new TH1F("hXjTruthHigh","",25,.0,1.5);
    TH1F* hXjRecoHigh = new TH1F("hXjRecoHigh","",25,0,1.5);
    TH2F* AjTruthvsReco = new TH2F("AjTruthvsReco", "", 20, 0, 0.8, 32, -0.5, 0.8);

// Aj and Xj with Centrality
    TH1F* hAjTruthLowCent = new TH1F("hAjTruthLowCent","",25,-0.35,0.8);
    TH1F* hAjRecoLowCent = new TH1F("hAjRecoLowCent","",25,-0.35,0.8);
    TH1F* hAjTruthMidCent = new TH1F("hAjTruthMidCent","",25,-0.35,0.8);
    TH1F* hAjRecoMidCent = new TH1F("hAjRecoMidCent","",25,-0.35,0.8);
    TH1F* hAjTruthHighCent = new TH1F("hAjTruthHighCent","",25,-0.35,0.8);
    TH1F* hAjRecoHighCent = new TH1F("hAjRecoHighCent","",25,-0.35,0.8);
    TH1F* hXjTruthLowCent = new TH1F("hXjTruthLowCent","",25,0,1.5);
    TH1F* hXjRecoLowCent = new TH1F("hXjRecoLowCent","",25,0,1.5);
    TH1F* hXjTruthMidCent = new TH1F("hXjTruthMidCent","",25,0,1.5);
    TH1F* hXjRecoMidCent = new TH1F("hXjRecoMidCent","",25,0,1.5);
    TH1F* hXjTruthHighCent = new TH1F("hXjTruthHighCent","",25,0,1.5);
    TH1F* hXjRecoHighCent = new TH1F("hXjRecoHighCent","",25,0,1.5);

//Aj and Xj Truth vs Reco vs Centrality
    TH1F* hAjTruthMinusRecoCent = new TH1F("hAjTruthMinusRecoCent","", 26, -0.7, 0.6);
    TH1F* hAjTruthMinusRecoLowCent = new TH1F("hAjTruthMinusRecoLowCent","", 26, -0.7, 0.6);
    TH1F* hAjTruthMinusRecoMidCent = new TH1F("hAjTruthMinusRecoMidCent","", 26, -0.7, 0.6);
    TH1F* hAjTruthMinusRecoHighCent = new TH1F("hAjTruthMinusRecoHighCent","", 26, -0.7, 0.6);
    
    TH1F* hXjTruthMinusRecoCent = new TH1F("hXjTruthMinusRecoCent","", 26, -0.7, 0.6);
    TH1F* hXjTruthMinusRecoLowCent = new TH1F("hXjTruthMinusRecoLowCent","", 26, -0.7, 0.6);
    TH1F* hXjTruthMinusRecoMidCent = new TH1F("hXjTruthMinusRecoMidCent","", 26, -0.7, 0.6);
    TH1F* hXjTruthMinusRecoHighCent = new TH1F("hXjTruthMinusRecoHighCent","", 26, -0.7, 0.6);

//QA Histograms No Cuts
    TH2F* TruthvsRecoEtaNoCut = new TH2F("TruthvsRecoEtaNoCut","",50,-1,1,50,-1,1);
    TH2F* TruthvsRecoPhiNoCut = new TH2F("TruthvsRecoPhiNoCut","",50,-TMath::Pi(),TMath::Pi(),50,-TMath::Pi(),TMath::Pi());
    TH2F* TruthvsRecoPtNoCut = new TH2F("TruthvsRecoPtNoCut","",70,0,70,70,0,70);
    TH1F* hTruthPhiNoCut = new TH1F("hTruthPhiNoCut","",50,-TMath::Pi(),TMath::Pi());
    TH1F* hRecoPhiNoCut = new TH1F("hRecoPhiNoCut","",50,-TMath::Pi(),TMath::Pi());
    TH1F* hTruthEtaNoCut = new TH1F("hTruthEtaNoCut","",25,-1,1);
    TH1F* hRecoEtaNoCut = new TH1F("hRecoEtaNoCut","",25,-1,1);
    TH2F* ScaleResEtaNoCut = new TH2F("ScaleResEtaNoCut","",50,-1,1,50,-.15,.15);
    TH2F* ScaleResPhiNoCut = new TH2F("ScaleResPhiNoCut","",50,-TMath::Pi(),TMath::Pi(),50,-.15,.15);
    TH2F* ScaleResPtNoCut = new TH2F("ScaleResPtNoCut","",25,10,60,50,-1.1,0.8);
    TH1F* hTruthSpectraNoCut = new TH1F("hTruthSpectraNoCut","",60,0,80);
    TH1F* hRecoSpectraNoCut = new TH1F("hRecoSpectraNoCut","",60,0,80);

//QA Histograms with cuts
    TH2F* TruthvsRecoEta = new TH2F("TruthvsRecoEta","",25,-1,1,25,-1,1);
    TH2F* TruthvsRecoPhi = new TH2F("TruthvsRecoPhi","",25,-TMath::Pi(),TMath::Pi(),25,-TMath::Pi(),TMath::Pi());
    TH2F* TruthvsRecoPt = new TH2F("TruthvsRecoPt","",35,0,70,35,0,70);
    TH1F* hTruthPhi = new TH1F("hTruthPhi","",25,-TMath::Pi(),TMath::Pi());
    TH1F* hRecoPhi = new TH1F("hRecoPhi","",25,-TMath::Pi(),TMath::Pi());
    TH1F* hTruthEta = new TH1F("hTruthEta","",25,-1,1);
    TH1F* hRecoEta = new TH1F("hRecoEta","",25,-1,1);
    TH2F* ScaleResEta = new TH2F("ScaleResEta","",25,-1,1,25,-.15,.15);
    TH2F* ScaleResPhi = new TH2F("ScaleResPhi","",25,-TMath::Pi(),TMath::Pi(),25,-.15,.15);
    TH2F* ScaleResPt = new TH2F("ScaleResPt","",25,10,60,50,-1.1,0.8);
    TH1F* hTruthSpectra = new TH1F("hTruthSpectra","",20,0,80);
    TH1F* hRecoSpectra = new TH1F("hRecoSpectra","",20,0,80);
   
    //number of entries in tree
    int Nentries = tree->GetEntries();
    
    //connect variables in the code to variables in the tree

   std::vector<double> *tjet_pt ={0};
   std::vector<double> *tjet_phi ={0};
   std::vector<double> *tjet_eta ={0};
   std::vector<double> *rjet_pt ={0};
   std::vector<double> *rjet_phi ={0};
   std::vector<double> *rjet_eta ={0};
   int tjet_cent;
   int rjet_cent;

   tree->SetBranchAddress("tjet_pt",&tjet_pt);
   tree->SetBranchAddress("tjet_phi",&tjet_phi);
   tree->SetBranchAddress("tjet_eta",&tjet_eta);
   tree->SetBranchAddress("tjet_cent",&tjet_cent);

   tree->SetBranchAddress("rjet_pt",&rjet_pt);
   tree->SetBranchAddress("rjet_phi",&rjet_phi);
   tree->SetBranchAddress("rjet_eta",&rjet_eta);
   tree->SetBranchAddress("rjet_cent",&rjet_cent);

    
    // initialize variables used
    float Ajtruth = 0;
    float Xjtruth = 0;
    float Xjreco = 0;
    float AJreco = 0;
    float count = 0;
    float ecount = 0;
    float lcount = 0;
    float fcount = 0;
    float jcount = 0;
    float icount = 0;
    float lowt   = 0;
    float lowr   = 0;
    float midt   = 0;
    float midr   = 0;
    float hight = 0;
    float highr = 0;
    float totalt = 0;
    float totalr = 0;
    float negative = 0;
    float leading = 0;
    float subleading = 0;
    float rleading = 0;
    float rsubleading = 0;
    float deltaphi = 0;
    float rdeltaphi = 0;
    float philead = 0; 
    float phisublead = 0;
    float rphilead = 0;
    float rphisublead = 0;
    float curevent;
    float event;

    float AjScale = 0;
    float XjScale = 0;

    float tout = 0;
    float tmiddle = 0; 
    float tcentral = 0;
    float rout = 0;
    float rmiddle = 0; 
    float rcentral = 0;

    float diffeta = 0;
    float diffphi = 0;
    float diffpt = 0;
    
    
    for (int i = 0;i<Nentries;i++){
        //loop over entries
        tree->GetEntry(i);
        if (i == 0)
            curevent = event;
            

        if (event == curevent){//still in same event
             
            ecount = ecount + 1;
            int ntjets = tjet_pt->size();
            for (int j = 0; j < ntjets;j++){
            
            float tjetpt = tjet_pt->at(j);
            float tjetphi = tjet_phi->at(j);
            float tjeteta = tjet_eta->at(j);
            float tcent = tjet_cent;

            float rjetpt = rjet_pt->at(j);
            float rjetphi = rjet_phi->at(j);
            float rjeteta = rjet_eta->at(j);
            float rcent = rjet_cent;
            jcount = jcount + 1;
            
            if (tjetpt < 1)
            continue;

            if (tjetpt > leading){
                subleading = leading;
                leading = tjetpt;
                rsubleading = rleading;
                rleading = rjetpt;

                phisublead = philead;
                philead = tjetphi;

                rphisublead = rphilead;
                rphilead = rjetphi;
            }
            else if (tjetpt > subleading){
                subleading = tjetpt;
                rsubleading = rjetpt;

                phisublead = tjetphi;
                rphisublead = rjetphi;


            }     
            if (j == ntjets - 1){//last entry of event
            
            icount = icount + 1;
            Ajtruth = (leading - subleading)/(leading + subleading);
            AJreco = (rleading - rsubleading)/(rleading + rsubleading); 
            Xjtruth = subleading/leading;
            Xjreco = rsubleading/rleading;
            if (philead <= 0 ){

            deltaphi = abs(philead - phisublead + TMath::Pi());
            }
            if (rphilead <= 0){
            rdeltaphi = abs(rphilead - rphisublead + TMath::Pi());    
            }

            if (philead > 0){
             deltaphi = abs(philead - phisublead - TMath::Pi());
            }
            if (rphilead > 0){
            rdeltaphi = abs(rphilead - rphisublead - TMath::Pi());    
            }
            


            //fill QA Histograms
            diffeta = rjeteta - tjeteta ;
            diffphi = rjetphi - tjetphi;
            diffpt = (rleading - leading)/leading ;

            TruthvsRecoEtaNoCut->Fill(tjeteta,rjeteta);
            TruthvsRecoPhiNoCut->Fill(tjetphi,rjetphi);
            TruthvsRecoPtNoCut->Fill(leading,rleading);
            ScaleResEtaNoCut->Fill(tjeteta,diffeta);
            ScaleResPhiNoCut->Fill(tjetphi,diffphi);
            ScaleResPtNoCut->Fill(leading,diffpt);
            hTruthPhiNoCut->Fill(tjetphi);
            hRecoPhiNoCut->Fill(rjetphi);
            hTruthEtaNoCut->Fill(tjeteta);
            hRecoEtaNoCut->Fill(rjeteta);
            hTruthSpectraNoCut->Fill(leading);
            hRecoSpectraNoCut->Fill(rleading);
            fcount = fcount + 1;  

            //Fill Jet Spectra histograms
            hJetTruthPt->Fill(leading);
            hJetRecoPt->Fill(rleading);

            
            if (leading > 30 && subleading > 10 && 0.4 > deltaphi  && rleading > 30 && rsubleading > 10 && 0.4 > rdeltaphi &&  0.7 > tjeteta && tjeteta > -0.7 && 0.7 > rjeteta && rjeteta > -0.7  ){

                //define AjScale and XjScale
                AjScale = (Ajtruth - AJreco);
                XjScale = (Xjtruth - Xjreco);
                
                
                
                //Fill Xj Aj Histograms
                hAjTruthMinusRecoCent->Fill(AjScale);
                hXjTruthMinusRecoCent->Fill(XjScale);


                hAjTruth->Fill(Ajtruth);
                hXjTruth->Fill(Xjtruth);
                hAjReco->Fill(AJreco);
                hXjReco->Fill(Xjreco);
                AjTruthvsReco->Fill(Ajtruth,AJreco);
                count = count + 1;
               //Fill Cut QA histograms

                diffeta = rjeteta - tjeteta ;
                diffphi = rjetphi - tjetphi;
                diffpt = (rleading - leading)/leading ;

                TruthvsRecoEta->Fill(tjeteta,rjeteta);
                TruthvsRecoPhi->Fill(tjetphi,rjetphi);
                TruthvsRecoPt->Fill(leading,rleading);
                ScaleResEta->Fill(tjeteta,diffeta);
                ScaleResPhi->Fill(tjetphi,diffphi);
                ScaleResPt->Fill(leading,diffpt);
                hTruthPhi->Fill(tjetphi);
                hRecoPhi->Fill(rjetphi);
                hTruthEta->Fill(tjeteta);
                hRecoEta->Fill(rjeteta);
                hTruthSpectra->Fill(leading);
                hRecoSpectra->Fill(rleading); 
               
            if  (100 > tcent && tcent > 50){
                hAjTruthLowCent->Fill(Ajtruth);
                hXjTruthLowCent->Fill(Xjtruth);
                
                hAjTruthMinusRecoLowCent->Fill(AjScale);
                hXjTruthMinusRecoLowCent->Fill(XjScale);
                tout = tout + 1;
                } 
            if  (50 > tcent && tcent > 20){
                hAjTruthMidCent->Fill(Ajtruth);
                hXjTruthMidCent->Fill(Xjtruth);

                hAjTruthMinusRecoMidCent->Fill(AjScale);
                hXjTruthMinusRecoMidCent->Fill(XjScale);
                tmiddle = tmiddle + 1;
                } 
            if  (20 > tcent && tcent > 0){
                tcentral = tcentral + 1;
                hAjTruthHighCent->Fill(Ajtruth);
                hXjTruthHighCent->Fill(Xjtruth);

                hAjTruthMinusRecoHighCent->Fill(AjScale);
                hXjTruthMinusRecoHighCent->Fill(XjScale);
                } 


            if  (100 > rcent && rcent > 50){
               
                hAjRecoLowCent->Fill(AJreco);
                hXjRecoLowCent->Fill(Xjreco);
                rout = rout + 1;
                } 
            if  (50 > rcent && rcent > 20){
                
                hAjRecoMidCent->Fill(AJreco);
                hXjRecoMidCent->Fill(Xjreco);
                rmiddle = rmiddle + 1;
                } 
            if  (20 > rcent && rcent > 0){
                
                hAjRecoHighCent->Fill(AJreco);
                hXjRecoHighCent->Fill(Xjreco);
                rcentral = rcentral + 1;
                } 
              
               
               
                if(AJreco < 0){
                    negative = negative + 1;
                }
            if (leading > 30 && leading < 32.5){
                lowt = lowt + 1;
                hAjTruthLow->Fill(Ajtruth);
                hXjTruthLow->Fill(Xjtruth);
            }
            if (leading > 32.5 && leading < 37.5){
                midt = midt + 1;
                hAjTruthMid->Fill(Ajtruth);
                hXjTruthMid->Fill(Xjtruth);
            }
             if (leading > 37.5){
                hight = hight + 1;
                hAjTruthHigh->Fill(Ajtruth);
                hXjTruthHigh->Fill(Xjtruth);
            }
            if (rleading > 30 && rleading < 32.5){
                lowr = lowr + 1;
                hAjRecoLow->Fill(AJreco);
                hXjRecoLow->Fill(Xjreco);
            }
            if (rleading > 32.5 && rleading < 37.5){
                midr = midr + 1;
                hAjRecoMid->Fill(AJreco);
                hXjRecoMid->Fill(Xjreco);
            }
             if (rleading > 37.5){
                highr = highr + 1;
                hAjRecoHigh->Fill(AJreco);
                hXjRecoHigh->Fill(Xjreco);
            }

            }

         
        leading = 0; rleading = 0;
        philead = 0; rphilead = 0;
        subleading = 0; rsubleading = 0;
        phisublead = 0; rphisublead = 0;
        curevent = event;
        lcount = lcount + 1;
        }
            
            
            
            }
    

         } 
         
         
    }

    totalt = lowt + midt + hight;
    totalr = lowr + midr + highr;
    //Scale Aj and Xj
    hAjTruth->Scale(1/count);
    hAjReco->Scale(1/count);
    hXjTruth->Scale(1/count);
    hXjReco->Scale(1/count);
    hAjTruthLow->Scale(1/lowt);
    hAjRecoLow->Scale(1/lowr);
    hXjTruthLow->Scale(1/lowt);
    hXjRecoLow->Scale(1/lowr);
    hAjTruthMid->Scale(1/midt);
    hAjRecoMid->Scale(1/midr);
    hXjTruthMid->Scale(1/midt);
    hXjRecoMid->Scale(1/midr);
    hAjTruthHigh->Scale(1/hight);
    hAjRecoHigh->Scale(1/highr);
    hXjTruthHigh->Scale(1/hight);
    hXjRecoHigh->Scale(1/highr);

    hAjTruthMinusRecoCent->Scale(1/count);
    hXjTruthMinusRecoCent->Scale(1/count);
    
    //Scale Aj and Xj with Centrality
    hAjTruthHighCent->Scale(1/tcentral);
    hAjTruthMidCent->Scale(1/tmiddle);
    hAjTruthLowCent->Scale(1/tout);
    hXjTruthHighCent->Scale(1/tcentral);
    hXjTruthMidCent->Scale(1/tmiddle);
    hXjTruthLowCent->Scale(1/tout);

    hAjRecoHighCent->Scale(1/rcentral);
    hAjRecoMidCent->Scale(1/rmiddle);
    hAjRecoLowCent->Scale(1/rout);
    hXjRecoHighCent->Scale(1/rcentral);
    hXjRecoMidCent->Scale(1/rmiddle);
    hXjRecoLowCent->Scale(1/rout);

    //Scale Scale Plots
    hAjTruthMinusRecoHighCent->Scale(1/tcentral);
    hAjTruthMinusRecoMidCent->Scale(1/tmiddle);
    hAjTruthMinusRecoLowCent->Scale(1/tout);
    hXjTruthMinusRecoHighCent->Scale(1/tcentral);
    hXjTruthMinusRecoMidCent->Scale(1/tmiddle);
    hXjTruthMinusRecoLowCent->Scale(1/tout);



    cout << "Percent = " << (negative/count)*100 << "  " ;
    cout << "negative = " << negative << "  " ;
    cout << "count =  "<< count << "  "; 
    cout << "ecount =  "<< ecount << "  ";
    cout << "lcount =  "<< lcount << "  "; 
    cout << "fcount =  "<< fcount << "  ";
    cout << "jcount =  "<< jcount << "  ";
    cout << "icount =  "<< icount << "  ";
    cout << "Low Truth = " << lowt << "  ";
    cout << "Mid Truth = " << midt << "  ";
    cout << "High Truth = " << hight << "  ";
    cout << "Total Truth = " << totalt << " ";
    cout << "Low Reco = " << lowr << "  ";
    cout << "Mid Reco = " << midr << "  ";
    cout << "High Reco = " << highr << "  ";
    cout << "Total Reco = " << totalr << " ";
    cout << "Truth Peripheral Jets = " << tout << " ";
    cout << "Truth Mid Centrality Jets = " << tmiddle << " ";
    cout << "Truth Central Jets = " << tcentral << " ";
    cout << "Reco Peripheral Jets = " << rout << " ";
    cout << "Reco Mid Centrality Jets = " << rmiddle << " ";
    cout << "Reco Central Jets = " << rcentral << " ";
    //Then we would want to save these histograms to a file so that we can Draw them in a macro
    TString outfilename = infile;
    outfilename.Prepend("Aj_");
    
    TFile *outfile = TFile::Open(outfilename,"RECREATE");
   //Write Jet Hists
    hJetTruthPt->Write();
    hJetRecoPt->Write();
   //Write Aj and Xj Pt Pins
    hAjTruth->Write();
    hAjReco->Write();
    hXjTruth->Write();
    hXjReco->Write();
    hAjTruthLow->Write();
    hAjRecoLow->Write();
    hXjTruthLow->Write();
    hXjRecoLow->Write();
    hAjTruthMid->Write();
    hAjRecoMid->Write();
    hXjTruthMid->Write();
    hXjRecoMid->Write();
    hAjTruthHigh->Write();
    hAjRecoHigh->Write();
    hXjTruthHigh->Write();
    hXjRecoHigh->Write();
    AjTruthvsReco->Write();

    hAjTruthMinusRecoCent->Write();
    hXjTruthMinusRecoCent->Write();

    TruthvsRecoEta->Write();
    TruthvsRecoPhi->Write();
    TruthvsRecoPt->Write();
    ScaleResEta->Write();
    ScaleResPhi->Write();
    ScaleResPt->Write();
    hTruthPhi->Write();
    hRecoPhi->Write();
    hTruthEta->Write();
    hRecoEta->Write();
    hTruthSpectra->Write();
    hRecoSpectra->Write();


    TruthvsRecoEtaNoCut->Write();
    TruthvsRecoPhiNoCut->Write();
    TruthvsRecoPtNoCut->Write();
    ScaleResEtaNoCut->Write();
    ScaleResPhiNoCut->Write();
    ScaleResPtNoCut->Write();
    hTruthPhiNoCut->Write();
    hRecoPhiNoCut->Write();
    hTruthEtaNoCut->Write();
    hRecoEtaNoCut->Write();
    hTruthSpectraNoCut->Write();
    hRecoSpectraNoCut->Write();
    

    hAjTruthHighCent->Write();
    hAjTruthMidCent->Write();
    hAjTruthLowCent->Write();
    hXjTruthHighCent->Write();
    hXjTruthMidCent->Write();
    hXjTruthLowCent->Write();

    hAjRecoHighCent->Write();
    hAjRecoMidCent->Write();
    hAjRecoLowCent->Write();
    hXjRecoHighCent->Write();
    hXjRecoMidCent->Write();
    hXjRecoLowCent->Write();


    hAjTruthMinusRecoHighCent->Write();
    hAjTruthMinusRecoMidCent->Write();
    hAjTruthMinusRecoLowCent->Write();
    hXjTruthMinusRecoHighCent->Write();
    hXjTruthMinusRecoMidCent->Write();
    hXjTruthMinusRecoLowCent->Write();  
}