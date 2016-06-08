#ifndef TPFILE_H
#define TPFILE_H

#include <gdal/gdal_priv.h>
#include <gdal/cpl_conv.h>

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
     * Inicializa la libreria GDAL
     *
     * Para inicializar la libreria GDAl, este metodo llama internamente a
     * GDALAllRegister (ver documentacion en gdal.org)
     * @note No modificae el estado de los objetos TPFile
     */
    static void initGDAL();

protected:

    string _nombreArchivo; ///< Nombre del archivo que queremos transformar

};

#endif // TPFILE_H
