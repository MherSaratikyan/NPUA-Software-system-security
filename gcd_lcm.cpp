#include <iostream>

int gcd(int a,int b){
    while(a % b != 0){
        int c = a;
        a = b;
        b = c % b;
    }

    return b;
}

int lcm(unsigned a,unsigned b){
    return (a * b) / gcd(a,b);
}

int main(){
    int a,b;
    std::cout<<"Enter two unsigned numbers: ";
    std::cin>>a>>b;
    std::cout<<"\ngcd of numbers "<<a<<" and "<<b<<" is "<<gcd(a,b);
    std::cout<<"\nlcm of numbers "<<a<<" and "<<b<<" is "<<lcm(a,b);
}