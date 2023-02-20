void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void Draw_Aj(string infile0 = "Aj_jetsMedium0to55.root"){
    
    gStyle->SetOptStat(0);

    
    TFile *_file0 = TFile::Open(infile0.c_str());
    
    TH1* hAjTruth = (TH1*)gROOT->FindObject("hAjTruth");
    TH1* hAjReco = (TH1*)gROOT->FindObject("hAjReco");
    TH2* AjTruthvsReco = (TH2*)gROOT->FindObject("AjTruthvsReco");

    
    TCanvas* can1 = new TCanvas("can1","",1200,600);
    can1->Divide(2,1,0,0);

    can1->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruth,"A_{j}","counts",1);
    SetHist(hAjReco,"A_{j}","?",2);
    
    hAjTruth->Draw();
    hAjTruth->SetLineColor(9);
    hAjReco->Draw("same");
    hAjReco->SetLineStyle(7);
    
    TLegend* leg1 = new TLegend(0.7,0.7,0.85,0.85);
    SetLeg(leg1);
    leg1->AddEntry(hAjTruth,"Truth","L");
    leg1->AddEntry(hAjReco,"Reco","L");
    leg1->Draw();

    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(AjTruthvsReco,"Truth A_{j}","Reco A_{j}",1); 
    AjTruthvsReco->Draw("ColZ");
    gStyle->SetTitleTextColor(1);
    
  
}

void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0)
{
    h->SetLineWidth(width);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(size);
    h->SetMarkerStyle(marker);
    h->GetYaxis()->SetTitle(yt.c_str());
    h->GetYaxis()->SetTitleOffset(1.6);
    h->GetXaxis()->SetTitle(xt.c_str());
}

void SetHist(TH1* h, int color = 1)
{
    h->SetLineWidth(3);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(1);
    h->GetYaxis()->SetTitleOffset(1.6);
    
}


void SetLeg(TLegend* l,float txtsize=0.03){
    l->SetBorderSize(0);
    l->SetFillColor(0);
    l->SetTextSize(txtsize);
}
