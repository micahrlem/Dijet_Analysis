void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void Draw_Aj_Multiple(string infile0 = "Aj_R02_30Gev_output.root", string infile1 = " Aj_R02_20Gev_output.root", string infile2 = "Aj_R04_20Gev_output.root", string infile3 = "Aj_R04_30Gev_output.root"){
    
    gStyle->SetOptStat(0);

    
    TFile *_file0 = TFile::Open(infile0.c_str());
    
    TH1* hAjTruth = (TH1*)gROOT->FindObject("hAjTruth");
    TH1* hAjReco = (TH1*)gROOT->FindObject("hAjReco");
    TH2* AjTruthvsReco = (TH2*)gROOT->FindObject("AjTruthvsReco");

    
    TCanvas* can1 = new TCanvas("can1","",1200,1200);
    can1->Divide(1,1,0,0);

    can1->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruth,"A_{j}","share of counts",1);
    SetHist(hAjReco,"A_{j}","?",2);
    
    hAjTruth->Draw();
    hAjTruth->SetMarkerColor(9);
    hAjTruth->SetMarkerStyle(20);
    hAjReco->Draw("same");
    hAjReco->SetLineColor(9);
    hAjReco->SetMarkerColor(1);
    hAjReco->SetMarkerStyle(24);
    
    TLegend* leg1 = new TLegend(0.65,0.65,0.90,0.90);
    SetLeg(leg1);
    leg1->AddEntry(hAjTruth,"Truth 0.2R 30Gev","P");
    leg1->AddEntry(hAjReco,"Reco 0.2R 30Gev","P");
    

    TCanvas* can2 = new TCanvas("can2","",1200,600);
    can2->Divide(2,2,0,0);
    can2->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(AjTruthvsReco,"Truth A_{j}","Reco A_{j}",1); 
    AjTruthvsReco->Draw("ColZ");
    AjTruthvsReco->SetTitle("R = 0.2 Min pt = 30Gev");
    gStyle->SetTitleTextColor(1);
    

   /* second file  */
    TFile *_file1 = TFile::Open(infile1.c_str());
    
    TH1* hAjTruth1 = (TH1*)gROOT->FindObject("hAjTruth");
    TH1* hAjReco1 = (TH1*)gROOT->FindObject("hAjReco");
    TH2* AjTruthvsReco1 = (TH2*)gROOT->FindObject("AjTruthvsReco");

    can1->cd(1);
    
    hAjTruth1->Draw("same");
    hAjTruth1->SetMarkerColor(7);
    hAjTruth1->SetMarkerStyle(21);
    hAjReco1->Draw("same");
    hAjReco1->SetLineColor(7);
    hAjReco1->SetMarkerColor(1);
    hAjReco1->SetMarkerStyle(25);
    
    leg1->AddEntry(hAjTruth1,"Truth 0.2R 20Gev","P");
    leg1->AddEntry(hAjReco1,"Reco 0.2R 20Gev","P");
    leg1->Draw();

    can2->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(AjTruthvsReco1,"Truth A_{j}","Reco A_{j}",1); 
    AjTruthvsReco1->Draw("ColZ");
    AjTruthvsReco1->SetTitle("R = 0.2 Min pt = 20Gev");
    gStyle->SetTitleTextColor(1);
  
  /* third file  */
    TFile *_file2 = TFile::Open(infile2.c_str());
    
    TH1* hAjTruth2 = (TH1*)gROOT->FindObject("hAjTruth");
    TH1* hAjReco2 = (TH1*)gROOT->FindObject("hAjReco");
    TH2* AjTruthvsReco2 = (TH2*)gROOT->FindObject("AjTruthvsReco");

    can1->cd(1);
    
    hAjTruth2->Draw("same");
    hAjTruth2->SetMarkerColor(1);
    hAjTruth2->SetMarkerStyle(22);
    hAjReco2->Draw("same");
    hAjReco2->SetLineColor(1);
    hAjReco2->SetMarkerStyle(26);
    
    leg1->AddEntry(hAjTruth2,"Truth 0.4R 20Gev","P");
    leg1->AddEntry(hAjReco2,"Reco 0.4R 20Gev","P");
    leg1->Draw();

    can2->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(AjTruthvsReco2,"Truth A_{j}","Reco A_{j}",1); 
    AjTruthvsReco2->Draw("ColZ");
    AjTruthvsReco2->SetTitle("R = 0.4 Min pt = 20Gev");
    gStyle->SetTitleTextColor(1);

/* fourth file  */
    TFile *_file3 = TFile::Open(infile3.c_str());
    
    TH1* hAjTruth3 = (TH1*)gROOT->FindObject("hAjTruth");
    TH1* hAjReco3 = (TH1*)gROOT->FindObject("hAjReco");
    TH2* AjTruthvsReco3 = (TH2*)gROOT->FindObject("AjTruthvsReco");

    can1->cd(1);
    
    hAjTruth3->Draw("same");
    hAjTruth3->SetMarkerColor(2);
    hAjTruth3->SetMarkerStyle(47);
    hAjReco3->Draw("same");
    hAjReco3->SetLineColor(2);
    hAjReco3->SetMarkerStyle(46);
    
    leg1->AddEntry(hAjTruth3,"Truth 0.4R 30Gev","P");
    leg1->AddEntry(hAjReco3,"Reco 0.4R 30Gev","P");
    leg1->Draw();

    can2->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(AjTruthvsReco3,"Truth A_{j}","Reco A_{j}",1); 
    AjTruthvsReco3->Draw("ColZ");
    AjTruthvsReco3->SetTitle("R = 0.4 Min pt = 30Gev");
    gStyle->SetTitleTextColor(1);


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


