void SetHist(TH1* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void EfficiencyDraw(string infile = "efficiency_G4sPHENIX_g4jet_eval.root"){
	

	TFile *_file0 = TFile::Open(infile.c_str());
    
    TH1*  MatchedJets = (TH1*)gROOT->FindObject("MatchedJets");
    TH1*  AllJets = (TH1*)gROOT->FindObject("AllJets");
    TH1*  Efficiency = (TH1*)gROOT->FindObject("Efficiency");
    TCanvas* can1 = new TCanvas("can1","",1200,600);

    can1->Divide(2,1,0,0);

    can1->cd(1);

    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    gPad->SetLogy();
    SetHist(MatchedJets,"pt (GeV/c)","Counts",1);
    MatchedJets->SetTitle("Matched vs All Jets (R = 0.4)");
    MatchedJets->SetLineStyle(2);
    MatchedJets->Draw();
    gStyle->SetTitleTextColor(1);
    gStyle->SetOptStat(0);
    AllJets->Draw("same");
    AllJets->SetLineStyle(1);
    AllJets->SetLineColor(2);
    TLegend *legend = new TLegend(0.75,0.80,0.9,0.9);
    legend->AddEntry(MatchedJets, "Matched");
    legend->AddEntry(AllJets, "All");
    legend->Draw();


    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(Efficiency,"pt (GeV/c))","Efficiency",1);
    Efficiency->SetTitle("Efficiency");
    Efficiency->Draw();
    gStyle->SetTitleTextColor(1);



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