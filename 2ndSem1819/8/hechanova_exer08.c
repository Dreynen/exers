// change the name of this file to your exercise

#include<stdio.h>
#include "readppm.h"

int main(){
	int w, h;

	//read the red,blue,green channels of the PPM image
	//read_PPM functions always read the file named sample.ppm inside the imgs folder
	unsigned char **red = readRedPPM(&w,&h);
	unsigned char **green = readGreenPPM(&w,&h);
	unsigned char **blue = readBluePPM(&w,&h);
	//after this line, you already have the value of width and height of the image stored in w and h respectively


	//insert manipulations here
	unsigned char **img = convertToGrayScale(red, blue, green, h, w);
	unsigned char **filter = getNegativeLaplacian(img, h, w);
	//addLaplacian(img, filter, h, w);


	//save the PPM image to see result

	//if you want to check if your allocate and deallocate function works, uncomment the savePPM()
	//this will result to result.ppm displaying the image itself

	savePPM(filter,filter,filter,h,w);


	//free your arrays
	deallocate(red, h);
	deallocate(green, h);
	deallocate(blue, h);
	deallocate(img, h);
	deallocate(filter, h);
	return 0;
}
