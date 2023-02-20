void SetHist(TH1* h, string xt ="", string yt ="",int color = 4, int marker = 20,int width = 3, float size = 1.0);
void SetHist(TH1* h, int color = 4);
void SetLeg(TLegend* l,float txtsize=0.03);


void DrawEfficiencyMultiple(string infile = "efficiency_G4sPHENIX_g4jet_eval.root")