void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH2* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void DrawSpectra2D(string infile = "spectra2D_jetsMedium0to55.root"){
    
   
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH2*  TruthvsRecoEta = (TH2*)gROOT->FindObject("TruthvsRecoEta");
    TH2*  TruthvsRecoPhi = (TH2*)gROOT->FindObject("TruthvsRecoPhi");
    TCanvas* can1 = new TCanvas("can1","",1200,600);
    can1->Divide(2,1,0,0);

    can1->cd(1);{
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoEta,"Truth Eta","Reco Eta",1);
    TruthvsRecoEta->SetTitle("Eta");
    TruthvsRecoEta->Draw("ColZ");
    gStyle->SetTitleTextColor(1);

}
    can1->cd(2);{
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.15);
    gPad->SetTopMargin(.07);
    can1->SetTitle("TruthvsRecoPhi");
    SetHist(TruthvsRecoPhi,"Truth Phi","Reco Phi",2);
    TruthvsRecoPhi->SetTitle("Phi");
    TruthvsRecoPhi->Draw("ColZ"); 
    gStyle->SetTitleTextColor(1);



}
      
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