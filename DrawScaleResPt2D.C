void SetHist(TH2* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH2* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void DrawScaleResPt2D(string infile = "scaleres2D_jetsMedium0to55.root"){
    
   
    TFile *_file0 = TFile::Open(infile.c_str());
    
    TH2*  ScaleResPt = (TH2*)gROOT->FindObject("ScaleResPt");
    TCanvas* can2 = new TCanvas("can2","",1200,600);
    can2->Divide(2,1,0,0);

    can2->cd(1);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.10);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.10);
    SetHist(ScaleResPt,"Truth Pt","(Reco Pt - Truth Pt)/Truth Pt",1);
    ScaleResPt->SetTitle("Pt");
    ScaleResPt->Draw("ColZ");
    
    TProfile* SRPTP = ScaleResPt->ProfileX("Statistics");
    
    gStyle->SetTitleTextColor(1);





    can2->cd(2);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(.03);
    gPad->SetTopMargin(.07);
    gPad->SetBottomMargin(.12);
    SRPTP->GetYaxis()->SetTitle("Mean");
    SRPTP->GetXaxis()->SetTitle("Pt");
    SRPTP->SetTitle("Profile");
    SRPTP->Draw("");
    




      
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