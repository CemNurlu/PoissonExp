{
  float canvasMultiplier = .5;
  TCanvas *canvas = new TCanvas("myCanvas","myCanvas", 1920 * canvasMultiplier,1080 * canvasMultiplier);
  TH1F *histogram = new TH1F("histogram","n = 0",10, 0, 50);
  histogram -> GetXaxis() -> SetTitle("Time Gap (mm)");
  histogram -> GetYaxis() -> SetTitle("Count");
  std::ifstream file("data/tdelta1.txt");

  int datum;
  while (file >> datum) histogram->Fill(datum);
  float mean = histogram -> GetMean();
  float std = histogram -> GetStdDev();
  TF1 *gausFit = new TF1("gausFit", "[0]*TMath::Gaus(x,[1],[2])", 0, 50);
  gausFit -> SetParameters(35, mean, std);
  gausFit -> SetLineColor(kBlue);
  histogram -> Fit("gausFit", "R");
  float c0Gaus = gausFit -> GetChisquare();
  float n0Gaus = gausFit -> GetNDF();
  TF1 *poissonFit = new TF1("poissonFit", "[0]*TMath::Poisson(x,[1])", 0, 50);
  poissonFit -> SetParameters(35, mean);
  poissonFit -> SetLineColor(kRed);
  histogram -> Fit("poissonFit", "R+");
  float c0Poi = poissonFit -> GetChisquare();
  float n0Poi = poissonFit -> GetNDF();
  histogram -> SetFillColor(kBlack);
  histogram -> Draw();
  canvas -> Draw();

  float cp = poissonFit -> GetChisquare();
  float np = poissonFit -> GetNDF();
  float cg = gausFit -> GetChisquare();
  float ng = gausFit -> GetNDF();
  std::cout << "Chi1: " << (cg/ng) << std::endl;
  std::cout << "Chi2: " << (cp/np) << std::endl;


}
