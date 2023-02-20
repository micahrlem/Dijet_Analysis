void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH2* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void DrawScaleRes2D(string infile = "scaleres2D_jetsMedium0to55.root"){
    
   
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH2*  ScaleResEta = (TH2*)gROOT->FindObject("ScaleResEta");
    TH2*  ScaleResPhi = (TH2*)gROOT->FindObject("ScaleResPhi");
    TCanvas* can1 = new TCanvas("can1","",1000,1000);
    can1->Divide(2,2,0,0);

    can1->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResEta,"Truth Eta","(Reco Eta - Truth Eta)/Truth Eta",1);
    ScaleResEta->SetTitle("Eta");
    ScaleResEta->Draw("ColZ");
    
    TProfile* SREP = ScaleResEta->ProfileX("Eta Statistics");
    
    gStyle->SetTitleTextColor(1);

    can1->cd(3);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SREP->SetTitle("Eta");
    SREP->GetYaxis()->SetTitle("Mean");
    SREP->GetXaxis()->SetTitle("Eta");
    SREP->Draw("");
    
    
    can1->cd(2);
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPhi,"Truth Phi","(Reco Phi - Truth Phi)/Truth Phi",2);
    ScaleResPhi->SetTitle("Phi");
    ScaleResPhi->Draw("ColZ"); 

    TProfile* SRPP = ScaleResPhi->ProfileX("Phi Statistics");
    gStyle->SetTitleTextColor(1);




    can1->cd(4);
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPP->GetYaxis()->SetTitle("Mean");
    SRPP->GetXaxis()->SetTitle("Phi");
    SRPP->SetTitle("Phi");
    SRPP->Draw("");




      
}


void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 24,int width = 3, float size = 1.0)
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

void SetHist(TH2* h, int color = 4)
{
    h->SetLineWidth(3);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(0.25);
    h->GetYaxis()->SetTitleOffset(1.6);
    
}


void SetLeg(TLegend* l,float txtsize=0.04){
    l->SetBorderSize(1);
    l->SetFillColor(1);
    l->SetTextSize(txtsize);
}