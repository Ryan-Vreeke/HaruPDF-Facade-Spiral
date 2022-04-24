/*
*   Assignment: A2 spiral pdf 
*   Name: Ryan Vreeke
*   Class: 3505
*   SpiralPDF.cpp
*
*/

#include "HaruPDF.h"
#include "Spiral.h"

int main(int argc, char **argv)
{
    HaruPDF pdf;
    char fname[256];
    //pre set text to put in pdf if the entered string length is zero
    const char *SAMP_TXT = argv[1];
    strcpy(fname, argv[0]);
    strcat(fname, ".pdf");

    Spiral spiral(210, 300, 0, 10);

    int len = strlen(SAMP_TXT);

    for (int i = 0; i < len; i++)
    {
        float x;
        float y;        

        // The position of the character depends on the center point
        // plus the angle and the radius.
        x = spiral.getTextX();
        y = spiral.getTextY();

        pdf.printChar(SAMP_TXT[i], spiral.getLetterAngle(), x, y);

        spiral++;
    }

    pdf.saveFile(fname);

    /* code */
    return 0;
}
