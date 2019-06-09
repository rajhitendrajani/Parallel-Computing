#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <stdio.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif


int a,b,n,intensity,fid,i;
float x=0,k=0,p=0,q=0,r=0;
double cpu_time_used;  
int main (int argc, char* argv[]) {
auto start = std::chrono::high_resolution_clock::now();
  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  		}
		sscanf(argv[3], "%d",&b);
		sscanf(argv[2], "%d",&a);
		sscanf(argv[4], "%d",&n);
		sscanf(argv[5], "%d",&intensity);
		sscanf(argv[1], "%d",&fid);
		
		for(i=0;i<n;i++){	
			
				p=(i+0.5);
				q=a+p;
				r=b-a;
				r=r/n;
				x=r*q;			
				switch(fid){
					case 1:
						k=k+f1( x, intensity);
					break;
					case 2:
						k=k+f2( x, intensity);
					break;
					case 3:
						k=k+f3( x, intensity);
					break;
					case 4:
						k=k+f4( x, intensity);
					break;
					default: printf("Wrong fid");
					}
				}
		k=k*r;
		printf("%f\n",k);
auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
		std::cerr<<elapsed.count()<<std::endl;
  return 0;
}
