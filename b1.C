{
  TH1F *histo = new TH1F("histo","Barium 1s",10, 0, 10);

  std::ifstream file("data/Barium 1s.txt");
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

TF1 *gausFit = new TF1("gausFit", "[0]*TMath::Gaus(x,[1],[2])", 0, 10);
gausFit -> SetLineColor(kBlue);

gausFit -> SetParameters(30, 2.2, 1.4);
histo -> Fit("gausFit", "R");
float cBa1Gaus = gausFit -> GetChisquare();
float nBa1Gaus = gausFit -> GetNDF();

TF1 *poissonFit = new TF1("poissonFit", "[0]*TMath::Poisson(x,[1])", 0, 10);
poissonFit -> SetParameters(30, 2.24);
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
