void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);


void Draw_Eta_Phi(string infile = "spectra_eta_phi_jets0000small.root"){
    
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH1* hTruthPhi = (TH1*)gROOT->FindObject("hTruthPhi");
    TH1* hRecoPhi = (TH1*)gROOT->FindObject("hRecoPhi");
    TH1* hTruthEta = (TH1*)gROOT->FindObject("hTruthEta");
    TH1* hRecoEta = (TH1*)gROOT->FindObject("hRecoEta");


    
    TCanvas* can1 = new TCanvas("can1","",600,600);
    gPad->SetLeftMargin(0.15);
    SetHist(hTruthPhi,"pt","counts",1);
    SetHist(hRecoPhi,"gpt","counts",2);
    SetHist(hTruthEta,"eta/phi","counts",3);
    SetHist(hRecoEta,"geta","counts",4);


    hRecoEta->Draw();
    hTruthEta->Draw("same");
    hTruthPhi->Draw("same");
    hRecoPhi->Draw("same");
    
    
    
    TLegend* leg1 = new TLegend(0.8,0.7,0.95,0.85);
    SetLeg(leg1);
    leg1->AddEntry(hTruthPhi,"TruthPhi","L");
    leg1->AddEntry(hRecoPhi,"RecoPhi","L");
    leg1->AddEntry(hTruthEta,"TruthEta","L");
    leg1->AddEntry(hRecoEta,"RecoEta","L");
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