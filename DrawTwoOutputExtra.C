void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void DrawTwoOutputExtra(string infile1 = "newhist_jetsMedium0to55.root", string infile2 = "JetOutput.root"){
	
	gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

 TFile *_file1 = TFile::Open(infile1.c_str());
    
    TH1*  hLeadingJetPtNew = (TH1*)gROOT->FindObject("hLeadingJetPtNew");
    TH1* hSubLeadingJetPtNew = (TH1*)gROOT->FindObject("hSubLeadingJetPtNew");

    hLeadingJetPtNew->Scale(1.0/hLeadingJetPtNew->GetEntries());
    hSubLeadingJetPtNew->Scale(1.0/hSubLeadingJetPtNew->GetEntries());

 
 TFile *_file2 = TFile::Open(infile2.c_str());  

    TH1* hLeadingJetPt = (TH1*)gROOT->FindObject("hLeadingJetPt");
    TH1* hSubLeadingJetPt = (TH1*)gROOT->FindObject("hSubLeadingJetPt");
  
    
    TCanvas* can1 = new TCanvas("can1","",600,600);
    gPad->SetLeftMargin(0.15);
    gPad->SetLogy();
    SetHist(hLeadingJetPtNew,"p_{T,jet} (Gev)","dN/dp_T,jet",1);
    SetHist(hSubLeadingJetPtNew,"p_{T,jet} (Gev)","dN/dp_T,jet",2);
    
    SetHist(hLeadingJetPt,"p_{T,jet} (Gev)","dN/dp_T,jet",3);
    SetHist(hSubLeadingJetPt,"p_{T,jet} (Gev)","dN/dp_T,jet",4);

    hLeadingJetPtNew->Draw("E1");
	hSubLeadingJetPtNew->Draw("E1same");

    hLeadingJetPt->Draw("E1same");
    hSubLeadingJetPt->Draw("E1same");
    
    TLegend* leg1 = new TLegend(0.25,0.7,0.5,0.85);
    SetLeg(leg1);
    leg1->AddEntry(hLeadingJetPtNew,"leading","L");
    leg1->AddEntry(hSubLeadingJetPtNew,"subleading","L");

    leg1->AddEntry(hLeadingJetPt,"leadingReed","L");
    leg1->AddEntry(hSubLeadingJetPt,"subleadingReed","L");

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