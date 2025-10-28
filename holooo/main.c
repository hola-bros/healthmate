#include <iostream>
#include <vector>
using namespace std;

void arreglos ();
void ciclar ();
void condicional ();

int main (){

    int op;

    cout <<"================================\n";
    cout <<"========MENÚ========\n";
    cout <<"1. Trabajar con arreglos  (pulsa 1)\n ";
    cout <<"2. Usar el ciclo do_while (pulsa 2)\n ";
    cout <<"3. Usar el condicional if (pulsa 3)\n ";
    cout <<"================================\n";
    cout <<  " Elige una de estas opciones: ";
    cin >> op;

    switch (op){

        case 1: arreglos();
            break;
        case 2: ciclar();
            break;
        case 3: condicional();
            break;
        default:
            cout <<"esta opcion no es valida\n";
            break;

    }

    return 0;

}

void arreglos(){
    string  a, b, c;

    cout <<"\n ingresa los nombres de tres autos separados por espacios: ";
    cin >> a >> b >> c;

    vector<string> autos={a, b, c};

    for (int i = 0;  i < autos.size (); i++ ){
        cout <<"Autos"<< i + 1<< ":" << autos[i] << endl;

    }
}

void ciclar(){
    int a, b;
    int sum;
    int cont = 0;
    do{
        cout << "ingresa el valor de a:  ";
        cin >> a;
        cout << " ingresa el valor de b: ";
        cin >> b;

        sum= a+b;
        cout <<"La suma es: "<<sum <<endl;

        cont++;

    } while(cont<4);

}

void condicional(){
    float n;

    cout << "ingresa un numero: ";
    cin >> n;

    if(n<0){
        cout<<"el numero es negativo ";
    }
    else if (n>0){
        cout << "el numero es positivo";
    }
    else
        cout << "el numero es cero "<<endl;

}
