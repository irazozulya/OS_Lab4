#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

struct Node {
    int number;
    int weight;
    vector<Node*> neightbours;
    vector<int> weightEdges;
    bool free = false;
};

void critical(vector<int>* path, int* length, Node Node);
void copyV(vector<int>* dest, vector<int> source);
bool condition(vector<Node*> Nodes);

int main() {
    clock_t start_time = clock();
    int nNodes, nEdges;
    nNodes = 15;
    vector<int> weightNodes(nNodes);

    int **adjacencyMatrix = new int *[nNodes];
    for (int i = 0; i < nNodes; i++) {
        adjacencyMatrix[i] = new int[nNodes];

        for (int j = 0; j < nNodes; j++) {
            adjacencyMatrix[i][j] = -1;
        }
    }
    vector<vector<int>> currentEdges = {
            {0,  2, 5},
            {1,  3, 5},
            {1,  4, 6},
            {2,  2, 6},
            {2,  2, 11},
            {3,  1, 10},
            {3,  3, 7},
            {4,  4, 11},
            {4,  3, 8},
            {5,  1, 9},
            {5,  2, 10},
            {6,  2, 10},
            {8,  4, 14},
            {9,  3, 13},
            {10, 6, 13},
            {10, 1, 11},
            {11, 2, 12}
    };
    vector<vector<int>> edges = currentEdges;

    nEdges = int(currentEdges.size());

    int edgeSum = 0;
    for (int i = 0; i < nEdges; i++) {
        adjacencyMatrix[edges[i][0]][edges[i][2]] = edges[i][1];
        edgeSum += edges[i][1];
    }
    
    cout << "\t 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n\t____________________________________________\n";
    for (int i = 0; i < nNodes; i++) {
         cout << i + 1 << " |\t";
         for (int j = 0; j < nNodes; j++) {
             
             if(adjacencyMatrix[i][j] > 0) {
                 cout << " " << adjacencyMatrix[i][j] << " ";
             }
             else {
                 cout << adjacencyMatrix[i][j] << " ";
             }
         }
         cout << endl;
     }
     
    int weight[] = {2, 3, 1, 2, 1, 4, 1, 1, 2, 1, 2, 1, 2, 4, 3};
    int weiSum = 0;
    for (int i = 0; i < nNodes; i++) {
        weightNodes.push_back(weight[i]);
        weiSum += weight[i];
    }
    
    vector<int> criticalPath;
    int maxL, weiPath = 0;
    do {
        
        for (int i = 0; i < nEdges; i++) {
            adjacencyMatrix[edges[i][0]][edges[i][2]] = edges[i][1];
        }
        
        for (int i = 0; i < nNodes; i++) {
            weightNodes.push_back(weight[i]);
        }
        
        criticalPath.clear();
        vector<Node *> Nodes(nNodes);
        
        for (int i = 0; i < nNodes; i++) {
            for (int j = 0; j < nNodes; j++) {
                if (Nodes[i] == nullptr)
                    Nodes[i] = new Node();
                    
                Nodes[i]->number = i;
                Nodes[i]->weight = weightNodes[i];
                
                if (adjacencyMatrix[i][j] > -1) {
                    if (Nodes[j] == nullptr)
                        Nodes[j] = new Node();
                        
                    Nodes[i]->neightbours.push_back(Nodes[j]);
                    Nodes[i]->weightEdges.push_back(adjacencyMatrix[i][j]);
                }
            }
        }
        
        while (condition(Nodes)) {
            int maxLength = 0;

            for (int i = 0; i < nNodes; i++) {
                if (Nodes[i]->free)
                    continue;
                    
                vector<int> path;
                int length = 0;
                critical(&path, &length, *Nodes[i]);
                
                if (length > maxLength) {
                    maxLength = length;
                    copyV(&criticalPath, path);
                }
            }
            for (int i = 0; i < criticalPath.size(); i++) {
                Nodes[criticalPath[i]]->free = true;
            }
            
            for (int i = 1; i < criticalPath.size(); i++) {
                int numEdge;
                for (int j = 0; j < Nodes[criticalPath[i - 1]]->neightbours.size(); j++) {
                    if (Nodes[criticalPath[i - 1]]->neightbours[j]->number == criticalPath[i]) {
                        numEdge = j;
                    }
                }
                Nodes[criticalPath[i - 1]]->weightEdges[numEdge] = 0;
            }
        }
        for (int i = 0; i < nNodes; i++) {
            Nodes[i]->free = false;
        }

        int maxLength = 0;

        for (int i = 0; i < nNodes; i++) {
            if (Nodes[i]->free)
                continue;

            vector<int> path;
            int length = 0;
            critical(&path, &length, *Nodes[i]);

            if (length > maxLength) {
                maxLength = length;
                copyV(&criticalPath, path);
            }
        }

        cout << endl;
        for (int i = 0; i < criticalPath.size(); i++) {
            cout << criticalPath[i] + 1 << " ";
            weiPath += weight[criticalPath[i]];
        }
        cout << endl << endl;
    } while(criticalPath.empty());
    
    cout << "Tкр = " << weiPath
        << "\nTMAX = " << weiSum
        << "\nNLOW = " << weiSum / weiPath
        << "\nTMIN = 8\nNMAX = " << nNodes
        << "\nNHIGH = 5\nTMAX = " << edgeSum << endl;
    
    float running_time = ((float) clock() - start_time) / CLOCKS_PER_SEC;
    cout << "Running time: " << running_time;
    
    return 0;
}

void critical(vector<int>* path, int* length, Node Node)
{
    path->push_back(Node.number);
    *length += Node.weight;

    if (Node.neightbours.size() == 0)
        return;

    if (Node.neightbours.size() > 1)
    {
        int tempMax = 0;
        int maxI;
        vector<vector<int>> tempPathes;

        for (int i = 0; i < Node.neightbours.size(); i++)
        {
            if (Node.neightbours[i]->free)
                continue;

            vector<int> tempPath;

            copyV(&tempPath, *path);
            int tempLength = Node.weightEdges[i];

            critical(&tempPath, &tempLength, *Node.neightbours[i]);

            tempPathes.push_back(tempPath);

            if (tempLength >= tempMax)
            {
                tempMax = tempLength;
                maxI = tempPathes.size() - 1;
            }
        }

        *length += tempMax;
        copyV(path, tempPathes[maxI]);
        return;
    }

    if (Node.neightbours[0]->free)
        return;

    critical(path, length, *Node.neightbours[0]);
    *length += Node.weightEdges[0];
}

void copyV(vector<int>* dest, vector<int> source)
{
    dest->clear();
    for (int i = 0; i < source.size(); i++)
    {
        dest->push_back(source[i]);
    }
}

bool condition(vector<Node*> Nodes)
{
    for (int i = 0; i < Nodes.size(); i++)
    {
        if (!Nodes[i]->free)
            return true;
    }
    return false;
}
