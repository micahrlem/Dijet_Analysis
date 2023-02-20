void SetHist(TH1* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);

void DrawEtaPhiTruthReco(string infile = "etaphi2D_jetsMedium0to55.root"){
    
   
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH1* hTruthPhi = (TH1*)gROOT->FindObject("hTruthPhi");
    TH1* hRecoPhi = (TH1*)gROOT->FindObject("hRecoPhi");
    TH1* hTruthEta = (TH1*)gROOT->FindObject("hTruthEta");
    TH1* hRecoEta = (TH1*)gROOT->FindObject("hRecoEta");
    TCanvas* can1 = new TCanvas("can1","",1200,600);
    can1->Divide(2,1,0,0);

    can1->cd(1);{
    SetHist(hTruthEta,"Eta","Counts",1);
    SetHist(hRecoEta,"Eta","Counts",2);
    hTruthEta->Draw();
    hRecoEta->Draw("same");
    hTruthEta -> SetTitle("Eta");
    gStyle->SetTitleTextColor(46);
    TLegend* leg1 = new TLegend(0.8,0.7,0.95,0.85);
    SetLeg(leg1);
    leg1->AddEntry(hTruthEta,"TruthEta","L");
    leg1->AddEntry(hRecoEta,"RecoEta","L");
    leg1->Draw();

}
    can1->cd(2);{
    can1->SetTitle("Phi");
    SetHist(hTruthPhi,"Phi","Counts",3);
    SetHist(hRecoPhi,"Phi","Counts",4);
    hTruthPhi -> SetTitle("Phi");
    hTruthPhi->Draw();
    hRecoPhi->Draw("same");
    hRecoPhi->SetMarkerColor(2);
    gStyle->SetTitleTextColor(46);
    gPad->SetLeftMargin(0.15);

    TLegend* leg2 = new TLegend(0.85,0.85,0.95,0.95);
    SetLeg(leg2);
    leg2->AddEntry(hTruthPhi,"TruthPhi","L");
    leg2->AddEntry(hRecoPhi,"RecoPhi","L");
    leg2->Draw();

}
      
}


void SetHist(TH1* h, string xt ="", string yt ="",int color = 4, int marker = 24,int width = 3, float size = 1.0)
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

void SetHist(TH1* h, int color = 4)
{
    h->SetLineWidth(3);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(0.25);
    h->GetYaxis()->SetTitleOffset(1.6);
    
}


void SetLeg(TLegend* l,float txtsize=0.04){
    l->SetBorderSize(0);
    l->SetFillColor(0);
    l->SetTextSize(txtsize);
}