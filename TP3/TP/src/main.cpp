#include "../include/estruturas.hpp"
#include <iostream>



int main(){
    int tseg=0, nops=0;
    std::cin>>tseg>>nops;
    SegTree S(tseg);

    char c;
    for(int i=0; i<nops; i++){
        std::cin>>c;
        if(c =='u'){
            int pos;
            int a, b, c, d;

            std::cin>>pos;
            std::cin>>a>>b;
            std::cin>>c>>d;
            
            Matriz aux;

            aux.AtualizaMatriz(a, b, c, d);
            S.Update(pos, aux, 1, 0, tseg-1);
        }
        else if(c == 'q'){
            int t0,tx;
            int x,y;

            std::cin>>t0>>tx>>x>>y;

            Matriz aux = S.Query(t0, tx, 1, 0, tseg-1);

            Ponto p;
            p.x_=x;
            p.y_=y;

            Ponto out = aux.MultiplicaPonto(p);

            std::cout<<out.x_<<" "<<out.y_<<"\n";
        }
    }


    return 0;
}
