#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TKey.h>
#include <TIterator.h>
#include <TFile.h>
#include <TROOT.h>
#include <TGaxis.h>
#include <TStyle.h>
#include <TClass.h>
#include <TCanvas.h>
#include <THStack.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TString.h>
#include <TGraph.h>
#include <map>
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <TGraphAsymmErrors.h>

using namespace std;
std::map < TString, TH1*> ST;
std::map < TString, TH1*> STGH;
std::map < TString, TH1*> STantiTop;
std::map < TString, TH1*> STantiTopGH;
std::map < TString, TH1*> TT;
std::map < TString, TH1*> TTGH;
std::map < TString, TH1*> TTOther;
std::map < TString, TH1*> TTOtherGH;
std::map < TString, TH1*> WW;
std::map < TString, TH1*> WWGH;
std::map < TString, TH1*> DY10;
std::map < TString, TH1*> DY10GH;
std::map < TString, TH1*> DY50;
std::map < TString, TH1*> DY50GH;
std::map < TString, TH1*> WJ;
std::map < TString, TH1*> WJGH;
std::map < TString, TH1*> WZ;
std::map < TString, TH1*> WZGH;
std::map < TString, TH1*> ZZ;
std::map < TString, TH1*> ZZGH;
std::map < TString, TH1*> TTWJetsToLNu;
std::map < TString, TH1*> TTWJetsToLNuGH;
std::map < TString, TH1*> TTZToLLNuNu;
std::map < TString, TH1*> TTZToLLNuNuGH;
std::map < TString, TH1*> TTZToQQ;
std::map < TString, TH1*> TTZToQQGH;
std::map < TString, TH1*> TTWJetsToQQ;
std::map < TString, TH1*> TTWJetsToQQGH;

std::map < TString, TH1*> MuMu;
std::map < TString, TH1*> ElMu;
std::map < TString, TH1*> ElEl;

std::map < TString, TH1*> TThad;
std::map < TString, TH1*> TThad800;
std::map < TString, TH1*> TThad1200;
std::map < TString, TH1*> TThad2500;

std::map < TString, TH1*> WWJJ;


std::map < TString, TH1*> tW;
std::map < TString, TH1*> tbarW;
std::map < TString, TH1*> TTJSLt;
std::map < TString, TH1*> TTJSLat;

std::map < TString, TH1*> WZTo3LNu;
std::map < TString, TH1*> ZGTo2LG;
std::map < TString, TH1*> WGToLNuG;
std::map < TString, TH1*> VHToNonbb;
std::map < TString, TH1*> TTGJets;
std::map < TString, TH1*> TGJets;
std::map < TString, TH1*> WWZ;

std::map < TString, TH1*> ttHJet;
std::map < TString, TH1*> TTTT;

std::map < TString, TH1*> ZZZ;
std::map < TString, TH1*> WWW;
std::map < TString, TH1*> ZZto4L;
std::map < TString, TH1*> WpWpJJ;
std::map < TString, TH1*> STtWll;


std::map < TString, TH1*> W1J;
std::map < TString, TH1*> W2J;
std::map < TString, TH1*> W3J;
std::map < TString, TH1*> W4J;



TH1F* Nevents = new TH1F("Nevents","Cut and Count",10,0,10);





std::map< TString, TH1*> hists( TString filename)
{
    TFile *file = TFile::Open(filename);
    //TDirectory *f1 = file->GetDirectory("");
    TIter keyList(file->GetListOfKeys());
    TKey *key;
    TCanvas c1;
    //THStack *hs = new THStack("hs","");
    //    c1.Print(filename +".pdf[");
    std::map< TString, TH1*> histmap;
    std::map<TString, TH2*> h2map;
    while ((key = (TKey*)keyList()))
    {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        //cout << key->GetName()<<endl;
        //        if (!cl->InheritsFrom("TH1")) continue;
        if (cl->InheritsFrom("TH1"))
        {
            TH1 *h = (TH1*)key->ReadObj();
            histmap[key->GetName()] = h;
            histmap[key->GetName()]->Draw("hist");
            c1.Draw();
        }
        else
        {
            TH2 *h2 = (TH2*)key->ReadObj();
            h2map[key->GetName()] = h2;
            h2map[key->GetName()]->Draw("colz");
            c1.Draw();

        }
        //        c1.Print(filename +".pdf");

    }
    //    c1.Print(filename+".pdf]");
    return histmap;

}
int main(int argc, char *argv[])
{
    // Global decoration settings
    //gStyle->SetErrorX(0.);
    gStyle->SetHistMinimumZero(kTRUE);
    gStyle->SetOptStat(0);
    gStyle->SetStripDecimals(kFALSE);

    TGaxis::SetMaxDigits(3);
    TFile* histograms = new TFile("histograms.root","RECREATE");
    float bin = 1.;
    if(argc != 0)
    {
        cout << argv[0] << endl;
        bin = atof (argv[1]);
        cout << bin << endl;
    }
    bool AprilFools = false;

    
    MuMu = hists("../data_h.root");
    ElMu = hists("../data_h.root");
    ElEl = hists("../data_h.root");
    TT = hists("../TT.root");
    STantiTop = hists("../STantiTop.root");
    ST = hists("../ST.root");
    WW = hists("../WW.root");
    WJ = hists("../WJets.root");
    WZ = hists("../WZ.root");
    ZZ = hists("../ZZ.root");
    DY10 = hists("../DY10.root");
    DY50 = hists("../DY50.root");
    TTZToLLNuNu = hists("../TTZToLLNuNu.root");
    TTWJetsToLNu = hists("../TTWJetsToLNu.root");
    TTWJetsToQQ = hists("../TTWJetsToQQ.root");
    TTZToQQ = hists("../TTZToQQ.root");
    TTOther = hists("../TTOther.root");
    TTOtherGH = hists("../TTOtherGH.root");
    TTGH = hists("../TTGH.root");
    STantiTopGH = hists("../STantiTopGH.root");
    STGH = hists("../STGH.root");
    WWGH = hists("../WWGH.root");
    WJGH = hists("../WJetsGH.root");
    WZGH = hists("../WZGH.root");
    ZZGH = hists("../ZZGH.root");
    DY10GH = hists("../DY10GH.root");
    DY50GH = hists("../DY50GH.root");
    TTZToLLNuNuGH = hists("../TTZToLLNuNuGH.root");
    TTWJetsToLNuGH = hists("../TTWJetsToLNuGH.root");
    TTWJetsToQQGH = hists("../TTWJetsToQQGH.root");
    TTZToQQGH = hists("../TTZToQQGH.root");
    float sigTT = 831.76;//pb

    float sigST = 35.85;

    float sigWW = 118.7;


    float sigWJ = 61526.7;


    float sigWZ = 47.13;

    float sigZZ =  16.523;


    double SF_DY = 1;

    float sigDY10 = 22635.1*SF_DY;

    float sigDY50 = 6025.2*SF_DY;

    //int N_TTZToLLNuNu=1992438;
    float sig_TTZToLLNuNu=0.2529;

    float sig_TTWJetsToLNu=0.2043;

    float sig_TTWJetsToQQ=0.4062;

    float sig_TTZToQQ=0.5297;


    TFile *file = TFile::Open("../data_h.root");
    //TDirectory *f1 = file->GetDirectory("Whelicity");
    TIter keyList(file->GetListOfKeys());
    TKey *key;
    double const bottomSpacing =  0.2;
    double const pad1Width = 0.85;
    double const margin = 0.1;
    TCanvas *c1 = new TCanvas("c1","c", 1500, 1000 / (1. - bottomSpacing));
    TLegend *leg = new TLegend(0.86,0.6,0.99, 0.9);

    leg->SetFillColor(kWhite);
    leg->SetTextFont(42);
    leg->SetTextSize(0.03);
    //     key = (TKey*)keyList();
    //     c1->cd();
    //     ST["h_cosMuMu"]->Draw();
    std::map<TString, THStack*> hs;
    // TT.begin()->second()->SetFillColor(kRed);
    //     TT.begin()->second->Draw();
    //float bin = 1.;
    float lumi =0;

    //     float lumiMuMu =  2499.686 + 4424.497 + 4251.947 +7831.899 ; //total delivered
    //    float lumiMuMu = 2395.577 + 4255.520 + 4050.476 + 3105.456 +7544.016; //total recoded
    float lumiMuMu = 35900;

    float lumiElMu = 35900;
    float lumiElEl2 = 2727.980+930.449+1089.355+920.211 + 2499.686 + 4424.497 + 495.610+3756.139  + 1104.866+2178.904 + 7831.746 + 8859.630 + 225.010;

    //float lumiElEl = 5672.051+2499.686+4424.497+4251.749+3283.770+7831.746+8859.630+225.010;
    float lumiElEl = 19713.032;
    float lumiElElGH = 16146.177;
    double nlofractionTTZ = .73;
    double nlofractionTTW = .76;
    //int NTT = TT["h_Nevents"]->Integral();
    double NTT = 1*77081156;//74924864.;
    //int NST = ST["h_Nevents"]->Integral();
    double NST = 1*992024.;
    //int NSTantiTop = STantiTop["h_Nevents"]->Integral();
    double  NSTantiTop = 1*998276.;
    //int NDY10 = DY10["h_Nevents"]->Integral();
    double NDY10 = 1*35291566;
    //int NDY50 = DY50["h_Nevents"]->Integral();
    double NDY50= 1*49144274;
    //int NWW = WW["h_Nevents"]->Integral();
    double NWW = 1*994012.;
    //int N_TTWJetsToLNu= 1*TTWJetsToLNu["num_events"]->Integral()*nlofraction ;
    double N_TTWJetsToLNu = 1*252908*nlofractionTTW ;
    //int N_TTWJetsToQQ= 1*TTWJetsToQQ["num_events"]->Integral()*nlofraction ;
    double N_TTWJetsToQQ= 1*833298*nlofractionTTW;
    //int N_TTZToQQ= 1*TTZToQQ["num_events"]->Integral()*nlofraction ;
    double N_TTZToQQ= 1*749400*nlofractionTTZ ;
    //int N_TTZToLLNuNu= 1*TTZToLLNuNu["num_events"]->Integral()*nlofraction ;
    double N_TTZToLLNuNu= 1*5934228*nlofractionTTZ ;
    //int NWZ = WZ["h_Nevents"]->Integral();
    double NWZ = 1*1.00000e+06;
    //int NZZ = ZZ["h_Nevents"]->Integral();
    double NZZ = 1*990064.;
    //int NWJ = WJ["h_Nevents"]->Integral();
    double NWJ = 1*2.35576e+08;

    float sigtW =35.85;
    int NtW = 992024;
    int NtbarW = 998276;
    float sigtbarW=3.806e+01;
    float sigTThad = 1.650;
    int NTThad = 14277035;
    float sigTThad800=6.736e-01;
    int NTThad800=10403610;
    float sigTThad1200=1.194e-01;
    int NTThad1200=2932983;
    float sigTThad2500=1.445e-03;
    int NTThad2500=1519815;
    float sigTTJSLt = 1.140e+02;
    int NTTJSLt = 11957043;
    float sigTTJSLat = 1.140e+02;
    int NTTJSLat = 11944041;



    float sigW1J = 9.628e+03;
    int NW1J = 45194274;
    float sigW2J = 3.164e+03;
    int NW2J = 29878415;
    float sigW3J = 9.489e+02;
    int NW3J = 19798117;
    float sigW4J = 4.950e+02;
    int NW4J = 9170576;

    float sig_WWJJ=2.662e+00;
    int N_WWJJ=467264;


    double scale =1;
    scale = 1;

    c1->Print("stack.pdf[");
    while ((key = (TKey*)keyList()))
    {
        THStack * h = new THStack("h","");
        TPad *pad1 = new TPad("pad1","pad1",0., bottomSpacing, pad1Width + margin, 1.);
        pad1->SetTicks();
        pad1->SetLeftMargin(margin / pad1->GetWNDC());
        pad1->SetRightMargin(margin / pad1->GetWNDC());
        pad1->SetBottomMargin(margin / pad1->GetHNDC());
        pad1->SetTopMargin(margin / pad1->GetHNDC());
        TPad *pad2 = new TPad("pad2", "pad2", 0., 0., pad1Width + margin,bottomSpacing + margin);
        pad2->SetTicks();
        pad2->SetGrid(0, 1);
        pad2->SetFillStyle(0);
        pad2->SetLeftMargin(margin / pad2->GetWNDC());
        pad2->SetRightMargin(margin / pad2->GetWNDC());
        pad2->SetBottomMargin(margin / pad2->GetHNDC());
        pad2->SetTopMargin(0.);
        TString s = key->GetName();
        cout << s<< endl;
        hs[s] = h;
        lumi = lumiElEl;
        float lumiGH = lumiElElGH;

        if(s.Contains("local"))continue;

        TT[s]->SetFillColor(kRed);
        TT[s]->SetLineColor(kRed);
        TT[s]->Scale((lumi*sigTT)/(NTT*scale));
        TT[s]->Rebin(bin);

        TTOther[s]->SetFillColor(kOrange+7);
        TTOther[s]->SetLineColor(kOrange+7);
        TTOther[s]->Scale((lumi*sigTT)/(NTT*scale));
        TTOther[s]->Rebin(bin);
        
        ST[s]->SetFillColor(kMagenta);
        ST[s]->SetLineColor(kMagenta);
        ST[s]->Scale((lumi*sigST)/(NST*scale));
        ST[s]->Rebin(bin);
        STantiTop[s]->SetFillColor(kMagenta);
        STantiTop[s]->SetLineColor(kMagenta);
        STantiTop[s]->Scale((lumi*sigST)/(NSTantiTop*scale));
        STantiTop[s]->Rebin(bin);
        WW[s]->SetFillColor(kWhite);
        WW[s]->SetLineColor(kWhite);
        WW[s]->Scale((lumi*sigWW)/(NWW*scale));
        WW[s]->Rebin(bin);

        DY10[s]->SetFillColor(kBlue);
        DY10[s]->SetLineColor(kBlue);
        DY10[s]->Scale((lumi*sigDY10)/(NDY10*scale));

        DY10[s]->Rebin(bin);
        DY50[s]->SetFillColor(kBlue);
        DY50[s]->SetLineColor(kBlue);
        DY50[s]->Scale((lumi*sigDY50)/(NDY50*scale));

        DY50[s]->Rebin(bin);

        WJ[s]->SetFillColor(kGreen);
        WJ[s]->SetLineColor(kGreen);
        WJ[s]->Scale((lumi*sigWJ)/(NWJ*scale));
        WJ[s]->Rebin(bin);

        WZ[s]->SetFillColor(kWhite);
        WZ[s]->SetLineColor(kWhite);
        WZ[s]->Scale((lumi*sigWZ)/(NWZ*scale));
        WZ[s]->Rebin(bin);
        ZZ[s]->SetFillColor(kWhite);
        ZZ[s]->SetLineColor(kWhite);
        ZZ[s]->Scale((lumi*sigZZ)/(NZZ*scale));
        ZZ[s]->Rebin(bin);
        TTWJetsToLNu[s]->SetFillColor(kOrange);
        TTWJetsToLNu[s]->SetLineColor(kOrange);
        TTWJetsToLNu[s]->Scale((lumi*sig_TTWJetsToLNu)/(N_TTWJetsToLNu*scale));
        TTWJetsToLNu[s]->Rebin(bin);

        TTWJetsToQQ[s]->SetFillColor(kOrange);
        TTWJetsToQQ[s]->SetLineColor(kOrange);
        TTWJetsToQQ[s]->Scale((lumi*sig_TTWJetsToQQ)/(N_TTWJetsToQQ*scale));
        TTWJetsToQQ[s]->Rebin(bin);

        TTZToQQ[s]->SetFillColor(kOrange);
        TTZToQQ[s]->SetLineColor(kOrange);
        TTZToQQ[s]->Scale((lumi*sig_TTZToQQ)/(N_TTZToQQ*scale));
        TTZToQQ[s]->Rebin(bin);

        TTZToLLNuNu[s]->SetFillColor(kOrange);
        TTZToLLNuNu[s]->SetLineColor(kOrange);
        TTZToLLNuNu[s]->Scale((lumi*sig_TTZToLLNuNu)/(N_TTZToLLNuNu*scale));
        TTZToLLNuNu[s]->Rebin(bin);

        TTGH[s]->SetFillColor(kRed);
        TTGH[s]->SetLineColor(kRed);
        TTGH[s]->Scale((lumiGH*sigTT)/(NTT*scale));
        TTGH[s]->Rebin(bin);

        TTOtherGH[s]->SetFillColor(kOrange+7);
        TTOtherGH[s]->SetLineColor(kOrange+7);
        TTOtherGH[s]->Scale((lumiGH*sigTT)/(NTT*scale));
        TTOtherGH[s]->Rebin(bin);
        
        STGH[s]->SetFillColor(kMagenta);
        STGH[s]->SetLineColor(kMagenta);
        STGH[s]->Scale((lumiGH*sigST)/(NST*scale));
        STGH[s]->Rebin(bin);
        STantiTopGH[s]->SetFillColor(kMagenta);
        STantiTopGH[s]->SetLineColor(kMagenta);
        STantiTopGH[s]->Scale((lumiGH*sigST)/(NSTantiTop*scale));
        STantiTopGH[s]->Rebin(bin);
        WWGH[s]->SetFillColor(kWhite);
        WWGH[s]->SetLineColor(kWhite);
        WWGH[s]->Scale((lumiGH*sigWW)/(NWW*scale));
        WWGH[s]->Rebin(bin);

        DY10GH[s]->SetFillColor(kBlue);
        DY10GH[s]->SetLineColor(kBlue);
        DY10GH[s]->Scale((lumiGH*sigDY10)/(NDY10*scale));

        DY10GH[s]->Rebin(bin);
        DY50GH[s]->SetFillColor(kBlue);
        DY50GH[s]->SetLineColor(kBlue);
        DY50GH[s]->Scale((lumiGH*sigDY50)/(NDY50*scale));

        DY50GH[s]->Rebin(bin);

        WJGH[s]->SetFillColor(kGreen);
        WJGH[s]->SetLineColor(kGreen);
        WJGH[s]->Scale((lumiGH*sigWJ)/(NWJ*scale));
        WJGH[s]->Rebin(bin);

        WZGH[s]->SetFillColor(kWhite);
        WZGH[s]->SetLineColor(kWhite);
        WZGH[s]->Scale((lumiGH*sigWZ)/(NWZ*scale));
        WZGH[s]->Rebin(bin);
        ZZGH[s]->SetFillColor(kWhite);
        ZZGH[s]->SetLineColor(kWhite);
        ZZGH[s]->Scale((lumiGH*sigZZ)/(NZZ*scale));
        ZZGH[s]->Rebin(bin);
        TTWJetsToLNuGH[s]->SetFillColor(kOrange);
        TTWJetsToLNuGH[s]->SetLineColor(kOrange);
        TTWJetsToLNuGH[s]->Scale((lumiGH*sig_TTWJetsToLNu)/(N_TTWJetsToLNu*scale));
        TTWJetsToLNuGH[s]->Rebin(bin);

        TTWJetsToQQGH[s]->SetFillColor(kOrange);
        TTWJetsToQQGH[s]->SetLineColor(kOrange);
        TTWJetsToQQGH[s]->Scale((lumiGH*sig_TTWJetsToQQ)/(N_TTWJetsToQQ*scale));
        TTWJetsToQQGH[s]->Rebin(bin);

        TTZToQQGH[s]->SetFillColor(kOrange);
        TTZToQQGH[s]->SetLineColor(kOrange);
        TTZToQQGH[s]->Scale((lumiGH*sig_TTZToQQ)/(N_TTZToQQ*scale));
        TTZToQQGH[s]->Rebin(bin);

        TTZToLLNuNuGH[s]->SetFillColor(kOrange);
        TTZToLLNuNuGH[s]->SetLineColor(kOrange);
        TTZToLLNuNuGH[s]->Scale((lumiGH*sig_TTZToLLNuNu)/(N_TTZToLLNuNu*scale));
        TTZToLLNuNuGH[s]->Rebin(bin);

        if(s.Contains("Vetojhgjhgjhgjhg"))
        {
            pad1->SetLogy(1);
            h->Clear();
            h->Add(DY10[s]);
            h->Add(DY50[s]);

        }
        else
        {


            h->Add(DY10[s]);
            h->Add(DY10GH[s]);
            h->Add(DY50[s]);
            h->Add(DY50GH[s]);
            h->Add(WW[s]);
            h->Add(WWGH[s]);
            h->Add(WZ[s]);
            h->Add(WZGH[s]);
            h->Add(ZZ[s]);
            h->Add(ZZGH[s]);

            h->Add(WJ[s]);
            h->Add(WJGH[s]);
            h->Add(TTWJetsToLNu[s]);
            h->Add(TTWJetsToLNuGH[s]);
            h->Add(TTWJetsToQQ[s]);
            h->Add(TTWJetsToQQGH[s]);

            h->Add(TTZToQQ[s]);
            h->Add(TTZToQQGH[s]);
            h->Add(TTZToLLNuNu[s]);
            h->Add(TTZToLLNuNuGH[s]);


            h->Add(ST[s]);
            h->Add(STGH[s]);
            h->Add(STantiTop[s]);
            h->Add(STantiTopGH[s]);
            h->Add(TTOther[s]);
            h->Add(TTOtherGH[s]);
            h->Add(TT[s]);
            h->Add(TTGH[s]);




        }
        ElEl[s]->Scale(1./scale);
        c1->cd();

        pad1->Draw();
        pad1->cd();
        double const histMax = 1.2 * max(h->GetMaximum(),ElEl[s]->GetMaximum());
        h->SetMaximum(histMax);
        //if(s.Contains("MET"))h->SetMinimum(30.);
        //if(s.Contains("num_jets"))h->SetMinimum(50.);
        //if(s.Contains("m_dilepton"))h->SetMinimum(1000.);
        //if(s.Contains("pt_lepton"))h->SetMinimum(100.);
        if(!s.Contains("PV"))pad1->SetLogy(1);
        if(s.Contains("cos") || s.Contains("top") || s.Contains("Nevents") )pad1->SetLogy(0);

        
        TH1F* MCerr =(TH1F*) h->GetStack()->Last();
        TGraphAsymmErrors* gr= new TGraphAsymmErrors(MCerr);
        gr->SetFillColor(920+3);
        gr->SetFillStyle(3004);

        //cout << gr->GetErrorY(1) << "error" << MCerr->GetBinError(1) << endl;

        h->Draw("hist");
        gr->Draw("2 same");


        c1->cd();
        if(s.Contains("pt_lepton")) h->GetXaxis()->SetTitle("p^{l}_{T} [GeV]");
        if(s.Contains("ptT")) h->GetXaxis()->SetTitle("p^{top}_{T} [GeV]");
        if(s.Contains("ptW")) h->GetXaxis()->SetTitle("p^{W}_{T} [GeV]");

        if(s.Contains("cos"))
        {
            h->GetXaxis()->SetTitle("Cos(#theta *)");
            h->GetXaxis()->SetRangeUser(-1,1.);
        }
        if(s.Contains("EtaLep")) h->GetXaxis()->SetTitle("#eta_{l}");
        if(s.Contains("yT")) h->GetXaxis()->SetTitle("y^{top}");
        if(s.Contains("yW")) h->GetXaxis()->SetTitle("y^{W}");
        if(s.Contains("MET")) h->GetXaxis()->SetTitle("MET");

        if(s.Contains("m_dilepton")) h->GetXaxis()->SetTitle("M^{l^{+}l^{-}}");
        if(s.Contains("mTT")) h->GetXaxis()->SetTitle("M^{t#bar{t}}");

        if(s.Contains("PV")) h->GetXaxis()->SetTitle("No. of good vertices");
        if(s.Contains("NBJets")) h->GetXaxis()->SetTitle("N_{b-jets}");
        if(s.Contains("num_jets")) h->GetXaxis()->SetTitle("N_{jets}");
        if(s.Contains("EtaLeading")) h->GetXaxis()->SetTitle("#eta_{Leading Jet}");
        if(s.Contains("PtLeading")) h->GetXaxis()->SetTitle("p_{T}^{Leading Jet}");

        double pi = 3.14159265359;
        stringstream stream;
        stream << fixed << setprecision(2) << (lumi+lumiGH)/1000;
        string lumiStr = stream.str();

        if(s.Contains("DiLep"))
        {
            continue;
            if(s.Contains("LeadingJet"))continue;

            string substr = (string) s;
            substr.erase(substr.end()-5,substr.end());
            cout << substr << endl;
            c1->cd();
            pad1->cd();
            TH1F *dataClone = (TH1F*)MuMu[substr+"MuMu"]->Clone();
            TString title = "#font[22]{CMS} Preliminary #mu^{+}#mu^{-} #mue e^{+}e^{-}"+ s;
            h->SetTitle(title);
            MuMu[substr+"MuMu"]->SetFillColor(kBlack);
            MuMu[substr+"MuMu"]->SetLineColor(kBlack);

            //            MuMu[substr+"MuMu"]->Rebin(bin);
            //            MuMu[s]->Draw("E same");
            MuMu[substr+"MuMu"]->SetStats(0);
            ElEl[substr+"ElEl"]->SetFillColor(kBlack);
            ElEl[substr+"ElEl"]->SetLineColor(kBlack);

            //            ElEl[substr+"ElEl"]->Rebin(bin);
            //            ElEl[s]->Draw("E same");
            ElEl[substr+"ElEl"]->SetStats(0);
            ElMu[substr+"ElMu"]->SetFillColor(kBlack);
            ElMu[substr+"ElMu"]->SetLineColor(kBlack);

            //            ElMu[substr+"ElMu"]->Rebin(bin);
            //            ElMu[s]->Draw("E same");
            ElMu[substr+"ElMu"]->SetStats(0);
            dataClone->Add(ElEl[substr+"ElEl"]);
            dataClone->Add(ElMu[substr+"ElMu"]);
            dataClone->SetFillColor(kBlack);
            dataClone->SetLineColor(kBlack);
            //            dataClone->Rebin(bin);
            dataClone->Draw("E same");
            dataClone->SetStats(0);
            leg->AddEntry(MuMu[substr+"MuMu"],"data");
            TH1F* RatioTop =(TH1F*) dataClone->Clone();
            TH1F* RatioBottom =(TH1F*) h->GetStack()->Last();
            RatioTop->Add(RatioBottom,-1);
            RatioTop->Divide(RatioBottom);
            c1->cd();

            TString const xAxisTitle = h->GetXaxis()->GetTitle();

            TString xAxisTitle2 = ";"+xAxisTitle + ";#frac{Data-MC}{MC}";

            // Reset the title of the residuals histogram. It gets axis titles only
            RatioTop->SetTitle(xAxisTitle2);


            // Decoration of the residuals histogram
            //            RatioTop->SetMinimum(-0.2);
            //            RatioTop->SetMaximum(0.2);

            RatioTop->SetMarkerStyle(20);
            RatioTop->SetLineColor(kBlack);

            TAxis *xAxis = RatioTop->GetXaxis();
            TAxis *yAxis = RatioTop->GetYaxis();

            // Make axis label and titles of same size as in the main pad (the actual text size for the
            //default font is linked up with the current pad's smallest dimension)
            xAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            xAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());

            yAxis->SetNdivisions(405);
            yAxis->CenterTitle();
            yAxis->SetTitleOffset(0.5);
            xAxis->SetTickLength(xAxis->GetTickLength() * (1. - 2. * margin - bottomSpacing) /
                                 bottomSpacing);


            // Alter the y axis so that its labels do not overlap with the ones of the stacked plot.
            //In the code "5" is the number of primary divisions
            double const tickOffset = (RatioTop->GetMaximum() - RatioTop->GetMinimum()) /
                    5 * 0.6;
            RatioTop->SetMaximum(RatioTop->GetMaximum() + tickOffset);
            pad2->Draw();
            pad2->cd();
//            TH1F* err =(TH1F*) h->GetStack()->Last();
//            //err->Scale(err->Integral());
//            TGraphAsymmErrors* ge= new TGraphAsymmErrors(err);
//            ge->SetFillColor(920+3);
//            ge->SetFillStyle(3004);
//            RatioTop->Draw("p0 e1");
//            ge->Draw("2 same");
            h->GetXaxis()->SetLabelOffset(999.);
            c1->cd();
        }

        if(s.Contains("MuMu"))
        {
            c1->cd();
            pad1->cd();
            MuMu[s]->SetFillColor(kBlack);
            MuMu[s]->SetLineColor(kBlack);

            MuMu[s]->Rebin(bin);
            MuMu[s]->Draw("E same");
            MuMu[s]->SetStats(0);
            leg->AddEntry(MuMu[s],"data");
            TString title = "#font[22]{CMS} Preliminary " + lumiStr + " fb^{-1} " + "#mu^{+}#mu^{-}" + s;
            h->SetTitle(title);
            TH1F* RatioTop =(TH1F*) MuMu[s]->Clone();
            TH1F* RatioBottom =(TH1F*) h->GetStack()->Last();
            RatioTop->Add(RatioBottom,-1);
            RatioTop->Divide(RatioBottom);
            c1->cd();

            TString const xAxisTitle = h->GetXaxis()->GetTitle();

            TString xAxisTitle2 = ";"+xAxisTitle + ";#frac{Data-MC}{MC}";

            // Reset the title of the residuals histogram. It gets axis titles only
            RatioTop->SetTitle(xAxisTitle2);



            if(s.Contains("NoVetofhsdjkfhjksdhfj"))
            {
                RatioTop->SetMinimum(0.6);
                RatioTop->SetMaximum(2.6);
            }
            else
            {
                RatioTop->SetMinimum(0.6);
                RatioTop->SetMaximum(1.6);
            }

            RatioTop->SetMarkerStyle(20);
            RatioTop->SetLineColor(kBlack);

            TAxis *xAxis = RatioTop->GetXaxis();
            TAxis *yAxis = RatioTop->GetYaxis();

            // Make axis label and titles of same size as in the main pad (the actual text size for the
            //default font is linked up with the current pad's smallest dimension)
            xAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            xAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());

            yAxis->SetNdivisions(405);
            yAxis->CenterTitle();
            yAxis->SetTitleOffset(0.5);
            xAxis->SetTickLength(xAxis->GetTickLength() * (1. - 2. * margin - bottomSpacing) /
                                 bottomSpacing);


            // Alter the y axis so that its labels do not overlap with the ones of the stacked plot.
            //In the code "5" is the number of primary divisions
            double const tickOffset = (RatioTop->GetMaximum() - RatioTop->GetMinimum()) /
                    5 * 0.6;
            RatioTop->SetMaximum(RatioTop->GetMaximum() + tickOffset);
            pad2->Draw();
            pad2->cd();
//            TH1F* err =(TH1F*) h->GetStack()->Last();
//            //err->Scale(err->Integral());
//            TGraphAsymmErrors* ge= new TGraphAsymmErrors(err);
//            ge->SetFillColor(920+3);
//            ge->SetFillStyle(3004);
//            RatioTop->Draw("p0 e1");
//            ge->Draw("2 same");
            h->GetXaxis()->SetLabelOffset(999.);
            c1->cd();
        }
        if(s.Contains("ElMu"))
        {
            c1->cd();
            pad1->cd();
            ElMu[s]->SetFillColor(kBlack);
            ElMu[s]->SetLineColor(kBlack);

            ElMu[s]->Rebin(bin);
            ElMu[s]->Draw("E same");
            ElMu[s]->SetStats(0);
            leg->AddEntry(ElMu[s],"data");
            TString title = "#font[22]{CMS} Preliminary " + lumiStr + " fb^{-1} " + "#mu e" + s;
            h->SetTitle(title);
            TH1F* RatioTop =(TH1F*) ElMu[s]->Clone();
            TH1F* RatioBottom =(TH1F*) h->GetStack()->Last();
            RatioTop->Add(RatioBottom,-1);
            RatioTop->Divide(RatioBottom);
            c1->cd();

            TString const xAxisTitle = h->GetXaxis()->GetTitle();

            TString xAxisTitle2 = ";"+xAxisTitle + ";#frac{Data-MC}{MC}";

            // Reset the title of the residuals histogram. It gets axis titles only
            RatioTop->SetTitle(xAxisTitle2);


            // Decoration of the residuals histogram
            //            RatioTop->SetMinimum(-0.2);
            //            RatioTop->SetMaximum(0.2);

            RatioTop->SetMarkerStyle(20);
            RatioTop->SetLineColor(kBlack);

            TAxis *xAxis = RatioTop->GetXaxis();
            TAxis *yAxis = RatioTop->GetYaxis();

            // Make axis label and titles of same size as in the main pad (the actual text size for the
            //default font is linked up with the current pad's smallest dimension)
            xAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            xAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());

            yAxis->SetNdivisions(405);
            yAxis->CenterTitle();
            yAxis->SetTitleOffset(0.5);
            xAxis->SetTickLength(xAxis->GetTickLength() * (1. - 2. * margin - bottomSpacing) /
                                 bottomSpacing);


            // Alter the y axis so that its labels do not overlap with the ones of the stacked plot.
            //In the code "5" is the number of primary divisions
            double const tickOffset = (RatioTop->GetMaximum() - RatioTop->GetMinimum()) /
                    5 * 0.6;
            RatioTop->SetMaximum(RatioTop->GetMaximum() + tickOffset);
            pad2->Draw();
            pad2->cd();

//            TH1F* err =(TH1F*) h->GetStack()->Last();
//            //err->Scale(err->Integral());
//            TGraphAsymmErrors* ge= new TGraphAsymmErrors(err);
//            ge->SetFillColor(920+3);
//            ge->SetFillStyle(3004);
//            RatioTop->Draw("p0 e1");
//            ge->Draw("2 same");

            h->GetXaxis()->SetLabelOffset(999.);
            c1->cd();
        }
        int i=0;
        
        c1->cd();
        pad1->cd();
        ElEl[s]->SetMarkerStyle(20);
        ElEl[s]->SetLineColor(kBlack);
        ElEl[s]->SetLineWidth(1);
        ElEl[s]->SetStats(0);
        ElEl[s]->Rebin(bin);

        ElEl[s]->Draw("p0 e1 same");
        if(s.Contains("Nevent"))
        {
            //                ElEl[s]->SetStats(1);
            Double_t binx = h->GetXaxis()->FindBin(1.0);
            h->GetXaxis()->SetBinLabel(binx,s);

            //                h->SetStats(1);
        }
        else
        {
            //                ElEl[s]->SetStats(0);
            //                h->SetStats(0);


        }
        leg->AddEntry(ElEl[s],"data");

        //            title = Root.TLatex(0.05,0.95,(DirKeys[dir].GetTitle())+"_"+hist[0:-4])
        //                    title.SetNDC()
        //# title.Draw()
        //                    lumi.Draw("Same")
        //                    h->SetTitle(title);
        TH1F* RatioTop =(TH1F*) ElEl[s]->Clone();
        TH1F* RatioBottom =(TH1F*) h->GetStack()->Last();
        //            RatioTop->Add(RatioBottom,-1);
        RatioTop->Divide(RatioBottom);
        c1->cd();

        TString const xAxisTitle = h->GetXaxis()->GetTitle();

        TString xAxisTitle2 = ";"+xAxisTitle + ";#frac{Data}{MC}";

        // Reset the title of the residuals histogram. It gets axis titles only
        RatioTop->SetTitle(xAxisTitle2);


        // Decoration of the residuals histogram

        if(s.Contains("NoVetokhdfjkhfshk"))
        {
            RatioTop->SetMinimum(1.6);
            RatioTop->SetMaximum(3.6);
        }
        else
        {
            RatioTop->SetMinimum(0.5);
            RatioTop->SetMaximum(1.45);
        }
        RatioTop->SetMarkerStyle(20);
        RatioTop->SetLineColor(kBlack);

        TAxis *xAxis = RatioTop->GetXaxis();
        TAxis *yAxis = RatioTop->GetYaxis();

        // Make axis label and titles of same size as in the main pad (the actual text size for the
        //default font is linked up with the current pad's smallest dimension)
        xAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                            pad1->GetHNDC() / pad2->GetHNDC());
        xAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                            pad1->GetHNDC() / pad2->GetHNDC());
        yAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                            pad1->GetHNDC() / pad2->GetHNDC());
        yAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                            pad1->GetHNDC() / pad2->GetHNDC());

        yAxis->SetNdivisions(410);
        yAxis->CenterTitle();
        yAxis->SetTitleOffset(0.5);
        xAxis->SetTickLength(xAxis->GetTickLength() * (1. - 2. * margin - bottomSpacing) /
                             bottomSpacing);


        // Alter the y axis so that its labels do not overlap with the ones of the stacked plot.
        //In the code "5" is the number of primary divisions
        double const tickOffset = (RatioTop->GetMaximum() - RatioTop->GetMinimum()) /
                5 * 0.6;
        RatioTop->SetMaximum(RatioTop->GetMaximum() + tickOffset);
        pad2->Draw();
        pad2->cd();
        //here


//        for(int i=0; i < n;i++)
//        {
//            double x = err->GetXaxis()->GetBinCenter(i);

//            double xl = err->GetBinWidth(i);
//            int bin = err->FindBin(x);
//            double yl = sqrt(err->GetBinError(bin)*err->GetBinError(bin));

//            cout << x << " "<< yl << " " << bin << endl;

//            error->SetBinContent(bin,yl);
//            //ge->SetPoint(i,x,0);
//            // ge->SetPointError(i,xl,xl,y,y);



//        }
        TH1F* error =(TH1F*) h->GetStack()->Last();

        //int n = err->GetXaxis()->GetNbins();
        TH1F* err = (TH1F*) error->Clone();
        err->GetSumw2();
        TH1F *err2 = (TH1F*) error->Clone();
        err2->GetSumw2();
        err2->Divide(err);
        //err->Scale(1/err->Integral("width"));


        // ge->SetFillColor(920+3);
        // ge->SetFillStyle(3004);
        TGraphAsymmErrors* ge= new TGraphAsymmErrors(err2);
        RatioTop->Draw("p0 e");
        ge->SetFillColor(920+3);
        ge->SetFillStyle(3004);

        //error->Draw("2 same");
        ge->Draw("2 same");
        err2->Draw("same");
        h->GetXaxis()->SetLabelOffset(999.);
        c1->cd();
        
        if(s.Contains("NPV"))
        {
            c1->cd();
            pad1->cd();
            TH1F *dataClone = (TH1F*)ElEl[s]->Clone();


            dataClone->SetFillColor(kBlack);
            dataClone->SetLineColor(kBlack);
            dataClone->Rebin(bin);
            dataClone->Draw("p0 e1 same");
            dataClone->SetStats(0);
            leg->AddEntry(MuMu[s],"data");
            TH1F* RatioTop =(TH1F*) dataClone->Clone();
            TH1F* RatioBottom =(TH1F*) h->GetStack()->Last();
            //            RatioTop->Add(RatioBottom,-1);
            RatioTop->Divide(RatioBottom);
            c1->cd();

            TString const xAxisTitle = h->GetXaxis()->GetTitle();

            TString xAxisTitle2 = ";"+xAxisTitle + ";#frac{Data}{MC}";

            // Reset the title of the residuals histogram. It gets axis titles only
            RatioTop->SetTitle(xAxisTitle2);


            // Decoration of the residuals histogram
            RatioTop->SetMinimum(0.6);
            RatioTop->SetMaximum(1.6);

            RatioTop->SetMarkerStyle(20);
            RatioTop->SetLineColor(kBlack);

            TAxis *xAxis = RatioTop->GetXaxis();
            TAxis *yAxis = RatioTop->GetYaxis();

            // Make axis label and titles of same size as in the main pad (the actual text size for the
            //default font is linked up with the current pad's smallest dimension)
            xAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            xAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetTitleSize(h->GetXaxis()->GetTitleSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());
            yAxis->SetLabelSize(h->GetXaxis()->GetLabelSize() *
                                pad1->GetHNDC() / pad2->GetHNDC());

            yAxis->SetNdivisions(405);
            yAxis->CenterTitle();
            yAxis->SetTitleOffset(0.5);
            xAxis->SetTickLength(xAxis->GetTickLength() * (1. - 2. * margin - bottomSpacing) /
                                 bottomSpacing);


            // Alter the y axis so that its labels do not overlap with the ones of the stacked plot.
            //In the code "5" is the number of primary divisions
            double const tickOffset = (RatioTop->GetMaximum() - RatioTop->GetMinimum()) /
                    5 * 0.6;
            RatioTop->SetMaximum(RatioTop->GetMaximum() + tickOffset);
            pad2->Draw();
            pad2->cd();

            RatioTop->Draw("p0 e1");

            h->GetXaxis()->SetLabelOffset(999.);
            c1->cd();
        }

        // leg->SetHeader("The Legend Title","C"); // option "C" allows to center the header
        leg->AddEntry(TT[s],"t#bar{t}");
        leg->AddEntry(TTOther[s],"t#bar{t} other");
        leg->AddEntry(ST[s],"Single t");
        //        leg->AddEntry(tW[s],"tW");
        //        leg->AddEntry(WWJJ[s],"WWJJ");
        leg->AddEntry(WJ[s],"W+Jets");
        //        leg->AddEntry(DY10[s],"DY 10");
        leg->AddEntry(DY50[s],"Z+Jets");
        leg->AddEntry(WZ[s],"diboson");
        //                leg->AddEntry(ZZ[s],"ZZ");
        leg->AddEntry(TTWJetsToQQ[s],"t#bar{t}+Z/W ");
        //        leg->AddEntry(TTJSLat[s],"tt single lepton from top");
        //        leg->AddEntry(TTJSLt[s],"tt single lepton from antitop");
        leg->Draw();
        TString title = "#scale[0.6]{#int L dt = " + lumiStr+ "fb^{-1}, #sqrt{s} = 13 TeV}";

        TLatex prelim = TLatex(0.20,0.94,"#scale[0.6]{CMS} #scale[0.5]{Preliminary}");
        TLatex lumi = TLatex(0.49,.94,title);
        prelim.SetNDC();
        lumi.SetNDC();
        prelim.Draw("same");
        lumi.Draw("same");
        histograms->cd();
        h->Write("stack"+ s +".C" );
        c1->Write(s + ".C");
        c1->Print("Plots/"+s+ ".png");
        c1->Print("stack.pdf");
        h->Clear();
        pad1->Clear();
        pad2->Clear();
        leg->Clear();
    }


    c1->Print("stack.pdf]");
    histograms->Close();
    cout << "AJS" <<endl;
    cout << "num in no MET:" << DY10["h_num_in_noMET"]->Integral()+DY50["h_num_in_noMET"]->Integral() + DY10GH["h_num_in_noMET"]->Integral()+DY50GH["h_num_in_noMET"]->Integral() << endl;
    cout << "num in with MET:" << DY10["h_num_in_MET"]->Integral()+DY50["h_num_in_MET"]->Integral() + DY10GH["h_num_in_MET"]->Integral()+DY50GH["h_num_in_MET"]->Integral() << endl;
    cout << "num out no MET:" << DY10["h_num_out_noMET"]->Integral()+DY50["h_num_out_noMET"]->Integral() +  DY10GH["h_num_out_noMET"]->Integral()+DY50GH["h_num_out_noMET"]->Integral()<< endl;
    cout << "num out  with MET:" << DY10["h_num_out_MET"]->Integral()+DY50["h_num_out_MET"]->Integral() +DY10GH["h_num_out_MET"]->Integral()+DY50GH["h_num_out_MET"]->Integral() << endl;

    cout << "DATA" << endl;
    cout << "num in no MET:" << ElEl["h_num_in_noMET"]->Integral() << endl;
    cout << "num in with MET:" << ElEl["h_num_in_MET"]->Integral() << endl;
    cout << "num out no MET:" << ElEl["h_num_out_noMET"]->Integral() << endl;
    cout << "num out  with MET:" << ElEl["h_num_out_MET"]->Integral() << endl;

    cout << "ABS" <<endl;
    cout << "num in no MET:" << DY10["h_num_in_A1BS_noMET"]->Integral()+DY50["h_num_in_A1BS_noMET"]->Integral() + DY10GH["h_num_in_A1BS_noMET"]->Integral()+DY50GH["h_num_in_A1BS_noMET"]->Integral()<< endl;
    cout << "num in with MET:" << DY10["h_num_in_A1BS_MET"]->Integral()+DY50["h_num_in_A1BS_MET"]->Integral() + DY10GH["h_num_in_A1BS_MET"]->Integral()+DY50GH["h_num_in_A1BS_MET"]->Integral()<< endl;
    cout << "num out no MET:" << DY10["h_num_out_A1BS_noMET"]->Integral()+DY50["h_num_out_A1BS_noMET"]->Integral()+ DY10GH["h_num_out_A1BS_noMET"]->Integral()+DY50GH["h_num_out_A1BS_noMET"]->Integral() << endl;
    cout << "num out  with MET:" << DY10["h_num_out_A1BS_MET"]->Integral()+DY50["h_num_out_A1BS_MET"]->Integral()+ DY10GH["h_num_out_A1BS_MET"]->Integral()+DY50GH["h_num_out_A1BS_MET"]->Integral() << endl;

    cout << "DATA" << endl;
    cout << "num in no MET:" << ElEl["h_num_in_A1BS_noMET"]->Integral() << endl;
    cout << "num in with MET:" << ElEl["h_num_in_A1BS_MET"]->Integral() << endl;
    cout << "num out no MET:" << ElEl["h_num_out_A1BS_noMET"]->Integral() << endl;
    cout << "num out  with MET:" << ElEl["h_num_out_A1BS_MET"]->Integral() << endl;

    cout << "A2BS" <<endl;
    cout << "num in no MET:" << DY10["h_num_in_A2BS_noMET"]->Integral()+DY50["h_num_in_A2BS_noMET"]->Integral() + DY10GH["h_num_in_A2BS_noMET"]->Integral()+DY50GH["h_num_in_A2BS_noMET"]->Integral()<< endl;
    cout << "num in with MET:" << DY10["h_num_in_A2BS_MET"]->Integral()+DY50["h_num_in_A2BS_MET"]->Integral()+ DY10GH["h_num_in_A2BS_MET"]->Integral()+DY50GH["h_num_in_A2BS_MET"]->Integral() << endl;
    cout << "num out no MET:" << DY10["h_num_out_A2BS_noMET"]->Integral()+DY50["h_num_out_A2BS_noMET"]->Integral() + DY10GH["h_num_out_A2BS_noMET"]->Integral()+DY50GH["h_num_out_A2BS_noMET"]->Integral() << endl;
    cout << "num out  with MET:" << DY10["h_num_out_A2BS_MET"]->Integral()+DY50["h_num_out_A2BS_MET"]->Integral() + DY10GH["h_num_out_A2BS_MET"]->Integral()+DY50GH["h_num_out_A2BS_MET"]->Integral() << endl;

    cout << "DATA" << endl;
    cout << "num in no MET:" << ElEl["h_num_in_A2BS_noMET"]->Integral() << endl;
    cout << "num in with MET:" << ElEl["h_num_in_A2BS_MET"]->Integral() << endl;
    cout << "num out no MET:" << ElEl["h_num_out_A2BS_noMET"]->Integral() << endl;
    cout << "num out  with MET:" << ElEl["h_num_out_A2BS_MET"]->Integral() << endl;


    ////Cut and Count tabel
    cout << " Cut and Count tabel:  "<<endl;
    cout << "|  source        |  xsec  |  #of Events  |  Top  |  2 Leptons  |   2 Jet  |  MET  |  1 B-Jets  | 2 B-Jets   |"<<endl;
    cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|  ttbar signal  |"<< sigTT                                                             <<"|" << NTT                                                        << "|" << TT["h_Nevents_ATS"]->Integral() + TTGH["h_Nevents_ATS"]->Integral()                                                                                                                                                                                                                                                                                       <<"|" << TT["h_Nevents_ALS"]->Integral()+ TTGH["h_Nevents_ALS"]->Integral()                                                                                                                                                                                                                                                                                        << "|" << TT["h_Nevents_AJS"]->Integral()+TTGH["h_Nevents_AJS"]->Integral() << "|" << TT["h_Nevents_AMS"]->Integral()+TTGH["h_Nevents_AMS"]->Integral() << "|" << TT["h_Nevents_ABS"]->Integral()+TTGH["h_Nevents_ABS"]->Integral() << "|" << TT["h_Nevents_A2BS"]->Integral()+TTGH["h_Nevents_A2BS"]->Integral() << "|"<<endl;
    cout << "|  ttbar other   |"<< sigTT                                                             <<"|" << NTT                                                        << "|" << TTOther["h_Nevents_ATS"]->Integral() + TTOtherGH["h_Nevents_ATS"]->Integral()                                                                                                                                                                                                                                                                                       <<"|" << TTOther["h_Nevents_ALS"]->Integral()+ TTOtherGH["h_Nevents_ALS"]->Integral()                                                                                                                                                                                                                                                                                        << "|" << TTOther["h_Nevents_AJS"]->Integral()+TTOtherGH["h_Nevents_AJS"]->Integral() << "|" << TTOther["h_Nevents_AMS"]->Integral()+TTOtherGH["h_Nevents_AMS"]->Integral() << "|" << TTOther["h_Nevents_ABS"]->Integral()+TTOtherGH["h_Nevents_ABS"]->Integral() << "|" << TTOther["h_Nevents_A2BS"]->Integral()+TTOtherGH["h_Nevents_A2BS"]->Integral() << "|"<<endl;
    cout << "|  DY            |"<< sigDY10+sigDY50                                                   <<"|" << NDY10+NDY50                                                << "|" << DY10["h_Nevents_ATS"]->Integral()  + DY50["h_Nevents_ATS"]->Integral() + DY10GH["h_Nevents_ATS"]->Integral()  + DY50GH["h_Nevents_ATS"]->Integral()                                                                                                                                                                                                       <<"|" << DY10["h_Nevents_ALS"]->Integral()  + DY50["h_Nevents_ALS"]->Integral() + DY10GH["h_Nevents_ALS"]->Integral()  + DY50GH["h_Nevents_ALS"]->Integral()                                                                                                                                                                                                       << "|" << DY10["h_Nevents_AJS"]->Integral()  + DY50["h_Nevents_AJS"]->Integral() + DY10GH["h_Nevents_AJS"]->Integral()  + DY50GH["h_Nevents_AJS"]->Integral() << "|" << DY10["h_Nevents_AMS"]->Integral()  + DY50["h_Nevents_AMS"]->Integral() + DY10GH["h_Nevents_AMS"]->Integral()  + DY50GH["h_Nevents_AMS"]->Integral() << "|" << DY10["h_Nevents_ABS"]->Integral()  + DY50["h_Nevents_ABS"]->Integral()+DY10GH["h_Nevents_ABS"]->Integral()  + DY50GH["h_Nevents_ABS"]->Integral() << "|"<< DY10["h_Nevents_A2BS"]->Integral()  + DY50["h_Nevents_A2BS"]->Integral() + DY10GH["h_Nevents_A2BS"]->Integral()  + DY50GH["h_Nevents_A2BS"]->Integral() << "|" <<endl;
    cout << "|  tW            |"<< sigST + sigST                                                     <<"|" << NST + NSTantiTop                                           << "|" << ST["h_Nevents_ATS"]->Integral()  + STantiTop["h_Nevents_ATS"]->Integral() + STGH["h_Nevents_ATS"]->Integral()  + STantiTopGH["h_Nevents_ATS"]->Integral()                                                                                                                                                                                                 <<"|" << ST["h_Nevents_ALS"]->Integral()  + STantiTop["h_Nevents_ALS"]->Integral() +STGH["h_Nevents_ALS"]->Integral()  + STantiTopGH["h_Nevents_ALS"]->Integral()                                                                                                                                                                                                  << "|" << ST["h_Nevents_AJS"]->Integral()  + STantiTop["h_Nevents_AJS"]->Integral() + STGH["h_Nevents_AJS"]->Integral()  + STantiTopGH["h_Nevents_AJS"]->Integral() << "|" << ST["h_Nevents_AMS"]->Integral()  + STantiTop["h_Nevents_AMS"]->Integral() + STGH["h_Nevents_AMS"]->Integral()  + STantiTopGH["h_Nevents_AMS"]->Integral() << "|" << ST["h_Nevents_ABS"]->Integral()  + STantiTop["h_Nevents_ABS"]->Integral() + STGH["h_Nevents_ABS"]->Integral()  + STantiTopGH["h_Nevents_ABS"]->Integral() <<"|" << ST["h_Nevents_A2BS"]->Integral()  + STantiTop["h_Nevents_A2BS"]->Integral() + STGH["h_Nevents_A2BS"]->Integral()  + STantiTopGH["h_Nevents_A2BS"]->Integral() << "|" <<endl;
    cout << "|  W+Jets        |"<< sigWJ                                                             <<"|" << NWJ                                                        << "|" << WJ["h_Nevents_ATS"]->Integral() + WJGH["h_Nevents_ATS"]->Integral()                                                                                                                                                                                                                                                                                       <<"|" << WJ["h_Nevents_ALS"]->Integral() + WJGH["h_Nevents_ALS"]->Integral()                                                                                                                                                                                                                                                                                       << "|" << WJ["h_Nevents_AJS"]->Integral() + WJGH["h_Nevents_AJS"]->Integral()  << "|" << WJ["h_Nevents_AMS"]->Integral() + WJGH["h_Nevents_AMS"]->Integral()<< "|" << WJ["h_Nevents_ABS"]->Integral() + WJGH["h_Nevents_ABS"]->Integral()  << "|"<< WJ["h_Nevents_A2BS"]->Integral() + WJGH["h_Nevents_A2BS"]->Integral()  << "|" <<endl;
    cout << "|  Diboson       |"<< sigZZ+ sigWW +sigWZ                                               <<"|" << NZZ+NWW+NWZ                                                << "|" << ZZ["h_Nevents_ATS"]->Integral()  + WW["h_Nevents_ATS"]->Integral() +WZ["h_Nevents_ATS"]->Integral() + ZZGH["h_Nevents_ATS"]->Integral()  + WWGH["h_Nevents_ATS"]->Integral() +WZGH["h_Nevents_ATS"]->Integral()                                                                                                                                           <<"|" << ZZ["h_Nevents_ALS"]->Integral()  + WW["h_Nevents_ALS"]->Integral() +WZ["h_Nevents_ALS"]->Integral() +ZZGH["h_Nevents_ALS"]->Integral()  + WWGH["h_Nevents_ALS"]->Integral() +WZGH["h_Nevents_ALS"]->Integral()                                                                                                                                            << "|" << ZZ["h_Nevents_AJS"]->Integral()  + WW["h_Nevents_AJS"]->Integral() +WZ["h_Nevents_AJS"]->Integral() + ZZGH["h_Nevents_AJS"]->Integral()  + WWGH["h_Nevents_AJS"]->Integral() +WZGH["h_Nevents_AJS"]->Integral() << "|" << ZZ["h_Nevents_AMS"]->Integral()  + WW["h_Nevents_AMS"]->Integral() +WZ["h_Nevents_AMS"]->Integral() +ZZGH["h_Nevents_AMS"]->Integral()  + WWGH["h_Nevents_AMS"]->Integral() +WZGH["h_Nevents_AMS"]->Integral() << "|" << ZZ["h_Nevents_ABS"]->Integral()  + WW["h_Nevents_ABS"]->Integral() +WZ["h_Nevents_ABS"]->Integral() +  ZZGH["h_Nevents_ABS"]->Integral()  + WWGH["h_Nevents_ABS"]->Integral() +WZGH["h_Nevents_ABS"]->Integral()    << "|" <<ZZ["h_Nevents_A2BS"]->Integral()  + WW["h_Nevents_A2BS"]->Integral() +WZ["h_Nevents_A2BS"]->Integral() + ZZGH["h_Nevents_A2BS"]->Integral()  + WWGH["h_Nevents_A2BS"]->Integral() +WZGH["h_Nevents_A2BS"]->Integral()<<"|"<<endl;
    cout << "|  ttbarV        |"<<sig_TTWJetsToLNu + sig_TTWJetsToQQ + sig_TTZToLLNuNu + sig_TTZToQQ <<"|" << N_TTWJetsToLNu + N_TTWJetsToQQ + N_TTZToLLNuNu + N_TTZToQQ << "|" << TTWJetsToLNu["h_Nevents_ATS"]->Integral() +TTWJetsToQQ["h_Nevents_ATS"]->Integral()  + TTZToLLNuNu["h_Nevents_ATS"]->Integral()  + TTZToQQ["h_Nevents_ATS"]->Integral() + TTWJetsToLNuGH["h_Nevents_ATS"]->Integral() +TTWJetsToQQGH["h_Nevents_ATS"]->Integral()  + TTZToLLNuNuGH["h_Nevents_ATS"]->Integral()  + TTZToQQGH["h_Nevents_ATS"]->Integral() <<"|" << TTWJetsToLNu["h_Nevents_ALS"]->Integral() +TTWJetsToQQ["h_Nevents_ALS"]->Integral()  + TTZToLLNuNu["h_Nevents_ALS"]->Integral()  + TTZToQQ["h_Nevents_ALS"]->Integral() +TTWJetsToLNuGH["h_Nevents_ALS"]->Integral() +TTWJetsToQQGH["h_Nevents_ALS"]->Integral()  + TTZToLLNuNuGH["h_Nevents_ALS"]->Integral()  + TTZToQQGH["h_Nevents_ALS"]->Integral()  << "|" << TTWJetsToLNu["h_Nevents_AJS"]->Integral() +TTWJetsToQQ["h_Nevents_AJS"]->Integral()  + TTZToLLNuNu["h_Nevents_AJS"]->Integral()  + TTZToQQ["h_Nevents_AJS"]->Integral() + TTWJetsToLNuGH["h_Nevents_AJS"]->Integral() +TTWJetsToQQGH["h_Nevents_AJS"]->Integral()  + TTZToLLNuNuGH["h_Nevents_AJS"]->Integral()  + TTZToQQGH["h_Nevents_AJS"]->Integral() << "|" << TTWJetsToLNu["h_Nevents_AMS"]->Integral() +TTWJetsToQQ["h_Nevents_AMS"]->Integral()  + TTZToLLNuNu["h_Nevents_AMS"]->Integral()  + TTZToQQ["h_Nevents_AMS"]->Integral() + TTWJetsToLNuGH["h_Nevents_AMS"]->Integral() +TTWJetsToQQGH["h_Nevents_AMS"]->Integral()  + TTZToLLNuNuGH["h_Nevents_AMS"]->Integral()  + TTZToQQGH["h_Nevents_AMS"]->Integral() << "|" << TTWJetsToLNu["h_Nevents_ABS"]->Integral() +TTWJetsToQQ["h_Nevents_ABS"]->Integral()  + TTZToLLNuNu["h_Nevents_ABS"]->Integral()  + TTZToQQ["h_Nevents_ABS"]->Integral() + TTWJetsToLNuGH["h_Nevents_ABS"]->Integral() +TTWJetsToQQGH["h_Nevents_ABS"]->Integral()  + TTZToLLNuNuGH["h_Nevents_ABS"]->Integral()  + TTZToQQGH["h_Nevents_ABS"]->Integral() << "|" <<TTWJetsToLNu["h_Nevents_A2BS"]->Integral() +TTWJetsToQQ["h_Nevents_A2BS"]->Integral()  + TTZToLLNuNu["h_Nevents_A2BS"]->Integral()  + TTZToQQ["h_Nevents_A2BS"]->Integral() + TTWJetsToLNuGH["h_Nevents_A2BS"]->Integral() +TTWJetsToQQGH["h_Nevents_A2BS"]->Integral()  + TTZToLLNuNuGH["h_Nevents_A2BS"]->Integral()  + TTZToQQGH["h_Nevents_A2BS"]->Integral()  <<"|" <<endl ;
    cout << "|  Data          |"<< 1                                                                 <<"|" << ElEl["h_Nevents"]->Integral()                              << "|" << ElEl["h_Nevents_ATS"]->Integral()                                                                                                                                                                                                                                                                                                                         <<"|" << ElEl["h_Nevents_ALS"]->Integral()                                                                                                                                                                                                                                                                                                                         << "|" << ElEl["h_Nevents_AJS"]->Integral() <<"|" << ElEl["h_Nevents_AMS"]->Integral() << "|" << ElEl["h_Nevents_ABS"]->Integral() <<"|" << ElEl["h_Nevents_A2BS"]->Integral() <<"|"<<endl;


    //  cout << "|  ttbar other   |"<< sigTT << "|" << NTT << "  |" << TTOther["h_Nevents_ATS"]->Integral()*((lumi*sigTT)/NTT) << "|" << TTOther["h_Nevents_ALS"]->Integral()*((lumi*sigTT)/NTT) << "|" << TTOther["h_Nevents_ALS"]->Integral()*((lumi*sigTT)/NTT) << "|" << TTOther["h_Nevents_ALS"]->Integral()*((lumi*sigTT)/NTT) << "|" << TTOther["h_Nevents_AJS"]->Integral()*((lumi*sigTT)/NTT) << "|" << TTOther["h_Nevents_AMS"]->Integral()*((lumi*sigTT)/NTT) << "|" << TTOther["h_Nevents_ABS"]->Integral()*((lumi*sigTT)/NTT) << "|" << TTOther["h_Nevents_A2BS"]->Integral()*((lumi*sigTT)/NTT) << "|"<<endl;


    return 0;
}
