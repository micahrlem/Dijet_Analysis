void SetHist(TH1* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void DrawEfficiencyMultiple(string infile1 = "efficiency_R02_20Gev_output.root", string infile2 = "efficiency_R02_30Gev_output.root", string infile3 = "efficiency_R04_20Gev_output.root", string infile4 = "efficiency_R04_30Gev_output.root"){

TFile *_file1 = TFile::Open(infile1.c_str());

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
    MatchedJets->SetTitle("Matched vs All Jets");
    MatchedJets->SetLineStyle(2);
    MatchedJets->SetLineColor(1);
    MatchedJets->Draw();
    gStyle->SetTitleTextColor(1);
    gStyle->SetOptStat(0);
    AllJets->Draw("same");
    AllJets->SetLineStyle(1);
    AllJets->SetLineColor(1);
    TLegend *legend = new TLegend(0.65,0.65,0.9,0.9);
    legend->AddEntry(MatchedJets, "Matched R02 20Gev");
    legend->AddEntry(AllJets, "All R02 20Gev");


    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(Efficiency,"pt (GeV/c))","Efficiency",1);
    Efficiency->SetTitle("Efficiency");
    Efficiency->Draw();
    Efficiency->SetLineStyle(1);
    gStyle->SetTitleTextColor(2);
    TLegend *legend2 = new TLegend(0.65,0.65,0.9,0.9);
    legend2->AddEntry(Efficiency, "Efficiency R02 20Gev");


TFile *_file2 = TFile::Open(infile2.c_str());

 TH1*  MatchedJets2 = (TH1*)gROOT->FindObject("MatchedJets");
 TH1*  AllJets2 = (TH1*)gROOT->FindObject("AllJets");
 TH1*  Efficiency2 = (TH1*)gROOT->FindObject("Efficiency");


 can1->cd(1);

    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    gPad->SetLogy();
    SetHist(MatchedJets2,"pt (GeV/c)","Counts",1);
    MatchedJets2->SetTitle("Matched vs All Jets");
    MatchedJets2->SetLineStyle(2);
    MatchedJets2->SetLineColor(2);
    MatchedJets2->Draw("same");
    gStyle->SetTitleTextColor(1);
    gStyle->SetOptStat(0);
    AllJets2->Draw("same");
    AllJets2->SetLineStyle(1);
    AllJets2->SetLineColor(2);
    legend->AddEntry(MatchedJets2, "Matched R02 30Gev");
    legend->AddEntry(AllJets2, "All R02 30Gev");


    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(Efficiency2,"pt (GeV/c))","Efficiency",1);
    Efficiency2->SetTitle("Efficiency");
    Efficiency2->Draw("same");
    Efficiency2->SetLineColor(2);
    Efficiency2->SetLineStyle(2);
    gStyle->SetTitleTextColor(2);
    legend2->AddEntry(Efficiency2, "Efficiency R02 30Gev");
    gStyle->SetTitleTextColor(2);


    TFile *_file3 = TFile::Open(infile3.c_str());

 TH1*  MatchedJets3 = (TH1*)gROOT->FindObject("MatchedJets");
 TH1*  AllJets3 = (TH1*)gROOT->FindObject("AllJets");
 TH1*  Efficiency3 = (TH1*)gROOT->FindObject("Efficiency");


 can1->cd(1);

    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    gPad->SetLogy();
    SetHist(MatchedJets3,"pt (GeV/c)","Counts",1);
    MatchedJets3->SetTitle("Matched vs All Jets");
    MatchedJets3->SetLineStyle(2);
    MatchedJets3->SetLineColor(11);
    MatchedJets3->Draw("same");
    gStyle->SetTitleTextColor(1);
    gStyle->SetOptStat(0);
    AllJets3->Draw("same");
    AllJets3->SetLineStyle(1);
    AllJets3->SetLineColor(11);
    legend->AddEntry(MatchedJets3, "Matched R04 20Gev");
    legend->AddEntry(AllJets3, "All R04 20Gev");



    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(Efficiency3,"pt (GeV/c))","Efficiency",1);
    Efficiency3->SetTitle("Efficiency");
    Efficiency3->Draw("same");
    Efficiency3->SetLineColor(11);
    Efficiency3->SetLineStyle(1);
    legend2->AddEntry(Efficiency3, "Efficiency R04 20Gev");
    gStyle->SetTitleTextColor(1);


TFile *_file4 = TFile::Open(infile4.c_str());

 TH1*  MatchedJets4 = (TH1*)gROOT->FindObject("MatchedJets");
 TH1*  AllJets4 = (TH1*)gROOT->FindObject("AllJets");
 TH1*  Efficiency4 = (TH1*)gROOT->FindObject("Efficiency");


 can1->cd(1);

    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    gPad->SetLogy();
    SetHist(MatchedJets4,"pt (GeV/c)","Counts",1);
    MatchedJets4->SetTitle("Matched vs All Jets");
    MatchedJets4->SetLineStyle(2);
    MatchedJets4->SetLineColor(4);
    MatchedJets4->Draw("same");
    gStyle->SetTitleTextColor(1);
    gStyle->SetOptStat(0);
    AllJets4->Draw("same");
    AllJets4->SetLineStyle(1);
    AllJets4->SetLineColor(4);
    legend->AddEntry(MatchedJets4, "Matched R04 30Gev");
    legend->AddEntry(AllJets4, "All R04 30Gev");
    legend->Draw();


    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(Efficiency4,"pt (GeV/c))","Efficiency",1);
    Efficiency4->SetTitle("Efficiency R04 30Gev");
    Efficiency4->Draw("same");
    Efficiency4->SetLineColor(4);
    Efficiency4->SetLineStyle(2);
    legend2->AddEntry(Efficiency4, "Efficiency R04 30Gev");
    legend2->Draw();
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