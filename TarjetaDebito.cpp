#include <iostream>
#include <stdlib.h>

using namespace std;

class TarjetaDebito{
    private:
        int saldo;
    public:
        TarjetaDebito(int saldo);
        int getSaldo();
        void depositar(int saldo);
        bool retirar(int saldo);

};

//constructor de la clase TarjetaDebito y despues se muestran los metodos de dicha clase
TarjetaDebito::TarjetaDebito(int saldo){
    this->saldo = saldo;
}

int TarjetaDebito::getSaldo(){
    cout << "Saldo total: $" << saldo <<endl;
    return saldo;
}

void TarjetaDebito::depositar(int monto){
    
    cout << "Se ha depositado: $" << monto << endl;
    saldo+=monto;
    cout << "Saldo total: $" << saldo<< endl;
}

bool TarjetaDebito::retirar(int monto){
    if (saldo>=monto){  
        cout << "Se han retirado: $" << monto << endl;
        saldo-=monto;
        cout << "Saldo total: $" << saldo << endl;
    }else{
        cout << "Saldo insuficiente. No se puede retirar.";
    }
    
}


class TarjetaCredito : public TarjetaDebito{
    private:
        int Limite_Credito;
    
    public:
        TarjetaCredito(int saldo,int Limite_Credito);
        int getLimite_Credito();
        void cambiarLimite();

};

//Constructor TarjetaCredito y despues se muestran los metodos de dicha clase
TarjetaCredito::TarjetaCredito(int saldo, int Limite_Credito) : TarjetaDebito(saldo){
    this->Limite_Credito= Limite_Credito;
}

int TarjetaCredito::getLimite_Credito(){
    cout << "El limite de credito actual es de: $" << Limite_Credito << endl;
    return Limite_Credito;
}
void TarjetaCredito::cambiarLimite(){
    cout << "El limite de credito ha cambiado" << endl;
    cout << "El nuevo limite de credito es: $" << Limite_Credito << endl;
}



int main(){
cout << "Prueba Tarjeta de Debito " << endl;
TarjetaDebito Edgar(5000);
Edgar.getSaldo();
Edgar.depositar(2000);
Edgar.retirar(100);

printf("\n******************************\n");
cout << "Prueba Tarjeta de Credito" << endl;

TarjetaCredito Javier(7000, 15000);
Javier.getLimite_Credito();
Javier.getSaldo();
Javier.depositar(3000);
Javier.retirar(5000);
}
