void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void DrawJetHist(string infile = "hist_G4sPHENIX.root_g4jet_eval.root"){
    
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH1* hJetTruthPt = (TH1*)gROOT->FindObject("hJetTruthPt");
    TH1* hJetRecoPt = (TH1*)gROOT->FindObject("hJetRecoPt");
    TH1* hJetTruthPt_gpt30 = (TH1*)gROOT->FindObject("hJetTruthPt_gpt30");
    TH1* hRatio = (TH1*)gROOT->FindObject("hRatio");
    
    
    TCanvas* can1 = new TCanvas("can1","",600,600);
    gPad->SetLeftMargin(0.15);
    gPad->SetLogy();
    SetHist(hJetTruthPt,"p_{T,jet}","counts",1);
    SetHist(hJetRecoPt,"p_{T,jet}","counts",2);
    
    hJetTruthPt->Draw();
    hJetRecoPt->Draw("same");
    
    TLegend* leg1 = new TLegend(0.7,0.7,0.85,0.85);
    SetLeg(leg1);
    leg1->AddEntry(hJetTruthPt,"Truth","L");
    leg1->AddEntry(hJetRecoPt,"Reco","L");
    leg1->Draw();
    
    TCanvas* can2 = new TCanvas("can2","",600,600);
    gPad->SetLeftMargin(0.15);
    gPad->SetLogy();
    SetHist(hJetTruthPt_gpt30,"p_{T,jet}","counts",4);
    
    
    hJetTruthPt->Draw();
    hJetTruthPt_gpt30->Draw("same");
    
    TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
    SetLeg(leg2);
    leg2->AddEntry(hJetTruthPt,"Truth pT","");
    leg2->AddEntry(hJetTruthPt,"All","L");
    leg2->AddEntry(hJetTruthPt_gpt30,"p_{T,jet}^{reco} > 30 GeV","L");
    leg2->Draw();
    
    
    TCanvas* can3 = new TCanvas("can3","",600,600);
    gPad->SetLeftMargin(0.15);

    SetHist(hRatio,"p_{T,jet}^{reco}/p_{T,jet}^{gen}","counts",1);
    
    hRatio->Draw();
    
    
    
    
    
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
