/*********************************
 *   Assignment: A2 spiral pdf   *
 *   Name: Ryan Vreeke           *
 *   Class: 3505                 *
 *   HaruPDF.h                   *
 *********************************/
#ifndef HARUPDF_H
#define HARUPDF_H

#include "hpdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

class HaruPDF
{

private:
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;

public:
    HaruPDF();
    ~HaruPDF();

    void printChar(char text, float rad1, float x, float y);

    void saveFile(const char *filename);
};

#endif