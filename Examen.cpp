#include <iostream>
#include <cstdio>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"



void Examen::EjemploDeListado(){
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}

void Examen::Punto1(){

    ArchivoServicioMesa aServicioMesa("restaurant.dat");
    int cantidadServicioMesa = aServicioMesa.CantidadRegistros();
    if (cantidadServicioMesa==0){
        cout << "PUNTO 1: no hay registros. " << endl;
        return;
    }
    float puntajeTotal =0, promedio;
    int cantidadMayoresPromedio=0;

    for (int i=0;i<cantidadServicioMesa;i++){
        ServicioMesa registro;
        registro = aServicioMesa.Leer(i);
        puntajeTotal += registro.getPuntajeObtenido();
    }
    promedio =puntajeTotal/cantidadServicioMesa;


    for (int i =0;i <cantidadServicioMesa;i++){
        ServicioMesa registro;
        registro =aServicioMesa.Leer(i);
        if (registro.getPuntajeObtenido()>promedio){
            cantidadMayoresPromedio++;
        }
    }

    cout << "Punto 1: " << cantidadMayoresPromedio << endl;
    cout << endl;
}

void Examen::Punto2(){

    ArchivoServicioMesa archivo("restaurant.dat");
    int cantidadRegistros = archivo.CantidadRegistros();
    if (cantidadRegistros==0){
        cout << "PUNTO 2: no hay registros. " << endl;
        return;
    }
    float recaudacion [70] = {0};

    for (int i=0; i < cantidadRegistros; i++){
        ServicioMesa registro=archivo.Leer(i);
        int indicePlato = registro.getIDPlato()-1;
        if (indicePlato>=0&&indicePlato<70){
            recaudacion [indicePlato]+=registro.getImporte();
        }
    }

    int platoMayorRecaudacion=1;

    for (int i=1; i<70; i++){
        if (recaudacion[i]>recaudacion[platoMayorRecaudacion-1]){
            platoMayorRecaudacion=i+1;
        }
    }

    cout << "Punto 2: plato con mayor recaudacion: "<< platoMayorRecaudacion<< endl;
    cout << endl;

}

void Examen::Punto3(){

    ArchivoServicioMesa archivo("restaurant.dat");
    int cantidadRegistros = archivo.CantidadRegistros();
    if (cantidadRegistros==0){
        cout << "PUNTO 3: no hay registros. " << endl;
        return;
    }

    float propinasRecaudadas [20]={0};

    for (int i =0; i<cantidadRegistros;i++){
        ServicioMesa registro=archivo.Leer(i);

        if (registro.getFecha().getAnio()== 2024 && registro.getPropina()>0){
        int indiceMozo = registro.getIDMozo()-1;
        if (indiceMozo>=0 && indiceMozo<20){
            propinasRecaudadas[indiceMozo]+= registro.getPropina();
        }
        }
    }

    int MozoMayorPropina=1;

    for (int i=1;i<20;i++){
        if (propinasRecaudadas[i]>propinasRecaudadas[MozoMayorPropina-1]){
            MozoMayorPropina=i+1;
        }
    }

    cout << "Punto 3: Mozo con mayor propina: " << MozoMayorPropina << endl;
    cout << endl;

}

///PREGUNTAS ADICIONALES

void Examen::Punto4(){
/*
Listar la cantidad de servicios de mesa que no tuvieron propina.
*/
ArchivoServicioMesa archivo("restaurant.dat");
int cantidadRegistros = archivo.CantidadRegistros();
if (cantidadRegistros==0){
        cout << "PUNTO 4: no hay registros. " << endl;
        return;
    }
int cantSinPropina =0;

for(int i = 0; i < cantidadRegistros; i++){
    ServicioMesa registro = archivo.Leer(i);


if (registro.getPropina()==0){
    cout << "Servicio sin propina: " << registro.getIDServicioMesa() << endl;
    cantSinPropina++;
}
}
cout << "Punto 4: Cantidad de servicios sin propina: " << cantSinPropina << endl;
cout << endl;

}

void Examen::Punto5(){
/*
Listar el/los número/s de plato con menor cantidad de servicios de mesa el año 2024.
Se deben informar todos los números de plato que tengan la cantidad mínima de servicios.
*/
ArchivoServicioMesa archivo("restaurant.dat");
int cantidadRegistros = archivo.CantidadRegistros();
if (cantidadRegistros==0){
        cout << "PUNTO 5: no hay registros. " << endl;
        return;
    }
   int cantidadPorPlato [70] = {0};

    for (int i=0;i<cantidadRegistros;i++){
        ServicioMesa registro=archivo.Leer(i);

    if (registro.getFecha().getAnio()== 2024){
        int indicePlato=registro.getIDPlato()-1;

        if (indicePlato>=0 && indicePlato<70){
        cantidadPorPlato[indicePlato]++;
        }
    }
    }
    int cantidadMinima = cantidadPorPlato [0];

    for (int i=1; i<70; i++){
        if (cantidadPorPlato[i]<cantidadMinima){
            cantidadMinima=cantidadPorPlato[i];
        }
    }
    cout << "PUNTO 5: el/los plato/s con menor cantidad de servicios en 2024 son (con " << cantidadMinima << " servicio/s) :" << endl;
    for (int i=0; i < 70;i++){
        if (cantidadPorPlato[i]==cantidadMinima){
            cout << i+1 << " " ;
        }
    }
    cout << endl;
    cout << endl;
}

void Examen::Punto6(){
/*
Listar el número de mozo con mayor importe recaudado
 entre todos los servicios de mesa que atendió.
*/

ArchivoServicioMesa archivo("restaurant.dat");
int cantidadRegistros = archivo.CantidadRegistros();
if (cantidadRegistros==0){
        cout << "PUNTO 6: no hay registros. " << endl;
        return;
    }

    float recaudacionImporteTotal [20]={0};

    for (int i =0;i<cantidadRegistros;i++){
        ServicioMesa registro = archivo.Leer(i);
        int indiceMozo= registro.getIDMozo()-1;

        if (indiceMozo>=0 && indiceMozo<20){
            recaudacionImporteTotal[indiceMozo]+= registro.getImporte();
        }
    }
int indiceMayor=0;

for(int i =1;i<20;i++){
    if (recaudacionImporteTotal[i]>recaudacionImporteTotal[indiceMayor]){
        indiceMayor=i;
    }
}
cout << "Punto 6: mozo con mayor importe total: " << indiceMayor+1 << endl;
cout << "importe: " << recaudacionImporteTotal[indiceMayor] << endl;
cout << endl;
}

void Examen::Punto7(){
/*
Emitir un listado de los servicios de mesa del año 2024
ordenados de menor a mayor por importe.
*/

ArchivoServicioMesa archivo("restaurant.dat");
int cantidadRegistros = archivo.CantidadRegistros();
if (cantidadRegistros==0){
        cout << "PUNTO 7: no hay registros. " << endl;
        return;
    }
int cantidad2024 =0;

for (int i =0;i<cantidadRegistros;i++){
    ServicioMesa registro=archivo.Leer(i);
    if (registro.getFecha().getAnio()==2024){
        cantidad2024++;
    }}
    if (cantidad2024==0){
        cout << "No hay servicios de 2024. " << endl;
        return ;
    }
    ServicioMesa *servicios2024 = new ServicioMesa[cantidad2024];

    if (servicios2024==nullptr){
        cout << "ERROR EN LA ASIGNACION DE MEMORIA DINAMICA" << endl;
        return;
    }
    int posicion =0;

    for (int i=0;i<cantidadRegistros;i++){
        ServicioMesa registro = archivo.Leer(i);

    if (registro.getFecha().getAnio()==2024){
        servicios2024[posicion] = registro;
        posicion++;
    }
    }
    for (int j=0;j<cantidad2024-1;j++){
        for (int i=0;i<cantidad2024-1-j;i++){
            if(servicios2024[i].getImporte()>servicios2024[i+1].getImporte()){

            ServicioMesa aux = servicios2024[i];
            servicios2024[i] = servicios2024[i+1];
            servicios2024 [i+1] =aux;
            }
        }
    }
    cout << "PUNTO 7: servicios de 2024 ordenados por importe: " << endl;
    cout << endl;
    for (int i=0;i<cantidad2024;i++){
        cout << servicios2024[i].toCSV()<<endl;
    }

    delete[] servicios2024;
}

void Examen::Punto8(){
    /*
     Generar un archivo con la recaudación total (suma de los importes de cada servicio de mesa)
     de cada número de plato. El formato de los registros del archivo tiene que ser el siguiente:
     IDPlato, promedio de puntaje y recaudación total.
    */

    //1. Lector de archivo+obtener cantidad de registros:
    ArchivoServicioMesa archivo("restaurant.dat");
    int cantidadRegistros = archivo.CantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "PUNTO 8: no hay registros." << endl;
        return;
    }

    //2. Crear 3 arrays de 70 posiciones:
    float sumaPuntajes[70] = {0};
    int cantidadPorPlato[70] = {0};
    float recaudacionPorPlato[70] = {0};

    //3. Recorrer los registros y convertir IDPlato a indice:
    for(int i = 0; i < cantidadRegistros; i++){
        ServicioMesa registro = archivo.Leer(i);
    int indicePlato = registro.getIDPlato() - 1;

    //4. Acumular el puntaje, incrementar el contador y acumular el importe.
    if(indicePlato >= 0 && indicePlato < 70){
            sumaPuntajes[indicePlato] += registro.getPuntajeObtenido();
            cantidadPorPlato[indicePlato]++;
            recaudacionPorPlato[indicePlato] += registro.getImporte();
        }
    }
    //5. Abrir un archivo de texto de salida.
    FILE *pArchivo = fopen ("recaudacion_platos.txt", "w");

    if (pArchivo==NULL){
        cout << "Punto 8: no se pudo crear el archivo. " << endl;
        return;
    }
    // 6. Para cada plato calcular sumapuntajes/cantservicios
    for (int i =0;i<70;i++){
        float promedio=0;
        if (cantidadPorPlato[i]>0){
            promedio=sumaPuntajes[i]/cantidadPorPlato[i];
        }
        fprintf(pArchivo, "%d,%.2f,%.2f\n", i+1, promedio, recaudacionPorPlato[i]);
    }
    fclose(pArchivo);

    cout << "Punto 8: se creo recaudacion_platos.txt." << endl;
    cout << endl;

}

void Examen::Punto10(){
    /*
    Informar la cantidad de servicios de mesa para cada uno de los meses
    (no interesa el año)
    */
    // 1. Lector de archivo+obtener cant de registros
    ArchivoServicioMesa archivo("restaurant.dat");
    int cantidadRegistros = archivo.CantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "PUNTO 10: no hay registros." << endl;
        return;
    }
    // 2. Crear un array de 12 contadores.
    int cantidadPorMes [12]={0};

    //3. Recorrer registros y obtener mes de la fecha. Restarle 1 para convertirlo en indice
    for (int i =0; i<cantidadRegistros;i++){
        ServicioMesa registro = archivo.Leer(i);
        int indiceMes = registro.getFecha().getMes()-1;
    // 4. Incrementar contador.
        if (indiceMes >=0 && indiceMes < 12){
            cantidadPorMes [indiceMes]++;
        }
    }
for (int i =0;i<12;i++){
    cout << "Mes " << i+1 << ": " << cantidadPorMes[i] << " servicios" << endl;
}
}

void Examen::Punto11(){
/*
El número de servicio, si existe, que haya obtenido a la vez
la mayor propina y la mejor calificación.
*/
// 1. Leer archivo y obtener cant de registros
 ArchivoServicioMesa archivo("restaurant.dat");
    int cantidadRegistros = archivo.CantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "PUNTO 11: no hay registros." << endl;
        return;
    }

//2. Inicializar la mayor propina y mejor puntaje
float mayorPropina = archivo.Leer(0).getPropina();
float mejorPuntaje = archivo.Leer(0).getPuntajeObtenido();

//3. Recorrer todos los servicios y actualizar ambos maximos
for(int i = 1; i < cantidadRegistros; i++){
        ServicioMesa registro = archivo.Leer(i);

        if(registro.getPropina() > mayorPropina){
            mayorPropina = registro.getPropina();
        }

        if(registro.getPuntajeObtenido() > mejorPuntaje){
            mejorPuntaje = registro.getPuntajeObtenido();
        }
    }

    bool encontrado = false;

    cout << "PUNTO 11: servicio/s con mayor propina y mejor puntaje:" << endl;
//4. Recorrer nuevamente y buscar registros con ambos maximos
for(int i = 0; i < cantidadRegistros; i++){
        ServicioMesa registro = archivo.Leer(i);

        if(registro.getPropina() == mayorPropina &&
           registro.getPuntajeObtenido() == mejorPuntaje){

            cout << registro.toCSV() << endl;
            encontrado = true;
        }
    }

    if(!encontrado){
        cout << "No hay un mismo servicio que tenga ambos máximos." << endl;
    }
}
