#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
main()
{ int b,i,j,x,y,num,flag,mome;
  int a[15][15],des_x[5],des_y[5];
  FILE *fp;
  printf("Welcome to the pushing-box game!\n");
  printf("Please choose a map(1~3):\n");
  scanf("%d",&b);
  num=0;
  if((fp=fopen("map.in","r"))==NULL)
  {  printf("Not find the map!");
     exit(0);
  }
  printf("Map in ");
  for(i=0;i<15;i++)
	  for(j=0;j<15;j++)
		 { fscanf(fp,"%d",&a[i][j]);
           if(a[i][j]==1)x=i,y=j,a[i][j]=0;
		   if(a[i][j]==4){des_x[num]=i;des_y[num]=j;num++;a[i][j]=0;
		   }
		   printf("%d %d\n",i,j);
         }
  printf("OK!\n");
  getchar();
  fclose(fp);
  b=0;
  flag=1;
  printf("Press w,a,s,d to control the boy\n");
  while(flag)
  { b=_getch();
    if(b=='a')
	{ if ((y>0)&&(a[x][y-1]==0))y--;
	  else if ((y>1)&&(a[x][y-1]==2)&&(a[x][y-2]==0)) 
	  { a[x][y-2]=2;a[x][y-1]=0;y--;}
	}
	if(b=='d')
	{ if ((y<14)&&(a[x][y+1]==0))y++;
	  else if ((y<13)&&(a[x][y+1]==2)&&(a[x][y+2]==0))
	  { a[x][y+2]=2;a[x][y+1]=0;y++;}
	}
	if(b=='w')
	{ if ((x>0)&&(a[x-1][y]==0))x--;
	  else if ((x>1)&&(a[x-1][y]==2)&&(a[x-2][y]==0))
	   { a[x-2][y]=2;a[x-1][y]=0;x--;};
	}
	if(b=='s')
	{ if ((x<14)&&(a[x+1][y]==0)) x++;
	  else if ((x<13)&&(a[x+1][y]==2)&&(a[x+2][y]==0))
	  { a[x+2][y]=2;a[x+1][y]=0;x++;}
	}

	flag=0;
	for(i=0;i<num;i++) 
		{ if(a[des_x[i]][des_y[i]]!=2)flag=1,a[des_x[i]][des_y[i]]=4;
		  else a[des_x[i]][des_y[i]]=5;
	}
	mome=a[x][y];
	a[x][y]=1;

    for(i=0;i<15;i++)
	{ for(j=0;j<15;j++)
		  switch(a[i][j])
	        {case 0:printf(" ");break;
			 case 1:printf("%c",1);break;
			 case 2:printf("%c",4);break;
			 case 3:printf("%c",35);break;
			 case 4:printf("%c",15);break;
			 case 5:printf("%c",5);break;
	        }
	  printf("\n");
	}

	a[x][y]=mome;
	for(i=0;i<num;i++)
		{ if(a[des_x[i]][des_y[i]]==4) a[des_x[i]][des_y[i]]=0;
		  else a[des_x[i]][des_y[i]]=2;
	    }
  }
  for(i=0;i<10;i++) printf("\n");
  printf("You win!\n");
  printf("Press Y to quit\n");
  while ((b=_getch())!='y');
}