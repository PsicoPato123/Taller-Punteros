#include <iostream>
#define RESET "\033[0m"
#define AZUL "\033[34m"
#define MORADO "\033[35m"

//punto 1. Intercambio de valores 
void camb(int *n1, int *n2){
    int t= *n1;
    *n1 = *n2;
    *n2=t;}

    //punto 2. Suma de arreglo dinámico
int add (){
  int x;
    std::cout<<"ingrese un numero de elementos: ";
    std::cin>>x;
    //new brinda lo dinámico :D
    int* n = new int[x];
    int suma =0;

    for (int i= 0; i<x; i++) {
            std::cout<<"ingresa los valores: "<<"[ " << i << "] ";
        std::cin>> n [i];  
     suma += *(n+i);     
    }
    std::cout<<"la suma es: "<<suma;
    delete [] n;
}

//punto 3. Definir el número mayor 
int mayor(){
    int x;
    std::cout<<"\nIngrese un numero de elementos: ";
    std::cin>>x;
     if(x<=0){
        std::cout<<"Arreglo vacio :c ";
        return 0;}

    int* n = new int[x];

    for (int i= 0; i<x; i++) {
    std::cout<<"Ingresa los valores: ";
    std::cin>> *(n+i);
    }

    int max= *n;
    for (int i= 1; i<x; i++) { 
    if(max<n[i]) {
        max=*(n+i);
    
}   delete []n;
    return max; 
}}

//punto 4. Callback simple 
 int dob (int n){
    return n*2;}
    int tri (int n){
    return n*3; }
    int ele (int n) {
    return n*n*n*n;
    }

    void call () { 
    int x; 
    std::cout<<"Crea tu arreglo ^w^\n"; 
    std::cout<<"Ingresa el tamaño: ";
    std::cin>>x;

     int* n= new int [x]; 

    for (int i=0; i<x; i++) {
    std::cout<<"Ingresa los valores :D: "<<"["<<i<<"] ";
    std::cin>>n [i];
    }
    int (*op)(int); 
    int opt; 
    std::cout<<"1. Duplicar los valores\n2. Triplicar los valores\n3. Elevado a 4";
    std::cin>>opt;

        if (opt==1){
            std::cout<<"Duplicado ^w^: ";
            op = dob;
         } 
        else if (opt==2){
            std::cout<<"Triplicado ^w^: ";
            op = tri;
            }
        else if (opt==3){
            std::cout<<"Elevado a la 4 ^w^: ";
            op = ele;
            }
        else{
            std::cout<<"Opción inválida X.X ";
            delete []n;
            return;
        }

        for (int i=0; i<x; i++){
            n[i] = op (n[i]);
        }
        
        std::cout<<"esto es :D : "; 
        for(int i=0; i<x; i++) {
            std::cout<<n[i]<<" ";
        }
        delete[] n;
    }

//punto 5. reinterpretación de memoria con casting   
void cast (){
    float user;
    std::cout<<"Ingresa un numero de cualquier tipo: ";
    std::cin>>user; 
    int* pint= (int*)&user;  //Valor interpretado
    //char* pchar= (char*)&user;  //recorre los bytes 
    char* po= (char*) &user;
    std::cout<<"Direccion de "<<user<<" "<<&user<<std::endl;
    std::cout<< "Direccion como entero: "<<pint<<std::endl;
    std::cout<< "Direccion como un char: "<<(void*)po <<std::endl; 

    
    for (int i=0; i<sizeof(float); i++){
    std::cout<<"Bytes: "<<i<<" "<< (int)*(po+i);
    }
}

void menu (){
std::cout<<AZUL<<"Bienvenido al menu ^w^ "<<"\nSelecciona una opcion\n"<<RESET;
int opt;
do{
    std::cout<<MORADO<< "\n1. Intercambio de valores usando punteros\n";
    std::cout<< "\n2. Suma de elementos en un arreglo dinamico\n" ;   
    std::cout<< "\n3. Encontrar el elemento mayor\n" ;   
    std::cout<< "\n4. Callback simple\n";
    std::cout<< "\n5. Reinterpretacion de memoria con casting\n";
    std::cout<< "\n6. Salir\n";
    std::cout<< "Seleccione una opcion: "<< RESET; 
    std::cin>> opt;

switch (opt){
case 1: {
int x, y; 
std::cout<<"Enter two numbers :D\n";
std::cin>>x>>y;
std::cout<<"POV before magic unu\nX="<<x<<"\nY="<<y<<std::endl;
camb(&x,&y);
std ::cout<<"POV after magic ^w^\nX= "<<x<<"\nY="<<y<<std::endl;
    break;
}
case 2: 
add ();
break;

case 3:{
    std::cout<<"Buscate un mayor :D"; 
    int is = mayor();
    
    std::cout<<"Tu mayor es:"<<is; 
}
break;

case 4: 
call();

break;

case 5:
cast();
break; 

default:
std::cout<<"Opción inválida X.X \n"; 
    break;

}; } while (opt !=6);}

int main(){
    menu();
   return 0;
}