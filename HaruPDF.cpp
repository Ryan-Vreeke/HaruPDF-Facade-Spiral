/*********************************
 *   Assignment: A2 spiral pdf   *
 *   Name: Ryan Vreeke           *
 *   Class: 3505                 *
 *   HaruPDF.cpp                 *
 *********************************/
#include "HaruPDF.h"

HaruPDF::HaruPDF()
{
    pdf = HPDF_New(NULL, NULL);

    // set page and add to pdf
    HaruPDF::page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    // set text for the page
    font = HPDF_GetFont(pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading(page, 20);
    HPDF_Page_SetGrayStroke(page, 0);
    HPDF_Page_SetFontAndSize(page, font, 30);

    HPDF_Page_BeginText(page);
}

HaruPDF::~HaruPDF()
{
}


void HaruPDF::printChar(char text, float angle, float x, float y)
{
    char buf[1];//adds the char to a char array so i can print as a string
    buf[0] = text;

    float rad1 = -angle * M_PI / 180;//turns the angle into a radian 

    HPDF_Page_SetTextMatrix(page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);

    HPDF_Page_ShowText(page, buf);
}

void HaruPDF::saveFile(const char *filename)
{
    HPDF_Page_EndText(page);

    HPDF_SaveToFile(pdf, filename);

    /* clean up */
    HPDF_Free(pdf);
}
