/*
 
  ������+ ��+   ��+ �����+ ���+   ��+��������+��+   ��+���+   ���+    �������+������+  �����+  ������+��������+��+   ��+������+ �������+
 ��+---��+���   �����+--��+����+  ���+--��+--+���   �������+ �����    ��+----+��+--��+��+--��+��+----++--��+--+���   �����+--��+��+----+
 ���   ������   �������������+��+ ���   ���   ���   �����+����+���    �����+  ������++�����������        ���   ���   ���������++�����+
 ���__ ������   �����+--������+��+���   ���   ���   ������+��++���    ��+--+  ��+--��+��+--������        ���   ���   �����+--��+��+--+
 +������+++������++���  ������ +�����   ���   +������++��� +-+ ���    ���     ���  ������  ���+������+   ���   +������++���  ����������+
  +--��-+  +-----+ +-+  +-++-+  +---+   +-+    +-----+ +-+     +-+    +-+     +-+  +-++-+  +-+ +-----+   +-+    +-----+ +-+  +-++------+
 
                                                            PRESENTA
                   _____________________________________________________________________________________________
                                 _                                  _              _
                                ' )   | | _ _    _| _       _  _   (  _  _. _    /| ) _  _.| _  _ \
                                ._).  |_|_\(_)  (_|(/_  |_|| |(_|  _)(/_| |(/_  | |_)(_|_\||(/_(_| |
                                                                                 \                /
 
 Qu� pasa chavales, muy buenas a todos, aqu� Crespo comentando (xD en serio, willy pls). Con este c�digo, escrito en C++, vamos a hacer
 que este ordenador calcule pi utilizando el m�todo favorito de todo el mundo: el uso de Series... No particularmente la serie que vamos
 a usar, pero cog�is la idea.
 Si quieres saber las ideas b�sicas de este algoritmo o no sabes como coj***s has llegado aqu� y qu� es este c�digo
 hablandome as� wtf, te recomiendo pasarte por YouTube y verte este v�deo
 -->  https://youtu.be/DQ5qqHukkAc  <--.
 
 Si no ves un mont�n de s�mbolos raros, te recomiendo que estires el tama�o de tu ventana, te llevar�s una sorpresa --->
 
 Vamos all�: como hab�is visto, vamos a explotar esto:
 
                                        _____
                                        \       1      pi^2
                                        /     ----- = ------
                                       /_____  n^2      6
                                          n
 
 Si no sabes lo que quiere decir el primer s�mbolo: es un sumatorio. Quiere decir que sumamos todos los t�rminos que contengan una n,
 empezando por el 1 y (en nuestro caso) no terminando nunca. Las series son sumas infinitas de t�rminos... pero si cogemos bastantes 
 al menos nos aproximaremos a pi.
 
 Por cierto, si quieres saber como Euler obtuvo este resultado, puedes consulta una demostraci�n aqu�
    ---->  http://gaussianos.com/el-problema-de-basilea/
 Puede que necesites saber algo de An�lisis para entenderlo... :P
 
 Si te has paseado por los otros c�digos (Pol�gonos y Montecarlo) te habr�s dado cuenta que tales programas aparte de dar un valor
 apr�ximado de pi, dan tambi�n el error que cometemos; dan el rango en el que el valor real de pi est�. Bien, en este caso no he 
 sabido programar unas cotas. Cuando se ejecuta la suma infinita se llega al valor de pi, pero si no sumas infinitos t�rminos siempre
 estar�s POR DEBAJO de tal cifra. Hubiera sido genial encontrar una cota superior que tambi�n convergiera a pi para N muy grande, pero
 no la he encontrado. Si eres un matem�tico muy listo y sabes como hacerlo, hazmelo saber; no tanto por corregir el c�digo, si no por
 curiosidad (--> qfracture@gmail.com)
 
 As� he nombrado cada variable:
 
   *  N   : el n�mero de t�rminos que vamos a sumar.
   *  S   : es la suma de los N t�rminos.
   *  pi  : valor de pi obtenido multiplicando la suma por 6 y haciendo la raiz cuadrada (tal y como indica la serie).
 
 */


#include <iostream>  // Cargo librer�as (colecciones de funciones ya hechas que hacen cositas): "iostream" me permite sacar texto
#include <cmath>     // y n�meros por el terminal, para que puedas ver el valor de pi, y "cmath" es una colecci�n de funciones
#include <fstream>   // matem�ticas que necesito, como elevar al cuadrado y hacer la raiz cuadrada.

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
    cout<<"                  +-++-+-  +-+- --  +-+  +-++-+  +-+-       +-++-+--+-+-++-+"<<endl;
    cout<<"                  �  +-��  �  � ��  � �   ��+�   �-+�  ---  +-++� +-+�+� +-+"<<endl;
    cout<<"                  +-+- ---++-++-+--++-+  --++-+  -  -       +-++-+-+--+-++-+"<<endl;
    
    cout<<endl<<"                  Sumas infinitas... �Al alcance de tu propio dispositivo!"<<endl<<endl;
    
    cout<<"_____________________________________________________________________________________________"<<endl<<endl;
    cout<<"                                         ADVERTENCIA                                     "<<endl;
    cout<<"Si est� usando este c�digo en un compilador online, puede ser que utilizar un n�mero excesivo"<<endl;
    cout<<" de t�rminos haga que el c�lculo necesite tanto tiempo para ser computado que el compilador lo"<<endl;
    cout<<"               aborte autom�ticamente. En ese caso, pruebe un n�mero menor."<<endl;
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    double N = 12345;         // N�MERO DE T�RMINOS A SUMAR. �CAMBIAD ESTO!
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Se introduce tal n�mero por terminal:
    
    cout<<endl<<"  +---------------------------------------------------------------------------------------------+";
    cout<<endl<<"  �                      N�mero de t�rminos que quierer sumar : "<<N;
    cout<<endl<<"  +---------------------------------------------------------------------------------------------+";
    
    double S=0;  // Defino la suma total de los t�rminos y la inicializo a 0.

    for (int i=0; i<N; i++) {  // Bucle, recorre todo los naturales hasta N.
        S=S+ 1/pow(i+1,2);     // En cada vuelta se a�ade a S el siguiente t�rmino.
    }
    
    double pi=sqrt(6*S);       // Se calcula pi.
    
    
    cout.precision(15); // Estos son el n�mero de digitos que quiero que se expulsen por pantalla. Puedes aumentarlo si quieres.
    
    // Sacamos los resultados por pantalla para disfrute del usuario:
    
    cout<<endl<<"  +----------------------------------------------------------------------------------------+";
    cout<<endl<<"  �                            "<<"Pi = "<<pi;
    cout<<endl<<"  �";
    cout<<endl<<"  �                "<<"El valor real de pi se encuentra algo m�s arriba";
    cout<<endl<<"  +----------------------------------------------------------------------------------------+"<<endl<<endl;
    
    
    return 0;  // Y hemos terminado. Cerramos el chiringuito.

}





