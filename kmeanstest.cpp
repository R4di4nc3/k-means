#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#define N 6
#define M 2



struct cluster
{
    double pontos[N][M];
    int qtd;
    double centroide[M];
};


double distancia(double p1[], double p2[]){
    for (int i = 0)
}


void k_means(double x[][M], int k){
    srand(time(0));
    cluster clusters[2];
    for (int i = 0; i<2; i++){
        for(int j = 0; j<M; j++){
            clusters[i].centroide[j] = rand() % 101;
        }
    }

    for (int i = 0; i<k;i++){
        int dis = distancia(x[i], clusters[i].centroide);
    }

    

}

int main()
{
    double x[N][M] = { {1, 2}, {2, 3}, {3, 4}, {6, 5}, {7, 6}, {8, 7}};
    int k = 2;
    
            
    k_means(x, k);
    
    return 0;
}