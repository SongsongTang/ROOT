#include <fstream>
#include <string>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>

TH1F* hist(std::string fileName, std::string histName, int nBins, double min, double max, Color_t fillColor, Style_t fillStyle, Color_t lineColor, Style_t lineStyle)
{
    std::ifstream inFile;
    inFile.open(fileName);
    TH1F* hist = new TH1F(histName.c_str(), histName.c_str(), nBins, min, max);
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
