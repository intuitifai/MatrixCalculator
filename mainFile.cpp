#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iomanip>

using namespace std;
class main_menu
{
public:
    main_menu();
    void read();
    int  back();
};
main_menu::main_menu()
{
    system("clear");
    cout<<endl;
    cout<<"\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t\t\t\tOBJECT ORIENTED PROGRAMMING"<<endl;
    cout<<"\t\t\t\t\t\tMINI - PROJECT"<<endl;
    cout<<"\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\t!!!!!! WELCOME !!!!!!"<<endl;
}
void main_menu::read()
{
    cout<<endl<<endl;
   // cout<<"\t\t\t\t\t1.SOLVE N-EQUATION: "<<endl;
   // cout<<"\t\t\t\t\t2.SOLVE FACTORIAL: "<<endl;
    cout<<"\t\t\t\t\t1.MATRIX TRANSPOSE:"<<endl<<endl;
    cout<<"\t\t\t\t\t2.DETERMINANT OF A MATRIX: "<<endl<<endl;
    cout<<"\t\t\t\t\t3.INVERSE OF A MATRIX: "<<endl<<endl;
    cout<<"\t\t\t\t\t4.EIGENVALUES AND EIGENVECTORS"<<endl<<endl;
}
int  main_menu::back()
{
    int num,choice;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t******************************************"<<endl;
    cout<<"\t\t\t\t\t\tDO YOU WANT TO CONTINUE ?"<<endl;
    cout<<"\t\t\t\t\t\t1.YES! CONTINUE"<<endl;
    cout<<"\t\t\t\t\t\t2.NO! EXIT"<<endl;
    cout<<"\t\t\t\t\t******************************************"<<endl;
    cout<<"\t\t\t\t\t\t";
    cin>>num;
    if(num==1)
        {
            main_menu m;
            main_menu::read();
            cout<<"\t\t\t\t\tENTER YOUR CHOICE HERE: "<<endl;
            cout<<"\t\t\t\t\t";
            cin>>choice;
            return choice;
        }
    else
            return 0;
}
//eigenvalues and eigenvectors
class eigen: public main_menu
{
public:
    int value();
};

int eigen::value()
{
    float a[10][10],x[10],c[10],d=0,temp;
    int n,i,j;
    system("clear");
    cout<<endl<<endl<<"\t\t\t\t##################### EIGENVALUES AND EIGENVECTORS #####################"<<endl<<endl;
    cout<<"\tEnter the order of matrix ? ";
    cin>>n;
    cout<<"\n\tCoefficients of matrix ";
    for(i=0;i<n;i++)
    {
        cout<<endl<<"row  "<<i+1<<"  ";
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }

    cout<<"\tEnter your starting vector ? ";
    for(i=0;i<n;i++)
    cin>>x[i];

    do
    {
        for(i=0;i<n;i++)
        {
            c[i]=0;
            for(j=0;j<n;j++)
                c[i]+=a[i][j]*x[j];
        }
        for(i=0;i<n;i++)
            x[i]=c[i];

        temp=d;
        d=0;

        for(i=0;i<n;i++)
        {
            if(fabs(x[i])>fabs(d))
                d=x[i];
        }
        for(i=0;i<n;i++)
            x[i]/=d;

    }while(fabs(d-temp)>0.00001);

    cout<<"\tEigen value is : "<<d<<endl;

    cout<<"\tEigenvector is: ";
    for(i=0;i<n;i++)
        cout<<endl<<"\t"<<x[i];


    return 0;
}
//inverse of the matrix
class inverse:public main_menu
{
public:
float deter(float [][25], float);
void cofactor(float [][25], float);
void trans(float [][25], float [][25], float);
int trans(float,float,float);
int inv();
};

int inverse::inv()


{
    cout<<setprecision(3);
     int deter(float[][25],float);
  void cofactor(float[][25],float);
  float a[25][25], k, d;
  int i, j;
  printf("Enter the order of the Matrix : ");
  scanf("%f", &k);
  printf("Enter the elements of %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &a[i][j]);
        }
    }
  d = deter(a, k);
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   cofactor(a, k);
   //main_menu::back();
}

/*For calculating deter of the Matrix */
float deter(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * deter(b, k - 1));
          s = -1 * s;
          }
    }

    return (det);
}

void cofactor(float num[25][25], float f)
{
 int trans(float [][25], float [][25], float);
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * deter(b, f - 1);
    }
  }
  trans(num, fac, f);
}
/*Finding trans of matrix*/
int trans(float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25], inverse[25][25], d;

  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = deter(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");

   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
     }

}

//transpose class definition
class matrix_transpose:public main_menu
{

int a[5][5];
int row,col;
public:

    int transpose()
    {
        int a[10][10], trans[10][10], r, c, i, j;
    system("clear");
    cout<<"\tEnter number of rows : ";
    cin>>r;
    cout<<endl;
    cout<<"\tEnter number of columns : ";
    cin>>c;
    cout<<endl;
    try
    {
        if(r==0||c==0)
            throw c;
    }
    catch(...)
    {
        cout<<"\tROWS AND COLUMNS CANNOT BE EMPTY! "<<endl;
        return 0;
    }

    // Storing element of matrix entered by user in array a[][].
    cout << endl << "\tEnter elements of matrix: " << endl;
    for(i = 0; i < r; ++i)
    for(j = 0; j < c; ++j)
    {
        cout << "\tEnter elements a" << i + 1 << j + 1 << ": ";
        cin >> a[i][j];
    }

    // Displaying the matrix a[][]
    cout << endl << "\tEntered Matrix: " << endl;
    for(i = 0; i < r; ++i)
    {
            cout<<"\t";

        for(j = 0; j < c; ++j)
        {
            cout << " " << a[i][j];
            if(j == c - 1)
                cout << endl << endl;
        }
    }
    // Finding transpose of matrix a[][] and storing it in array trans[][].
    for(i = 0; i < r; ++i)
        {
            cout<<"\t";
            for(j = 0; j < c; ++j)
        {
            trans[j][i]=a[i][j];
        }
        }
    // Displaying the transpose,i.e, Displaying array trans[][].
    cout << endl << "\tTranspose of Matrix: " << endl;
    for(i = 0; i < c; ++i)
        {
            cout<<"\t";
            for(j = 0; j < r; ++j)
        {
            cout << " " << trans[i][j];
            if(j == r - 1)
                cout << endl << endl;
        }
        }

main_menu::back();
    }


};
//class  determinant defintion
class determinant:public main_menu
{
    int getMinimoCount = 0; //ignore these, just to keep track of the recursion.
    int calcDetCount = 0;
public:

    void printMatrix ( vector< vector<double> > M)
     {
  //just does what it means
  int size = M.size();
  for( int i = 0; i < size; i++ ) {
    cout << "\t";
    for( int j = 0; j < size; j++ ) {
      cout << M[i][j] << "\t"; }
    cout << endl << endl << endl; }
  cout << endl;
}
vector< vector<double> > getMinimo( vector< vector<double> > src, int I, int J, int ordSrc ) {
  // Compute and return the minimum of the element I J
  // If the element is not in the Ith row or Jth column it will get copied to the minimum matrix
  getMinimoCount++;

  vector< vector<double> > minimo( ordSrc-1, vector<double> (ordSrc-1,0));

  int rowCont = 0;
  for( int i=0; i < ordSrc; i++)
  {
    int colCont = 0;
    if ( i != I ) {

      for ( int j=0; j < ordSrc; j++)
      {
        if ( j != J ) {
          minimo[rowCont][colCont] = src[i][j];
          colCont++; }
      };

      rowCont++; }
  }
  return minimo;
}

double calcDet( vector< vector<double> > src, int ord) {
  // Here be recursion.
  calcDetCount++;

  if ( ord == 2 ) {

    double mainDiag = src[0][0] * src[1][1];
    double negDiag = src[1][0] * src[0][1];

    return mainDiag - negDiag; }
  else {
    double det = 0;

    for( int J = 0; J < ord; J++)
    {
      vector< vector<double> > min = getMinimo( src, 0, J, ord);

      if ( (J % 2) == 0 ) { det += src[0][J] * calcDet( min, ord-1); }
      else { det -= src[0][J] * calcDet( min, ord-1); }

    }

    return det;
  }
}
int calculate_determinant()
{
    int ord;
    system("clear");
  cout << "\t############## MATRIX DETERMINANT ##############" << endl << endl;
  cout << "\tMatrix order: "; cin >> ord; cout << endl;
  vector <vector<double> > mainMatrix( ord, vector<double> (ord, 0));

  cout << """ \tinsert values one row at time. Top to bottom:\n\n""";
  for ( int countY = 0; countY < ord; countY++) {
    for ( int countX = 0; countX < ord; countX++) {
      cin >> mainMatrix[countY][countX];};
  };

  system("clear");
  cout << "\t############## MATRIX DETERMINANT ##############" << endl << endl;
  cout << endl << endl << "\tThis is the input matrix:" << endl << endl << endl;
  printMatrix( mainMatrix );

  system("PAUSE");

  system("clear");
  cout << "\t############## MATRIX DETERMINANT ##############" << endl << endl;
  cout << "\tWorking...!" << endl;
  double det = calcDet( mainMatrix, ord );
  system("clear");

  cout << endl << endl << "\t############## MATRIX DET ##############" << endl << endl;
  cout << "\tDet =\t" << det << endl << endl;

   // main_menu::back();
  }
};
//main function definition
int main()
{
    main_menu first_page;
    int i=0,choice;
    int l;


        for(;;)
    {
        choice=first_page.back();
        switch(choice)
        {
        case 0:
            return 0;




        case 1:{matrix_transpose t;
            l=t.transpose();
            break;}
        case 2: {determinant d ;
                d.calculate_determinant();
                break;}
        case 3:
                {inverse i;
                i.inv();
                break;}
        case 4:
               {eigen e;
                e.value();
                break;}

        }

    }
        return 0;
}




