#include <iostream>
#include<cmath>
#include <windows.h>
#define MAX 100
using namespace std;

float determinante(float X[][MAX], int orden);
float cof(float X[][MAX], int orden, int fila, int columna);


int main(){
int op1;
cout<<"				CALCULADORA MATRICIAL(LETN-307)"<<endl;
cout<<"Integrantes:"<<endl;
cout<<"-Augusto Bautista Colque"<<endl;
cout<<"-Marcelo William Daza Chambi\n"<<endl;
again:
cout<<"\nQue operacion desea realizar (1->suma; 2->resta; 3->multiplicacion; 4->division; 5-->otro; 6-->salir): ";
cin>>op1;
cout<<"\n";

if(op1==1){
	int m,n,j,k;
	float A[MAX][MAX],B[MAX][MAX];
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;
	cout<<"Introduzca el numero de filas de B: ";
	cin>>j;
	cout<<"Introduzca el numero de columnas de B: ";
	cin>>k;
cout<<"A:"<<endl;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": ";
		cin>>A[i][j];
	}
	cout<<"\n";
}
cout<<"B:"<<endl;
for(int i=0;i<j;i++){
	for(int l=0;l<k;l++){
		cout<<"B"<<i<<","<<l<<": ";
		cin>>B[i][l];
	}
	cout<<"\n";
}	

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
	int m,n,j,k;
	float A[MAX][MAX],B[MAX][MAX];
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;
	cout<<"Introduzca el numero de filas de B: ";
	cin>>j;
	cout<<"Introduzca el numero de columnas de B: ";
	cin>>k;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": "<<endl;
		cin>>A[i][j];
	}
cout<<"\n";
}

for(int i=0;i<j;i++){
	for(int l=0;l<k;l++){
		cout<<"B"<<i<<","<<l<<": "<<endl;
		cin>>B[i][l];
	}
	cout<<"\n";
}	
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
	int m,n,j,k;
	float A[MAX][MAX],B[MAX][MAX];
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;
	cout<<"Introduzca el numero de filas de B: ";
	cin>>j;
	cout<<"Introduzca el numero de columnas de B: ";
	cin>>k;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": ";
		cin>>A[i][j];
	}
	cout<<"\n";
}

for(int i=0;i<j;i++){
	for(int l=0;l<k;l++){
		cout<<"B"<<i<<","<<l<<": ";
		cin>>B[i][l];
	}
	cout<<"\n";
}	
	
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
	int m,n,j,k;
	float A[MAX][MAX],B[MAX][MAX];
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;
	cout<<"Introduzca el numero de filas de B: ";
	cin>>j;
	cout<<"Introduzca el numero de columnas de B: ";
	cin>>k;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": ";
		cin>>A[i][j];
	}
	cout<<"\n";
}

for(int i=0;i<j;i++){
	for(int l=0;l<k;l++){
		cout<<"B"<<i<<","<<l<<": ";
		cin>>B[i][l];
	}
	cout<<"\n";
}

float B2[MAX][MAX];
	for(int i=0;i<j;i++){
		for(int l=0;l<k;l++){			//Llenamos la matriz B2
		B2[i][l]=B[i][l];
		}
	}

	if(j==k && determinante(B,j) != 0){//Inversa de B
		float IB[j][j];
		for (int i = 0; i < j; i++) {
      		for (int l = 0; l < j; l++){							
        	IB[i][l]=0;
			if(i==l){
        	IB[i][l]=1;
			}  
			}
		}	
      	
	for(int i=0; i<j; i++){
		float pivote2=B2[i][i];
		for(int w=0; w<j; w++){
			B2[i][w]=B2[i][w]/pivote2;
			IB[i][w]=IB[i][w]/pivote2;
		}
		for(int y=0; y<j; y++){	
		float aux2=B2[y][i];
			if(y != i){
			for(int x=0; x < j; x++){
			B2[y][x]=B2[y][x]-aux2*B2[i][x];
			IB[y][x]=IB[y][x]-aux2*IB[i][x];
			}
			}
		}
	}
	
if(n == j){
	float D[m][k];
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < k ; j++){
			D[i][j]=0;
			for(int p=0 ; p < n ; p++){
				D[i][j]=D[i][j]+A[i][p]*IB[p][j];
			}
		}
	}
	for (int i = 0; i < m; i++) {								//Multiplicacion de matrices A y B
      	for (int j = 0; j < k; j++){
        cout <<"	"<<D[i][j]<<"	";
      	}
    cout << "\n";
	}    		
   	cout<<"	"<<"\nHECHO!"<<endl;
   	goto again;
   	}else{
   	cout<<"Las columnas de A tienen que ser igual a las filas de B"<<endl;	
   	goto again;
	}
	}else{
		cout<<"B tiene que ser cuadrada"<<endl;
		goto again;
	}	
	
	
	
}else if(op1==5){
	int op2;
	cout<<"\nQUE DESEA CALCULAR??: "<<endl;
	cout<<"-Determinante -> 1"<<endl;
	cout<<"-Matriz inversa -> 2"<<endl;
	cout<<"-Matriz transpuesta -> 3"<<endl;
	cout<<"-Valores propios-> 4"<<endl;
	cout<<"-Escalar -> 5"<<endl;										//Otra operacion entre A y B
	cout<<"-Matriz triangular -> 6"<<endl;
	cin>>op2;
if(op2==1){	//Determinante de A y B
	int m,n;	
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;	
	float A[MAX][MAX];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": "<<endl;
		cin>>A[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
	
	if(m==n){
		cout<<"\nEl determinante de A es: " << determinante(A, m) << endl;	
	}else{
		cout<<"\nLa matriz tiene que ser cuadrada"<<endl;
	}
		goto again;
}else if(op2==2){//matriz inversa de A
	int m,n;	
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;	
	float A[MAX][MAX];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": "<<endl;
		cin>>A[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
	float A2[MAX][MAX];
	for(int i=0;i<m;i++){
		for(int l=0;l<n;l++){			//Llenamos la matriz A2
		A2[i][l]=A[i][l];
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
	goto again;

}else if(op2==3){	//matriz transpuesta de A y B
	int m,n;	
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;	
	float A[MAX][MAX];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": "<<endl;
		cin>>A[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
	float At[MAX][MAX];
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){			//Llenamos la matriz At
			At[j][i]=A[i][j];
			}
		}

		cout<<"Transpuesta de A:"<<endl;		
		for (int i = 0; i < n; i++) {
      		for (int j = 0; j < m; j++){							//mostrando transpuesta de A 
        	cout <<"	"<<At[i][j]<<"	";
      		}
    	cout << "\n";
		}
goto again;
}else if(op2==4){
	int m,n;	
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;	
	float A[MAX][MAX];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": "<<endl;
		cin>>A[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
float s=0;
float mean;	
for(int i=0;i<m;i++){
	s=s+A[i][i];
}
mean=s/m;
cout<<"Valores propios:"<<endl;
	float Va[MAX];
	if((pow(mean,2)-determinante(A,m))>=0){
		Va[0]=mean+sqrt(pow(mean,2)-determinante(A,m));
		Va[1]=mean-sqrt(pow(mean,2)-determinante(A,m));
		cout<<"Valor1: "<<Va[0]<<endl;
		cout<<"Valor2: "<<Va[1]<<endl;
		
		int op4;
		cout<<"\nQue mas quiere calcular?: "<<endl;
		cout<<"Diagonal -> 2"<<endl;
		cin>>op4;	
		float Diag[m][m];
		for (int i = 0; i < m; i++) {
      		for (int l = 0; l < m; l++){							
        	Diag[i][l]=0;
			if(i==l){
        	Diag[i][l]=Va[i];
			}  
			}
		}
		for (int i = 0; i < m; i++) {
  	   		for (int a = 0; a < m; a++){							//Mostrar triangular A
        	cout <<"	"<<Diag[i][a]<<"	";
      		}
    	cout << "\n";
		}
		goto again;
	}else{
		cout<<"Valor1: "<<mean<<"+ ( "<<sqrt(-pow(mean,2)+determinante(A,m))<<" )"<<endl;
		cout<<"Valor1: "<<mean<<"- ( "<<sqrt(-pow(mean,2)+determinante(A,m))<<" )"<<endl;
		cout<<"\nLa matriz diagonal sera con estos valores en su diagonal"<<endl;
		goto again;
	}

}else if(op2==5){//escalar
	int m,n;	
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;	
	float A[MAX][MAX];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": "<<endl;
		cin>>A[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";

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
goto again;
}else if(op2==6){	//Matriz triangular
	int m,n;	
	cout<<"Introduzca el numero de filas de A: ";
	cin>>m;
	cout<<"Introduzca el numero de columnas de A: ";		//Pedimos al usuario el orden de A y B
	cin>>n;	
	float A[MAX][MAX];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){			//Llenamos la matriz A
		cout<<"A"<<i<<","<<j<<": "<<endl;
		cin>>A[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";

float A3[MAX][MAX];
	
for(int i=0;i<m;i++){
	for(int l=0;l<n;l++){			//Llenamos la matriz A3
	A3[i][l]=A[i][l];
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
cout<<"Triangular de A:"<<endl;
	for (int i = 0; i < m; i++) {
      		for (int a = 0; a < n; a++){							//Mostrar triangular A
        	cout <<"	"<<A3[i][a]<<"	";
      		}
    	cout << "\n";
	}
	cout<<"\n\n";
int op3;
	cout<<"Que mas quiere calcular?: "<<endl;
	cout<<"Factorizacion LU -> 2"<<endl;
	cin>>op3;
if(op3==2){
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
goto again;
}else{
	cout<<"Numero No Valido!"<<endl;
	goto again;
}
}else{
cout<<"Numero No Valido!"<<endl;
	goto again;	
}
}else if(op1==6){
	cout<<"FIN"<<endl;
}
else{
	cout<<"Numero No Valido!"<<endl;
	goto again;
}
return 0;
}

float determinante(float X[][MAX], int orden){
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

