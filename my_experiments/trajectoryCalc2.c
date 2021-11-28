#include <stdio.h>
#include <math.h>

int main(){

	long long t=0;
	long long x = 0;  //in mm
	long long y = 0;  //in mm
	double w = 500000;  //in mm/sec
	double z = 500000;  //in mm/sec
	double g = 9800;  //in mm/sec2
	long long tl = 1000*50; //in ms
	double vangle = 0;
	double ag;
	
	for(t=0; t<tl; t++){
	
		vangle = 57.3*atan(z/w);
		w = w - (1-(0.000000466*y/(0.000000466*y+1)))*w/7000; //7000 for 50bmg
		x = x + w/1000;
		z = z - g/1000 - (1-(0.000000466*y/(0.000000466*y+1)))*z/7000 ; //7000 for 50bmg
		y = y + z/1000;
		if (t % 250 == 0){

			printf( "t = %lld ms, x = %lld m, y = %lld m, vx = %f m/s, vy = %f m/s, 	vangle = %f degrees \n", t , x/1000 , y/1000 , w/1000 , z/1000 , vangle );
			
		}

	}

}
