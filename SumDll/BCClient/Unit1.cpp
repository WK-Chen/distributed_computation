//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "ISum.h"
#include "ipo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ISum *mysum = CreateObject(3, 5);
        ShowMessage(AnsiString(mysum->getMul()));
        IPO *pIPO = dynamic_cast<IPO*>(mysum);
        ShowMessage(AnsiString(pIPO->getMul()));
        pIPO->Save();
        delete mysum;
}
//---------------------------------------------------------------------------
