void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH2* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void Draw_QA_Plot_NoCut(string infile = "qa_R02_20Gev_output.root"){

	TFile *_file0 = TFile::Open(infile.c_str());
    
    TH2*  ScaleResEta = (TH2*)gROOT->FindObject("ScaleResEtaNoCut");
    TH2*  ScaleResPhi = (TH2*)gROOT->FindObject("ScaleResPhiNoCut");
    TH2*  ScaleResPt = (TH2*)gROOT->FindObject("ScaleResPtNoCut");
    TH2*  TruthvsRecoEta = (TH2*)gROOT->FindObject("TruthvsRecoEtaNoCut");
    TH2*  TruthvsRecoPhi = (TH2*)gROOT->FindObject("TruthvsRecoPhiNoCut");
    TH2*  TruthvsRecoPt = (TH2*)gROOT->FindObject("TruthvsRecoPtNoCut");
    TCanvas* can1 = new TCanvas("can1","",1000,1000);
    can1->Divide(2,2,0,0);

    can1->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResEta,"Truth Eta No Cuts","(Reco Eta - Truth Eta)/Truth Eta",1);
    ScaleResEta->SetTitle("Eta No Cuts ");
    ScaleResEta->Draw("ColZ");
    
    TProfile* SREP = ScaleResEta->ProfileX("Eta Statistics No Cuts");
    
    gStyle->SetTitleTextColor(1);

    can1->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SREP->SetTitle("Eta No Cuts");
    SREP->GetYaxis()->SetTitle("Mean");
    SREP->GetXaxis()->SetTitle("Eta");
    SREP->Draw("");
    
    
    can1->cd(2);
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPhi,"Truth Phi No Cuts","(Reco Phi - Truth Phi)/Truth Phi",2);
    ScaleResPhi->SetTitle("Phi No Cuts");
    ScaleResPhi->Draw("ColZ"); 

    TProfile* SRPP = ScaleResPhi->ProfileX("Phi Statistics No Cuts");
    gStyle->SetTitleTextColor(1);




    can1->cd(4);
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPP->GetYaxis()->SetTitle("Mean");
    SRPP->GetXaxis()->SetTitle("Phi");
    SRPP->SetTitle("Phi No Cuts");
    SRPP->Draw("");


TCanvas* can2 = new TCanvas("can2","",1200,600);
    can2->Divide(2,1,0,0);

    can2->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPt,"Truth Pt","(Reco Pt - Truth Pt)/Truth Pt",1);
    ScaleResPt->SetTitle("Pt  No Cuts");
    ScaleResPt->Draw("ColZ");
    
    TProfile* SRPTP = ScaleResPt->ProfileX("Statistics");
    
    gStyle->SetTitleTextColor(1);


    can2->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPTP->GetYaxis()->SetTitle("Mean");
    SRPTP->GetXaxis()->SetTitle("Pt");
    SRPTP->SetTitle("Scale No Cuts");
    SRPTP->Draw("");
    

    TCanvas* can3 = new TCanvas("can3","",1200,600);
    can3->Divide(2,1,0,0);

    can3->cd(1);{
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoEta,"Truth Eta","Reco Eta",1);
    TruthvsRecoEta->SetTitle("Eta No Cuts");
    TruthvsRecoEta->Draw("ColZ");
    gStyle->SetTitleTextColor(1);

}
    can3->cd(2);{
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.15);
    gPad->SetTopMargin(.07);
    can3->SetTitle("TruthvsRecoPhi");
    SetHist(TruthvsRecoPhi,"Truth Phi","Reco Phi",2);
    TruthvsRecoPhi->SetTitle("Phi No Cuts");
    TruthvsRecoPhi->Draw("ColZ"); 
    gStyle->SetTitleTextColor(1);
}
    TCanvas* can4 = new TCanvas("can4","",600,600);


    can4->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoPt,"Truth Pt","Reco Pt",1);
    TruthvsRecoPt->SetTitle("Pt No Cuts");
    TruthvsRecoPt->Draw("ColZ");
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