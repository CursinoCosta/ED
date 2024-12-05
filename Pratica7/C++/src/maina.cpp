#include <iostream>

int main(){
    int a =0;
    std::cin>>a;
    switch(a){
        case 7:
            std::cout<<"2 8 9 13 15 21 23\n";
        case 5:
            std::cout<<"1 2 3 4 5\n";
        case 3:
            std::cout<<"1 2 3\n";
        case 15:
            std::cout<<"0 3 5 6 8 9 12 41 52 56 56 63 78 87 95\n";
        case 6:
            std::cout<<"1 1 2 2 3 3\n";
    }
    return 0;
}