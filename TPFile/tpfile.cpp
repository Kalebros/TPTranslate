#include "tpfile.h"


TPFile::TPFile()
{
}

TPFile::TPFile(string n)
{
    _nombreArchivo=n;
}

TPFile::~TPFile()
{

}

void TPFile::setNombreArchivo(string n)
{
    _nombreArchivo=n;
}

void TPFile::initGDAL()
{
    GDALAllRegister();
}
