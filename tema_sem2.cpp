#include <iostream>
using namespace std;

struct Stiva{
    int s[1000];
    int lungime = 0;
    void push(int x){
        s[lungime++] = x;
    }

    int pop(){
        return s[--lungime];
    }
};

struct Coada{
    // FOLOSESC S1 CA SA STOCHEZ TOATE ELEM DIN COADA
    // FOLOSESC S2 PENTRU FUNCTIA DE removeFromQueue
    Stiva s1, s2;

    void addInQueue(int x){
        s1.push(x);
    }

    int removeFromQueue(){
        // VERIFICA DACA COADA ESTE GOALA
        if (s2.lungime == 0 && s1.lungime == 0){
            cout << "Coada este goala";
            return;}

        // MUT TOATE ELEM DIN STIVA 1 IN STIVA 2 (O SA SE STEARGA DIN STIVA 1 PT CA DAU POP)
        if (s2.lungime == 0){
            while(s1.lungime != 0)
                s2.push(s1.pop());
        }

        // ELEM ELIMINAT DIN COADA ESTE X
        // IL ELIMIN SI DIN STIVA 2
        int x = s2.pop();

        // MUT CELELALTE ELEM INAPOI IN STIVA 1
        while(s2.lungime != 0)
            s1.push(s2.pop());
        return x;
    }

    void printQ(){
        for (int i = 0; i < s1.lungime; i++)
            cout << s1.s[i];
    }
};


int main(){
    Coada coada;
    coada.addInQueue(1);
    coada.addInQueue(2);
    coada.addInQueue(3);
    coada.printQ();
    cout << endl;
    cout << coada.removeFromQueue() << endl;
    coada.printQ();
    return 0;
}