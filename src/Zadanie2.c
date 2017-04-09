#include <stdio.h>

void print_line_segment(char ax, char ay, char bx, char by) {
	//using Bresenham's line algorithm
	int dx, dy, D, y, x, i, j;
	char field[by+1][bx+1];
	
	for(i = 0; i <= by; i++) {
		for(j = 0; j <= bx; j++) {
			field[i][j] = ' ';
		}
	}
	
	dx = bx - ax;
	dy = by - ay;
	
	if(dx >= dy) {
		D = 2*dy - dx;
		y = ay;
	
		for(x = ax; x < bx; x++) {
			field[y][x] = 'x';
			if(D > 0) {
				y = y + 1;
				D = D - 2*dx;
			} else {
				D = D + 2*dy;
			}
		}
	} else {
		D = 2*dx - dy;
		x = ax;
	
		for(y = ay; y < by; y++) {
			field[y][x] = 'x';
			if(D > 0) {
				x = x + 1;
				D = D - 2*dy;
			} else {
				D = D + 2*dx;
			}
		}
	}
	
	for(i = 0; i <= by; i++) {
		for(j = 0; j <= bx; j++) {
			printf("%c", field[i][j]);
		}
		printf("\n");
	}
}
		
void controller(int ax, int ay, int bx, int by) {
	if(ax > bx && ay > by) {
		print_line_segment(bx, by, ax, ay);
	}
	else if(ax > bx && ay < by) {
		print_line_segment(bx, ay, ax, by);
	}
	else if(ax < bx && ay > by) {
		print_line_segment(ax, by, bx, ay);
	}
	else {
		print_line_segment(ax, ay, bx, by);
	}
}
	
int main(void) {
	int ax, ay, bx, by;
	
	printf("Zadaj x-ovu a y-ovu suradnicu prveho bodu:\n");
	scanf("%d %d", &ax, &ay);
	
	printf("Zadaj x-ovu a y-ovu suradnicu druheho bodu:\n");
	scanf("%d %d", &bx, &by);
	
	controller(ax, ay, bx, by);
	
	return 0;
}
