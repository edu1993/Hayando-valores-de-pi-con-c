
/*
 
  ������+ ��+   ��+ �����+ ���+   ��+��������+��+   ��+���+   ���+    �������+������+  �����+  ������+��������+��+   ��+������+ �������+
 ��+---��+���   �����+--��+����+  ���+--��+--+���   �������+ �����    ��+----+��+--��+��+--��+��+----++--��+--+���   �����+--��+��+----+
 ���   ������   �������������+��+ ���   ���   ���   �����+����+���    �����+  ������++�����������        ���   ���   ���������++�����+
 ���__ ������   �����+--������+��+���   ���   ���   ������+��++���    ��+--+  ��+--��+��+--������        ���   ���   �����+--��+��+--+
 +������+++������++���  ������ +�����   ���   +������++��� +-+ ���    ���     ���  ������  ���+������+   ���   +������++���  ����������+
  +--��-+  +-----+ +-+  +-++-+  +---+   +-+    +-----+ +-+     +-+    +-+     +-+  +-++-+  +-+ +-----+   +-+    +-----+ +-+  +-++------+
 
                                                                 PRESENTA
                      _____________________________________________________________________________________________
                        ,
                       '|    |\/| _�_|_ _  _| _    _| _    /\  _ _    � _ _  _  _| _  _   /|~) _ |� _  _  _  _  _\
                       _|_.  |  |(/_ | (_)(_|(_)  (_|(/_  /~~\| (_||_||| | |(/_(_|(/__\  | |~ (_)||(_|(_)| |(_)_\ |
                                                                  |                       \         _|           /
 
 Qu� pasa chavales, muy buenas a todos, aqu� Crespo comentando (xD willy pls). Con este c�digo, escrito en C++, vamos a hacer que
 este ordenador calcule pi utilizando el m�todo que nuestro Antiguos usaban: calculando pol�gonos de lado 2*n (dos veces n).
 Si quieres saber las ideas b�sicas de este algoritmo o no sabes como coj***s has llegado aqu� y qu� es este c�digo
 hablandome as� wtf, te recomiendo pasarte por YouTube y verte este v�deo 
 --> https://youtu.be/DQ5qqHukkAc   <--.
 Vamos ahora a la miga: Imagina que tenemos DOS pol�gonos de "2n" lados: Uno inscrito dentro de una circunferencia de radio "r" 
 (es decir, cuyos vertices tocan la circunferencia, est� dentro del circulo) y otro circunscrito (es decir, cuyos lados tocan 
 la circunferencia, est�n por fuera del circulo). 
 En cualquier pol�gono siempre puedo tirar dos l�neas desde el centro a dos v�rtices contiguos y formar un tri�ngulo 
 (el menor que se puede formar de esta manera):
 
  
                                                          _____________________ (B)
                                                          \     d   |         /
                                                           \________|________/ h2
                                                        (A) \   l   |       /
                                                             \      |      /
                                                              \     |r    /
                                                            h1 \    |    /
                                                                \   |   /
                                                                 \  |  /
                                                                  \ | /
                                                                   \ /  <----------- al �ngulo del tri�ngulo vamos a llamarlo "ang"
                                                                    .
                                                                  centro (O)
 ...donde:
    
    * r   --> radio del circunferencia.
    * h2  --> distancia centro-vertice (OB) del poligono que est� CIRCUNSCRITO (que es el poligono est� por fuera del c�rculo,
             con los lados tocando la circunferencia).
    * h1  --> distancia centro-vertice (OA) del pol�gono que est� INSCRITO (que es el poligono est� dentro del c�rculo,
             con los v�rtices tocando la circunferencia).
    * l   --> es la MITAD del lado del poligono interno.
    * d   --> es la MITAD del lado del poligono externo.
    * ang --> angulo formado por OA y OB. Si el poligono tiene n lados, entonces
              sabemos cuanto vale: una vuelta completa son 2*pi, luego si tiene n lados,
 
                                                    ang = 2*pi/n
 
 Si no ves un carajo del gr�fico te recomiendo que estires el tama�o de tu ventana, te llevar�s una sorpresa --->
 Tambi�n es bastante recomendable que, si te quiere enterar bien de esto, te lo dibujes en un papel. Really.
 
 Dos definciones m�s: sea...
 
    * A_n --> el per�metro del pol�gono de n lados inscrito.
    * B_n --> el per�metro del pol�gono de n lados cricunscrito.
 
 A las cuentas: vamos a calcular cuanto vale "l" y cuanto vale "d". Los necesitaremos para saber cuanto son los per�metros 
 que es lo que buscamos, oh�. Por trigonometr�a b�sica (definici�n de seno), "l" verifica:
 
                                                   l = r * sin( pi/n )
 
 ... y "d" verifica:
 
                                                   d = r * tan( pi/n )
 
 Por lo tanto los respectivos per�metros ser�n el n�mero de lados, n, por el lado, 2l y 2d respectivamente:
 
                  A_n = 2 * n * r * sin( pi/n )        B_n = 2 * n * r * tan( pi/n ) = A_n / cos(pi/n)
 
 Entonces, el per�metro de un pol�gono con el doble de lados debe verficar:
 
                  A_2n = 4 * n * r * sin( pi/2n )        B_2n = 4 * n * r * tan( pi/2n ) = A_2n / cos(pi/2n)
 
 El objetivo, ahora, es dejar A_2n y B_2n en funci�n de A_n y B_n, es decir, que no dependamos de calcular �ngulos (que
 requieren de pi) para saber cuanto vale los per�metros. De este modo partiendo de un pol�gono muy sencillo cuyas dimensiones puedan
 ser c�lculados usando identidades trigonometricas muy sencillas, podemos ir generando los pol�gonos de m�s y m�s lados.
 
 No voy a escribir explicitamente como poner unos en funci�n de los otros; es un desarrollo largo y tengo v�deos que hacer! Pero
 si quer�is intentarlo, usad todas las identidades trigonom�tricas que pod�is, especialmente las del angulo doble y �ngulo mitad ;)
 
 El resultado es:
 
                                                    B_2n = 2 * A_n * B_n / ( A_n + B_n )
                                                    A_2n = raiz cuadrada de { A_n * B_2n }
 
 Dado que A se acerca al perimetro de la circunferencia desde valores menores y B desde valores mayores, podemos usar estos para 
 calcular los errores del m�todo. Es decir, que, una vez paremos en un cierto n�mero de lados, tomaremos la media de ambos pi's 
 calculados con los diferentes per�metros como el valor de este, y la diferencia de estos como el error que estamos comentiendo;
 as� tendremos el rango de valores en lo que el verdadero pi se encuentra.
 
 Quiero agradecer ENORMEMENTE a Diego Soler Polo por ayudarme a encontrar este algoritmo. Sin �l, muchos aspectos de este v�deo
 no ser�an posibles... y este c�digo menos. 
 
 
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
    cout<<"              +-++-+-  +-+- --  +-+  +-++-+  +-+-       +-++-+-  -+-++-+++++-++-+"<<endl;
    cout<<"              �  +-��  �  � ��  � �   ��+�   �-+�  ---  �-+� ��  �� -� ����� �+-+"<<endl;
    cout<<"              +-+- ---++-++-+--++-+  --++-+  -  -       -  +-+--+-+-++-+++++-++-+"<<endl;
    
    cout<<endl<<"                       Dividiendo per�metros entre diametros desde 2017"<<endl<<endl;
    
    cout<<"_____________________________________________________________________________________________"<<endl<<endl;
    cout<<"                                         ADVERTENCIA                                     "<<endl;
    cout<<"Si est� usando este c�digo en un compilador online, puede ser que utilizar un n�mero excesivo"<<endl;
    cout<<" de lados haga que el c�lculo necesite tanto tiempo para ser computado que el compilador lo"<<endl;
    cout<<"               aborte autom�ticamente. En ese caso, pruebe un n�mero menor."<<endl;
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    
    int n = 12345  ;         // N�MERO DE LADOS DEL POL�GONO. �CAMBIAD ESTO!
    
    ///////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
    
    // Se expulsa tal n�mero por terminal:
    
    cout<<endl<<"  +----------------------------------------------------------------------------------------+";
    cout<<endl<<"  �                 N�mero de lados m�ximo del pol�gono : "<<n;
    cout<<endl<<"  +----------------------------------------------------------------------------------------+";
    
    double r=1;  // Este es RADIO DE LA CIRCUNFERENCIA. Puedes cambiarlo; el valor de pi no se ve afectado.

    double A;    // Defino los Per�metros de los pol�gonos inscritos y circunscritos.
    double B;
    
    A=4*sqrt(2)*r;  // Cargo los per�metros de un CUADRADO inscrito (A) y circunscrito (B). Estos valores pueden ser f�cilmente
    B=8*r;          // obtenidos con el teorema de pitagoras, no pi required.
    
    double m=4;     // Este es el n�mero de lados de los pol�gonos con los que estamos trabajando.
    
    while (m*2<=n) {  // BUCLE. Si el n�mero de lados del pol�gono a generar supera el n�mero impuesto por usuario, para.
        
        B=2*A*B/(A+B);      // Calculo de los per�metros con el doble de lados. A cada vuelta los valores de A y B se sobreeescriben.
        A=sqrt(A*B);
        
        m=m*2;              // El n�mero de lados se duplica en cada vuelta.
        
    }                 // Fin de BUCLE
    
    double pi=(  A/2/r + B/2/r  )/2;         // Calculamos pi como la media de los valores de pi de cada perimetro...
    double err = abs(  A/2/r - B/2/r  )/2;   // ... y el error como la resta.
    
    cout.precision(15); // Estos son el n�mero de digitos que quiero que se expulsen por pantalla. Puedes aumentarlo si quieres.
    
    // Sacamos los resultados por pantalla para disfrute del usuario:
    
    cout<<endl<<"  +----------------------------------------------------------------------------------------+";
    cout<<endl<<"  �                Con un pol�gono de "<<m<<" lados, obtenemos:";
    cout<<endl<<"  �";
    cout<<endl<<"  �                       "<<"Pi = "<<pi<<"  +/-  "<<err;
    cout<<endl<<"  �";
    cout<<endl<<"  �                "<<"o, dicho de otra manera, el valor de pi se encuentra entre";
    cout<<endl<<"  �                       "<<pi+err<<"   y   "<<pi-err;
    cout<<endl<<"  +----------------------------------------------------------------------------------------+"<<endl<<endl;
    
    
    return 0;  // Y hemos terminado. Cerramos el chiringuito.
    
}







