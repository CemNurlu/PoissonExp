{
  TH1F *histo = new TH1F("histo","Barium 10s",10, 10, 35);

  std::ifstream file("data/Barium 10s.txt");
  float datum;
  while (file>>datum ) histo->Fill(datum);
  histo->Draw();




// Calculate the current mean of the histogram
float mean = histo->GetMean();
float stddev = histo->GetStdDev();

// Print the mean and standard deviation to the standard output
std::cout << "Mean: " << mean << std::endl;
std::cout << "Standard deviation: " << stddev << std::endl;

// Draw the histogram
histo->Draw("SAME");

TF1 *gausFit = new TF1("gausFit", "[0]*TMath::Gaus(x,[1],[2])", 10, 35);
gausFit -> SetLineColor(kBlue);

gausFit -> SetParameters(18, 22, 5);
histo -> Fit("gausFit", "R");
float cBa1Gaus = gausFit -> GetChisquare();
float nBa1Gaus = gausFit -> GetNDF();

TF1 *poissonFit = new TF1("poissonFit", "[0]*TMath::Poisson(x,[1])", 10, 35);
poissonFit -> SetParameters(18, 22);
poissonFit -> SetLineColor(kRed);
histo -> Fit("poissonFit", "R+");
float cBa1Poi = poissonFit -> GetChisquare();
float nBa1Poi = poissonFit -> GetNDF();


float cp = poissonFit -> GetChisquare();
float np = poissonFit -> GetNDF();
float cg = gausFit -> GetChisquare();
float ng = gausFit -> GetNDF();
std::cout << "Chi1: " << (cg/ng) << std::endl;
std::cout << "Chi2: " << (cp/np) << std::endl;



}
