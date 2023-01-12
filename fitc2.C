// Example multi-fitting macro written for ROOT
{
   // Defining a Canvas
   // If not defined, the plot will be drawn on the previous canvas on each execution
   TCanvas *c1 = new TCanvas();
   c1->SetWindowSize(1400, 900);



   // Defining the graph object with error bars. Read from a txt file. Set it to your directory
   TGraphErrors *mygraph = new TGraphErrors("Cesium 10s.txt");
   // Setting the title of the graph
   mygraph->SetTitle("Multi-fitting Example");
   // Drawing the graph
   mygraph->Draw("A*");


   // Defining a gaussian function in a given range
   TF1 *gauss_fit = new TF1("gauss_fit","[0]*TMath::Gaus(x,[1],[2])",80,130);
   // Starting parameters for the search of [0], [1] and [2].
   // Choices here are sometimes important for optimization.
   // Try (150, 10, 2) instead of (150,100,20)
   gauss_fit->SetParameters(150,100,20);
   // Cosmetics
   gauss_fit->SetLineColor(kGreen);
   gauss_fit->SetLineWidth(5);
   // Fitting to "mygraph" object in the "given range" defined in gauss_fit
   // Try deleting "R"
   mygraph->Fit(gauss_fit,"R");



   // Defining and fitting an exponential function in a given range
   TF1 *expo_fit = new TF1("expo_fit","[0]*exp([1]*x)",0,60);
   expo_fit->SetParameters(100,-0.02);
   expo_fit->SetLineColor(kRed);
   expo_fit->SetLineWidth(5);
   // Fitting and plotting on the same graph with the previous fit requires "R+" option
   // Try deleting the plus sign
   mygraph->Fit(expo_fit,"R+");


   // Defining and just "drawing" a gaussian function with known parameters in a given range
   TF1 *gauss_draw = new TF1("gauss_draw","95*TMath::Gaus(x,153,15)",145,175);
   gauss_draw->SetLineColor(kBlue);
   gauss_draw->SetLineWidth(5);
   // For Draw, "same" is needed to draw on the existing graph.
   gauss_draw->Draw("same");



}
