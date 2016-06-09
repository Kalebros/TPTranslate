#include "tpfile.h"


TPFile::TPFile()
{
    _dataset=0;
    _nombreArchivo=string();
}

TPFile::TPFile(string n)
{
    _nombreArchivo=n;

    //Abrir el dataset
    _dataset=(GDALDataset*) GDALOpen(_nombreArchivo.c_str(),GA_ReadOnly);
}

bool TPFile::isOpen() const
{
    if(_dataset)
        return true;
    return false;
}

TPFile::~TPFile()
{
    if(_dataset)
        GDALClose((GDALDatasetH)_dataset);
    _dataset=0;
}

void TPFile::setNombreArchivo(string n)
{
    _nombreArchivo=n;
}

bool TPFile::saveToTIFF(string aSalida)
{
    const char *format="GTiff";
    GDALDriver *outputDriver;

    outputDriver=GetGDALDriverManager()->GetDriverByName(format);

    if(outputDriver==NULL)
        return false;

    GDALDataset *destino=outputDriver->CreateCopy(aSalida.c_str(),_dataset,FALSE,NULL,NULL,NULL);

    if(destino!=NULL)
        GDALClose((GDALDatasetH)destino);

    return true;
}

