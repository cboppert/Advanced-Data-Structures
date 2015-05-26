#include <stdio.h>
#include <stdlib.h>

int main()
{  int points[90003][2];
   int triangles[180002][3];
   int i,j, k;
   k=0;
   for(i=0; i<300; i++)
   {  for(j=0; j<300; j++)
      {  points[k][0] = 15*i;  points[k][1] = 15*j;
         k +=1;
      }
   }
   points[k][0] = -4500;  points[k++][1] = -15;
   points[k][0] =  9000;  points[k++][1] = -15;
   points[k][0] =  2250;  points[k++][1] = 9000;
   printf("Prepared %d points\n", k);
   k=0;
   triangles[k][0]=90000;  
   triangles[k][1]=90001;  
   triangles[k++][2]=90002;
   for(i=0; i<299; i++)
   {   triangles[k][0]=i;  
       triangles[k][1]=i+1;  
       triangles[k++][2]=90000;
   }
   triangles[k][0]=299;  
   triangles[k][1]=90000;  
   triangles[k++][2]=90002;
   for(i=0; i<299; i++)
   {   triangles[k][0]=299 + 300*i;  
       triangles[k][1]=299 + 300*(i+1);  
       triangles[k++][2]=90002;
   }
   triangles[k][0]=90002;  
   triangles[k][1]=89999;  
   triangles[k++][2]=90001;
   for(i=0; i<299; i++)
   {   triangles[k][0]=299*300 +i;  
       triangles[k][1]=299*300 +i+1;  
       triangles[k++][2]=90001;
   }
   triangles[k][0]=90000;  
   triangles[k][1]=89700;  
   triangles[k++][2]=90001;
   for(i=0; i<299; i++)
   {   triangles[k][0]=300*i;  
       triangles[k][1]=300*(i+1);  
       triangles[k++][2]=90000;
   }
   for(i=0; i<299; i++)
   {  for(j=0; j<299; j++)
      {  triangles[k][0]=300*i + j;  
         triangles[k][1]=300*(i+1) + j;  
         triangles[k++][2]=300*i+j+1;
         triangles[k][0]=300*(i+1) + j+1;  
         triangles[k][1]=300*(i+1) + j;  
         triangles[k++][2]=300*i+j+1;
      }
   }
   printf("Prepared %d triangles\n", k);   
   { ploc_t *pl;
     pl = create_ploc( points, triangles, 90003, 180002); 
     for(i=0; i<10000; i++)
     {  int a,b,c,x,y, t; 
        j = (rand()%180001)+1;
        a = triangles[j][0]; b=triangles[j][1]; c=triangles[j][2];       
        x = (points[a][0]+points[b][0]+points[c][0])/3;
        y = (points[a][1]+points[b][1]+points[c][1])/3;
        t = query_ploc(pl, x,y);
        if ( t!= j )
	{  printf("Error on triangle %d, misidentified as triangle %d\n",j,t);
	   printf("Point (%d,%d) should be in triangle (%d,%d), (%d,%d), (%d,%d)\n",
                x,y, points[a][0],points[a][1],points[b][0], points[b][1],
                points[c][0], points[c][1]);
           printf("Instead claimed in triangle (%d,%d), (%d,%d), (%d,%d)\n",
	       points[triangles[t][0]][0], points[triangles[t][0]][1],
               points[triangles[t][1]][0], points[triangles[t][1]][1],
		  points[triangles[t][2]][0], points[triangles[t][2]][1] );
	  exit(0);
        }
     }
   }
   printf("Passed test\n");
} 
