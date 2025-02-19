#include <iostream>
#include <cmath>
using namespace std;

#define N 6
#define M 2

struct especie
{
    float exCaule;
    float alCaule;
    float exFolha;
    float alFolha;
    int tipo;
};


void k_means(double x[][M], int k){
    int dist1, dist2;
    double group1[N+1][M];
    double group2[N+1][M];
    group1[0][0]=0;
    group1[0][1]=0;
    group2[0][0]=10;
    group1[0][1]=10;
    for(int a = 0; a<50; a++){
        for (int i = 0; i<=N; i++){
            dist1 = sqrt((pow(x[i][0]-group1[0][0], 2))+pow(x[i][1]-group1[0][1], 2));
            dist2 = sqrt((pow(x[i][0]-group2[0][0], 2))+pow(x[i][1]-group2[0][1], 2));
            if(dist1<dist2){
                group1[i+1][0] = x[i][0];
                group1[i+1][1] = x[i][1];
            }
            else{
                group2[i+1][0] = x[i][0];
                group2[i+1][1] = x[i][1];
            }
        }
    }

    for(int i = 0; i<=N; i++){
        for(int j = 0; j<M; j++){
            cout << group1[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    double x[N][M] = { {1, 2}, {2, 3}, {3, 4}, {6, 5}, {7, 6}, {8, 7}};
    int k = 2;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << x[i][j] << ' ';
        cout << endl;
    }
            
    k_means(x, k);
    
    return 0;
}