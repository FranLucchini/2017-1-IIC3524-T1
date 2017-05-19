#include <stdio.h>
#include <stdlib.h>
#include "../imagelib/imagelib.h"
#include "omp.h"
#include <time.h>
#define BILLION 1E9

void process_image (Image* img, Image* result, float** kernel, int k_row, int k_col, int num_threads) {
	//int tid;

	omp_set_num_threads(num_threads);
	/* Change colors */
	int i, j;
	#pragma omp parallel for shared(img, result, kernel)
	for (i = 0; i < img->height; i++) {
		//printf("Hello world! I am thread %d in for 1, i=%i\n", tid, i);
		//int tid = omp_get_thread_num();
		//int num = omp_get_num_threads();
		//#pragma omp parallel for shared(img, result, kernel)
		for (j = 0; j < img->width; j++) {
			//printf("Hello world! I am thread %i in for 1, i=%i, j=%i\n", tid, i, j);
			//printf("Num of thread %i\n", num);
			float determinant[3] = {0.0f, 0.0f, 0.0f}; // |R|G|B|
			int r_desp = (k_row-1)/2;
			int c_desp = (k_col-1)/2;
			for (int m = i - r_desp; m <= i + r_desp ; m++) {
					for (int n = j - c_desp; n <= j + c_desp; n++) {
								int x = abs( i - m - r_desp );
								int y = abs( j - n - c_desp );
								if( m < 0 && n < 0)
								{
									determinant[0] += img->pixels[0][0].R * kernel[x][y];
									determinant[1] += img->pixels[0][0].G * kernel[x][y];
									determinant[2] += img->pixels[0][0].B * kernel[x][y];
								}
								else if( m < 0 && n >= img->width )
								{
									determinant[1] += img->pixels[0][img->width-1].G * kernel[x][y];
									determinant[0] += img->pixels[0][img->width-1].R * kernel[x][y];
									determinant[2] += img->pixels[0][img->width-1].B * kernel[x][y];
								}
								else if( m >= img->height && n >= img->width )
								{
									determinant[0] += img->pixels[img->height-1][img->width-1].R * kernel[x][y];
									determinant[2] += img->pixels[img->height-1][img->width-1].B * kernel[x][y];
									determinant[1] += img->pixels[img->height-1][img->width-1].G * kernel[x][y];
								}
								else if( m >= img->height && n < 0)
								{
									determinant[0] += img->pixels[img->height-1][0].R * kernel[x][y];
									determinant[1] += img->pixels[img->height-1][0].G * kernel[x][y];
									determinant[2] += img->pixels[img->height-1][0].B * kernel[x][y];
								}


								else if( m < 0 )
								{
									determinant[0] += img->pixels[0][n].R * kernel[x][y];
									determinant[1] += img->pixels[0][n].G * kernel[x][y];
									determinant[2] += img->pixels[0][n].B * kernel[x][y];
								}
								else if( m >= img->height )
								{
									determinant[0] += img->pixels[img->height-1][n].R * kernel[x][y];
									determinant[1] += img->pixels[img->height-1][n].G * kernel[x][y];
									determinant[2] += img->pixels[img->height-1][n].B * kernel[x][y];
								}


								else if( n < 0 )
								{
									determinant[0] += img->pixels[m][0].R * kernel[x][y];
									determinant[1] += img->pixels[m][0].G * kernel[x][y];
									determinant[2] += img->pixels[m][0].B * kernel[x][y];
								}
								else if( n >= img->width )
								{
									determinant[0] += img->pixels[m][img->width-1].R * kernel[x][y];
									determinant[1] += img->pixels[m][img->width-1].G * kernel[x][y];
									determinant[2] += img->pixels[m][img->width-1].B * kernel[x][y];
								}


								else
								{
									//printf("Transformed m to %i and n to %i\n", m, n);
									determinant[0] += img->pixels[m][n].R * kernel[x][y];
									determinant[1] += img->pixels[m][n].G * kernel[x][y];
									determinant[2] += img->pixels[m][n].B * kernel[x][y];
									//printf("    R sum: %f * %f = %f \n", img->pixels[0][0].R, kernel[x][y], img->pixels[0][0].R * kernel[x][y]);
								}
								//printf("----\n" );
					}
			}
			//printf("determinant R:%f G:%f B:%f\n", determinant[0], determinant[1], determinant[2]);
			result->pixels[i][j].R = determinant[0];
			result->pixels[i][j].G = determinant[1];
			result->pixels[i][j].B = determinant[2];
		}
	}

}

void print_kernel(float** kernel, int row, int col) {
	for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
					printf("%f ", kernel[i][j]);
			}
			printf("\n");
	}
}

float** get_kernel(char* kernel_path, int* r_row, int* r_col) {
		/*Read dimentions*/
    FILE* kernel_file = fopen(kernel_path, "r");
    int row, col;

    fscanf(kernel_file, "%i", &row);
		fscanf(kernel_file, "%i", &col);

		*r_row = row;
		*r_col = col;

		/* Read kernel matrix */
		float** kernel;
		kernel = malloc(row * sizeof(float*));

		for (size_t i = 0; i < row; i++) {
				kernel[i] = malloc(col * sizeof(float));

				for (size_t j = 0; j < col; j++) {
						fscanf(kernel_file, "%f", &kernel[i][j]);
				}
		}

		//printf("row: %i, col: %i\n", *r_row, *r_col);
		//print_kernel(kernel, row, col);

		fclose(kernel_file);

		return kernel;

}

/** TODO: Libera los recursos asociados a una imagen */
void img_destroy(Image* img) {
	for (size_t i = 0; i < img->height; i++) {
		free(img->pixels[i]);
	}
	free(img->pixels);
	free(img);
}

/** TODO: destroy kernel **/
void kernel_destroy(float** kernel, int row) {
	for (size_t i = 0; i < row; i++) {
			free(kernel[i]);
	}
	free(kernel);
}

int main(int argc, char *argv[])
{
	/* El programa recibe 5 parametros */
	if(argc != 6)
	{
		printf("Modo de uso: %s <input.png> <kernel.txt> <output.png> <number_of_iterations> <number_of_threads>\n", argv[0]);
		printf("\t<input.png> es la imagen a filtrar\n");
		printf("\t<kernel.txt> es el filtro a usar\n");
		printf("\t<output.png> es donde se guardará la imagen resultante\n");
		printf("\t<number_of_iterations> es el número de veces que se aplica el filtro\n");
		printf("\t<number_of_threads> es el número de threads que usará la región paralelizada\n");
		return 1;
	}

	/* Leemos la imagen a partir del archivo */
	char* input_file  = argv[1];
	char* kernel_file = argv[2];
	char* output_file = argv[3];
	int interations = atoi(argv[4]);
	int num_threads = atoi(argv[5]);

	Image* img = img_png_read_from_file(input_file);

	/* Leer el kernel a partir del archivo */
	int row = 0;
	int col = 0;
	float** kernel = get_kernel(kernel_file, &row, &col);

	/* Create output image */
	Image* result  = malloc(sizeof(Image));
	result->height = img->height;
	result->width  = img->width;

	/* Create array */
	Color** array;
	array = malloc(img->height * sizeof(Color*));
	for (int i = 0; i < img->height; i++) {
			array[i] = malloc(img->width * sizeof(Color));
	}
	result->pixels = array;
	/* End array creation */

	struct timespec requestStart, requestEnd;
	clock_gettime(CLOCK_REALTIME, &requestStart);
	for (int i = 0; i < interations; i++) {
		process_image(img, result, kernel, row, col, num_threads);
		Image* aux = result;
		result = img;
		img = aux;
	}
	clock_gettime(CLOCK_REALTIME, &requestEnd);
	// Calculate time it took
	double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
  + ( requestEnd.tv_nsec - requestStart.tv_nsec )
  / BILLION;

	printf("Time:%f, Thread(s):%i, Repetitions:%i\n", accum, num_threads, interations);
	img_png_write_to_file (result, output_file);

	/* Liberamos los recursos */
	kernel_destroy(kernel, row);
	img_destroy(img);
	img_destroy(result);

	return 0;
}
