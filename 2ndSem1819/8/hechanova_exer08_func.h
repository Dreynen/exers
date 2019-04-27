/*
This is where you will implement your allocateArray(), deallocate() and manipulating functions
*/

// allocates an unsigned char 2D array
unsigned char ** allocateArray(int height, int width){
	unsigned char ** array = malloc(sizeof(unsigned char *) * height);
	for(int i = 0; i < height; i++){
		array[i] = calloc(width, sizeof(unsigned char));
	}

	return array;
}

// deallocates memory from an unsigned char double pointer
void deallocate(unsigned char ** array, int height){
	for(int i = 0; i < height; i++){
		free(array[i]);
	}
	free(array);
}

// gets the negative laplacian of an image
unsigned char ** getNegativeLaplacian(unsigned char ** img, int height, int width){
	unsigned char ** filter = allocateArray(height, width);

	for(int i = 1; i < height - 1; i++){
		for(int j = 1; j < width - 1; j++){
			int value = (img[i - 1][j] * -2 + img[i][j - 1] * -2 + img[i][j] * 8 + img[i][j + 1] * -2 + img[i + 1][j] * -2)/9;
			if(value > 255) value = 255;
			else if(value < 0) value = 0;
			filter[i][j] = value;
		}
	}

	return filter;
}

// adds the original image to the negative laplacian
void addLaplacian(unsigned char ** img, unsigned char ** filter, int height, int width){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			int value = img[i][j] + filter[i][j];
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			filter[i][j] = value;
		}
	}
}


/* This function converts rgb image to a grayscale image*/
unsigned char ** convertToGrayScale(unsigned char **red,unsigned char **blue,unsigned char **green,int h, int w){
	int i,j;
	unsigned char ** img = allocateArray(h,w); //allocates another 2d array for the new image
	//traversing the whole image
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			img[i][j] = (red[i][j] + blue[i][j] + green[i][j])/3; //gets the average among 3 channels
		}
	}
	return img;
}