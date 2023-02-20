void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH2* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void DrawSpectraPt2D(string infile = "spectra2D_jetsMedium0to55.root"){
    
   
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH2*  TruthvsRecoEta = (TH2*)gROOT->FindObject("TruthvsRecoPt");
    TCanvas* can4 = new TCanvas("can4","",600,600);


    can4->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    SetHist(TruthvsRecoEta,"Truth Pt","Reco Pt",1);
    TruthvsRecoEta->SetTitle("Pt");
    TruthvsRecoEta->Draw("ColZ");
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