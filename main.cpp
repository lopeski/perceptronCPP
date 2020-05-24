#include <iostream>
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

class Perceptron
{
    public:
    float n = 0.5;
    int a, i, b, j, k, l, epocas;
    float y,u,erroSintax, u2, y2;
    bool erro = true;
    vector<float> vectorVazio{n,0.1,0.1,0.1,0.1};
    vector<float> vectorClasificacao{-1,0.3,0.7,0.2};
    vector< vector<float> > amostras{
                                     {-n,-n,-n,-n},
                                     {0.1,0.3,0.6,0.5},
                                     {0.4,0.7,0.9,0.7},
                                     {0.7,0.2,0.8,0.1}};
    vector<float> saidas {1,-1,-1,1};

    int nucleo(float ub) {
        if (ub >= 0) {
            return 1;
        } else {
            return -1;
        }
    }
    void Treinamento() {
        epocas =1;
            for (j = 0; j < 3; ++j) {
                cout << "Veja" << vectorVazio[j] << endl;
                while (!erro) {
                    u = 0.0;
                    for (int i1 = 0; i1 < 3; ++i1) {
                        u += vectorVazio[i1] * amostras[j][i1];
                    }
                    y = nucleo(u);
                    if (epocas == 500) {
                        cout << "NAO FOI" << endl;
                        break;
                    } else if (y != saidas[j]) {
                        cout <<"UM erro" << endl;
                        ++epocas;
                        erroSintax = saidas[j] - y;
                        for (int m = 0; m <= 4; ++m) {
                            cout <<"Corrigindo ..." << endl;
                            vectorVazio.at(m) = vectorVazio[m] + n * erroSintax * amostras[j][m];
                        }
                        erro = false;
                    }  else {
                        erro = true;
                        ++epocas;
                        cout << "BELEZA!" << endl;
                    }
                }
                cout << "Acabamos!" << endl;
                erro = false;
        }
        cout << "Epocas necessarias " << epocas << endl;

    }
    void Execucao() {
        int limite = vectorClasificacao.size();
        u2 = 0;
        for (int m = 0; m < 3; ++m) {
            u2 += vectorVazio[m] * vectorClasificacao[m];
            cout << u2 << endl;
        }
        cout << "A amostra " << u2 << endl;
        y2 = nucleo(u2);
        cout << "Y " << y2 << endl;
        if (y2 == 1) {
                cout << "A amostra " << y2 << "pertence a classe A " << endl;
            } else if (y2 == -1) {
                cout << "A amostra " << y2 << "pertence a classe B " << endl;
            }
    }

};

int main() {

    Perceptron IA;
    IA.Treinamento();
    IA.Execucao();
    return 0;
}
