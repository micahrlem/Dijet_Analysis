void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void DrawTwoRatio(string infile = "newhist_jets0000small.root"){
    
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH1* hRatioLvsSL = (TH1*)gROOT->FindObject("hRatioLvsSL");
    TH1* hRatioLvsSLReco = (TH1*)gROOT->FindObject("hRatioLvsSLReco");

    TCanvas* can1 = new TCanvas("can1","",600,600);
    gPad->SetLeftMargin(0.15);
    gPad->SetLogy();
    SetHist(hRatioLvsSL,"subleading/leading","counts",1);
    SetHist(hRatioLvsSLReco,"subleading/leading","counts",2);

    hRatioLvsSL->Draw();
    hRatioLvsSLReco->Draw("same");
    
    TLegend* leg1 = new TLegend(0.7,0.7,0.85,0.85);
    SetLeg(leg1);
    leg1->AddEntry(hRatioLvsSL,"Truth","L");
    leg1->AddEntry(hRatioLvsSLReco,"Reco","L");
    leg1->Draw();

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
