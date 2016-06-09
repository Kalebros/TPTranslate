#ifndef TPFILE_H
#define TPFILE_H

#include <gdal/gdal_priv.h>
#include <gdal/cpl_conv.h>
#include <gdal/cpl_string.h>
#include <string>

using namespace std;

/*!
 * @class TPFile
 * @brief Clase para abrir y cambiar el formato de un archivo de imagen a otro
 *
 *  Esta clase utiliza las librerias de GDAL para realizar la transformacion.
 */
class TPFile
{

public:

    /*!
     * Constructor
     */
    TPFile();

    /*!
     * @overload
     */
    TPFile(string n);

    /*!
      Destructor
      */
    ~TPFile();

    /*!
     * Devuelve el nombre del archivo de entrada
     * @return Nombre del archivo de entrada
     * @note No modifica el objeto
     */
    string nombreArchivo() const
    { return _nombreArchivo; }

    /*!
     * Cambia el nombre del archivo de entrada
     * @param n Nuevo nombre del archivo de entrada
     * @note Modifica el objeto
     */
    void setNombreArchivo(string n);

    /*!
     * Indica si el archivo esta abierto (listo para usarse)
     * @return True, esta abierto y puede usarse, false en caso contrario
     * @note No modifica el objeto
     */
    bool isOpen() const;

    /*!
     * Guarda el archivo en formato GeoTIFF
     * @param aSalida   Ruta del archivo de salida
     * @return True, se ha transformado correctamente, false en caso contrario
     * @pre El archivo DEBE DE ESTAR ABIERTO
     * @note No modifica el objeto
     */
    bool saveToTIFF(string aSalida);

protected:

    string _nombreArchivo; ///< Nombre del archivo que queremos transformar
    GDALDataset *_dataset;

};

#endif // TPFILE_H
