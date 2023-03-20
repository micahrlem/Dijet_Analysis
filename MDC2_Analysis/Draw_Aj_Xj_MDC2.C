void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void Draw_Aj_Xj_MDC2(string infile0 = "Aj_Xj_MDC2wCentJetsUEsub.root"){
    
    gStyle->SetOptStat(0);

    
    TFile *_file0 = TFile::Open(infile0.c_str());
    
    TH1* hAjTruth = (TH1*)gROOT->FindObject("hAjTruth");
    TH1* hAjReco = (TH1*)gROOT->FindObject("hAjReco");
    TH2* AjTruthvsReco = (TH2*)gROOT->FindObject("AjTruthvsReco");

    TH1* hXjTruth = (TH1*)gROOT->FindObject("hXjTruth");
    TH1* hXjReco = (TH1*)gROOT->FindObject("hXjReco");
    TH2* XjTruthvsReco = (TH2*)gROOT->FindObject("XjTruthvsReco");
    
    TH1* hAjTruth_0_20 = (TH1*)gROOT->FindObject("hAjTruth_0_20");
    TH1* hAjTruth_20_50 = (TH1*)gROOT->FindObject("hAjTruth_20_50");
    TH1* hAjTruth_50_100 = (TH1*)gROOT->FindObject("hAjTruth_50_100");
    TH1* hAjReco_0_20 = (TH1*)gROOT->FindObject("hAjReco_0_20");
    TH1* hAjReco_20_50 = (TH1*)gROOT->FindObject("hAjReco_20_50");
    TH1* hAjReco_50_100 = (TH1*)gROOT->FindObject("hAjReco_50_100");
    
    TH1* hXjTruth_0_20 = (TH1*)gROOT->FindObject("hXjTruth_0_20");
    TH1* hXjTruth_20_50 = (TH1*)gROOT->FindObject("hXjTruth_20_50");
    TH1* hXjTruth_50_100 = (TH1*)gROOT->FindObject("hXjTruth_50_100");
    TH1* hXjReco_0_20 = (TH1*)gROOT->FindObject("hXjReco_0_20");
    TH1* hXjReco_20_50 = (TH1*)gROOT->FindObject("hXjReco_20_50");
    TH1* hXjReco_50_100 = (TH1*)gROOT->FindObject("hXjReco_50_100");
    
    

    
    TCanvas* can1 = new TCanvas("can1","",1200,600);
    can1->Divide(2,1,0,0);

    can1->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruth,"A_{j}","Share of Total",1);
    SetHist(hAjReco,"A_{j}","Share of Centrality Range",2);
    
    hAjReco->GetYaxis()->SetRangeUser(0,0.12);
    hAjReco->SetTitle("A_{j} Overall Truth vs Reconstructed Values");
    hAjTruth->SetLineColor(9);
    hAjReco->Draw();
    hAjTruth->Draw("same");
    hAjReco->SetLineStyle(7);
    
    TLegend* leg1 = new TLegend(0.7,0.7,0.85,0.85);
    SetLeg(leg1);
    leg1->AddEntry(hAjTruth,"Truth","P");
    leg1->AddEntry(hAjReco,"Reco","P");
    leg1->Draw();

    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.15);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(AjTruthvsReco,"Truth A_{j}","Reco A_{j}",1);
    AjTruthvsReco->SetTitle("A_{j} Overall Truth Values vs Reconstructed Values");
    AjTruthvsReco->Draw("ColZ");
    gStyle->SetTitleTextColor(1);

    TCanvas* can2 = new TCanvas("can2","",1200,600);
    can2->Divide(2,1,0,0);

    can2->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hXjTruth,"X_{j}","Share of Total",1);
    SetHist(hXjReco,"X_{j}","Share of Centrality Range",2);
    
    hXjReco->GetYaxis()->SetRangeUser(0,0.07);
    hXjTruth->SetLineColor(9);
    hXjReco->SetTitle("X_{j} Overall Truth vs Reconstructed Values");
    hXjReco->Draw();
    hXjTruth->Draw("same");
    hXjReco->SetLineStyle(7);
    
    TLegend* leg2 = new TLegend(0.2,0.7,0.35,0.85);
    SetLeg(leg2);
    leg2->AddEntry(hXjTruth,"Truth","P");
    leg2->AddEntry(hXjReco,"Reco","P");
    leg2->Draw();

    can2->cd(2);
    
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(XjTruthvsReco,"Truth X_{j}","Reco X_{j}",1); 
    XjTruthvsReco->SetTitle("X_{j} Overall Truth Values vs Reconstructed Values");
    XjTruthvsReco->Draw("ColZ");
    gStyle->SetTitleTextColor(1);
    
  
    TCanvas* can3 = new TCanvas("can3","",1200,600);
    can3->Divide(2,1,0,0);

    can3->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruth,"A_{j}","Share  of Centrality Range",1);
    
    hAjTruth->GetXaxis()->SetRangeUser(0,0.85);
    hAjTruth->GetYaxis()->SetRangeUser(0,0.13);
    hAjTruth->SetTitle("Truth A_{j} Values of Various Centrality Ranges");
    hAjTruth->Draw();
    hAjTruth->SetMarkerColor(1);
    hAjTruth->SetMarkerStyle(20);
    hAjTruth_0_20->SetMarkerColor(2);
    hAjTruth_0_20->SetMarkerStyle(21);
    hAjTruth_0_20->Draw("same");
    hAjTruth_20_50->SetMarkerColor(4);
    hAjTruth_20_50->SetMarkerStyle(29);
    hAjTruth_20_50->Draw("same");
    hAjTruth_50_100->SetMarkerColor(6);
    hAjTruth_50_100->SetMarkerStyle(23);  
    hAjTruth_50_100->Draw("same");
    
    TLegend* leg3 = new TLegend(0.6,0.7,0.75,0.85);
    SetLeg(leg3);
    leg3->AddEntry(hAjTruth,"All Ranges","P");
    leg3->AddEntry(hAjTruth_0_20,"Very Central (0 - 20%)","P");
    leg3->AddEntry(hAjTruth_20_50,"Mid Centrality (20 - 50%)","P");
    leg3->AddEntry(hAjTruth_50_100,"Peripheral (50 - 100%)","P");
    leg3->Draw();

    can3->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);

    hAjReco_0_20->SetTitle("Reconstructed A_{j} Values of Various Centrality Ranges");
    hAjReco_0_20->GetYaxis()->SetRangeUser(0,0.055);
    hAjReco_0_20->Draw();
    hAjReco->SetMarkerColor(1);
    hAjReco->SetMarkerStyle(24);
    hAjReco_0_20->SetMarkerColor(2);
    hAjReco_0_20->SetMarkerStyle(25);
    hAjReco->Draw("same");
    hAjReco_20_50->SetMarkerColor(4);
    hAjReco_20_50->SetMarkerStyle(30);
    hAjReco_20_50->Draw("same");
    hAjReco_50_100->SetMarkerColor(6);
    hAjReco_50_100->SetMarkerStyle(32);  
    hAjReco_50_100->Draw("same");
    
    TLegend* leg4 = new TLegend(0.6,0.7,0.75,0.85);
    SetLeg(leg4);
    leg4->AddEntry(hAjReco,"All Ranges","P");
    leg4->AddEntry(hAjReco_0_20,"Very Central (0 - 20%)","P");
    leg4->AddEntry(hAjReco_20_50,"Mid Centrality (20 - 50%)","P");
    leg4->AddEntry(hAjReco_50_100,"Peripheral (50 - 100%)","P");
    leg4->Draw();

    TCanvas* can4 = new TCanvas("can4","",1200,600);
    can4->Divide(2,1,0,0);
   
   can4->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hXjTruth,"X_{j}","Share  of Centrality Range",1);
    
    hXjTruth->GetXaxis()->SetRangeUser(0,1.05);
    hXjTruth->SetTitle("Truth X_{j} Values of Various Centrality Ranges");
    hXjTruth->GetYaxis()->SetRangeUser(0,0.075);
    hXjTruth->Draw();
    hXjTruth->SetMarkerColor(1);
    hXjTruth->SetMarkerStyle(20);
    hXjTruth_0_20->SetMarkerColor(2);
    hXjTruth_0_20->SetMarkerStyle(21);
    hXjTruth_0_20->Draw("same");
    hXjTruth_20_50->SetMarkerColor(4);
    hXjTruth_20_50->SetMarkerStyle(29);
    hXjTruth_20_50->Draw("same");
    hXjTruth_50_100->SetMarkerColor(6);
    hXjTruth_50_100->SetMarkerStyle(23);  
    hXjTruth_50_100->Draw("same");
    
    TLegend* leg5 = new TLegend(0.2,0.7,0.35,0.85);
    SetLeg(leg5);
    leg5->AddEntry(hXjTruth,"All Ranges","P");
    leg5->AddEntry(hAjTruth_0_20,"Very Central (0 - 20%)","P");
    leg5->AddEntry(hAjTruth_20_50,"Mid Centrality (20 - 50%)","P");
    leg5->AddEntry(hXjTruth_50_100,"Peripheral (50 - 100%)","P");
    leg5->Draw();

    can4->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
 
    hXjReco_0_20->SetTitle("Reconstructed X_{j} Values of Various Centrality Ranges");
    hXjReco_0_20->GetYaxis()->SetRangeUser(0,0.040);
    hXjReco_0_20->SetMarkerColor(2);
    hXjReco_0_20->SetMarkerStyle(25);
    hXjReco_0_20->Draw();
    hXjReco->Draw("same");
    hXjReco->SetMarkerColor(1);
    hXjReco->SetMarkerStyle(24);
    hXjReco_0_20->SetMarkerColor(2);
    hXjReco_0_20->SetMarkerStyle(25);
    hXjReco_0_20->Draw("same");
    hXjReco_20_50->SetMarkerColor(4);
    hXjReco_20_50->SetMarkerStyle(30);
    hXjReco_20_50->Draw("same");
    hXjReco_50_100->SetMarkerColor(6);
    hXjReco_50_100->SetMarkerStyle(32);  
    hXjReco_50_100->Draw("same");
    
    TLegend* leg6 = new TLegend(0.4,0.2,0.55,0.35);
    SetLeg(leg6);
    leg6->AddEntry(hXjReco,"All Ranges","P");
    leg6->AddEntry(hXjReco_0_20,"Very Central (0 - 20%)","P");
    leg6->AddEntry(hXjReco_20_50,"Mid Centrality (20 - 50%)","P");
    leg6->AddEntry(hXjReco_50_100,"Peripheral (50 - 100%)","P");
    leg6->Draw(); 
   
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
