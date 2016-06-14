#include <iostream>

#include <TPFile/tpfile.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    TPFile::initGDAL();

    TPFile archivo2("/home/bardo/Workbench/Qt/ClasesQt/imagen_prueba.jpg");

    if(archivo2.isOpen())
        cout << "Archivo abierto"<<endl;
    else cout << "Archivo ERRONEO!"<<endl;

    vector<string> listaDrivers=TPFile::driverNames();

    for(auto it=listaDrivers.begin();it!=listaDrivers.end();it++) {
        cout <<"DRIVER NAME: "<<(*it) <<endl;
    }
    archivo2.saveToTIFF("/home/bardo/Workbench/Qt/ClasesQt/imagen_salida.tiff");

    return 0;
}
