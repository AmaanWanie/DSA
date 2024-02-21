#include<stdio.h>

void LCS(char X[], char Y[], int len_X, int len_Y);
int maxValue(int a, int b);
void printCostMatrix(int cost[6][6], int len_X, int len_Y);

int maxValue(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}


void printCostMatrix(int cost[6][6], int len_X, int len_Y) {
    printf("Cost Matrix:\n");
    for (int i = 0; i <= len_X; i++) {
        for (int j = 0; j <= len_Y; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}

void LCS(char X[], char Y[], int len_X, int len_Y) {
    int cost[len_X + 1][len_Y + 1];
    
    for(int i=0;i<=len_X;i++){
    	cost[i][0]=0;
	}
	for(int j=0;j<=len_Y;j++){
    	cost[0][j]=0;
	}
    

    for (int i = 1; i <= len_X; i++) {
        for (int j = 1; j <= len_Y; j++) {
        	
        	
             if (X[i - 1] == Y[j - 1])
                cost[i][j] = 1 + cost[i - 1][j - 1];
            else
                cost[i][j] = maxValue(cost[i - 1][j], cost[i][j - 1]);
        }
    }


    printf("The length of the longest subsequence is: %d\n", cost[len_X][len_Y]);
    
    printCostMatrix(cost, len_X, len_Y);
}

int main() {
    char X[] = {'a', 'b', 'a', 'a', 'b'};
    char Y[] = {'b', 'a', 'b', 'b', 'a'};

    int len_X = sizeof(X) / sizeof(X[0]);
    int len_Y = sizeof(Y) / sizeof(Y[0]);

    LCS(X, Y, len_X, len_Y);

    return 0;
}
