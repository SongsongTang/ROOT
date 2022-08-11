#include <fstream>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>

TH1F* hist(const char* fileName, const char* histName, int nBins, double min, double max, Color_t fillColor=0, Style_t fillStyle=0, Color_t lineColor=1, Style_t lineStyle=1)
{
    std::ifstream inFile;
    inFile.open(fileName);
    TH1F* hist = new TH1F(histName, histName, nBins, min, max);
    double x;
    while (inFile >> x)
    {
        hist->Fill(x);
    }
    hist->SetFillColor(fillColor);
    hist->SetFillStyle(fillStyle);
    hist->SetLineColor(lineColor);
    hist->SetLineStyle(lineStyle);
    hist->Scale(1./hist->Integral());
    hist->SetTitle("");
    hist->SetStats(0);
    inFile.close();
    return hist;
}
