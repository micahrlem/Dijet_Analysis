void SetHist(TH2* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH2* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void DrawTwoRatioXandY(string infile = "newhist2_jets0000small.root"){
    
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH2*  RecovsTruth = (TH2*)gROOT->FindObject("RecovsTruth");

    TCanvas* can1 = new TCanvas("can1","",600,600);
    gPad->SetLeftMargin(0.15);
    SetHist(RecovsTruth,"Truth","Reco",1);
    
    RecovsTruth->Draw("ColZ");

    
      
}

void SetHist(TH2* h, string xt ="", string yt ="",int color = 2, int marker = 20,int width = 3, float size = 1.0)
{
    h->SetLineWidth(width);
    h->SetLineColor(color);
    h->SetMarkerColor(2);
    h->SetMarkerSize(0.5);
    h->SetMarkerStyle(marker);
    h->GetYaxis()->SetTitle(yt.c_str());
    h->GetYaxis()->SetTitleOffset(1.6);
    h->GetXaxis()->SetTitle(xt.c_str());
}

void SetHist(TH2* h, int color = 2)
{
    h->SetLineWidth(3);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(0.25);
    h->GetYaxis()->SetTitleOffset(1.6);
    
}


void SetLeg(TLegend* l,float txtsize=0.03){
    l->SetBorderSize(0);
    l->SetFillColor(0);
    l->SetTextSize(txtsize);
}
