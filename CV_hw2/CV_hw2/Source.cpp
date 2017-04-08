#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include <math.h>
using namespace std;
using namespace cv;
uchar blue[512][512];
uchar green[512][512];
uchar red[512][512];
uchar temp[512][512];
uchar blueX[512][512];
uchar greenX[512][512];
uchar redX[512][512];
uchar blueY[512][512];
uchar greenY[512][512];
uchar redY[512][512];


void meanFilter(IplImage *srcImg){
	printf("123  \n");
	for (int i = 0; i<srcImg->height; i++){
		for (int j = 0; j<srcImg->widthStep; j = j + 3){
			blue[i][(int)(j / 3)] = srcImg->imageData[i*srcImg->widthStep + j];
			green[i][(int)(j / 3)] = srcImg->imageData[i*srcImg->widthStep + j + 1];
			red[i][(int)(j / 3)] = srcImg->imageData[i*srcImg->widthStep + j + 2];
			//printf("%d   %d\n", srcImg->imageData[i*srcImg->widthStep + j], srcImg->nChannels);
		}
	}
	for (int i = 3; i<srcImg->height-3; i++){
	for (int j = 3; j<srcImg->widthStep-3; j = j + 3){
	blue[i][j] = (blue[i - 3][j - 3] + blue[i - 3][j - 2] + blue[i - 3][j - 1] + blue[i - 3][j] + blue[i - 3][j + 1] + blue[i - 3][j + 2] + blue[i - 3][j + 3]
	+blue[i - 2][j - 3] + blue[i - 2][j - 2] + blue[i - 2][j - 1] + blue[i - 2][j] + blue[i - 2][j + 1] + blue[i - 2][j + 2] + blue[i - 2][j + 3]
	+blue[i - 1][j - 3] + blue[i - 1][j - 2] + blue[i - 1][j - 1] + blue[i - 1][j] + blue[i - 1][j + 1] + blue[i - 1][j + 2] + blue[i - 1][j + 3]
	+blue[i][j - 3]     + blue[i][j - 2]	 + blue[i][j - 1]	  + blue[i][j]	   + blue[i][j + 1]	    + blue[i][j + 2]	 + blue[i][j + 3]
	+blue[i + 1][j - 3] + blue[i + 1][j - 2] + blue[i + 1][j - 1] + blue[i + 1][j] + blue[i + 1][j + 1] + blue[i + 1][j + 2] + blue[i + 1][j + 3]
	+blue[i + 2][j - 3] + blue[i + 2][j - 2] + blue[i + 2][j - 1] + blue[i + 2][j] + blue[i + 2][j + 1] + blue[i + 2][j + 2] + blue[i + 2][j + 3]
	+blue[i + 3][j - 3] + blue[i + 3][j - 2] + blue[i + 3][j - 1] + blue[i + 1][j] + blue[i + 3][j + 1] + blue[i + 3][j + 2] + blue[i + 3][j + 3] )/ 49;
	red[i][j] = (red[i - 3][j - 3] + red[i - 3][j - 2] + red[i - 3][j - 1] + red[i - 3][j] + red[i - 3][j + 1] + red[i - 3][j + 2] + red[i - 3][j + 3]
	+ red[i - 2][j - 3] + red[i - 2][j - 2] + red[i - 2][j - 1] + red[i - 2][j] + red[i - 2][j + 1] + red[i - 2][j + 2] + red[i - 2][j + 3]
	+ red[i - 1][j - 3] + red[i - 1][j - 2] + red[i - 1][j - 1] + red[i - 1][j] + red[i - 1][j + 1] + red[i - 1][j + 2] + red[i - 1][j + 3]
	+ red[i][j - 3] + red[i][j - 2] + red[i][j - 1] + red[i][j] + red[i][j + 1] + red[i][j + 2] + red[i][j + 3]
	+ red[i + 1][j - 3] + red[i + 1][j - 2] + red[i + 1][j - 1] + red[i + 1][j] + red[i + 1][j + 1] + red[i + 1][j + 2] + red[i + 1][j + 3]
	+ red[i + 2][j - 3] + red[i + 2][j - 2] + red[i + 2][j - 1] + red[i + 2][j] + red[i + 2][j + 1] + red[i + 2][j + 2] + red[i + 2][j + 3]
	+ red[i + 3][j - 3] + red[i + 3][j - 2] + red[i + 3][j - 1] + red[i + 1][j] + red[i + 3][j + 1] + red[i + 3][j + 2] + red[i + 3][j + 3]) / 49;
	green[i][j] = (green[i - 3][j - 3] + green[i - 3][j - 2] + green[i - 3][j - 1] + green[i - 3][j] + green[i - 3][j + 1] + green[i - 3][j + 2] + green[i - 3][j + 3]
	+ green[i - 2][j - 3] + green[i - 2][j - 2] + green[i - 2][j - 1] + green[i - 2][j] + green[i - 2][j + 1] + green[i - 2][j + 2] + green[i - 2][j + 3]
	+ green[i - 1][j - 3] + green[i - 1][j - 2] + green[i - 1][j - 1] + green[i - 1][j] + green[i - 1][j + 1] + green[i - 1][j + 2] + green[i - 1][j + 3]
	+ green[i][j - 3] + green[i][j - 2] + green[i][j - 1] + green[i][j] + green[i][j + 1] + green[i][j + 2] + green[i][j + 3]
	+ green[i + 1][j - 3] + green[i + 1][j - 2] + green[i + 1][j - 1] + green[i + 1][j] + green[i + 1][j + 1] + green[i + 1][j + 2] + green[i + 1][j + 3]
	+ green[i + 2][j - 3] + green[i + 2][j - 2] + green[i + 2][j - 1] + green[i + 2][j] + green[i + 2][j + 1] + green[i + 2][j + 2] + green[i + 2][j + 3]
	+ green[i + 3][j - 3] + green[i + 3][j - 2] + green[i + 3][j - 1] + green[i + 1][j] + green[i + 3][j + 1] + green[i + 3][j + 2] + green[i + 3][j + 3]) / 49;
	}
	}
	/*for (int i = 3; i < srcImg->height - 3; i++){
		for (int j = 3; j < srcImg->widthStep - 3; j = j + 3){
			int sumB = 0;
			int sumG = 0;
			int sumR = 0;
			for (int p = i - 3; p < i + 3; p++){
				for (int q = j - 3; q < j + 3; q++){
					sumB = sumB + srcImg->imageData[p*srcImg->widthStep + q];
					sumG = sumG + srcImg->imageData[p*srcImg->widthStep + q+1];
					sumR = sumR + srcImg->imageData[p*srcImg->widthStep + q+2];
				}
			}
			sumB = sumB / 49;
			sumG = sumG / 49;
			sumR = sumR / 49;

			//srcImg->imageData[i*srcImg->widthStep + j] = sumB;
			//srcImg->imageData[i*srcImg->widthStep + j + 1] = sumG;
			//srcImg->imageData[i*srcImg->widthStep + j + 2] = sumR;

			blue[i][j] = sumB;
			green[i][j] = sumG;
			red[i][j] = sumR;
			//printf("---->%d    \n", srcImg->widthStep);
		}
	}*/	
	for (int i = 3; i<srcImg->height-3; i++){
		for (int j = 3; j<srcImg->widthStep-3; j = j +3){
			srcImg->imageData[i*srcImg->widthStep + j] = blue[i][(int)(j / 3)];
			srcImg->imageData[i*srcImg->widthStep + j + 1] = green[i][(int)(j / 3)];
			srcImg->imageData[i*srcImg->widthStep + j + 2] = red[i][(int)(j / 3)];
		}
	}
}
void medianFilter(IplImage* Img){
	//Load
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			blue[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j];
			green[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 1];
			red[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 2];
		}
	}
	//Median
	//int window[49];
	for (int i =3; i < Img->height - 3; i++) {
		for (int j = 3; j < Img->widthStep - 3; j=j+3) {
			int counter = 0;
			int window[49];
			for (int p = i - 3; p <= i + 3; p++){
				for (int q = j - 3; q <= j + 3; q++){					
					//window[k++] = blue[p][q];
					//window[k++] = green[p][q];
					window[counter++] = red[p][q];
				}
			}
			for (int i = 0; i <= 48; i++){
				//int jj = j / 3;
				for (int j = 0; j <= (48 - i - 1); j++){  //why?
					if (window[j] > window[j + 1]){
						int temp = window[j];
						window[j] = window[j + 1];
						window[j + 1] = temp;
					}
				}
			}
			//blue[i][int(j /3)] = window[24];  //why放一樣的?
			//green[i][int(j /3)] = window[24];
			//red[i][int(j/3) ] = window[24];
			Img->imageData[i*Img->widthStep + j*3] = window[24];
			Img->imageData[i*Img->widthStep + j*3 + 1] = window[24];
			Img->imageData[i*Img->widthStep + j*3 + 2] = window[24];
		}
	}
	//Save
	/*for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep-3; j =j+3){
			Img->imageData[i*Img->widthStep + j] = blue[i][(int)(j /3)];
			Img->imageData[i*Img->widthStep + j + 1] = green[i][(int)(j /3)];
			Img->imageData[i*Img->widthStep + j + 2] = red[i][(int)(j /3)];
			//Img->imageData[i*Img->widthStep + j] = window[24];
			//Img->imageData[i*Img->widthStep + j + 1] = window[24];
			//Img->imageData[i*Img->widthStep + j + 2] = window[24];
		}
	}*/
}
void gaussianFilter(IplImage* Img){
	int Gaussian_Matrix[49] = { 1, 3, 6, 8, 6, 3, 1
							, 3, 11, 23, 30, 23, 11, 3
							, 6, 23, 50, 64, 50, 23, 6
							, 8, 30, 64, 83, 64, 30, 8
							, 6, 23, 50, 64, 50, 23, 6
							, 3, 11, 23, 30, 23, 11, 3
							, 1, 3, 6, 8, 6, 3, 1 };
	//Load
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j++ ){
			blue[i][(int)(j/3 )] = Img->imageData[i*Img->widthStep + j];
			green[i][(int)(j/3)] = Img->imageData[i*Img->widthStep + j + 1];
			red[i][(int)(j/3 )] = Img->imageData[i*Img->widthStep + j + 2];
			//printf("%d   %d\n", Img->imageData[i*Img->widthStep + j], Img->nChannels);
		}
	}
	//Gaussian
	for (int i = 3; i < Img->height - 3; i++){
		for (int j = 3; j < Img->widthStep - 3; j = j + 3){
			blue[i][j] = (1 * blue[i - 3][j - 3] + 3 * blue[i - 3][j - 2] + 6 * blue[i - 3][j - 1] + 8 * blue[i - 3][j] + 6 * blue[i - 3][j + 1] + 3 * blue[i - 3][j + 2] + 1 * blue[i - 3][j + 3]
				+ 3 * blue[i - 2][j - 3] + 11 * blue[i - 2][j - 2] + 23 * blue[i - 2][j - 1] + 30 * blue[i - 2][j] + 23 * blue[i - 2][j + 1] + 11 * blue[i - 2][j + 2] + 2 * blue[i - 2][j + 3]
				+ 6 * blue[i - 1][j - 3] + 23 * blue[i - 1][j - 2] + 50 * blue[i - 1][j - 1] + 64 * blue[i - 1][j] + 50 * blue[i - 1][j + 1] + 23 * blue[i - 1][j + 2] + 6 * blue[i - 1][j + 3]
				+ 8 * blue[i][j - 3] + 30 * blue[i][j - 2] + 64 * blue[i][j - 1] + 83 * blue[i][j] + 64 * blue[i][j + 1] + 30 * blue[i][j + 2] + 8 * blue[i][j + 3]
				+ 6 * blue[i + 1][j - 3] + 23 * blue[i + 1][j - 2] + 50 * blue[i + 1][j - 1] + 64 * blue[i + 1][j] + 50 * blue[i + 1][j + 1] + 23 * blue[i + 1][j + 2] + 6 * blue[i + 1][j + 3]
				+ 3 * blue[i + 2][j - 3] + 11 * blue[i + 2][j - 2] + 23 * blue[i + 2][j - 1] + 30 * blue[i + 2][j] + 23 * blue[i + 2][j + 1] + 11 * blue[i + 2][j + 2] + 3 * blue[i + 2][j + 3]
				+ 1 * blue[i + 3][j - 3] + 3 * blue[i + 3][j - 2] + 6 * blue[i + 3][j - 1] + 8 * blue[i + 1][j] + 6 * blue[i + 3][j + 1] + 3 * blue[i + 3][j + 2] + 1 * blue[i + 3][j + 3]) / 996;
			red[i][j] = (1 * red[i - 3][j - 3] + 3 * red[i - 3][j - 2] + 6 * red[i - 3][j - 1] + 8 * red[i - 3][j] + 6 * red[i - 3][j + 1] + 3 * red[i - 3][j + 2] + 1 * red[i - 3][j + 3]
				+ 3 * red[i - 2][j - 3] + 11 * red[i - 2][j - 2] + 23 * red[i - 2][j - 1] + 30 * red[i - 2][j] + 23 * red[i - 2][j + 1] + 11 * red[i - 2][j + 2] + 2 * red[i - 2][j + 3]
				+ 6 * red[i - 1][j - 3] + 23 * red[i - 1][j - 2] + 50 * red[i - 1][j - 1] + 64 * red[i - 1][j] + 50 * red[i - 1][j + 1] + 23 * red[i - 1][j + 2] + 6 * red[i - 1][j + 3]
				+ 8 * red[i][j - 3] + 30 * red[i][j - 2] + 64 * red[i][j - 1] + 83 * red[i][j] + 64 * red[i][j + 1] + 30 * red[i][j + 2] + 8 * red[i][j + 3]
				+ 6 * red[i + 1][j - 3] + 23 * red[i + 1][j - 2] + 50 * red[i + 1][j - 1] + 64 * red[i + 1][j] + 50 * red[i + 1][j + 1] + 23 * red[i + 1][j + 2] + 6 * red[i + 1][j + 3]
				+ 3 * red[i + 2][j - 3] + 11 * red[i + 2][j - 2] + 23 * red[i + 2][j - 1] + 30 * red[i + 2][j] + 23 * red[i + 2][j + 1] + 11 * red[i + 2][j + 2] + 3 * red[i + 2][j + 3]
				+ 1 * red[i + 3][j - 3] + 3 * red[i + 3][j - 2] + 6 * red[i + 3][j - 1] + 8 * red[i + 1][j] + 6 * red[i + 3][j + 1] + 3 * red[i + 3][j + 2] + 1 * red[i + 3][j + 3]) / 996;
			green[i][j] = (1 * green[i - 3][j - 3] + 3 * green[i - 3][j - 2] + 6 * green[i - 3][j - 1] + 8 * green[i - 3][j] + 6 * green[i - 3][j + 1] + 3 * green[i - 3][j + 2] + 1 * green[i - 3][j + 3]
				+ 3 * green[i - 2][j - 3] + 11 * green[i - 2][j - 2] + 23 * green[i - 2][j - 1] + 30 * green[i - 2][j] + 23 * green[i - 2][j + 1] + 11 * green[i - 2][j + 2] + 2 * green[i - 2][j + 3]
				+ 6 * green[i - 1][j - 3] + 23 * green[i - 1][j - 2] + 50 * green[i - 1][j - 1] + 64 * green[i - 1][j] + 50 * green[i - 1][j + 1] + 23 * green[i - 1][j + 2] + 6 * green[i - 1][j + 3]
				+ 8 * green[i][j - 3] + 30 * green[i][j - 2] + 64 * green[i][j - 1] + 83 * green[i][j] + 64 * green[i][j + 1] + 30 * green[i][j + 2] + 8 * green[i][j + 3]
				+ 6 * green[i + 1][j - 3] + 23 * green[i + 1][j - 2] + 50 * green[i + 1][j - 1] + 64 * green[i + 1][j] + 50 * green[i + 1][j + 1] + 23 * green[i + 1][j + 2] + 6 * green[i + 1][j + 3]
				+ 3 * green[i + 2][j - 3] + 11 * green[i + 2][j - 2] + 23 * green[i + 2][j - 1] + 30 * green[i + 2][j] + 23 * green[i + 2][j + 1] + 11 * green[i + 2][j + 2] + 3 * green[i + 2][j + 3]
				+ 1 * green[i + 3][j - 3] + 3 * green[i + 3][j - 2] + 6 * green[i + 3][j - 1] + 8 * green[i + 1][j] + 6 * green[i + 3][j + 1] + 3 * green[i + 3][j + 2] + 1 * green[i + 3][j + 3]) / 996;
		
			/*int sumB = 0; int sumG = 0;	int sumR = 0;
			int counter = 0;	int total = 0;
			for (int p = i - 3; p <= i + 3; p++){
				for (int q = j-3 ; q <= j+3; q++){
					sumR = sumR + Gaussian_Matrix[counter]* (Img->imageData[p*Img->widthStep + q]);					
					//sumG = sumG + Gaussian_Matrix[counter]* (Img->imageData[p*Img->widthStep + q + 1]);
					///sumR = sumR + Gaussian_Matrix[counter]* (Img->imageData[p*Img->widthStep + q +2]);
					total = total + Gaussian_Matrix[counter++];
					//counter++;
					//printf("%d   %d\n",p,q);
				}
			}
			//sumB = sumB / total;
			//sumG = sumG / total;
			sumR = sumR / total;*/

			//blue[i][(int)(j / 3)] =blue[i][j];
			//green[i][(int)(j / 3)] = green[i][j];
			//red[i][(int)(j / 3)] = red[i][j];
			Img->imageData[i*Img->widthStep + j] = blue[i][(int)(j/3)];
			Img->imageData[i*Img->widthStep + j + 1] = green[i][(int)(j/3)];
			Img->imageData[i*Img->widthStep + j + 2] = red[i][(int)(j/3)];
		}
	}
	//Save
	/*for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			Img->imageData[i*Img->widthStep + j] = blue[i][(int)(j )];
			Img->imageData[i*Img->widthStep + j + 1] = green[i][(int)(j )];
			Img->imageData[i*Img->widthStep + j + 2] = red[i][(int)(j )];
		}
	}*/
}
////////////////////////////////////////////////////////////////////////////////////////////
void robertEdge(IplImage* Img, int threshold){
	int robertX_Matrix[4] = { 1, 0,
								0, -1,};
	int robertY_Matrix[4] = { 0, 1,
								-1, 0};
	//Load
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			blue[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j];
			green[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 1];
			red[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 2];
		}
	}
	//robert
	for (int i = 1; i < Img->height - 1; i++){
		for (int j = 1; j < Img->widthStep - 1; j ++){
			int sum = 0;
			int sumX = 0;
			int sumY = 0;
			//sum = abs(Img->imageData[i*Img->widthStep + j] - Img->imageData[(i + 1)*Img->widthStep + j + 1]) + abs(Img->imageData[(i + 1)*Img->widthStep + j] - Img->imageData[i*Img->widthStep + j +1]);
			sumX = -abs(Img->imageData[(i + 1)*Img->widthStep + j + 1]);
			sumX = sumX + abs(Img->imageData[i*Img->widthStep + j]);
			sumY = -abs(Img->imageData[i*Img->widthStep + j + 1]);
			sumY = sumY + abs(Img->imageData[(i + 1)*Img->widthStep + j] );
			sum = abs(sumX) + abs(sumY);
			//sum = abs(Img->imageData[i*Img->widthStep + j] - Img->imageData[(i + 1)*Img->widthStep + j + 1]) 
				 // + abs(Img->imageData[(i + 1)*Img->widthStep + j] - Img->imageData[i*Img->widthStep + j+1]);
			
			/*int Gx = 0;
			int Gy = 0;
			Gx = -abs(Img->imageData[(i - 1)*Img->widthStep + (j - 1)] + 2 * Img->imageData[(i - 1)*Img->widthStep + j] + Img->imageData[(i - 1)*Img->widthStep + (j + 1)]);
			Gx = Gx + abs(Img->imageData[(i + 1)*Img->widthStep + (j - 1)] + 2 * Img->imageData[(i + 1)*Img->widthStep + j] + Img->imageData[(i + 1)*Img->widthStep + (j + 1)]);
			Gy = -abs(Img->imageData[(i - 1)*Img->widthStep + (j - 1)] + 2 * Img->imageData[(i)*Img->widthStep + (j - 1)] + Img->imageData[(i + 1)*Img->widthStep + (j - 1)]);
			Gy = Gy + abs(Img->imageData[(i - 1)*Img->widthStep + (j + 1)] + 2 * Img->imageData[(i)*Img->widthStep + (j + 1)] + Img->imageData[(i + 1)*Img->widthStep + (j + 1)]);
			sum = abs(Gx) + abs(Gy);*/
			/*for (int p = i - 1; p <= i + 1; p++){
				for (int q = j - 1; q <= j + 1; q=q+3){
					int counter = 0;
					sumX = sumX + (robertX_Matrix[counter] * Img->imageData[p*Img->widthStep + q ]);
					sumY = sumY + (robertY_Matrix[counter] * Img->imageData[p*Img->widthStep + q]);
					sum = abs(sumX) + abs(sumY);//abs是啥*/
					if (threshold <= sum)
						sum = 255;
					else
						sum = 0;
					//counter++;
				//}
			//}
			blue[i][(int)(j / 3)] = sum;
			green[i][(int)(j / 3)] = sum;
			red[i][(int)(j / 3)] = sum;
			//Img->imageData[i*Img->widthStep + j] = sum;
			//Img->imageData[i*Img->widthStep + j + 1] = sum;
			//Img->imageData[i*Img->widthStep + j + 2] = sum;
		}
	}
	//Save
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			Img->imageData[i*Img->widthStep + j] = blue[i][(int)(j / 3)];
			Img->imageData[i*Img->widthStep + j + 1] = green[i][(int)(j / 3)];
			Img->imageData[i*Img->widthStep + j + 2] = red[i][(int)(j / 3)];
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
void prewittEdge(IplImage* Img, int threshold){
	int prewittX_Matrix[9] = { 1, 1, 1 ,
							   0, 0, 0,
							   -1,-1,-1	};
	int prewittY_Matrix[9] = { -1, 0, 1,
								-1, 0, 1,
								-1, 0, 1 };
	//Load
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			blue[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j];
			green[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 1];
			red[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 2];
		}
	}
	//prewitt
	for (int i = 1; i < Img->height - 1; i++){
		for (int j = 1; j < Img->widthStep - 1; j = j + 3){
			int sum = 0;
			int Gx = 0;//-1,-1   0,-1    +1.-1
			int Gy = 0; //  +1     +1       +1
			Gx = -abs(Img->imageData[(i - 1)*Img->widthStep + (j - 1)] + Img->imageData[(i - 1)*Img->widthStep + j] + Img->imageData[(i - 1)*Img->widthStep + (j + 1)]);
			Gx = Gx + abs(Img->imageData[(i + 1)*Img->widthStep + (j - 1)] + Img->imageData[(i + 1)*Img->widthStep + j] + Img->imageData[(i + 1)*Img->widthStep + (j + 1)]);
			Gy = -abs(Img->imageData[(i - 1)*Img->widthStep + (j - 1)] + Img->imageData[(i)*Img->widthStep + (j - 1)] + Img->imageData[(i + 1)*Img->widthStep + (j - 1)]);
			Gy = Gy + abs(Img->imageData[(i - 1)*Img->widthStep + (j + 1)] + Img->imageData[(i)*Img->widthStep + (j + 1)] + Img->imageData[(i + 1)*Img->widthStep + (j + 1)]);
			sum = abs(Gx) + abs(Gy);
			//int threshold = 160;
			/*for (int p = i - 1; p <= i + 2; p++){
				for (int q = j - 1; q <= j + 2; q++){
					int counter = 0;
					sumX = sumX + prewittX_Matrix[counter] * Img->imageData[p*Img->widthStep + q];
					sumY = sumY + prewittY_Matrix[counter] * Img->imageData[p*Img->widthStep + q];
					sum = abs(sumX) + abs(sumY);//abs是啥*/
					if (threshold<=sum)
						sum = 255;
					else
						sum = 0;			
				//	counter++;
				//}
			//}
			blue[i][(int)(j / 3)] = sum;
			green[i][(int)(j / 3)] = sum;
			red[i][(int)(j / 3)] = sum;
		}
	}
	//Save
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			Img->imageData[i*Img->widthStep + j] = blue[i][(int)(j / 3)];
			Img->imageData[i*Img->widthStep + j + 1] = green[i][(int)(j / 3)];
			Img->imageData[i*Img->widthStep + j + 2] = red[i][(int)(j / 3)];
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
void sobelEdge(IplImage* Img,int threshold){
	int prewittX_Matrix[9] = { 1, 2, 1,
		0, 0, 0,
		-1, -2, -1 };
	int prewittY_Matrix[9] = { -1, 0, 1,
		-2, 0, 2,
		-1, 0, 1 };
	//Load
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			blue[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j];
			green[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 1];
			red[i][(int)(j / 3)] = Img->imageData[i*Img->widthStep + j + 2];
		}
	}
	//sobel
	for (int i = 1; i < Img->height - 1; i++){
		for (int j = 1; j < Img->widthStep - 1; j = j + 3){
			int sum = 0;
			int Gx = 0;
			int Gy = 0; 
			Gx = -abs(Img->imageData[(i - 1)*Img->widthStep + (j - 1)] + 2 * Img->imageData[(i - 1)*Img->widthStep + j] + Img->imageData[(i - 1)*Img->widthStep + (j + 1)]);
			Gx = Gx + abs(Img->imageData[(i + 1)*Img->widthStep + (j - 1)] + 2 * Img->imageData[(i + 1)*Img->widthStep + j] + Img->imageData[(i + 1)*Img->widthStep + (j + 1)]);
			Gy = -abs(Img->imageData[(i - 1)*Img->widthStep + (j - 1)] + 2 * Img->imageData[(i)*Img->widthStep + (j - 1)] + Img->imageData[(i + 1)*Img->widthStep + (j - 1)]);
			Gy = Gy + abs(Img->imageData[(i - 1)*Img->widthStep + (j + 1)] + 2 * Img->imageData[(i)*Img->widthStep + (j + 1)] + Img->imageData[(i + 1)*Img->widthStep + (j + 1)]);
			sum = abs(Gx) + abs(Gy);
			//int threshold = 170;
			/*for (int p = i - 1; p <= i + 2; p++){
				//int k = (j - 1) / 2; int m = (j + 2) / 2;
				for (int q = j - 1; q <= j + 2; q++){
					int counter = 0;
					sumX = sumX +( prewittX_Matrix[counter] * Img->imageData[p*Img->widthStep + q]);
					sumY = sumY +( prewittY_Matrix[counter] * Img->imageData[p*Img->widthStep + q]);
					sum = abs(sumX) + abs(sumY);//abs是啥*/
					if (threshold<=sum)
						sum = 255;
					else
						sum = 0;
					//counter++;
			//	}
			//}
			blue[i][(int)(j / 3)] = sum;
			green[i][(int)(j / 3)] = sum;
			red[i][(int)(j / 3)] = sum;
			//Img->imageData[i*Img->widthStep + j] = sum;
			//Img->imageData[i*Img->widthStep + j + 1] = sum;
			//Img->imageData[i*Img->widthStep + j + 2] = sum;
		}
	}
	//Save
	for (int i = 0; i<Img->height; i++){
		for (int j = 0; j<Img->widthStep; j = j + 3){
			Img->imageData[i*Img->widthStep + j] = blue[i][(int)(j / 3)];
			Img->imageData[i*Img->widthStep + j + 1] = green[i][(int)(j / 3)];
			Img->imageData[i*Img->widthStep + j + 2] = red[i][(int)(j / 3)];
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
int I3_Canny_ThresSholding = 210;
Mat img3 = imread("I3.jpg");
Mat I3_Canny_Gaussian(Size(img3.cols, img3.rows), CV_8UC3, CV_RGB(255, 255, 255));
Mat I3_Canny_Sobel_Strength(Size(img3.cols, img3.rows), CV_8UC3, CV_RGB(255, 255, 255));
Mat I3_Canny_Sobel_Orientation(Size(img3.cols, img3.rows), CV_8UC3, CV_RGB(255, 255, 255));
Mat I3_Canny_Non_Maximal_Result(Size(img3.cols, img3.rows), CV_8UC3, CV_RGB(255, 255, 255));

void I3_Canny_Gaussian_Fliter(int y, int x){
	int sum = 0;
	int counter = 0, total = 0;
	int Gaussian_Matrix[49] = { 1, 3, 6, 8, 6, 3, 1
		, 3, 11, 23, 30, 23, 11, 3
		, 6, 23, 50, 64, 50, 23, 6
		, 8, 30, 64, 83, 64, 30, 8
		, 6, 23, 50, 64, 50, 23, 6
		, 3, 11, 23, 30, 23, 11, 3
		, 1, 3, 6, 8, 6, 3, 1 };
	for (int sumy = y - 3; sumy <= y + 3; sumy++){
		for (int sumx = x - 3; sumx <= x + 3; sumx++){
			sum = sum + (Gaussian_Matrix[counter] * img3.at<Vec3b>(sumy, sumx)[0]);
			total = total + Gaussian_Matrix[counter];
			counter++;
		}
	}
	sum = (sum) / total;
	I3_Canny_Gaussian.at<Vec3b>(y, x)[0] = sum;
	I3_Canny_Gaussian.at<Vec3b>(y, x)[1] = sum;
	I3_Canny_Gaussian.at<Vec3b>(y, x)[2] = sum;
}
void I3_Canny_Sobel_edge(int y, int x){
	int sum = 0, Gx = 0, Gy = 0, newangle = 0;
	double angle = 0;
	Gx = -(img3.at<Vec3b>(y - 1, x - 1)[0] + 2 * img3.at<Vec3b>(y - 1, x)[0] + img3.at<Vec3b>(y - 1, x + 1)[0]);
	Gx = Gx + (img3.at<Vec3b>(y + 1, x - 1)[0] + 2 * img3.at<Vec3b>(y + 1, x)[0] + img3.at<Vec3b>(y + 1, x + 1)[0]);
	Gy = -(img3.at<Vec3b>(y - 1, x - 1)[0] + 2 * img3.at<Vec3b>(y, x - 1)[0] + img3.at<Vec3b>(y + 1, x - 1)[0]);
	Gy = Gy + (img3.at<Vec3b>(y - 1, x + 1)[0] + 2 * img3.at<Vec3b>(y, x + 1)[0] + img3.at<Vec3b>(y + 1, x + 1)[0]);
	sum = abs(Gx) + abs(Gy);
	I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0] = sum;
	I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[1] = sum;
	I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[2] = sum;

	angle = atan2((double)Gx, (double)Gy);
	angle = angle * 180.0 / 3.14159;
	if (((angle < 22.5) && (angle > -22.5)) || (angle > 157.5) || (angle < -157.5)){
		newangle = 0;
	}
	if (((angle > 22.5) && (angle < 67.5)) || ((angle < -112.5) && (angle > -157.5))){
		newangle = 45;
	}
	if (((angle > 67.5) && (angle < 112.5)) || ((angle < -67.5) && (angle > -112.5))){
		newangle = 90;
	}
	if (((angle > 112.5) && (angle < 157.5)) || ((angle < -22.5) && (angle > -67.5))){
		newangle = 135;
	}
	I3_Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] = newangle;
	I3_Canny_Sobel_Orientation.at<Vec3b>(y, x)[1] = newangle;
	I3_Canny_Sobel_Orientation.at<Vec3b>(y, x)[2] = newangle;
}
void I3_Non_Maximal(int a, int b, int c, int y, int x){
	I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[0] = 0;
	I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[1] = 0;
	I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[2] = 0;
	if (b>a){
		if (b>c){
			I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[0] = 255;
			I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[1] = 255;
			I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[2] = 255;
		}
	}
}
void I3_Canny_Non_Maximal(int y, int x){
	if ((I3_Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 0) && (I3_Canny_ThresSholding <= I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		I3_Non_Maximal(I3_Canny_Sobel_Strength.at<Vec3b>(y - 1, x)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y + 1, x)[0], y, x);
	}else if ((I3_Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 45) && (I3_Canny_ThresSholding <= I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		I3_Non_Maximal(I3_Canny_Sobel_Strength.at<Vec3b>(y + 1, x - 1)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y - 1, x + 1)[0], y, x);
	}else if ((I3_Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 90) && (I3_Canny_ThresSholding <= I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		I3_Non_Maximal(I3_Canny_Sobel_Strength.at<Vec3b>(y, x + 1)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y, x - 1)[0], y, x);
	}else if ((I3_Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 135) && (I3_Canny_ThresSholding <= I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		I3_Non_Maximal(I3_Canny_Sobel_Strength.at<Vec3b>(y - 1, x - 1)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y, x)[0], I3_Canny_Sobel_Strength.at<Vec3b>(y + 1, x + 1)[0], y, x);
	}else{
		I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[0] = 0;
		I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[1] = 0;
		I3_Canny_Non_Maximal_Result.at<Vec3b>(y, x)[2] = 0;
	}
}
void I3_Canny_edge_Detection(){
	int tempcounter = 0;
	for (int y = 3; y < img3.rows - 3; y++){
		for (int x = 3; x < img3.cols - 3; x++) {
			I3_Canny_Gaussian_Fliter(y, x);
		}
		tempcounter = y;
	}
	for (int y = 4; y < img3.rows - 1; y++){
		for (int x = 4; x < img3.cols - 1; x++) {
			I3_Canny_Sobel_edge(y, x);
		}
		tempcounter = y;
	}
	for (int y = 4; y < img3.rows - 1; y++){
		for (int x = 4; x < img3.cols - 1; x++) {
			I3_Canny_Non_Maximal(y, x);
		}
		tempcounter = y;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
int I2_Canny_ThresSholding = 100;
Mat img2 = imread("I2.jpg");
Mat Canny_Gaussian(Size(img2.cols, img2.rows), CV_8UC3, CV_RGB(255, 255, 255));
Mat Canny_Sobel_Strength(Size(img2.cols, img2.rows), CV_8UC3, CV_RGB(255, 255, 255));
Mat Canny_Sobel_Orientation(Size(img2.cols, img2.rows), CV_8UC3, CV_RGB(255, 255, 255));
Mat Canny_Non_Maximal_Result(Size(img2.cols, img2.rows), CV_8UC3, CV_RGB(255, 255, 255));

void Canny_Gaussian_Fliter(int y, int x){
	//ULONG sum = 0;
	int sum = 0;
	int counter = 0, total = 0;
	int Gaussian_Matrix[49] = { 1, 3, 6, 8, 6, 3, 1
		, 3, 11, 23, 30, 23, 11, 3
		, 6, 23, 50, 64, 50, 23, 6
		, 8, 30, 64, 83, 64, 30, 8
		, 6, 23, 50, 64, 50, 23, 6
		, 3, 11, 23, 30, 23, 11, 3
		, 1, 3, 6, 8, 6, 3, 1 };
	for (int sumy = y - 3; sumy <= y + 3; sumy++){
		for (int sumx = x - 3; sumx <= x + 3; sumx++){
			sum = sum + (Gaussian_Matrix[counter] * img2.at<Vec3b>(sumy, sumx)[0]);
			total = total + Gaussian_Matrix[counter];
			counter++;
		}
	}
	sum = (sum) / total;
	Canny_Gaussian.at<Vec3b>(y, x)[0] = sum;
	Canny_Gaussian.at<Vec3b>(y, x)[1] = sum;
	Canny_Gaussian.at<Vec3b>(y, x)[2] = sum;
}
void Canny_Sobel_edge(int y, int x){
	int sum = 0, Gx = 0, Gy = 0, newangle = 0;
	double angle = 0;
	Gx = -(img2.at<Vec3b>(y - 1, x - 1)[0] + 2 * img2.at<Vec3b>(y - 1, x)[0] + img2.at<Vec3b>(y - 1, x + 1)[0]);
	Gx = Gx + (img2.at<Vec3b>(y + 1, x - 1)[0] + 2 * img2.at<Vec3b>(y + 1, x)[0] + img2.at<Vec3b>(y + 1, x + 1)[0]);
	Gy = -(img2.at<Vec3b>(y - 1, x - 1)[0] + 2 * img2.at<Vec3b>(y, x - 1)[0] + img2.at<Vec3b>(y + 1, x - 1)[0]);
	Gy = Gy + (img2.at<Vec3b>(y - 1, x + 1)[0] + 2 * img2.at<Vec3b>(y, x + 1)[0] + img2.at<Vec3b>(y + 1, x + 1)[0]);
	sum = abs(Gx) + abs(Gy);
	Canny_Sobel_Strength.at<Vec3b>(y, x)[0] = sum;
	Canny_Sobel_Strength.at<Vec3b>(y, x)[1] = sum;
	Canny_Sobel_Strength.at<Vec3b>(y, x)[2] = sum;

	angle = atan2((double)Gx, (double)Gy);
	angle = angle * 180.0 / 3.14159;
	if (((angle < 22.5) && (angle > -22.5)) || (angle > 157.5) || (angle < -157.5)){
		newangle = 0;
	}
	if (((angle > 22.5) && (angle < 67.5)) || ((angle < -112.5) && (angle > -157.5))){
		newangle = 45;
	}
	if (((angle > 67.5) && (angle < 112.5)) || ((angle < -67.5) && (angle > -112.5))){
		newangle = 90;
	}
	if (((angle > 112.5) && (angle < 157.5)) || ((angle < -22.5) && (angle > -67.5))){
		newangle = 135;
	}
	Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] = newangle;
}
void Non_Maximal(int a, int b, int c, int y, int x){
	Canny_Non_Maximal_Result.at<Vec3b>(y, x)[0] = 0;
	Canny_Non_Maximal_Result.at<Vec3b>(y, x)[1] = 0;
	Canny_Non_Maximal_Result.at<Vec3b>(y, x)[2] = 0;
	if (b>a){
		if (b>c){
			Canny_Non_Maximal_Result.at<Vec3b>(y, x)[0] = 255;
			Canny_Non_Maximal_Result.at<Vec3b>(y, x)[1] = 255;
			Canny_Non_Maximal_Result.at<Vec3b>(y, x)[2] = 255;
		}
	}
}
void Canny_Non_Maximal(int y, int x){
	if ((Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 0) && (I2_Canny_ThresSholding <= Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		Non_Maximal(Canny_Sobel_Strength.at<Vec3b>(y - 1, x)[0], Canny_Sobel_Strength.at<Vec3b>(y, x)[0], Canny_Sobel_Strength.at<Vec3b>(y + 1, x)[0], y, x);
	}else if ((Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 45) && (I2_Canny_ThresSholding <= Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		Non_Maximal(Canny_Sobel_Strength.at<Vec3b>(y + 1, x - 1)[0], Canny_Sobel_Strength.at<Vec3b>(y, x)[0], Canny_Sobel_Strength.at<Vec3b>(y - 1, x + 1)[0], y, x);
	}else if ((Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 90) && (I2_Canny_ThresSholding <= Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		Non_Maximal(Canny_Sobel_Strength.at<Vec3b>(y, x + 1)[0], Canny_Sobel_Strength.at<Vec3b>(y, x)[0], Canny_Sobel_Strength.at<Vec3b>(y, x - 1)[0], y, x);
	}else if ((Canny_Sobel_Orientation.at<Vec3b>(y, x)[0] == 135) && (I2_Canny_ThresSholding <= Canny_Sobel_Strength.at<Vec3b>(y, x)[0])){
		Non_Maximal(Canny_Sobel_Strength.at<Vec3b>(y - 1, x - 1)[0], Canny_Sobel_Strength.at<Vec3b>(y, x)[0], Canny_Sobel_Strength.at<Vec3b>(y + 1, x + 1)[0], y, x);
	}else{
		Canny_Non_Maximal_Result.at<Vec3b>(y, x)[0] = 0;
		Canny_Non_Maximal_Result.at<Vec3b>(y, x)[1] = 0;
		Canny_Non_Maximal_Result.at<Vec3b>(y, x)[2] = 0;
	}
}
void Canny_edge_Detection(){
	int tempcounter = 0;
	for (int y = 3; y < img2.rows - 3; y++){
		for (int x = 3; x < img2.cols - 3; x++) {
			Canny_Gaussian_Fliter(y, x);
		}
		tempcounter = y;
	}
	for (int y = 4; y < img2.rows - 1; y++){
		for (int x = 4; x < img2.cols - 1; x++) {
			Canny_Sobel_edge(y, x);
		}
		tempcounter = y;
	}
	for (int y = 4; y < img2.rows - 1; y++){
		for (int x = 4; x < img2.cols - 1; x++) {
			Canny_Non_Maximal(y, x);
		}
		tempcounter = y;
	}
}
/////////////////////////////////////////////////////////////////////
int main(){
	char* pictureFileName = "I1.jpg";
	IplImage *img1 = cvLoadImage(pictureFileName);
	IplImage *img1_mean = cvLoadImage(pictureFileName);
	IplImage *img1_median = cvLoadImage(pictureFileName);
	IplImage *img1_gaussian = cvLoadImage(pictureFileName);

	meanFilter(img1_mean);
	medianFilter(img1_median);
	gaussianFilter(img1_gaussian);

	cvShowImage("I1", img1);
	cvShowImage("I1_Mean", img1_mean);
	cvShowImage("I1_Median", img1_median);
	cvShowImage("I1_Gaussian", img1_gaussian);
	cvSaveImage("I1_Mean.jpg", img1_mean);
	cvSaveImage("I1_Median.jpg", img1_median);
	cvSaveImage("I1_Gaussian.jpg", img1_gaussian);

	char* pictureFileName2 = "I2.jpg";
	IplImage *img2 = cvLoadImage(pictureFileName2, 1);
	IplImage *img2_robert = cvLoadImage(pictureFileName2, 1);
	IplImage *img2_prewitt = cvLoadImage(pictureFileName2, 1);
	IplImage *img2_sobel = cvLoadImage(pictureFileName2, 1);

	robertEdge(img2_robert, 30);
	prewittEdge(img2_prewitt, 55);
	sobelEdge(img2_sobel, 75);

	cvShowImage("I2", img2);
	cvShowImage("I2_Robert", img2_robert);
	cvShowImage("I2_Prewitt", img2_prewitt);
	cvShowImage("I2_Sobel", img2_sobel);
	cvSaveImage("I2_Robert.jpg", img2_robert);
	cvSaveImage("I2_Prewitt.jpg", img2_prewitt);
	cvSaveImage("I2_Sobel.jpg", img2_sobel);

	IplImage *img3 = cvLoadImage("I3.jpg");
	IplImage *img3_robert = cvLoadImage("I3.jpg");
	IplImage *img3_prewitt = cvLoadImage("I3.jpg");
	IplImage *img3_sobel = cvLoadImage("I3.jpg");

	robertEdge(img3_robert, 70);
	prewittEdge(img3_prewitt, 130);
	sobelEdge(img3_sobel, 180);
	
	cvShowImage("I3", img3);
	cvShowImage("I3_Robert", img3_robert);
	cvShowImage("I3_Prewitt", img3_prewitt);
	cvShowImage("I3_Sobel", img3_sobel);
	cvSaveImage("I3_Robert.jpg", img3_robert);
	cvSaveImage("I3_Prewitt.jpg", img3_prewitt);
	cvSaveImage("I3_Sobel.jpg", img3_sobel);

	Canny_edge_Detection();
	//imshow("I2_Canny_Gaussian",Canny_Gaussian);
	//imshow("I2_Canny_Sobel_Strength",Canny_Sobel_Strength);
	//imshow("I2_Canny_Non_Maximal_Result", Canny_Non_Maximal_Result);
	imshow("I2_Canny", Canny_Non_Maximal_Result);
	imwrite("I2_Canny.jpg", Canny_Non_Maximal_Result);
	I3_Canny_edge_Detection();
	imshow("I3_Canny", I3_Canny_Non_Maximal_Result);
	imwrite("I3_Canny.jpg", I3_Canny_Non_Maximal_Result);
	cvReleaseImage(&img1);
	cvReleaseImage(&img1_mean);
	cvReleaseImage(&img1_median);
	cvReleaseImage(&img1_gaussian);
	cvReleaseImage(&img2);
	cvReleaseImage(&img2_robert);
	cvReleaseImage(&img2_prewitt);
	cvReleaseImage(&img2_sobel);
	cvReleaseImage(&img3);
	cvReleaseImage(&img3_robert);
	cvReleaseImage(&img3_prewitt);
	cvReleaseImage(&img3_sobel);

	cvWaitKey();
	return 0;
}

