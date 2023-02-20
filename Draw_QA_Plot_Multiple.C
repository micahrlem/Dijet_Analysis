void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH2* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);



void Draw_QA_Plot_Multiple(string infile1 = "qa_R02_20Gev_output.root", string infile2 = "qa_R02_30Gev_output.root", string infile3 = "qa_R04_20Gev_output.root", string infile4 = "qa_R04_30Gev_output.root"){

gStyle->SetOptStat(0);
TFile *_file1 = TFile::Open(infile1.c_str());

	TH2*  ScaleResEta1 = (TH2*)gROOT->FindObject("ScaleResEta");
    TH2*  ScaleResPhi1 = (TH2*)gROOT->FindObject("ScaleResPhi");
    TH2*  ScaleResPt1 = (TH2*)gROOT->FindObject("ScaleResPt");
    TH2*  TruthvsRecoEta1 = (TH2*)gROOT->FindObject("TruthvsRecoEta");
    TH2*  TruthvsRecoPhi1 = (TH2*)gROOT->FindObject("TruthvsRecoPhi");
    TH2*  TruthvsRecoPt1 = (TH2*)gROOT->FindObject("TruthvsRecoPt");
    TCanvas* can1 = new TCanvas("can1","",1000,1000);
    can1->Divide(2,2,0,0);

    can1->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResEta1,"Truth Eta","(Reco Eta - Truth Eta)/Truth Eta",1);
    ScaleResEta1->SetTitle("Eta");
    ScaleResEta1->Draw("ColZ");
    
    TProfile* SREP1 = ScaleResEta1->ProfileX("Eta Statistics");
    
    TCanvas* can2 = new TCanvas("can2","",1200,1200);
    can2->Divide(2,2,0,0);

    gStyle->SetTitleTextColor(1);

    can2->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SREP1->SetTitle("Eta");
    SREP1->GetYaxis()->SetTitle("Mean");
    SREP1->GetXaxis()->SetTitle("Eta_R02_20Gev");
    SREP1->Draw("");
    
    TCanvas* can3 = new TCanvas("can3","",1000,1000);
    can3->Divide(2,2,0,0);

    can3->cd(1);
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPhi1,"Truth Phi","(Reco Phi - Truth Phi)/Truth Phi",2);
    ScaleResPhi1->SetTitle("Phi_R02_20Gev");
    ScaleResPhi1->Draw("ColZ"); 

    TProfile* SRPP1 = ScaleResPhi1->ProfileX("Phi Statistics");
    gStyle->SetTitleTextColor(1);



    TCanvas* can4 = new TCanvas("can4","",1200,1200);
    can4->Divide(2,2,0,0);

    can4->cd(1);
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPP1->GetYaxis()->SetTitle("Mean");
    SRPP1->GetXaxis()->SetTitle("Phi");
    SRPP1->SetTitle("Phi_R02_20Gev");
    SRPP1->Draw("");


TCanvas* can5 = new TCanvas("can5","",1200,1200);
    can5->Divide(2,2,0,0);

    can5->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPt1,"Truth Pt","(Reco Pt - Truth Pt)/Truth Pt",1);
    ScaleResPt1->SetTitle("Pt_R02_20Gev");
    ScaleResPt1->Draw("ColZ");
    
    TProfile* SRPTP1 = ScaleResPt1->ProfileX("Statistics");
    
    TCanvas* can6 = new TCanvas("can6","",1200,1200);
    can6->Divide(2,2,0,0);
    gStyle->SetTitleTextColor(1);


    can6->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPTP1->GetYaxis()->SetTitle("Mean");
    SRPTP1->GetXaxis()->SetTitle("Pt");
    SRPTP1->SetTitle("Pt_R02_20Gev");
    SRPTP1->Draw("");
    

    TCanvas* can7 = new TCanvas("can7","",1200,1200);
    can7->Divide(2,2,0,0);

    can7->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoEta1,"Truth Eta","Reco Eta",1);
    TruthvsRecoEta1->SetTitle("Eta_R02_20Gev");
    TruthvsRecoEta1->Draw("ColZ");
    gStyle->SetTitleTextColor(1);



    TCanvas* can8 = new TCanvas("can8","",1200,1200);
    can8->Divide(2,2,0,0);
    can8->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.15);
    gPad->SetTopMargin(.07);
    can3->SetTitle("TruthvsRecoPhi1");
    SetHist(TruthvsRecoPhi1,"Truth Phi","Reco Phi",2);
    TruthvsRecoPhi1->SetTitle("Phi_R02_20Gev");
    TruthvsRecoPhi1->Draw("ColZ"); 
    gStyle->SetTitleTextColor(1);

	TCanvas* can9 = new TCanvas("can9","",1200,1200);
    can9->Divide(2,2,0,0);


    can9->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoPt1,"Truth Pt","Reco Pt",1);
    TruthvsRecoPt1->SetTitle("Pt_R02_20Gev");
    TruthvsRecoPt1->Draw("ColZ");
    gStyle->SetTitleTextColor(1);

/* File 2 */
   TFile *_file2 = TFile::Open(infile2.c_str());

	TH2*  ScaleResEta2 = (TH2*)gROOT->FindObject("ScaleResEta");
    TH2*  ScaleResPhi2 = (TH2*)gROOT->FindObject("ScaleResPhi");
    TH2*  ScaleResPt2 = (TH2*)gROOT->FindObject("ScaleResPt");
    TH2*  TruthvsRecoEta2 = (TH2*)gROOT->FindObject("TruthvsRecoEta");
    TH2*  TruthvsRecoPhi2 = (TH2*)gROOT->FindObject("TruthvsRecoPhi");
    TH2*  TruthvsRecoPt2 = (TH2*)gROOT->FindObject("TruthvsRecoPt");

    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResEta2,"Truth Eta","(Reco Eta - Truth Eta)/Truth Eta",1);
    ScaleResEta2->SetTitle("Eta_R02_30Gev");
    ScaleResEta2->Draw("ColZ");
    
    TProfile* SREP2 = ScaleResEta2->ProfileX("Eta Statistics");
    

    

    can2->cd(2);
    gStyle->SetTitleTextColor(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SREP2->SetTitle("Eta_R02_30Gev");
    SREP2->GetYaxis()->SetTitle("Mean");
    SREP2->GetXaxis()->SetTitle("Eta");
    SREP2->Draw("");
    SREP2->SetMarkerColor(2);
    
  
    can3->cd(2);
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPhi2,"Truth Phi","(Reco Phi - Truth Phi)/Truth Phi",2);
    ScaleResPhi2->SetTitle("Phi_R02_30Gev");
    ScaleResPhi2->Draw("ColZ"); 

    TProfile* SRPP2 = ScaleResPhi2->ProfileX("Phi Statistics");
    gStyle->SetTitleTextColor(1);



    can4->cd(2);
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPP2->GetYaxis()->SetTitle("Mean");
    SRPP2->GetXaxis()->SetTitle("Phi");
    SRPP2->SetTitle("Phi_R02_30Gev");
    SRPP2->Draw("");



    can5->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPt2,"Truth Pt","(Reco Pt - Truth Pt)/Truth Pt",1);
    ScaleResPt2->SetTitle("Pt_R02_30Gev");
    ScaleResPt2->Draw("ColZ");
    
    TProfile* SRPTP2 = ScaleResPt2->ProfileX("Statistics");
    
    gStyle->SetTitleTextColor(1);


    can6->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPTP2->GetYaxis()->SetTitle("Mean");
    SRPTP2->GetXaxis()->SetTitle("Pt");
    SRPTP2->SetTitle("Pt_R02_30Gev");
    SRPTP2->Draw("");
    SRPTP2-> SetLineColor(2);

    can7->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoEta2,"Truth Eta","Reco Eta",1);
    TruthvsRecoEta2->SetTitle("Eta_R02_30Gev");
    TruthvsRecoEta2->Draw("ColZ");
    gStyle->SetTitleTextColor(1);



    can8->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.15);
    gPad->SetTopMargin(.07);
    can3->SetTitle("TruthvsRecoPhi2");
    SetHist(TruthvsRecoPhi2,"Truth Phi","Reco Phi",2);
    TruthvsRecoPhi2->SetTitle("Phi_R02_30Gev");
    TruthvsRecoPhi2->Draw("ColZ"); 
    gStyle->SetTitleTextColor(1);


    can9->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoPt2,"Truth Pt","Reco Pt",1);
    TruthvsRecoPt2->SetTitle("Pt_R02_30Gev");
    TruthvsRecoPt2->Draw("ColZ");
    gStyle->SetTitleTextColor(1);


/* File 3 */
    TFile *_file3 = TFile::Open(infile3.c_str());

	TH2*  ScaleResEta3 = (TH2*)gROOT->FindObject("ScaleResEta");
    TH2*  ScaleResPhi3 = (TH2*)gROOT->FindObject("ScaleResPhi");
    TH2*  ScaleResPt3 = (TH2*)gROOT->FindObject("ScaleResPt");
    TH2*  TruthvsRecoEta3 = (TH2*)gROOT->FindObject("TruthvsRecoEta");
    TH2*  TruthvsRecoPhi3 = (TH2*)gROOT->FindObject("TruthvsRecoPhi");
    TH2*  TruthvsRecoPt3 = (TH2*)gROOT->FindObject("TruthvsRecoPt");

    can1->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResEta3,"Truth Eta","(Reco Eta - Truth Eta)/Truth Eta",1);
    ScaleResEta3->SetTitle("Eta_R04_20Gev");
    ScaleResEta3->Draw("ColZ");
    
    TProfile* SREP3 = ScaleResEta3->ProfileX("Eta Statistics");
    
    gStyle->SetTitleTextColor(1);

    can2->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SREP3->SetTitle("Eta_R04_20Gev");
    SREP3->GetYaxis()->SetTitle("Mean");
    SREP3->GetXaxis()->SetTitle("Eta");
    SREP3->Draw("");


    can3->cd(3);
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPhi3,"Truth Phi","(Reco Phi - Truth Phi)/Truth Phi",2);
    ScaleResPhi3->SetTitle("Phi_R04_20Gev");
    ScaleResPhi3->Draw("ColZ"); 

    TProfile* SRPP3 = ScaleResPhi3->ProfileX("Phi Statistics");
    gStyle->SetTitleTextColor(1);



    can4->cd(3);
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPP3->GetYaxis()->SetTitle("Mean");
    SRPP3->GetXaxis()->SetTitle("Phi");
    SRPP3->SetTitle("Phi_R04_20Gev");
    SRPP3->Draw("");


    can5->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPt3,"Truth Pt","(Reco Pt - Truth Pt)/Truth Pt",1);
    ScaleResPt3->SetTitle("Pt_R04_20Gev");
    ScaleResPt3->Draw("ColZ");
    
    TProfile* SRPTP3 = ScaleResPt3->ProfileX("Statistics");
    
    gStyle->SetTitleTextColor(1);


    can6->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPTP3->GetYaxis()->SetTitle("Mean");
    SRPTP3->GetXaxis()->SetTitle("Pt");
    SRPTP3->SetTitle("Pt_R04_20Gev");
    SRPTP3->Draw("");
    SRPTP3-> SetLineColor(3);

    can7->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoEta3,"Truth Eta","Reco Eta",1);
    TruthvsRecoEta3->SetTitle("Eta_R04_20Gev");
    TruthvsRecoEta3->Draw("ColZ");
    gStyle->SetTitleTextColor(1);



    can8->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.15);
    gPad->SetTopMargin(.07);
    can3->SetTitle("TruthvsRecoPhi3");
    SetHist(TruthvsRecoPhi3,"Truth Phi","Reco Phi",2);
    TruthvsRecoPhi3->SetTitle("Phi_R04_20Gev");
    TruthvsRecoPhi3->Draw("ColZ"); 
    gStyle->SetTitleTextColor(1);


    can9->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoPt3,"Truth Pt","Reco Pt",1);
    TruthvsRecoPt3->SetTitle("Pt_R04_20Gev");
    TruthvsRecoPt3->Draw("ColZ");
    gStyle->SetTitleTextColor(1);

/* File 4 */
TFile *_file4 = TFile::Open(infile4.c_str());

	TH2*  ScaleResEta4 = (TH2*)gROOT->FindObject("ScaleResEta");
    TH2*  ScaleResPhi4 = (TH2*)gROOT->FindObject("ScaleResPhi");
    TH2*  ScaleResPt4 = (TH2*)gROOT->FindObject("ScaleResPt");
    TH2*  TruthvsRecoEta4 = (TH2*)gROOT->FindObject("TruthvsRecoEta");
    TH2*  TruthvsRecoPhi4 = (TH2*)gROOT->FindObject("TruthvsRecoPhi");
    TH2*  TruthvsRecoPt4 = (TH2*)gROOT->FindObject("TruthvsRecoPt");


    can1->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResEta4,"Truth Eta","(Reco Eta - Truth Eta)/Truth Eta",1);
    ScaleResEta4->SetTitle("Eta_R04_20Gev");
    ScaleResEta4->Draw("ColZ");
    
    TProfile* SREP4 = ScaleResEta4->ProfileX("Eta Statistics");
    

    gStyle->SetTitleTextColor(1);

    can2->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SREP4->SetTitle("Eta_R04_20Gev");
    SREP4->GetYaxis()->SetTitle("Mean");
    SREP4->GetXaxis()->SetTitle("Eta");
    SREP4->Draw("");
    

    can3->cd(4);
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPhi4,"Truth Phi","(Reco Phi - Truth Phi)/Truth Phi",2);
    ScaleResPhi4->SetTitle("Phi_R04_20Gev");
    ScaleResPhi4->Draw("ColZ"); 

    TProfile* SRPP4 = ScaleResPhi4->ProfileX("Phi Statistics");
    gStyle->SetTitleTextColor(1);


    can4->cd(4);
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPP4->GetYaxis()->SetTitle("Mean");
    SRPP4->GetXaxis()->SetTitle("Phi");
    SRPP4->SetTitle("Phi_R04_20Gev");
    SRPP4->Draw("");



    can5->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPt4,"Truth Pt","(Reco Pt - Truth Pt)/Truth Pt",1);
    ScaleResPt4->SetTitle("Pt_R04_20Gev");
    ScaleResPt4->Draw("ColZ");
    
    TProfile* SRPTP4 = ScaleResPt4->ProfileX("Statistics");
   


    can6->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPTP4->GetYaxis()->SetTitle("Mean");
    SRPTP4->GetXaxis()->SetTitle("Pt");
    SRPTP4->SetTitle("Pt_R04_20Gev");
    SRPTP4->Draw("");
    SRPTP4-> SetLineColor(4);

    can7->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoEta4,"Truth Eta","Reco Eta",1);
    TruthvsRecoEta4->SetTitle("Eta_R04_20Gev");
    TruthvsRecoEta4->Draw("ColZ");
    gStyle->SetTitleTextColor(1);



    can8->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.15);
    gPad->SetTopMargin(.07);
    can4->SetTitle("TruthvsRecoPhi4");
    SetHist(TruthvsRecoPhi4,"Truth Phi","Reco Phi",2);
    TruthvsRecoPhi4->SetTitle("Phi_R04_20Gev");
    TruthvsRecoPhi4->Draw("ColZ"); 
    gStyle->SetTitleTextColor(1);


    can9->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoPt4,"Truth Pt","Reco Pt",1);
    TruthvsRecoPt4->SetTitle("Pt_R04_20Gev");
    TruthvsRecoPt4->Draw("ColZ");
    gStyle->SetTitleTextColor(1);

  }

   void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 24,int width = 3, float size = 1.0)
{
    h->SetLineWidth(width);
    h->SetLineColor(color);
    h->SetMarkerColor(3);
    h->SetMarkerSize(0.5);
    h->SetMarkerStyle(marker);
    h->GetYaxis()->SetTitle(yt.c_str());
    h->GetYaxis()->SetTitleOffset(1.6);
    h->GetXaxis()->SetTitle(xt.c_str());
}

void SetHist(TH2* h, int color = 4)
{
    h->SetLineWidth(3);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(0.25);
    h->GetYaxis()->SetTitleOffset(1.6);
    
}


void SetLeg(TLegend* l,float txtsize=0.04){
    l->SetBorderSize(1);
    l->SetFillColor(1);
    l->SetTextSize(txtsize);
}