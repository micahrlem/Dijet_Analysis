void SetHist(TH1* h, string xt ="", string yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 1);
void SetLeg(TLegend* l,float txtsize=0.03);

void Draw_Aj_Xj(string infile0 = "Aj_MDC2wCentJets.root"){
    
    //gStyle->SetOptStat(0);

    
    TFile *_file0 = TFile::Open(infile0.c_str());
    
    TH1* hAjTruth = (TH1*)gROOT->FindObject("hAjTruth");
    TH1* hAjReco = (TH1*)gROOT->FindObject("hAjReco");
    TH1* hXjTruth = (TH1*)gROOT->FindObject("hXjTruth");
    TH1* hXjReco = (TH1*)gROOT->FindObject("hXjReco");


    TH1* hAjTruthLow = (TH1*)gROOT->FindObject("hAjTruthLow");
    TH1* hAjRecoLow = (TH1*)gROOT->FindObject("hAjRecoLow");
    TH1* hXjTruthLow = (TH1*)gROOT->FindObject("hXjTruthLow");
    TH1* hXjRecoLow = (TH1*)gROOT->FindObject("hXjRecoLow");


    TH1* hAjTruthMid = (TH1*)gROOT->FindObject("hAjTruthMid");
    TH1* hAjRecoMid = (TH1*)gROOT->FindObject("hAjRecoMid");
    TH1* hXjTruthMid = (TH1*)gROOT->FindObject("hXjTruthMid");
    TH1* hXjRecoMid = (TH1*)gROOT->FindObject("hXjRecoMid");

    TH1* hAjTruthHigh = (TH1*)gROOT->FindObject("hAjTruthHigh");
    TH1* hAjRecoHigh = (TH1*)gROOT->FindObject("hAjRecoHigh");
    TH1* hXjTruthHigh = (TH1*)gROOT->FindObject("hXjTruthHigh");
    TH1* hXjRecoHigh = (TH1*)gROOT->FindObject("hXjRecoHigh");

    TH1* hAjTruthLowCent = (TH1*)gROOT->FindObject("hAjTruthLowCent");
    TH1* hAjRecoLowCent = (TH1*)gROOT->FindObject("hAjRecoLowCent");
    TH1* hXjTruthLowCent = (TH1*)gROOT->FindObject("hXjTruthLowCent");
    TH1* hXjRecoLowCent = (TH1*)gROOT->FindObject("hXjRecoLowCent");


    TH1* hAjTruthMidCent = (TH1*)gROOT->FindObject("hAjTruthMidCent");
    TH1* hAjRecoMidCent = (TH1*)gROOT->FindObject("hAjRecoMidCent");
    TH1* hXjTruthMidCent = (TH1*)gROOT->FindObject("hXjTruthMidCent");
    TH1* hXjRecoMidCent = (TH1*)gROOT->FindObject("hXjRecoMidCent");

    TH1* hAjTruthHighCent = (TH1*)gROOT->FindObject("hAjTruthHighCent");
    TH1* hAjRecoHighCent = (TH1*)gROOT->FindObject("hAjRecoHighCent");
    TH1* hXjTruthHighCent = (TH1*)gROOT->FindObject("hXjTruthHighCent");
    TH1* hXjRecoHighCent = (TH1*)gROOT->FindObject("hXjRecoHighCent");

    TH1* hAjTruthMinusRecoCent = (TH1*)gROOT->FindObject("hAjTruthMinusRecoCent");
    TH1* hAjTruthMinusRecoLowCent = (TH1*)gROOT->FindObject("hAjTruthMinusRecoLowCent");
    TH1* hAjTruthMinusRecoMidCent = (TH1*)gROOT->FindObject("hAjTruthMinusRecoMidCent");
    TH1* hAjTruthMinusRecoHighCent = (TH1*)gROOT->FindObject("hAjTruthMinusRecoHighCent");
    TH1* hXjTruthMinusRecoCent = (TH1*)gROOT->FindObject("hXjTruthMinusRecoCent");
    TH1* hXjTruthMinusRecoLowCent = (TH1*)gROOT->FindObject("hXjTruthMinusRecoLowCent");
    TH1* hXjTruthMinusRecoMidCent = (TH1*)gROOT->FindObject("hXjTruthMinusRecoMidCent");
    TH1* hXjTruthMinusRecoHighCent = (TH1*)gROOT->FindObject("hXjTruthMinusRecoHighCent");

    //TH2* AjTruthvsReco = (TH2*)gROOT->FindObject("AjTruthvsReco");

    
    TCanvas* can1 = new TCanvas("can1","",1200,600);
    can1->Divide(2,1,0,0);

    can1->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruth,"A_{J}","Event Fraction",4);
    SetHist(hAjReco,"A_{J}","Event Fraction",2);
    hAjTruth->SetTitle("A_{j}");
    
    hAjTruth->Draw("E1");
    hAjTruth->SetMarkerColor(4);
    hAjReco->Draw("E1 same");
    hAjReco->SetLineStyle(7);
    
    TLegend* leg1 = new TLegend(0.42,0.7,0.85,0.85);
    SetLeg(leg1);
    leg1->SetHeader("p_{T} leading > 30 GeV/c  p_{T} subleading > 10 GeV/c" );
    leg1->AddEntry(hAjTruth,"Truth","P");
    leg1->AddEntry(hAjReco,"Reco","P");
    leg1->Draw();

    can1->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hXjTruth,"X_{J}","Event Fraction",4);
    SetHist(hXjReco,"X_{J}","Event Fraction",2);
    hXjTruth->SetTitle("X_{j}");
    
    hXjTruth->Draw("E1");
    hXjTruth->SetMarkerColor(4);
    hXjReco->Draw("E1 same");
    hXjReco->SetLineStyle(7);

    TLegend* leg2 = new TLegend(0.20,0.65,0.40,0.85);
    SetLeg(leg2);
    leg2->AddEntry((TObject*)0,"p_{T} leading > 30 GeV/c","" );
    leg2->AddEntry((TObject*)0,"p_{T} subleading > 10 GeV/c",""); 
    leg2->AddEntry(hXjTruth,"Truth","P");
    leg2->AddEntry(hXjReco,"Reco","P");
    leg2->Draw();
    
  
    TCanvas* can2 = new TCanvas("can2","",1600,1600);
    can2-> Divide(2,2,0,0);

    can2->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruthLow,"A_{J}","Event Fraction",1);
    SetHist(hAjTruthMid,"A_{J}","Event Fraction",2);
    SetHist(hAjTruthHigh,"A_{J}","Event Fraction",4);
    
    hAjTruthHigh->Draw("E1 same");
    hAjTruthLow->Draw("E1 same");
    hAjTruthMid->Draw("E1 same");
    hAjTruthHigh->SetTitle("A_{j} Truth p_{T} comparison");

    hAjTruthLow->SetMarkerStyle(33);
    hAjTruthMid->SetMarkerStyle(29);
    hAjTruthHigh->SetMarkerStyle(22);
    

    TLegend* leg3 = new TLegend(0.42,0.7,0.85,0.85);
    SetLeg(leg3);
    leg3->AddEntry(hAjTruthLow,"Low (30 Gev/C < p_{T} < 32.5 Gev/C)","P");
    leg3->AddEntry(hAjTruthMid,"Mid (32.5 Gev/C < p_{T} < 35 Gev/C)","P");
    leg3->AddEntry(hAjTruthHigh,"High (35 Gev/C < p_{T})","P");
    leg3->Draw();
   

    can2->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hXjTruthLow,"X_{J}","Event Fraction",1);
    SetHist(hXjTruthMid,"X_{J}","Event Fraction",2);
    SetHist(hXjTruthHigh,"X_{J}","Event Fraction",4);


    hXjTruthHigh->Draw("E1 same");
    hXjTruthLow->Draw("E1 same");
    hXjTruthMid->Draw("E1 same");
    hXjTruthHigh->SetTitle("X_{j} Truth p_{T} comparison");

    hXjTruthLow->SetMarkerStyle(33);
    hXjTruthMid->SetMarkerStyle(29);
    hXjTruthHigh->SetMarkerStyle(22);
    

    TLegend* leg4 = new TLegend(0.20,0.65,0.40,0.85);
    SetLeg(leg4);
    leg4->AddEntry(hXjTruthLow,"Low (30 Gev/C < p_{T} < 32.5 Gev/C) ","P");
    leg4->AddEntry(hXjTruthMid,"Mid (32.5 Gev/C < p_{T} < 35 Gev/C)","P");
    leg4->AddEntry(hXjTruthHigh,"High (35 Gev/C < p_{T})","P");
    leg4->Draw();
   
   can2->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjRecoLow,"A_{J}","Event Fraction",1);
    SetHist(hAjRecoMid,"A_{J}","Event Fraction",2);
    SetHist(hAjRecoHigh,"A_{J}","Event Fraction",4);
    
    hAjRecoMid->Draw("E1 same");
    hAjRecoHigh->Draw("E1 same");
    hAjRecoLow->Draw("E1 same");
    hAjRecoMid->SetTitle("A_{j} Reconstructed p_{T} comparison");

    hAjRecoLow->SetMarkerStyle(33);
    hAjRecoMid->SetMarkerStyle(29);
    hAjRecoHigh->SetMarkerStyle(22);
    

    TLegend* leg5 = new TLegend(0.6,0.7,0.85,0.85);
    SetLeg(leg5);
    leg5->AddEntry(hAjRecoLow,"Low (30 Gev/C < p_{T} < 32.5 Gev/C)","P");
    leg5->AddEntry(hAjRecoMid,"Mid (32.5 Gev/C < p_{T} < 35 Gev/C)","P");
    leg5->AddEntry(hAjRecoHigh,"High (35 Gev/C < p_{T})","P");
    leg5->Draw();


  can2->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hXjRecoLow,"X_{J}","Event Fraction",1);
    SetHist(hXjRecoMid,"X_{J}","Event Fraction",2);
    SetHist(hXjRecoHigh,"X_{J}","Event Fraction",4);


    hXjRecoHigh->Draw("E1 same");
    hXjRecoLow->Draw("E1 same");
    hXjRecoMid->Draw("E1 same");
    hXjRecoHigh->SetTitle("X_{j} Reconstructed p_{T} comparison");

    hXjRecoLow->SetMarkerStyle(33);
    hXjRecoMid->SetMarkerStyle(29);
    hXjRecoHigh->SetMarkerStyle(22);


    

    TLegend* leg6 = new TLegend(0.20,0.65,0.40,0.85);
    SetLeg(leg6);
    leg6->AddEntry(hXjRecoLow,"Low (30 Gev/C < p_{T} < 32.5 Gev/C)","P");
    leg6->AddEntry(hXjRecoMid,"Mid (32.5 Gev/C < p_{T} < 35 Gev/C)","P");
    leg6->AddEntry(hXjRecoHigh,"High (35 Gev/C < p_{T})","P");
    leg6->Draw();





TCanvas* can3 = new TCanvas("can3","",1600,1600);
    can3-> Divide(2,2,0,0);

    can3->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruthLowCent,"A_{J}","Event Fraction",1);
    SetHist(hAjTruthMidCent,"A_{J}","Event Fraction",2);
    SetHist(hAjTruthHighCent,"A_{J}","Event Fraction",4);
    
    hAjTruthHighCent->Draw("E1 same");
    hAjTruthLowCent->Draw("E1 same");
    hAjTruthMidCent->Draw("E1 same");
    hAjTruthHighCent->SetTitle("A_{j} Truth Centrality Bins");

    hAjTruthLowCent->SetMarkerStyle(33);
    hAjTruthMidCent->SetMarkerStyle(29);
    hAjTruthHighCent->SetMarkerStyle(22);
    

    TLegend* leg7 = new TLegend(0.6,0.7,0.85,0.85);
    SetLeg(leg7);
    leg7->AddEntry(hAjTruthLowCent,"Peripheral (50 - 100%)","P");
    leg7->AddEntry(hAjTruthMidCent,"Mid Centrality (20 - 50%)","P");
    leg7->AddEntry(hAjTruthHighCent,"Central (0 - 20%) ","P");
    leg7->Draw();
   

    can3->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hXjTruthLowCent,"X_{J}","Event Fraction",1);
    SetHist(hXjTruthMidCent,"X_{J}","Event Fraction",2);
    SetHist(hXjTruthHighCent,"X_{J}","Event Fraction",4);

    hXjTruthHighCent->Draw("E1 same");
    hXjTruthMidCent->Draw("E1 same");
    hXjTruthLowCent->Draw("E1 same");
    hXjTruthHighCent->SetTitle("X_{j} Truth Centrality Bins");

    hXjTruthLowCent->SetMarkerStyle(33);
    hXjTruthMidCent->SetMarkerStyle(29);
    hXjTruthHighCent->SetMarkerStyle(22);
    

    TLegend* leg8 = new TLegend(0.20,0.65,0.40,0.85);
    SetLeg(leg8);
    leg8->AddEntry(hXjTruthLowCent,"Peripheral (50 - 100%)","P");
    leg8->AddEntry(hXjTruthMidCent,"Mid Centrality (20 - 50%)","P");
    leg8->AddEntry(hXjTruthHighCent,"Central (0 - 20%) ","P");
    leg8->Draw();
   
   can3->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjRecoLowCent,"A_{J}","Event Fraction",1);
    SetHist(hAjRecoMidCent,"A_{J}","Event Fraction",2);
    SetHist(hAjRecoHighCent,"A_{J}","Event Fraction",4);
    
    hAjRecoLowCent->Draw("E1 same");
    hAjRecoHighCent->Draw("E1 same");
    hAjRecoMidCent->Draw("E1 same");
    hAjRecoLowCent->SetTitle("A_{j} Reconstructed Centrality Bins");

    hAjRecoLowCent->SetMarkerStyle(33);
    hAjRecoMidCent->SetMarkerStyle(29);
    hAjRecoHighCent->SetMarkerStyle(22);
    

    TLegend* leg9 = new TLegend(0.6,0.7,0.85,0.85);
    SetLeg(leg9);
    leg9->AddEntry(hAjRecoLowCent,"Peripheral (50 - 100%)","P");
    leg9->AddEntry(hAjRecoMidCent,"Mid Centrality (20 - 50%)","P");
    leg9->AddEntry(hAjRecoHighCent,"Central (0 - 20%) ","P");
    leg9->Draw();


  can3->cd(4);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hXjRecoLowCent,"X_{J}","Event Fraction",1);
    SetHist(hXjRecoMidCent,"X_{J}","Event Fraction",2);
    SetHist(hXjRecoHighCent,"X_{J}","Event Fraction",4);


    hXjRecoLowCent->Draw("E1 same");
    hXjRecoHighCent->Draw("E1 same");
    hXjRecoMidCent->Draw("E1 same");

    hXjRecoLowCent->SetMarkerStyle(33);
    hXjRecoMidCent->SetMarkerStyle(29);
    hXjRecoHighCent->SetMarkerStyle(22);
    hXjRecoLowCent->SetTitle("X_{j} Reconstructed Centrality Bins");
    

    TLegend* leg10 = new TLegend(0.20,0.65,0.40,0.85);
    SetLeg(leg10);
    leg10->AddEntry(hXjRecoLowCent,"Peripheral (50 - 100%)","P");
    leg10->AddEntry(hXjRecoMidCent,"Mid Centrality (20 - 50%)","P");
    leg10->AddEntry(hXjRecoHighCent,"Central (0 - 20%) ","P");
    leg10->Draw();


    TCanvas* can4 = new TCanvas("can4","",1600,800);
    can4-> Divide(2,1,0,0);

    can4->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(hAjTruthMinusRecoCent, "A_{j, truth} - A_{j, reco}", "Event Fraction", 6);
    SetHist(hAjTruthMinusRecoLowCent,"A_{j, truth} - A_{j, reco}","Event Fraction",1);
    SetHist(hAjTruthMinusRecoMidCent,"A_{j, truth} - A_{j, reco}","Event Fraction",2);
    SetHist(hAjTruthMinusRecoHighCent,"A_{j, truth} - A_{j, reco}","Event Fraction",4);
    
    hAjTruthMinusRecoLowCent->SetTitle("A_{j} Truth Minus Reconstructed");

    hAjTruthMinusRecoLowCent->Draw("E1 same");
    hAjTruthMinusRecoMidCent->Draw("E1 same");
    hAjTruthMinusRecoHighCent->Draw("E1 same");
    hAjTruthMinusRecoCent->Draw("E1 same");

    hAjTruthMinusRecoLowCent->SetMarkerStyle(33);
    hAjTruthMinusRecoMidCent->SetMarkerStyle(29);
    hAjTruthMinusRecoHighCent->SetMarkerStyle(22);

    
    
    
    


    TLegend* leg11 = new TLegend(0.17,0.70,0.30,0.90);
    SetLeg(leg11);
    leg11->AddEntry(hAjTruthMinusRecoCent, "Overall", "P");
    leg11->AddEntry(hAjTruthMinusRecoLowCent,"Peripheral (50 - 100%)","P");
    leg11->AddEntry(hAjTruthMinusRecoMidCent,"Mid Centrality (20 - 50%)","P");
    leg11->AddEntry(hAjTruthMinusRecoHighCent,"Central (0 - 20%) ","P");
    leg11->Draw();


    can4->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.05);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    
    SetHist(hXjTruthMinusRecoCent, "X_{j, truth} - X_{j, reco}", "Event Fraction", 6);
    SetHist(hXjTruthMinusRecoLowCent,"X_{j, truth} - X_{j, reco}","Event Fraction",1);
    SetHist(hXjTruthMinusRecoMidCent,"X_{j, truth} - X_{j, reco}","Event Fraction",2);
    SetHist(hXjTruthMinusRecoHighCent,"X_{j, truth} - X_{j, reco}","Event Fraction",4);

    hXjTruthMinusRecoLowCent->SetTitle("X_{j} Truth Minus Reconstructed");
    

   
    hXjTruthMinusRecoLowCent->Draw("E1 same");
    hXjTruthMinusRecoMidCent->Draw("E1 same");
    hXjTruthMinusRecoHighCent->Draw("E1 same");
    hXjTruthMinusRecoCent->Draw("E1 same");

    


    hXjTruthMinusRecoLowCent->SetMarkerStyle(33);
    hXjTruthMinusRecoMidCent->SetMarkerStyle(29);
    hXjTruthMinusRecoHighCent->SetMarkerStyle(22);
   
    
    


    TLegend* leg12 = new TLegend(0.17,0.70,0.35,0.90);
    SetLeg(leg12);
    leg12->AddEntry(hXjTruthMinusRecoCent, "Overall", "P");
    leg12->AddEntry(hXjTruthMinusRecoLowCent,"Peripheral (50 - 100%)","P");
    leg12->AddEntry(hXjTruthMinusRecoMidCent,"Mid Centrality (20 - 50%)","P");
    leg12->AddEntry(hXjTruthMinusRecoHighCent,"Central (0 - 20%) ","P");
    leg12->Draw();

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
