/*
 
  ������+ ��+   ��+ �����+ ���+   ��+��������+��+   ��+���+   ���+    �������+������+  �����+  ������+��������+��+   ��+������+ �������+
 ��+---��+���   �����+--��+����+  ���+--��+--+���   �������+ �����    ��+----+��+--��+��+--��+��+----++--��+--+���   �����+--��+��+----+
 ���   ������   �������������+��+ ���   ���   ���   �����+����+���    �����+  ������++�����������        ���   ���   ���������++�����+
 ���__ ������   �����+--������+��+���   ���   ���   ������+��++���    ��+--+  ��+--��+��+--������        ���   ���   �����+--��+��+--+
 +������+++������++���  ������ +�����   ���   +������++��� +-+ ���    ���     ���  ������  ���+������+   ���   +������++���  ����������+
  +--��-+  +-----+ +-+  +-++-+  +---+   +-+    +-----+ +-+     +-+    +-+     +-+  +-++-+  +-+ +-----+   +-+    +-----+ +-+  +-++------+
 
                                                                PRESENTA
                       _____________________________________________________________________________________________
                                      _
                                     ' )    |\/| _�_|_ _  _| _    _| _   |\/| _  _ _|_ _  _ _  _ | _
                                      /_ .  |  |(/_ | (_)(_|(_)  (_|(/_  |  |(_)| | | (/_(_(_||  |(_)
 
 Qu� pasa chavales, muy buenas a todos, aqu� Crespo comentando (xD en serio, willy pls). Con este c�digo, escrito en C++, vamos a hacer que
 este ordenador calcule pi utilizando el m�todo que se us� para hacer ciertos c�lculos en el desarrollo del proyecto Manhattan: el m�todo
 de Montecarlo.
 Si quieres saber las ideas b�sicas de este algoritmo o no sabes como coj***s has llegado aqu� y qu� es este c�digo
 hablandome as� wtf, te recomiendo pasarte por YouTube y verte este v�deo
 -->  https://youtu.be/DQ5qqHukkAc  <--.
 
 Si no ves un mont�n de s�mbolos raros, te recomiendo que estires el tama�o de tu ventana, te llevar�s una sorpresa --->

 
 Muy bien, ahora que estamos en la misma onda, sabemos que vamos a calcular pi a partir de la proporci�n entre puntos aleatorios dentro 
 de un c�rculo y los totales (ya que todos caen dentro del cuadrado). Puesto en ecuaciones:
 
                                            4  (n� de puntos dentro del circulo)
                                    pi = -----------------------------------------
                                                (n� de puntos "lanzados")
 
 Atentos: en vez de medir las proporciones en un circulo entero vamos a calcularlo para un CUADRANTE de este circulo; un cuarto de �l, 
 como una porci�n de una pizza partida en cuatro.
 Con m�s exactitud: tenemos un cuadrado de lado r. Dentro est� inscrita tal porci�n del circulo, cuyo centro estar�a ubicado en uno de 
 los vertices del cuadrado, que designamos con coordenadas (x=0 , y=0). Vamos a dividir el numero de puntos que caigan dentro de 
 esa porci�n (es decir que verifican que x^2 + y^2 < r^2) entre el numero de puntos totales lanzados.
 
 Adem�s, no solo vamos a hacer esto una vez: se realizaran varias tandas de tiradas, cada una con el mismo n�mero de puntos aleatorios 
 a lanzar. Dado que los resultados de Montecarlo no son los mismos en cada ejecuci�n del programa (dada la naturaleza aleatoria 
 del c�lculo), haremos que el c�digo repita el m�todo un cierto n�mero de veces para hacer estad�stica con los varios pi's que nos 
 saque. Obtendremos media y desviaci�n est�ndar, con lo que tendremos una estimaci�n del error del m�todo. En pocas palabras: tendremos 
 un pi fiable, no tan dependiente de la ejecuci�n y con un error que nos permita acotar el valor exacto.
 
 As� he nombrado a cada variable:
 
   *  r     : el radio del circulo.
   *  N     : el n�mero total de puntos a lanzar. Es un input.
   *  x     : posici�n del punto aleatorio en el eje X.
   *  y     : posici�n del punto aleatorio en el eje Y.
   *  cota  : es el n�mero de veces que queremos que se repita internamente Montecarlo para tener una estimaci�n del error.
   *  c     : n�mero de puntos que han caido dentro de la porci�n.
   *  pi_ar : array (como un vector) de valores de pi recogidos en cada tanda de tiradas. Sus dimensiones son "cota".
   *  pi    : valor de pi obtenido como la media de los valores de "pi_ar".
   *  err   : error en el valor de pi obtenido como la desviaci�n est�ndar de los valores de "pi_ar".

 
 */


#include <iostream>  // Cargo librer�as (colecciones de funciones ya hechas que hacen cositas): "iostream" me permite sacar texto
#include <cmath>     // y n�meros por el terminal, para que puedas ver el valor de pi, y "cmath" es una colecci�n de funciones
#include <fstream>   // matem�ticas que necesito, como elevar al cuadrado y hacer la raiz cuadrada.
#include <stdlib.h>
#include <time.h>
using namespace std;  // A efectos pr�ticos, esto es para no tener que poner "std" todo el rato.

int main(){           // �Comenzamos!
    
    // Imprimimos en el terminal... la bienvenida ;)
    
    cout<<endl<<endl;
    cout<<"                       +-+ - -+-+++++-+- -+-+  +-+--++-++-++-+- ---++-+"<<endl;
    cout<<"                       �-++� �+-���� � � ����  �� +-++-��   � � �+-++�"<<endl;
    cout<<"                       +-+++-+- -+++ - +-+- -  +  -+-- -+-+ - +-+-+-+-+"<<endl;
    cout<<"            ______________________________________________________________________     "<<endl<<endl;
    cout<<"                                          PRESENTA...                                  "<<endl;
    cout<<endl;
    cout<<"+-++-+-  +-+- --  +-+  +-++-+  +-+-       +-++-++-++-++-++-+  +-++-+  +-++-+++++-++-++-++-+--+-  +-+"<<endl;
    cout<<"�  +-��  �  � ��  � �   ��+�   �-+�  ---  ���+�  � � � ��� �   ��+�   ���� ���� � +� �  +-�+-+�  � �"<<endl;
    cout<<"+-+- ---++-++-+--++-+  --++-+  -  -       - -+-+ - +-+--++-+  --++-+  - -+-++++ - +-++-+- --+---++-+"<<endl;
    
    cout<<endl<<"                  �Con todos los n�meros aleatorios que quieras! �Garantizado! ;)"<<endl<<endl;
    
    cout<<"_____________________________________________________________________________________________"<<endl<<endl;
    cout<<"                                         ADVERTENCIA                                     "<<endl;
    cout<<"Si est� usando este c�digo en un compilador online, puede ser que utilizar un n�mero excesivo"<<endl;
    cout<<" de dardos haga que el c�lculo necesite tanto tiempo para ser computado que el compilador lo"<<endl;
    cout<<"               aborte autom�ticamente. En ese caso, pruebe un n�mero menor."<<endl;
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    double N = 12345;         // N�MERO DE PUNTOS ALEATORIOS A LANZAR. �CAMBIAD ESTO!
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Se expulsa tal n�mero por terminal:
    
    cout<<endl<<"  +----------------------------------------------------------------------------------------+";
    cout<<endl<<"  �                         N�mero de 'dardos' a lanzar :   "<<N;
    cout<<endl<<"  +----------------------------------------------------------------------------------------+";
    
    double r=1;       // RADIO DEL C�RCULO: Puedes cambiar este n�mero si lo deseas; el tama�o de la circunferencia no afecta a pi.
 
    srand((unsigned)time(0));  // Para que el ordenador nos genere los n�meros aleatorios, hay que darle una semilla. Normalmente
                               // suele cogerse el tiempo del reloj del ordenador en ese momento.
    
    double x;                  // Defino las coordenadas de cada punto aleatorio. No queremos almacenarlas; reescribiremos estas variable.
    double y;
    
    double c=0;                // Defino el n�mero de puntos dentro del c�rculo (de la porci�n). Partimos de 0.
    
    //int m=1e7;
    
    int cota=10;               // COTA. N�MERO DE REPETICIONES DEL M�TODO. Puedes cambiar este n�mero si lo deseas.
    
    double pi_ar[cota];        // Defino el array que voy a llenar de los distintos pi's que obtenga.
    
    
    for (int j=0; j<cota; j++) {               // Primer BUCLE. Repetir� Montecarlo "cota" veces.
        
        for (int i=0; i<N; i++) {                // Segundo BUCLE. En cada vuelta, lanza un dardo.
            
            x=(double)rand()/(double)RAND_MAX;   // Generamos dos n�meros aleatorios desde 0 a 1. N�tese que en los siguientes
            y=(double)rand()/(double)RAND_MAX;   // lanzamientos estos n�meros ser�n reescritos.
            
            x=x*r;                               // Dilato estos n�meros hasta el radio. Ahora van de 0 a "r". Estas son las coordenadas
            y=y*r;                               // en las que ha caido un dardo.
            
            if (x*x+y*y<r*r) {                   // Compruebo si el dardo est� o no dentro del circulo. Si es as�, c aumentar� en uno.
                c++;
            }
        }                                        // FIN Segundo BUCLE
        
        pi_ar[j]=4*c/N;                        // Calculo el pi generado en esta tanda y lo almaceno.
        c=0;                                   // Inicializo a cero para la siguiente tanda de disparos.
        
    }                                          // FIN Primer BUCLE
    
    double pi=0;             // Defino pi y el error de pi. Los inicializo a cero por el m�todo para obtener la media y la SD.
    double err=0;
    
    for (int j=0; j<cota; j++) {
        pi = pi_ar[j]/cota + pi;                 // Hago la media de todos los pi's calculados
    }
    
    for (int j=0; j<cota; j++) {
        err = err + pow(pi-pi_ar[j],2)/cota;     // Calculo la desviaci�n est�ndar de los pi's calculados. Consulta su definici�n
    }                                            // para m�s info, pero es sumar estos t�rminos y...
    
    err = sqrt(err);                             // ... hacer la raiz cuadrada de lo que te salga.
    
    
    cout.precision(15); // Estos son el n�mero de digitos que quiero que se expulsen por pantalla. Puedes aumentarlo si quieres.
    
    // Sacamos los resultados por pantalla para disfrute del usuario:
    
    cout<<endl<<"  +----------------------------------------------------------------------------------------+";
    cout<<endl<<"  �                       "<<"Pi = "<<pi<<"  +/-  "<<err;
    cout<<endl<<"  �";
    cout<<endl<<"  �                "<<"o, dicho de otra manera, el valor de pi se encuentra entre";
    cout<<endl<<"  �                       "<<pi+err<<"   y   "<<pi-err;
    cout<<endl<<"  +----------------------------------------------------------------------------------------+"<<endl<<endl;

    
    return 0;  // Y hemos terminado. Cerramos el chiringuito.

}


