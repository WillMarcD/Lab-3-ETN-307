#include <iostream>
#include<cmath>
#include <windows.h>
#define MAX 100
using namespace std;

float determinante(float X[][MAX], int orden);
float cof(float X[][MAX], int orden, int fila, int columna);
COORD coord={0,0};

void gotoxy(int x, int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);	
}

int main(){
int m,n,j,k;

cout<<"Introduzca el numero de filas de A: ";
cin>>m;
cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
cin>>n;
cout<<"Introduzca el numero de filas de B: ";
cin>>j;
cout<<"Introduzca el numero de columnas de B: ";
cin>>k;

float A[MAX][MAX],B[MAX][MAX];

for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){			//Llenamos la matriz A
		gotoxy(j*5,5+i);
		cin>>A[i][j];
	}
}

for(int i=0;i<j;i++){
	for(int l=0;l<k;l++){
		gotoxy(50+l*5,5+i);			//Llenamos la matriz B
		cin>>B[i][l];
	}
}

int op1;
if(m>=j){
	gotoxy(0,m+6);
}else if(j>m){
	gotoxy(0,j+6);	
}
again:
cout<<"\nQue operacion desea realizar (1->suma; 2->resta; 3->multiplicacion; 4->otro; 5-->salir): ";
cin>>op1;
cout<<"\n\n";
if(op1==1){
	if(m==j && n==k){
	float C[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		C[i][j]=A[i][j]+B[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
      	for (int j = 0; j < n; j++){							//Suma de matrices A y B
        cout <<"	"<<C[i][j]<<"	";
      	}
    cout << "\n";
	}    		
   	cout<<"	"<<"\nHECHO!"<<endl;
   	goto again;
	}else{
	cout<<"\nERROR! A y B deben ser del mismo tamano"<<endl;
	goto again;
	}	
}else if(op1==2){
	if(m==j && n==k){
	float C[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		C[i][j]=A[i][j]-B[i][j];
		}
	}
	for (int i = 0; i < m; i++) {								//Resta de matrices A y B
      	for (int j = 0; j < n; j++){
        cout <<"	"<<C[i][j]<<"	";
      	}
    cout << "\n";
	}    		
   	cout<<"	"<<"\nHECHO!"<<endl;
   	goto again;
	}else{
	cout<<"\nERROR! A y B deben ser del mismo tamano"<<endl;
	goto again;
	}	
}else if(op1==3){
	if(n == j){
	float M[m][k];
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < k ; j++){
			M[i][j]=0;
			for(int p=0 ; p < n ; p++){
				M[i][j]=M[i][j]+A[i][p]*B[p][j];
			}
		}
	}
	for (int i = 0; i < m; i++) {								//Multiplicacion de matrices A y B
      	for (int j = 0; j < k; j++){
        cout <<"	"<<M[i][j]<<"	";
      	}
    cout << "\n";
	}    		
   	cout<<"	"<<"\nHECHO!"<<endl;
   	goto again;
   	}else{
   	cout<<"Las columnas de A tienen que ser igual a las filas de B"<<endl;	
   	goto again;
	}
}else if(op1==4){
	int op2;
	cout<<"\nQUE DESEA CALCULAR??: "<<endl;
	cout<<"-Determinante -> 1"<<endl;
	cout<<"-Matriz inversa -> 2"<<endl;
	cout<<"-Matriz transpuesta -> 3"<<endl;
	cout<<"-Escalar -> 4"<<endl;										//Otra operacion entre A y B
	cout<<"-Matriz triangular -> 5"<<endl;
	cin>>op2;
	if(op2==1){	//Determinante de A y B
		if(m==n && j==k){
		cout<<"\nEl determinante de A es: " << determinante(A, m) << endl;
		cout<<"\nEl determinante de B es: " << determinante(B, j) << endl;	
		}else if (m==n && j!=k){
		cout<<"\nEl determinante de A es: " << determinante(A, m) << endl;
		cout<<"\nLa matriz B tiene que ser cuadrada"<<endl;					
		}else if(m!=n && j==k){
		cout<<"\nLa matriz A tiene que ser cuadrada"<<endl;
		cout<<"\nEl determinante de B es: " << determinante(B, j) << endl;	
		}else{
		cout<<"\nLas matrices tienen que ser cuadradas"<<endl;
		}
		goto again;
	}else if(op2==2){	//matriz inversa de A y B
	float A2[MAX][MAX],B2[MAX][MAX];
	
	for(int i=0;i<m;i++){
		for(int l=0;l<n;l++){			//Llenamos la matriz A2
		A2[i][l]=A[i][l];
		}
	}

	for(int i=0;i<j;i++){
		for(int l=0;l<k;l++){				//Llenamos la matriz B2
		B2[i][l]=B[i][l];
		}
	}
	if(m==n && determinante(A,m) != 0){//Inversa de A
		float I[m][m];
		for (int i = 0; i < m; i++) {
      		for (int l = 0; l < m; l++){							
        	I[i][l]=0;
			if(i==l){
        	I[i][l]=1;
			}  
			}
		}	
      	
		for(int i=0; i<m; i++){
			float pivote1=A2[i][i];
			for(int w=0; w<m; w++){
				A2[i][w]=A2[i][w]/pivote1;
				I[i][w]=I[i][w]/pivote1;
			}
			for(int y=0; y<m; y++){	
			float aux1=A2[y][i];
				if(y != i){
					for(int x=0; x < m; x++){
					A2[y][x]=A2[y][x]-aux1*A2[i][x];
					I[y][x]=I[y][x]-aux1*I[i][x];
					}
				}
			}
		}
		cout<<"Inversa de A:"<<endl;
		for (int i = 0; i < m; i++) {
      		for (int j = 0; j < m; j++){							
        	cout <<"	"<<I[i][j]<<"	";
      		}
    	cout << "\n";
		}   
		}else{
			cout<<"A NO tiene inversa"<<endl;
		}
		cout<<"\n";
		
	if(j==k && determinante(B,j) != 0){//Inversa de B
	float I2[j][j];
		for (int i = 0; i < j; i++) {
      		for (int l = 0; l < j; l++){							
        	I2[i][l]=0;
        	if(i==l){
        	I2[i][l]=1;
			}
      		}
		}   
		for(int i=0; i<j; i++){
			float pivote2=B2[i][i];
			for(int r=0; r<j; r++){
				B2[i][r]=B2[i][r]/pivote2;
				I2[i][r]=I2[i][r]/pivote2;
			}
			for(int y=0; y<j; y++){
				if(y != i){
					float aux2=B2[y][i];
					for(int x=0;x < j; x++){
					B2[y][x]=B2[y][x]-aux2*B2[i][x];
					I2[y][x]=I2[y][x]-aux2*I2[i][x];
					}
				}
			}
		}
		cout<<"Inversa de B:"<<endl;
		for (int i = 0; i < j; i++) {
      		for (int a = 0; a < j; a++){							//
        	cout <<"	"<<I2[i][a]<<"	";
      		}
    	cout << "\n";
		}    
		}else{
			cout<<"B no tiene inversa"<<endl;
		}
		
	goto again;
	}else if(op2==3){	//matriz transpuesta de A y B
		float At[MAX][MAX],Bt[MAX][MAX];
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){			//Llenamos la matriz At
			At[j][i]=A[i][j];
			}
		}

		for(int i=0;i<j;i++){
			for(int j=0;j<k;j++){			//Llenamos la matriz Bt
			Bt[j][i]=B[i][j];
			}	
		}
		cout<<"Transpuesta de A:"<<endl;		
		for (int i = 0; i < n; i++) {
      		for (int j = 0; j < m; j++){							//mostrando transpuesta de A 
        	cout <<"	"<<At[i][j]<<"	";
      		}
    	cout << "\n";
		}
		cout<<"Transpuesta de B:"<<endl;
		cout<<"\n";
		for (int i = 0; i < k; i++) {
      		for (int w = 0; w < j; w++){							//mostrando transpuesta de B
        	cout <<"	"<<Bt[i][w]<<"	";
      		}
    	cout << "\n";
		}
		goto again;
	}else if(op2==4){
		float e;
		cout<<"ingrese el escalar: "<<endl;
		cin>>e;
		cout<<"\n";
		cout<<"escalar*A:"<<endl;
		for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
            cout << e*A[i][j] << "	";
        }
        cout << "\n";
    	}
    	cout<<"\n";
    	cout<<"escalar*B:"<<endl;
		for (int i = 0; i < j; i++){
            for (int l = 0; l < k; l++){
            cout << e*B[i][l] << "	";
        }
        cout << "\n";
    	}
    cout << endl;
	goto again;
	}else if(op2==5){	//Matriz triangular
	float A3[MAX][MAX],B3[MAX][MAX];
	
	for(int i=0;i<m;i++){
		for(int l=0;l<n;l++){			//Llenamos la matriz A3
		A3[i][l]=A[i][l];
		}
	}

	for(int i=0;i<j;i++){
		for(int l=0;l<k;l++){				//Llenamos la matriz B3
		B3[i][l]=B[i][l];
		}
	}
	
	float LA[m][m];
	for (int i = 0; i < m; i++) {
   		for (int l = 0; l < m; l++){		//Creando matriz L de A					
      	if(i==l){
       	LA[i][l]=1.0;
		}else if(i<l){
		LA[i][l]=0.0;	
		}
   		}
	}  
	
	if(m<=n){
	for(int i=0; i<m; i++){//Matriz triangular de A
	float piv0=A3[i][i];
		for(int y=i+1; y<m; y++){	
		float a0=A3[y][i];
		float au0=a0/piv0;
		LA[y][i]=au0;
			for(int x=0; x < n; x++){
			A3[y][x]=A3[y][x]-au0*A3[i][x];
			
			}
			
		}
	}
	}else if (n<m){
	for(int i=0; i<n; i++){//Matriz triangular de A
	float piv0=A3[i][i];
		for(int y=i+1; y<m; y++){	
		float a0=A3[y][i];
		float au0=a0/piv0;
		LA[y][i]=au0;
			for(int x=0; x < n; x++){
			A3[y][x]=A3[y][x]-au0*A3[i][x];
			}
		}
	}
	}
	
	float LB[j][j];
	for (int i = 0; i < j; i++) {
   		for (int l = 0; l < j; l++){		//Creando matriz L de B							
      	if(i==l){
       	LB[i][l]=1.0;
		}else if(i<l){
		LB[i][l]=0.0;	
		}
   		}
	}  	
		
	if(j<=k){
	for(int i=0; i<j; i++){//Matriz triangular de B
	float piv1=B3[i][i];
		for(int y=i+1; y<j; y++){	
		float a1=B3[y][i];
		float au1=a1/piv1;
		LB[y][i]=au1;
			for(int x=0; x < k; x++){
			B3[y][x]=B3[y][x]-au1*B3[i][x];
			}
		}
	}	
	}else if (k<j){
	for(int i=0; i<k; i++){//Matriz triangular de B
	float piv1=B3[i][i];
		for(int y=i+1; y<j; y++){	
		float a1=B3[y][i];
		float au1=a1/piv1;
		LB[y][i]=au1;
			for(int x=0; x < k; x++){
			B3[y][x]=B3[y][x]-au1*B3[i][x];
			}
		}
	}
		
	}
cout<<"Triangular de A:"<<endl;
	for (int i = 0; i < m; i++) {
      		for (int a = 0; a < n; a++){							//Mostrar triangular A
        	cout <<"	"<<A3[i][a]<<"	";
      		}
    	cout << "\n";
	}
	cout<<"\n\n";
cout<<"Triangular de B:"<<endl;	
	for (int i = 0; i < j; i++) {
      		for (int a = 0; a < k; a++){							//Mostrar triangular B
        	cout <<"	"<<B3[i][a]<<"	";
      		}
    	cout << "\n";
	}    
	int op3;
	cout<<"Que mas quiere calcular?: "<<endl;
	cout<<"Factorizacion LU -> 2"<<endl;
	cin>>op3;
	cout<<"Matriz L de A:"<<endl;	
	for (int i = 0; i < m; i++) {
      	for (int a = 0; a < m; a++){							
       	cout<<"	"<<LA[i][a]<<"	";
      	}
    cout << "\n";
	} 
	cout<<"Matriz U de A:"<<endl;
	for (int i = 0; i < m; i++) {
      		for (int a = 0; a < n; a++){							//Mostrar L de A
        	cout <<"	"<<A3[i][a]<<"	";
      		}
    	cout << "\n";
	}
	cout<<"\n"; 
	cout<<"Matriz L de B:"<<endl;	
	for (int i = 0; i < j; i++) {
      	for (int a = 0; a < j; a++){
       	cout<<"	"<<LB[i][a]<<"	";
      	}
    cout << "\n";
	} 
	cout<<"Matriz U de B:"<<endl;
	for (int i = 0; i < j; i++) {
      		for (int a = 0; a < k; a++){							//Mostrar U de B
        	cout <<"	"<<B3[i][a]<<"	";
      		}
    	cout << "\n";
	}  
	cout<<"\n";
	goto again;
	}else{
		cout<<"Numero No Valido!"<<endl;
		goto again;
	}
}else if(op1==5){
	cout<<"FIN"<<endl;
}
else{
	cout<<"Numero No Valido!"<<endl;
	goto again;
}
return 0;
}

float determinante(float X[][MAX], int orden)
{
   float det = 0.0;
   
   if (orden == 1) {
      det = X[0][0];
   } else {
      for (int j = 0; j < orden; j++) {
         det = det + X[0][j] * cof(X, orden, 0, j);
      }
   }
   
   return det;
}


float cof(float X[][MAX], int orden, int fila, int columna)
{
   float subm[MAX][MAX];
   int n = orden - 1;
   
   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            subm[x][y] = X[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, fila + columna) * determinante(subm, n);
}

