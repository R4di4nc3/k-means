#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

#define LENGHT 6
#define N 10
#define DIMENSIONS 2

//define the structure cluster containing a space for the atribution of a specie and the centroid of the cluster
struct clusters
{
    double points[LENGHT][DIMENSIONS];
    int qtd;
    double distanceToP;
    double centroid[DIMENSIONS];
};

//function to calculate eucledian distance
double distance(double p1[], double p2[]){
    double sum = 0;
    for (int i = 0; i < DIMENSIONS; i++){
        sum += pow(p2[i]-p1[i],2);
    }

    return sqrt(sum);
}

void kmeans (int k, double species[LENGHT][DIMENSIONS]){
    srand(time(0));
    int indice;
    double smaller, sum;

    //initialize the k clusters
    clusters cluster[N];
    for (int i = 0; i<k; i++){
        for(int j = 0; j<DIMENSIONS; j++){
            cluster[i].centroid[j] = rand() % 101;
        }
    }

    //repeat the processe for 100 times
    for (int z = 0; z < 100; z++){
        for (int i = 0; i < k; i++){
            cluster[i].qtd = 0;
        }
        //assign each point (specie) to a cluster
        for (int i=0; i < LENGHT; i++){

            //calculate de distance between the point and the centroid
            for(int j = 0; j < k; j++){
                cluster[j].distanceToP = distance(cluster[j].centroid, species[i]);
            }
            
            //compare the distances of the point to each cluster
            smaller = cluster[0].distanceToP;
            indice = 0;
            for(int j = 1; j < k; j++){
                if(smaller > cluster[j].distanceToP){
                    smaller = cluster[j].distanceToP;
                    indice = j;
                }
            }

            //assign the point to the cluster and update the number of points in the cluster
            for(int j = 0; j < DIMENSIONS; j++){
                cluster[indice].points[cluster[indice].qtd][j] = species[i][j];
                cluster[indice].qtd++;
            }

        }

        //calculates the mean of all the coordenates of a cluster and uptade its centroid
        for (int i = 0; i < k; i++){   
            for (int j = 0; j < DIMENSIONS; j++){
                sum = 0;
                for (int l = 0; l < LENGHT; l++){
                    sum += cluster[i].points[l][j];
                }

                sum = sum/cluster[i].qtd;
                cluster[i].centroid[j] = sum;
            }
        }
    }


    for (int i = 0; i < k; i++){
        for (int j = 0; j < LENGHT; j++){
            for (int l = 0; l < DIMENSIONS; l++){
                cout << cluster[i].points[j][l] << ", ";
            }
            cout << "tipo " << i+1 << endl;
        }
        cout << endl;
    }

}

int main(){
    int k;
    cin >> k;

    //read file and define an array with multiple points representing the flowers and its atributes
    ifstream data("iris.data");
    double species[LENGHT][DIMENSIONS] = { {1, 2}, {2, 3}, {3, 4}, {6, 5}, {7, 6}, {8, 7}};

    kmeans(k, species);
}