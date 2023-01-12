{

  float means[4] = {2.24, 22.4, 10.0588, 102.535};
  float stds[4] = {1.45685, 4.91935, 2.80344, 8.97506};
  float data[4];
  for(int i = 0; i < 4; i++){
  data[i] = TMath::Sqrt(means[i]) / stds[i];
  }


  TGraph *myGraph = new TGraph(4, means, data);
  myGraph -> SetTitle("#sqrt{#mu}/ #sigma vs. #mu");
  myGraph -> GetXaxis() -> SetTitle("#mu");
  myGraph -> GetYaxis() -> SetTitle("#sqrt{#mu}/#sigma");
  myGraph -> Draw("A*");












}
