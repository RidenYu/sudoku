#include<iostream.h>
#include<iomanip.h>
#define M 9
#define N 9

int count=0;//记录一共有多少个空
int kong[81]={0};//记录每一个空格对应的K值
int tt=0;

struct Point
{
	int id;
	int num;
	int hang;
	int lie;
	int flag;
	};
Point data[81];

void main()
{
	int sudoku[M][N];
	cout<<"Please input the origin datas:"<<endl;
	for(int a=0;a<M;a++)
		for(int b=0;b<N;b++)
		{cin>>sudoku[a][b];}
		cout<<endl;
		cout<<endl;
		cout<<"   The origin datas:  "<<endl;
	
    for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			if(j==0)
			{
				cout<<"| "<<sudoku[i][j]<<"  ";
			}
			else if((j==2)||(j==5))
			{
				cout<<sudoku[i][j]<<" | ";
			}
			else if((i==2)&&(j==8))
			{
				cout<<sudoku[i][j]<<" |"<<endl;
			  cout<<"*******************************"<<endl;
			}
			else if((i==5)&&(j==8))
			{
				cout<<sudoku[i][j]<<" |"<<endl;
			  cout<<"*******************************"<<endl;
			}

			else if(j==8)
			{
				cout<<sudoku[i][j]<<" |"<<endl;
			}
			else
			{
				cout<<sudoku[i][j]<<"  ";
			}
		}

	int pp=0;
	for(int c=0;c<M;c++)
		for(int d=0;d<N;d++)
		{
			data[pp].num=sudoku[c][d];
			data[pp].hang=c;
			data[pp].lie=d;
			pp++;
		}

	data[0].id=data[1].id=data[2].id=data[9].id=data[10].id=data[11].id=data[18].id=data[19].id=data[20].id=0;
	data[3].id=data[4].id=data[5].id=data[12].id=data[13].id=data[14].id=data[21].id=data[22].id=data[23].id=1;
	data[6].id=data[7].id=data[8].id=data[15].id=data[16].id=data[17].id=data[24].id=data[25].id=data[26].id=2;


	data[27].id=data[28].id=data[29].id=data[36].id=data[37].id=data[38].id=data[45].id=data[46].id=data[47].id=3;
	data[30].id=data[31].id=data[32].id=data[39].id=data[40].id=data[41].id=data[48].id=data[49].id=data[50].id=4;
	data[33].id=data[34].id=data[35].id=data[42].id=data[43].id=data[44].id=data[51].id=data[52].id=data[53].id=5;


	data[54].id=data[55].id=data[56].id=data[63].id=data[64].id=data[65].id=data[72].id=data[73].id=data[74].id=6;
	data[57].id=data[58].id=data[59].id=data[66].id=data[67].id=data[68].id=data[75].id=data[76].id=data[77].id=7;
	data[60].id=data[61].id=data[62].id=data[69].id=data[70].id=data[71].id=data[78].id=data[79].id=data[80].id=8;

	for(int e=0;e<81;e++)
	{
		if(data[e].num) {data[e].flag=1;}
		else {data[e].flag=0;count++;}
	}
	
    for(int f=0;f<81;f++)//数组kong[]记录空数位置
	{
		if(data[f].flag==0)
		{
			kong[tt]=f;
			tt++;
		}
	}

	//回溯法解数独
	int z=-1;
	for(int x=0;x<81;x++)
	{
		if(data[x].flag==0)
		{
			z++;
			data[x].num++;
			for(int y=0;y<81;y++)
			{
			
				if(x!=y)
				{
					if((data[x].lie==data[y].lie)||(data[x].hang==data[y].hang)||(data[x].id==data[y].id))
					{
						if(data[x].num==data[y].num){data[x].num++;y=-1;}
						if(data[x].num>9)
						{
							data[x].num=0;
				        	x=kong[z-1]-1;
				        	z=z-2;
				        	break;
						}
					}
				}
				
			}
			if(z<-1){cout<<"No ANswer"<<endl;break;}
		}
	}

if(x>=81)
{	int p=0;
	while(p<81)
	{
	   for(int m=0;m<M;m++)
	     	for(int n=0;n<N;n++)
			{
		    	sudoku[m][n]=data[p].num;
				p++;
			}
	}

cout<<endl;
cout<<endl;
cout<<endl;
cout<<"     The  Answer:        "<<endl;
cout<<"*******************************"<<endl;
	for(int r=0;r<M;r++)
		for(int s=0;s<N;s++)
		{
			if(s==0)
			{
				cout<<"| "<<sudoku[r][s]<<"  ";
			}
			else if((s==2)||(s==5))
			{
				cout<<sudoku[r][s]<<" | ";
			}
			else if((r==2)&&(s==8))
			{
				cout<<sudoku[r][s]<<" |"<<endl;
			  cout<<"*******************************"<<endl;
			}
			else if((r==5)&&(s==8))
			{
				cout<<sudoku[r][s]<<" |"<<endl;
			  cout<<"*******************************"<<endl;
			}

			else if(s==8)
			{
				cout<<sudoku[r][s]<<" |"<<endl;
			}
			else
			{
				cout<<sudoku[r][s]<<"  ";
			}
		}
}
}







			
