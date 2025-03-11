#include <iostream>
using namespace std;
//Area triangulo (base * Altura) / 2
class areaT {
  public:
    float base,altura,area;
    areaT (float b, float a);
    ~areaT();
    void calcularArea();
    void mostrarArea();
};

areaT::areaT(float b, float a){
  this->base = b;
  this->altura = a;
}
areaT::~areaT(){
  cout << "\nDestruyendo objeto" << endl;
}
void areaT::calcularArea(){
  this->area = (this->base * this->altura)/2;
}
void areaT::mostrarArea(){
  cout << "\nEl area del triangulo es: " << this->area;
}

int main() { 
  areaT at(10,5);
  at.calcularArea();
  at.mostrarArea();
}